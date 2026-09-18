Gate_NationalPark_hns_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "Bonjour, Dresseur! Le Concours de\n"
	.string "Capture a lieu aujourd'hui.\p"
	.string "Les règles sont simples.\p"
	.string "Avec un de tes POKéMON, attrape\n"
	.string "un POKéMON Insecte à faire juger.\p"
	.string "Tu veux tenter ta chance?$"

Route35NationalParkGate_Text_OfficerGiveSportBalls:
	.string "L'EXP gagnée par ton POKéMON\n"
	.string "pendant le concours sera annulée\l"
	.string "à ton départ.\p"
	.string "Voici les COMPÉT'BALL du\n"
	.string "Concours.$"

Route35NationalParkGate_Text_ReceivedSportBalls:
	.string "{PLAYER} reçoit des COMPÉT'BALL.$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "Celui qui obtient le POKéMON\n"
	.string "Insecte le plus fort l'emporte.\p"
	.string "Si tu n'as plus de COMPÉT'BALL,\n"
	.string "c'est terminé pour toi.\p"
	.string "Tu peux attraper jusqu'à 5\n"
	.string "POKéMON. Seul le dernier attrapé\l"
	.string "sera gardé et présenté au\l"
	.string "concours.\p"
	.string "Va donc attraper le POKéMON\n"
	.string "Insecte le plus fort possible!$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "Si tu as plus d'un POKéMON, tu\n"
	.string "devras utiliser le premier de\l"
	.string "ton équipe.\p"
	.string "Ça te convient?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "Parfait, nous gardons tes autres\n"
	.string "POKéMON pendant le concours.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "Les POKéMON de {PLAYER} sont\n"
	.string "confiés à l'ASSISTANT CONCOURS.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "Choisis le POKéMON à utiliser au\n"
	.string "Concours, puis viens me voir.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "Entendu. Nous espérons te voir\n"
	.string "participer une autre fois.$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "Oh là… Le premier POKéMON de ton\n"
	.string "équipe ne peut pas combattre.\p"
	.string "Échange-le avec celui que tu veux\n"
	.string "utiliser, puis viens me voir.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "Oh là… Ton équipe et ta BOÎTE PC\n"
	.string "sont pleines.\p"
	.string "Tu n'as pas de place pour le\n"
	.string "POKéMON Insecte que tu attraperas.\p"
	.string "Fais de la place dans ton équipe\n"
	.string "ou ta BOÎTE PC, puis viens me\l"
	.string "voir.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "Oh là… Tu as un ŒUF en tête\n"
	.string "d'équipe.\p"
	.string "Échange-le avec le POKéMON que tu\n"
	.string "veux utiliser, puis viens me voir.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "Le Concours du jour est terminé.\n"
	.string "À une prochaine fois, j'espère.$"

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "J'adore les POKéMON oiseaux! J'ai\n"
	.string "trouvé un oiseau de type TÉNÈBRES\l"
	.string "dans le parc, cette nuit!$"

Route35NationalParkGate_Text_BC2:
	.string "J'ai attrapé un INSÉCATEUR géant!$"

Route35NationalParkGate_Text_Beauty:
	.string "Il gagne toujours ces concours!$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "Nous organisons des Concours\n"
	.string "régulièrement dans le PARC.\l"
	.string "Tu devrais essayer.$"

Route35NationalParkGate_Text_YoungsterWonders:
	.string "C'est quand, le prochain Concours\n"
	.string "de Capture?$"

Route35NationalParkGate_Text_ContestExplanation:
	.string "Le Concours de Capture se déroule\n"
	.string "le mardi, le jeudi et le samedi.\p"
	.string "Non seulement tu gagnes un lot\n"
	.string "rien qu'en participant,\p"
	.string "mais tu gardes aussi le POKéMON\n"
	.string "Insecte que tu as à la fin du\l"
	.string "concours.$"
