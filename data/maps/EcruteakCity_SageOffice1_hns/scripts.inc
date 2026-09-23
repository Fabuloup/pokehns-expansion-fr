EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "La cloche d'étain résonne pour\n"
	.string "ceux que la tour protège.$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "La TOUR FERRAILLE est interdite\n"
	.string "aux indignes. Navré, mais vous\l"
	.string "devez partir.$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "La TOUR FERRAILLE est interdite\n"
	.string "sans le BADGE de ROSALIA.\p"
	.string "Ah!\p"
	.string "Le BADGE de ROSALIA! Je vous en\n"
	.string "prie, passez.$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "Un événement capital a eu lieu.\p"
	.string "Pardonnez-moi, mais je dois vous\n"
	.string "demander de partir.\p"
	.string "…Ce qui apaise l'âme…\p"
	.string "Les TROIS SAGES tiennent des\n"
	.string "propos bien difficiles à saisir…$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "Un événement capital a eu lieu.\p"
	.string "Pardonnez-moi, mais je dois vous\n"
	.string "demander de partir.\p"
	.string "..............................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "Ah!\p"
	.string "Le son de cette GLAS TRANSPARENT!\p"
	.string "C'est… C'est sublime!\p"
	.string "Jamais je n'avais entendu un son\n"
	.string "aussi beau!\p"
	.string "Ce carillon révèle la nature de\n"
	.string "l'âme de son porteur.\p"
	.string "You…\p"
	.string "Vous pourrez peut-être gravir la\n"
	.string "TOUR FERRAILLE.\p"
	.string "Je vous en prie, continuez.$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Je vous en prie, continuez.$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "Ce carillon révèle la nature de\n"
	.string "l'âme de son porteur.\p"
	.string "You…\n"
	.string "Vous en êtes vraiment digne.$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TOUR FERRAILLE devant nous a\n"
	.string "neuf étages d'une beauté divine.\p"
	.string "Elle apaise l'âme de tous ceux\n"
	.string "qui la contemplent.$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "La TOUR FERRAILLE a tremblé! Un\n"
	.string "POKéMON a dû regagner son sommet!$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "Deux tours… Deux POKéMON…\p"
	.string "Mais quand l'une brûla, tous deux\n"
	.string "s'envolèrent à jamais.$"
