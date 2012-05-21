/*
 * Copyright (C) 2010-2012 Strawberry-Pr0jcts <http://strawberry-pr0jcts.com/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Object.h"
#include "Player.h"
#include "BattleGround.h"
#include "BattleGroundSM.h"
#include "Creature.h"
#include "GameObject.h"
#include "BattleGroundMgr.h"
#include "Language.h"
#include "Util.h"
#include "WorldPacket.h"
#include "MapManager.h"

BattleGroundSM::BattleGroundSM()
{
    m_BuffChange = true;
    m_BgObjects.resize(BG_SM_OBJECT_MAX);

    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = 0;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_SM_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_SM_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_SM_HAS_BEGUN;
}

BattleGroundSM::~BattleGroundSM()
{
}

void BattleGroundSM::Update(uint32 diff)
{
    BattleGround::Update(diff);

    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        int team_points[BG_TEAMS_COUNT] = { 0, 0 };

        for (int CART = 0; CART < BG_SM_CARTS_MAX; ++CART)
        {
            // 3 sec delay to spawn new Cart instead previous despawned one
            if (m_CartTimers[CART].timer)
            {
                if (m_CartTimers[CART].timer > diff)
                    m_CartTimers[CART].timer -= diff;
                else
                {
                    m_CartTimers[CART].timer = 0;
                    _CreateCart(CART, m_CartTimers[CART].type, m_CartTimers[CART].teamIndex, false);
                }
            }

            // 1-minute to occupy a CART from contested state
            if (m_CARTTimers[CART])
            {
                if (m_CARTTimers[CART] > diff)
                    m_CARTTimers[CART] -= diff;
                else
                {
                    m_CARTTimers[CART] = 0;
                    // Change from contested to occupied !
                    uint8 teamIndex = m_CARTS[CART]-1;
                    m_prevCARTS[CART] = m_CARTS[CART];
                    m_CARTS[CART] += 2;
                    // create new occupied Cart
                    _CreateCart(CART, BG_SM_CART_TYPE_OCCUPIED, teamIndex, true);
                    _SendCARTUpdate(CART);
                    _CARTOccupied(CART,(teamIndex == 0) ? ALLIANCE:HORDE);
                    // Message to chatlog

                    if (teamIndex == 0)
                    {
                        SendMessage2ToAll(LANG_BG_SM_CART_TAKEN,CHAT_MSG_BG_SYSTEM_ALLIANCE,NULL,LANG_BG_ALLY,_GetCARTNameId(CART));
                        PlaySoundToAll(BG_SM_SOUND_CART_CAPTURED_ALLIANCE);
                    }
                    else
                    {
                        SendMessage2ToAll(LANG_BG_SM_CART_TAKEN,CHAT_MSG_BG_SYSTEM_HORDE,NULL,LANG_BG_HORDE,_GetCARTNameId(CART));
                        PlaySoundToAll(BG_SM_SOUND_CART_CAPTURED_HORDE);
                    }
                }
            }

            for (int team = 0; team < BG_TEAMS_COUNT; ++team)
                if (m_CARTS[CART] == team + BG_SM_CART_TYPE_OCCUPIED)
                    ++team_points[team];
        }

        // Accumulate points
        for (int team = 0; team < BG_TEAMS_COUNT; ++team)
        {
            int points = team_points[team];
            if (!points)
                continue;
            m_lastTick[team] += diff;
            if (m_lastTick[team] > 100)
            {
                m_lastTick[team] -= 100;
                m_TeamScores[team] += BG_SM_TickPoints[points];
                if (!m_IsInformedNearVictory && m_TeamScores[team] > BG_SM_WARNING_NEAR_VICTORY_SCORE)
                {
                    if (team == BG_TEAM_ALLIANCE)
                        SendMessageToAll(LANG_BG_SM_A_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    else
                        SendMessageToAll(LANG_BG_SM_H_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    PlaySoundToAll(BG_SM_SOUND_NEAR_VICTORY);
                    m_IsInformedNearVictory = true;
                }

                if (m_TeamScores[team] > BG_SM_MAX_TEAM_SCORE)
                    m_TeamScores[team] = BG_SM_MAX_TEAM_SCORE;
                if (team == BG_TEAM_ALLIANCE)
                    UpdateWorldState(BG_SM_OP_RESOURCES_ALLY, m_TeamScores[team]);
                if (team == BG_TEAM_HORDE)
                    UpdateWorldState(BG_SM_OP_RESOURCES_HORDE, m_TeamScores[team]);
            }
        }

        // Test win condition
        if (m_TeamScores[BG_TEAM_ALLIANCE] >= BG_SM_MAX_TEAM_SCORE)
            EndBattleGround(ALLIANCE);
        if (m_TeamScores[BG_TEAM_HORDE] >= BG_SM_MAX_TEAM_SCORE)
            EndBattleGround(HORDE);
    }
}

void BattleGroundSM::StartingEventCloseDoors()
{
    // despawn buffs
    for (int i = 0; i < BG_SM_CARTS_MAX * 3; ++i)
        SpawnBGObject(m_BgObjects[BG_SM_OBJECT_SPEEDBUFF_1 + i], RESPAWN_ONE_DAY);
}

void BattleGroundSM::StartingEventOpenDoors()
{
    for (int i = 0; i < BG_SM_CARTS_MAX; ++i)
    {
        //randomly select buff to spawn
        uint8 buff = urand(0, 2);
        SpawnBGObject(m_BgObjects[BG_SM_OBJECT_SPEEDBUFF_1 + buff + i * 3], RESPAWN_IMMEDIATELY);
    }
    OpenDoorEvent(BG_EVENT_DOOR);

    // Players that join battleground after start are not eligible to get achievement.
    StartTimedAchievement(ACHIEVEMENT_CRITERIA_TYPE_WIN_BG, BG_SM_EVENT_START_BATTLE);
}

void BattleGroundSM::AddPlayer(Player *plr)
{
    BattleGround::AddPlayer(plr);
    //create score and add it to map, default values are set in the constructor
    BattleGroundSMScore* sc = new BattleGroundSMScore;

    m_PlayerScores[plr->GetObjectGuid()] = sc;
}

void BattleGroundSM::RemovePlayer(Player * /*plr*/, ObjectGuid /*guid*/)
{

}

void BattleGroundSM::HandleAreaTrigger(Player *Source, uint32 Trigger)
{
    switch(Trigger)
    {
        case 4062:                                          // A START
        case 4061:                                          // H START
        default:
            //sLog.outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
            //Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
            break;
    }
}

/*  type: 0-neutral, 1-contested, 3-occupied
    teamIndex: 0-ally, 1-horde                        */
void BattleGroundSM::_CreateCart(uint8 CART, uint8 type, uint8 teamIndex, bool delay)
{
    // Just put it into the queue
    if (delay)
    {
        m_CartTimers[CART].timer = 2000;
        m_CartTimers[CART].type = type;
        m_CartTimers[CART].teamIndex = teamIndex;
        return;
    }

    // cause the CART-type is in the generic form
    // please see in the headerfile for the ids
    if (type != BG_SM_CART_TYPE_NEUTRAL)
        type += teamIndex;

    SpawnEvent(CART, type, true);                           // will automaticly despawn other events
}

int32 BattleGroundSM::_GetCARTNameId(uint8 CART)
{
    switch (CART)
    {
        case BG_SM_CART_1:          return LANG_BG_SM_CART_1;
        case BG_SM_CART_2:          return LANG_BG_SM_CART_2;
        case BG_SM_CART_3:          return LANG_BG_SM_CART_3;
        default:
            STRAWBERRY_ASSERT(0);
    }
    return 0;
}

void BattleGroundSM::FillInitialWorldStates(WorldPacket& data, uint32& count)
{
    const uint8 plusArray[] = {0, 2, 3, 0, 1};

    // CART icons
    for (uint8 CART = 0; CART < BG_SM_CARTS_MAX; ++CART)
        FillInitialWorldState(data, count, BG_SM_OP_CARTICONS[CART], m_CARTS[CART]==0);

    // CART occupied states
    for (uint8 CART = 0; CART < BG_SM_CARTS_MAX; ++CART)
        for (uint8 i = 1; i < BG_SM_CARTS_MAX; ++i)
            FillInitialWorldState(data, count, BG_SM_OP_CARTSTATES[CART] + plusArray[i], m_CARTS[CART]==i);

    // Team scores
    FillInitialWorldState(data, count, BG_SM_OP_RESOURCES_MAX,      BG_SM_MAX_TEAM_SCORE);
    FillInitialWorldState(data, count, BG_SM_OP_RESOURCES_WARNING,  BG_SM_WARNING_NEAR_VICTORY_SCORE);
    FillInitialWorldState(data, count, BG_SM_OP_RESOURCES_ALLY,     m_TeamScores[BG_TEAM_ALLIANCE]);
    FillInitialWorldState(data, count, BG_SM_OP_RESOURCES_HORDE,    m_TeamScores[BG_TEAM_HORDE]);

    // other unknown
    FillInitialWorldState(data, count, 0x745, 0x2);         // 37 1861 unk
}

void BattleGroundSM::_SendCARTUpdate(uint8 CART)
{
    // Send CART owner state update to refresh map icons on client
    const uint8 plusArray[] = {0, 2, 3, 0, 1};

    if (m_prevCARTS[CART])
        UpdateWorldState(BG_SM_OP_CARTSTATES[CART] + plusArray[m_prevCARTS[CART]], 0);
    else
        UpdateWorldState(BG_SM_OP_CARTICONS[CART], 0);

    UpdateWorldState(BG_SM_OP_CARTSTATES[CART] + plusArray[m_CARTS[CART]], 1);

}

void BattleGroundSM::_CARTOccupied(uint8 CART,Team team)
{
    uint8 capturedCARTS = 0;
    for (uint8 i = 0; i < BG_SM_CARTS_MAX; ++i)
    {
        if (m_CARTS[CART] == GetTeamIndexByTeamId(team) + BG_SM_CART_TYPE_OCCUPIED && !m_CARTTimers[i])
            ++capturedCARTS;
    }
}

/* Invoked if a player used a Cart as a gameobject */
void BattleGroundSM::EventPlayerClickedOnCART(Player *source, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    uint8 event = (sBattleGroundMgr.GetGameObjectEventIndex(target_obj->GetGUIDLow())).event1;
    if (event >= BG_SM_CARTS_MAX)                           // not a CART
        return;
    BG_SM_CARTS CART = BG_SM_CARTS(event);

    BattleGroundTeamIndex teamIndex = GetTeamIndexByTeamId(source->GetTeam());

    // Check if player really could use this Cart, not cheated
    if (!(m_CARTS[CART] == 0 || teamIndex == m_CARTS[CART] % 2))
        return;

    source->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
    uint32 sound = 0;

    // TODO in the following code we should restructure a bit to avoid
    // duplication (or maybe write functions?)
    // If CART is neutral, change to contested
    if (m_CARTS[CART] == BG_SM_CART_TYPE_NEUTRAL)
    {
        UpdatePlayerScore(source, SCORE_CARTS_HELPED, 1);
        m_prevCARTS[CART] = m_CARTS[CART];
        m_CARTS[CART] = teamIndex + 1;
        // create new contested Cart
        _CreateCart(CART, BG_SM_CART_TYPE_CONTESTED, teamIndex, true);
        _SendCARTUpdate(CART);
        m_CARTTimers[CART] = BG_SM_CART_CAPTURING_TIME;

        if (teamIndex == 0)
            SendMessage2ToAll(LANG_BG_SM_CART_CLAIMED,CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetCARTNameId(CART), LANG_BG_ALLY);
        else
            SendMessage2ToAll(LANG_BG_SM_CART_CLAIMED,CHAT_MSG_BG_SYSTEM_HORDE, source, _GetCARTNameId(CART), LANG_BG_HORDE);

        sound = BG_SM_SOUND_CART_CLAIMED;
    }
    // If CART is contested
    else if ((m_CARTS[CART] == BG_SM_CART_STATUS_ALLY_CONTESTED) || (m_CARTS[CART] == BG_SM_CART_STATUS_HORDE_CONTESTED))
    {
        // If last state is NOT occupied, change CART to enemy-contested
        if (m_prevCARTS[CART] < BG_SM_CART_TYPE_OCCUPIED)
        {
            UpdatePlayerScore(source, SCORE_CARTS_HELPED, 1);
            m_prevCARTS[CART] = m_CARTS[CART];
            m_CARTS[CART] = teamIndex + BG_SM_CART_TYPE_CONTESTED;
            // create new contested Cart
            _CreateCart(CART, BG_SM_CART_TYPE_CONTESTED, teamIndex, true);
            _SendCARTUpdate(CART);
            m_CARTTimers[CART] = BG_SM_CART_CAPTURING_TIME;

            if (teamIndex == BG_TEAM_ALLIANCE)
                SendMessage2ToAll(LANG_BG_SM_CART_ASSAULTED,CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetCARTNameId(CART));
            else
                SendMessage2ToAll(LANG_BG_SM_CART_ASSAULTED,CHAT_MSG_BG_SYSTEM_HORDE, source, _GetCARTNameId(CART));
        }
        // If contested, change back to occupied
        else
        {
            UpdatePlayerScore(source, SCORE_CARTS_HELPED, 1);
            m_prevCARTS[CART] = m_CARTS[CART];
            m_CARTS[CART] = teamIndex + BG_SM_CART_TYPE_OCCUPIED;
            // create new occupied Cart
            _CreateCart(CART, BG_SM_CART_TYPE_OCCUPIED, teamIndex, true);
            _SendCARTUpdate(CART);
            m_CARTTimers[CART] = 0;
            _CARTOccupied(CART,(teamIndex == BG_TEAM_ALLIANCE) ? ALLIANCE:HORDE);

            if (teamIndex == BG_TEAM_ALLIANCE)
                SendMessage2ToAll(LANG_BG_SM_CART_DEFENDED,CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetCARTNameId(CART));
            else
                SendMessage2ToAll(LANG_BG_SM_CART_DEFENDED,CHAT_MSG_BG_SYSTEM_HORDE, source, _GetCARTNameId(CART));
        }
        sound = (teamIndex == BG_TEAM_ALLIANCE) ? BG_SM_SOUND_CART_ASSAULTED_ALLIANCE : BG_SM_SOUND_CART_ASSAULTED_HORDE;
    }
    // If CART is occupied, change to enemy-contested
    else
    {
        UpdatePlayerScore(source, SCORE_CARTS_HELPED, 1);
        m_prevCARTS[CART] = m_CARTS[CART];
        m_CARTS[CART] = teamIndex + BG_SM_CART_TYPE_CONTESTED;
        // create new contested Cart
        _CreateCart(CART, BG_SM_CART_TYPE_CONTESTED, teamIndex, true);
        _SendCARTUpdate(CART);
        m_CARTTimers[CART] = BG_SM_CART_CAPTURING_TIME;

        if (teamIndex == BG_TEAM_ALLIANCE)
            SendMessage2ToAll(LANG_BG_SM_CART_ASSAULTED,CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetCARTNameId(CART));
        else
            SendMessage2ToAll(LANG_BG_SM_CART_ASSAULTED,CHAT_MSG_BG_SYSTEM_HORDE, source, _GetCARTNameId(CART));

        sound = (teamIndex == BG_TEAM_ALLIANCE) ? BG_SM_SOUND_CART_ASSAULTED_ALLIANCE : BG_SM_SOUND_CART_ASSAULTED_HORDE;
    }

    // If CART is occupied again, send "X has taken the Y" msg.
    if (m_CARTS[CART] >= BG_SM_CART_TYPE_OCCUPIED)
    {
        if (teamIndex == BG_TEAM_ALLIANCE)
            SendMessage2ToAll(LANG_BG_SM_CART_TAKEN,CHAT_MSG_BG_SYSTEM_ALLIANCE, NULL, LANG_BG_ALLY, _GetCARTNameId(CART));
        else
            SendMessage2ToAll(LANG_BG_SM_CART_TAKEN,CHAT_MSG_BG_SYSTEM_HORDE, NULL, LANG_BG_HORDE, _GetCARTNameId(CART));
    }
    PlaySoundToAll(sound);
}

bool BattleGroundSM::SetupBattleGround()
{
    //buffs
    for (int i = 0; i < BG_SM_CARTS_MAX; ++i)
    {
        if (!AddObject(BG_SM_OBJECT_SPEEDBUFF_1 + 3 * i, Buff_Entries[0], BG_SM_BuffPositions[i][0], BG_SM_BuffPositions[i][1], BG_SM_BuffPositions[i][2], BG_SM_BuffPositions[i][3], 0, 0, sin(BG_SM_BuffPositions[i][3]/2), cos(BG_SM_BuffPositions[i][3]/2), RESPAWN_ONE_DAY)
            || !AddObject(BG_SM_OBJECT_SPEEDBUFF_1 + 3 * i + 1, Buff_Entries[1], BG_SM_BuffPositions[i][0], BG_SM_BuffPositions[i][1], BG_SM_BuffPositions[i][2], BG_SM_BuffPositions[i][3], 0, 0, sin(BG_SM_BuffPositions[i][3]/2), cos(BG_SM_BuffPositions[i][3]/2), RESPAWN_ONE_DAY)
            || !AddObject(BG_SM_OBJECT_SPEEDBUFF_1 + 3 * i + 2, Buff_Entries[2], BG_SM_BuffPositions[i][0], BG_SM_BuffPositions[i][1], BG_SM_BuffPositions[i][2], BG_SM_BuffPositions[i][3], 0, 0, sin(BG_SM_BuffPositions[i][3]/2), cos(BG_SM_BuffPositions[i][3]/2), RESPAWN_ONE_DAY)
            )
            sLog.outErrorDb("BatteGroundAB: Failed to spawn buff object!");
    }

    return true;
}

void BattleGroundSM::Reset()
{
    //call parent's class reset
    BattleGround::Reset();

    for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        m_TeamScores[i]          = 0;
        m_lastTick[i]            = 0;
    }

    m_IsInformedNearVictory                 = false;

    for (uint8 i = 0; i < BG_SM_CARTS_MAX; ++i)
    {
        m_CARTS[i] = 0;
        m_prevCARTS[i] = 0;
        m_CARTTimers[i] = 0;
        m_CartTimers[i].timer = 0;

        // all CARTS owned by neutral team at beginning
        m_ActiveEvents[i] = BG_SM_CART_TYPE_NEUTRAL;
    }

}

void BattleGroundSM::EndBattleGround(Team winner)
{
    //win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    //complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);

    BattleGround::EndBattleGround(winner);
}

WorldSafeLocsEntry const* BattleGroundSM::GetClosestGraveYard(Player* player)
{
    BattleGroundTeamIndex teamIndex = GetTeamIndexByTeamId(player->GetTeam());

    // Is there any occupied CART for this team?
    std::vector<uint8> CARTS;
    for (uint8 i = 0; i < BG_SM_CARTS_MAX; ++i)
        if (m_CARTS[i] == teamIndex + 3)
            CARTS.push_back(i);

    WorldSafeLocsEntry const* good_entry = NULL;
    // If so, select the closest CART to place ghost on
    if (!CARTS.empty())
    {
        float plr_x = player->GetPositionX();
        float plr_y = player->GetPositionY();

        float mindist = 999999.0f;
        for (uint8 i = 0; i < CARTS.size(); ++i)
        {
            WorldSafeLocsEntry const*entry = sWorldSafeLocsStore.LookupEntry( BG_SM_GraveyardIds[CARTS[i]] );
            if (!entry)
                continue;
            float dist = (entry->x - plr_x)*(entry->x - plr_x)+(entry->y - plr_y)*(entry->y - plr_y);
            if (mindist > dist)
            {
                mindist = dist;
                good_entry = entry;
            }
        }
        CARTS.clear();
    }
    // If not, place ghost on starting location
    if (!good_entry)
        good_entry = sWorldSafeLocsStore.LookupEntry( BG_SM_GraveyardIds[teamIndex+5] );

    return good_entry;
}

void BattleGroundSM::UpdatePlayerScore(Player *Source, uint32 type, uint32 value)
{
    BattleGroundScoreMap::iterator itr = m_PlayerScores.find(Source->GetObjectGuid());
    if( itr == m_PlayerScores.end() )                         // player not found...
        return;

    switch(type)
    {
        case SCORE_CARTS_HELPED:
            ((BattleGroundSMScore*)itr->second)->CARTSHelped += value;
            break;
        default:
            BattleGround::UpdatePlayerScore(Source,type,value);
            break;
    }
}