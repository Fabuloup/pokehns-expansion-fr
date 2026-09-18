CianwoodHouse2_hns_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "Tu viens d'OLIVILLE?\p"
	.string "Tu te souviens des quatre îles\n"
	.string "sur le chemin?\p"
	.string "On raconte qu'une créature marine\n"
	.string "mythique s'y cache.$"

CianwoodCity_Text_LugiaHouseLass:
	.string "Il paraît qu'on ne peut la voir\n"
	.string "qu'avec une ARGENT'AILE.\p"
	.string "Elle doit avoir la même odeur\n"
	.string "que la créature.$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "On dit que les tourbillons autour\n"
	.string "des îles sont causés par la\l"
	.string "créature marine.\p"
	.string "Il te faudra sans doute une\n"
	.string "capacité spéciale pour passer.$"
