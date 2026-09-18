Gate_EcruteakCity_Route42_hns_MapScripts::
	.byte 0

Gate_EcruteakCity_Route42_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route42_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route42_Text_EcruteakGateOfficer:
	.string "Le MONT CREUSET est un vrai\n"
	.string "labyrinthe à l'intérieur.\p"
	.string "Sois prudent. Ne t'y perds pas.$"

