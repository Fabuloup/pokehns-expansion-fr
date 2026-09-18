GoldenrodCity_House2_hns_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "Un jour, en plein combat, mon\n"
    .string "POKéMON ne pouvait plus attaquer.\p"
    .string "Les POINTS DE POUVOIR, ou PP, de\n"
    .string "ses capacités étaient épuisés.$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "Parfois, un POKéMON en pleine\n"
    .string "forme ne peut plus attaquer.\p"
    .string "Dans ce cas, soigne-le au CENTRE\n"
    .string "POKéMON ou utilise un objet.$"
