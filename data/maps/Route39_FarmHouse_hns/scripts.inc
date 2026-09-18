Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "Mon ÉCRÉMEUH ne donne plus rien.\p"
	.string "Cette FERME a un lait célèbre.\p"
	.string "Tout le monde veut y goûter.\p"
	.string "Il donnera plein de lait si je\n"
	.string "lui donne beaucoup de BAIES,\l"
	.string "j'imagine.$"

Route39_Text_FarmerMBuyMilk:
	.string "Que dis-tu de mon LAIT MEUMEU?\p"
	.string "C'est ma grande fierté.\p"
	.string "Il restaure les PV des POKéMON!\p"
	.string "Je te le vends pour seulement\n"
	.string "500¥.$"

Route39_Text_FarmerMGotMilk:
	.string "Et voilà!\n"
	.string "Bois-le et régale-toi!$"

Route39_Text_FarmerMNoMoney:
	.string "Désolé.\n"
	.string "Pas d'argent, pas de vente!$"

Route39_Text_FarmerMNoRoom:
	.string "Ton SAC semble plein.$"

Route39_Text_FarmerMNoSale:
	.string "Tu n'en veux pas?\n"
	.string "Reviens nous voir!$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "Tu en veux un autre?$"

Route39_Text_GotMilk:
	.string "{PLAYER} obtient du LAIT MEUMEU.$"

Route39_Text_FarmerMMilking:
	.string "Je dois retourner à la traite.$"

Route39_Text_FarmerFInTrouble:
	.string "Notre lait est même livré à\n"
	.string "KANTO.\p"
	.string "Alors si notre ÉCRÉMEUH ne donne\n"
	.string "plus de lait, on est mal.$"

Route39_Text_FarmerFHealedMiltank:
	.string "Tu as soigné notre ÉCRÉMEUH.\n"
	.string "Il donne à nouveau du LAIT MEUMEU.\p"
	.string "Voici quelque chose pour ta peine.$"

Route39_Text_FarmerFSnatchSpeech:
	.string "C'est la capacité SAISIE.\p"
	.string "Elle permet à un POKéMON de voler\n"
	.string "la capacité adverse juste avant\l"
	.string "son utilisation.\p"
	.string "Si plusieurs POKéMON utilisent\n"
	.string "SAISIE, seul le plus lent finira\l"
	.string "par voler la capacité.\p"
	.string "Utilise-la bien. Le timing fait\n"
	.string "tout.$"
