BattleFrontier_Lounge3_hns_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5_hns
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10_hns
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15_hns
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet5_hns::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet10_hns::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet15_hns::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet_hns
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_PlaceBet_hns::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet_hns
	end

BattleFrontier_Lounge3_EventScript_FinishBet_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns::
	msgbox BattleFrontier_Lounge3_Text_Oh_hns, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults_hns
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults_hns::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge_hns
	goto BattleFrontier_Lounge3_EventScript_LostChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_WonChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15_hns
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NotInterested_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet_hns::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_PokefanF_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FatMan_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns::
	.string "… Qu'est-ce que tu veux?\p"
	.string "Nous sommes occupés. Tu ne\n"
	.string "peux pas revenir plus tard?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns::
	.string "… Tu as l'air d'être un bon\n"
	.string "DRESSEUR. Hé, hé… J'ai quelque\p"
	.string "chose à te proposer. On est\n"
	.string "un petit groupe et on joue\p"
	.string "à un petit jeu ici. On mise\n"
	.string "sur ce qui se passe à la ZONE\l"
	.string "DE COMBAT. Les règles sont\p"
	.string "simples. D'abord, on choisit\p"
	.string "un des bâtiments de la ZONE\n"
	.string "DE COMBAT. Ensuite, on choisit\p"
	.string "chacun un DRESSEUR qui relève\n"
	.string "le défi de ce bâtiment et\l"
	.string "on mise des POINTS DE COMBAT\p"
	.string "dessus. Celui qui a misé sur le\n"
	.string "DRESSEUR qui fait le meilleur\l"
	.string "score récolte tous les POINTS\p"
	.string "DE COMBAT mis en jeu. Plutôt\n"
	.string "simple, non? De toute façon…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va relever le défi des SALLES\l"
	.string "DE COMBAT SOLO de la TOUR DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va relever le défi des SALLES\l"
	.string "DE COMBAT DUO de la TOUR DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va relever le défi des SALLES\l"
	.string "DE COMBAT MULTI de la TOUR DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va participer au TOURNOI\l"
	.string "DE COMBAT SOLO du DÔME DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va participer au TOURNOI\l"
	.string "DE COMBAT DUO du DÔME DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\l"
	.string "ÉCHANGE SOLO de l'USINE DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\l"
	.string "ÉCHANGE DUO de l'USINE DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va relever le défi des HALLS\l"
	.string "DE COMBAT SOLO du PALACE DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va relever le défi des HALLS\l"
	.string "DE COMBAT DUO du PALACE DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va participer au TOURNOI\l"
	.string "K.O. du DOJO DE COMBAT.\p"
	.string "Mais je n'ai pas vu un\n"
	.string "seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va relever le défi du COMBAT\l"
	.string "HASARD au REPTILE DE COMBAT.\p"
	.string "Mais je n'ai pas vu un\n"
	.string "seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid_hns::
	.string "Je cherche un DRESSEUR qui\n"
	.string "va relever le défi du COMBAT\l"
	.string "QUETE dans la PYRAMIDE DE\p"
	.string "COMBAT. Mais je n'ai pas vu\n"
	.string "un seul DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns::
	.string "Bien sûr, tu ne feras pas ça pour\n"
	.string "rien. Qu'est-ce que tu en dis?\l"
	.string "Tu veux bien être ce DRESSEUR?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns::
	.string "Très bien. Parfait. Heu…\n"
	.string "Tu veux bien me prêter\l"
	.string "quelques POINTS DE COMBAT?\p"
	.string "Fais-moi confiance, je te\n"
	.string "remercierai comme il se doit.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns::
	.string "Super! Combien tu\n"
	.string "peux me prêter?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns::
	.string "Non mais! Tu n'as pas assez\n"
	.string "de POINTS DE COMBAT! Ça\p"
	.string "t'amuse de faire perdre leur\n"
	.string "temps aux honnêtes gens?$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns::
	.string "Hé, hé! Merci\n"
	.string "bien! C'est parti!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle_hns::
	.string "Vite, les SALLES DE COMBAT\n"
	.string "SOLO de la TOUR DE COMBAT\p"
	.string "t'attendent! Tu dois gagner!\n"
	.string "Je compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble_hns::
	.string "Vite, les SALLES DE COMBAT\n"
	.string "DUO de la TOUR DE COMBAT\p"
	.string "t'attendent! Tu dois gagner!\n"
	.string "Je compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti_hns::
	.string "Vite, les SALLES DE COMBAT\n"
	.string "MULTI de la TOUR DE COMBAT\p"
	.string "t'attendent! Tu dois gagner!\n"
	.string "Je compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle_hns::
	.string "Vite, le TOURNOI DE COMBAT\n"
	.string "SOLO du DÔME DE COMBAT\p"
	.string "t'attend! Tu dois gagner! Je\n"
	.string "compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble_hns::
	.string "Vite, le TOURNOI DE COMBAT DUO\n"
	.string "du DÔME DE COMBAT t'attend!\p"
	.string "Tu dois gagner! Je compte\n"
	.string "sur toi! Notre avenir à\l"
	.string "tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle_hns::
	.string "Vite, le TOURNOI COMBAT ÉCHANGE\n"
	.string "SOLO de l'USINE DE COMBAT\p"
	.string "t'attend! Tu dois gagner! Je\n"
	.string "compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble_hns::
	.string "Vite, le TOURNOI COMBAT ÉCHANGE\n"
	.string "DUO de l'USINE DE COMBAT\p"
	.string "t'attend! Tu dois gagner! Je\n"
	.string "compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle_hns::
	.string "Vite, les HALLS DE COMBAT\n"
	.string "SOLO du PALACE DE COMBAT\p"
	.string "t'attendent! Tu dois gagner!\n"
	.string "Je compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble_hns::
	.string "Vite, les HALLS DE COMBAT\n"
	.string "DUO du PALACE DE COMBAT\p"
	.string "t'attendent! Tu dois gagner!\n"
	.string "Je compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleArena_hns::
	.string "Vite, le TOURNOI K.O. du\n"
	.string "DOJO DE COMBAT t'attend!\p"
	.string "Tu dois gagner! Je compte\n"
	.string "sur toi! Notre avenir à\l"
	.string "tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePike_hns::
	.string "Vite, le défi du COMBAT\n"
	.string "HASARD t'attend au REPTILE\p"
	.string "DE COMBAT! Tu dois gagner! Je\n"
	.string "compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid_hns::
	.string "Vite, le défi du COMBAT QUETE\n"
	.string "t'attend dans la PYRAMIDE DE\p"
	.string "COMBAT! Tu dois gagner! Je\n"
	.string "compte sur toi! Notre avenir\l"
	.string "à tous les deux en dépend!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns::
	.string "Oh, c'est toi… C'était bien\n"
	.string "tenté… Malheureusement,\p"
	.string "je ne peux pas te rendre\n"
	.string "ce que tu m'as prêté… Ça\p"
	.string "nous apprendra à faire plus\n"
	.string "attention la prochaine fois!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns::
	.string "Bravo! Tu as été\n"
	.string "formidable! Je le\p"
	.string "savais! Je te faisais\n"
	.string "confiance! On est les\l"
	.string "meilleurs! Je te rends\p"
	.string "ce que tu m'as prêté\n"
	.string "avec un petit extra!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns::
	.string "{PLAYER} obtient\n"
	.string "{STR_VAR_1} POINTS DE COMBAT.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns::
	.string "Si tu as envie de relever\n"
	.string "un autre défi, pense à moi!$"

BattleFrontier_Lounge3_Text_NotInterested_hns::
	.string "Ça ne t'intéresse pas?\n"
	.string "Penses-y, au moins!$"

BattleFrontier_Lounge3_Text_Oh_hns::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns::
	.string "J'ai encore misé sur le mauvais\p"
	.string "DRESSEUR! Je crois que je\n"
	.string "devrais arrêter ces bêtises…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns::
	.string "Ce DRESSEUR… Il est bon, mais\p"
	.string "il n'a pas les nerfs assez\n"
	.string "solides pour le DÔME DE COMBAT…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns::
	.string "Hi, hi, hi! Je sais\n"
	.string "reconnaître un gagnant!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns::
	.string "Ces DRESSEURS… Mais que\n"
	.string "font-ils? Ils devraient\l"
	.string "aller se battre.$"
