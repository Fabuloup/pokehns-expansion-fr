PalletTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "J'élève aussi des POKéMON.\p"
	.string "Ils me servent de gardes du\n"
	.string "corps.$"

PalletTown_Text_Fisher:
	.string "La technologie, c'est\n"
	.string "incroyable!\p"
	.string "On échange maintenant des POKéMON\n"
	.string "à travers le temps, comme un\l"
	.string "e-mail.$"

PalletTown_Text_Sign:
	.string "BOURG PALETTE\p"
	.string "Calme, paix et pureté$"

PalletTown_Text_RedsHouseSign:
	.string "CHEZ RED$"

PalletTown_Text_OaksLabSign:
	.string "LABO POKéMON\n"
	.string "de CHEN$"

PalletTown_Text_BluesHouseSign:
	.string "CHEZ BLUE$"
