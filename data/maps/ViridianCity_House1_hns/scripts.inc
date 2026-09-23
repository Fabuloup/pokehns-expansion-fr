ViridianCity_House1_hns_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "Tu réfléchis beaucoup aux noms de\n"
	.string "tes POKéMON?\p"
	.string "De bons surnoms rendent les\n"
	.string "échanges encore plus amusants.$"

ViridianCity_House1_Text_Lass:
	.string "Voici PIAFOU, un PIAFABEC, et\n"
	.string "RATOU, un RATTATA.$"

ViridianCity_House1_Text_Speary:
	.string "PIAFOU: Ch-chun!$"

ViridianCity_House1_Text_Rattey:
	.string "RATOU: Kikiii!$"

