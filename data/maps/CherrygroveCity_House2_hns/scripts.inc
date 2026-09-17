CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "Quand j'étais gamin, j'étais un\n"
	.string "sacré Dresseur!\p"
	.string "Un petit conseil:\n"
	.string "attrape beaucoup de POKéMON!\p"
	.string "Traite-les toujours avec bonté!$"
