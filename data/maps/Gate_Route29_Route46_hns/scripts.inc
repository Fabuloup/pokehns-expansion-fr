Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "On ne peut pas escalader les\n"
	.string "rebords.\p"
	.string "Mais on peut sauter en bas pour\n"
	.string "prendre un raccourci.$"

Gate_Route29_Route46_Text_Youngster:
	.string "D'autres espèces de POKéMON\n"
	.string "apparaissent au-delà.\p"
	.string "Si tu veux tous les attraper, il\n"
	.string "faut chercher partout.$"
