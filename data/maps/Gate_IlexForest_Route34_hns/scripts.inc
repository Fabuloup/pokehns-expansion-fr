Gate_IlexForest_Route34_hns_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_Lass::
	lock
	faceplayer
	msgbox Route34IlexForestGate_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_Lass:
	.string "Tu as vu l'AUTEL dédié au\n"
	.string "protecteur?\p"
	.string "Il veille sur la FORÊT à travers\n"
	.string "le temps.\p"
	.string "Je crois que ce doit être un\n"
	.string "POKéMON de type PLANTE.$"

Route34IlexForestGate_Text_Butterfree:
	.string "PAPILUSION: Papiii!$"
