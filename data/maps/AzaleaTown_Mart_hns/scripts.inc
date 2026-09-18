AzaleaTown_Mart_hns_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "Tu peux acheter des SUPER BALL?\n"
	.string "Moi, je n'ai droit qu'aux\l"
	.string "POKé BALL.\p"
	.string "Il paraît qu'on débloque plus\n"
	.string "d'objets à mesure qu'on gagne\l"
	.string "des BADGES d'ARÈNE!\p"
	.string "J'aimerais bien que FARGAS me\n"
	.string "fabrique une de ses BALL.$"

AzaleaMart_Text_BugCatcher:
	.string "Une SUPER BALL attrape mieux les\n"
	.string "POKéMON qu'une POKé BALL.\p"
	.string "Mais parfois, celles de FARGAS\n"
	.string "sont encore meilleures.$"

