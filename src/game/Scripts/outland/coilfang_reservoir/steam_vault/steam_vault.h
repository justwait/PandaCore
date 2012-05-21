/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_STEAM_VAULT_H
#define DEF_STEAM_VAULT_H

enum
{
    MAX_ENCOUNTER                   = 3,

    TYPE_HYDROMANCER_THESPIA        = 1,
    TYPE_MEKGINEER_STEAMRIGGER      = 2,
    TYPE_WARLORD_KALITHRESH         = 3,

    NPC_NAGA_DISTILLER              = 17954,
    NPC_STEAMRIGGER                 = 17796,
    NPC_KALITHRESH                  = 17798,
    //NPC_THESPIA                   = 17797,

    GO_MAIN_CHAMBERS_DOOR           = 183049,
    GO_ACCESS_PANEL_HYDRO           = 184125,
    GO_ACCESS_PANEL_MEK             = 184126,
};

class instance_steam_vault : public ScriptedInstance
{
    public:
        instance_steam_vault(Map* pMap);

        void Initialize();

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void OnCreatureDeath(Creature* pCreature);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
};

#endif
