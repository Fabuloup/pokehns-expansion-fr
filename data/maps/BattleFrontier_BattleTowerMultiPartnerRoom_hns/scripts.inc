BattleFrontier_BattleTowerMultiPartnerRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume_hns:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition_hns:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner_hns::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp_hns:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth_hns::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom_hns::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom_hns::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom_hns:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit_hns:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_hns::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge_hns::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator_hns::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR_HNS, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hns::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsEast_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator_hnsWest_hns:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hns:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator_hnsEast_hns:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest_hns:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM_HNS, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner_hns::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit_hnsSouth_hns::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hns:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit_hnsSouth_hns:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8_hns::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_hns
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns:
	.string "Veuillez choisir le DRESSEUR qui\n"
	.string "sera votre partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner_hns:
	.string "{PLAYER}, vous n'avez pas trouvé de\n"
	.string "partenaire.\p"
	.string "Voulez-vous arrêter de chercher et\n"
	.string "retourner au guichet\l"
	.string "d'inscription?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner_hns2_hns:
	.string "Alors je vous prie de choisir l'un\n"
	.string "de ces DRESSEURS comme partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner_hns::
	.string "Merci d'avoir choisi un\n"
	.string "partenaire.\p"
	.string "Je vais maintenant vous mener à\n"
	.string "votre SALLE DE COMBAT MULTI.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro_hns::
	.string "Je suis l'apprenti no {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "Appelle-moi {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1_hns::
	.string "Sur les conseils de {STR_VAR_1}, j'ai pris\n"
	.string "un {STR_VAR_3} avec {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Laisse-moi faire équipe avec toi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept_hns::
	.string "Merci! Je vais m'inscrire tout de\n"
	.string "suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject_hns::
	.string "Je voulais vraiment faire équipe\n"
	.string "avec toi, {PLAYER}...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro_hns::
	.string "Je suis l'apprenti no {STR_VAR_2} de {STR_VAR_1}. Je\n"
	.string "m'appelle {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1_hns::
	.string "{STR_VAR_1} m'a conseillé de choisir un {STR_VAR_3}\n"
	.string "avec {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "S'il te plaît, faisons équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept_hns::
	.string "Merci beaucoup! Je vais vite\n"
	.string "m'inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject_hns::
	.string "{PLAYER}, j'espérais pouvoir faire équipe\n"
	.string "avec toi...$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro_hns::
	.string "Hum, je m'appelle {STR_VAR_3}. Je suis\n"
	.string "l'apprenti nº {STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Sniff…\p"
	.string "Je suis désolé! Je ne supporte pas\n"
	.string "cette pression…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1_hns::
	.string "{STR_VAR_3} m'a conseillé. J'ai un {STR_VAR_2} avec {STR_VAR_1}\n"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Sniff… S'il te plaît, fais équipe\n"
	.string "avec moi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept_hns::
	.string "Vraiment? Tu veux bien? Super!\n"
	.string "Extra!\p"
	.string "Oh… Je suis désolé… Ce sont des\n"
	.string "larmes de joie…\p"
	.string "Je vais nous inscrire tout de\n"
	.string "suite. Surtout, reste ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject_hns::
	.string "Oh, mais… Sniff… Ouin!!!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro_hns::
	.string "Bonjour! Je suis {STR_VAR_3}! Je suis\n"
	.string "l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1_hns::
	.string "{STR_VAR_3} a choisi mon équipe! J'ai un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask_hns::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}! Plutôt pas mal,\n"
	.string "hein?\p"
	.string "Allez, vas-y! Fais équipe avec\n"
	.string "moi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept_hns::
	.string "Ouais, super! Je vais m'inscrire,\n"
	.string "alors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject_hns::
	.string "Mais pourquoi, d'abord? Je veux\n"
	.string "faire équipe avec toi, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro_hns::
	.string "Je suis {STR_VAR_3}, l'apprenti nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1_hns::
	.string "J'ai demandé conseil à {STR_VAR_3}. Un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}, voilà ce\n"
	.string "que j'ai.\p"
	.string "S'il te plaît, tu veux bien faire\n"
	.string "équipe avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept_hns::
	.string "Merci! Je vais nous inscrire tout\n"
	.string "de suite!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject_hns::
	.string "{PLAYER}, j'avais tellement envie de\n"
	.string "faire équipe avec toi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro_hns::
	.string "Oh… Ça me fait plaisir que tu\n"
	.string "viennes me parler.\p"
	.string "Je m'appelle {STR_VAR_3}. Je suis\n"
	.string "l'apprentie nº {STR_VAR_2} de {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1_hns::
	.string "{STR_VAR_3} a bien voulu me conseiller. Je\n"
	.string "lui dois tant de choses!\p"
	.string "Dans mon équipe, j'ai un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask_hns::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}. Je sais que j'en\n"
	.string "demande trop…\p"
	.string "Tu vas sûrement refuser, mais tu\n"
	.string "veux bien qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept_hns::
	.string "Vraiment? Je n'arrive pas à le\n"
	.string "croire! On va faire équipe! Je… Je\l"
	.string "serai à la hauteur!\p"
	.string "Bon… Je vais vite nous inscrire\n"
	.string "avant que tu ne changes d'avis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject_hns::
	.string "Je comprends… Je ne suis pas à la\n"
	.string "hauteur…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro_hns::
	.string "Salut, je m'appelle {STR_VAR_3}. Je suis\n"
	.string "l'apprentie nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1_hns::
	.string "C'est {STR_VAR_3} qui a fait mon équipe!\n"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask_hns::
	.string "et un {STR_VAR_2} qui connaît {STR_VAR_1}.\p"
	.string "Pas mal, non? Alors, on fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept_hns::
	.string "D'accord! J'espère qu'on va bien\n"
	.string "s'entendre! Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject_hns::
	.string "Quoi? Tu refuses? Tu ne sais pas\n"
	.string "ce que tu perds!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro_hns::
	.string "Je m'appelle {STR_VAR_3}. Je suis\n"
	.string "TRIATHLETE. Je n'arrête pas!\l"
	.string "Footing, entraînement, danse…\p"
	.string "Et je suis aussi l'apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1_hns::
	.string "Voilà ce que {STR_VAR_3} m'a conseillé. Un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Malgré tout ce que j'ai à faire,\n"
	.string "j'ai trouvé le temps de les\l"
	.string "dresser!\p"
	.string "On fait équipe et on voit ce que\n"
	.string "ça donne?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept_hns::
	.string "Merci! Tu as l'esprit sportif! Ne\n"
	.string "bouge pas, je vais nous inscrire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject_hns::
	.string "Je vois. Pour ta gouverne, je\n"
	.string "déteste qu'on me fasse perdre mon\l"
	.string "temps!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro_hns::
	.string "Bonjour! Comment ça va?\p"
	.string "Je suis {STR_VAR_3}, l'apprentie nº {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "Enchantée!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1_hns::
	.string "Ecoute, écoute! C'est {STR_VAR_3} qui a\n"
	.string "composé mon équipe POKéMON. J'ai\l"
	.string "un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask_hns::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}. Je les ai bien\n"
	.string "dressés!\p"
	.string "Tu veux qu'on fasse équipe? Je\n"
	.string "suis sûre qu'on ira bien ensemble!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept_hns::
	.string "Super, on va bien s'amuser! Je\n"
	.string "vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject_hns::
	.string "Quelle méchanceté! Je suis sûre\n"
	.string "que tu vas le regretter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro_hns::
	.string "Je me présente, je m'appelle {STR_VAR_3}.\p"
	.string "Je suis l'apprentie nº {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1_hns::
	.string "J'ai suivi les conseils de {STR_VAR_3} et\n"
	.string "dans mon équipe j'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask_hns::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "On fait équipe ensemble? S'il te\n"
	.string "plaît!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept_hns::
	.string "Oh… J'en suis ravie! Je vais\n"
	.string "donner tout ce que j'ai!\p"
	.string "Allez, je vais nous inscrire!\n"
	.string "Attends-moi ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject_hns::
	.string "J'espérais vraiment être ta\n"
	.string "partenaire, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro_hns::
	.string "Hé, tu m'as parlée! Ça me fait\n"
	.string "tellement plaisir!\p"
	.string "Je m'appelle {STR_VAR_3}! Je suis\n"
	.string "l'apprentie nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1_hns::
	.string "J'ai écouté {STR_VAR_3} et j'ai dressé un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Tu veux bien exaucer mon souhait?\n"
	.string "J'aimerais faire équipe avec toi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept_hns::
	.string "Oh… C'est un jour merveilleux!\n"
	.string "Merci infiniment! Je vais nous\l"
	.string "inscrire sur le champ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject_hns::
	.string "Oh! Tu n'as donc aucun cœur? Mais\n"
	.string "je t'admire, tu sais…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro_hns::
	.string "Bonjour! Je suis l'apprenti nº {STR_VAR_2}\n"
	.string "de {STR_VAR_1}!\p"
	.string "Je m'appelle {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1_hns::
	.string "Mon mentor {STR_VAR_3} m'a conseillé un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Pas mal, non? On fait équipe,\n"
	.string "alors?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept_hns::
	.string "Excellent! Je vais nous inscrire\n"
	.string "vite fait!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject_hns::
	.string "Je me méfierai de toi à l'avenir,\n"
	.string "{PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro_hns::
	.string "Tu sais quoi? C'est le dernier\n"
	.string "jour de la TOUR DE COMBAT!\p"
	.string "… … … … … … Mais non, je rigole!\p"
	.string "On m'appelle {STR_VAR_3}. Normal, c'est mon\n"
	.string "nom! Je suis l'apprenti nº 1 000\l"
	.string "de {STR_VAR_1}. Non, je suis le nº {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1_hns::
	.string "{STR_VAR_3} m'a recommandé les {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask_hns::
	.string "et les {STR_VAR_2} utilisant {STR_VAR_1}. J'en ai dix\n"
	.string "de chaque. Je rigole, j'en ai\l"
	.string "qu'un de chaque!\p"
	.string "Alors, on fait équipe, toi et moi?\n"
	.string "Qu'en dis-tu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept_hns::
	.string "Youpi! Allez, je te donne un\n"
	.string "POKéMON!\p"
	.string "Tu m'as pas cru, j'espère! Je\n"
	.string "passe au guichet d'inscription et\l"
	.string "je reviens!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject_hns::
	.string "Tu me le paieras! Je vais faire de\n"
	.string "ta vie un enfer!\p"
	.string "Mais non, je rigole! Ha, ha, ha!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro_hns::
	.string "Salut, DRESSEUR! J'attends ici\n"
	.string "depuis des heures!\p"
	.string "Non, je ne suis pas un requin\n"
	.string "blanc… Je suis {STR_VAR_3}, le MARIN\l"
	.string "chantant!\p"
	.string "Je suis l'apprenti nº {STR_VAR_2} de {STR_VAR_1}. Avec\n"
	.string "moi, ça va swinguer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1_hns::
	.string "Les conseils de {STR_VAR_3}, je les ai\n"
	.string "suivis, et mon équipe a bien\l"
	.string "grandi! J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask_hns::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Faisons équipe, nom d'une pipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept_hns::
	.string "Hé, hé, j'aime ton style! Je vais\n"
	.string "nous inscrire, je file!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject_hns::
	.string "Hé, {PLAYER}! Tu me surprends! Moi,\n"
	.string "j'étais partant!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro_hns::
	.string "Yahou, yippie! Oh, je t'en prie,\n"
	.string "reste!\p"
	.string "Je m'appelle {STR_VAR_3}! Je suis l'apprenti\n"
	.string "nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1_hns::
	.string "{STR_VAR_3} m'a dit quoi faire. J'ai un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask_hns::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Qu'en dis-tu? Me choisiras-tu?\p"
	.string "Laisse-moi être ton partenaire!\n"
	.string "Allez… Accepte, partenaire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept_hns::
	.string "Oh, ça me fait tellement plaisir!\n"
	.string "Je ne sais pas quoi dire!\p"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject_hns::
	.string "Tu me rejettes? {PLAYER}, ton\n"
	.string "comportement est abject!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro_hns::
	.string "Oh, je tousse!\p"
	.string "Désolé, j'ai pris froid. Mes\n"
	.string "POKéMON vont bien, eux.\p"
	.string "Je m'appelle {STR_VAR_3}. Je suis l'apprenti\n"
	.string "nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1_hns::
	.string "{STR_VAR_3} a formé mon équipe. J'ai un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et aussi un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask_hns::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Je les entraîne tous les jours,\n"
	.string "qu'il pleuve, qu'il neige, qu'il\l"
	.string "vente!\p"
	.string "C'est d'ailleurs pour ça que j'ai\n"
	.string "pris froid, je pense.\p"
	.string "Maintenant que tu me connais un\n"
	.string "peu, tu veux qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept_hns::
	.string "Merci! Ça me fait plaisir! Je\n"
	.string "n'arrête pas de tousser… Allez, je\l"
	.string "vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject_hns::
	.string "Tu ne veux pas? Quel dommage, {PLAYER}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro_hns::
	.string "Bonjour! Il y a trop de monde,\n"
	.string "ici…\p"
	.string "Je m'appelle {STR_VAR_3}. Je suis l'apprenti\n"
	.string "nº {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1_hns::
	.string "{STR_VAR_3} m'a conseillé cette équipe… Un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ça me met mal à l'aise de te\n"
	.string "parler… Mais veux-tu qu'on fasse\l"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept_hns::
	.string "Oh, merci! J'ai peur mais je ferai\n"
	.string "de mon mieux!\p"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject_hns::
	.string "Tu ne peux pas refuser! Je crois\n"
	.string "que je vais faire un malaise…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro_hns::
	.string "Je m'appelle {STR_VAR_3}, je suis l'apprenti\n"
	.string "nº {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1_hns::
	.string "Je dois mon équipe à {STR_VAR_3}.\p"
	.string "J'ai suivi ses conseils. J'ai un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask_hns::
	.string "{STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Si tu es d'accord, j'aimerais être\n"
	.string "ton partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept_hns::
	.string "Tu acceptes? Tu ne le regretteras\n"
	.string "pas!\p"
	.string "Je vais nous inscrire et nous\n"
	.string "pourrons commencer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject_hns::
	.string "Tu refuses? Ton humour est\n"
	.string "totalement déplacé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro_hns::
	.string "Je m'appelle {STR_VAR_1}. Je suis une\n"
	.string "FILLETTE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1_hns::
	.string "J'ai un {STR_VAR_2} qui utilise {STR_VAR_1} et puis un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask_hns::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}. C'est tout ce que\n"
	.string "j'ai avec moi.\p"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept_hns::
	.string "Merci! Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject_hns::
	.string "Tu ne veux pas de moi comme\n"
	.string "partenaire? Tu vas t'en mordre les\l"
	.string "doigts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro_hns::
	.string "Salut!\p"
	.string "Je suis GAMIN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1_hns::
	.string "Tu veux savoir ce que j'ai? Un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On va faire équipe, toi et moi,\n"
	.string "non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept_hns::
	.string "Chouette! Je vais nous inscrire,\n"
	.string "alors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject_hns::
	.string "Tu as tort! Avec tes POKéMON et\n"
	.string "les miens, on serait invincibles!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro_hns::
	.string "Bien le bonjour! Je suis\n"
	.string "MONTAGNARD {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1_hns::
	.string "Tu veux savoir ce que j'ai avec\n"
	.string "moi? Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Pas trop mal, non? Tu veux qu'on\n"
	.string "fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept_hns::
	.string "D'accord! Je vais au guichet et je\n"
	.string "reviens.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject_hns::
	.string "Dommage, j'aurais aimé me battre à\n"
	.string "tes côtés.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro_hns::
	.string "Bonjour! Je m'appelle {STR_VAR_1} et je suis\n"
	.string "un CANON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1_hns::
	.string "Tu sais ce que j'ai dressé? Un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu'en penses-tu? Tu veux qu'on\n"
	.string "fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept_hns::
	.string "Merveilleux! Je vais au guichet!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject_hns::
	.string "Quel dommage!\p"
	.string "Toi et moi, nous aurions fait une\n"
	.string "belle équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro_hns::
	.string "Bonjour, toi!\p"
	.string "Tu sais qui je suis? Je suis {STR_VAR_1} le\n"
	.string "PECHEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1_hns::
	.string "Mon équipe se compose d'un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask_hns::
	.string "d'un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Qu'en dis-tu? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept_hns::
	.string "Bien, bien! Je me charge de tout!\p"
	.string "Je vais nous inscrire tout de\n"
	.string "suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject_hns::
	.string "Oh, c'est bien dommage…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro_hns::
	.string "Ravie de te rencontrer. Je suis\n"
	.string "MADEMOISELLE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1_hns::
	.string "Je suis accompagnée d'un {STR_VAR_2}\n"
	.string "maîtrisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask_hns::
	.string "et d'un {STR_VAR_2} maîtrisant {STR_VAR_1}.\p"
	.string "M'acceptes-tu comme partenaire?\n"
	.string "Cela me ferait tant plaisir!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept_hns::
	.string "Je te remercie du fond du cœur. Je\n"
	.string "m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject_hns::
	.string "Je suis sûre que tu vas le\n"
	.string "regretter. Cependant, je respecte\l"
	.string "ta décision.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro_hns::
	.string "Je m'appelle {STR_VAR_1}. Je suis\n"
	.string "TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1_hns::
	.string "Voyons ce que j'ai… Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}! C'est mon équipe!\p"
	.string "Dis, tu veux bien qu'on soit\n"
	.string "partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept_hns::
	.string "Merci! Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject_hns::
	.string "C'est dommage, je sais qu'on\n"
	.string "aurait été très forts ensemble!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro_hns::
	.string "Bonjour! Je suis le SCOUT {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1_hns::
	.string "Regarde ce que j'ai! Un {STR_VAR_2} avec {STR_VAR_1}\n"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Je te propose que nous fassions\n"
	.string "équipe, tous les deux! Tu es\l"
	.string "d'accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept_hns::
	.string "Bien!\p"
	.string "Je m'occupe de l'inscription,\n"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject_hns::
	.string "Tu sais, mes POKéMON valent le\n"
	.string "détour. J'espère que tu ne le\l"
	.string "regretteras pas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro_hns::
	.string "Bonjour! Je suis l'ELEVE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1_hns::
	.string "J'ai dressé un {STR_VAR_2} qui utilise {STR_VAR_1} et\n"
	.string "un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask_hns::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "C'est plutôt bien, non? Tu veux\n"
	.string "qu'on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept_hns::
	.string "Merci! Je m'occupe de\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject_hns::
	.string "Je suis déçu…\p"
	.string "En me battant avec toi, j'aurais\n"
	.string "pu apprendre un tas de choses…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro_hns::
	.string "Bonjour. Je suis RICHARD {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1_hns::
	.string "Tu ne devineras jamais ce que\n"
	.string "j'ai! Un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask_hns::
	.string "et un {STR_VAR_2} utilisant {STR_VAR_1}!\p"
	.string "Si tu le souhaites, tu peux faire\n"
	.string "équipe avec moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept_hns::
	.string "C'est intelligent de ta part! Avec\n"
	.string "moi, impossible de perdre!\p"
	.string "Je m'occupe de l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject_hns::
	.string "Tu vas le regretter! Je suis le\n"
	.string "meilleur dans cette pièce!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro_hns::
	.string "Hiyah! Je suis KARATEKA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1_hns::
	.string "J'ai un {STR_VAR_2} qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask_hns::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Sois sympa, choisis-moi comme\n"
	.string "partenaire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept_hns::
	.string "Hiyah! Je vais nous inscrire\n"
	.string "illico presto!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject_hns::
	.string "Je comprends… Ce n'est que partie\n"
	.string "remise…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro_hns::
	.string "Bonjour! Je suis FLOTTEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1_hns::
	.string "Voilà ce que j'ai… Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}! Tu veux bien qu'on\n"
	.string "fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept_hns::
	.string "Merci! Je vais nous inscrire\n"
	.string "immédiatement!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject_hns::
	.string "Ensemble, on aurait pu battre\n"
	.string "n'importe qui, j'en suis sûre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro_hns::
	.string "Bien le bonjour… Je suis\n"
	.string "MYSTIMANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1_hns::
	.string "J'ai sur moi un {STR_VAR_2} qui utilise {STR_VAR_1} et\n"
	.string "un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask_hns::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}…\p"
	.string "Je t'en supplie… Choisis-moi comme\n"
	.string "partenaire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept_hns::
	.string "Je te remercie… Je vais nous\n"
	.string "inscrire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject_hns::
	.string "J'espérais tant qu'on fasse\n"
	.string "équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro_hns::
	.string "Comment ça va? Je m'appelle {STR_VAR_1}. Je\n"
	.string "suis un ELEVEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1_hns::
	.string "J'ai deux POKéMON pas mal du tout!\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu'en penses-tu? Tu penses qu'on\n"
	.string "devrait faire équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept_hns::
	.string "Je te remercie!\p"
	.string "Ne bouge pas, je vais au guichet\n"
	.string "d'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject_hns::
	.string "J'aurais préféré que tu dises oui,\n"
	.string "bien sûr… Mais tant pis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro_hns::
	.string "Bonjour! Je m'appelle {STR_VAR_1}. Je suis\n"
	.string "TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1_hns::
	.string "Tu veux savoir ce que j'ai? Un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Alors? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept_hns::
	.string "C'est parti! Je vais nous inscrire\n"
	.string "sur le champ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject_hns::
	.string "Toi et moi, on aurait fait un\n"
	.string "carton! Tu ne sais pas ce que tu\l"
	.string "rates…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro_hns::
	.string "Bonjour! Je m'appelle {STR_VAR_1}! Je suis\n"
	.string "TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1_hns::
	.string "J'ai bien entraîné mes POKéMON!\n"
	.string "J'ai un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Il y a pire, non? Tu veux de moi\n"
	.string "comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept_hns::
	.string "Très bien! Je cours nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject_hns::
	.string "J'aurais bien aimé combattre à tes\n"
	.string "côtés…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro_hns::
	.string "Je suis COMBATTANTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1_hns::
	.string "J'ai dressé un {STR_VAR_2} qui utilise {STR_VAR_1} et\n"
	.string "un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask_hns::
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Alors, ça te plaît? Si on faisait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept_hns::
	.string "Oh, merci!\p"
	.string "Je m'occupe de l'inscription, ne\n"
	.string "bouge pas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject_hns::
	.string "Je suis sûre qu'ensemble, on\n"
	.string "aurait été imbattables…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro_hns::
	.string "Je m'appelle {STR_VAR_1}. Je suis\n"
	.string "TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1_hns::
	.string "J'ai un {STR_VAR_2} à qui j'ai appris {STR_VAR_1} et\n"
	.string "un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask_hns::
	.string "{STR_VAR_2} qui connaît {STR_VAR_1}!\p"
	.string "On ferait une équipe du tonnerre,\n"
	.string "tous les deux! Non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept_hns::
	.string "Merci!\p"
	.string "Il ne reste plus qu'à nous\n"
	.string "inscrire. J'y cours!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject_hns::
	.string "C'est dommage. Je me faisais une\n"
	.string "telle joie à l'idée de combattre à\l"
	.string "tes côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro_hns::
	.string "Moi? Je suis FLOTTEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1_hns::
	.string "Ce que j'ai? Un {STR_VAR_2} qui connaît {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask_hns::
	.string "un {STR_VAR_2} qui connaît {STR_VAR_1}!\p"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept_hns::
	.string "D'accord!\p"
	.string "Je vais nous inscrire! Ça va\n"
	.string "déménager!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject_hns::
	.string "Mes POKéMON sont forts… C'est bête\n"
	.string "que tu ne veuilles pas de moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro_hns::
	.string "Bonjour! Je suis GUITARISTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1_hns::
	.string "Regarde qui est là… Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On pourrait pas rêver mieux, non?\n"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept_hns::
	.string "Super! Je vais m'occuper des\n"
	.string "formalités au guichet. Je reviens!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject_hns::
	.string "Mes POKéMON sont les meilleurs! Tu\n"
	.string "risques de le regretter!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro_hns::
	.string "Ravi de faire ta connaissance. Je\n"
	.string "suis {STR_VAR_1}, un vrai GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1_hns::
	.string "Mon cher {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask_hns::
	.string "mon cher {STR_VAR_2} avec {STR_VAR_1} sont ici.\p"
	.string "Puis-je te demander de me choisir\n"
	.string "comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept_hns::
	.string "Je te remercie de ta confiance.\n"
	.string "Reste ici, je m'occupe de\l"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject_hns::
	.string "Cela m'aurait fait tant plaisir…\p"
	.string "J'espère que nous aurons\n"
	.string "l'occasion de faire équipe une\l"
	.string "autre fois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro_hns::
	.string "Bonjour, je m'appelle {STR_VAR_1}. Je suis\n"
	.string "POKéFAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1_hns::
	.string "Avec moi, j'ai un {STR_VAR_2} qui utilise {STR_VAR_1}\n"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask_hns::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Est-ce que ça te plaît? On fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept_hns::
	.string "Merci! Je m'occupe de\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject_hns::
	.string "Tu ne sais pas reconnaître de bons\n"
	.string "POKéMON quand tu en vois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro_hns::
	.string "Je suis {STR_VAR_1}. Je suis un EXPERT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1_hns::
	.string "J'ai élevé un {STR_VAR_2} qui connaît {STR_VAR_1} et\n"
	.string "un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask_hns::
	.string "{STR_VAR_2} qui connaît {STR_VAR_1}!\p"
	.string "Que dirais-tu de faire équipe avec\n"
	.string "moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept_hns::
	.string "Parfait! Je vais de ce pas nous\n"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject_hns::
	.string "Je doute que tu aies fait le bon\n"
	.string "choix…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro_hns::
	.string "Bonjour, bonjour! Je suis EXPERT\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1_hns::
	.string "J'ai élevé mes POKéMON avec soin.\n"
	.string "J'ai un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask_hns::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}. Voilà!\p"
	.string "Voudrais-tu faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept_hns::
	.string "Bien, bien. Je vais de suite nous\n"
	.string "inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject_hns::
	.string "D'accord. On remet ça à une\n"
	.string "prochaine fois, alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro_hns::
	.string "Je suis DRACOLOGUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1_hns::
	.string "Mon équipe se compose d'un {STR_VAR_2}\n"
	.string "utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask_hns::
	.string "et d'un {STR_VAR_2} utilisant {STR_VAR_1}!\p"
	.string "Qu'est-ce que tu en dis? Tu me\n"
	.string "prends comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept_hns::
	.string "Je te promets de faire de mon\n"
	.string "mieux! Je m'occupe de\l"
	.string "l'inscription, d'accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject_hns::
	.string "Tu sais, tu ne trouveras pas mieux\n"
	.string "que moi, ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro_hns::
	.string "Je suis l'ORNITHOLOGUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1_hns::
	.string "Quels POKéMON j'ai? Un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask_hns::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Tu ne penses pas qu'on ferait une\n"
	.string "bonne équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept_hns::
	.string "Super, merci! Je vais m'occuper de\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject_hns::
	.string "Mes POKéMON et moi sommes très\n"
	.string "forts. Quel dommage pour toi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro_hns::
	.string "Je suis NINJA FAN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1_hns::
	.string "Mon équipe de POKéMON comporte un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Faisons équipe, tous les deux!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept_hns::
	.string "Ouais! Je me charge de\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject_hns::
	.string "Tu vas regretter de ne pas avoir\n"
	.string "mes POKéMON à tes côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro_hns::
	.string "Bonjour! Je suis SŒUR PARASOL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1_hns::
	.string "Je ne suis pas seule. J'ai avec\n"
	.string "moi un {STR_VAR_2} utilisant {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask_hns::
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}.\p"
	.string "N'est-ce pas merveilleux? Tu veux\n"
	.string "faire équipe avec nous?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept_hns::
	.string "Merci beaucoup!\p"
	.string "Je vais nous inscrire au guichet.\n"
	.string "Nous ferons de notre mieux!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject_hns::
	.string "Mes POKéMON sont incroyablement\n"
	.string "forts. Quelle déception…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro_hns::
	.string "Bonjour! Je suis {STR_VAR_1} l'ENTOMOMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1_hns::
	.string "Oui, j'ai trouvé mes POKéMON. J'ai\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask_hns::
	.string "et {STR_VAR_2} avec {STR_VAR_1}. C'est tout ce que\n"
	.string "j'ai trouvé.\p"
	.string "Ça t'intéresse de faire équipe\n"
	.string "avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept_hns::
	.string "Compris! Super!\p"
	.string "Je m'occupe de l'inscription. Ça\n"
	.string "ne prendra pas longtemps!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject_hns::
	.string "Avec mes POKéMON, on aurait gagné\n"
	.string "à coup sûr, tu sais?…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro_hns::
	.string "Bonjour! Je suis MARIN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1_hns::
	.string "Mes POKéMON sont ma fierté! J'ai\n"
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask_hns::
	.string "et un {STR_VAR_2} utilisant {STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec moi,\n"
	.string "n'est-ce pas?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept_hns::
	.string "J'en étais sûr! Je m'occupe de\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject_hns::
	.string "Avec mes POKéMON et moi, c'était\n"
	.string "pourtant la victoire assurée!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro_hns::
	.string "Bonjour, je suis COLLEC {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1_hns::
	.string "J'ai ici deux beaux spécimens: un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "C'est le nec plus ultra en matière\n"
	.string "de POKéMON, non? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept_hns::
	.string "Oh, super!\p"
	.string "Ne perdons pas de temps. Je vais\n"
	.string "nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject_hns::
	.string "Ça me chiffonne un peu… Tu n'aimes\n"
	.string "pas mes POKéMON…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro_hns::
	.string "Bonjour, je m'appelle {STR_VAR_1}. Je suis\n"
	.string "un POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1_hns::
	.string "Je suis escorté par un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask_hns::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Tu ne penses pas qu'on ferait une\n"
	.string "équipe du tonnerre, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept_hns::
	.string "C'est super! Je vais m'occuper de\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject_hns::
	.string "La prochaine fois, choisis mes\n"
	.string "POKéMON où je risque de me vexer…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro_hns::
	.string "Je suis {STR_VAR_1}, une POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1_hns::
	.string "Voici mon équipe: j'ai un {STR_VAR_2} avec {STR_VAR_1}\n"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec mes\n"
	.string "petits protégés et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept_hns::
	.string "Nous ferons de notre mieux, c'est\n"
	.string "promis! Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject_hns::
	.string "J'espère que tu nous choisiras, la\n"
	.string "prochaine fois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro_hns::
	.string "Ravie de faire ta connaissance. Je\n"
	.string "suis AROMA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1_hns::
	.string "Je sillonne les chemins avec un {STR_VAR_2}\n"
	.string "utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask_hns::
	.string "et un {STR_VAR_2} utilisant {STR_VAR_1}.\p"
	.string "J'espère qu'ils te conviennent. Tu\n"
	.string "veux bien qu'on soit partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept_hns::
	.string "Ton choix m'honore. Je vais au\n"
	.string "guichet d'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject_hns::
	.string "Cela me ferait plaisir de faire\n"
	.string "équipe avec toi une prochaine\l"
	.string "fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro_hns::
	.string "Tu veux savoir qui je suis? Je\n"
	.string "suis RUINEMANIAC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1_hns::
	.string "Les POKéMON qui m'accompagnent\n"
	.string "sont un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask_hns::
	.string "et un {STR_VAR_2} utilisant {STR_VAR_1}!\p"
	.string "Intrigant, n'est-ce pas? Si nous\n"
	.string "faisions équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept_hns::
	.string "C'est une sage décision! Je me\n"
	.string "charge des formalités\l"
	.string "d'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject_hns::
	.string "Hum… Mes POKéMON sont très forts\n"
	.string "pourtant…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro_hns::
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1_hns::
	.string "J'ai amené un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask_hns::
	.string "un {STR_VAR_2} qui sait utiliser {STR_VAR_1}.\n"
	.string "Impressionnant, je sais!\p"
	.string "Dis, tu ne crois pas qu'on devrait\n"
	.string "faire équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept_hns::
	.string "Cool! Je vais vite au guichet\n"
	.string "d'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject_hns::
	.string "On aurait pourtant bien combattu\n"
	.string "ensemble.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro_hns::
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1_hns::
	.string "L'équipe que j'ai formée comporte\n"
	.string "un {STR_VAR_2} utilisant {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask_hns::
	.string "un {STR_VAR_2} utilisant {STR_VAR_1}.\p"
	.string "Ça correspond à ce que tu\n"
	.string "cherches? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept_hns::
	.string "J'espérais que tu dirais ça! Je\n"
	.string "vais nous inscrire, alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject_hns::
	.string "Je pensais qu'on aurait fait une\n"
	.string "belle équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro_hns::
	.string "Bonjour! Je suis POKéMANIAC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1_hns::
	.string "Tu te demandes ce que j'ai? Un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}. Oui, rien\n"
	.string "que ça!\p"
	.string "Je sais que ça t'impressionne.\n"
	.string "Allez, faisons équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept_hns::
	.string "Excellente décision! Je vais nous\n"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject_hns::
	.string "Rien ne peut arrêter mes POKéMON!\n"
	.string "Tu vas regretter ta décision!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro_hns::
	.string "Salut, toi! Je m'appelle {STR_VAR_1}! Je\n"
	.string "suis un SALTIMBANQUE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1_hns::
	.string "Voici le fruit de mon\n"
	.string "entraînement: un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Alors, qu'en dis-tu? On fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept_hns::
	.string "Bien! Je m'occupe de\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject_hns::
	.string "Quel dommage. Promets-moi qu'on\n"
	.string "fera équipe la prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro_hns::
	.string "Je suis CAMPEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1_hns::
	.string "J'ai dressé un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask_hns::
	.string "{STR_VAR_2} qui sait utiliser {STR_VAR_1}.\p"
	.string "On s'amuserait bien si on était\n"
	.string "dans la même équipe! Alors, on\l"
	.string "essaie?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept_hns::
	.string "Super! Sur ce, je vais nous\n"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject_hns::
	.string "Bon, une prochaine fois, alors!\n"
	.string "J'aimerais bien combattre à tes\l"
	.string "côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro_hns::
	.string "Bonjour! Je suis PIQUE-NIQUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1_hns::
	.string "J'ai avec moi un {STR_VAR_2} qui utilise {STR_VAR_1}\n"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask_hns::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Ça te dirait de faire équipe avec\n"
	.string "moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept_hns::
	.string "Eh bien, merci! Je me charge de\n"
	.string "l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject_hns::
	.string "D'accord. J'espère qu'on fera\n"
	.string "équipe une prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro_hns::
	.string "Je suis KINESISTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1_hns::
	.string "Les deux POKéMON que j'ai dressés\n"
	.string "sont un {STR_VAR_2} utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask_hns::
	.string "et un {STR_VAR_2} utilisant {STR_VAR_1}.\p"
	.string "Qu'en dis-tu? On est partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept_hns::
	.string "Très bien! Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject_hns::
	.string "D'accord. Mais tu dois me\n"
	.string "promettre qu'on fera équipe\l"
	.string "bientôt.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro_hns::
	.string "Je suis KINESISTE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1_hns::
	.string "J'ai avec moi… un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask_hns::
	.string "un {STR_VAR_2} avec {STR_VAR_1}. Ce sont mes\n"
	.string "disciples.\p"
	.string "Je suis sûre que tout cela\n"
	.string "t'intrigue… Si tu veux, nous\l"
	.string "pouvons faire équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept_hns::
	.string "Merci. Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject_hns::
	.string "J'espère qu'il y aura une autre\n"
	.string "occasion. Tu m'intrigues…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro_hns::
	.string "Je suis ELEVE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1_hns::
	.string "Mes POKéMON? J'ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask_hns::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Ça me plairait bien d'être ta\n"
	.string "partenaire. Tu es d'accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept_hns::
	.string "Oh, merci! Je vais aller au\n"
	.string "guichet pour nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject_hns::
	.string "Hein? La prochaine fois alors,\n"
	.string "non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro_hns::
	.string "Coucou! Je suis {STR_VAR_1}, un ELEVEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1_hns::
	.string "Voici les POKéMON que j'ai\n"
	.string "dressés: un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "C'est plutôt tentant, je sais. On\n"
	.string "fait équipe, d'accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept_hns::
	.string "Parfait! Laisse-moi m'occuper de\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject_hns::
	.string "Je comprends, mais la prochaine\n"
	.string "fois, tu ne pourras pas refuser!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro_hns::
	.string "Je suis {STR_VAR_1}. Je suis une POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1_hns::
	.string "Mes POKéMON chéris sont un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}.\p"
	.string "Ne sont-ils pas mignons? Il faut\n"
	.string "absolument qu'on fasse équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept_hns::
	.string "Je te remercie! Je m'occupe de\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject_hns::
	.string "Mes POKéMON chéris sont les\n"
	.string "meilleurs, crois-moi. Mais c'est\l"
	.string "toi qui décides!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro_hns::
	.string "Bonjour! Je suis {STR_VAR_1}, une NAGEUSE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1_hns::
	.string "Mes POKéMON? J'ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask_hns::
	.string "un {STR_VAR_2} qui sait utiliser {STR_VAR_1}.\p"
	.string "Si on faisait équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept_hns::
	.string "Super! Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject_hns::
	.string "Si jamais on se rencontre de\n"
	.string "nouveau, tu ne pourras pas\l"
	.string "refuser!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro_hns::
	.string "Oui? Je m'appelle {STR_VAR_1} et je suis\n"
	.string "TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1_hns::
	.string "J'ai quelques POKéMON qui se\n"
	.string "défendent: un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask_hns::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Ce serait sympa si on faisait\n"
	.string "équipe, tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept_hns::
	.string "Merveilleux! Je vais nous\n"
	.string "inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject_hns::
	.string "Tu me laisseras être ton\n"
	.string "partenaire la prochaine fois,\l"
	.string "j'espère.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro_hns::
	.string "Je suis {STR_VAR_1}, une TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1_hns::
	.string "J'ai avec moi… un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}, voilà ce\n"
	.string "que j'ai.\p"
	.string "Qu'en penses-tu? Je pense qu'on\n"
	.string "ferait une bonne équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept_hns::
	.string "J'aime cette réponse! Je m'occupe\n"
	.string "de l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject_hns::
	.string "Promets-moi que tu me donneras\n"
	.string "bientôt ma chance…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro_hns::
	.string "Bonjour, bonjour! Je suis {STR_VAR_1}, un\n"
	.string "NAGEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1_hns::
	.string "Regarde quels POKéMON j'ai\n"
	.string "dressés! Un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask_hns::
	.string "et un {STR_VAR_2} qui utilise {STR_VAR_1}!\p"
	.string "Pas mal, non? Alors, on fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept_hns::
	.string "Quel honneur! Je me charge de\n"
	.string "l'inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject_hns::
	.string "On remet ça à une prochaine fois,\n"
	.string "d'accord?$"
