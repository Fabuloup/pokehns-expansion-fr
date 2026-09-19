BattleFrontier_ReceptionGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition_hns
	.byte 0

BattleFrontier_ReceptionGate_OnTransition_hns:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame_hns:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_FRONTIER_RECEPTION_GREETER
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene_hns
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene_hns::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter_hns
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit_hns
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter_hns:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit_hns:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike_hns
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall_hns
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode_hns::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_Level50_hns::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry_hns::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems_hns::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_Symbols_hns::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns:
	.string "C'est la première fois que vous\n"
	.string "venez? Par ici, s'il vous plaît!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns:
	.string "Bienvenue à la ZONE DE COMBAT!\n"
	.string "Le summum des combats de POKéMON!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns:
	.string "Pour votre première visite,\n"
	.string "nous devons vous délivrer\p"
	.string "le PASSE ZONE. Vous pourrez\n"
	.string "l'utiliser dans toute la\p"
	.string "ZONE DE COMBAT. Tenez!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns:
	.string "{PLAYER} obtient\n"
	.string "le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns:
	.string "{PLAYER} place sa CARTE DRESSEUR\n"
	.string "dans le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns:
	.string "Profitez de tout ce que la ZONE\n"
	.string "DE COMBAT peut vous offrir!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns:
	.string "???: Tiens, mais c'est {PLAYER}{KUN}!\n"
	.string "Tu es venu jusqu'ici!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns:
	.string "GUIDE: Oh! SCOTT! Quel\n"
	.string "plaisir de vous voir!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns:
	.string "SCOTT: Je suis très heureux\n"
	.string "de te voir ici! J'espère que\p"
	.string "tu prendras le temps de tout\n"
	.string "visiter. Naturellement, j'espère\p"
	.string "aussi que tu profiteras de\n"
	.string "l'essence même du combat.\p"
	.string "J'ai également une maison ici,\n"
	.string "n'hésite pas à me rendre visite.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns:
	.string "Je vous présente les différents\n"
	.string "sites de la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns:
	.string "Que voulez-vous découvrir?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns:
	.string "Cette tour gigantesque est le\n"
	.string "symbole de la ZONE DE COMBAT.\p"
	.string "Elle a quatre SALLES DE COMBAT\n"
	.string "pour les modes SOLO, DUO, MULTI\l"
	.string "et MULTI LINK.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns:
	.string "Le DÔME DE COMBAT\n"
	.string "est un grand bâtiment\p"
	.string "en forme d'œuf. Des\n"
	.string "TOURNOIS DE COMBAT y\p"
	.string "ont lieu. Les TOURNOIS\n"
	.string "DE COMBAT se jouent en\l"
	.string "COMBATS SOLO ou DUO.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns:
	.string "Le bâtiment rouge à droite est le\n"
	.string "PALACE DE COMBAT.\p"
	.string "Il propose deux SALLES DE COMBAT\n"
	.string "pour les modes SOLO et DUO.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns:
	.string "Le DOJO DE COMBAT se\n"
	.string "trouve à la droite du\l"
	.string "centre de la ZONE DE\p"
	.string "COMBAT. Des TOURNOIS\n"
	.string "K.O. y ont lieu.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns:
	.string "L'USINE DE COMBAT est\n"
	.string "le grand bâtiment tout\p"
	.string "près d'ici. On y propose\n"
	.string "le COMBAT ECHANGE. Ce\p"
	.string "défi peut prendre la\n"
	.string "forme de COMBATS SOLO\l"
	.string "ou de COMBATS DUO.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns:
	.string "Au centre-gauche, le bâtiment en\n"
	.string "forme de POKéMON est le REPTILE\l"
	.string "DE COMBAT.\p"
	.string "On y joue à l'épreuve appelée\n"
	.string "COMBAT HASARD.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns:
	.string "La PYRAMIDE DE COMBAT\n"
	.string "est l'énorme pyramide.\p"
	.string "L'évènement appelé\n"
	.string "COMBAT QUETE y a lieu.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns:
	.string "Le HALL DE CLASSEMENT se\n"
	.string "trouve près de la TOUR DE\p"
	.string "COMBAT. On peut y consulter\n"
	.string "les records des meilleurs\l"
	.string "DRESSEURS s'étant battus\l"
	.string "dans la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns:
	.string "Le SERVICE D'ECHANGE se trouve\n"
	.string "près de la TOUR DE COMBAT. Vous\p"
	.string "pouvez y échanger les POINTS DE\n"
	.string "COMBAT obtenus dans la ZONE DE\l"
	.string "COMBAT contre des prix fabuleux.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns:
	.string "Je peux vous expliquer les\n"
	.string "règles de base communes\l"
	.string "aux défis des différents\l"
	.string "bâtiments de la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns:
	.string "Que voulez-vous découvrir?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns:
	.string "Pour tous les défis de la ZONE\n"
	.string "DE COMBAT, vous pouvez choisir\l"
	.string "entre niveau 50 et niveau libre.$"

BattleFrontier_ReceptionGate_Text_Level50Info_hns:
	.string "Le niveau 50 accepte les POKéMON\n"
	.string "jusqu'au niveau 50 inclus.\p"
	.string "Attention: aucun DRESSEUR\n"
	.string "que vous affronterez n'aura de\l"
	.string "POKéMON sous le niveau 50.\p"
	.string "Ce parcours permet de débuter les\n"
	.string "combats de la ZONE DE COMBAT.\p"
	.string "Commencez plutôt par tenter\n"
	.string "ce parcours.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns:
	.string "Niveau libre ne fixe pas de\n"
	.string "limite au niveau des POKéMON\l"
	.string "participant à un défi. Le niveau\p"
	.string "de vos adversaires sera ajusté en\n"
	.string "fonction du niveau de vos POKéMON.\l"
	.string "Cependant, aucun des DRESSEURS que\p"
	.string "vous affronterez n'aura de POKéMON\n"
	.string "dont le niveau est inférieur à 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns:
	.string "Presque tous les POKéMON\n"
	.string "peuvent relever les défis de\p"
	.string "tous les bâtiments. Les OEUFS\n"
	.string "et certains POKéMON ne sont pas\p"
	.string "autorisés. Le nombre de POKéMON\n"
	.string "nécessaires pour participer\p"
	.string "varie selon l'endroit. Cependant,\n"
	.string "il est impossible d'inscrire\l"
	.string "deux POKéMON identiques.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns:
	.string "Dans une épreuve de la ZONE DE\n"
	.string "COMBAT, deux POKéMON ne peuvent\l"
	.string "tenir le même type d'objet.\p"
	.string "Vérifiez que tous vos POKéMON\n"
	.string "participants tiennent des\l"
	.string "objets différents.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns:
	.string "Je vous présente le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns:
	.string "Que voulez-vous découvrir?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns:
	.string "La ZONE DE COMBAT compte sept\n"
	.string "sites.\p"
	.string "Les DRESSEURS reconnus pour leur\n"
	.string "talent peuvent recevoir un Symbole\l"
	.string "de chaque site.\p"
	.string "Pour en gagner un, ils doivent\n"
	.string "vaincre des DRESSEURS à la suite\l"
	.string "et parfois répéter les épreuves.\p"
	.string "Ce n'est vraiment pas facile.\n"
	.string "Je vous souhaite bonne chance!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns:
	.string "Un combat peut être enregistré\n"
	.string "sur votre PASSE ZONE.\p"
	.string "Vous pouvez enregistrer un combat\n"
	.string "contre un ou plusieurs amis.\p"
	.string "Ou bien un combat de la ZONE,\n"
	.string "sauf ceux ayant lieu dans le\l"
	.string "REPTILE DE COMBAT ou dans la\l"
	.string "PYRAMIDE DE COMBAT.\p"
	.string "Vous pourrez alors l'enregistrer\n"
	.string "à la fin du combat.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns:
	.string "Les POINTS DE COMBAT récompensent\n"
	.string "les DRESSEURS qui font de\l"
	.string "beaux combats dans la ZONE DE\p"
	.string "COMBAT. Vous pouvez échanger\n"
	.string "vos POINTS DE COMBAT contre\l"
	.string "des prix au SERVICE D'ECHANGE.$"

