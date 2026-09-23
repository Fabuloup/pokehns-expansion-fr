EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "C'est arrivé quand j'étais jeune.\p"
	.string "Le ciel est devenu noir d'un\n"
	.string "coup. Un POKéMON volant géant\l"
	.string "masquait le soleil.\p"
	.string "Quel POKéMON était-ce donc?\p"
	.string "On aurait dit un oiseau et un\n"
	.string "dragon à la fois.$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "Un POKéMON aussi grand existe\n"
	.string "vraiment?\p"
	.string "S'il existe, il doit être\n"
	.string "puissant.$"
