AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "Tes POKéMON connaissent-ils des\n"
	.string "capacités de CS?\p"
	.string "On peut les utiliser même si le\n"
	.string "POKéMON est K.O.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "Ce dénommé LEO a créé le système\n"
	.string "de stockage des POKéMON sur PC.\p"
	.string "Le PC de LEO peut stocker jusqu'à\n"
	.string "30 POKéMON par BOÎTE.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "Le PC de LEO peut stocker jusqu'à\n"
	.string "30 POKéMON par BOÎTE.$"

AzaleaPokecenter_Text_PokefanF:
	.string "Tu connais les BAIES?\p"
	.string "On en fend une, on la vide, puis\n"
	.string "on y place un dispositif spécial.\p"
	.string "On peut alors attraper des\n"
	.string "POKéMON avec.\p"
	.string "Avant l'invention des POKé BALL,\n"
	.string "tout le monde utilisait ça.$"
