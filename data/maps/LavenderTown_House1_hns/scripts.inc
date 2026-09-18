LavenderTown_House1_hns_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "Tu te rends compte?\p"
	.string "Certains se lassent de s'occuper\n"
	.string "de leurs POKéMON.\p"
	.string "Pépé recueille ces pauvres\n"
	.string "POKéMON sans foyer et les soigne.$"
LavenderTown_House1_Text_Guy:
	.string "M. FUJI vit bien ici, mais il est\n"
	.string "absent. Il doit être à la MAISON\l"
	.string "DES ÂMES.$"
LavenderTown_House1_Text_Marowak:
	.string ".............................$"

LavenderTown_House1_Text_Marowak2:
	.string "L'OSSATUEUR est silencieux, mais\n"
	.string "il a l'air bien heureux.$"

