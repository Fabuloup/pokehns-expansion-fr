PalletTown_RedsHouse_1F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "Bonjour!\p"
	.string "RED est parti depuis longtemps.\p"
	.string "Il n'a pas appelé non plus, alors\n"
	.string "j'ignore où il est et ce qu'il\l"
	.string "fabrique.\p"
	.string "On dit que pas de nouvelles,\n"
	.string "bonnes nouvelles, mais je\l"
	.string "m'inquiète pour lui.$"

RedsHouse_Text_Mom2:
	.string "J'ai peur que RED se blesse ou\n"
	.string "tombe malade, mais c'est un\l"
	.string "garçon.\p"
	.string "Je suis fière qu'il fasse ce\n"
	.string "qu'il veut faire.$"

RedsHouse_Text_TV:
	.string "Il y a des émissions qu'on ne\n"
	.string "voit pas à JOHTO…$"
