Route2_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_RobRegister:
	.string "Donne-moi ton numéro!$"

Route2_Text_RobRematchIntro:
	.string "J'ai attrapé encore plus\n"
	.string "d'insectes! Regarde-les!$"

Route2_Text_RobRematchDefeat:
	.string "Il me faut de meilleurs\n"
	.string "insectes!$"

Route2_Text_RobPostRematch:
	.string "J'ai attrapé tous les insectes\n"
	.string "de JADIELLE. Y a-t-il une\l"
	.string "meilleure FORÊT ailleurs?$"

Route2_Text_BugCatcherRob_Seen:
	.string "Mes POKéMON Insecte sont\n"
	.string "coriaces. Prépare-toi à perdre!$"

Route2_Text_BugCatcherRob_Beaten:
	.string "J'ai été balayé…$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "Je vais chercher des POKéMON\n"
	.string "Insecte plus forts.$"

Route2_Text_BugCatcherEd_Seen:
	.string "Si tu marches dans les hautes\n"
	.string "herbes en short, tu te fais des\l"
	.string "égratignures?$"

Route2_Text_BugCatcherEd_Beaten:
	.string "Aïe, aïe, aïe!$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "Ça pique vraiment quand tu\n"
	.string "prends ton bain.$"

Route2_Text_BugCatcherDoug_Seen:
	.string "Pourquoi les filles n'aiment\n"
	.string "pas les POKéMON Insecte?$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "Pas terrible!$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "Les POKéMON Insecte font comme\n"
	.string "des peluches quand on presse\l"
	.string "leur ventre.\p"
	.string "J'adore cette sensation!$"

Route2_Text_Sign:
	.string "ROUTE 2\p"
	.string "JADIELLE - ARGENTA$"

Route2_Text_DiglettsCaveSign:
	.string "GROTTE TAUPIQUEUR$"

