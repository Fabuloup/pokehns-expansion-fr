NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "Bonjour, {PLAYER}! Mon mari est\n"
	.string "toujours débordé.\l"
	.string "J'espère qu'il va bien.\p"
	.string "Quand il se plonge dans ses\n"
	.string "recherches sur les POKéMON,\l"
	.string "il oublie même de manger.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "Quand je serai grand, j'aiderai\n"
	.string "mon papa!\p"
	.string "Je deviendrai un grand\n"
	.string "PROFESSEUR POKéMON!$"
