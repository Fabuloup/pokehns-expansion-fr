UlaulaIsle_hns_MapScripts::
	.byte 0

Alola_Ulaula_FindItem1::
	finditem ITEM_FRIEND_BALL, 1
	end


Alola_Ulaula_FindItem2::
	finditem ITEM_PROTEIN, 1
	end


Alola_Ulaula_MtLanikalaSign::
	lock
	msgbox Alola_Ulaula_MtLanikalaSign_Text_0
	release
	end


Alola_Ulaula_UlaulaSign::
	lock
	msgbox Alola_Ulaula_UlaulaSign_Text_0
	release
	end


Alola_Ulaula_TapuBulu_Flyover::
	goto_if_set FLAG_FLYOVER_TAPU_BULU, Alola_Ulaula_TapuBulu_Flyover_2
	release
	end

Alola_Ulaula_TapuBulu_Flyover_2:
	addobject Ulaula_Flyover_Tapu
	playse SE_M_FLY
	applymovement Ulaula_Flyover_Tapu, Alola_Ulaula_TapuBulu_Flyover_Movement_0
	waitmovement 0
	removeobject Ulaula_Flyover_Tapu
	clearflag FLAG_FLYOVER_TAPU_BULU
	clearflag FLAG_HIDE_TAPU_BULU
	release
	end


Alola_Ulaula_Phant_outside::
	lock
	faceplayer
	hidefollower
	msgbox Alola_Ulaula_Phant_outside_Text_0, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 35
	goto_if_eq Alola_Ulaula_Phant_outside_3
Alola_Ulaula_Phant_outside_1:
	compare VAR_TEMP_0, 36
	goto_if_eq Alola_Ulaula_Phant_outside_8
Alola_Ulaula_Phant_outside_6:
	compare VAR_TEMP_0, 37
	goto_if_eq Alola_Ulaula_Phant_outside_13
Alola_Ulaula_Phant_outside_11:
	compare VAR_TEMP_0, 36
	goto_if_eq Alola_Ulaula_Phant_outside_18
Alola_Ulaula_Phant_outside_16:
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Ulaula_Phant_outside_Text_1, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 35
	goto_if_eq Alola_Ulaula_Phant_outside_23
Alola_Ulaula_Phant_outside_22:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_6
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement Phant_Noivern_Outside, Alola_Ulaula_Phant_outside_Movement_5
	waitmovement 0
	removeobject Phant_Noivern_Outside
	removeobject Phant_Outside
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

Alola_Ulaula_Phant_outside_2:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_0
	goto Alola_Ulaula_Phant_outside_1

Alola_Ulaula_Phant_outside_3:
	compare VAR_TEMP_1, 46
	goto_if_eq Alola_Ulaula_Phant_outside_2
	goto Alola_Ulaula_Phant_outside_1

Alola_Ulaula_Phant_outside_7:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_1
	goto Alola_Ulaula_Phant_outside_6

Alola_Ulaula_Phant_outside_8:
	compare VAR_TEMP_1, 47
	goto_if_eq Alola_Ulaula_Phant_outside_7
	goto Alola_Ulaula_Phant_outside_6

Alola_Ulaula_Phant_outside_12:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_2
	goto Alola_Ulaula_Phant_outside_11

Alola_Ulaula_Phant_outside_13:
	compare VAR_TEMP_1, 46
	goto_if_eq Alola_Ulaula_Phant_outside_12
	goto Alola_Ulaula_Phant_outside_11

Alola_Ulaula_Phant_outside_17:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_3
	goto Alola_Ulaula_Phant_outside_16

Alola_Ulaula_Phant_outside_18:
	compare VAR_TEMP_1, 45
	goto_if_eq Alola_Ulaula_Phant_outside_17
	goto Alola_Ulaula_Phant_outside_16

Alola_Ulaula_Phant_outside_21:
	applymovement Phant_Outside, Alola_Ulaula_Phant_outside_Movement_4
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement Phant_Noivern_Outside, Alola_Ulaula_Phant_outside_Movement_5
	waitmovement 0
	removeobject Phant_Noivern_Outside
	removeobject Phant_Outside
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

Alola_Ulaula_Phant_outside_23:
	compare VAR_TEMP_1, 46
	goto_if_eq Alola_Ulaula_Phant_outside_21
	goto Alola_Ulaula_Phant_outside_22


Alola_Ulaula_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_ULAULA_PICNICKER_HNS, Alola_Ulaula_TrainerBattlePicnicker_Text_0, Alola_Ulaula_TrainerBattlePicnicker_Text_1
	msgbox Alola_Ulaula_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_TrainerBattleYoungster::
	trainerbattle_single TRAINER_ULAULA_YOUNGSTER_HNS, Alola_Ulaula_TrainerBattleYoungster_Text_0, Alola_Ulaula_TrainerBattleYoungster_Text_1
	msgbox Alola_Ulaula_TrainerBattleYoungster_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_TrainerBattleHiker::
	trainerbattle_single TRAINER_ULAULA_HIKER_HNS, Alola_Ulaula_TrainerBattleHiker_Text_0, Alola_Ulaula_TrainerBattleHiker_Text_1
	msgbox Alola_Ulaula_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_TrainerBattleCooltrainer::
	trainerbattle_single TRAINER_ULAULA_COOLTRAINER_HNS, Alola_Ulaula_TrainerBattleCooltrainer_Text_0, Alola_Ulaula_TrainerBattleCooltrainer_Text_1
	msgbox Alola_Ulaula_TrainerBattleCooltrainer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_LassNPC::
	lock
	faceplayer
	msgbox Alola_Ulaula_LassNPC_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Ulaula_Bench_Heal_Right::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq Alola_Ulaula_Bench_Heal_Skip
	goto Alola_Ulaula_Bench_Heal

Alola_Ulaula_Bench_Heal_Left::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq Alola_Ulaula_Bench_Heal_Skip
	goto Alola_Ulaula_Bench_Heal

Alola_Ulaula_Bench_Heal_Skip:
	end

Alola_Ulaula_Bench_Heal:
	lock
	faceplayer
	msgbox Alola_Ulaula_Bench_Heal_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Ulaula_Bench_Heal_2
Alola_Ulaula_Bench_Heal_1:
	callnative UpdateFollowingPokemon
	release
	end

Alola_Ulaula_Bench_Heal_2:
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	applymovement LOCALID_PLAYER, Alola_Ulaula_Bench_Heal_Movement_0
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Alola_Ulaula_Bench_Heal_1


Alola_Ulaula_TapuBulu_Flyover_Movement_0:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Alola_Ulaula_Phant_outside_Movement_0:
	jump_in_place_left
	jump_in_place_left
	step_end

Alola_Ulaula_Phant_outside_Movement_1:
	jump_in_place_down
	jump_in_place_down
	step_end

Alola_Ulaula_Phant_outside_Movement_2:
	jump_in_place_right
	jump_in_place_right
	step_end

Alola_Ulaula_Phant_outside_Movement_3:
	jump_in_place_up
	jump_in_place_up
	step_end

Alola_Ulaula_Phant_outside_Movement_4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

Alola_Ulaula_Phant_outside_Movement_5:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Alola_Ulaula_Phant_outside_Movement_6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

Alola_Ulaula_Bench_Heal_Movement_0:
	face_down
	step_end

Alola_Ulaula_BattlePalossand_Text_0:
	.string "Crac !$"

Alola_Ulaula_MtLanikalaSign_Text_0:
	.string "Les habitants nomment ce sommet\n"
	.string "MONT LANAKILA. Il est le plus haut\l"
	.string "des sommets des\l"
	.string "ÎLES D'ALOLA.\p"
	.string "Son véritable nom s'est perdu\n"
	.string "s'est perdu avec le temps.$"

Alola_Ulaula_UlaulaSign_Text_0:
	.string "ÎLE D'ULA-ULA$"

Alola_Ulaula_Phant_outside_Text_0:
	.string "Salut, {PLAYER} !\p"
	.string "Je suis le développeur qui a créé\n"
	.string "cette partie du jeu !\p"
	.string "J'espère que cet aperçu t'a plu.\p"
	.string "Je crée un demake complet de\n"
	.string "la région nommé ULTRA ECLIPSE.$"

Alola_Ulaula_Phant_outside_Text_1:
	.string "Viens me voir dans ma maison au\n"
	.string "sommet de cette île.\l"
	.string "Tu ne le regretteras pas !$"

Alola_Ulaula_TrainerBattlePicnicker_Text_0:
	.string "Surprise !\nJ'étais dans les arbres !$"

Alola_Ulaula_TrainerBattlePicnicker_Text_1:
	.string "Je retourne me cacher…$"

Alola_Ulaula_TrainerBattlePicnicker_Text_2:
	.string "J'ai vu quelque chose de rouge\n"
	.string "voler dans le ciel.\p"
	.string "Était-ce un POKéMON ?$"

Alola_Ulaula_TrainerBattleYoungster_Text_0:
	.string "Hé, je serai le premier à gravir\nle MONT LANAKILA !$"

Alola_Ulaula_TrainerBattleYoungster_Text_1:
	.string "Ce n'est pas le MONT LANAKILA…$"

Alola_Ulaula_TrainerBattleYoungster_Text_2:
	.string "Mon père ignore le vrai nom\n"
	.string "de cette montagne.\p"
	.string "On dit toujours MONT LANAKILA.$"

Alola_Ulaula_TrainerBattleHiker_Text_0:
	.string "Tu es robuste pour affronter\nce terrain accidenté !$"

Alola_Ulaula_TrainerBattleHiker_Text_1:
	.string "Ouf,\nj'aurais dû mieux m'entraîner…$"

Alola_Ulaula_TrainerBattleHiker_Text_2:
	.string "Randonnée idéale à ULA-ULA !\p"
	.string "Les gens appellent ce sommet MONT\n"
	.string "LANAKILA, le plus haut des\l"
	.string "ÎLES D'ALOLA !$"

Alola_Ulaula_TrainerBattleCooltrainer_Text_0:
	.string "Cette grotte sent très mauvais !\nCombattons pour ne plus y penser !$"

Alola_Ulaula_TrainerBattleCooltrainer_Text_1:
	.string "Il me fallait du désodorisant…$"

Alola_Ulaula_TrainerBattleCooltrainer_Text_2:
	.string "Tu devrais te boucher le nez si tu\n"
	.string "comptes entrer dans cette grotte.$"

Alola_Ulaula_LassNPC_Text_0:
	.string "La mer autour des ÎLES est superbe\n"
	.string "à couper le souffle.\p"
	.string "Je pourrais rester assise ici à\n"
	.string "regarder les vagues tout le jour.$"

Alola_Ulaula_Bench_Heal_Text_0:
	.string "Veux-tu te reposer sur ce\n"
	.string "banc ?$"

Alola_Ulaula_EventScript_MoveTutor::
	lock
	faceplayer
	goto_if_set FLAG_ULAULA_MOVE_TUTOR_PAID, Alola_Ulaula_EventScript_MoveTutorMenu
	msgbox Alola_Ulaula_Text_MoveTutorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Alola_Ulaula_EventScript_MoveTutorDecline
	checkitem ITEM_HEART_SCALE, 5
	goto_if_eq VAR_RESULT, FALSE, Alola_Ulaula_EventScript_MoveTutorNoScales
	removeitem ITEM_HEART_SCALE, 5
	setflag FLAG_ULAULA_MOVE_TUTOR_PAID
	msgbox Alola_Ulaula_Text_MoveTutorPaid, MSGBOX_DEFAULT

Alola_Ulaula_EventScript_MoveTutorMenu::
	message Alola_Ulaula_Text_MoveTutorChoose
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, Alola_Ulaula_Text_TutorMove_Acrobatics, Alola_Ulaula_Text_TutorMove_AuroraVeil, Alola_Ulaula_Text_TutorMove_BrutalSwing, Alola_Ulaula_Text_TutorMove_Bulldoze, Alola_Ulaula_Text_TutorMove_Confide, Alola_Ulaula_Text_TutorMove_DazzlingGleam, Alola_Ulaula_Text_TutorMove_DragonTail, Alola_Ulaula_Text_TutorMove_EchoedVoice, Alola_Ulaula_Text_TutorMove_FlameCharge, Alola_Ulaula_Text_TutorMove_FrostBreath, Alola_Ulaula_Text_TutorMove_Infestation, Alola_Ulaula_Text_TutorMove_LeechLife, Alola_Ulaula_Text_TutorMove_LowSweep, Alola_Ulaula_Text_TutorMove_Psyshock, Alola_Ulaula_Text_TutorMove_Quash, Alola_Ulaula_Text_TutorMove_Round, Alola_Ulaula_Text_TutorMove_Scald, Alola_Ulaula_Text_TutorMove_SkyDrop, Alola_Ulaula_Text_TutorMove_SludgeWave, Alola_Ulaula_Text_TutorMove_SmackDown, Alola_Ulaula_Text_TutorMove_SmartStrike, Alola_Ulaula_Text_TutorMove_Snarl, Alola_Ulaula_Text_TutorMove_Venoshock, Alola_Ulaula_Text_TutorMove_VoltSwitch, Alola_Ulaula_Text_TutorMove_WildCharge, Alola_Ulaula_Text_TutorMove_WorkUp, Alola_Ulaula_Text_TutorMove_Cancel
	switch VAR_RESULT
	case 0, Alola_Ulaula_EventScript_TutorTeach_Acrobatics
	case 1, Alola_Ulaula_EventScript_TutorTeach_AuroraVeil
	case 2, Alola_Ulaula_EventScript_TutorTeach_BrutalSwing
	case 3, Alola_Ulaula_EventScript_TutorTeach_Bulldoze
	case 4, Alola_Ulaula_EventScript_TutorTeach_Confide
	case 5, Alola_Ulaula_EventScript_TutorTeach_DazzlingGleam
	case 6, Alola_Ulaula_EventScript_TutorTeach_DragonTail
	case 7, Alola_Ulaula_EventScript_TutorTeach_EchoedVoice
	case 8, Alola_Ulaula_EventScript_TutorTeach_FlameCharge
	case 9, Alola_Ulaula_EventScript_TutorTeach_FrostBreath
	case 10, Alola_Ulaula_EventScript_TutorTeach_Infestation
	case 11, Alola_Ulaula_EventScript_TutorTeach_LeechLife
	case 12, Alola_Ulaula_EventScript_TutorTeach_LowSweep
	case 13, Alola_Ulaula_EventScript_TutorTeach_Psyshock
	case 14, Alola_Ulaula_EventScript_TutorTeach_Quash
	case 15, Alola_Ulaula_EventScript_TutorTeach_Round
	case 16, Alola_Ulaula_EventScript_TutorTeach_Scald
	case 17, Alola_Ulaula_EventScript_TutorTeach_SkyDrop
	case 18, Alola_Ulaula_EventScript_TutorTeach_SludgeWave
	case 19, Alola_Ulaula_EventScript_TutorTeach_SmackDown
	case 20, Alola_Ulaula_EventScript_TutorTeach_SmartStrike
	case 21, Alola_Ulaula_EventScript_TutorTeach_Snarl
	case 22, Alola_Ulaula_EventScript_TutorTeach_Venoshock
	case 23, Alola_Ulaula_EventScript_TutorTeach_VoltSwitch
	case 24, Alola_Ulaula_EventScript_TutorTeach_WildCharge
	case 25, Alola_Ulaula_EventScript_TutorTeach_WorkUp
	case 26, Alola_Ulaula_EventScript_MoveTutorDecline
	case MULTI_B_PRESSED, Alola_Ulaula_EventScript_MoveTutorDecline
	end

Alola_Ulaula_EventScript_TutorTeach_Acrobatics::
	setvar VAR_0x8005, MOVE_ACROBATICS
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_AuroraVeil::
	setvar VAR_0x8005, MOVE_AURORA_VEIL
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_BrutalSwing::
	setvar VAR_0x8005, MOVE_BRUTAL_SWING
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Bulldoze::
	setvar VAR_0x8005, MOVE_BULLDOZE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Confide::
	setvar VAR_0x8005, MOVE_CONFIDE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_DazzlingGleam::
	setvar VAR_0x8005, MOVE_DAZZLING_GLEAM
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_DragonTail::
	setvar VAR_0x8005, MOVE_DRAGON_TAIL
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_EchoedVoice::
	setvar VAR_0x8005, MOVE_ECHOED_VOICE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_FlameCharge::
	setvar VAR_0x8005, MOVE_FLAME_CHARGE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_FrostBreath::
	setvar VAR_0x8005, MOVE_FROST_BREATH
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Infestation::
	setvar VAR_0x8005, MOVE_INFESTATION
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_LeechLife::
	setvar VAR_0x8005, MOVE_LEECH_LIFE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_LowSweep::
	setvar VAR_0x8005, MOVE_LOW_SWEEP
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Psyshock::
	setvar VAR_0x8005, MOVE_PSYSHOCK
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Quash::
	setvar VAR_0x8005, MOVE_QUASH
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Round::
	setvar VAR_0x8005, MOVE_ROUND
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Scald::
	setvar VAR_0x8005, MOVE_SCALD
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SkyDrop::
	setvar VAR_0x8005, MOVE_SKY_DROP
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SludgeWave::
	setvar VAR_0x8005, MOVE_SLUDGE_WAVE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SmackDown::
	setvar VAR_0x8005, MOVE_SMACK_DOWN
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_SmartStrike::
	setvar VAR_0x8005, MOVE_SMART_STRIKE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Snarl::
	setvar VAR_0x8005, MOVE_SNARL
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_Venoshock::
	setvar VAR_0x8005, MOVE_VENOSHOCK
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_VoltSwitch::
	setvar VAR_0x8005, MOVE_VOLT_SWITCH
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_WildCharge::
	setvar VAR_0x8005, MOVE_WILD_CHARGE
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_TutorTeach_WorkUp::
	setvar VAR_0x8005, MOVE_WORK_UP
	goto Alola_Ulaula_EventScript_MoveTutorTeachMove
	end

Alola_Ulaula_EventScript_MoveTutorTeachMove::
	buffermovename STR_VAR_1, VAR_0x8005
	msgbox Alola_Ulaula_Text_MoveTutorConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Alola_Ulaula_EventScript_MoveTutorMenu
	msgbox Alola_Ulaula_Text_MoveTutorWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, Alola_Ulaula_EventScript_MoveTutorCancelMon
	msgbox Alola_Ulaula_Text_MoveTutorDone, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_EventScript_MoveTutorCancelMon::
	msgbox Alola_Ulaula_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_EventScript_MoveTutorDecline::
	msgbox Alola_Ulaula_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_EventScript_MoveTutorNoScales::
	msgbox Alola_Ulaula_Text_MoveTutorNoScales, MSGBOX_DEFAULT
	release
	end

Alola_Ulaula_Text_MoveTutorIntro:
	.string "ARH !\n"
	.string "AGH !\p"
	.string "TOI !\p"
	.string "Les autres t'ont envoyé ici ?\n"
	.string "T'ont-ils dit que je suis le\l"
	.string "maître des capacités POKéMON ?\p"
	.string "........................\p"
	.string "J'enseigne à tes POKéMON les\n"
	.string "techniques des ÎLES, contre une\l"
	.string "petite somme.\p"
	.string "Cela coûte 5 ÉCAILLES COEUR.\p"
	.string "Tu les as ?$"

Alola_Ulaula_Text_MoveTutorPaid:
	.string "Ma femme adore ces choses.\p"
	.string "Désormais, mes services te\n"
	.string "sont acquis.$"

Alola_Ulaula_Text_MoveTutorNoScales:
	.string "Cinq ÉCAILLES COEUR.\n"
	.string "Pas quatre.\p"
	.string "Essaie de briser des rochers.\n"
	.string "Avec tes POKéMON ou tes poings !$"

Alola_Ulaula_Text_MoveTutorChoose:
	.string "Quelle capacité veux-tu ?$"

Alola_Ulaula_Text_MoveTutorConfirm:
	.string "Tu veux apprendre {STR_VAR_1} ?$"

Alola_Ulaula_Text_MoveTutorWhichMon:
	.string "Quel POKéMON doit l'apprendre ?$"

Alola_Ulaula_Text_MoveTutorDone:
	.string "EXCELLENT !\p"
	.string "Ton POKéMON possède le savoir\n"
	.string "des ÎLES.$"

Alola_Ulaula_Text_MoveTutorComeBack:
	.string "Les ÎLES ne vont pas disparaître.\n"
	.string "Reviens quand tu veux.$"

Alola_Ulaula_Text_TutorMove_Acrobatics:
	.string "ACROBATIE$"

Alola_Ulaula_Text_TutorMove_AuroraVeil:
	.string "VOILE AURORE$"

Alola_Ulaula_Text_TutorMove_BrutalSwing:
	.string "CENTRIFUGIFLE$"

Alola_Ulaula_Text_TutorMove_Bulldoze:
	.string "PIÉTISOL$"

Alola_Ulaula_Text_TutorMove_Confide:
	.string "CONFIDENCE$"

Alola_Ulaula_Text_TutorMove_DazzlingGleam:
	.string "ÉCLAT MAGIQUE$"

Alola_Ulaula_Text_TutorMove_DragonTail:
	.string "DRACO-QUEUE$"

Alola_Ulaula_Text_TutorMove_EchoedVoice:
	.string "ÉCHO$"

Alola_Ulaula_Text_TutorMove_FlameCharge:
	.string "NITROCHARGE$"

Alola_Ulaula_Text_TutorMove_FrostBreath:
	.string "SOUFFLE GLACÉ$"

Alola_Ulaula_Text_TutorMove_Infestation:
	.string "HARCÈLEMENT$"

Alola_Ulaula_Text_TutorMove_LeechLife:
	.string "VAMPIRISME$"

Alola_Ulaula_Text_TutorMove_LowSweep:
	.string "BALAYETTE$"

Alola_Ulaula_Text_TutorMove_Psyshock:
	.string "CHOC PSY$"

Alola_Ulaula_Text_TutorMove_Quash:
	.string "À LA QUEUE$"

Alola_Ulaula_Text_TutorMove_Round:
	.string "CHANT CANON$"

Alola_Ulaula_Text_TutorMove_Scald:
	.string "ÉBULLITION$"

Alola_Ulaula_Text_TutorMove_SkyDrop:
	.string "CHUTE LIBRE$"

Alola_Ulaula_Text_TutorMove_SludgeWave:
	.string "CRADOVAGUE$"

Alola_Ulaula_Text_TutorMove_SmackDown:
	.string "ANTI-AIR$"

Alola_Ulaula_Text_TutorMove_SmartStrike:
	.string "ESTOCORNE$"

Alola_Ulaula_Text_TutorMove_Snarl:
	.string "ABOIEMENT$"

Alola_Ulaula_Text_TutorMove_Venoshock:
	.string "CHOC VENIN$"

Alola_Ulaula_Text_TutorMove_VoltSwitch:
	.string "CHANGE ÉCLAIR$"

Alola_Ulaula_Text_TutorMove_WildCharge:
	.string "ÉCLAIR FOU$"

Alola_Ulaula_Text_TutorMove_WorkUp:
	.string "RENGORGEMENT$"

Alola_Ulaula_Text_TutorMove_Cancel:
	.string "ANNULER$"
