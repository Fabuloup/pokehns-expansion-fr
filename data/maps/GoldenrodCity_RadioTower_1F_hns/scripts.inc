GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "BLANCHE: Salut!\p"
	.string "Je m'appelle BLANCHE!\p"
	.string "J'ai entendu parler du QUIZ pour\n"
	.string "gagner une CARTE RADIO, alors je\l"
	.string "suis venue en chercher une…\p"
	.string "Mais ce QUIZ est trop dur!$"

RadioTower1F_Text_Whitney2::
	.string "BLANCHE: Ouah, tu as réussi!\p"
	.string "J'étais sûre que la réponse à la\n"
	.string "troisième question, c'était les\l"
	.string "NOIGRUMES! Oups!\p"
	.string "Il est temps que je rentre à\n"
	.string "l'ARÈNE!$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "Bienvenue!$"

RadioTower1F_Text_ReceptionistNoTours:
    .string "Bonjour. Désolée, nous ne faisons\n"
    .string "pas de visites aujourd'hui.$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "Nous organisons un QUIZ spécial\n"
    .string "en ce moment.\p"
    .string "Réponds juste à cinq questions et\n"
    .string "gagne une CARTE RADIO pour le\l"
    .string "POKéMATOS.\p"
    .string "Toi et tes POKéMON pourrez écouter\n"
    .string "de la musique partout, à toute\l"
    .string "heure.\p"
    .string "Veux-tu participer au QUIZ?$"

RadioTower1F_Text_QuizQuestion1:
    .string "Question 1:\p"
    .string "Existe-t-il un POKéMON qui\n"
    .string "n'apparaît que le jour?$"

RadioTower1F_Text_QuizQuestion2:
    .string "Exact!\n"
    .string "Question 2:\p"
    .string "Cette affirmation est-elle vraie?\p"
    .string "On ne peut pas acheter de BAIE\n"
    .string "dans une BOUTIQUE.$"

RadioTower1F_Text_QuizQuestion3:
    .string "Dans le mille!\n"
    .string "Question 3:\p"
    .string "FARGAS, le créateur de POKé BALL,\n"
	.string "utilise des NOIGRUMES?$"

RadioTower1F_Text_QuizQuestion4:
    .string "Ça se passe bien!\n"
    .string "Question 4:\p"
    .string "ALBERT est-il le CHAMPION de\n"
    .string "MAUVILLE, qui utilise des POKéMON\l"
    .string "oiseaux?$"

RadioTower1F_Text_QuizQuestion5:
    .string "Ouah! Encore juste!\n"
    .string "Voici la dernière question:\p"
    .string "Les machines du CASINO de\n"
    .string "DOUBLONVILLE ont-elles SALAMÈCHE\l"
    .string "sur leurs rouleaux?$"

RadioTower1F_Text_QuizWin:
    .string "Bingo! Tu as trouvé!\n"
    .string "Félicitations!\p"
    .string "Voici ton prix, une CARTE RADIO!$"

RadioTower1F_Text_PokegearRadio:
    .string "Le POKéMATOS de {PLAYER} fait\n"
    .string "maintenant aussi RADIO!$"

RadioTower1F_Text_TuneIn:
    .string "Écoute bien nos émissions RADIO.$"

RadioTower1F_Text_WrongAnswer:
    .string "Oh là.\n"
    .string "Désolée, c'est faux.\p"
    .string "Réessaie donc!$"

RadioTower1F_Text_DeclineQuiz:
    .string "Oh. Je vois. Reviens me voir si\n"
    .string "tu changes d'avis.$"

RadioTower1F_Text_Lass:
    .string "BEN est un super DJ!\p"
    .string "Sa voix me fait craquer!$"

RadioTower1F_Text_Youngster:
    .string "J'adore LULA, de la CHRONIQUE\n"
    .string "POKéMON.\p"
    .string "Cela dit, je ne connais que sa\n"
    .string "voix.$"

RadioTower1F_Text_GruntM3Seen:
    .string "Nous avons enfin pris la\n"
    .string "TOUR RADIO!\p"
    .string "Le monde entier va connaître la\n"
    .string "vraie terreur de la TEAM ROCKET!\p"
    .string "On va te montrer à quel point on\n"
    .string "fait peur!$"

RadioTower1F_Text_GruntM3Beaten:
    .string "Trop fort! Pardon, patron…$"

RadioTower1F_Text_GruntM3After:
    .string "Tu es trop fort.\p"
    .string "Notre plan pourrait échouer. Je\n"
    .string "dois prévenir les autres…$"

RadioTower1F_Text_Directory:
    .string "1F ACCUEIL\n"
    .string "2F VENTES\p"
    .string "3F PERSONNEL\n"
    .string "4F PRODUCTION\p"
    .string "5F BUREAU DU DIRECTEUR$"

RadioTower1F_Text_GotRadio:
	.string "{PLAYER} obtient la CARTE RADIO\n"
	.string "pour le POKéMATOS!$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "Ici, c'est le COIN LOTO POKéMON.\p"
	.string "Si le numéro du TICKET LOTO\n"
	.string "correspond au numéro d'ID d'un de\l"
	.string "tes POKéMON, tu recevras un\l"
	.string "fabuleux cadeau.\p"
	.string "Veux-tu tirer un TICKET LOTO\n"
	.string "POKéMON?$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "Reviens demain, s'il te plaît.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "Reviens nous voir.$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "Choisis un TICKET LOTO.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "Le numéro du TICKET LOTO est\n"
	.string "{STR_VAR_1}.\p"
	.string "Je dois vérifier s'il correspond\n"
	.string "au numéro d'ID d'un de tes\l"
	.string "POKéMON. Un instant.$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "Félicitations!\p"
	.string "Le numéro d'ID du {STR_VAR_1} de\n"
	.string "ton équipe correspond à celui de\l"
	.string "ton TICKET LOTO!$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "Félicitations!\p"
	.string "Le numéro d'ID du {STR_VAR_1}\n"
	.string "rangé dans ton PC correspond à\l"
	.string "celui de ton TICKET LOTO!$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "Je suis désolée.\n"
	.string "Aucun numéro ne correspond.$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "Deux chiffres correspondent, tu\n"
	.string "gagnes le troisième prix!\l"
	.string "Tu remportes {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "Trois chiffres correspondent, tu\n"
	.string "gagnes le deuxième prix!\l"
	.string "Tu remportes {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "Quatre chiffres correspondent, tu\n"
	.string "gagnes le premier prix!\l"
	.string "Tu remportes {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "Oh, mon dieu, les cinq chiffres\n"
	.string "correspondent!\p"
	.string "Tu remportes le gros lot!\n"
	.string "Tu gagnes {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "Oh?\n"
	.string "Tu n'as pas de place pour ça.\p"
	.string "Fais de la place dans ton SAC et\n"
	.string "préviens-moi.$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{PLAYER}?\n"
	.string "Oui, je t'attendais.\p"
	.string "Voici le prix que nous gardions\n"
	.string "pour toi.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "Reviens nous voir.$"


