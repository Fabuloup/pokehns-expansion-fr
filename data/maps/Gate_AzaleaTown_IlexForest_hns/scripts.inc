Gate_AzaleaTown_IlexForest_hns_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "Le BOIS AUX CHÊNES est grand.\n"
	.string "Sois prudent!\l"
	.string "Ne te perds pas.$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "Le BOIS AUX CHÊNES est veillé\n"
	.string "par son protecteur.\p"
	.string "Alors pas de bêtises!$"
