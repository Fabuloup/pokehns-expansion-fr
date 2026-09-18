Gate_EcruteakCity_Route38_hns_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "D'où viens-tu, déjà?\p"
	.string "BOURG GEON?\p"
	.string "C'est bien là que vit le\n"
	.string "PROF. ORME, non?\p"
	.string "Tu as fait un sacré chemin pour\n"
	.string "arriver ici.$"
