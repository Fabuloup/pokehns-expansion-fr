LavenderTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN_HNS
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "Au nord de LAVANVILLE se trouve\n"
	.string "le TUNNEL ROCHEUX. Traverse-le\l"
	.string "pour atteindre la CENTRALE.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "Il y a une émission qui passe la\n"
	.string "musique de la POKÉ FLÛTE.\p"
	.string "Oh? Ah, il faut une EXTENSION\n"
	.string "RADIO pour la capter.\p"
	.string "La STATION RADIO de la ville\n"
	.string "pourrait peut-être t'en fournir\l"
	.string "une?$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "Si la CENTRALE ne tourne pas, le\n"
	.string "TRAIN MAGNÉTIQUE non plus…\p"
	.string "Et la STATION RADIO ne peut plus\n"
	.string "émettre…$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "Le DIRECTEUR de la STATION RADIO\n"
	.string "était bien content.\p"
	.string "Il a dit qu'ils réémettent, car\n"
	.string "la CENTRALE tourne de nouveau\l"
	.string "normalement.$"
