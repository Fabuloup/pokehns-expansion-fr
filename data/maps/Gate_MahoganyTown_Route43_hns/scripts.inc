Gate_MahoganyTown_Route43_hns_MapScripts::
	.byte 0

Gate_MahoganyTown_Route43_EventScript_Cop::
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, Gate_MahoganyTown_Route43_EventScript_CopAfter
	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_NPC
	end

Gate_MahoganyTown_Route43_EventScript_CopAfter::
	msgbox Route43MahoganyGate_Text_Officer_RocketsCleared, MSGBOX_NPC
	end

Route43MahoganyGate_Text_Officer:
    .string "Ces temps-ci, seuls ceux qui\n"
    .string "montent au LAC COLÈRE passent\l"
    .string "par ici.$"

Route43MahoganyGate_Text_Officer_RocketsCleared:
    .string "Plus personne ne monte au LAC\n"
    .string "COLÈRE ces jours-ci.$"

