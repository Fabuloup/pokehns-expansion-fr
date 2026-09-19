BattleFrontier_ScottsHouse_hns_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott_hns::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment_hns::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns:
	.string "SCOTT: Bonjour et bienvenue!\n"
	.string "Hi hi… Désolé, c'est étroit ici.\p"
	.string "Enfin, {PLAYER}{KUN}, laisse-moi\n"
	.string "t'accueillir à la ZONE DE COMBAT.\p"
	.string "Mon rêve est devenu réalité.\n"
	.string "Après tant d'années, j'ai enfin\l"
	.string "pu lui donner vie.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns:
	.string "Ce fut un très long voyage…\n"
	.string "J'ai pris la route pour me\p"
	.string "mettre à la recherche de\n"
	.string "DRESSEURS forts. J'ai bâti\p"
	.string "ce rêve au prix de tant\n"
	.string "d'efforts et de sacrifices!$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns:
	.string "Mais tout cela est du passé.\n"
	.string "Inutile de s'y attarder!\p"
	.string "Je veux que tu profites à fond\n"
	.string "des combats proposés ici.\p"
	.string "{PLAYER}{KUN}, accepte ce souvenir\n"
	.string "de toutes les fois où nos chemins\l"
	.string "se sont croisés.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns:
	.string "{PLAYER} obtient\n"
	.string "{STR_VAR_1} POINT(S) DE COMBAT.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns:
	.string "SCOTT: Tes POINTS DE COMBAT sont\n"
	.string "indiqués sur ton PASSE ZONE.\p"
	.string "Plus tu réussiras d'épreuves,\n"
	.string "plus tu gagneras de Points\l"
	.string "de Combat.\p"
	.string "Utilise-les comme bon te semble,\n"
	.string "par exemple contre des objets.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns:
	.string "J'attends beaucoup de toi!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns:
	.string "SCOTT: Chaque DRESSEUR est unique.\n"
	.string "Chacun a sa propre histoire.\p"
	.string "Mais au combat, ils doivent\n"
	.string "laisser tout ça derrière eux!\p"
	.string "Ils sont tous DRESSEURS! J'aime\p"
	.string "cette pureté. Face au combat,\n"
	.string "les DRESSEURS sont tous égaux.\p"
	.string "C'est pourquoi je voyage à la\n"
	.string "recherche de DRESSEURS dignes de\l"
	.string "ce nom et que je les invite ici.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns:
	.string "SCOTT: As-tu déjà rencontré\n"
	.string "un des CERVEAUX DE LA ZONE?\p"
	.string "Mieux, as-tu déjà obtenu des\n"
	.string "Symboles? Les CERVEAUX DE LA ZONE\p"
	.string "ont été triés sur le volet.\n"
	.string "Ce sont les meilleurs! Mais\p"
	.string "je suis sûr que tu serais\n"
	.string "capable de leur faire peur!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns:
	.string "SCOTT: Tu ne t'entraînes\n"
	.string "pas que pour les combats,\p"
	.string "n'est-ce pas? Il me semble\n"
	.string "que tu travailles aussi à\p"
	.string "un POKéDEX. Eh bien, devine\p"
	.string "quoi! Il y a des POKéMON\n"
	.string "sauvages dans la ZONE DE\l"
	.string "COMBAT… Ouvre les yeux!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns:
	.string "SCOTT: Tout se passe bien\n"
	.string "dans la ZONE DE COMBAT?\p"
	.string "Attends un instant… Oh!\n"
	.string "Ton PASSE ZONE! Tu as\p"
	.string "tous les symboles argent!\n"
	.string "C'est impressionnant!\l"
	.string "Mais ça ne me surprend\p"
	.string "pas vraiment! D'ordinaire,\n"
	.string "je ne fais pas ce genre\p"
	.string "de choses, mais là c'est\n"
	.string "exceptionnel! Je veux que\p"
	.string "tu prennes ça. Je suis sûr\n"
	.string "que tu en feras bon usage.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns:
	.string "SCOTT: J'espère que tu profites\n"
	.string "bien de toute la ZONE DE COMBAT.\p"
	.string "…Attends une seconde…\n"
	.string "Je n'en crois pas mes yeux!\p"
	.string "Ton PASSE ZONE!\n"
	.string "Tu as réuni la collection entière\l"
	.string "des Symboles d'or!\p"
	.string "C'est tout simplement prodigieux!\n"
	.string "Tu es incroyable, je le savais!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, tu dois accepter ceci!\p"
	.string "Je pense que tu sauras vraiment\n"
	.string "apprécier la valeur de ce cadeau!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns:
	.string "Je sais reconnaître un bon\n"
	.string "DRESSEUR quand j'en vois\p"
	.string "un. Je me félicite d'avoir\n"
	.string "décidé de t'inviter ici!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns:
	.string "La POCHE BAIES\n"
	.string "a l'air pleine.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns:
	.string "SCOTT: Oh, on m'a raconté tes\n"
	.string "exploits à la TOUR DE COMBAT!\l"
	.string "Tu as battu plus de 50 DRESSEURS\p"
	.string "à la suite? C'est fantastique!\n"
	.string "Je veux que tu acceptes ça!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns:
	.string "SCOTT: Oh! On m'a tout raconté!\n"
	.string "Tu as dominé la TOUR DE COMBAT!\l"
	.string "Plus de 100 DRESSEURS à la suite?\p"
	.string "C'est absolument spectaculaire!\n"
	.string "Tu dois accepter ceci!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns:
	.string "Je me demande bien quelles\n"
	.string "surprises tu me réserves encore!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns:
	.string "Eh bien si tu n'as pas de place\n"
	.string "pour l'instant, reviens plus tard.$"

