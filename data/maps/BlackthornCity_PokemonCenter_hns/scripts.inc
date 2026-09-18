BlackthornCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "Au fond du lointain PLATEAU\n"
	.string "INDIGO se trouve la LIGUE\l"
	.string "POKéMON.\p"
	.string "On dit que les meilleurs\n"
	.string "Dresseurs du pays s'y réunissent.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "Il y avait une capacité que je\n"
	.string "voulais absolument apprendre à\l"
	.string "mon POKéMON.\p"
	.string "L'EFFACEUR lui a donc fait\n"
	.string "oublier une capacité de CS.$"
