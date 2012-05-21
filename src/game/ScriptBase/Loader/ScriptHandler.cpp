/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#include "pchdef.h"

// battlegrounds
extern void AddSC_battleground();

// world
extern void AddSC_areatrigger_scripts();
extern void AddSC_bosses_emerald_dragons();
extern void AddSC_generic_creature();
extern void AddSC_go_scripts();
extern void AddSC_guards();
extern void AddSC_item_scripts();
extern void AddSC_npc_professions();
extern void AddSC_npcs_special();
extern void AddSC_spell_scripts();
extern void AddSC_world_map_scripts();

// eastern kingdoms
extern void AddSC_blackrock_depths();                       // blackrock_depths
extern void AddSC_boss_ambassador_flamelash();
extern void AddSC_boss_anubshiah();
extern void AddSC_boss_coren_direbrew();
extern void AddSC_boss_draganthaurissan();
extern void AddSC_boss_general_angerforge();
extern void AddSC_boss_gorosh_the_dervish();
extern void AddSC_boss_grizzle();
extern void AddSC_boss_high_interrogator_gerstahn();
extern void AddSC_boss_magmus();
extern void AddSC_boss_tomb_of_seven();
extern void AddSC_instance_blackrock_depths();
extern void AddSC_boss_drakkisath();                        // blackrock_spire
extern void AddSC_boss_halycon();
extern void AddSC_boss_highlordomokk();
extern void AddSC_boss_mothersmolderweb();
extern void AddSC_boss_overlordwyrmthalak();
extern void AddSC_boss_shadowvosh();
extern void AddSC_boss_thebeast();
extern void AddSC_boss_warmastervoone();
extern void AddSC_boss_quatermasterzigris();
extern void AddSC_boss_pyroguard_emberseer();
extern void AddSC_boss_gyth();
extern void AddSC_boss_rend_blackhand();
extern void AddSC_instance_blackrock_spire();
extern void AddSC_boss_razorgore();                         // blackwing_lair
extern void AddSC_boss_vaelastrasz();
extern void AddSC_boss_broodlord();
extern void AddSC_boss_firemaw();
extern void AddSC_boss_ebonroc();
extern void AddSC_boss_flamegor();
extern void AddSC_boss_chromaggus();
extern void AddSC_boss_nefarian();
extern void AddSC_boss_victor_nefarius();
extern void AddSC_instance_blackwing_lair();
extern void AddSC_gnomeregan();                             // gnomeregan
extern void AddSC_boss_thermaplugg();
extern void AddSC_instance_gnomeregan();
extern void AddSC_boss_attumen();                           // karazhan
extern void AddSC_boss_curator();
extern void AddSC_boss_maiden_of_virtue();
extern void AddSC_boss_shade_of_aran();
extern void AddSC_boss_netherspite();
extern void AddSC_boss_nightbane();
extern void AddSC_boss_prince_malchezaar();
extern void AddSC_boss_terestian_illhoof();
extern void AddSC_boss_moroes();
extern void AddSC_bosses_opera();
extern void AddSC_chess_event();
extern void AddSC_instance_karazhan();
extern void AddSC_karazhan();
extern void AddSC_boss_felblood_kaelthas();                 // magisters_terrace
extern void AddSC_boss_selin_fireheart();
extern void AddSC_boss_vexallus();
extern void AddSC_boss_priestess_delrissa();
extern void AddSC_instance_magisters_terrace();
extern void AddSC_magisters_terrace();
extern void AddSC_boss_lucifron();                          // molten_core
extern void AddSC_boss_magmadar();
extern void AddSC_boss_gehennas();
extern void AddSC_boss_garr();
extern void AddSC_boss_baron_geddon();
extern void AddSC_boss_shazzrah();
extern void AddSC_boss_golemagg();
extern void AddSC_boss_sulfuron();
extern void AddSC_boss_majordomo();
extern void AddSC_boss_ragnaros();
extern void AddSC_instance_molten_core();
extern void AddSC_molten_core();
extern void AddSC_ebon_hold();                              // scarlet_enclave
extern void AddSC_boss_magistrate_barthilas();              // stratholme
extern void AddSC_boss_maleki_the_pallid();
extern void AddSC_boss_nerubenkan();
extern void AddSC_boss_cannon_master_willey();
extern void AddSC_boss_baroness_anastari();
extern void AddSC_boss_ramstein_the_gorger();
extern void AddSC_boss_timmy_the_cruel();
extern void AddSC_boss_postmaster_malown();
extern void AddSC_boss_baron_rivendare();
extern void AddSC_boss_dathrohan_balnazzar();
extern void AddSC_boss_order_of_silver_hand();
extern void AddSC_instance_stratholme();
extern void AddSC_stratholme();
extern void AddSC_instance_sunken_temple();                 // sunken_temple
extern void AddSC_sunken_temple();
extern void AddSC_boss_brutallus();                         // sunwell_plateau
extern void AddSC_boss_eredar_twins();
extern void AddSC_boss_felmyst();
extern void AddSC_boss_kalecgos();
extern void AddSC_boss_kiljaeden();
extern void AddSC_boss_muru();
extern void AddSC_instance_sunwell_plateau();
extern void AddSC_boss_archaedas();                         // uldaman
extern void AddSC_instance_uldaman();
extern void AddSC_uldaman();

extern void AddSC_alterac_mountains();
extern void AddSC_arathi_highlands();
extern void AddSC_blasted_lands();
extern void AddSC_boss_kruul();
extern void AddSC_burning_steppes();
extern void AddSC_dun_morogh();
extern void AddSC_eastern_plaguelands();
extern void AddSC_elwynn_forest();
extern void AddSC_eversong_woods();
extern void AddSC_ghostlands();
extern void AddSC_hinterlands();
extern void AddSC_ironforge();
extern void AddSC_isle_of_queldanas();
extern void AddSC_loch_modan();
extern void AddSC_redridge_mountains();
extern void AddSC_searing_gorge();
extern void AddSC_silvermoon_city();
extern void AddSC_silverpine_forest();
extern void AddSC_stormwind_city();
extern void AddSC_stranglethorn_vale();
extern void AddSC_swamp_of_sorrows();
extern void AddSC_tirisfal_glades();
extern void AddSC_undercity();
extern void AddSC_western_plaguelands();
extern void AddSC_westfall();
extern void AddSC_wetlands();

// kalimdor
extern void AddSC_instance_blackfathom_deeps();             // blackfathom_deeps
extern void AddSC_boss_aeonus();                            // COT, dark_portal
extern void AddSC_boss_chrono_lord_deja();
extern void AddSC_boss_temporus();
extern void AddSC_dark_portal();
extern void AddSC_instance_dark_portal();
extern void AddSC_hyjal();                                  // COT, hyjal
extern void AddSC_boss_archimonde();
extern void AddSC_instance_mount_hyjal();
extern void AddSC_boss_captain_skarloc();                   // COT, old_hillsbrad
extern void AddSC_boss_epoch_hunter();
extern void AddSC_boss_lieutenant_drake();
extern void AddSC_instance_old_hillsbrad();
extern void AddSC_old_hillsbrad();
extern void AddSC_culling_of_stratholme();                  // COT, culling_of_stratholme
extern void AddSC_instance_culling_of_stratholme();
extern void AddSC_dire_maul();                              // dire_maul
extern void AddSC_instance_dire_maul();
extern void AddSC_boss_celebras_the_cursed();               // maraudon
extern void AddSC_boss_landslide();
extern void AddSC_boss_noxxion();
extern void AddSC_boss_ptheradras();
extern void AddSC_boss_onyxia();                            // onyxias_lair
extern void AddSC_instance_onyxias_lair();
extern void AddSC_boss_amnennar_the_coldbringer();          // razorfen_downs
extern void AddSC_razorfen_downs();
extern void AddSC_instance_razorfen_kraul();                // razorfen_kraul
extern void AddSC_razorfen_kraul();
extern void AddSC_boss_ayamiss();                           // ruins_of_ahnqiraj
extern void AddSC_boss_buru();
extern void AddSC_boss_kurinnaxx();
extern void AddSC_boss_ossirian();
extern void AddSC_boss_moam();
extern void AddSC_ruins_of_ahnqiraj();
extern void AddSC_instance_ruins_of_ahnqiraj();
extern void AddSC_boss_cthun();                             // temple_of_ahnqiraj
extern void AddSC_boss_fankriss();
extern void AddSC_boss_huhuran();
extern void AddSC_bug_trio();
extern void AddSC_boss_sartura();
extern void AddSC_boss_skeram();
extern void AddSC_boss_twinemperors();
extern void AddSC_boss_viscidus();
extern void AddSC_mob_anubisath_sentinel();
extern void AddSC_instance_temple_of_ahnqiraj();
extern void AddSC_instance_wailing_caverns();               // wailing_caverns
extern void AddSC_wailing_caverns();
extern void AddSC_boss_zumrah();                            // zulfarrak
extern void AddSC_instance_zulfarrak();
extern void AddSC_zulfarrak();

extern void AddSC_ashenvale();
extern void AddSC_azshara();
extern void AddSC_azuremyst_isle();
extern void AddSC_bloodmyst_isle();
extern void AddSC_boss_azuregos();
extern void AddSC_darkshore();
extern void AddSC_desolace();
extern void AddSC_durotar();
extern void AddSC_dustwallow_marsh();
extern void AddSC_felwood();
extern void AddSC_feralas();
extern void AddSC_moonglade();
extern void AddSC_mulgore();
extern void AddSC_orgrimmar();
extern void AddSC_silithus();
extern void AddSC_stonetalon_mountains();
extern void AddSC_tanaris();
extern void AddSC_teldrassil();
extern void AddSC_the_barrens();
extern void AddSC_thousand_needles();
extern void AddSC_thunder_bluff();
extern void AddSC_ungoro_crater();
extern void AddSC_winterspring();

// northrend
extern void AddSC_boss_jedoga();                            // azjol-nerub, ahnkahet
extern void AddSC_boss_nadox();
extern void AddSC_boss_taldaram();
extern void AddSC_boss_volazj();
extern void AddSC_instance_ahnkahet();
extern void AddSC_boss_anubarak();                          // azjol-nerub, azjol-nerub
extern void AddSC_boss_hadronox();
extern void AddSC_boss_krikthir();
extern void AddSC_instance_azjol_nerub();
extern void AddSC_trial_of_the_champion();                  // CC, trial_of_the_champion
extern void AddSC_boss_grand_champions();
extern void AddSC_instance_trial_of_the_champion();
extern void AddSC_boss_anubarak_trial();                    // CC, trial_of_the_crusader
extern void AddSC_boss_faction_champions();
extern void AddSC_boss_jaraxxus();
extern void AddSC_instance_trial_of_the_crusader();
extern void AddSC_northrend_beasts();
extern void AddSC_trial_of_the_crusader();
extern void AddSC_twin_valkyr();
extern void AddSC_boss_novos();                             // draktharon_keep
extern void AddSC_boss_tharonja();
extern void AddSC_boss_trollgore();
extern void AddSC_instance_draktharon_keep();
extern void AddSC_boss_colossus();                          // gundrak
extern void AddSC_boss_eck();
extern void AddSC_boss_galdarah();
extern void AddSC_boss_moorabi();
extern void AddSC_boss_sladran();
extern void AddSC_instance_gundrak();
extern void AddSC_boss_bronjahm();                          // ICC, forge_of_souls
extern void AddSC_boss_devourer_of_souls();
extern void AddSC_instance_forge_of_souls();
extern void AddSC_boss_falric();                            // ICC, halls_of_reflection
extern void AddSC_boss_lich_king();
extern void AddSC_boss_marwyn();
extern void AddSC_halls_of_reflection();
extern void AddSC_instance_halls_of_reflection();
extern void AddSC_boss_garfrost();                          // ICC, pit_of_saron
extern void AddSC_boss_krick_and_ick();
extern void AddSC_boss_tyrannus();
extern void AddSC_instance_pit_of_saron();
extern void AddSC_pit_of_saron();
extern void AddSC_blood_prince_council();                   // ICC, icecrown_citadel
extern void AddSC_boss_blood_queen_lanathel();
extern void AddSC_boss_deathbringer_saurfang();
extern void AddSC_boss_festergut();
extern void AddSC_boss_lady_deathwhisper();
extern void AddSC_boss_lord_marrowgar();
extern void AddSC_boss_professor_putricide();
extern void AddSC_boss_rotface();
extern void AddSC_boss_sindragosa();
extern void AddSC_boss_the_lich_king();
extern void AddSC_boss_valithria_dreamwalker();
extern void AddSC_gunship_battle();
extern void AddSC_instance_icecrown_citadel();
extern void AddSC_boss_anubrekhan();                        // naxxramas
extern void AddSC_boss_four_horsemen();
extern void AddSC_boss_faerlina();
extern void AddSC_boss_gluth();
extern void AddSC_boss_gothik();
extern void AddSC_boss_grobbulus();
extern void AddSC_boss_kelthuzad();
extern void AddSC_boss_loatheb();
extern void AddSC_boss_maexxna();
extern void AddSC_boss_noth();
extern void AddSC_boss_heigan();
extern void AddSC_boss_patchwerk();
extern void AddSC_boss_razuvious();
extern void AddSC_boss_sapphiron();
extern void AddSC_boss_thaddius();
extern void AddSC_instance_naxxramas();
extern void AddSC_boss_malygos();                           // nexus, eye_of_eternity
extern void AddSC_boss_anomalus();                          // nexus, nexus
extern void AddSC_boss_keristrasza();
extern void AddSC_boss_ormorok();
extern void AddSC_boss_telestra();
extern void AddSC_instance_nexus();
extern void AddSC_boss_eregos();                            // nexus, oculus
extern void AddSC_boss_urom();
extern void AddSC_instance_oculus();
extern void AddSC_boss_sartharion();                        // obsidian_sanctum
extern void AddSC_instance_obsidian_sanctum();
extern void AddSC_boss_baltharus();                         // ruby_sanctum
extern void AddSC_boss_halion();
extern void AddSC_boss_saviana();
extern void AddSC_boss_zarithrian();
extern void AddSC_instance_ruby_sanctum();
extern void AddSC_boss_bjarngrim();                         // ulduar, halls_of_lightning
extern void AddSC_boss_ionar();
extern void AddSC_boss_loken();
extern void AddSC_boss_volkhan();
extern void AddSC_instance_halls_of_lightning();
extern void AddSC_boss_maiden_of_grief();                   // ulduar, halls_of_stone
extern void AddSC_boss_sjonnir();
extern void AddSC_halls_of_stone();
extern void AddSC_instance_halls_of_stone();
extern void AddSC_boss_assembly_of_iron();                  // ulduar, ulduar
extern void AddSC_boss_algalon();
extern void AddSC_boss_auriaya();
extern void AddSC_boss_flame_leviathan();
extern void AddSC_boss_freya();
extern void AddSC_boss_general_vezax();
extern void AddSC_boss_hodir();
extern void AddSC_boss_ignis();
extern void AddSC_boss_kologarn();
extern void AddSC_boss_mimiron();
extern void AddSC_boss_razorscale();
extern void AddSC_boss_thorim();
extern void AddSC_boss_xt_002();
extern void AddSC_boss_yogg_saron();
extern void AddSC_instance_ulduar();
extern void AddSC_ulduar();
extern void AddSC_boss_ingvar();                            // utgarde_keep, utgarde_keep
extern void AddSC_boss_keleseth();
extern void AddSC_boss_skarvald_and_dalronn();
extern void AddSC_instance_utgarde_keep();
extern void AddSC_utgarde_keep();
extern void AddSC_boss_gortok();                           // utgarde_keep, utgarde_pinnacle
extern void AddSC_boss_skadi();
extern void AddSC_boss_svala();
extern void AddSC_boss_ymiron();
extern void AddSC_instance_pinnacle();
extern void AddSC_boss_archavon();                          // vault_of_archavon
extern void AddSC_boss_emalon();
extern void AddSC_boss_koralon();
extern void AddSC_boss_toravon();
extern void AddSC_instance_vault_of_archavon();
extern void AddSC_boss_erekem();                            // violet_hold
extern void AddSC_boss_ichoron();
extern void AddSC_instance_violet_hold();
extern void AddSC_violet_hold();

extern void AddSC_borean_tundra();
extern void AddSC_dalaran();
extern void AddSC_dragonblight();
extern void AddSC_grizzly_hills();
extern void AddSC_howling_fjord();
extern void AddSC_icecrown();
extern void AddSC_sholazar_basin();
extern void AddSC_storm_peaks();
extern void AddSC_zuldrak();

// outland
extern void AddSC_boss_exarch_maladaar();                   // auchindoun, auchenai_crypts
extern void AddSC_boss_shirrak();
extern void AddSC_boss_nexusprince_shaffar();               // auchindoun, mana_tombs
extern void AddSC_boss_pandemonius();
extern void AddSC_boss_anzu();                              // auchindoun, sethekk_halls
extern void AddSC_boss_darkweaver_syth();
extern void AddSC_boss_talon_king_ikiss();
extern void AddSC_instance_sethekk_halls();
extern void AddSC_boss_ambassador_hellmaw();                // auchindoun, shadow_labyrinth
extern void AddSC_boss_blackheart_the_inciter();
extern void AddSC_boss_grandmaster_vorpil();
extern void AddSC_boss_murmur();
extern void AddSC_instance_shadow_labyrinth();
extern void AddSC_black_temple();                           // black_temple
extern void AddSC_boss_illidan();
extern void AddSC_boss_shade_of_akama();
extern void AddSC_boss_supremus();
extern void AddSC_boss_gurtogg_bloodboil();
extern void AddSC_boss_mother_shahraz();
extern void AddSC_boss_reliquary_of_souls();
extern void AddSC_boss_teron_gorefiend();
extern void AddSC_boss_najentus();
extern void AddSC_boss_illidari_council();
extern void AddSC_instance_black_temple();
extern void AddSC_boss_fathomlord_karathress();             // CR, serpent_shrine
extern void AddSC_boss_hydross_the_unstable();
extern void AddSC_boss_lady_vashj();
extern void AddSC_boss_leotheras_the_blind();
extern void AddSC_boss_morogrim_tidewalker();
extern void AddSC_boss_the_lurker_below();
extern void AddSC_instance_serpentshrine_cavern();
extern void AddSC_boss_ahune();                             // CR, slave_pens
extern void AddSC_boss_hydromancer_thespia();               // CR, steam_vault
extern void AddSC_boss_mekgineer_steamrigger();
extern void AddSC_boss_warlord_kalithresh();
extern void AddSC_instance_steam_vault();
extern void AddSC_boss_hungarfen();                         // CR, Underbog
extern void AddSC_boss_gruul();                             // gruuls_lair
extern void AddSC_boss_high_king_maulgar();
extern void AddSC_instance_gruuls_lair();
extern void AddSC_boss_broggok();                           // HC, blood_furnace
extern void AddSC_boss_kelidan_the_breaker();
extern void AddSC_boss_the_maker();
extern void AddSC_instance_blood_furnace();
extern void AddSC_boss_nazan_and_vazruden();                // HC, hellfire_ramparts
extern void AddSC_boss_omor_the_unscarred();
extern void AddSC_boss_watchkeeper_gargolmar();
extern void AddSC_instance_ramparts();
extern void AddSC_boss_magtheridon();                       // HC, magtheridons_lair
extern void AddSC_instance_magtheridons_lair();
extern void AddSC_boss_grand_warlock_nethekurse();          // HC, shattered_halls
extern void AddSC_boss_warbringer_omrogg();
extern void AddSC_boss_warchief_kargath_bladefist();
extern void AddSC_instance_shattered_halls();
extern void AddSC_arcatraz();                               // TK, arcatraz
extern void AddSC_boss_harbinger_skyriss();
extern void AddSC_instance_arcatraz();
extern void AddSC_boss_high_botanist_freywinn();            // TK, botanica
extern void AddSC_boss_laj();
extern void AddSC_boss_warp_splinter();
extern void AddSC_boss_alar();                              // TK, the_eye
extern void AddSC_boss_high_astromancer_solarian();
extern void AddSC_boss_kaelthas();
extern void AddSC_boss_void_reaver();
extern void AddSC_instance_the_eye();
extern void AddSC_the_eye();
extern void AddSC_boss_gatewatcher_iron_hand();             // TK, the_mechanar
extern void AddSC_boss_nethermancer_sepethrea();
extern void AddSC_boss_pathaleon_the_calculator();
extern void AddSC_instance_mechanar();

extern void AddSC_blades_edge_mountains();
extern void AddSC_boss_doomlordkazzak();
extern void AddSC_boss_doomwalker();
extern void AddSC_hellfire_peninsula();
extern void AddSC_nagrand();
extern void AddSC_netherstorm();
extern void AddSC_shadowmoon_valley();
extern void AddSC_shattrath_city();
extern void AddSC_terokkar_forest();
extern void AddSC_zangarmarsh();

// Cataclysm
//Raids 6
extern void AddSC_instance_baradin_hold();                    //Baradin Hold
extern void AddSC_boss_argaloth();
extern void AddSC_boss_occuthar();
extern void AddSC_boss_alizabal();
extern void AddSC_instance_blackwing_descent();                //Blackwing Decent
extern void AddSC_boss_magmaw();
extern void AddSC_boss_omnotron();
extern void AddSC_boss_maloriak();
extern void AddSC_boss_atramedes();
extern void AddSC_boss_chimaeron();
extern void AddSC_boss_nefarian_onyxia();
extern void AddSC_instance_dragon_soul();                    //Dragon Soul
extern void AddSC_boss_morchok();
extern void AddSC_boss_warlord_zonozz();
extern void AddSC_boss_yorsahi_the_unsleeping();
extern void AddSC_boss_hagara_the_stormbinder();
extern void AddSC_boss_ultraxion();
extern void AddSC_boss_warmaster_blackhorn();
extern void AddSC_boss_spine_of_deathwing();
extern void AddSC_boss_madness_of_deathwing();
extern void AddSC_instance_firelands();                        //Firelands
extern void AddSC_boss_shannox();
extern void AddSC_boss_lord_rhyolith();
extern void AddSC_boss_bethtilac();
extern void AddSC_boss_alysrazor();
extern void AddSC_boss_baleroc();
extern void AddSC_boss_major_domo();
extern void AddSC_boss_ragnaros_final();
extern void AddSC_instance_the_bastion_of_twilight();         //The Bastion Of Twilight
extern void AddSC_boss_halfus_wyrmbreaker();
extern void AddSC_boss_theralion_and_valiona();
extern void AddSC_boss_ascendant_council();
extern void AddSC_boss_chogall();
extern void AddSC_boss_sinestra();
extern void AddSC_instance_throne_of_the_four_winds();        // Throne of the Four Winds
extern void AddSC_boss_conclave_of_wind();
extern void AddSC_boss_alakir();
//Instances 14
extern void AddSC_instance_throne_of_the_tides();            //Abyssal Maw: Throne of the Tides
extern void AddSC_boss_lady_nazjar();
extern void AddSC_boss_commander_ulthok();
extern void AddSC_boss_erunak_ghursha();
extern void AddSC_boss_ozumat();
extern void AddSC_instance_blackrock_caverns();                //Blackrock Caverns
extern void AddSC_boss_romogg_bonecrusher();
extern void AddSC_boss_corla_herald_of_twilight();
extern void AddSC_boss_karsh_steelbender();
extern void AddSC_boss_beauty();
extern void AddSC_boss_ascendant_lord_obsidius();
extern void AddSC_instance_deadmines();                     //Deadmines
extern void AddSC_boss_glubtok();
extern void AddSC_boss_helix_gearbreaker();
extern void AddSC_boss_foe_reaper_5000();
extern void AddSC_boss_admiral_ripsnarl();
extern void AddSC_boss_cookie();
extern void AddSC_boss_vanessa_vancleef();
extern void AddSC_instance_end_time();                        //End Time
extern void AddSC_boss_echo_of_baine();
extern void AddSC_boss_echo_of_jaina();
extern void AddSC_boss_echo_of_sylvanas();
extern void AddSC_boss_echo_of_tyrande();
extern void AddSC_boss_murozond();
extern void AddSC_instance_grim_batol();                    //Grimbatol
extern void AddSC_boss_general_umbriss();
extern void AddSC_boss_forgemaster_throngus();
extern void AddSC_boss_drahga_shadowburner();
extern void AddSC_boss_erudax();
extern void AddSC_instance_halls_of_origination();            //Halls of Origination
extern void AddSC_boss_temple_guardian_anhuur();
extern void AddSC_boss_earthrager_ptah();
extern void AddSC_boss_anraphet();
extern void AddSC_boss_isiset();
extern void AddSC_boss_ammunae();
extern void AddSC_boss_setesh();
extern void AddSC_boss_rajh();
extern void AddSC_instance_hour_of_twilight();                //Hour of Twilight
extern void AddSC_boss_arcurion();
extern void AddSC_boss_asira_dawnslayer();
extern void AddSC_boss_archbishop_benedictus();
extern void AddSC_instance_shadowfang_keep();               //Shadowfang Keep
extern void AddSC_boss_baron_ashbury();
extern void AddSC_boss_baron_silverlaine();
extern void AddSC_boss_commander_springvale();
extern void AddSC_boss_lord_walden();
extern void AddSC_boss_lord_godfrey();
extern void AddSC_instance_lost_city_of_the_tolvir();        //The Lost City of the Tol'vir
extern void AddSC_boss_husam();
extern void AddSC_boss_high_prophet_barim();
extern void AddSC_boss_lockmaw();
extern void AddSC_boss_siamat();
extern void AddSC_instance_the_stonecore();                    //The Stonecore
extern void AddSC_boss_corborus();
extern void AddSC_boss_slabhide();
extern void AddSC_boss_ozruk();
extern void AddSC_boss_priestess_azil();
extern void AddSC_instance_vortex_pinnacle();                //Vortex Pinnacle
extern void AddSC_boss_grand_vizier_ertan();
extern void AddSC_boss_altairus();
extern void AddSC_boss_asaad();
extern void AddSC_instance_well_of_eternity();                //Well of Eternity
extern void AddSC_boss_perotharn();
extern void AddSC_boss_queen_azshara();
extern void AddSC_boss_mannaroth_varothen();
extern void AddSC_instance_zul_aman();                        //Zul_aman
extern void AddSC_boss_akilzon();
extern void AddSC_boss_nalorakk();
extern void AddSC_boss_janalai();
extern void AddSC_boss_halazzi();
extern void AddSC_boss_malacrass();
extern void AddSC_boss_zuljin();
extern void AddSC_instance_zul_gurub();                      //Zul_gurub
extern void AddSC_boss_venoxis();
extern void AddSC_boss_mandokir();
extern void AddSC_boss_edge_of_madness();
extern void AddSC_boss_kilnara();
extern void AddSC_boss_zanzil();
extern void AddSC_boss_jindo();
//Zones 13
extern void AddSC_ahnqiraj_fallen_kingdom();
extern void AddSC_darkmoon();
extern void AddSC_deepholm();
extern void AddSC_gilneas();
extern void AddSC_lost_isles();
extern void AddSC_molten_front();
extern void AddSC_mount_hyjal();
extern void AddSC_the_maelstrom();
extern void AddSC_tol_barad();
extern void AddSC_twilight_highlands();
extern void AddSC_uldum();
extern void AddSC_vashjir();
extern void AddSC_instance_kezan();
/*
// Mists Of Pandaria
//Raids 3
extern void AddSC_instance_mogushan_vaults();                // Mogu'shan Vaults
extern void AddSC_boss_the_stone_guard();
extern void AddSC_boss_feng_the_accursed();
extern void AddSC_boss_garajal_the_spiritbinder();
extern void AddSC_boss_the_spirit_emporers();
extern void AddSC_boss_will_of_the_emporor();
extern void AddSC_instance_terrace_of_endless_spring();        //Terrace of Endless Spring
extern void AddSC_boss_protectors_of_the_endless();
extern void AddSC_boss_sha_of_fear();
extern void AddSC_boss_sha_of_anger();
extern void AddSC_instance_mantid();                        // Mantid Raid
//Instances 12
extern void AddSC_instance_temple_of_the_jade_serpent();    // Temple of the Jade Serpent
extern void AddSC_boss_wise_mari();
extern void AddSC_boss_zao_sunseeker();
extern void AddSC_boss_lui_flameheart();
extern void AddSC_boss_sha_of_doubt();
extern void AddSC_instance_stormstout_brewery();            // Stormstout Brewery
extern void AddSC_boss_ook_ook();
extern void AddSC_boss_hoptallus();
extern void AddSC_boss_yan_zhu_the_uncasked();
extern void AddSC_instance_shado_pan_monastery();            // Shado Pan Monastery
extern void AddSC_instance_gate_of_the_setting_sun();        // Gate Of the Setting Sun
extern void AddSC_boss_striker_gadok();
extern void AddSC_boss_commander_rimok();
extern void AddSC_boss_saboteur_kiptilak();
extern void AddSC_boss_raigonn();
extern void AddSC_instance_mogushan_palace();                // Mogu'shan Palace
extern void AddSC_boss_clan_leaders_of_the_mogu();
extern void AddSC_boss_gekkan();
extern void AddSC_boss_xin_the_weaponmaster();
extern void AddSC_instance_the_perfect_storm();                // The Perfect Storm
extern void AddSC_instance_ancient_mogu_crypt();            // Ancient Mogo Crypt
extern void AddSC_instance_the_jade_forest();                // The Jade Forest
extern void AddSC_instance_ragefire_chasm();                // Ragefire Chasm
extern void AddSC_boss_adarogg();
extern void AddSC_boss_dark_shaman_koranthal();
extern void AddSC_boss_lava_guard_gordoth();
extern void AddSC_boss_slagmaw.cpp();
extern void AddSC_instance_siege_of_niuzao_temple();        // Siege of Niuzao Temple
extern void AddSC_boss_bloodmage_thalnos();                 // scarlet_monastery_cathedral
extern void AddSC_boss_durand_and_whitemane();
extern void AddSC_boss_houndmaster_braun();                 // scarlet_monastery_scarlet_halls
extern void AddSC_boss_armsmaster_harlan();
extern void AddSC_boss_flameweaver_koegler();
extern void AddSC_boss_headless_horseman();
extern void AddSC_instance_scarlet_monastery();
extern void AddSC_instance_scholomance();                    // scholomance
extern void AddSC_boss_instructor_chillheart();
extern void AddSC_boss_jandice_barov();
extern void AddSC_boss_rattlegore();
extern void AddSC_boss_lilian_voss();
extern void AddSC_boss_darkmaster_gandling ();
//Zones 10
extern void AddSC_dread_wastes();
extern void AddSC_krasarang_wilds();
extern void AddSC_kun_lai_summit();
extern void AddSC_the_jade_forest();
extern void AddSC_townlong_steppes();
extern void AddSC_vale_of_eternal_blossoms();
extern void AddSC_valley_of_the_four_winds();
extern void AddSC_wandering_isle();
extern void AddSC_instance_the_battle_for_theramore();        // The Battle for Theramore
extern void AddSC_instance_heart_of_fear();                    // Heart  Of Fear
extern void AddSC_boss_garalon();
*/
void AddScripts()
{
    // battlegrounds
    AddSC_battleground();

    // world
    AddSC_areatrigger_scripts();
    AddSC_bosses_emerald_dragons();
    AddSC_generic_creature();
    AddSC_go_scripts();
    AddSC_guards();
    AddSC_item_scripts();
    AddSC_npc_professions();
    AddSC_npcs_special();
    AddSC_spell_scripts();
    AddSC_world_map_scripts();

    // eastern kingdoms
    AddSC_blackrock_depths();                               // blackrock_depths
    AddSC_boss_ambassador_flamelash();
    AddSC_boss_anubshiah();
    AddSC_boss_coren_direbrew();
    AddSC_boss_draganthaurissan();
    AddSC_boss_general_angerforge();
    AddSC_boss_gorosh_the_dervish();
    AddSC_boss_grizzle();
    AddSC_boss_high_interrogator_gerstahn();
    AddSC_boss_magmus();
    AddSC_boss_tomb_of_seven();
    AddSC_instance_blackrock_depths();
    AddSC_boss_drakkisath();                                // blackrock_spire
    AddSC_boss_halycon();
    AddSC_boss_highlordomokk();
    AddSC_boss_mothersmolderweb();
    AddSC_boss_overlordwyrmthalak();
    AddSC_boss_shadowvosh();
    AddSC_boss_thebeast();
    AddSC_boss_warmastervoone();
    AddSC_boss_quatermasterzigris();
    AddSC_boss_pyroguard_emberseer();
    AddSC_boss_gyth();
    AddSC_boss_rend_blackhand();
    AddSC_instance_blackrock_spire();
    AddSC_boss_razorgore();                                 // blackwing_lair
    AddSC_boss_vaelastrasz();
    AddSC_boss_broodlord();
    AddSC_boss_firemaw();
    AddSC_boss_ebonroc();
    AddSC_boss_flamegor();
    AddSC_boss_chromaggus();
    AddSC_boss_nefarian();
    AddSC_boss_victor_nefarius();
    AddSC_instance_blackwing_lair();
    AddSC_gnomeregan();                                     // gnomeregan
    AddSC_boss_thermaplugg();
    AddSC_instance_gnomeregan();
    AddSC_boss_attumen();                                   // karazhan
    AddSC_boss_curator();
    AddSC_boss_maiden_of_virtue();
    AddSC_boss_shade_of_aran();
    AddSC_boss_netherspite();
    AddSC_boss_nightbane();
    AddSC_boss_prince_malchezaar();
    AddSC_boss_terestian_illhoof();
    AddSC_boss_moroes();
    AddSC_bosses_opera();
    AddSC_chess_event();
    AddSC_instance_karazhan();
    AddSC_karazhan();
    AddSC_boss_felblood_kaelthas();                         // magisters_terrace
    AddSC_boss_selin_fireheart();
    AddSC_boss_vexallus();
    AddSC_boss_priestess_delrissa();
    AddSC_instance_magisters_terrace();
    AddSC_magisters_terrace();
    AddSC_boss_lucifron();                                  // molten_core
    AddSC_boss_magmadar();
    AddSC_boss_gehennas();
    AddSC_boss_garr();
    AddSC_boss_baron_geddon();
    AddSC_boss_shazzrah();
    AddSC_boss_golemagg();
    AddSC_boss_sulfuron();
    AddSC_boss_majordomo();
    AddSC_boss_ragnaros();
    AddSC_instance_molten_core();
    AddSC_molten_core();
    AddSC_ebon_hold();                                      // scarlet_enclave
    AddSC_boss_magistrate_barthilas();                      // stratholme
    AddSC_boss_maleki_the_pallid();
    AddSC_boss_nerubenkan();
    AddSC_boss_cannon_master_willey();
    AddSC_boss_baroness_anastari();
    AddSC_boss_ramstein_the_gorger();
    AddSC_boss_timmy_the_cruel();
    AddSC_boss_postmaster_malown();
    AddSC_boss_baron_rivendare();
    AddSC_boss_dathrohan_balnazzar();
    AddSC_boss_order_of_silver_hand();
    AddSC_instance_stratholme();
    AddSC_stratholme();
    AddSC_instance_sunken_temple();                         // sunken_temple
    AddSC_sunken_temple();
    AddSC_boss_brutallus();                                 // sunwell_plateau
    AddSC_boss_eredar_twins();
    AddSC_boss_felmyst();
    AddSC_boss_kalecgos();
    AddSC_boss_kiljaeden();
    AddSC_boss_muru();
    AddSC_instance_sunwell_plateau();
    AddSC_boss_archaedas();                                 // uldaman
    AddSC_instance_uldaman();
    AddSC_uldaman();
    
    AddSC_alterac_mountains();
    AddSC_arathi_highlands();
    AddSC_blasted_lands();
    AddSC_boss_kruul();
    AddSC_burning_steppes();
    AddSC_dun_morogh();
    AddSC_eastern_plaguelands();
    AddSC_elwynn_forest();
    AddSC_eversong_woods();
    AddSC_ghostlands();
    AddSC_hinterlands();
    AddSC_ironforge();
    AddSC_isle_of_queldanas();
    AddSC_loch_modan();
    AddSC_redridge_mountains();
    AddSC_searing_gorge();
    AddSC_silvermoon_city();
    AddSC_silverpine_forest();
    AddSC_stormwind_city();
    AddSC_stranglethorn_vale();
    AddSC_swamp_of_sorrows();
    AddSC_tirisfal_glades();
    AddSC_undercity();
    AddSC_western_plaguelands();
    AddSC_westfall();
    AddSC_wetlands();

    // kalimdor
    AddSC_instance_blackfathom_deeps();                     // blackfathom deeps
    AddSC_boss_aeonus();                                    // CoT, dark_portal
    AddSC_boss_chrono_lord_deja();
    AddSC_boss_temporus();
    AddSC_dark_portal();
    AddSC_instance_dark_portal();
    AddSC_hyjal();                                          // CoT, hyjal
    AddSC_boss_archimonde();
    AddSC_instance_mount_hyjal();
    AddSC_boss_captain_skarloc();                           // CoT, old_hillsbrand
    AddSC_boss_epoch_hunter();
    AddSC_boss_lieutenant_drake();
    AddSC_instance_old_hillsbrad();
    AddSC_old_hillsbrad();
    AddSC_culling_of_stratholme();                          // CoT, culling_of_stratholme
    AddSC_instance_culling_of_stratholme();
    AddSC_dire_maul();                                      // dire_maul
    AddSC_instance_dire_maul();
    AddSC_boss_celebras_the_cursed();                       // maraudon
    AddSC_boss_landslide();
    AddSC_boss_noxxion();
    AddSC_boss_ptheradras();
    AddSC_boss_onyxia();                                    // onyxias_lair
    AddSC_instance_onyxias_lair();
    AddSC_boss_amnennar_the_coldbringer();                  // razorfen_downs
    AddSC_razorfen_downs();
    AddSC_instance_razorfen_kraul();                        // razorfen_kraul
    AddSC_razorfen_kraul();
    AddSC_boss_ayamiss();                                   // ruins_of_ahnqiraj
    AddSC_boss_buru();
    AddSC_boss_kurinnaxx();
    AddSC_boss_ossirian();
    AddSC_boss_moam();
    AddSC_ruins_of_ahnqiraj();
    AddSC_instance_ruins_of_ahnqiraj();
    AddSC_boss_cthun();                                     // temple_of_ahnqiraj
    AddSC_boss_fankriss();
    AddSC_boss_huhuran();
    AddSC_bug_trio();
    AddSC_boss_sartura();
    AddSC_boss_skeram();
    AddSC_boss_twinemperors();
    AddSC_boss_viscidus();
    AddSC_mob_anubisath_sentinel();
    AddSC_instance_temple_of_ahnqiraj();
    AddSC_instance_wailing_caverns();                       // wailing_caverns
    AddSC_wailing_caverns();
    AddSC_boss_zumrah();                                    // zulfarrak
    AddSC_zulfarrak();
    AddSC_instance_zulfarrak();

    AddSC_ashenvale();
    AddSC_azshara();
    AddSC_azuremyst_isle();
    AddSC_bloodmyst_isle();
    AddSC_boss_azuregos();
    AddSC_darkshore();
    AddSC_desolace();
    AddSC_durotar();
    AddSC_dustwallow_marsh();
    AddSC_felwood();
    AddSC_feralas();
    AddSC_moonglade();
    AddSC_mulgore();
    AddSC_orgrimmar();
    AddSC_silithus();
    AddSC_stonetalon_mountains();
    AddSC_tanaris();
    AddSC_teldrassil();
    AddSC_the_barrens();
    AddSC_thousand_needles();
    AddSC_thunder_bluff();
    AddSC_ungoro_crater();
    AddSC_winterspring();

    // northrend
    AddSC_boss_jedoga();                                    // azjol-nerub, ahnkahet
    AddSC_boss_nadox();
    AddSC_boss_taldaram();
    AddSC_boss_volazj();
    AddSC_instance_ahnkahet();
    AddSC_boss_anubarak();                                  // azjol-nerub, azjol-nerub
    AddSC_boss_hadronox();
    AddSC_boss_krikthir();
    AddSC_instance_azjol_nerub();
    AddSC_boss_grand_champions();                           // CC, trial_of_the_champion
    AddSC_instance_trial_of_the_champion();
    AddSC_trial_of_the_champion();
    AddSC_boss_anubarak_trial();                            // CC, trial_of_the_crusader
    AddSC_boss_faction_champions();
    AddSC_boss_jaraxxus();
    AddSC_instance_trial_of_the_crusader();
    AddSC_northrend_beasts();
    AddSC_trial_of_the_crusader();
    AddSC_twin_valkyr();
    AddSC_boss_novos();                                     // draktharon_keep
    AddSC_boss_tharonja();
    AddSC_boss_trollgore();
    AddSC_instance_draktharon_keep();
    AddSC_boss_colossus();                                  // gundrak
    AddSC_boss_eck();
    AddSC_boss_galdarah();
    AddSC_boss_moorabi();
    AddSC_boss_sladran();
    AddSC_instance_gundrak();
    AddSC_boss_bronjahm();                                  // ICC, FH, forge_of_souls
    AddSC_boss_devourer_of_souls();
    AddSC_instance_forge_of_souls();
    AddSC_boss_falric();                                    // ICC, FH, halls_of_reflection
    AddSC_boss_lich_king();
    AddSC_boss_marwyn();
    AddSC_halls_of_reflection();
    AddSC_instance_halls_of_reflection();
    AddSC_boss_garfrost();                                  // ICC, FH, pit_of_saron
    AddSC_boss_krick_and_ick();
    AddSC_boss_tyrannus();
    AddSC_instance_pit_of_saron();
    AddSC_pit_of_saron();
    AddSC_blood_prince_council();                           // ICC, icecrown_citadel
    AddSC_boss_blood_queen_lanathel();
    AddSC_boss_deathbringer_saurfang();
    AddSC_boss_festergut();
    AddSC_boss_lady_deathwhisper();
    AddSC_boss_lord_marrowgar();
    AddSC_boss_professor_putricide();
    AddSC_boss_rotface();
    AddSC_boss_sindragosa();
    AddSC_boss_the_lich_king();
    AddSC_boss_valithria_dreamwalker();
    AddSC_gunship_battle();
    AddSC_instance_icecrown_citadel();
    AddSC_boss_anubrekhan();                                // naxxramas
    AddSC_boss_four_horsemen();
    AddSC_boss_faerlina();
    AddSC_boss_gluth();
    AddSC_boss_gothik();
    AddSC_boss_grobbulus();
    AddSC_boss_kelthuzad();
    AddSC_boss_loatheb();
    AddSC_boss_maexxna();
    AddSC_boss_noth();
    AddSC_boss_heigan();
    AddSC_boss_patchwerk();
    AddSC_boss_razuvious();
    AddSC_boss_sapphiron();
    AddSC_boss_thaddius();
    AddSC_instance_naxxramas();
    AddSC_boss_malygos();                                   // nexus, eye_of_eternity
    AddSC_boss_anomalus();                                  // nexus, nexus
    AddSC_boss_keristrasza();
    AddSC_boss_ormorok();
    AddSC_boss_telestra();
    AddSC_instance_nexus();
    AddSC_boss_eregos();                                    // nexus, oculus
    AddSC_boss_urom();
    AddSC_instance_oculus();
    AddSC_boss_sartharion();                                // obsidian_sanctum
    AddSC_instance_obsidian_sanctum();
    AddSC_boss_baltharus();                                 // ruby_sanctum
    AddSC_boss_halion();
    AddSC_boss_saviana();
    AddSC_boss_zarithrian();
    AddSC_instance_ruby_sanctum();
    AddSC_boss_bjarngrim();                                 // ulduar, halls_of_lightning
    AddSC_boss_ionar();
    AddSC_boss_loken();
    AddSC_boss_volkhan();
    AddSC_instance_halls_of_lightning();
    AddSC_boss_maiden_of_grief();                           // ulduar, halls_of_stone
    AddSC_boss_sjonnir();
    AddSC_halls_of_stone();
    AddSC_instance_halls_of_stone();
    AddSC_boss_assembly_of_iron();                          // ulduar, ulduar
    AddSC_boss_algalon();
    AddSC_boss_auriaya();
    AddSC_boss_flame_leviathan();
    AddSC_boss_freya();
    AddSC_boss_general_vezax();
    AddSC_boss_hodir();
    AddSC_boss_ignis();
    AddSC_boss_kologarn();
    AddSC_boss_mimiron();
    AddSC_boss_razorscale();
    AddSC_boss_thorim();
    AddSC_boss_xt_002();
    AddSC_boss_yogg_saron();
    AddSC_instance_ulduar();
    AddSC_ulduar();
    AddSC_boss_ingvar();                                    // UK, utgarde_keep
    AddSC_boss_keleseth();
    AddSC_boss_skarvald_and_dalronn();
    AddSC_instance_utgarde_keep();
    AddSC_utgarde_keep();
    AddSC_boss_gortok();                                    // UK, utgarde_pinnacle
    AddSC_boss_skadi();
    AddSC_boss_svala();
    AddSC_boss_ymiron();
    AddSC_instance_pinnacle();
    AddSC_boss_archavon();                                  // vault_of_archavon
    AddSC_boss_emalon();
    AddSC_boss_koralon();
    AddSC_boss_toravon();
    AddSC_instance_vault_of_archavon();
    AddSC_boss_erekem();                                    // violet_hold
    AddSC_boss_ichoron();
    AddSC_instance_violet_hold();
    AddSC_violet_hold();

    AddSC_borean_tundra();
    AddSC_dalaran();
    AddSC_dragonblight();
    AddSC_grizzly_hills();
    AddSC_howling_fjord();
    AddSC_icecrown();
    AddSC_sholazar_basin();
    AddSC_storm_peaks();
    AddSC_zuldrak();

    // outland
    AddSC_boss_exarch_maladaar();                           // auchindoun, auchenai_crypts
    AddSC_boss_shirrak();
    AddSC_boss_nexusprince_shaffar();                       // auchindoun, mana_tombs
    AddSC_boss_pandemonius();
    AddSC_boss_anzu();                                      // auchindoun, sethekk_halls
    AddSC_boss_darkweaver_syth();
    AddSC_boss_talon_king_ikiss();
    AddSC_instance_sethekk_halls();
    AddSC_boss_ambassador_hellmaw();                        // auchindoun, shadow_labyrinth
    AddSC_boss_blackheart_the_inciter();
    AddSC_boss_grandmaster_vorpil();
    AddSC_boss_murmur();
    AddSC_instance_shadow_labyrinth();
    AddSC_black_temple();                                   // black_temple
    AddSC_boss_illidan();
    AddSC_boss_shade_of_akama();
    AddSC_boss_supremus();
    AddSC_boss_gurtogg_bloodboil();
    AddSC_boss_mother_shahraz();
    AddSC_boss_reliquary_of_souls();
    AddSC_boss_teron_gorefiend();
    AddSC_boss_najentus();
    AddSC_boss_illidari_council();
    AddSC_instance_black_temple();
    AddSC_boss_fathomlord_karathress();                     // CR, serpent_shrine
    AddSC_boss_hydross_the_unstable();
    AddSC_boss_lady_vashj();
    AddSC_boss_leotheras_the_blind();
    AddSC_boss_morogrim_tidewalker();
    AddSC_boss_the_lurker_below();
    AddSC_instance_serpentshrine_cavern();
    AddSC_boss_ahune();                                     // CR, slave_pens
    AddSC_boss_hydromancer_thespia();                       // CR, steam_vault
    AddSC_boss_mekgineer_steamrigger();
    AddSC_boss_warlord_kalithresh();
    AddSC_instance_steam_vault();
    AddSC_boss_hungarfen();                                 // CR, Underbog
    AddSC_boss_gruul();                                     // gruuls_lair
    AddSC_boss_high_king_maulgar();
    AddSC_instance_gruuls_lair();
    AddSC_boss_broggok();                                   // HC, blood_furnace
    AddSC_boss_kelidan_the_breaker();
    AddSC_boss_the_maker();
    AddSC_instance_blood_furnace();
    AddSC_boss_nazan_and_vazruden();                        // HC, hellfire_ramparts
    AddSC_boss_omor_the_unscarred();
    AddSC_boss_watchkeeper_gargolmar();
    AddSC_instance_ramparts();
    AddSC_boss_magtheridon();                               // HC, magtheridons_lair
    AddSC_instance_magtheridons_lair();
    AddSC_boss_grand_warlock_nethekurse();                  // HC, shattered_halls
    AddSC_boss_warbringer_omrogg();
    AddSC_boss_warchief_kargath_bladefist();
    AddSC_instance_shattered_halls();
    AddSC_arcatraz();                                       // TK, arcatraz
    AddSC_boss_harbinger_skyriss();
    AddSC_instance_arcatraz();
    AddSC_boss_high_botanist_freywinn();                    // TK, botanica
    AddSC_boss_laj();
    AddSC_boss_warp_splinter();
    AddSC_boss_alar();                                      // TK, the_eye
    AddSC_boss_high_astromancer_solarian();
    AddSC_boss_kaelthas();
    AddSC_boss_void_reaver();
    AddSC_instance_the_eye();
    AddSC_the_eye();
    AddSC_boss_gatewatcher_iron_hand();                     // TK, the_mechanar
    AddSC_boss_nethermancer_sepethrea();
    AddSC_boss_pathaleon_the_calculator();
    AddSC_instance_mechanar();

    AddSC_blades_edge_mountains();
    AddSC_boss_doomlordkazzak();
    AddSC_boss_doomwalker();
    AddSC_hellfire_peninsula();
    AddSC_nagrand();
    AddSC_netherstorm();
    AddSC_shadowmoon_valley();
    AddSC_shattrath_city();
    AddSC_terokkar_forest();
    AddSC_zangarmarsh();

    // Cataclysm
    //Raids 6
    AddSC_instance_baradin_hold();                    //Baradin Hold
    AddSC_boss_argaloth();
    AddSC_boss_occuthar();
    AddSC_boss_alizabal();
    AddSC_instance_blackwing_descent();                //Blackwing Decent
    AddSC_boss_magmaw();
    AddSC_boss_omnotron();
    AddSC_boss_maloriak();
    AddSC_boss_atramedes();
    AddSC_boss_chimaeron();
    AddSC_boss_nefarian_onyxia();
    AddSC_instance_dragon_soul();                    //Dragon Soul
    AddSC_boss_morchok();
    AddSC_boss_warlord_zonozz();
    AddSC_boss_yorsahi_the_unsleeping();
    AddSC_boss_hagara_the_stormbinder();
    AddSC_boss_ultraxion();
    AddSC_boss_warmaster_blackhorn();
    AddSC_boss_spine_of_deathwing();
    AddSC_boss_madness_of_deathwing();
    AddSC_instance_firelands();                        //Firelands
    AddSC_boss_shannox();
    AddSC_boss_lord_rhyolith();
    AddSC_boss_bethtilac();
    AddSC_boss_alysrazor();
    AddSC_boss_baleroc();
    AddSC_boss_major_domo();
    AddSC_boss_ragnaros_final();
    AddSC_instance_the_bastion_of_twilight();         //The Bastion Of Twilight
    AddSC_boss_halfus_wyrmbreaker();
    AddSC_boss_theralion_and_valiona();
    AddSC_boss_ascendant_council();
    AddSC_boss_chogall();
    AddSC_boss_sinestra();
    AddSC_instance_throne_of_the_four_winds();        // Throne of the Four Winds
    AddSC_boss_conclave_of_wind();
    AddSC_boss_alakir();
    //Instances 14
    AddSC_instance_throne_of_the_tides();            //Abyssal Maw: Throne of the Tides
    AddSC_boss_lady_nazjar();
    AddSC_boss_commander_ulthok();
    AddSC_boss_erunak_ghursha();
    AddSC_boss_ozumat();
    AddSC_instance_blackrock_caverns();                //Blackrock Caverns
    AddSC_boss_romogg_bonecrusher();
    AddSC_boss_corla_herald_of_twilight();
    AddSC_boss_karsh_steelbender();
    AddSC_boss_beauty();
    AddSC_boss_ascendant_lord_obsidius();
    AddSC_instance_deadmines();                     //Deadmines
    AddSC_boss_glubtok();
    AddSC_boss_helix_gearbreaker();
    AddSC_boss_foe_reaper_5000();
    AddSC_boss_admiral_ripsnarl();
    AddSC_boss_cookie();
    AddSC_boss_vanessa_vancleef();
    AddSC_instance_end_time();                        //End Time
    AddSC_boss_echo_of_baine();
    AddSC_boss_echo_of_jaina();
    AddSC_boss_echo_of_sylvanas();
    AddSC_boss_echo_of_tyrande();
    AddSC_boss_murozond();
    AddSC_instance_grim_batol();                    //Grimbatol
    AddSC_boss_general_umbriss();
    AddSC_boss_forgemaster_throngus();
    AddSC_boss_drahga_shadowburner();
    AddSC_boss_erudax();
    AddSC_instance_halls_of_origination();            //Halls of Origination
    AddSC_boss_temple_guardian_anhuur();
    AddSC_boss_earthrager_ptah();
    AddSC_boss_anraphet();
    AddSC_boss_isiset();
    AddSC_boss_ammunae();
    AddSC_boss_setesh();
    AddSC_boss_rajh();
    AddSC_instance_hour_of_twilight();                //Hour of Twilight
    AddSC_boss_arcurion();
    AddSC_boss_asira_dawnslayer();
    AddSC_boss_archbishop_benedictus();
    AddSC_instance_shadowfang_keep();               //Shadowfang Keep
    AddSC_boss_baron_ashbury();
    AddSC_boss_baron_silverlaine();
    AddSC_boss_commander_springvale();
    AddSC_boss_lord_walden();
    AddSC_boss_lord_godfrey();
    AddSC_instance_lost_city_of_the_tolvir();        //The Lost City of the Tol'vir
    AddSC_boss_husam();
    AddSC_boss_high_prophet_barim();
    AddSC_boss_lockmaw();
    AddSC_boss_siamat();
    AddSC_instance_the_stonecore();                    //The Stonecore
    AddSC_boss_corborus();
    AddSC_boss_slabhide();
    AddSC_boss_ozruk();
    AddSC_boss_priestess_azil();
    AddSC_instance_vortex_pinnacle();                //Vortex Pinnacle
    AddSC_boss_grand_vizier_ertan();
    AddSC_boss_altairus();
    AddSC_boss_asaad();
    AddSC_instance_well_of_eternity();                //Well of Eternity
    AddSC_boss_perotharn();
    AddSC_boss_queen_azshara();
    AddSC_boss_mannaroth_varothen();
    AddSC_instance_zul_aman();                        //Zulaman
    AddSC_boss_akilzon();
    AddSC_boss_nalorakk();
    AddSC_boss_janalai();
    AddSC_boss_halazzi();
    AddSC_boss_malacrass();
    AddSC_boss_zuljin();
    AddSC_instance_zul_gurub();                      //Zulgurub
    AddSC_boss_venoxis();
    AddSC_boss_mandokir();
    AddSC_boss_edge_of_madness();
    AddSC_boss_kilnara();
    AddSC_boss_zanzil();
    AddSC_boss_jindo();
    //Zones 13
    AddSC_ahnqiraj_fallen_kingdom();
    AddSC_darkmoon();
    AddSC_deepholm();
    AddSC_gilneas();
    AddSC_lost_isles();
    AddSC_molten_front();
    AddSC_mount_hyjal();
    AddSC_the_maelstrom();
    AddSC_tol_barad();
    AddSC_twilight_highlands();
    AddSC_uldum();
    AddSC_vashjir();
    AddSC_instance_kezan();

    /*
    // Mists Of Pandaria
    //Raids 3
    AddSC_instance_mogushan_vaults();                // Mogu'shan Vaults
    AddSC_boss_the_stone_guard();
    AddSC_boss_feng_the_accursed();
    AddSC_boss_garajal_the_spiritbinder();
    AddSC_boss_the_spirit_emporers();
    AddSC_boss_will_of_the_emporor();
    AddSC_instance_terrace_of_endless_spring();        //Terrace of Endless Spring
    AddSC_boss_protectors_of_the_endless();
    AddSC_boss_sha_of_fear();
    AddSC_boss_sha_of_anger();
    AddSC_instance_mantid_raid();                    // Mantid Raid (un named)
    //Instances 12
    AddSC_instance_temple_of_the_jade_serpent();    // Temple of the Jade Serpent
    AddSC_boss_wise_mari();
    AddSC_boss_zao_sunseeker();
    AddSC_boss_lui_flameheart();
    AddSC_boss_sha_of_doubt();
    AddSC_instance_stormstout_brewery();            // Stormstout Brewery
    AddSC_boss_ook_ook();
    AddSC_boss_hoptallus();
    AddSC_boss_yan_zhu_the_uncasked();
    AddSC_instance_shado_pan_monastery();            // Shado Pan Monastery
    AddSC_instance_gate_of_the_setting_sun();        // Gate Of the Setting Sun
    AddSC_boss_striker_gadok();
    AddSC_boss_commander_rimok();
    AddSC_boss_saboteur_kiptilak();
    AddSC_boss_raigonn();
    AddSC_instance_mogushan_palace();                // Mogu'shan Palace
    AddSC_boss_clan_leaders_of_the_mogu();
    AddSC_boss_gekkan();
    AddSC_boss_xin_the_weaponmaster();
    AddSC_instance_the_perfect_storm();                // The Perfect Storm
    AddSC_instance_ancient_mogu_crypt();            // Ancient Mogo Crypt
    AddSC_instance_the_jade_forest();                // The Jade Forest
    AddSC_instance_siege_of_niuzao_temple();        // Siege of Niuzao Temple
    AddSC_boss_bloodmage_thalnos();                 // scarlet_monastery_cathedral
    AddSC_boss_durand_and_whitemane();
    AddSC_boss_houndmaster_braun();                 // scarlet_monastery_scarlet_halls
    AddSC_boss_armsmaster_harlan();
    AddSC_boss_flameweaver_koegler();
    AddSC_boss_headless_horseman();
    AddSC_instance_scarlet_monastery();
    AddSC_instance_scholomance();                    // scholomance
    AddSC_boss_instructor_chillheart();
    AddSC_boss_jandice_barov();
    AddSC_boss_rattlegore();
    AddSC_boss_lilian_voss();
    AddSC_boss_darkmaster_gandling ();
    //Zones 10
    AddSC_dread_wastes();
    AddSC_krasarang_wilds();
    AddSC_kun_lai_summit();
    AddSC_the_jade_forest();
    AddSC_townlong_steppes();
    AddSC_vale_of_eternal_blossoms();
    AddSC_valley_of_the_four_winds();
    AddSC_wandering_isle();
    AddSC_instance_the_battle_for_theramore();        // The Battle for Theramore
    AddSC_instance_heart_of_fear();                    // Heart  Of Fear
    AddSC_boss_garalon();
*/
}
