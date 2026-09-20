.set FOUND_FIRST_SWITCH, FLAG_TEMP_1
.set SWITCH1_ID,         VAR_0x8004
.set SWITCH2_ID,         VAR_0x8005
.set TRASH_CAN_ID,       VAR_0x8008

.set CHECK_VISITOR_STATE, 6
.set TYPE, VAR_0x8003
.set ARGUMENT, VAR_0x8004

VermilionCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_Return::
	end

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_EventScript_Gregory::
	trainerbattle_single TRAINER_GREGORY_HNS, VermilionGym_Text_GentlemanGregorySeen, VermilionGym_Text_GentlemanGregoryBeaten
	msgbox VermilionGym_Text_GentlemanGregoryAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT_HNS, VermilionGym_Text_GuitaristVincentSeen, VermilionGym_Text_GuitaristVincentBeaten
	msgbox VermilionGym_Text_GuitaristVincentAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Horton::
	trainerbattle_single TRAINER_HORTON_HNS, VermilionGym_Text_JugglerHortonSeen, VermilionGym_Text_JugglerHortonBeaten
	msgbox VermilionGym_Text_JugglerHortonAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_Surge_Defeated
	msgbox VermilionGym_Text_LtSurgeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, VermilionGym_Text_LtSurgeWinLoss
	message VermilionGym_Text_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VermilionGym_Text_ThunderBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE11_GET
	setflag FLAG_DEFEATED_VERMILION_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers_hns
	checkitem ITEM_TM_SHOCK_WAVE
	call_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_GiveThunderstone
	call_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_GiveTM
	clearflag FLAG_HIDE_PLANT_SURGE
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GiveThunderstone::
	msgbox VermilionGym_Text_LtSurgeThunderstone, MSGBOX_DEFAULT
	giveitem ITEM_THUNDER_STONE
	return

VermilionCity_Gym_EventScript_GiveTM::
	msgbox VermilionGym_Text_LtSurge_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SHOCK_WAVE
	msgbox VermilionGym_Text_LtSurge_ExplainTM, MSGBOX_DEFAULT
	return

VermilionCity_Gym_EventScript_Surge_Defeated::
	msgbox VermilionGym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionGym_Text_LtSurgeIntro:
	.string "MAJOR BOB : Hé, petit !\p"
	.string "Je dois le reconnaître.\n"
	.string "Me défier n'est peut-être pas\l"
	.string "très malin, mais tu as du cran !\p"
	.string "Pour les POKéMON de type\n"
	.string "ÉLECTRIK, je suis numéro un !\p"
	.string "Je n'ai jamais perdu sur le\n"
	.string "champ de bataille.\p"
	.string "Je vais te foudroyer comme mes\n"
	.string "ennemis pendant la guerre !$"

VermilionGym_Text_LtSurgeWinLoss:
	.string "MAJOR BOB : Argh ! Tu es fort !\p"
	.string "OK, petit. Voici le BADGE FOUDRE !$"

VermilionGym_Text_ReceivedThunderBadge:
	.string "{PLAYER} reçoit le BADGE FOUDRE.$"

VermilionGym_Text_ThunderBadgeInfo:
	.string "MAJOR BOB : Ce BADGE augmente\n"
	.string "la Vitesse des POKéMON.\p"
	.string "Considère-le comme la preuve que\n"
	.string "tu m'as vaincu.\p"
	.string "Porte-le fièrement, compris ?$"

VermilionGym_Text_LtSurge_GiveTM:
	.string "Et prends cette CT. Elle m'a bien\n"
	.string "servi pendant la guerre !$"

VermilionGym_Text_LtSurge_ExplainTM:
	.string "C'est ONDE DE CHOC.\p"
	.string "Une capacité électrisante qui\n"
	.string "touche à chaque fois !$"

VermilionGym_Text_LtSurgeThunderstone:
	.string "Et prends cette pierre. Elle a\n"
	.string "un vrai pouvoir électrique !$"


VermilionGym_Text_LtSurgePostBattle:
	.string "MAJOR BOB : Hé, petit ! Toujours\n"
	.string "en train de te battre ?\p"
	.string "Mes POKéMON et moi continuons !$"

VermilionGym_Text_SurgeRematch:
	.string "MAJOR BOB : Alors, tu es le MAÎTRE\n"
	.string "de KANTO !\p"
	.string "Beau travail, petit !\n"
	.string "Mais je n'ai pas fini !\p"
	.string "On remet ça ?$"

VermilionGym_Text_SurgeRematchDefeat:
	.string "MAJOR BOB : Argh ! Tu es toujours\n"
	.string "aussi fort !$"

VermilionGym_Text_GentlemanGregorySeen:
	.string "Tu viens vaincre le MAJOR BOB ?\p"
	.string "Pas si je peux l'éviter !$"

VermilionGym_Text_GentlemanGregoryBeaten:
	.string "Désolé de vous avoir déçu,\n"
	.string "MAJOR BOB, monsieur !$"

VermilionGym_Text_GentlemanGregoryAfter:
	.string "Quand j'étais encore dans l'armée,\n"
	.string "le MAJOR BOB m'a sauvé la vie.$"

VermilionGym_Text_GuitaristVincentSeen:
	.string "Le MAJOR BOB a reconnu mon talent\n"
	.string "avec les POKéMON ÉLECTRIK.\p"
	.string "Tu crois pouvoir me battre ?$"

VermilionGym_Text_GuitaristVincentBeaten:
	.string "Oh, quel choc !$"

VermilionGym_Text_GuitaristVincentAfter:
	.string "Maman m'a dit de ne pas quitter\n"
	.string "mon emploi, mais que faire si je\l"
	.string "n'y rencontre pas plus de\l"
	.string "succès ?$"

VermilionGym_Text_JugglerHortonSeen:
	.string "Je vais te terrasser !\n"
	.string "Prépare-toi à prendre un choc !$"

VermilionGym_Text_JugglerHortonBeaten:
	.string "Gwaaah ! J'ai été dépassé…$"

VermilionGym_Text_JugglerHortonAfter:
	.string "Ne prends pas trop confiance après\n"
	.string "m'avoir battu…\p"
	.string "Le MAJOR BOB est coriace.$"

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "Yo !\n"
    .string "Futur MAÎTRE !\p"
    .string "Le MAJOR BOB a un surnom.\p"
    .string "On l'appelle\n"
    .string "l'Américain survolté !\p"
    .string "C'est un expert des POKéMON\n"
    .string "ÉLECTRIK.\p"
    .string "Les POKéMON VOL/EAU sont faibles\n"
    .string "face au type ÉLECTRIK.\p"
    .string "Attention aussi à la paralysie.\p"
    .string "Le MAJOR BOB est très prudent.\p"
    .string "Il s'est enfermé, alors il sera\n"
    .string "difficile de l'atteindre.$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "Ouf ! Quel combat\n"
	.string "électrisant !\p"
	.string "Il m'a vraiment rendu nerveux.$"

VermilionCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CARMIN SUR MER\n"
    .string "CHAMPION : MAJOR BOB\p"
	.string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED$"


VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CARMIN SUR MER\n"
    .string "CHAMPION : MAJOR BOB\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED, {PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "Non !\n"
    .string "Il n'y a que des déchets ici.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "Hé ! Il y a un interrupteur sous\n"
    .string "les déchets ! Activons-le !\p"
    .string "Le premier verrou s'ouvre !$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "Le deuxième verrou s'ouvre !\n"
    .string "La porte motorisée s'ouvre !$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "Non !\n"
    .string "Il n'y a que des déchets ici.\p"
    .string "Hé !\n"
    .string "Les verrous sont réinitialisés !$"
