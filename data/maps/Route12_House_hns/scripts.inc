Route12_House_hns_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "Je suis le petit frère du GOUROU\n"
	.string "DE LA PÊCHE.\p"
	.string "Je vois bien que tu aimes pêcher.\p"
	.string "Je n'en doute pas un seul\n"
	.string "instant!\p"
	.string "Alors? Je sais que j'ai raison.$"

Route12_House_Text_GiveSuperRod:
	.string "Oui, oui. Comme je le pensais!\p"
	.string "Tiens, amateur de pêche! Prends\n"
	.string "ceci: une MÉGA CANNE.$"

Route12_House_Text_GaveSuperRod:
	.string "Essaie de pêcher partout où il y\n"
	.string "a de l'eau.\p"
	.string "Retiens bien: chaque CANNE permet\n"
	.string "d'attraper des POKéMON différents.$"

Route12_House_Text_DontWantSuperRod:
	.string "Hein? Mes yeux m'ont trompé?$"

