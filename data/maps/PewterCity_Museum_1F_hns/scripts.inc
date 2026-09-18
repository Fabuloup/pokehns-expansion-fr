PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "Bienvenue!\p"
	.string "Sache que tous les grands\n"
	.string "spécimens ont été envoyés aux\l"
	.string "autres musées pour exposition.\p"
	.string "Du coup, l'entrée est gratuite\n"
	.string "pour le moment!\p"
	.string "Je t'en prie, entre.$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "Tu dois être un DRESSEUR fort.\p"
	.string "Les fossiles sur le comptoir\n"
	.string "là-bas ne nous servent à rien.\p"
	.string "Un homme étrange aux cheveux\n"
	.string "argentés en a déposé une tonne.\p"
	.string "Prends-les si le cœur t'en dit.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "Nous partageons souvent nos\n"
	.string "recherches avec les chercheurs\l"
	.string "des RUINES D'ALPHA.\p"
	.string "On échange même des fossiles\n"
	.string "avec eux par le PC!$"

PewterCity_Museum_1F_Text_Oldman:
	.string "Je devrais être reconnaissant\n"
	.string "d'avoir vécu si longtemps.\p"
	.string "Je n'aurais jamais cru voir les\n"
	.string "os d'un dragon!$"

PewterCity_Museum_1F_Text_Bones:
	.string "Ossements d'un ancien POKéMON\n"
	.string "dragon.$"
