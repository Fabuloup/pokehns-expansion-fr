CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "Tu veux évaluer ton niveau de\n"
	.string "Dresseur POKéMON?\p"
	.string "Tu devrais visiter les ARÈNES de\n"
	.string "JOHTO et collectionner les\l"
	.string "BADGES.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "Quand je serai grand, je serai\n"
	.string "CHAMPION d'ARÈNE!\p"
	.string "Je fais combattre mes POKéMON\n"
	.string "contre ceux de mon ami pour les\l"
	.string "rendre plus forts!$"
