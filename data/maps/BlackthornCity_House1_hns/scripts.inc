BlackthornCity_House1_hns_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "Un clan de Dresseurs capables de\n"
	.string "commander aux dragons vit ici\l"
	.string "même, à EBENELLE.\p"
	.string "D'où les nombreuses légendes de\n"
	.string "dragons dans cette ville.$"

BlackthornCity_House1_Text_Dratini:
	.string "MINIDRAKO: Draa!$"
