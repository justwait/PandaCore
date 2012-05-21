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
#ifndef __BattleGroundBG_H
#define __BattleGroundBG_H

#include "Common.h"
#include "BattleGround.h"

enum BG_BG_WorldStates
{
    BG_BG_OP_OCCUPIED_BASES_HORDE       = 2753,
    BG_BG_OP_OCCUPIED_BASES_ALLY        = 2752,
    BG_BG_OP_RESOURCES_ALLY             = 2749,
    BG_BG_OP_RESOURCES_HORDE            = 2750,
    BG_BG_OP_RESOURCES_MAX              = 1780,
    BG_BG_OP_RESOURCES_WARNING          = 1955
/*
    BG_BG_OP_LIGHTHOUSE_ICON            = 1842,             //LIGHTHOUSE map icon (NONE)
    BG_BG_OP_LIGHTHOUSE_STATE_ALLIANCE  = 1767,             //LIGHTHOUSE map state (ALLIANCE)
    BG_BG_OP_LIGHTHOUSE_STATE_HORDE     = 1768,             //LIGHTHOUSE map state (HORDE)
    BG_BG_OP_LIGHTHOUSE_STATE_CON_ALI   = 1769,             //LIGHTHOUSE map state (CON ALLIANCE)
    BG_BG_OP_LIGHTHOUSE_STATE_CON_HOR   = 1770,             //LIGHTHOUSE map state (CON HORDE)

    BG_BG_OP_WATERWORKS_ICON            = 1845,             //WATERWORKS map icon (NONE)
    BG_BG_OP_WATERWORKS_STATE_ALLIANCE  = 1772,             //WATERWORKS state (ALLIANCE)
    BG_BG_OP_WATERWORKS_STATE_HORDE     = 1773,             //WATERWORKS state (HORDE)
    BG_BG_OP_WATERWORKS_STATE_CON_ALI   = 1774,             //WATERWORKS state (CON ALLIANCE)
    BG_BG_OP_WATERWORKS_STATE_CON_HOR   = 1775,             //WATERWORKS state (CON HORDE)

    BG_BG_OP_MINES_ICON                 = 1846,             //MINES map icon (NONE)
    BG_BG_OP_MINES_STATE_ALLIANCE       = 1782,             //MINES map state (ALLIANCE)
    BG_BG_OP_MINES_STATE_HORDE          = 1783,             //MINES map state (HORDE)
    BG_BG_OP_MINES_STATE_CON_ALI        = 1784,             //MINES map state (CON ALLIANCE)
    BG_BG_OP_MINES_STATE_CON_HOR        = 1785,             //MINES map state (CON HORDE)
*/
};

const uint32 BG_BG_OP_NODESTATES[3] =    {1767, 1782, 1772};

const uint32 BG_BG_OP_NODEICONS[3]  =    {1842, 1846, 1845};

enum BG_BG_ObjectType
{
    // TODO drop them (pool-system should be used for this)
    //buffs
    BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE    = 1,
    BG_BG_OBJECT_REGENBUFF_LIGHTHOUSE    = 2,
    BG_BG_OBJECT_BERSERKBUFF_LIGHTHOUSE  = 3,
    BG_BG_OBJECT_SPEEDBUFF_WATERWORKS    = 4,
    BG_BG_OBJECT_REGENBUFF_WATERWORKS    = 5,
    BG_BG_OBJECT_BERSERKBUFF_WATERWORKS  = 6,
    BG_BG_OBJECT_SPEEDBUFF_MINES         = 7,
    BG_BG_OBJECT_REGENBUFF_MINES         = 8,
    BG_BG_OBJECT_BERSERKBUFF_MINES       = 9,
    BG_BG_OBJECT_MAX                     = 16,
};


/* node events */
// node-events are just event1=BG_BG_Nodes, event2=BG_BG_NodeStatus
// so we don't need to define the constants here :)

enum BG_BG_Timers
{
    BG_BG_FLAG_CAPTURING_TIME           = 60000,
};

enum BG_BG_Score
{
    BG_BG_WARNING_NEAR_VICTORY_SCORE    = 1400,
    BG_BG_MAX_TEAM_SCORE                = 1600
};

/* do NOT change the order, else wrong behaviour */
enum BG_BG_Nodes
{
    BG_BG_NODE_LIGHTHOUSE       = 0,
    BG_BG_NODE_WATERWORKS       = 1,
    BG_BG_NODE_MINES            = 2,
    BG_BG_NODES_ERROR           = 255
};

#define BG_BG_NODES_MAX   3

enum BG_BG_NodeStatus
{
    BG_BG_NODE_TYPE_NEUTRAL             = 0,
    BG_BG_NODE_TYPE_CONTESTED           = 1,
    BG_BG_NODE_STATUS_ALLY_CONTESTED    = 1,
    BG_BG_NODE_STATUS_HORDE_CONTESTED   = 2,
    BG_BG_NODE_TYPE_OCCUPIED            = 3,
    BG_BG_NODE_STATUS_ALLY_OCCUPIED     = 3,
    BG_BG_NODE_STATUS_HORDE_OCCUPIED    = 4
};

enum BG_BG_Sounds
{
    BG_BG_SOUND_NODE_CLAIMED            = 8192,
    BG_BG_SOUND_NODE_CAPTURED_ALLIANCE  = 8173,
    BG_BG_SOUND_NODE_CAPTURED_HORDE     = 8213,
    BG_BG_SOUND_NODE_ASSAULTED_ALLIANCE = 8212,
    BG_BG_SOUND_NODE_ASSAULTED_HORDE    = 8174,
    BG_BG_SOUND_NEAR_VICTORY            = 8456
};

#define BG_BG_NotABBGWeekendHonorTicks      330
#define BG_BG_ABBGWeekendHonorTicks         200
#define BG_BG_NotABBGWeekendReputationTicks 200
#define BG_BG_ABBGWeekendReputationTicks    150
#define BG_BG_EVENT_START_BATTLE            9158

// Tick intervals and given points: case 0,1,2,3 captured nodes
const uint32 BG_BG_TickIntervals[4] = {0, 12000, 9000, 6000};
const uint32 BG_BG_TickPoints[3] = {0, 10, 20};

// WorldSafeLocs ids for ally, and horde starting location
const uint32 BG_BG_GraveyardIds[2] = {1740, 1739};

// x, y, z, o
const float BG_BG_BuffPositions[BG_BG_NODES_MAX][4] = {
    {1185.71f, 1185.24f, -56.36f, 2.56f},                   // Light House
    {990.75f, 1008.18f, -42.60f, 2.43f},                    // Waterworks
    {817.66f, 843.34f, -56.54f, 3.01f},                     // Mines
};

struct BG_BG_BannerTimer
{
    uint32      timer;
    uint8       type;
    uint8       teamIndex;
};

class BattleGroundBGScore : public BattleGroundScore
{
    public:
        BattleGroundBGScore(): BasesAssaulted(0), BasesDefended(0) {};
        virtual ~BattleGroundBGScore() {};
        uint32 BasesAssaulted;
        uint32 BasesDefended;
};

class BattleGroundBG : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundBG();
        ~BattleGroundBG();

        void Update(uint32 diff);
        void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();
        void RemovePlayer(Player *plr, ObjectGuid guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        virtual bool SetupBattleGround();
        virtual void Reset();
        void EndBattleGround(Team winner);
        virtual WorldSafeLocsEntry const* GetClosestGraveYard(Player* player);

        /* Scorekeeping */
        virtual void UpdatePlayerScore(Player *Source, uint32 type, uint32 value);

        virtual void FillInitialWorldStates(WorldPacket& data, uint32& count);

        /* Nodes occupying */
        virtual void EventPlayerClickedOnFlag(Player *source, GameObject* target_obj);

        /* achievement req. */
        bool IsAllNodesConrolledByTeam(Team team) const;    // overwrited
        bool IsTeamScores500Disadvantage(Team team) const { return m_TeamScores500Disadvantage[GetTeamIndexByTeamId(team)]; }
    private:
        /* Gameobject spawning/despawning */
        void _CreateBanner(uint8 node, uint8 type, uint8 teamIndex, bool delay);
        void _DelBanner(uint8 node, uint8 type, uint8 teamIndex);
        void _SendNodeUpdate(uint8 node);

        /* Creature spawning/despawning */
        // TODO: working, scripted peons spawning
        void _NodeOccupied(uint8 node,Team team);

        int32 _GetNodeNameId(uint8 node);

        /* Nodes info:
            0: neutral
            1: ally contested
            2: horde contested
            3: ally occupied
            4: horde occupied     */
        uint8               m_Nodes[BG_BG_NODES_MAX];
        uint8               m_prevNodes[BG_BG_NODES_MAX];   // used for performant wordlstate-updating
        BG_BG_BannerTimer   m_BannerTimers[BG_BG_NODES_MAX];
        uint32              m_NodeTimers[BG_BG_NODES_MAX];
        uint32              m_lastTick[BG_TEAMS_COUNT];
        uint32              m_HonorScoreTics[BG_TEAMS_COUNT];
        uint32              m_ReputationScoreTics[BG_TEAMS_COUNT];
        bool                m_IsInformedNearVictory;
        uint32              m_HonorTics;
        uint32              m_ReputationTics;
        // need for achievements
        bool                m_TeamScores500Disadvantage[BG_TEAMS_COUNT];
};
#endif
