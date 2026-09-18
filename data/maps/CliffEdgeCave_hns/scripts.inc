CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "Quand un chemin se sépare dans\n"
	.string "une grotte, l'un mène au but et\l"
	.string "l'autre à une impasse.\p"
	.string "Mais on ne peut s'empêcher\n"
	.string "d'essayer les deux.$"
