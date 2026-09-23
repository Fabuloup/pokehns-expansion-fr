FuchsiaCity_Mart_hns_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_Fisher::
	msgbox FuchsiaMart_Text_Fisher, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Woman::
	msgbox FuchsiaMart_Text_CooltrainerF, MSGBOX_NPC
	end

FuchsiaMart_Text_Fisher:
	.string "L'ancien PARC SAFARI avait de\n"
	.string "bien meilleurs souvenirs…$"

FuchsiaMart_Text_CooltrainerF:
	.string "La petite-fille de l'ancien GARDE\n"
	.string "du PARC SAFARI vit en ville.$"
