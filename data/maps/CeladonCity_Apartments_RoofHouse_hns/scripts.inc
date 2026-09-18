CeladonCity_Apartments_RoofHouse_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_SLEEP_TALK, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_SLEEP_TALK
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "Écoute cette histoire terrifiante…$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "Mais tout compte fait, elle fait\n"
	.string "moins peur en plein jour.\p"
	.string "Reviens après le coucher\n"
	.string "du soleil, d'accord?$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "Il était une fois un garçon qui\n"
	.string "avait reçu une BICYCLETTE neuve…\p"
	.string "Il voulut l'essayer aussitôt…\p"
	.string "Il s'amusait tellement qu'il ne\n"
	.string "vit pas le soleil se coucher…\p"
	.string "Sur le chemin du retour, dans la\n"
	.string "nuit noire, son vélo ralentit\l"
	.string "soudain!\p"
	.string "Les pédales devinrent lourdes!\p"
	.string "Quand il cessa de pédaler, le vélo\n"
	.string "se mit à reculer!\p"
	.string "Comme si le vélo était maudit\n"
	.string "et voulait l'entraîner vers\l"
	.string "les ténèbres!\p"
	.string "…\p"
	.string "…\p"
	.string "SHRIEEEEK!\p"
	.string "Le garçon montait la PISTE\n"
	.string "CYCLABLE!\p"
	.string "…\n"
	.string "Badam badam!\p"
	.string "Pour m'avoir écouté patiemment,\n"
	.string "prends cette CT82!$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "La CT82 contient BLABLA DODO.\p"
	.string "Elle permet à ton POKéMON\n"
	.string "d'utiliser une capacité au hasard\l"
	.string "pendant son sommeil.\p"
	.string "Mais bonne chance pour dormir\n"
	.string "après cette histoire terrifiante!$"
