MahoganyTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "Quoi? La TEAM ROCKET est de\n"
    .string "retour?\p"
    .string "J'ai vu des hommes en noir au\n"
    .string "LAC COLÈRE…$"

MahoganyTown_PokemonCenter_Text_Youngster:
    .string "J'empêche mes POKéMON d'évoluer\n"
    .string "trop tôt.\p"
    .string "Je leur fais apprendre certaines\n"
    .string "capacités avant de les laisser\l"
    .string "évoluer.$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "Les POKéMON deviennent plus forts\n"
    .string "en évoluant,\p"
    .string "mais ils apprennent aussi les\n"
    .string "capacités plus lentement.$"
