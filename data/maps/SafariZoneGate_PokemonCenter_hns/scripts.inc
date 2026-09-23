SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Ceux qui viennent au CENTRE\n"
	.string "POKéMON prennent souvent grand\l"
	.string "soin de leurs POKéMON.\p"
	.string "Tu ne trouves pas?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "Après une longue marche en\n"
	.string "montagne pour trouver un CENTRE\l"
	.string "POKéMON, quand on est au bout du\l"
	.string "rouleau…\p"
	.string "On se croirait au paradis!$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Safari, safari, c'est tellement\n"
	.string "chouette. Safari, safari, c'est\l"
	.string "passionnant, hein!\p"
	.string "Tant de POKéMON nous attendent!\p"
	.string "…C'est une chanson de moi.\n"
	.string "Je la chante au PARC SAFARI.$"
