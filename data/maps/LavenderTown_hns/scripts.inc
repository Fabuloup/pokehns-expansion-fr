LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "Sacré bâtiment, pas vrai?\p"
	.string "C'est la TOUR RADIO de KANTO.$"

LavenderTown_Text_Teacher:
	.string "KANTO a plein de bonnes émissions\n"
	.string "de radio.$"

LavenderTown_Text_Gramps:
	.string "Les gens viennent de partout\n"
	.string "pour se recueillir sur les âmes\l"
	.string "des POKéMON disparus.$"

LavenderTown_Text_Youngster:
	.string "Il faut une POKÉ FLÛTE pour\n"
	.string "réveiller un POKéMON endormi.\p"
	.string "Tout DRESSEUR doit savoir ça!$"

LavenderTown_Text_Sign:
	.string "LAVANVILLE\p"
	.string "La noble ville mauve$"

LavenderTown_Text_KantoRadioStationSign:
	.string "STATION RADIO DE KANTO\p"
	.string "Vos émissions préférées\n"
	.string "à l'antenne jour et nuit!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "MAISON DES BÉNÉVOLES POKéMON\n"
	.string "DE LAVANVILLE$"

LavenderTown_Text_SoulHouseSign:
	.string "MAISON DES ÂMES\p"
	.string "Que les âmes des POKéMON\n"
	.string "reposent en paix$"
