BlackthornCity_Mart_hns_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "Le RAPPEL MAX ne s'achète pas,\n"
	.string "mais il rétablit complètement un\l"
	.string "POKéMON K.O.\p"
	.string "Attention: il ne rend pas les PP,\n"
	.string "les POINTS DE POUVOIR des\l"
	.string "capacités.$"

BlackthornMart_Text_BlackBelt:
	.string "REPOUSSE MAX éloigne les POKéMON\n"
	.string "faibles.\p"
	.string "C'est le plus durable des sprays\n"
	.string "REPOUSSE.$"
