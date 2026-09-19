BattleFrontier_OutsideWest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition_hns
	.byte 0

BattleFrontier_OutsideWest_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_EventScript_Sailor_hns::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_AsYouLike_hns
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	hideobjectat LOCALID_BATTLE_FRONTIER_SAILOR_HNS, MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS
	setvar VAR_0x8004, LOCALID_FARAWAY_BATTLE_FRONTIER_HNS_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_AsYouLike_hns::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign_hns, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2_hns::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1_hns::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_Maniac2_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hns::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns::
	return

BattleFrontier_OutsideWest_EventScript_Girl_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass_hns::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM_hns::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2_hns::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1_hns::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2_hns::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF_hns::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign_hns:
	.string "DÔME DE COMBAT La voie toute\n"
	.string "tracée vers la célébrité!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign_hns:
	.string "USINE DE COMBAT Nos POKéMON\n"
	.string "sont les plus forts!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign_hns:
	.string "REPTILE DE COMBAT Choisissez\n"
	.string "un des trois chemins!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns:
	.string "Voici la TOUR DE COMBAT.\p"
	.string "Les DRESSEURS y font participer\n"
	.string "leurs meilleurs POKéMON en duel.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket_hns:
	.string "Bonjour. C'est pour le ferry?\n"
	.string "Puis-je voir votre PASSE BATEAU?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard_hns:
	.string "{PLAYER} n'a pas de TICKET…\p"
	.string "Je suis vraiment désolé.\p"
	.string "Il faut un TICKET pour monter\n"
	.string "à bord du ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo_hns:
	.string "{PLAYER} montre son TICKET.\p"
	.string "Parfait! C'est tout ce qu'il faut!\p"
	.string "Où souhaitez-vous aller?$"

BattleFrontier_OutsideWest_Text_SlateportItIs_hns:
	.string "Alors, cap sur POIVRESSEL!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs_hns:
	.string "Alors, cap sur NENUCRIQUE?$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime_hns:
	.string "Revenez une autre fois!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry_hns:
	.string "Veuillez monter sur le\n"
	.string "ferry et attendre le départ.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo_hns:
	.string "Alors, où souhaiteriez-vous aller?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns:
	.string "Je suis meilleur que\n"
	.string "tous mes copains.\l"
	.string "Mais ici… Je suis nul!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns:
	.string "Je cherche la TOUR DE COMBAT,\n"
	.string "mais même avec la carte de la\l"
	.string "ZONE DE COMBAT, je me perds.\p"
	.string "Cet endroit est immense!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns:
	.string "Mon intention était de relever\n"
	.string "un défi dès mon arrivée\p"
	.string "ici. Mais en chemin, j'ai\n"
	.string "eu le mal de mer… Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns:
	.string "Tout le monde ne peut pas\n"
	.string "venir ici, tu sais. Seuls les\p"
	.string "DRESSEURS dont le talent a été\n"
	.string "reconnu sont ici. Beaucoup de\p"
	.string "DRESSEURS n'ont jamais entendu\n"
	.string "parler de la ZONE DE COMBAT.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns:
	.string "Dis… Tu penses qu'on\p"
	.string "peut participer même si\n"
	.string "on n'a pas de POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns:
	.string "Heu… Ben, c'est ce qu'on m'a\n"
	.string "dit. Enfin, je crois… Et tu\p"
	.string "te souviens de ce que m'a dit\p"
	.string "le colosse? Il m'a dit qu'il\n"
	.string "me prêterait des POKéMON!$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns:
	.string "C'est l'USINE DE COMBAT. Tu peux\n"
	.string "y louer des POKéMON très forts.\p"
	.string "Mais au fait… Je me demande qui\n"
	.string "élève ces POKéMON de location!?!$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns:
	.string "J'ai peur d'aller au REPTILE\n"
	.string "DE COMBAT à cause de SEVIPER…\p"
	.string "Mais je ne suis pas venue\n"
	.string "ici pour rien! Je vais\l"
	.string "me battre! … J'ai peur…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns:
	.string "Jouons à pierre, papier,\n"
	.string "ciseaux! Un, deux,\p"
	.string "trois! … … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns:
	.string "Oui! J'ai gagné! Je vais relever\n"
	.string "le défi du REPTILE DE COMBAT!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns:
	.string "Oh, non… J'ai perdu. Ce\n"
	.string "n'est pas mon jour de\p"
	.string "chance. Je vais attendre\n"
	.string "demain pour relever le\l"
	.string "défi du REPTILE DE COMBAT.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns:
	.string "Je suis persuadé que je suis la\n"
	.string "seule personne ici qui préfère\l"
	.string "la pêche aux combats. Comment?\p"
	.string "Il n'y a rien à pêcher ici? C'est\n"
	.string "dommage, c'est un bel endroit…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns:
	.string "Aujourd'hui, je combattrai sans\n"
	.string "relâche jusqu'à gagner un Symbole.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns:
	.string "Tu veux relever le défi du\n"
	.string "DÔME DE COMBAT? Je te souhaite\p"
	.string "bonne chance. Ce serait\n"
	.string "amusant, si l'on se retrouvait\l"
	.string "face à face lors d'un combat.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns:
	.string "Papy, par ici! Le\n"
	.string "DÔME DE COMBAT est\l"
	.string "là! Vas-y, papy!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns:
	.string "C'est donc ça, le DÔME DE COMBAT?\n"
	.string "Aucun GENTLEMAN ne pourra me\p"
	.string "battre! Mais où est l'entrée?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns:
	.string "Il n'y a pas si longtemps, il n'y\n"
	.string "avait rien à cet endroit. Mais\p"
	.string "maintenant, regarde! Incroyable!\n"
	.string "Il faut que j'emmène ma mère ici.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns:
	.string "Je suis enfin arrivée à la\n"
	.string "ZONE DE COMBAT! Mon physique\p"
	.string "avantageux et ma technique\n"
	.string "me feront sûrement gagner!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns:
	.string "Miam, miam… On\p"
	.string "dirait que tout le\n"
	.string "monde est très fort\p"
	.string "ici. Miam, miam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns:
	.string "Miam, miam… Il y a un\p"
	.string "certain temps, j'ai rencontré\n"
	.string "cette femme au REPTILE DE\p"
	.string "COMBAT. Elle avait un regard\n"
	.string "effrayant, ça m'a fichu la\p"
	.string "frousse. Miam, miam… Elle\p"
	.string "m'a hurlé dessus: Arrête\n"
	.string "de manger! et s'est mise à\p"
	.string "rire! J'en ai eu la chair\n"
	.string "de poule… J'entends encore\p"
	.string "son rire… Miam, miam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns:
	.string "Hein? Écoute-toi un peu!\n"
	.string "Ce n'est rien du tout!\p"
	.string "En l'acclamant la dernière fois,\n"
	.string "nos regards se sont croisés!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns:
	.string "Quoi??? Pfft! Si je n'avais\n"
	.string "pas été assis à côté de\p"
	.string "toi, il ne t'aurait même\n"
	.string "pas regardée! Ce sont mes\p"
	.string "encouragements qui ont attiré\n"
	.string "le regard de l'AS DU DÔME!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns:
	.string "Oh, chut! Mettez-la un\n"
	.string "peu en sourdine! Vous, les\p"
	.string "fans, vous devriez vous\n"
	.string "contenter des CHAMPION\p"
	.string "D'ARÈNE! L'AS DU DÔME\n"
	.string "est à moi! C'est mon idole!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns:
	.string "Ces gens qui se disputent là-bas…\p"
	.string "C'est dur à croire, mais ils\n"
	.string "étaient DRESSEURS, avant. Ils\p"
	.string "étaient bons. Ils avaient une\n"
	.string "force incroyable et ils étaient\p"
	.string "même célèbres! Mais ils se sont\n"
	.string "fait écraser par un DRESSEUR lors\p"
	.string "d'un tournoi. Leur défaite a été\n"
	.string "telle qu'ils ont été subjugués\p"
	.string "par lui. Maintenant, ce sont des\n"
	.string "fans. Ils vont au DÔME DE COMBAT\l"
	.string "tous les jours pour l'encourager.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns:
	.string "On raconte qu'un POKéMON doté\n"
	.string "d'une longue queue aurait été\l"
	.string "vu dans la ZONE DE COMBAT.\p"
	.string "Il doit être adorable, c'est sûr…\p"
	.string "Les défis attendront. Je dois\n"
	.string "trouver cette merveille!$"

