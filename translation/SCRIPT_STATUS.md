# Suivi global des scripts H&S

Ce tableau inventorie tous les fichiers `data/maps/*_hns/scripts.inc` du projet.
Le deuxième badge est un jalon de test, pas une limite de traduction.

Règles de suivi :

- un fichier est traduit intégralement dans un commit dédié ;
- les codes, variables et contrôles de dialogue doivent rester intacts ;
- `traduit, à valider en jeu` signifie que les contrôles automatiques et la compilation ont réussi ;
- `validé en jeu` est réservé à une vérification visuelle dans l'émulateur ;
- les scripts hors cartes et les fichiers hérités de `pokeemerald-expansion` sont suivis dans l'audit transversal lorsqu'ils sont réellement utilisés par H&S.

Progression actuelle : **307 / 413 fichiers à traduire**, dont **0 validé en jeu**.

Le tableau suit 549 fichiers, mais **136 d'entre eux ne contiennent aucune chaîne
affichée** : ce sont des scripts purement logiques (couloirs, ascenseurs, warps).
Ils portent l'état `sans texte affiché` et sont exclus du décompte. La cible
réelle est donc de 413 fichiers, dont 106 restent à traduire.

| Fichier | État |
|---|---|
| `data/maps/AkalaIsle_hns/scripts.inc` | à traduire |
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
| `data/maps/BattleColosseum_2P_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_BattleArenaBattleRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleArenaCorridor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleArenaLobby_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleDomeBattleRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleDomeCorridor_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_BattleDomeLobby_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleDomePreBattleRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleFactoryBattleRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleFactoryLobby_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleFactoryPreBattleRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePalaceBattleRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePalaceCorridor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePalaceLobby_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePikeCorridor_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePikeLobby_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePikeRoomFinal_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattlePikeRoomNormal_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePikeRoomWildMons_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_BattlePikeThreePathRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePyramidFloor_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePyramidLobby_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattlePyramidTop_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleTowerBattleRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleTowerCorridor_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_BattleTowerElevator_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_BattleTowerLobby_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_BattleTowerMultiBattleRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_BattleTowerMultiCorridor_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_BattleTowerMultiPartnerRoom_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_ExchangeServiceCorner_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge1_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_Lounge2_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_Lounge3_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_Lounge4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge7_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_Lounge8_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_Lounge9_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_OutsideEast_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_OutsideWest_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_PokemonCenter_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_PokemonCenter_2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattleFrontier_RankingHall_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BattleFrontier_ReceptionGate_hns/scripts.inc` | à traduire |
| `data/maps/BattleFrontier_ScottsHouse_hns/scripts.inc` | à traduire |
| `data/maps/BattlePyramidSquare01_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare02_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare03_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare04_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare05_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare06_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare07_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare08_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare09_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare10_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare11_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare12_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare13_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare14_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare15_hns/scripts.inc` | sans texte affiché |
| `data/maps/BattlePyramidSquare16_hns/scripts.inc` | sans texte affiché |
| `data/maps/BellchimeTrail_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BirthIsland_Exterior_hns/scripts.inc` | sans texte affiché |
| `data/maps/BirthIsland_Harbor_hns/scripts.inc` | sans texte affiché |
| `data/maps/BlackthornCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/BlackthornCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_House3_hns/scripts.inc` | à traduire |
| `data/maps/BlackthornCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BlackthornCity_hns/scripts.inc` | à traduire |
| `data/maps/BurnedTower_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/BurnedTower_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_RoofDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_RoofHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Apartments_RoofNight_hns/scripts.inc` | sans texte affiché |
| `data/maps/CeladonCity_DepartmentStore_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_4F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_5F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_RoofDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_DepartmentStore_RoofNight_hns/scripts.inc` | sans texte affiché |
| `data/maps/CeladonCity_GameCorner_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/CeladonCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_House2_hns/scripts.inc` | sans texte affiché |
| `data/maps/CeladonCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeladonCity_hns/scripts.inc` | à traduire |
| `data/maps/CeruleanCave_1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/CeruleanCave_B1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/CeruleanCave_B2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/CeruleanCity_BikeShop_hns/scripts.inc` | sans texte affiché |
| `data/maps/CeruleanCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/CeruleanCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CeruleanCity_hns/scripts.inc` | à traduire |
| `data/maps/CherrygroveCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CherrygroveCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodCity_hns/scripts.inc` | à traduire |
| `data/maps/CianwoodGym_hns/scripts.inc` | à traduire |
| `data/maps/CianwoodHouse1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodHouse2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodHouse3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodPokecenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CianwoodShop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CinnabarIsland_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CinnabarIsland_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CliffEdgeCave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/CliffEdgeGate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ContestHall_hns/scripts.inc` | sans texte affiché |
| `data/maps/DarkCave_NorthSide_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/DarkCave_SouthSide_hns/scripts.inc` | sans texte affiché |
| `data/maps/DiglettsCave_EntranceNorth_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/DiglettsCave_EntranceSouth_hns/scripts.inc` | sans texte affiché |
| `data/maps/DiglettsCave_Tunnel_hns/scripts.inc` | sans texte affiché |
| `data/maps/DragonsDen_Cavern_hns/scripts.inc` | à traduire |
| `data/maps/DragonsDen_Entrance_hns/scripts.inc` | sans texte affiché |
| `data/maps/DragonsDen_Shrine_hns/scripts.inc` | à traduire |
| `data/maps/EcruteakCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/EcruteakCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/EcruteakCity_SageOffice1_hns/scripts.inc` | à traduire |
| `data/maps/EcruteakCity_SageOffice2_hns/scripts.inc` | sans texte affiché |
| `data/maps/EcruteakCity_Theater_hns/scripts.inc` | à traduire |
| `data/maps/EcruteakCity_hns/scripts.inc` | à traduire |
| `data/maps/EmbeddedTower_hns/scripts.inc` | sans texte affiché |
| `data/maps/FallarborTown_BattleTentBattleRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/FallarborTown_BattleTentCorridor_hns/scripts.inc` | sans texte affiché |
| `data/maps/FallarborTown_BattleTentLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FarawayIsland_Entrance_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FarawayIsland_Interior_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/FuchsiaCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Route15_Gate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_Route19_Gate_hns/scripts.inc` | sans texte affiché |
| `data/maps/FuchsiaCity_SafariZoneBeach_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/FuchsiaCity_SafariZoneBrush_hns/scripts.inc` | sans texte affiché |
| `data/maps/FuchsiaCity_SafariZoneCave_hns/scripts.inc` | sans texte affiché |
| `data/maps/FuchsiaCity_SafariZoneEntrance_hns/scripts.inc` | à traduire |
| `data/maps/FuchsiaCity_SafariZoneMountain_hns/scripts.inc` | sans texte affiché |
| `data/maps/FuchsiaCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_AzaleaTown_IlexForest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_CeladonCity_Route16_hns/scripts.inc` | sans texte affiché |
| `data/maps/Gate_EcruteakCity_Route38_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_EcruteakCity_Route42_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_FuchsiaCity_Route18_hns/scripts.inc` | sans texte affiché |
| `data/maps/Gate_GoldenrodCity_Route35_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_IlexForest_Route34_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_MahoganyTown_Route43_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_NationalPark_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_Route29_Route46_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_Route2_ViridianForest_hns/scripts.inc` | sans texte affiché |
| `data/maps/Gate_Route2_hns/scripts.inc` | sans texte affiché |
| `data/maps/Gate_Route31_VioletCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_Route40_TrainerHill_Courtyard_hns/scripts.inc` | sans texte affiché |
| `data/maps/Gate_Route43_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_RuinsOfAlph_Route32_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_RuinsOfAlph_Route36_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route7_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_SaffronCity_Route8_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Gate_ViridianForest_Route2_hns/scripts.inc` | sans texte affiché |
| `data/maps/GoldenrodCity_BikeShop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_BillsHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStoreBasement_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStoreElevator_hns/scripts.inc` | sans texte affiché |
| `data/maps/GoldenrodCity_DepartmentStore_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_4F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_5F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_6F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/GoldenrodCity_DepartmentStore_7FNight_hns/scripts.inc` | sans texte affiché |
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
| `data/maps/IcePath_B2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/IcePath_B3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IcePath_B4F_hns/scripts.inc` | sans texte affiché |
| `data/maps/IlexForest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IndigoPlateau_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/IndigoPlateau_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRageLowTide_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRage_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRage_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LakeOfRage_hns/scripts.inc` | à traduire |
| `data/maps/LavenderTown_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_House3_hns/scripts.inc` | sans texte affiché |
| `data/maps/LavenderTown_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_RadioStation_hns/scripts.inc` | à traduire |
| `data/maps/LavenderTown_SoulHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LavenderTown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/LilycoveCity_ContestHall_hns/scripts.inc` | à traduire |
| `data/maps/LilycoveCity_ContestLobby_hns/scripts.inc` | à traduire |
| `data/maps/MahoganyTown_Gym_hns/scripts.inc` | à traduire |
| `data/maps/MahoganyTown_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MahoganyTown_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MahoganyTown_Shop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Mahoganytown_hns/scripts.inc` | à traduire |
| `data/maps/MelemeleIsle_hns/scripts.inc` | à traduire |
| `data/maps/Melemele_House_2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Melemele_PlayerHouse_hns/scripts.inc` | à traduire |
| `data/maps/MtMoon_Cave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMoon_Outside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMoon_Shop_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMortar_1F_North_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMortar_1F_South_hns/scripts.inc` | sans texte affiché |
| `data/maps/MtMortar_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtMortar_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_1F_ItemRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/MtSilver_1F_MoltresRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/MtSilver_1F_WaterfallRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/MtSilver_3F_hns/scripts.inc` | sans texte affiché |
| `data/maps/MtSilver_MountainSide_hns/scripts.inc` | sans texte affiché |
| `data/maps/MtSilver_Outside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_Snow_hns/scripts.inc` | sans texte affiché |
| `data/maps/MtSilver_SummitDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/MtSilver_SummitNight_hns/scripts.inc` | sans texte affiché |
| `data/maps/NationalPark_BugContest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NationalPark_Normal_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_Lab_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_PlayersHouse_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewBarkTown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_HotSprings_hns/scripts.inc` | à traduire |
| `data/maps/NewSinjoh_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_House3_hns/scripts.inc` | à traduire |
| `data/maps/NewSinjoh_House4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_KimonoHideout_hns/scripts.inc` | à traduire |
| `data/maps/NewSinjoh_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/NewSinjoh_hns/scripts.inc` | à traduire |
| `data/maps/OlivineCity_Cafe_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/OlivineCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_Lighthouse_hns/scripts.inc` | à traduire |
| `data/maps/OlivineCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_PortInside_hns/scripts.inc` | à traduire |
| `data/maps/OlivineCity_PortOutside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/OlivineCity_hns/scripts.inc` | à traduire |
| `data/maps/PalletTown_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_House3_hns/scripts.inc` | sans texte affiché |
| `data/maps/PalletTown_Lab_hns/scripts.inc` | à traduire |
| `data/maps/PalletTown_RedsHouse_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_RedsHouse_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PalletTown_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/PewterCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Museum_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_Museum_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PewterCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_BrunosRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_ChampionsRoom_hns/scripts.inc` | à traduire |
| `data/maps/PokemonLeague_HallOfFame_hns/scripts.inc` | à traduire |
| `data/maps/PokemonLeague_KarensRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_KogasRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PokemonLeague_WillsRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/PoniIsle_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Poni_Cave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ReceptionGate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RockTunnel_1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/RockTunnel_B1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/RocketHideout_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RocketHideout_B2F_hns/scripts.inc` | à traduire |
| `data/maps/RocketHideout_B3F_hns/scripts.inc` | à traduire |
| `data/maps/Route10_PowerPlantBackRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route10_PowerPlantEntrance_hns/scripts.inc` | à traduire |
| `data/maps/Route10_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route11_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route12_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route12_hns/scripts.inc` | à traduire |
| `data/maps/Route13_hns/scripts.inc` | à traduire |
| `data/maps/Route14_hns/scripts.inc` | à traduire |
| `data/maps/Route15_hns/scripts.inc` | à traduire |
| `data/maps/Route16_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route16_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route17_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route18_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route19_Cave_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route19_hns/scripts.inc` | à traduire |
| `data/maps/Route1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route20_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route21_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route22_hns/scripts.inc` | à traduire |
| `data/maps/Route23_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route24_hns/scripts.inc` | à traduire |
| `data/maps/Route25_BillsHouse_hns/scripts.inc` | à traduire |
| `data/maps/Route25_hns/scripts.inc` | à traduire |
| `data/maps/Route26North_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route26_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route26_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route26_hns/scripts.inc` | à traduire |
| `data/maps/Route27_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route27_hns/scripts.inc` | à traduire |
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
| `data/maps/Route38_hns/scripts.inc` | à traduire |
| `data/maps/Route39_Barn_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route39_FarmHouse_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route39_hns/scripts.inc` | à traduire |
| `data/maps/Route3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route40_hns/scripts.inc` | à traduire |
| `data/maps/Route41_hns/scripts.inc` | à traduire |
| `data/maps/Route42_hns/scripts.inc` | à traduire |
| `data/maps/Route43_hns/scripts.inc` | à traduire |
| `data/maps/Route44_hns/scripts.inc` | à traduire |
| `data/maps/Route45_hns/scripts.inc` | à traduire |
| `data/maps/Route46_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route47_hns/scripts.inc` | à traduire |
| `data/maps/Route48_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route49_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route4_PokemonCenter_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route4_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route50_hns/scripts.inc` | à traduire |
| `data/maps/Route5_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route5_TunnelEntrance_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route5_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route6_TunnelEntrance_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route6_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route7_TunnelEntrance_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route7_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route8_TunnelEntrance_hns/scripts.inc` | sans texte affiché |
| `data/maps/Route8_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route9_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Route9_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_Lab_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_Outside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_PuzzleAndRewardChambers_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/RuinsOfAlph_WordsRoom1_hns/scripts.inc` | sans texte affiché |
| `data/maps/RuinsOfAlph_WordsRoom2_hns/scripts.inc` | sans texte affiché |
| `data/maps/RuinsOfAlph_WordsRoom3_hns/scripts.inc` | sans texte affiché |
| `data/maps/RuinsOfAlph_WordsRoom4_hns/scripts.inc` | sans texte affiché |
| `data/maps/SSAqua_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_B1F_hns/scripts.inc` | à traduire |
| `data/maps/SSAqua_CaptainsRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_PlayersRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomNE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomNNE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomNW_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSSE_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSSW_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SSAqua_RoomSW_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SafariZone1_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone2_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone3_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZoneGate_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SafariZoneGate_SafariZoneEntrance_hns/scripts.inc` | à traduire |
| `data/maps/SafariZoneGate_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SafariZoneIndoor_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone_Enterance_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone_Low_Left_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone_Low_Mid_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone_Low_Right_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone_Top_Left_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone_Top_Mid_hns/scripts.inc` | sans texte affiché |
| `data/maps/SafariZone_Top_Right_hns/scripts.inc` | sans texte affiché |
| `data/maps/SaffronCity_CopyCatsHouse_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_CopyCatsHouse_2F_hns/scripts.inc` | à traduire |
| `data/maps/SaffronCity_FightingDojoVIP_hns/scripts.inc` | à traduire |
| `data/maps/SaffronCity_FightingDojo_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/SaffronCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_SilphCo_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_TrainStation_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Tunnel_NS_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SaffronCity_Tunnel_SW_hns/scripts.inc` | sans texte affiché |
| `data/maps/SaffronCity_hns/scripts.inc` | à traduire |
| `data/maps/Saffron_Temp_hns/scripts.inc` | sans texte affiché |
| `data/maps/SeafoamIslands_1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/SeafoamIslands_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SeafoamIslands_Gym_hns/scripts.inc` | à traduire |
| `data/maps/SeafoamIslands_SecretCave_hns/scripts.inc` | sans texte affiché |
| `data/maps/SinjohRuins_ArceusRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SinjohRuins_House1_hns/scripts.inc` | à traduire |
| `data/maps/SinjohRuins_RegiceRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/SinjohRuins_RegidracoRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/SinjohRuins_RegielekiRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/SinjohRuins_RegigigasRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/SinjohRuins_RegirockRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/SinjohRuins_RegisteelRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/SinjohRuins_Temple_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SinjohRuins_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlateportCity_BattleTentBattleRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/SlateportCity_BattleTentCorridor_hns/scripts.inc` | sans texte affiché |
| `data/maps/SlateportCity_BattleTentLobby_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlowpokeWell_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SlowpokeWell_B2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SnowsweptCavern_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SouthernIsland_Exterior_hns/scripts.inc` | sans texte affiché |
| `data/maps/SouthernIsland_Interior_hns/scripts.inc` | sans texte affiché |
| `data/maps/SproutTower_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SproutTower_2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/SproutTower_3F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TestMap1_hns/scripts.inc` | sans texte affiché |
| `data/maps/TestMap2_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TinTower_2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_3F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_4F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_5F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_6F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_7F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_8F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_9F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TinTower_RoofDay_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TinTower_RoofNight_hns/scripts.inc` | sans texte affiché |
| `data/maps/TohjoFalls_Cavern_hns/scripts.inc` | sans texte affiché |
| `data/maps/TohjoFalls_GiovanniRoom_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TradeCenter_hns/scripts.inc` | sans texte affiché |
| `data/maps/TrainerHill_1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TrainerHill_2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TrainerHill_3F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TrainerHill_4F_hns/scripts.inc` | sans texte affiché |
| `data/maps/TrainerHill_Courtyard_hns/scripts.inc` | à traduire |
| `data/maps/TrainerHill_Elevator_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/TrainerHill_Entrance_hns/scripts.inc` | à traduire |
| `data/maps/TrainerHill_Roof_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/Trees_hns/scripts.inc` | sans texte affiché |
| `data/maps/UlaUla_Cave_2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaUla_Cave_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaUla_Forest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaUla_House_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UlaulaIsle_hns/scripts.inc` | à traduire |
| `data/maps/UnionCave_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UnionCave_B1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UnionCave_B2F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/UnionRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/VerdanturfTown_BattleTentBattleRoom_hns/scripts.inc` | sans texte affiché |
| `data/maps/VerdanturfTown_BattleTentCorridor_hns/scripts.inc` | sans texte affiché |
| `data/maps/VerdanturfTown_BattleTentLobby_hns/scripts.inc` | à traduire |
| `data/maps/VermilionCity_FanClub_hns/scripts.inc` | à traduire |
| `data/maps/VermilionCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/VermilionCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_House3_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_PortInside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_PortOutside_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VermilionCity_hns/scripts.inc` | à traduire |
| `data/maps/VictoryRoadKanto_1F_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VictoryRoadKanto_B1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/VictoryRoadKanto_B2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/VioletCity_Gym_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_House2_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_TrainerSchool_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/VioletCity_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_Gym_hns/scripts.inc` | à traduire |
| `data/maps/ViridianCity_House1_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_House2_hns/scripts.inc` | sans texte affiché |
| `data/maps/ViridianCity_Mart_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_PokemonCenter_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/ViridianCity_hns/scripts.inc` | à traduire |
| `data/maps/ViridianForest_hns/scripts.inc` | traduit, à valider en jeu |
| `data/maps/WhirlIslands_1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/WhirlIslands_B1F_Inner_hns/scripts.inc` | sans texte affiché |
| `data/maps/WhirlIslands_B1F_hns/scripts.inc` | sans texte affiché |
| `data/maps/WhirlIslands_B2F_hns/scripts.inc` | sans texte affiché |
| `data/maps/WhirlIslands_B3F_hns/scripts.inc` | sans texte affiché |
| `data/maps/WhirlIslands_Descent_hns/scripts.inc` | sans texte affiché |
| `data/maps/WhirlIslands_LugiaChamber_hns/scripts.inc` | traduit, à valider en jeu |
