ViridianCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY_HNS
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "Où peut bien être le CHAMPION de\n"
	.string "JADIELLE? Je voulais le défier.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "Il n'y a aucun Dresseur à l'ARÈNE\n"
	.string "de JADIELLE.\p"
	.string "Le CHAMPION dit vouloir gagner\n"
	.string "sans avoir de subalternes.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "Il paraît que l'ARÈNE de\n"
	.string "CRAMOIS'ÎLE a disparu.\p"
	.string "Je me demande ce qu'est devenu\n"
	.string "AUGUSTE, le CHAMPION.$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "Mon rêve est de devenir CHAMPION\n"
	.string "d'ARÈNE.$"
