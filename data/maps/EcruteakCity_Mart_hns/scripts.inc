EcruteakCity_Mart_hns_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "Mon ÉVOLI a évolué en MENTALI.\p"
	.string "Mais l'ÉVOLI de mon ami est\n"
	.string "devenu un NOCTALI.\p"
	.string "Pourquoi donc? On les élevait\n"
	.string "pourtant de la même façon…$"

EcruteakMart_Text_Granny:
	.string "Avec un RAPPEL, un POKéMON K.O.\n"
	.string "se réveille aussitôt.$"
