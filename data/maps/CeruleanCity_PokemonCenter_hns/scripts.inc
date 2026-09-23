CeruleanCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY_HNS
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "Pour combattre, je préfère de\n"
	.string "loin les POKéMON que j'ai élevés,\p"
	.string "même s'ils sont plus faibles que\n"
	.string "des POKéMON tout juste attrapés.$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "Le TRAIN MAGNÉTIQUE roule à plus\n"
	.string "de 550 km/h. Il relie KANTO et\l"
	.string "JOHTO en un rien de temps.\p"
	.string "JOHTO en devient vraiment\n"
	.string "accessible.$"
