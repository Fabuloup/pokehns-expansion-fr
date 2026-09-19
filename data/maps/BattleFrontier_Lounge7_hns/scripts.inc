BattleFrontier_Lounge7_hns_MapScripts::
	.byte 0

@special ChooseMonForMoveTutor
BattleFrontier_Lounge7_EventScript_LeftMoveTutor_hns::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor_hns
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro_hns, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor_hns::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled_hns
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss_hns
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater_hns
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch_hns
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick_hns
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam_hns
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide_hns
	case 7, BattleFrontier_Lounge7_EventScript_Counter_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave_hns
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled_hns
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss_hns
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater_hns
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch_hns
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick_hns
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam_hns
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide_hns
	case 7, BattleFrontier_Lounge7_EventScript_Counter_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave_hns
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_Softboiled_hns::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_SeismicToss_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_DreamEater_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_MegaPunch_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_MegaKick_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_BodySlam_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_RockSlide_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Counter_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ThunderWave_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_SwordsDance_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor_hns::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor_hns
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro_hns, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor_hns::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl_hns
	case 1, BattleFrontier_Lounge7_EventScript_Snore_hns
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap_hns
	case 3, BattleFrontier_Lounge7_EventScript_Swift_hns
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind_hns
	case 5, BattleFrontier_Lounge7_EventScript_Endure_hns
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp_hns
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch_hns
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl_hns
	case 1, BattleFrontier_Lounge7_EventScript_Snore_hns
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap_hns
	case 3, BattleFrontier_Lounge7_EventScript_Swift_hns
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind_hns
	case 5, BattleFrontier_Lounge7_EventScript_Endure_hns
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp_hns
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch_hns
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl_hns::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Snore_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_MudSlap_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Swift_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_IcyWind_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Endure_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_PsychUp_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_IcePunch_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_FirePunch_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon_hns_hns::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo_hns, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove_hns
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove_hns
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove_hns
	end


BattleFrontier_Lounge7_EventScript_TeachTutorMove_hns::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon_hns_hns
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints_hns, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove_hns::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove_hns
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_Sailor_hns::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor::
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	end

BattleFrontier_Lounge7_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	setvar VAR_0x8005, MOVE_FRENZY_PLANT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	setvar VAR_0x8005, MOVE_BLAST_BURN
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	setvar VAR_0x8005, MOVE_HYDRO_CANNON
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon_hns::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end


BattleFrontier_Lounge7_Text_LeftTutorIntro_hns:
	.string "Oh, oh! Tu auras du mal à le\p"
	.string "croire, mais dans le temps,\n"
	.string "j'étais un DRESSEUR hors pair.\p"
	.string "On disait que j'étais le CANON\n"
	.string "le plus doué du coin! … … …\p"
	.string "… … … Comment? Je sais, c'est\p"
	.string "dur à croire. Je ne suis pas\n"
	.string "comme cette vantarde en face.\p"
	.string "Moi, j'ai vraiment du talent!\n"
	.string "Je vais te le prouver. Je\p"
	.string "peux enseigner à tes POKéMON\n"
	.string "des capacités particulières\l"
	.string "mais mignonnes. Bien sûr,\p"
	.string "ce ne sera pas gratuit.\n"
	.string "Si tu payais ces capacités\l"
	.string "avec des POINTS DE COMBAT?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack_hns:
	.string "Oh, oh! Tu veux des\p"
	.string "capacités particulières mais\n"
	.string "mignonnes pour tes POKéMON?$"

BattleFrontier_Lounge7_Text_TeachWhichMove_hns:
	.string "Bien! Quelle\n"
	.string "capacité veux-tu?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints_hns:
	.string "La capacité {STR_VAR_1}?\n"
	.string "Elle coûte {STR_VAR_2} POINTS DE COMBAT.$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon_hns:
	.string "Très bien. Choisis le POKéMON\n"
	.string "auquel je dois l'enseigner.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints_hns:
	.string "Mais enfin… Tu n'as pas\n"
	.string "assez de POINTS DE COMBAT!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints_hns:
	.string "Je suis douée, non? Je prends\n"
	.string "tes POINTS DE COMBAT, merci!$"

BattleFrontier_Lounge7_Text_YouDontWantTo_hns:
	.string "Oh? Tu as changé d'avis…\n"
	.string "Si tu veux que je te\p"
	.string "montre à quel point je suis\n"
	.string "douée, reviens me voir!$"

BattleFrontier_Lounge7_Text_RightTutorIntro_hns:
	.string "Hi, hi, hi! C'est difficile à\p"
	.string "imaginer, à présent, mais j'ai\n"
	.string "été un DRESSEUR fantastique.\p"
	.string "On disait que j'étais la plus\n"
	.string "forte des NAGEUSE, rien que\p"
	.string "ça! … … … … … … Comment? Tu\p"
	.string "ne me crois pas, évidemment.\n"
	.string "Je ne suis pas comme cette\p"
	.string "menteuse en face. J'ai vraiment\n"
	.string "du talent! Je peux te le\p"
	.string "prouver. Je peux enseigner\n"
	.string "des capacités difficiles mais\l"
	.string "belles à tes POKéMON. Bien\p"
	.string "sûr, ce ne sera pas gratuit.\n"
	.string "Si tu payais ces capacités\l"
	.string "avec des POINTS DE COMBAT?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack_hns:
	.string "Hi, hi, hi! Tu veux que j'enseigne\p"
	.string "des capacités difficiles\n"
	.string "mais belles à tes POKéMON?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong_hns:
	.string "Ces deux vieilles dames n'arrêtent\n"
	.string "pas de se critiquer, comme si\l"
	.string "elles se détestaient. Mais si\p"
	.string "c'était vrai, elles ne seraient\n"
	.string "pas toujours ensemble ici, non?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful_hns:
	.string "Quand j'étais un jeune GAMIN,\n"
	.string "elles étaient fortes et belles.\p"
	.string "Nous, DRESSEURS, les admirions.\p"
	.string "Leur âge n'a toujours pas émoussé\n"
	.string "leurs talents.\p"
	.string "Leurs POKéMON sont même devenus\n"
	.string "plus habiles encore.\p"
	.string "Mais… Une idée me poursuit\n"
	.string "sans cesse…\p"
	.string "Le temps est vraiment cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc_hns::
	.string "Regagne jusqu'à\n"
	.string "la moitié des PV\n"
	.string "max du lanceur.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc_hns::
	.string "Inflige des\n"
	.string "dégâts selon le\n"
	.string "niveau du lanceur.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc_hns::
	.string "Aspire la moitié\n"
	.string "des dégâts sur\n"
	.string "l'ennemi endormi.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc_hns::
	.string "Un coup de poing\n"
	.string "d'une puissance\n"
	.string "incroyable.$"

BattleFrontier_Lounge7_Text_MegaKickDesc_hns::
	.string "Un coup de pied\n"
	.string "super puissant\n"
	.string "et intense.$"

BattleFrontier_Lounge7_Text_BodySlamDesc_hns::
	.string "Une attaque en\n"
	.string "charge. Peut pa-\n"
	.string "ralyser l'ennemi.$"

BattleFrontier_Lounge7_Text_RockSlideDesc_hns::
	.string "Envoie de gros\n"
	.string "rochers. Peut\n"
	.string "apeurer l'ennemi.$"

BattleFrontier_Lounge7_Text_CounterDesc_hns::
	.string "Renvoie toute\n"
	.string "attaque physique,\n"
	.string "2 fois plus fort.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc_hns::
	.string "Un faible choc\n"
	.string "électrique qui\n"
	.string "paralyse l'ennemi.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc_hns::
	.string "Une danse de\n"
	.string "combat pour\n"
	.string "booster l'ATTAQUE.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc_hns::
	.string "S'enroule, cache\n"
	.string "les faiblesses.\n"
	.string "Monte la DEFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc_hns::
	.string "Attaque sonore\n"
	.string "qui ne peut être\n"
	.string "lancée qu'endormi.$"

BattleFrontier_Lounge7_Text_MudSlapDesc_hns::
	.string "Envoie de la boue\n"
	.string "au visage et rend\n"
	.string "moins précis.$"

BattleFrontier_Lounge7_Text_SwiftDesc_hns::
	.string "Envoie des rayons\n"
	.string "en forme d'étoile.\n"
	.string "Touche toujours.$"

BattleFrontier_Lounge7_Text_IcyWindDesc_hns::
	.string "Attaque glaciale.\n"
	.string "Baisse la VITESSE\n"
	.string "de l'ennemi.$"

BattleFrontier_Lounge7_Text_EndureDesc_hns::
	.string "Encaisse les\n"
	.string "attaques du tour\n"
	.string "et conserve 1 PV.$"

BattleFrontier_Lounge7_Text_PsychUpDesc_hns::
	.string "Copie les effets\n"
	.string "de l'ennemi et les\n"
	.string "passe au lanceur.$"

BattleFrontier_Lounge7_Text_IcePunchDesc_hns::
	.string "Un poing de\n"
	.string "glace pouvant\n"
	.string "geler l'ennemi.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc_hns::
	.string "Un poing électri-\n"
	.string "que pouvant para-\n"
	.string "lyser l'ennemi.$"

BattleFrontier_Lounge7_Text_FirePunchDesc_hns::
	.string "Un poing de\n"
	.string "feu pouvant\n"
	.string "brûler l'ennemi.$"


BattleFrontier_Lounge7_Text_ElementalTutorIntro::
	.string "Zzzzzz…\p"
	.string "Quoi? Comment? Hein?\p"
	.string "Oh, pardon, je somnolais un peu.\p"
	.string "Je suis le MAÎTRE DES ÉLÉMENTS.\p"
	.string "Je peux enseigner les capacités\n"
	.string "les plus puissantes aux POKéMON\l"
	.string "de types PLANTE, FEU et EAU.\p"
	.string "Tu es venu acquérir une telle\n"
	.string "puissance?$"

BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack:
	.string "Zzzzzz…\p"
	.string "Quoi? Comment? Qui ça?\p"
	.string "Oh, tu veux apprendre la\n"
	.string "force de mes capacités ultimes?$"

BattleFrontier_Lounge7_Text_TeachWhichMoveElemental::
	.string "Quelle capacité conviendrait le\n"
	.string "mieux à ton POKéMON?$"

BattleFrontier_Lounge7_Text_StrongElementalMoveDesc::
	.string "Très puissante,\n"
	.string "mais immobilise\n"
	.string "au tour suivant.$"

