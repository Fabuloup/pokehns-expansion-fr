# Suivi de la traduction française

Relevé du 23/09/2026, commit `ec0d367842`.

## État en un coup d'œil

| Zone | Fichiers | Chaînes anglaises |
|---|---|---|
| Scripts de cartes `_hns` | 423 traduits, 126 sans texte | 4 |
| Fichiers transversaux (`data/text`, `src/data/text`) | 45 traduits | 2 |
| **Cartes héritées atteignables** | 279 | **10 887** |
| **Code source `src/`** | 70 | **1 959** |
| **`data/scripts/`** | 36 | **1 269** |
| `data/event_scripts.s` | 1 | 65 |
| **Reste à traduire** | | **~14 200** |
| | | |
| Cartes sans chemin d'accès | 305 | 6 429 |
| Fixture de test (hors ROM) | 1 | 39 |

Aucun texte n'a été validé en jeu. Le jeu compile, ce qui ne prouve rien sur
l'exhaustivité ni sur l'affichage.

> Les scripts de cartes sont terminés, mais ils ne représentent qu'une partie
> du jeu. L'essentiel de ce qui reste est dans le code source, et c'est le plus
> visible en jeu.

## Ce qu'il reste à faire, par priorité

L'ordre est celui de la visibilité en jeu, pas du volume.

| Rang | Fichier | Chaînes | Ce que le joueur voit |
|---|---|---|---|
| 1 | `src/battle_message.c` | 524 | tous les messages de combat |
| 2 | `src/strings.c` | 402 | menus et interface |
| 3 | `src/data/union_room.h` | 155 | jeu en réseau |
| 4 | `src/berry.c` | 114 | Baies |
| 5 | `src/challenge_menu.c` | 105 | menu de défis |
| 6 | `src/data/abilities.h` | 73 | descriptions des talents |
| 7 | `src/battle_dome.c` | 59 | Dôme de Combat |
| 8 | `src/data/contest_moves.h` | 55 | concours |
| 9 | `src/data/items.h` | 28 | descriptions d'objets |

Les descriptions de talents et l'écran de résumé sont signalés par une autre
traduction française du jeu comme sources de **plantages** quand le texte est
trop long. À traiter avec prudence et à tester en priorité.

Dans `data/scripts/`, seuls quatre fichiers étaient appelés depuis les cartes
`_hns` et ils sont déjà traduits. Le reste demande un tri avant traduction :
voir la section suivante.


## Inventaire des fichiers restants

Relevé automatique. Chaque ligne donne le nombre de chaînes détectées
comme anglaises. Régénérable par le détecteur décrit plus haut.

### Code source `src/` — 70 fichiers, 1959 chaînes

Le plus visible en jeu. À traiter en premier.

| Fichier | Chaînes |
|---|---|
| `src/battle_message.c` | 524 |
| `src/strings.c` | 402 |
| `src/data/union_room.h` | 155 |
| `src/berry.c` | 114 |
| `src/challenge_menu.c` | 105 |
| `src/data/abilities.h` | 73 |
| `src/battle_dome.c` | 59 |
| `src/data/contest_moves.h` | 55 |
| `src/data/contest_text_tables.h` | 42 |
| `src/pokemon_storage_system.c` | 34 |
| `src/data/items.h` | 28 |
| `src/pokedex_plus_hgss.c` | 19 |
| `src/data/easy_chat/easy_chat_group_endings.h` | 19 |
| `src/contest.c` | 19 |
| `src/data/easy_chat/easy_chat_group_people.h` | 18 |
| `src/item_use.c` | 17 |
| `src/data/easy_chat/easy_chat_group_misc.h` | 14 |
| `src/data/easy_chat/easy_chat_group_feelings.h` | 14 |
| `src/pokenav_match_call_data.c` | 13 |
| `src/pokemon_sprite_visualizer.c` | 13 |
| `src/data/easy_chat/easy_chat_group_greetings.h` | 13 |
| `src/data/easy_chat/easy_chat_group_actions.h` | 13 |
| `src/data/script_menu.h` | 11 |
| `src/data/help_window.h` | 11 |
| `src/pokenav_menu_handler_gfx.c` | 10 |
| `src/debug.c` | 10 |
| `src/data/easy_chat/easy_chat_group_speech.h` | 10 |
| `src/berry_blender.c` | 10 |
| `src/battle_controller_oak_old_man.c` | 10 |
| `src/item_menu.c` | 9 |
| `src/roulette.c` | 7 |
| `src/party_menu.c` | 7 |
| `src/data/easy_chat/easy_chat_group_battle.h` | 7 |
| `src/credits_frlg.c` | 7 |
| `src/main_menu.c` | 6 |
| `src/frontier_util.c` | 6 |
| `src/data/trade.h` | 6 |
| `src/slot_machine.c` | 5 |
| `src/berry_fix_program.c` | 5 |
| `src/field_screen_effect.c` | 4 |
| `src/data/credits_hns.h` | 4 |
| `src/pokeblock_feed.c` | 3 |
| `src/fishing.c` | 3 |
| `src/data/party_menu.h` | 3 |
| `src/data/moves_info.h` | 3 |
| `src/data/easy_chat/easy_chat_group_conditions.h` | 3 |
| `src/data/credits.h` | 3 |
| `src/berry_tag_screen.c` | 3 |
| `src/battle_main.c` | 3 |
| `src/use_pokeblock.c` | 2 |
| `src/tv.c` | 2 |
| `src/pokeblock.c` | 2 |
| `src/naming_screen.c` | 2 |
| `src/data/easy_chat/easy_chat_group_time.h` | 2 |
| `src/battle_debug.c` | 2 |
| `src/voltorb_flip.c` | 1 |
| `src/script_menu.c` | 1 |
| `src/pokenav_match_call_list.c` | 1 |
| `src/pokenav_match_call_gfx.c` | 1 |
| `src/oak_speech_hns.c` | 1 |
| `src/mystery_gift_scripts.c` | 1 |
| `src/mail.c` | 1 |
| `src/landmark.c` | 1 |
| `src/dexnav.c` | 1 |
| `src/data/pokemon/species_info/gen_5_families.h` | 1 |
| `src/data/easy_chat/easy_chat_group_voices.h` | 1 |
| `src/data/easy_chat/easy_chat_group_trendy_saying.h` | 1 |
| `src/data/easy_chat/easy_chat_group_trainer.h` | 1 |
| `src/data/battle_environment.h` | 1 |
| `src/battle_controller_player.c` | 1 |

### `data/scripts/` — 36 fichiers, 1269 chaînes

Vérifier l'atteignabilité avant de traduire : plusieurs de ces fichiers sont du contenu hérité sans appel.

| Fichier | Chaînes |
|---|---|
| `data/scripts/mauville_man.inc` | 245 |
| `data/scripts/cable_club_frlg.inc` | 200 |
| `data/scripts/berry_blender.inc` | 125 |
| `data/scripts/safari_zone.inc` | 105 |
| `data/scripts/lilycove_lady.inc` | 99 |
| `data/scripts/debug.inc` | 76 |
| `data/scripts/day_care.inc` | 63 |
| `data/scripts/berry_tree.inc` | 48 |
| `data/scripts/profile_man.inc` | 41 |
| `data/scripts/flavor_text.inc` | 36 |
| `data/scripts/mystery_event_club.inc` | 32 |
| `data/scripts/secret_power_tm.inc` | 25 |
| `data/scripts/field_move_scripts.inc` | 20 |
| `data/scripts/gift_trainer.inc` | 17 |
| `data/scripts/route23.inc` | 16 |
| `data/scripts/gift_battle_card.inc` | 13 |
| `data/scripts/gift_old_sea_map.inc` | 12 |
| `data/scripts/mom_savings.inc` | 11 |
| `data/scripts/gift_mystic_ticket.inc` | 11 |
| `data/scripts/gift_aurora_ticket.inc` | 11 |
| `data/scripts/aide.inc` | 8 |
| `data/scripts/apricorn_tree.inc` | 7 |
| `data/scripts/gift_pichu.inc` | 6 |
| `data/scripts/gift_altering_cave.inc` | 6 |
| `data/scripts/pkmn_center_nurse_frlg.inc` | 5 |
| `data/scripts/dexnav.inc` | 5 |
| `data/scripts/shared_secret_base.inc` | 4 |
| `data/scripts/players_house.inc` | 4 |
| `data/scripts/silphco_doors.inc` | 3 |
| `data/scripts/gift_stamp_card.inc` | 3 |
| `data/scripts/test_signpost.inc` | 2 |
| `data/scripts/repel.inc` | 2 |
| `data/scripts/move_tutors_frlg.inc` | 2 |
| `data/scripts/follower.inc` | 2 |
| `data/scripts/config.inc` | 2 |
| `data/scripts/battle_frontier.inc` | 2 |

### Cartes accessibles au joueur — 279 fichiers, 10887 chaînes

Atteignables par le graphe des warps depuis la carte de départ. Majorant : certaines peuvent être derrière un drapeau jamais activé.

| Fichier | Chaînes |
|---|---|
| `data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc` | 617 |
| `data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc` | 319 |
| `data/maps/BattleFrontier_BattleTowerLobby/scripts.inc` | 234 |
| `data/maps/PetalburgCity_Gym/scripts.inc` | 227 |
| `data/maps/SlateportCity/scripts.inc` | 208 |
| `data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc` | 194 |
| `data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc` | 183 |
| `data/maps/LilycoveCity/scripts.inc` | 165 |
| `data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc` | 159 |
| `data/maps/BattleFrontier_Lounge2/scripts.inc` | 149 |
| `data/maps/MtChimney/scripts.inc` | 135 |
| `data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.inc` | 133 |
| `data/maps/RustboroCity/scripts.inc` | 131 |
| `data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc` | 130 |
| `data/maps/BattleFrontier_ReceptionGate/scripts.inc` | 129 |
| `data/maps/MossdeepCity_Gym/scripts.inc` | 125 |
| `data/maps/MtPyre_Summit/scripts.inc` | 124 |
| `data/maps/BattleFrontier_Lounge3/scripts.inc` | 124 |
| `data/maps/BattleFrontier_BattleArenaLobby/scripts.inc` | 124 |
| `data/maps/BattleFrontier_BattleDomeLobby/scripts.inc` | 121 |
| `data/maps/BattleFrontier_OutsideWest/scripts.inc` | 111 |
| `data/maps/BattleFrontier_OutsideEast/scripts.inc` | 102 |
| `data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc` | 102 |
| `data/maps/Route110/scripts.inc` | 99 |
| `data/maps/MauvilleCity/scripts.inc` | 98 |
| `data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc` | 94 |
| `data/maps/LilycoveCity_ContestHall/scripts.inc` | 92 |
| `data/maps/RustboroCity_Gym/scripts.inc` | 90 |
| `data/maps/FortreeCity_Gym/scripts.inc` | 89 |
| `data/maps/TrainerHill_Entrance/scripts.inc` | 88 |
| `data/maps/LavaridgeTown_Gym_1F/scripts.inc` | 88 |
| `data/maps/BattleFrontier_BattlePikeLobby/scripts.inc` | 87 |
| `data/maps/SlateportCity_Harbor/scripts.inc` | 85 |
| `data/maps/MauvilleCity_BikeShop/scripts.inc` | 85 |
| `data/maps/BattleFrontier_ScottsHouse/scripts.inc` | 84 |
| `data/maps/SlateportCity_PokemonFanClub/scripts.inc` | 81 |
| `data/maps/BattleFrontier_Lounge7/scripts.inc` | 81 |
| `data/maps/SlateportCity_OceanicMuseum_2F/scripts.inc` | 80 |
| `data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc` | 80 |
| `data/maps/RustboroCity_PokemonSchool/scripts.inc` | 77 |
| `data/maps/MauvilleCity_GameCorner/scripts.inc` | 76 |
| `data/maps/MossdeepCity_SpaceCenter_1F/scripts.inc` | 75 |
| `data/maps/DewfordTown_Gym/scripts.inc` | 74 |
| `data/maps/Route104/scripts.inc` | 73 |
| `data/maps/DewfordTown/scripts.inc` | 73 |
| `data/maps/DewfordTown_Hall/scripts.inc` | 72 |
| `data/maps/PetalburgWoods/scripts.inc` | 70 |
| `data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc` | 69 |
| `data/maps/Route119/scripts.inc` | 68 |
| `data/maps/LavaridgeTown/scripts.inc` | 66 |
| `data/maps/MossdeepCity_SpaceCenter_2F/scripts.inc` | 65 |
| `data/maps/LittlerootTown_BrendansHouse_1F/scripts.inc` | 65 |
| `data/maps/MauvilleCity_Gym/scripts.inc` | 64 |
| `data/maps/RustboroCity_DevonCorp_3F/scripts.inc` | 63 |
| `data/maps/MossdeepCity/scripts.inc` | 63 |
| `data/maps/EverGrandeCity_ChampionsRoom/scripts.inc` | 63 |
| `data/maps/SlateportCity_BattleTentCorridor/scripts.inc` | 61 |
| `data/maps/Route110_TrickHouseEntrance/scripts.inc` | 61 |
| `data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.inc` | 61 |
| `data/maps/BattleFrontier_BattlePyramidTop/scripts.inc` | 61 |
| `data/maps/Route116/scripts.inc` | 59 |
| `data/maps/Route111/scripts.inc` | 59 |
| `data/maps/Route119_WeatherInstitute_2F/scripts.inc` | 58 |
| `data/maps/RusturfTunnel/scripts.inc` | 56 |
| `data/maps/RustboroCity_DevonCorp_2F/scripts.inc` | 56 |
| `data/maps/Route110_TrickHouseEnd/scripts.inc` | 56 |
| `data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.inc` | 56 |
| `data/maps/BattleFrontier_ExchangeServiceCorner/scripts.inc` | 55 |
| `data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.inc` | 55 |
| `data/maps/LilycoveCity_ContestLobby/scripts.inc` | 54 |
| `data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.inc` | 53 |
| `data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc` | 53 |
| `data/maps/RustboroCity_Flat1_2F/scripts.inc` | 48 |
| `data/maps/LittlerootTown_MaysHouse_2F/scripts.inc` | 48 |
| `data/maps/BattleFrontier_Lounge1/scripts.inc` | 48 |
| `data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc` | 48 |
| `data/maps/VerdanturfTown_WandasHouse/scripts.inc` | 47 |
| `data/maps/LittlerootTown_MaysHouse_1F/scripts.inc` | 47 |
| `data/maps/LilycoveCity_House3/scripts.inc` | 47 |
| `data/maps/MeteorFalls_1F_2R/scripts.inc` | 46 |
| `data/maps/VictoryRoad_1F/scripts.inc` | 45 |
| `data/maps/SlateportCity_SternsShipyard_1F/scripts.inc` | 45 |
| `data/maps/MagmaHideout_4F/scripts.inc` | 45 |
| `data/maps/Route110_TrickHousePuzzle5/scripts.inc` | 44 |
| `data/maps/SSTidalRooms/scripts.inc` | 43 |
| `data/maps/Route113_GlassWorkshop/scripts.inc` | 42 |
| `data/maps/JaggedPass/scripts.inc` | 42 |
| `data/maps/AbandonedShip_Rooms2_1F/scripts.inc` | 42 |
| `data/maps/PetalburgCity_WallysHouse/scripts.inc` | 40 |
| `data/maps/SSTidalCorridor/scripts.inc` | 38 |
| `data/maps/Route109/scripts.inc` | 38 |
| `data/maps/MtPyre_2F/scripts.inc` | 37 |
| `data/maps/Route109_SeashoreHouse/scripts.inc` | 36 |
| `data/maps/MeteorFalls_1F_1R/scripts.inc` | 35 |
| `data/maps/RustboroCity_DevonCorp_1F/scripts.inc` | 34 |
| `data/maps/Route128/scripts.inc` | 33 |
| `data/maps/Route114_LanettesHouse/scripts.inc` | 33 |
| `data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.inc` | 33 |
| `data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.inc` | 33 |
| `data/maps/Route103/scripts.inc` | 32 |
| `data/maps/MtPyre_3F/scripts.inc` | 32 |
| `data/maps/MossdeepCity_StevensHouse/scripts.inc` | 32 |
| `data/maps/FortreeCity/scripts.inc` | 32 |
| `data/maps/AquaHideout_B2F/scripts.inc` | 32 |
| `data/maps/AquaHideout_1F/scripts.inc` | 32 |
| `data/maps/BattleFrontier_Lounge5/scripts.inc` | 31 |
| `data/maps/VerdanturfTown_BattleTentLobby/scripts.inc` | 30 |
| `data/maps/Route104_MrBrineysHouse/scripts.inc` | 30 |
| `data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.inc` | 30 |
| `data/maps/VictoryRoad_B2F/scripts.inc` | 29 |
| `data/maps/Route119_WeatherInstitute_1F/scripts.inc` | 29 |
| `data/maps/Route110_TrickHousePuzzle7/scripts.inc` | 29 |
| `data/maps/VerdanturfTown/scripts.inc` | 28 |
| `data/maps/FallarborTown_BattleTentLobby/scripts.inc` | 27 |
| `data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc` | 27 |
| `data/maps/VictoryRoad_B1F/scripts.inc` | 26 |
| `data/maps/Route120/scripts.inc` | 26 |
| `data/maps/PetalburgCity/scripts.inc` | 26 |
| `data/maps/PacifidlogTown_House2/scripts.inc` | 25 |
| `data/maps/LilycoveCity_Harbor/scripts.inc` | 24 |
| `data/maps/Route111_WinstrateFamilysHouse/scripts.inc` | 23 |
| `data/maps/MagmaHideout_2F_2R/scripts.inc` | 23 |
| `data/maps/FallarborTown_CozmosHouse/scripts.inc` | 23 |
| `data/maps/SlateportCity_NameRatersHouse/scripts.inc` | 22 |
| `data/maps/Route114_FossilManiacsTunnel/scripts.inc` | 22 |
| `data/maps/SlateportCity_BattleTentLobby/scripts.inc` | 21 |
| `data/maps/Route118/scripts.inc` | 21 |
| `data/maps/Route116_TunnelersRestHouse/scripts.inc` | 21 |
| `data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.inc` | 20 |
| `data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc` | 20 |
| `data/maps/Route110_TrickHousePuzzle3/scripts.inc` | 20 |
| `data/maps/EverGrandeCity_DrakesRoom/scripts.inc` | 20 |
| `data/maps/RustboroCity_CuttersHouse/scripts.inc` | 19 |
| `data/maps/MtPyre_6F/scripts.inc` | 19 |
| `data/maps/MossdeepCity_GameCorner_1F/scripts.inc` | 19 |
| `data/maps/MeteorFalls_StevensCave/scripts.inc` | 19 |
| `data/maps/FallarborTown_PokemonCenter_1F/scripts.inc` | 19 |
| `data/maps/AbandonedShip_Rooms_1F/scripts.inc` | 19 |
| `data/maps/SkyPillar_Outside/scripts.inc` | 18 |
| `data/maps/PetalburgCity_PokemonCenter_1F/scripts.inc` | 18 |
| `data/maps/PacifidlogTown_House3/scripts.inc` | 18 |
| `data/maps/OldaleTown/scripts.inc` | 18 |
| `data/maps/FortreeCity_House1/scripts.inc` | 18 |
| `data/maps/FallarborTown_MoveRelearnersHouse/scripts.inc` | 18 |
| `data/maps/Route110_TrickHousePuzzle4/scripts.inc` | 17 |
| `data/maps/Route110_TrickHousePuzzle1/scripts.inc` | 17 |
| `data/maps/Route101/scripts.inc` | 17 |
| `data/maps/MagmaHideout_1F/scripts.inc` | 17 |
| `data/maps/GraniteCave_StevensRoom/scripts.inc` | 17 |
| `data/maps/FortreeCity_PokemonCenter_1F/scripts.inc` | 17 |
| `data/maps/FortreeCity_House2/scripts.inc` | 17 |
| `data/maps/EverGrandeCity_GlaciasRoom/scripts.inc` | 17 |
| `data/maps/AquaHideout_B1F/scripts.inc` | 17 |
| `data/maps/Route110_TrickHousePuzzle8/scripts.inc` | 16 |
| `data/maps/Route110_TrickHousePuzzle6/scripts.inc` | 16 |
| `data/maps/EverGrandeCity_PokemonCenter_1F/scripts.inc` | 16 |
| `data/maps/EverGrandeCity_PhoebesRoom/scripts.inc` | 16 |
| `data/maps/DewfordTown_House2/scripts.inc` | 16 |
| `data/maps/RustboroCity_House1/scripts.inc` | 15 |
| `data/maps/Route110_TrickHousePuzzle2/scripts.inc` | 15 |
| `data/maps/LittlerootTown_BrendansHouse_2F/scripts.inc` | 15 |
| `data/maps/FallarborTown/scripts.inc` | 15 |
| `data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc` | 15 |
| `data/maps/MauvilleCity_House1/scripts.inc` | 14 |
| `data/maps/MagmaHideout_2F_1R/scripts.inc` | 14 |
| `data/maps/LilycoveCity_MoveDeletersHouse/scripts.inc` | 14 |
| `data/maps/BattleFrontier_Lounge8/scripts.inc` | 14 |
| `data/maps/Route112/scripts.inc` | 13 |
| `data/maps/MossdeepCity_House3/scripts.inc` | 13 |
| `data/maps/LilycoveCity_DepartmentStore_1F/scripts.inc` | 13 |
| `data/maps/EverGrandeCity_SidneysRoom/scripts.inc` | 13 |
| `data/maps/BattleFrontier_RankingHall/scripts.inc` | 13 |
| `data/maps/Route114_FossilManiacsHouse/scripts.inc` | 12 |
| `data/maps/PacifidlogTown/scripts.inc` | 12 |
| `data/maps/MagmaHideout_3F_1R/scripts.inc` | 12 |
| `data/maps/GraniteCave_1F/scripts.inc` | 12 |
| `data/maps/FortreeCity_House4/scripts.inc` | 12 |
| `data/maps/BattleFrontier_Lounge6/scripts.inc` | 12 |
| `data/maps/AbandonedShip_Corridors_B1F/scripts.inc` | 12 |
| `data/maps/SSTidalLowerDeck/scripts.inc` | 11 |
| `data/maps/PetalburgCity_Mart/scripts.inc` | 11 |
| `data/maps/OldaleTown_PokemonCenter_1F/scripts.inc` | 11 |
| `data/maps/MossdeepCity_Mart/scripts.inc` | 11 |
| `data/maps/LavaridgeTown_PokemonCenter_1F/scripts.inc` | 11 |
| `data/maps/FallarborTown_BattleTentCorridor/scripts.inc` | 11 |
| `data/maps/VerdanturfTown_PokemonCenter_1F/scripts.inc` | 10 |
| `data/maps/Route113/scripts.inc` | 10 |
| `data/maps/Route111_OldLadysRestStop/scripts.inc` | 10 |
| `data/maps/MirageTower_4F/scripts.inc` | 10 |
| `data/maps/MauvilleCity_House2/scripts.inc` | 10 |
| `data/maps/MagmaHideout_3F_2R/scripts.inc` | 10 |
| `data/maps/FortreeCity_House3/scripts.inc` | 10 |
| `data/maps/EverGrandeCity_PokemonLeague_1F/scripts.inc` | 10 |
| `data/maps/BattleFrontier_PokemonCenter_1F/scripts.inc` | 10 |
| `data/maps/BattleFrontier_Mart/scripts.inc` | 10 |
| `data/maps/VerdanturfTown_BattleTentCorridor/scripts.inc` | 9 |
| `data/maps/Route117/scripts.inc` | 9 |
| `data/maps/Route105/scripts.inc` | 9 |
| `data/maps/Route102/scripts.inc` | 9 |
| `data/maps/PetalburgCity_House1/scripts.inc` | 9 |
| `data/maps/PacifidlogTown_PokemonCenter_1F/scripts.inc` | 9 |
| `data/maps/PacifidlogTown_House4/scripts.inc` | 9 |
| `data/maps/MtPyre_1F/scripts.inc` | 9 |
| `data/maps/LilycoveCity_PokemonCenter_1F/scripts.inc` | 9 |
| `data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.inc` | 9 |
| `data/maps/LavaridgeTown_HerbShop/scripts.inc` | 9 |
| `data/maps/EverGrandeCity_HallOfFame/scripts.inc` | 9 |
| `data/maps/AbandonedShip_CaptainsOffice/scripts.inc` | 9 |
| `data/maps/VerdanturfTown_Mart/scripts.inc` | 8 |
| `data/maps/SlateportCity_House/scripts.inc` | 8 |
| `data/maps/RustboroCity_PokemonCenter_1F/scripts.inc` | 8 |
| `data/maps/RustboroCity_Mart/scripts.inc` | 8 |
| `data/maps/PacifidlogTown_House1/scripts.inc` | 8 |
| `data/maps/MauvilleCity_PokemonCenter_1F/scripts.inc` | 8 |
| `data/maps/MauvilleCity_Mart/scripts.inc` | 8 |
| `data/maps/LilycoveCity_DepartmentStore_5F/scripts.inc` | 8 |
| `data/maps/FortreeCity_DecorationShop/scripts.inc` | 8 |
| `data/maps/DewfordTown_House1/scripts.inc` | 8 |
| `data/maps/BattleFrontier_Lounge4/scripts.inc` | 8 |
| `data/maps/Route123/scripts.inc` | 7 |
| `data/maps/OldaleTown_Mart/scripts.inc` | 7 |
| `data/maps/FallarborTown_Mart/scripts.inc` | 7 |
| `data/maps/VerdanturfTown_House/scripts.inc` | 6 |
| `data/maps/SlateportCity_PokemonCenter_1F/scripts.inc` | 6 |
| `data/maps/ShoalCave_LowTideLowerRoom/scripts.inc` | 6 |
| `data/maps/RustboroCity_Flat2_2F/scripts.inc` | 6 |
| `data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.inc` | 6 |
| `data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.inc` | 6 |
| `data/maps/PacifidlogTown_House5/scripts.inc` | 6 |
| `data/maps/OldaleTown_House1/scripts.inc` | 6 |
| `data/maps/NewMauville_Inside/scripts.inc` | 6 |
| `data/maps/MtPyre_5F/scripts.inc` | 6 |
| `data/maps/MossdeepCity_House1/scripts.inc` | 6 |
| `data/maps/LilycoveCity_House4/scripts.inc` | 6 |
| `data/maps/LilycoveCity_DepartmentStore_4F/scripts.inc` | 6 |
| `data/maps/LilycoveCity_DepartmentStore_3F/scripts.inc` | 6 |
| `data/maps/FortreeCity_Mart/scripts.inc` | 6 |
| `data/maps/FortreeCity_House5/scripts.inc` | 6 |
| `data/maps/DewfordTown_PokemonCenter_1F/scripts.inc` | 6 |
| `data/maps/Underwater_SeafloorCavern/scripts.inc` | 5 |
| `data/maps/SlateportCity_Mart/scripts.inc` | 5 |
| `data/maps/RustboroCity_House3/scripts.inc` | 5 |
| `data/maps/Route121/scripts.inc` | 5 |
| `data/maps/Route114/scripts.inc` | 5 |
| `data/maps/OldaleTown_House2/scripts.inc` | 5 |
| `data/maps/MossdeepCity_PokemonCenter_1F/scripts.inc` | 5 |
| `data/maps/MossdeepCity_House4/scripts.inc` | 5 |
| `data/maps/MauvilleCity_PokemonCenter_2F/scripts.inc` | 5 |
| `data/maps/AbandonedShip_Corridors_1F/scripts.inc` | 5 |
| `data/maps/SlateportCity_SternsShipyard_2F/scripts.inc` | 4 |
| `data/maps/RustboroCity_House2/scripts.inc` | 4 |
| `data/maps/Route119_House/scripts.inc` | 4 |
| `data/maps/Route112_CableCarStation/scripts.inc` | 4 |
| `data/maps/PetalburgCity_House2/scripts.inc` | 4 |
| `data/maps/NewMauville_Entrance/scripts.inc` | 4 |
| `data/maps/MtPyre_4F/scripts.inc` | 4 |
| `data/maps/MtChimney_CableCarStation/scripts.inc` | 4 |
| `data/maps/MossdeepCity_House2/scripts.inc` | 4 |
| `data/maps/LilycoveCity_House2/scripts.inc` | 4 |
| `data/maps/LilycoveCity_House1/scripts.inc` | 4 |
| `data/maps/LilycoveCity_DepartmentStore_2F/scripts.inc` | 4 |
| `data/maps/LavaridgeTown_Mart/scripts.inc` | 4 |
| `data/maps/LavaridgeTown_House/scripts.inc` | 4 |
| `data/maps/RustboroCity_Flat1_1F/scripts.inc` | 3 |
| `data/maps/Route115/scripts.inc` | 3 |
| `data/maps/AbandonedShip_Rooms_B1F/scripts.inc` | 3 |
| `data/maps/AbandonedShip_Rooms2_B1F/scripts.inc` | 3 |
| `data/maps/RustboroCity_Flat2_3F/scripts.inc` | 2 |
| `data/maps/Route106/scripts.inc` | 2 |
| `data/maps/MossdeepCity_PokemonCenter_2F/scripts.inc` | 2 |
| `data/maps/EverGrandeCity/scripts.inc` | 2 |
| `data/maps/EcruteakCity_SageOffice1_hns/scripts.inc` | 2 |
| `data/maps/DesertUnderpass/scripts.inc` | 2 |
| `data/maps/CeladonCity_Apartments_2F_hns/scripts.inc` | 2 |
| `data/maps/BattleFrontier_BattlePikeCorridor/scripts.inc` | 2 |
| `data/maps/BattleFrontier_BattleArenaCorridor/scripts.inc` | 2 |
| `data/maps/SkyPillar_Top/scripts.inc` | 1 |
| `data/maps/RustboroCity_Flat2_1F/scripts.inc` | 1 |
| `data/maps/FarawayIsland_Interior/scripts.inc` | 1 |

### Autres — 3 fichiers, 67 chaînes

| Fichier | Chaînes |
|---|---|
| `data/event_scripts.s` | 65 |
| `data/text/tv.inc` | 1 |
| `data/text/pokedex_rating.inc` | 1 |

### Cartes sans chemin d'accès — 305 fichiers, 6429 chaînes

Aucun warp n'y mène. **Ne pas traduire** sans avoir vérifié.
Liste complète non reproduite ici : la régénérer au besoin.


## Contenu hérité : ce qui est atteignable et ce qui ne l'est pas

Le projet est bâti sur une décompilation : il hérite de tout Émeraude et d'une
partie de Rouge Feu / Vert Feuille, qu'ils servent ou non. Du contenu inutilisé
est donc normal et attendu.

Mais **la majorité de ce contenu est accessible**. Depuis
`BATTLE_FRONTIER_OUTSIDE_WEST_HNS`, un warp mène à `ARTISAN_CAVE_B1F`, qui
rouvre la Zone de Combat de Hoenn puis Hoenn entier. Un parcours du graphe des
warps depuis la carte de départ atteint **921 cartes sur 1 499**.

| | Fichiers | Chaînes |
|---|---|---|
| Cartes héritées avec un chemin d'accès | 279 | 10 887 |
| Cartes héritées sans aucun chemin | 305 | 6 429 |

Les 6 429 sont un plancher fiable : aucun warp n'y mène. Les 10 887 sont un
**majorant** : le parcours suit tous les warps sans vérifier les drapeaux qui
les conditionnent, donc certaines de ces cartes peuvent rester inaccessibles en
pratique. Seul un test en jeu tranchera.

Pour recalculer l'atteignabilité, le script de parcours est décrit dans
« Comment mesurer ». Ne jamais se fier au seul test des warps cités depuis les
cartes `_hns` : il rate toutes les chaînes de warps de plus d'un saut.

Dans `data/scripts/`, sans référence trouvée et probablement morts :
`mauville_man.inc` (245), `cable_club_frlg.inc` (200), `berry_blender.inc` (125),
`safari_zone.inc` (105), `lilycove_lady.inc` (99), `profile_man.inc` (41),
`mystery_event_club.inc` (32).

`debug.inc` (76) ne sert qu'au débogage. `day_care.inc` (63) et `berry_tree.inc`
(48) demandent une vérification manuelle : ces fonctions existent en jeu, donc
une variante `_hns` les remplace probablement.

Ne jamais traduire un identifiant. `FLAG_HIDE_PETALBURG_GYM_WALLY`,
`VAR_PETALBURG_GYM_STATE` et `MAPSEC_PETALBURG_WOODS` sont du code : un terme
anglais dans les sources n'est pas forcément une lacune de traduction.

## Comment mesurer

Le compte ci-dessus vient d'un détecteur qui extrait les chaînes réellement
affichées (`.string "..."`, `_("...")`, `COMPOUND_STRING("...")`), neutralise
les codes entre accolades, puis cherche des mots outils anglais sans ambiguïté
en français. Il ne compte ni les identifiants, ni les commentaires.

## États de suivi

- `à traduire` : rien n'a été fait ;
- `traduit, à valider en jeu` : sources françaises en place, contrôles
  automatiques passés, jamais vu en jeu ;
- `validé en jeu` : vérifié visuellement pendant une partie ;
- `sans chaîne locale à traduire` : aucune chaîne affichable dans ce fichier,
  exclu du décompte ;
- `bloqué` : accompagné d'une explication.

Tant qu'aucun test sur émulateur n'a eu lieu, `validé en jeu` est interdit.

## Détail : scripts de cartes

549 fichiers suivis, dont 423 traduits et 126 sans chaîne locale.

| Fichier | État |
|---|---|
| `data/maps/AkalaIsle_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Akala_Cave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Akala_Forest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Akala_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/AlolaWater_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/AzaleaTown_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/AzaleaTown_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/AzaleaTown_KurtsHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/AzaleaTown_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/AzaleaTown_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/AzaleaTown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleColosseum_2P_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_BattleArenaBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleArenaCorridor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleArenaLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleDomeBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleDomeCorridor_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_BattleDomeLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleDomePreBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleFactoryBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleFactoryLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleFactoryPreBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePalaceBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePalaceCorridor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePalaceLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePikeCorridor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePikeLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePikeRoomFinal_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePikeRoomNormal_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePikeRoomWildMons_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_BattlePikeThreePathRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePyramidFloor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePyramidLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePyramidTop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleTowerBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleTowerCorridor_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_BattleTowerElevator_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_BattleTowerLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleTowerMultiBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleTowerMultiCorridor_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_BattleTowerMultiPartnerRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_ExchangeServiceCorner_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge7_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge8_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge9_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_OutsideEast_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_OutsideWest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_PokemonCenter_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_PokemonCenter_2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattleFrontier_RankingHall_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_ReceptionGate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_ScottsHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattlePyramidSquare01_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare02_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare03_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare04_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare05_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare06_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare07_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare08_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare09_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare10_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare11_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare12_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare13_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare14_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare15_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BattlePyramidSquare16_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BellchimeTrail_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BirthIsland_Exterior_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/BirthIsland_Harbor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BurnedTower_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BurnedTower_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_RoofDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_RoofHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_RoofNight_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/CeladonCity_DepartmentStore_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_4F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_5F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_RoofDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_RoofNight_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/CeladonCity_GameCorner_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_House2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/CeladonCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCave_1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/CeruleanCave_B1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/CeruleanCave_B2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/CeruleanCity_BikeShop_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/CeruleanCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodGym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodHouse1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodHouse2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodHouse3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodPokecenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodShop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CinnabarIsland_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CinnabarIsland_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CliffEdgeCave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CliffEdgeGate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ContestHall_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/DarkCave_NorthSide_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/DarkCave_SouthSide_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/DiglettsCave_EntranceNorth_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/DiglettsCave_EntranceSouth_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/DiglettsCave_Tunnel_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/DragonsDen_Cavern_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/DragonsDen_Entrance_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/DragonsDen_Shrine_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_SageOffice1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_SageOffice2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/EcruteakCity_Theater_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EmbeddedTower_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/FallarborTown_BattleTentBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FallarborTown_BattleTentCorridor_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/FallarborTown_BattleTentLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FarawayIsland_Entrance_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FarawayIsland_Interior_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Route15_Gate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Route19_Gate_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/FuchsiaCity_SafariZoneBeach_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_SafariZoneBrush_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/FuchsiaCity_SafariZoneCave_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/FuchsiaCity_SafariZoneEntrance_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_SafariZoneMountain_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/FuchsiaCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_AzaleaTown_IlexForest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_CeladonCity_Route16_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_EcruteakCity_Route38_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_EcruteakCity_Route42_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_FuchsiaCity_Route18_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Gate_GoldenrodCity_Route35_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_IlexForest_Route34_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_MahoganyTown_Route43_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_NationalPark_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_Route29_Route46_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_Route2_ViridianForest_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Gate_Route2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Gate_Route31_VioletCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_Route40_TrainerHill_Courtyard_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Gate_Route43_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_RuinsOfAlph_Route32_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_RuinsOfAlph_Route36_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route7_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route8_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_ViridianForest_Route2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/GoldenrodCity_BikeShop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_BillsHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStoreBasement_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStoreElevator_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_4F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_5F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_6F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_7FNight_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/GoldenrodCity_DepartmentStore_7F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_FlowerShop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_GameCorner_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_RadioTower_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_RadioTower_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_RadioTower_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_RadioTower_4F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_RadioTower_5F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_TrainStation_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_UndergroundEntrance_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_UndergroundStorage_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_UndergroundSwitches_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_UndergroundTunnel_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IcePath_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IcePath_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IcePath_B2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/IcePath_B3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IcePath_B4F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/IlexForest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IndigoPlateau_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IndigoPlateau_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRageLowTide_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRage_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRage_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRage_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_House3_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/LavenderTown_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_RadioStation_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_SoulHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LilycoveCity_ContestHall_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LilycoveCity_ContestLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MahoganyTown_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MahoganyTown_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MahoganyTown_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MahoganyTown_Shop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Mahoganytown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MelemeleIsle_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_PlayerHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMoon_Cave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMoon_Outside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMoon_Shop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMortar_1F_North_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMortar_1F_South_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/MtMortar_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMortar_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_1F_ItemRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/MtSilver_1F_MoltresRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_1F_WaterfallRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/MtSilver_3F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/MtSilver_MountainSide_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/MtSilver_Outside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_Snow_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/MtSilver_SummitDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_SummitNight_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/NationalPark_BugContest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NationalPark_Normal_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_Lab_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_PlayersHouse_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_HotSprings_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_House4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_KimonoHideout_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_Cafe_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_Lighthouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_PortInside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_PortOutside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_House3_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/PalletTown_Lab_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_RedsHouse_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_RedsHouse_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Museum_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Museum_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_BrunosRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_ChampionsRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_HallOfFame_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_KarensRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_KogasRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_WillsRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PoniIsle_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Poni_Cave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ReceptionGate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RockTunnel_1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/RockTunnel_B1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/RocketHideout_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RocketHideout_B2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RocketHideout_B3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route10_PowerPlantBackRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route10_PowerPlantEntrance_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route10_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route11_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route12_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route12_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route13_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route14_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route15_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route16_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route16_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route17_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route18_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route19_Cave_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route19_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route20_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route21_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route22_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route23_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route24_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route25_BillsHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route25_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route26North_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route26_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route26_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route26_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route27_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route27_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route28_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route28_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route29_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route2_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route30_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route30_MrPokemonsHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route30_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route31_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route32_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route32_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route33_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route34_DayCare_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route34_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route35_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route36_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route37_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route38_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route39_Barn_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route39_FarmHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route39_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route40_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route41_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route42_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route43_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route44_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route45_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route46_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route47_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route48_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route49_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route4_PokemonCenter_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route50_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route5_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route5_TunnelEntrance_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route6_TunnelEntrance_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route7_TunnelEntrance_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route7_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route8_TunnelEntrance_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/Route8_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route9_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route9_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_Lab_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_Outside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_PuzzleAndRewardChambers_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_WordsRoom1_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/RuinsOfAlph_WordsRoom2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/RuinsOfAlph_WordsRoom3_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/RuinsOfAlph_WordsRoom4_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SSAqua_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_CaptainsRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_PlayersRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomNE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomNNE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomNW_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSSE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSSW_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSW_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SafariZone1_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone3_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZoneGate_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SafariZoneGate_SafariZoneEntrance_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SafariZoneGate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SafariZoneIndoor_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone_Enterance_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone_Low_Left_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone_Low_Mid_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone_Low_Right_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone_Top_Left_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone_Top_Mid_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SafariZone_Top_Right_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SaffronCity_CopyCatsHouse_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_CopyCatsHouse_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_FightingDojoVIP_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_FightingDojo_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_SilphCo_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_TrainStation_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Tunnel_NS_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Tunnel_SW_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SaffronCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Saffron_Temp_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SeafoamIslands_1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SeafoamIslands_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SeafoamIslands_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SeafoamIslands_SecretCave_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SinjohRuins_ArceusRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SinjohRuins_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SinjohRuins_RegiceRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SinjohRuins_RegidracoRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SinjohRuins_RegielekiRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SinjohRuins_RegigigasRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SinjohRuins_RegirockRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SinjohRuins_RegisteelRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SinjohRuins_Temple_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SinjohRuins_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlateportCity_BattleTentBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlateportCity_BattleTentCorridor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlateportCity_BattleTentLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlowpokeWell_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlowpokeWell_B2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SnowsweptCavern_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SouthernIsland_Exterior_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SouthernIsland_Interior_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/SproutTower_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SproutTower_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SproutTower_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TestMap1_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TestMap2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TinTower_2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_3F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_4F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_5F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_6F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_7F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_8F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_9F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TinTower_RoofDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TinTower_RoofNight_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TohjoFalls_Cavern_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TohjoFalls_GiovanniRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TradeCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TrainerHill_1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TrainerHill_2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TrainerHill_3F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TrainerHill_4F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/TrainerHill_Courtyard_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TrainerHill_Elevator_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TrainerHill_Entrance_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TrainerHill_Roof_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Trees_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/UlaUla_Cave_2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaUla_Cave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaUla_Forest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaUla_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaulaIsle_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UnionCave_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UnionCave_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UnionCave_B2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UnionRoom_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/VerdanturfTown_BattleTentBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VerdanturfTown_BattleTentCorridor_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/VerdanturfTown_BattleTentLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_FanClub_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_PortInside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_PortOutside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VictoryRoadKanto_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VictoryRoadKanto_B1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/VictoryRoadKanto_B2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/VioletCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_TrainerSchool_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_House2_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/ViridianCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianForest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/WhirlIslands_1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/WhirlIslands_B1F_Inner_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/WhirlIslands_B1F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/WhirlIslands_B2F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/WhirlIslands_B3F_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/WhirlIslands_Descent_hns/scripts.inc` | sans chaîne locale à traduire |
| `data/maps/WhirlIslands_LugiaChamber_hns/scripts.inc` | traduit, à valider en jeu |

## Détail : fichiers transversaux

45 fichiers, tous traduits et à valider en jeu.

| Fichier | État |
|---|---|
| `data/text/abnormal_weather.inc` | traduit, à valider en jeu |
| `data/text/apprentice.inc` | traduit, à valider en jeu |
| `data/text/battle_tent.inc` | traduit, à valider en jeu |
| `data/text/berries.inc` | traduit, à valider en jeu |
| `data/text/birch_speech.inc` | traduit, à valider en jeu |
| `data/text/blend_master.inc` | traduit, à valider en jeu |
| `data/text/braille.inc` | traduit, à valider en jeu |
| `data/text/cable_club.inc` | traduit, à valider en jeu |
| `data/text/check_furniture.inc` | traduit, à valider en jeu |
| `data/text/day_care_frlg.inc` | traduit, à valider en jeu |
| `data/text/event_ticket_1.inc` | traduit, à valider en jeu |
| `data/text/event_ticket_2.inc` | traduit, à valider en jeu |
| `data/text/fame_checker_frlg.inc` | traduit, à valider en jeu |
| `data/text/ingame_trade_frlg.inc` | traduit, à valider en jeu |
| `data/text/lottery_corner.inc` | traduit, à valider en jeu |
| `data/text/mart_clerk.inc` | traduit, à valider en jeu |
| `data/text/match_call.inc` | traduit, à valider en jeu |
| `data/text/match_call_hns.inc` | traduit, à valider en jeu |
| `data/text/mauville_man.inc` | traduit, à valider en jeu |
| `data/text/move_relearner.inc` | traduit, à valider en jeu |
| `data/text/move_tutors.inc` | traduit, à valider en jeu |
| `data/text/new_game_intro_frlg.inc` | traduit, à valider en jeu |
| `data/text/oak_speech_hns.inc` | traduit, à valider en jeu |
| `data/text/obtain_item.inc` | traduit, à valider en jeu |
| `data/text/pc.inc` | traduit, à valider en jeu |
| `data/text/pc_transfer.inc` | traduit, à valider en jeu |
| `data/text/pkmn_center_nurse.inc` | traduit, à valider en jeu |
| `data/text/pokedex_rating.inc` | traduit, à valider en jeu |
| `data/text/pokemon_news.inc` | traduit, à valider en jeu |
| `data/text/questionnaire.inc` | traduit, à valider en jeu |
| `data/text/record_mix.inc` | traduit, à valider en jeu |
| `data/text/save.inc` | traduit, à valider en jeu |
| `data/text/secret_base_trainers.inc` | traduit, à valider en jeu |
| `data/text/shoal_cave.inc` | traduit, à valider en jeu |
| `data/text/surf.inc` | traduit, à valider en jeu |
| `data/text/trainer_card_frlg.inc` | traduit, à valider en jeu |
| `data/text/trainers.inc` | traduit, à valider en jeu |
| `data/text/trainers_frlg.inc` | traduit, à valider en jeu |
| `data/text/tv.inc` | traduit, à valider en jeu |
| `src/data/text/follower_messages.h` | traduit, à valider en jeu |
| `src/data/text/gift_ribbon_descriptions.h` | traduit, à valider en jeu |
| `src/data/text/match_call_messages.h` | traduit, à valider en jeu |
| `src/data/text/radio_strings.h` | traduit, à valider en jeu |
| `src/data/text/ribbon_descriptions.h` | traduit, à valider en jeu |
| `data/text/*.inc` (reliquat) | 1 |
