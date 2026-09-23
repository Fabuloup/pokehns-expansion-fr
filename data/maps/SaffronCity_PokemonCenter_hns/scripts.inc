SaffronCity_PokemonCenter_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY_HNS
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "Comment sont les CENTRES POKéMON\n"
	.string "de JOHTO?\p"
	.string "…Ah, je vois. Ils ne sont donc\n"
	.string "pas si différents de ceux de\l"
	.string "KANTO.\p"
	.string "Je peux aller à JOHTO sans\n"
	.string "m'inquiéter, alors!$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "Je viens de passer par le TUNNEL\n"
	.string "ROCHEUX.\p"
	.string "Il y avait de l'agitation à la\n"
	.string "CENTRALE.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "Il y a une grotte étrange à\n"
	.string "AZURIA.\p"
	.string "En MONTAGNARD chevronné, je\n"
	.string "devrais l'explorer, mais cet\l"
	.string "endroit me fait peur, à moi aussi.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "Le SIÈGE de la SYLPHE SARL et la\n"
	.string "GARE DU TRAIN MAGNÉTIQUE: voilà\l"
	.string "ce qu'il faut voir à SAFRANIA.$"
