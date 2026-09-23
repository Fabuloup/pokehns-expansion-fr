Route40_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON_HNS, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "Il faut s'échauffer avant\n"
	.string "d'entrer dans l'eau.\p"
	.string "C'est la base.$"

Route40_Text_SwimmermSimonBeaten:
	.string "OK! Pitié! J'abandonne!$"

Route40_Text_SwimmermSimonAfter:
	.string "IRISIA est encore assez\n"
	.string "loin d'ici.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "Hé, tu es jeune et en forme!\p"
	.string "Ne monte pas sur ton POKéMON!\n"
	.string "Nage!$"

Route40_Text_SwimmermRandallBeaten:
	.string "Oh oh. J'ai perdu…$"

Route40_Text_SwimmermRandallAfter:
	.string "La natation fait travailler\n"
	.string "tout le corps. C'est bon.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "Tu vas à IRISIA?\p"
	.string "Un petit combat rapide\n"
	.string "avant?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "J'ai perdu celui-là!$"

Route40_Text_SwimmerfElaineAfter:
	.string "Je nage mieux que toi,\n"
	.string "ça oui!$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "Pas de bouée pour moi.\p"
	.string "Je m'accroche à un POKéMON\n"
	.string "marin!$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "Oh, j'ai la tête qui tourne!$"

Route40_Text_SwimmerfPaulaAfter:
	.string "Quand je flotte ainsi,\n"
	.string "les vagues m'emportent.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Même si on ne la voit pas d'ici,\n"
	.string "IRISIA est de l'autre côté.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Je suis venue à OLIVILLE en bateau\n"
	.string "pour visiter et profiter de\l"
	.string "l'ambiance.\p"
	.string "Ce port est si différent\n"
	.string "d'une grande ville.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "Tu es allé à la COLLINE\n"
	.string "DRESSEURS?\p"
	.string "Beaucoup de Dresseurs coriaces\n"
	.string "doivent déjà s'y trouver.\p"
	.string "Mais avec tous tes BADGES,\n"
	.string "tu devrais bien t'en sortir.$"

Route40_Text_Monica:
	.string "MONICA: Enchantée.\n"
	.string "Je suis MONICA de la famille JOUR.\p"
	.string "Tu ne devineras jamais mon jour\n"
	.string "préféré de la semaine!$"

Route40_Text_MonicaGivesGift:
	.string "Exact!\p"
	.string "Pour célébrer notre amitié,\n"
	.string "j'ai un cadeau pour toi!$"

Route40_Text_MonicaGaveGift:
	.string "MONICA: Cet objet renforce\n"
	.string "les capacités de type VOL.\p"
	.string "Tu devrais le donner à un\n"
	.string "POKéMON oiseau.$"

Route40_Text_MonicaMonday:
	.string "MONICA: Mes frères et sœurs\n"
	.string "sont dispersés un peu partout.\p"
	.string "Essaie donc de tous\n"
	.string "les trouver!$"

Route40_Text_MonicaNotMonday:
	.string "MONICA: Je ne crois pas que nous\n"
	.string "soyons lundi. Quel dommage…$"

Route40_Text_MonicaNope:
	.string "Ce n'est pas ça.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
