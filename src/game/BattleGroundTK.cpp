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
#include "BattleGroundTK.h"
#include "Creature.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "BattleGroundMgr.h"
#include "WorldPacket.h"
#include "Language.h"
#include "MapManager.h"

BattleGroundTK::BattleGroundTK()
{
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = 0;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_TK_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_TK_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_TK_HAS_BEGUN;
}

BattleGroundTK::~BattleGroundTK()
{
}

void BattleGroundTK::Update(uint32 diff)
{
    BattleGround::Update(diff);

    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        if (m_EndTimer <= diff)
        {
            uint32 allianceScore = GetTeamScore(ALLIANCE);
            uint32 hordeScore    = GetTeamScore(HORDE);

            if (allianceScore > hordeScore)
                EndBattleGround(ALLIANCE);
            else if (allianceScore < hordeScore)
                EndBattleGround(HORDE);
            else
            {
                // if 0 => tie
                EndBattleGround(m_LastCapturedOrbTeam);
            }
        }
        else
        {
            uint32 minutesLeftPrev = GetRemainingTimeInMinutes();
            m_EndTimer -= diff;
            uint32 minutesLeft = GetRemainingTimeInMinutes();

            if (minutesLeft != minutesLeftPrev)
                UpdateWorldState(BG_TK_TIME_REMAINING, minutesLeft);
        }
    }
}

void BattleGroundTK::StartingEventCloseDoors()
{
}

void BattleGroundTK::StartingEventOpenDoors()
{
    OpenDoorEvent(BG_EVENT_DOOR);

    // TODO implement timer to despawn doors after a short while

    SpawnEvent(TK_EVENT_SPIRITGUIDES_SPAWN, 0, true);
    SpawnEvent(TK_EVENT_ORB, 0, true);

    // Players that join battleground after start are not eligible to get achievement.
    StartTimedAchievement(ACHIEVEMENT_CRITERIA_TYPE_WIN_BG, BG_TK_EVENT_START_BATTLE);
}

void BattleGroundTK::AddPlayer(Player *plr)
{
    BattleGround::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattleGroundTKScore* sc = new BattleGroundTKScore;

    m_PlayerScores[plr->GetObjectGuid()] = sc;
}

void BattleGroundTK::EventPlayerDroppedOrb(Player *Source)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
    {
        if (!IsAllianceOrbPickedup())
			return;

		if (Source->GetTeam() == ALLIANCE)
        {
		    Source->RemoveAurasDueToSpell(BG_TK_SPELL_ORB);
		    Source->RemoveAurasDueToSpell(BG_TK_SPELL_ORB1);
		    Source->RemoveAurasDueToSpell(BG_TK_SPELL_ORB2);
		    m_OrbState[BG_TEAM_ALLIANCE] = BG_TK_ORB_STATE_ON_GROUND;
		    Source->CastSpell(Source, BG_TK_SPELL_ORB_DROPPED, true);
		    UpdateOrbState(Source->GetTeam(), 1);
		    SendMessageToAll(LANG_BG_TK_DROPPED, CHAT_MSG_BG_SYSTEM_ALLIANCE, Source);
		    UpdateWorldState(BG_TK_ICON_A, uint32(-1));            
	    }
    }

    if (GetStatus() != STATUS_IN_PROGRESS)
    {
        if (!IsHordeOrbPickedup())
			return;

		if (Source->GetTeam() == HORDE)
        {
		    Source->RemoveAurasDueToSpell(BG_TK_SPELL_ORB);
		    Source->RemoveAurasDueToSpell(BG_TK_SPELL_ORB1);
		    Source->RemoveAurasDueToSpell(BG_TK_SPELL_ORB2);
		    m_OrbState[BG_TEAM_HORDE] = BG_TK_ORB_STATE_ON_GROUND;
		    Source->CastSpell(Source, BG_TK_SPELL_ORB_DROPPED, true);
		    UpdateOrbState(Source->GetTeam(), 1);
		    SendMessageToAll(LANG_BG_TK_DROPPED, CHAT_MSG_BG_SYSTEM_HORDE, Source);
		    UpdateWorldState(BG_TK_ICON_H, uint32(-1));            
	    }
    }
	
}

void BattleGroundTK::EventPlayerClickedOnOrb(Player *Source, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    int32 message_id = 0;
    ChatMsg type;

    uint8 event = (sBattleGroundMgr.GetGameObjectEventIndex(target_obj->GetGUIDLow())).event1;

    //Orb on base
    if (Source->IsWithinDistInMap(target_obj, 10))
    {
        if (Source->GetTeam() == HORDE)
        {
            message_id = LANG_BG_TK_PICKEDUP;
            type = CHAT_MSG_BG_SYSTEM_HORDE;
            PlaySoundToAll(BG_TK_SOUND_A_ORB_PICKED_UP);
            SpawnEvent(TK_EVENT_ORB, 0, false);
            SetAllianceOrbPicker(Source->GetObjectGuid());
            Source->CastSpell(Source, BG_TK_SPELL_ORB, true);
            m_OrbState[BG_TEAM_ALLIANCE] = BG_TK_ORB_STATE_ON_PLAYER;
            UpdateOrbState(HORDE, BG_TK_ORB_STATE_ON_PLAYER);
            UpdateWorldState(BG_TK_ICON_A, 1);
        }
        else
        {
            message_id = LANG_BG_TK_PICKEDUP;
            type = CHAT_MSG_BG_SYSTEM_ALLIANCE;
            PlaySoundToAll(BG_TK_SOUND_H_ORB_PICKED_UP);
            SpawnEvent(TK_EVENT_ORB, 0, false);
            SetHordeOrbPicker(Source->GetObjectGuid());
            Source->CastSpell(Source, BG_TK_SPELL_ORB, true);
            m_OrbState[BG_TEAM_HORDE] = BG_TK_ORB_STATE_ON_PLAYER;
            UpdateOrbState(ALLIANCE, BG_TK_ORB_STATE_ON_PLAYER);
            UpdateWorldState(BG_TK_ICON_H, 1);
        }
        //called in HandleGameObjectUseOpcode:
        //target_obj->Delete();
    }

    if (!message_id)
        return;

    SendMessageToAll(message_id, type, Source);
    Source->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
}

void BattleGroundTK::RemovePlayer(Player *plr, ObjectGuid guid)
{
    // sometimes flag aura not removed :(
    if (IsAllianceOrbPickedup() && m_OrbKeepers[BG_TEAM_ALLIANCE] == guid)
    {
            sLog.outError("BattleGroundTK: Removing offline player who has the FLAG!!");
            ClearAllianceOrbPicker();
            EventPlayerDroppedOrb(plr);
    }
    if (IsHordeOrbPickedup() && m_OrbKeepers[BG_TEAM_HORDE] == guid)
    {
            sLog.outError("BattleGroundTK: Removing offline player who has the FLAG!!");
            ClearHordeOrbPicker();
            EventPlayerDroppedOrb(plr);
    }
}

void BattleGroundTK::UpdateOrbState(Team team, uint32 value)
{
    if (team == ALLIANCE)
        UpdateWorldState(BG_TK_ICON_A, value);
    else
        UpdateWorldState(BG_TK_ICON_H, value);
}

void BattleGroundTK::UpdateTeamScore(Team team)
{
    if (team == ALLIANCE)
        UpdateWorldState(BG_TK_ORB_POINTS_A, GetTeamScore(team));
    else
        UpdateWorldState(BG_TK_ORB_POINTS_H, GetTeamScore(team));
}

void BattleGroundTK::HandleAreaTrigger(Player *Source, uint32 Trigger)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    //uint32 SpellId = 0;
    //uint64 buff_guid = 0;
    switch(Trigger)
    {
        case 6060:                                          // ZONE1
		    if (Source->GetTeam() == HORDE && !IsAllianceOrbPickedup())
            {
			    SetHordeOrbPicker(Source->GetObjectGuid());
                Source->CastSpell(Source, BG_TK_SPELL_ORB, true);
		    }
		    if (Source->GetTeam() == ALLIANCE && !IsHordeOrbPickedup())
            {
			    SetAllianceOrbPicker(Source->GetObjectGuid());
                Source->CastSpell(Source, BG_TK_SPELL_ORB, true);
		    }
			break;
		case 6061:                                          // ZONE2
		    if (Source->GetTeam() == HORDE && !IsAllianceOrbPickedup())
            {
			    SetHordeOrbPicker(Source->GetObjectGuid());
                Source->CastSpell(Source, BG_TK_SPELL_ORB1, true);
		    }
		    if (Source->GetTeam() == ALLIANCE && !IsHordeOrbPickedup())
            {
			    SetAllianceOrbPicker(Source->GetObjectGuid());
                Source->CastSpell(Source, BG_TK_SPELL_ORB1, true);
		    }
			break;
		case 6136:                                          // ZONE3
		    if (Source->GetTeam() == HORDE && !IsAllianceOrbPickedup())
            {
			    SetHordeOrbPicker(Source->GetObjectGuid());
                Source->CastSpell(Source, BG_TK_SPELL_ORB2, true);
		    }
		    if (Source->GetTeam() == ALLIANCE && !IsHordeOrbPickedup())
            {
			    SetAllianceOrbPicker(Source->GetObjectGuid());
                Source->CastSpell(Source, BG_TK_SPELL_ORB2, true);
		    }
			break;
        default:
            sLog.outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
            Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
            break;
    }
}

bool BattleGroundTK::SetupBattleGround()
{
    return true;
}

void BattleGroundTK::Reset()
{
    //call parent's class reset
    BattleGround::Reset();

    // spiritguides and flags not spawned at beginning
    m_ActiveEvents[TK_EVENT_SPIRITGUIDES_SPAWN] = BG_EVENT_NONE;
    m_ActiveEvents[TK_EVENT_ORB] = BG_EVENT_NONE;

    for(uint32 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        m_DroppedOrbGuid[i].Clear();
        m_OrbKeepers[i].Clear();
        m_OrbState[i]       = BG_TK_ORB_STATE_ON_BASE;
        m_TeamScores[i]      = 0;
    }
    bool isBGWeekend = BattleGroundMgr::IsBGWeekend(GetTypeID());
    m_ReputationCapture = (isBGWeekend) ? 45 : 35;
    m_HonorWinKills = (isBGWeekend) ? 3 : 1;
    m_HonorEndKills = (isBGWeekend) ? 4 : 2;

    m_EndTimer = BG_TK_TIME_LIMIT;
    m_LastCapturedOrbTeam = TEAM_NONE;
}

void BattleGroundTK::EndBattleGround(Team winner)
{
    //win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(m_HonorWinKills), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(m_HonorWinKills), HORDE);
    //complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(m_HonorEndKills), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(m_HonorEndKills), HORDE);

    BattleGround::EndBattleGround(winner);
}

void BattleGroundTK::HandleKillPlayer(Player *player, Player *killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    EventPlayerDroppedOrb(player);

    BattleGround::HandleKillPlayer(player, killer);
}


void BattleGroundTK::UpdatePlayerScore(Player *Source, uint32 type, uint32 value)
{

    BattleGroundScoreMap::iterator itr = m_PlayerScores.find(Source->GetObjectGuid());
    if(itr == m_PlayerScores.end())                         // player not found
        return;

    switch(type)
    {
        case SCORE_ORB_HANDLES:                           // orb handles
            ((BattleGroundTKScore*)itr->second)->OrbHandles += value;
            break;
        default:
            BattleGround::UpdatePlayerScore(Source, type, value);
            break;
    }
}

WorldSafeLocsEntry const* BattleGroundTK::GetClosestGraveYard(Player* player)
{
    //if status in progress, it returns main graveyards with spiritguides
    //else it will return the graveyard in the flagroom - this is especially good
    //if a player dies in preparation phase - then the player can't cheat
    //and teleport to the graveyard outside the flagroom
    //and start running around, while the doors are still closed
    if (player->GetTeam() == ALLIANCE)
    {
        if (GetStatus() == STATUS_IN_PROGRESS)
            return sWorldSafeLocsStore.LookupEntry(TK_GRAVEYARD_RECTANGLEA1);
        else
            return sWorldSafeLocsStore.LookupEntry(TK_GRAVEYARD_RECTANGLEA2);
    }
    else
    {
        if (GetStatus() == STATUS_IN_PROGRESS)
            return sWorldSafeLocsStore.LookupEntry(TK_GRAVEYARD_RECTANGLEH1);
        else
            return sWorldSafeLocsStore.LookupEntry(TK_GRAVEYARD_RECTANGLEH2);
    }
}

void BattleGroundTK::FillInitialWorldStates(WorldPacket& data, uint32& count)
{
    FillInitialWorldState(data, count, BG_TK_ORB_POINTS_A, GetTeamScore(ALLIANCE));
    FillInitialWorldState(data, count, BG_TK_ORB_POINTS_H, GetTeamScore(HORDE));

    if (m_OrbState[BG_TEAM_ALLIANCE] == BG_TK_ORB_STATE_ON_GROUND)
        FillInitialWorldState(data, count, BG_TK_ICON_A, -1);
    else if (m_OrbState[BG_TEAM_ALLIANCE] == BG_TK_ORB_STATE_ON_PLAYER)
        FillInitialWorldState(data, count, BG_TK_ICON_A, 1);
    else
        FillInitialWorldState(data, count, BG_TK_ICON_A, 0);

    if (m_OrbState[BG_TEAM_HORDE] == BG_TK_ORB_STATE_ON_GROUND)
        FillInitialWorldState(data, count, BG_TK_ICON_H, -1);
    else if (m_OrbState[BG_TEAM_HORDE] == BG_TK_ORB_STATE_ON_PLAYER)
        FillInitialWorldState(data, count, BG_TK_ICON_H, 1);
    else
        FillInitialWorldState(data, count, BG_TK_ICON_H, 0);

    FillInitialWorldState(data, count, BG_TK_ORB_POINTS_MAX, BG_TK_MAX_TEAM_SCORE);

    if (m_OrbState[BG_TEAM_HORDE] == BG_TK_ORB_STATE_ON_PLAYER)
        FillInitialWorldState(data, count, BG_TK_ORB_STATE, 2);
    else
        FillInitialWorldState(data, count, BG_TK_ORB_STATE, 1);

    if (m_OrbState[BG_TEAM_ALLIANCE] == BG_TK_ORB_STATE_ON_PLAYER)
        FillInitialWorldState(data, count, BG_TK_ORB_STATE, 2);
    else
        FillInitialWorldState(data, count, BG_TK_ORB_STATE, 1);

    FillInitialWorldState(data, count, BG_TK_TIME_ENABLED, 1);
    FillInitialWorldState(data, count, BG_TK_TIME_REMAINING, GetRemainingTimeInMinutes());
}
