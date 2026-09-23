CherrygroveCity_House3_hns_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "Les POKéMON gagnent de\n"
	.string "l'expérience au combat et changent\l"
	.string "de forme.$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "Les POKéMON changent?\p"
	.string "J'aimerais vraiment voir ça!$"
