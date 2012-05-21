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

#ifndef __BattleGroundSM_H
#define __BattleGroundSM_H

class BattleGround;
//MAP OF SILVERSHARD MINES
/* ########################################################################## */
/* #                 wwwwwwww                   wwwwwwwwww         ******   # */
/* #    ******        wwwwww           =========================== *    *   # */
/* #    *    * ===================  ===          wwwwwwwww         * D2 *   # */
/* #    * D1 *        wwwwww      X1          ||||||||||||         *    *   # */
/* #    *    *        wwwwww       =        |||          ||        ******   # */
/* #    ******      |||||||||      =        |             |            ==   # */
/* #              |||       ||     =        |             ||||||||      =   # */
/* #            |||          |     =        |                    |||    =   # */
/* #||||      |||           ||     =        |||        A           ||   =   # */
/* #   ||||||||||          ||      =          ||||||                ||  ==  # */
/* #                      ||       =               ||                |   =  # */
/* #                     ||       C1                 |              ||   =  # */
/* #                   |||                           |||            |   =   # */
/* #                 |||        ==C2 C3=              ||         ||||   =   # */
/* #             |||||       ==        ====           ||    S2||||||   ==   # */
/* #           |||       ==               ===         ||||||||||||   ===    # */
/* #         S1||       ===                  ===                T2 ====     # */
/* # ||||||||||   T1 ==              ||       ====          =======   ||||||# */
/* #||             ==         ||||||| |||||      =====X2=====   T2||||      # */
/* #             ==         |||          ||||          =      ||||          # */
/* #          ==    T1     ||     H         ||          ==  ||          ||| # */
/* #  ******  =          |||                 ||          ||||       |||||   # */
/* #  *    *           |||                   |         |||  ==== ||||       # */
/* #  * D3 *          ||                     |        ||       =||******    # */
/* #  *    *         ||                      |||||||||         || *    *    # */
/* #  ******        ||                                       |||  * D4 *    # */
/* #               |                                        ||    *    *    # */
/* #               |                                       |      ******    # */
/* ########################################################################## */
enum BG_SM_SPELLS
{
    BG_SM_CART_START_SPELL              = 111827,
    BG_SM_CART_1_PLAYER_IN_RANGE_SPELL  = 115904,
	BG_SM_CART_2_PLAYER_IN_RANGE_SPELL  = 116488,
	BG_SM_CART_3_PLAYER_IN_RANGE_SPELL  = 116490,
	BG_SM_CART_4_PLAYER_IN_RANGE_SPELL  = 116491,
	BG_SM_CART_5_PLAYER_IN_RANGE_SPELL  = 116492,
	BG_SM_CART_CONTROL_SPELL            = 115815,
	BG_SM_TRAP_1_SPELL                  = 115815,
	BG_SM_TRAP_2_SPELL                  = 115815,
};

enum BG_SM_NPC
{
    BG_SM_NPC_CART_1					= 46485,		//C1
	BG_SM_NPC_CART_2    				= 46485,		//C2
	BG_SM_NPC_CART_3    				= 46485,		//C3
	BG_SM_NPC_TRAP_1    				= 46485,		//T1		
	BG_SM_NPC_TRAP_2    				= 46485,		//T2
};

enum BG_SM_GO							// Gameobjects
{
    BG_SM_GO_TRAP_SWITCH_1				= 46485,		//S1
	BG_SM_GO_TRAP_SWITCH_2    			= 46485,		//S2
	BG_SM_GO_TRACK_SWITCH_1     		= 46485,		//X1
	BG_SM_GO_TRACK_SWITCH_2     		= 46485,		//X2
};

enum BG_SM_DEPOTS_AT					// Depot Area Trigger
{
    BG_SM_DEPOT_AT_1     				= 46485,		//D1
	BG_SM_DEPOT_AT_2     				= 46485,		//D2
	BG_SM_DEPOT_AT_3     				= 46485,		//D3
	BG_SM_DEPOT_AT_4     				= 46485,		//D4
};

/*
Cart 1 (GREEN) can go to depot 1 or 2
Cart 2 (YELLOW) can go to depot 3
Cart 3 (ORANGE) can go to depot 2 or 4
*/
// x, y, z, o
const float BG_SM_CART1_WP1[50][4] = {         //Waypoints for Mine Cart 1 from START1 to SWITCH1
    {1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	{1185.71f, 1185.24f, -56.36f, 2.56f},      // 6
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 7
    {817.66f, 843.34f, -56.54f, 3.01f},        // 8
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 9
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 10
};

const float BG_SM_CART1_WP2[50][4] = {         //Waypoints for Mine Cart 1 from SWITCH1 to DEPOT1
    {1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	{1185.71f, 1185.24f, -56.36f, 2.56f},      // 6
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 7
    {817.66f, 843.34f, -56.54f, 3.01f},        // 8
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 9
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 10
};

const float BG_SM_CART1_WP3[50][4] = {         //Waypoints for Mine Cart 1 from SWITCH1 to DEPOT2
    {1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	{1185.71f, 1185.24f, -56.36f, 2.56f},      // 6
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 7
    {817.66f, 843.34f, -56.54f, 3.01f},        // 8
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 9
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 10
};

const float BG_SM_CART2_WP1[50][4] = {         //Waypoints for Mine Cart 2 from START2 to DEPOT3
    {1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	{1185.71f, 1185.24f, -56.36f, 2.56f},      // 6
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 7
    {817.66f, 843.34f, -56.54f, 3.01f},        // 8
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 9
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 10
};

const float BG_SM_CART3_WP1[50][4] = {         //Waypoints for Mine Cart 3 from START3 to SWITCH2
    {1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	{1185.71f, 1185.24f, -56.36f, 2.56f},      // 6
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 7
    {817.66f, 843.34f, -56.54f, 3.01f},        // 8
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 9
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 10
};

const float BG_SM_CART3_WP2[50][4] = {         //Waypoints for Mine Cart 3 from SWITCH2 to DEPOT2
    {1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	{1185.71f, 1185.24f, -56.36f, 2.56f},      // 6
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 7
    {817.66f, 843.34f, -56.54f, 3.01f},        // 8
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 9
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 10
};

const float BG_SM_CART3_WP3[50][4] = {         //Waypoints for Mine Cart 3 from SWITCH2 to DEPOT4
    {1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	{1185.71f, 1185.24f, -56.36f, 2.56f},      // 6
    {990.75f, 1008.18f, -42.60f, 2.43f},       // 7
    {817.66f, 843.34f, -56.54f, 3.01f},        // 8
    {807.46f, 1189.16f, 11.92f, 5.44f},        // 9
    {1146.62f, 816.94f, -98.49f, 6.14f},       // 10
};
enum BG_SM_WorldStates
{
    BG_SM_OP_RESOURCES_ALLY             = 1776,
    BG_SM_OP_RESOURCES_HORDE            = 1777,
    BG_SM_OP_RESOURCES_MAX              = 1780,
    BG_SM_OP_RESOURCES_WARNING          = 1955
};

const uint32 BG_SM_OP_CARTSTATES[3] =    {1767, 1782, 1772};

const uint32 BG_SM_OP_CARTICONS[3]  =    {1842, 1846, 1845};

enum BG_SM_ObjectType
{
    // TODO drop them (pool-system should be used for this)
    //buffs
    BG_SM_OBJECT_SPEEDBUFF_1             = 1,
    BG_SM_OBJECT_REGENBUFF_1             = 2,
    BG_SM_OBJECT_BERSERKBUFF_1           = 3,
    BG_SM_OBJECT_SPEEDBUFF_2             = 4,
    BG_SM_OBJECT_REGENBUFF_2             = 5,
    BG_SM_OBJECT_BERSERKBUFF_2           = 6,
    BG_SM_OBJECT_SPEEDBUFF_3             = 7,
    BG_SM_OBJECT_REGENBUFF_3             = 8,
    BG_SM_OBJECT_BERSERKBUFF_3           = 9,
    BG_SM_OBJECT_MAX                     = 10,
};


/* CART events */
// CART-events are just event1=BG_SM_CARTS, event2=BG_SM_CARTStatus
// so we don't need to define the constants here :)

enum BG_SM_Timers
{
    BG_SM_CART_CAPTURING_TIME           = 60000,
};

enum BG_SM_Score
{
    BG_SM_WARNING_NEAR_VICTORY_SCORE    = 1400,
    BG_SM_MAX_TEAM_SCORE                = 1600
};

/* do NOT change the order, else wrong behaviour */
enum BG_SM_CARTS
{
    BG_SM_CART_1                = 0,
    BG_SM_CART_2                = 1,
    BG_SM_CART_3                = 2,
    BG_SM_CARTS_ERROR           = 255
};

#define BG_SM_CARTS_MAX   3

enum BG_SM_CARTStatus
{
    BG_SM_CART_TYPE_NEUTRAL             = 0,
	BG_SM_CART_TYPE_CONTESTED           = 1,
    BG_SM_CART_STATUS_ALLY_CONTESTED    = 1,
    BG_SM_CART_STATUS_HORDE_CONTESTED   = 2,
    BG_SM_CART_TYPE_OCCUPIED            = 3,
    BG_SM_CART_STATUS_ALLY_OCCUPIED     = 3,
    BG_SM_CART_STATUS_HORDE_OCCUPIED    = 4
};

enum BG_SM_Sounds
{
    BG_SM_SOUND_CART_CLAIMED            = 8192,
    BG_SM_SOUND_CART_CAPTURED_ALLIANCE  = 8173,
    BG_SM_SOUND_CART_CAPTURED_HORDE     = 8213,
    BG_SM_SOUND_CART_ASSAULTED_ALLIANCE = 8212,
    BG_SM_SOUND_CART_ASSAULTED_HORDE    = 8174,
    BG_SM_SOUND_NEAR_VICTORY            = 8456
};

#define BG_SM_EVENT_START_BATTLE            9158

// Tick intervals and given points: case 0,1,2 captured CARTS
const uint32 BG_SM_TickPoints[1] = {200};

// WorldSafeLocs ids for ally, and horde starting location
const uint32 BG_SM_GraveyardIds[6] = {4074, 4075, 4073, 4072, 4062, 4061};

// x, y, z, o
const float BG_SM_BuffPositions[BG_SM_CARTS_MAX][4] = {
    {1185.71f, 1185.24f, -56.36f, 2.56f},                   // 1
    {990.75f, 1008.18f, -42.60f, 2.43f},                    // 2
    {817.66f, 843.34f, -56.54f, 3.01f},                     // 3
};

struct BG_SM_CartTimer
{
    uint32      timer;
    uint8       type;
    uint8       teamIndex;
};

class BattleGroundSMScore : public BattleGroundScore
{
    public:
        BattleGroundSMScore(): CARTSHelped(0) {};
        virtual ~BattleGroundSMScore() {};
        uint32 CARTSHelped;
};

class BattleGroundSM : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundSM();
        ~BattleGroundSM();

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

        /* CARTS occupying */
        virtual void EventPlayerClickedOnCART(Player *source, GameObject* target_obj);

    private:
        /* Gameobject spawning/despawning */
        void _CreateCart(uint8 CART, uint8 type, uint8 teamIndex, bool delay);
        void _DelCart(uint8 CART, uint8 type, uint8 teamIndex);
        void _SendCARTUpdate(uint8 CART);

        /* Creature spawning/despawning */
        // TODO: working, scripted peons spawning
        void _CARTOccupied(uint8 CART,Team team);

        int32 _GetCARTNameId(uint8 CART);

        /* CARTS info:
            0: neutral
            1: ally contested
            2: horde contested
            3: ally occupied
            4: horde occupied     */
        uint8               m_CARTS[BG_SM_CARTS_MAX];
        uint8               m_prevCARTS[BG_SM_CARTS_MAX];   // used for performant wordlstate-updating
        BG_SM_CartTimer   m_CartTimers[BG_SM_CARTS_MAX];
        uint32              m_CARTTimers[BG_SM_CARTS_MAX];
        uint32              m_lastTick[BG_TEAMS_COUNT];
        bool                m_IsInformedNearVictory;
};
#endif
