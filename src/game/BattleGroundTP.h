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

#ifndef __BattleGroundTP_H
#define __BattleGroundTP_H

#include "BattleGround.h"

#define BG_TP_MAX_TEAM_SCORE      3
#define BG_TP_FLAG_RESPAWN_TIME   (23*IN_MILLISECONDS)
#define BG_TP_FLAG_DROP_TIME      (10*IN_MILLISECONDS)
#define BG_TP_TIME_LIMIT          (25*MINUTE*IN_MILLISECONDS)
#define BG_TP_EVENT_START_BATTLE  8563

enum BG_TP_Sound
{
    BG_TP_SOUND_FLAG_CAPTURED_ALLIANCE  = 8173,
    BG_TP_SOUND_FLAG_CAPTURED_HORDE     = 8213,
    BG_TP_SOUND_FLAG_PLACED             = 8232,
    BG_TP_SOUND_FLAG_RETURNED           = 8192,
    BG_TP_SOUND_HORDE_FLAG_PICKED_UP    = 8212,
    BG_TP_SOUND_ALLIANCE_FLAG_PICKED_UP = 8174,
    BG_TP_SOUND_FLAGS_RESPAWNED         = 8232
};

enum BG_TP_SpellId
{
    BG_TP_SPELL_WARSONG_FLAG            = 23333,
    BG_TP_SPELL_WARSONG_FLAG_DROPPED    = 23334,
    BG_TP_SPELL_SILVERWING_FLAG         = 23335,
    BG_TP_SPELL_SILVERWING_FLAG_DROPPED = 23336
};

enum BG_TP_WorldStates
{
    BG_TP_FLAG_UNK_ALLIANCE       = 1545,
    BG_TP_FLAG_UNK_HORDE          = 1546,
//    FLAG_UNK                      = 1547,
    BG_TP_FLAG_CAPTURES_ALLIANCE  = 1581,
    BG_TP_FLAG_CAPTURES_HORDE     = 1582,
    BG_TP_FLAG_CAPTURES_MAX       = 1601,
    BG_TP_FLAG_STATE_HORDE        = 2338,
    BG_TP_FLAG_STATE_ALLIANCE     = 2339,
    BG_TP_TIME_ENABLED            = 4247,
    BG_TP_TIME_REMAINING          = 4248
};

enum BG_TP_FlagState
{
    BG_TP_FLAG_STATE_ON_BASE      = 0,
    BG_TP_FLAG_STATE_WAIT_RESPAWN = 1,
    BG_TP_FLAG_STATE_ON_PLAYER    = 2,
    BG_TP_FLAG_STATE_ON_GROUND    = 3
};

enum BG_TP_Graveyards
{
    TP_GRAVEYARD_FLAGROOM_ALLIANCE = 1726,
    TP_GRAVEYARD_FLAGROOM_HORDE    = 1727,
    TP_GRAVEYARD_MAIN_ALLIANCE     = 1728,
    TP_GRAVEYARD_MAIN_HORDE        = 1729
};

class BattleGroundTPScore : public BattleGroundScore
{
    public:
        BattleGroundTPScore() : FlagCaptures(0), FlagReturns(0) {};
        virtual ~BattleGroundTPScore() {};
        uint32 FlagCaptures;
        uint32 FlagReturns;
};


enum BG_TP_Events
{
    TP_EVENT_FLAG_A               = 0,
    TP_EVENT_FLAG_H               = 1,
    // spiritguides will spawn (same moment, like TP_EVENT_DOOR_OPEN)
    TP_EVENT_SPIRITGUIDES_SPAWN   = 2
};

class BattleGroundTP : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        /* Construction */
        BattleGroundTP();
        ~BattleGroundTP();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        /* BG Flags */
        ObjectGuid GetAllianceFlagPickerGuid() const{ return m_FlagKeepers[BG_TEAM_ALLIANCE]; }
        ObjectGuid GetHordeFlagPickerGuid() const   { return m_FlagKeepers[BG_TEAM_HORDE]; }
        void SetAllianceFlagPicker(ObjectGuid guid) { m_FlagKeepers[BG_TEAM_ALLIANCE] = guid; }
        void SetHordeFlagPicker(ObjectGuid guid)    { m_FlagKeepers[BG_TEAM_HORDE] = guid; }
        void ClearAllianceFlagPicker()              { m_FlagKeepers[BG_TEAM_ALLIANCE].Clear(); }
        void ClearHordeFlagPicker()                 { m_FlagKeepers[BG_TEAM_HORDE].Clear(); }
        bool IsAllianceFlagPickedup() const         { return !m_FlagKeepers[BG_TEAM_ALLIANCE].IsEmpty(); }
        bool IsHordeFlagPickedup() const            { return !m_FlagKeepers[BG_TEAM_HORDE].IsEmpty(); }
        void RespawnFlag(Team team, bool captured);
        void RespawnFlagAfterDrop(Team team);
        uint8 GetFlagState(Team team)             { return m_FlagState[GetTeamIndexByTeamId(team)]; }

        /* Battleground Events */
        virtual void EventPlayerDroppedFlag(Player *Source);
        virtual void EventPlayerClickedOnFlag(Player *Source, GameObject* target_obj);
        virtual void EventPlayerCapturedFlag(Player *Source);

        void RemovePlayer(Player *plr, ObjectGuid guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        void HandleKillPlayer(Player *player, Player *killer);
        bool SetupBattleGround();
        virtual void Reset();
        void EndBattleGround(Team winner);
        virtual WorldSafeLocsEntry const* GetClosestGraveYard(Player* player);
        uint32 GetRemainingTimeInMinutes() { return m_EndTimer ? (m_EndTimer-1) / (MINUTE * IN_MILLISECONDS) + 1 : 0; }

        void UpdateFlagState(Team team, uint32 value);
        void UpdateTeamScore(Team team);
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value);
        void SetDroppedFlagGuid(ObjectGuid guid, Team team)  { m_DroppedFlagGuid[GetTeamIndexByTeamId(team)] = guid;}
        void ClearDroppedFlagGuid(Team team)  { m_DroppedFlagGuid[GetTeamIndexByTeamId(team)].Clear();}
        ObjectGuid const& GetDroppedFlagGuid(Team team) const { return m_DroppedFlagGuid[GetTeamIndexByTeamId(team)];}
        virtual void FillInitialWorldStates(WorldPacket& data, uint32& count);

        /* Scorekeeping */
        uint32 GetTeamScore(Team team) const            { return m_TeamScores[GetTeamIndexByTeamId(team)]; }
        void AddPoint(Team team, uint32 Points = 1)     { m_TeamScores[GetTeamIndexByTeamId(team)] += Points; }
        void SetTeamPoint(Team team, uint32 Points = 0) { m_TeamScores[GetTeamIndexByTeamId(team)] = Points; }
        void RemovePoint(Team team, uint32 Points = 1)  { m_TeamScores[GetTeamIndexByTeamId(team)] -= Points; }
    private:
        ObjectGuid m_FlagKeepers[BG_TEAMS_COUNT];

        ObjectGuid m_DroppedFlagGuid[BG_TEAMS_COUNT];
        uint8 m_FlagState[BG_TEAMS_COUNT];
        int32 m_FlagsTimer[BG_TEAMS_COUNT];
        int32 m_FlagsDropTimer[BG_TEAMS_COUNT];

        uint32 m_ReputationCapture;
        uint32 m_HonorWinKills;
        uint32 m_HonorEndKills;
        uint32 m_EndTimer;
        Team   m_LastCapturedFlagTeam;
};
#endif
