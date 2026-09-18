Route7_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "Qu'est-ce que ce tract?\p"
	.string "… Des Dresseurs mal élevés\n"
	.string "organisent des combats dans le\l"
	.string "SOUTERRAIN.\p"
	.string "Devant les plaintes croissantes\n"
	.string "des riverains, le SOUTERRAIN est\l"
	.string "fermé pour une durée indéterminée.\p"
	.string "POLICE DE CÉLADOPOLE$"

Route7_Text_LockedDoor:
	.string "C'est fermé à clé…$"

