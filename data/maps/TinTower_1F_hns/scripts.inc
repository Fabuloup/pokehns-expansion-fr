TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "Selon la légende…\n"
	.string "Quand les âmes des POKéMON et des humains\p"
	.string "communient, un POKéMON aux couleurs\n"
	.string "de l'arc-en-ciel descend des cieux…\p"
	.string "Les POKéMON légendaires nous\n"
	.string "mettraient-ils à l'épreuve ?$"

TinTower_1F_Sage2_Text:
	.string "Quand la TOUR CENDRÉE a brûlé,\n"
	.string "trois POKéMON inconnus auraient\l"
	.string "péri. C'était tragique.\p"
	.string "Cependant…\p"
	.string "Un POKéMON aux couleurs de l'arc-en-ciel…\n"
	.string "Autrement dit…\p"
	.string "HO-OH est descendu du ciel et a\n"
	.string "rendu la vie aux trois POKéMON.\p"
	.string "Ce sont…\n"
	.string "SUICUNE, ENTEI et RAIKOU.\p"
	.string "C'est ce qu'on raconte.$"

TinTower_1F_Sage3_Text:
	.string "Les deux TOURS auraient été bâties\n"
	.string "pour encourager l'amitié et\p"
	.string "l'espoir entre humains et POKéMON.\n"
	.string "C'était il y a 700 ans, mais cet idéal\p"
	.string "reste important aujourd'hui.$"

TinTower_1F_Sage4_Text1:
	.string "HO-OH semble être descendu sur\n"
	.string "cette TOUR FERRAILLE !$"

TinTower_1F_Sage4_Text2:
	.string "Les POKéMON légendaires incarneraient\n"
	.string "trois puissances…\p"
	.string "La foudre qui frappa la TOUR.\n"
	.string "Le feu qui brûla la TOUR.\p"
	.string "Et la pluie qui éteignit le feu…$"

TinTower_1F_Sage6_Text2:
	.string "Parmi les POKéMON légendaires, SUICUNE\n"
	.string "serait le plus proche de HO-OH.\p"
	.string "On dit qu'il serait aussi lié aux\n"
	.string "POKéMON appelés ZARBI.\p"
	.string "Les ZARBI doivent partager un lien\n"
	.string "de coopération avec SUICUNE.$"

TinTower_1F_EusineHoOh_Text:
	.string "Je le savais.\p"
	.string "Je savais que tu verrais le POKéMON\n"
	.string "aux couleurs de l'arc-en-ciel, <PLAYER>.\p"
	.string "Tout s'est passé comme je l'imaginais.\n"
	.string "Mes recherches ne sont pas mauvaises.\p"
	.string "Je vais continuer d'étudier les POKéMON\n"
	.string "pour devenir un POKéMANIAQUE célèbre !$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE : Incroyable ! Trop incroyable !\n"
	.string "Je n'ai jamais vu un tel combat.\p"
	.string "C'était vraiment inspirant.\n"
	.string "SUICUNE était puissant, mais tu étais\p"
	.string "encore plus incroyable, <PLAYER>.\n"
	.string "J'ai entendu dire que le pouvoir mystique\p"
	.string "de SUICUNE invoque un POKéMON arc-en-ciel.\n"
	.string "Peut-être que ce qui s'est passé aujourd'hui\p"
	.string "fera apparaître ce POKéMON.\n"
	.string "Je vais étudier les légendes davantage.\p"
	.string "Merci de m'avoir montré ce combat\n"
	.string "fantastique.\p"
	.string "À plus tard, <PLAYER> !$"
