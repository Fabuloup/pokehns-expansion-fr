FuchsiaCity_House2_hns_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "Mon pépé est le GARDE du PARC\n"
	.string "SAFARI.\p"
	.string "Enfin, il l'était…\p"
	.string "Il a décidé de partir en vacances\n"
	.string "et s'est envolé seul à l'étranger.\p"
	.string "Il a cessé de gérer le PARC\n"
	.string "SAFARI, comme ça.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "Beaucoup ont été déçus de la\n"
	.string "fermeture du PARC SAFARI, mais\l"
	.string "Pépé est si têtu…$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "Une photo d'un vieil homme\n"
	.string "hilare entouré de POKéMON.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "Une photo d'une vaste plaine\n"
	.string "herbeuse où gambadent des POKéMON\l"
	.string "rares.$"
