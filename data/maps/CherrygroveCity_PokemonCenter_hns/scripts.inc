CherrygroveCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGrove_Pokecenter_OnTransition
	.byte 0

CherryGrove_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	end

CherryGrove_Pokecenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_Chansey::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox CherryGrove_Pokecenter_Text_Chansey, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	closemessage
	end

CherryGrove_Pokecenter_Text_Fisher:
	.string "Super! Je peux stocker autant\n"
	.string "de POKéMON que je veux.\l"
	.string "Et c'est gratuit.$"

CherryGrove_Pokecenter_Text_Gentleman:
	.string "Ce PC est en libre-service pour\n"
	.string "tous les Dresseurs.$"

CherryGrove_Pokecenter_Text_Lass:
	.string "On dit que plus on attend, plus le\n"
	.string "temps paraît long. Mais devant\l"
	.string "l'horloge du CENTRE POKéMON,\l"
	.string "il file!$"

CherryGrove_Pokecenter_Text_Chansey:
	.string "LEVEINARD: Leveeei!$"
