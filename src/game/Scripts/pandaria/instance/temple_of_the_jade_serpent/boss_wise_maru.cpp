/* ScriptData
SDName: Script for Boss Maru in instance "Temple of the jade serpent"
SD%Complete: 0
EndScriptData */

#include "pchdef.h"
#include "instance_temple_of_the_jade_serpent.h"

enum
{
    // Enums for the Script for a better Overview
    SAY_ENTER_COMBAT = -1469003
};

struct boss_wise_maru : public ScriptedAI
{
    // *** HANDLED FUNCTION ***
    // This is the constructor, called only once when the creature is first created
    boss_wise_maru(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    // *** CUSTOM VARIABLES ****
    // These variables are for use only by this individual script.
    // Nothing else will ever call them but us.

    uint32 m_uiSayTimer;                                    // Timer for random chat
    uint32 m_uiRebuffTimer;                                 // Timer for rebuffing
    uint32 m_uiSpellOneTimer;                               // Timer for spell 1 when in combat
    uint32 m_uiSpellTwoTimer;                               // Timer for spell 1 when in combat
    uint32 m_uiSpellThreeTimer;                             // Timer for spell 1 when in combat
    uint32 m_uiBeserkTimer;                                 // Timer until we go into Beserk (enraged) mode
    uint32 m_uiPhase;                                       // The current battle phase we are in
    uint32 m_uiPhaseTimer;                                  // Timer until phase transition

    // *** HANDLED FUNCTION ***
    // This is called whenever the core decides we need to evade
    void Reset()
    {
        m_uiPhase           = 0;
        m_uiPhaseTimer      = 0;
        m_uiSpellOneTimer   = 0;
        m_uiSpellTwoTimer   = 0;
        m_uiSpellThreeTimer = 0;
        m_uiBeserkTimer     = 0;
    }

    // *** HANDLED FUNCTION ***
    // Aggro is called when we enter combat, against an enemy, and haven't been in combat before
    void Aggro(Unit* pWho)
    {
        // Say some stuff
        DoScriptText(SAY_ENTER_COMBAT, m_creature, pWho);

        // Can also cast any Spells/Buffs
    }

    // *** HANDLED FUNCTION ***
    // Update AI is called Every single map update (roughly once every 100ms if a player is within the grid)
    void UpdateAI(const uint32 uiDiff)
    {
        // Normal behaviour: if possible mobs do attack with melee
        DoMeleeAttackIfReady();
    }
};

// This is the GetAI method used by all scripts that involve AI
// It is called every time a new creature using this script is created
CreatureAI* GetAI_boss_wise_maru(Creature* pCreature)
{
    return new boss_wise_maru(pCreature);
}

// This is the actual function called only once durring InitScripts()
// It must define all handled functions that are to be run in this script
void AddSC_boss_wise_maru()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_wise_maru";
    pNewScript->GetAI = &GetAI_boss_wise_maru;
    pNewScript->RegisterSelf(false);
}