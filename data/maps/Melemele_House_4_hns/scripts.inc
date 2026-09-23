Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "On est en vacances sur les ÎLES\n"
	.string "ALOLA!\p"
	.string "C'est comme la région d'ALOLA,\n"
	.string "mais plus près de KANTO!\p"
	.string "J'ai économisé un maximum sur le\n"
	.string "voyage!$"

Melemele_House4_Woman_Text_0:
	.string "Mon copain m'a dit qu'on allait à\n"
	.string "ALOLA…\p"
	.string "Je croyais qu'il parlait de la\n"
	.string "région d'ALOLA, pas des petites\l"
	.string "îles au large de KANTO.$"
