PewterCity_Museum_2F_hns_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "On dit que des météorites ont\n"
	.string "frappé l'ÎLE NAISSANCE.\p"
	.string "Nous aimerions les exposer ici,\n"
	.string "dans notre musée, mais…\p"
	.string "Ces météorites émettraient une\n"
	.string "étrange énergie et ne peuvent\l"
	.string "être déplacées…$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "Je veux un PIKACHU!\n"
    .string "Il est trop mignon!\p"
    .string "J'ai demandé à mon papa de m'en\n"
    .string "attraper un!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "Oui, un PIKACHU bientôt, promis!$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "Navette spatiale$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "Une météorite tombée sur le MONT\n"
    .string "SÉLÉNITE. On pense que c'est une\l"
    .string "PIERRE LUNE.$"
