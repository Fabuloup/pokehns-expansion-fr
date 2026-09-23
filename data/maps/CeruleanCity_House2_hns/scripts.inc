CeruleanCity_House2_hns_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "Il paraît qu'un individu louche\n"
	.string "rôde dans le coin.\p"
	.string "S'il s'avère que c'est un voleur,\n"
	.string "je ne le tolérerai pas.$"

CeruleanPolice_Text_PokefanF:
	.string "On a déjà été braqués par des\n"
	.string "voleurs.$"

CeruleanPolice_Text_Diglett:
	.string "TAUPIQUEUR: Taup taup.$"
