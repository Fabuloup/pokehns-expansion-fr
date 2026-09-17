.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}!\p"
	.string "Que fais-tu ici?\p"
	.string "Mon assistant t'attend toujours\n"
	.string "à MAUVILLE!$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1_Register, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_RegisteredElm, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "Mieux vaut ne pas y toucher!$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "ORME: {PLAYER}! Te voilà!\p"
	.string "J'ai un service à te demander.\p"
	.string "Je mène de nouvelles recherches\n"
	.string "sur les POKéMON et j'aimerais\l"
	.string "que tu m'aides, {PLAYER}.\p"
	.string "Tu vois…\p"
	.string "J'écris un article que je veux\n"
	.string "présenter à une conférence.\p"
	.string "Mais certains points m'échappent\n"
	.string "encore.\p"
	.string "Alors voilà!\p"
	.string "J'aimerais que tu élèves un\n"
	.string "POKéMON capturé récemment.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "Merci, {PLAYER}!\n"
	.string "Tu m'es d'une grande aide!$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Mais… S'il te plaît, j'ai\n"
	.string "besoin de ton aide!$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Quand je publierai mes résultats,\n"
	.string "nous en apprendrons sûrement plus\p"
	.string "sur les nombreux mystères des\n"
	.string "POKéMON.\p"
	.string "Tu peux en être sûr!$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "Oh! J'ai reçu un e-mail!\p"
	.string "… … … … … … … …\n"
	.string "Hmm… Oui…\p"
	.string "D'accord…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Écoute voir.\p"
	.string "J'ai un ami du nom de\n"
	.string "M. POKéMON.\p"
	.string "Il découvre sans cesse des choses\n"
	.string "étranges et s'en émerveille.\p"
	.string "Il vient de m'envoyer un e-mail\n"
	.string "pour me dire que, cette fois,\l"
	.string "c'est du sérieux.\p"
	.string "C'est intriguant, mais nos\n"
	.string "recherches nous occupent…\p"
	.string "Attends!\n"
	.string "J'ai une idée!\p"
	.string "{PLAYER}, peux-tu y aller à\n"
	.string "notre place?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Je veux que tu élèves l'un des\n"
	.string "POKéMON dans ces BALLS.\p"
	.string "Tu seras son premier partenaire,\n"
	.string "{PLAYER}!\p"
	.string "Allez! Choisis!$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ORME: Hep! Où vas-tu?$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ORME: Tu veux {STR_VAR_1},\n"
	.string "le POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ORME: Tu choisis {STR_VAR_1},\n"
	.string "le POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ORME: {STR_VAR_1} te plaît,\n"
	.string "le POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ORME: Réfléchis bien.\p"
	.string "Ton partenaire est très important.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "ORME: C'est aussi un très bon\n"
	.string "POKéMON!$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER} reçoit {STR_VAR_1}!$"

NewBarkTown_Lab_Text_Nickname:
	.string "Veux-tu donner un surnom à\n"
	.string "{STR_VAR_1}?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "M. POKéMON habite un peu après\n"
	.string "VILLE GRIOTTE, la ville\l"
	.string "voisine.\p"
	.string "Le chemin est presque tout droit.\n"
	.string "Tu ne peux pas te tromper.\p"
	.string "Au cas où, tu as mon numéro.\n"
	.string "Appelle-moi s'il se passe\l"
	.string "quelque chose!$"

NewBarkTown_Lab_Text_ElmDirections1_Register:
	.string "M. POKéMON habite un peu après\n"
	.string "VILLE GRIOTTE, la ville\l"
	.string "voisine.\p"
	.string "Le chemin est presque tout droit.\n"
	.string "Tu ne peux pas te tromper.\p"
	.string "Au cas où, voici mon numéro.\n"
	.string "Appelle-moi s'il se passe\l"
	.string "quelque chose!$"

NewBarkTown_Lab_Text_RegisteredElm:
	.string "Le PROF. ORME est enregistré\n"
	.string "dans le POKéMATOS.$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Si un POKéMON sauvage apparaît,\n"
	.string "laisse ton POKéMON le combattre!$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "Si un POKéMON sauvage apparaît,\n"
	.string "laisse ton POKéMON le combattre!\p"
	.string "S'il est blessé, soigne-le avec\n"
	.string "la machine à ma droite ou dans\l"
	.string "un CENTRE POKéMON.\p"
	.string "Je compte sur toi!$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} obtient le numéro de\n"
	.string "téléphone du PROF. ORME.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "M. POKéMON voyage partout et\n"
	.string "découvre des raretés.\p"
	.string "Hélas, elles sont souvent rares,\n"
	.string "mais pas très utiles…$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Elle contient un POKéMON capturé\n"
	.string "par le PROF. ORME.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ORME: {PLAYER}, c'est terrible…\p"
	.string "Au fait, quelle était la grande\n"
	.string "découverte de M. POKéMON?$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} confie l'ŒUF MYSTÈRE\n"
	.string "au PROF. ORME.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "ORME: C'est ça?$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Mais… Serait-ce un ŒUF de POKéMON?\p"
	.string "Si c'est le cas, c'est une grande\n"
	.string "découverte!\p"
	.string "ORME: Quoi?!?\p"
	.string "Le PROF. CHEN t'a donné un POKéDEX?\p"
	.string "{PLAYER}, c'est vrai?\n"
	.string "C-c'est incroyable!\p"
	.string "Il sait repérer le potentiel\n"
	.string "des Dresseurs.\p"
	.string "Waouh, {PLAYER}. Tu pourrais bien\n"
	.string "devenir Maître POKéMON.\p"
	.string "Et tu sembles très bien t'entendre\n"
	.string "avec les POKéMON.\p"
	.string "Tu devrais relever le défi des\n"
	.string "Arènes POKéMON.\p"
	.string "L'Arène la plus proche se trouve\n"
	.string "à MAUVILLE.\p"
	.string "…{PLAYER}. La route vers le titre\n"
	.string "sera longue.\p"
	.string "Avant de partir, va parler à\n"
	.string "ta mère.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ORME: N'abandonne pas!\n"
	.string "Je t'appellerai si j'apprends\l"
	.string "quelque chose sur cet ŒUF!$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ORME: {PLAYER}? Tu n'as pas vu\n"
	.string "mon assistant?\p"
	.string "Il devait te remettre l'ŒUF au\n"
	.string "CENTRE POKéMON de MAUVILLE.\p"
	.string "Vous avez dû vous manquer.\n"
	.string "Essaie de le retrouver là-bas.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ORME: Alors, cet ŒUF a-t-il\n"
	.string "changé?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER}? Je croyais que l'ŒUF\n"
	.string "avait éclos.\p"
	.string "Où est le POKéMON?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ORME: {PLAYER}, tu as l'air en forme!$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "Quoi? Ce POKéMON?!?$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "L'ŒUF a éclos! Les POKéMON\n"
	.string "naissent donc dans des ŒUFS…\p"
	.string "Non, peut-être pas tous les\n"
	.string "POKéMON.\p"
	.string "Il reste encore tant de\n"
	.string "recherches à mener.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Merci, {PLAYER}! Grâce à toi, nous\n"
	.string "perçons les mystères des POKéMON!\p"
	.string "Je veux t'offrir ceci pour te\n"
	.string "remercier.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "C'est une PIERRE STASE.\p"
	.string "Certaines espèces de POKéMON\n"
	.string "évoluent à un niveau précis.\p"
	.string "Un POKéMON qui tient une PIERRE\n"
	.string "STASE n'évoluera pas.\p"
	.string "Donne-la à un POKéMON dont tu\n"
	.string "veux empêcher l'évolution.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ORME: {PLAYER}, je t'appellerai\n"
	.string "s'il se passe quelque chose.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "…Soupir… Ce POKéMON volé…\p"
	.string "Je me demande comment il va.\p"
	.string "On dit qu'un POKéMON élevé par\n"
	.string "une mauvaise personne le devient.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ORME: Bonjour, {PLAYER}!\p"
	.string "Grâce à toi, mes recherches\n"
	.string "avancent à merveille!\p"
	.string "Prends ceci en signe de ma\n"
	.string "reconnaissance.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "La MASTER BALL est la meilleure!\p"
	.string "C'est la BALL ultime! Elle attrape\n"
	.string "tout POKéMON à coup sûr.\p"
	.string "On ne l'offre qu'aux chercheurs\n"
	.string "POKéMON reconnus.\p"
	.string "Tu en feras meilleur usage que moi,\n"
	.string "{PLAYER}!$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "Au fait…\n"
	.string "Un groupe de charmantes SŒURS\l"
	.string "KIMONO te cherchait.\p"
	.string "Elles t'attendent à la\n"
	.string "SALLE DE DANSE de ROSALIA.\p"
	.string "Tu as traversé bien des épreuves\n"
	.string "depuis que cet ŒUF t'a mêlé à\l"
	.string "toute cette histoire…\p"
	.string "J'espère que tu iras jusqu'au bout.$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF. ORME: Les SŒURS KIMONO\n"
	.string "t'attendent à la SALLE DE DANSE\l"
	.string "de ROSALIA.$"

NewBarkTown_Lab_Text_League:
	.string "PROF. ORME: Hahaha…\n"
	.string "Bravo!\p"
	.string "Cet ŒUF rare t'a causé bien des\n"
	.string "ennuis, pas vrai?\p"
	.string "Les SŒURS KIMONO t'ont parlé\n"
	.string "de moi?\p"
	.string "Je n'ai rien à voir là-dedans.\p"
	.string "Tu as pris ta décision et tu es\n"
	.string "allé jusqu'au bout.\p"
	.string "Après tout ce chemin, tu peux\n"
	.string "affronter la LIGUE!\p"
	.string "Rends-toi au PLATEAU INDIGO!\p"
	.string "Tu sais comment y aller?\n"
	.string "Suis la ROUTE 27, puis la ROUTE 26.\p"
	.string "Ensuite, continue plein nord!$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ORME: {PLAYER}! Te voilà!\p"
	.string "Je t'ai appelé car j'ai quelque\n"
	.string "chose pour toi.\p"
	.string "Regarde! C'est un PASSE BATEAU.\p"
	.string "Tu peux maintenant capturer des\n"
	.string "POKéMON à KANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "Le bateau part d'OLIVILLE.\p"
	.string "Mais tu le savais déjà,\n"
	.string "{PLAYER}.\p"
	.string "Après tout, tu as tant voyagé\n"
	.string "avec tes POKéMON.\p"
	.string "Passe le bonjour au PROF. CHEN\n"
	.string "à KANTO!$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "C'est l'ŒUF de POKéMON étudié\n"
	.string "par le PROF. ORME.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, prends ceci pour ton\n"
	.string "voyage.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "Nous ne sommes que trois, alors\n"
	.string "nous sommes toujours débordés.$"

NewBarkTown_Lab_Text_AideSave:
	.string "N'oublie pas de sauvegarder\n"
	.string "régulièrement!\p"
	.string "Appuie sur START, puis choisis\n"
	.string "SAUVEGARDER!$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Un grand bruit a retenti\n"
	.string "dehors…\p"
	.string "Quand nous sommes sortis voir,\n"
	.string "quelqu'un avait volé un POKéMON.\p"
	.string "Comment peut-on faire une chose\n"
	.string "pareille?\p"
	.string "…Soupir… Ce POKéMON volé…\p"
	.string "Je me demande comment il va.\p"
	.string "On dit qu'un POKéMON élevé par\n"
	.string "une mauvaise personne le devient.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER}!\p"
	.string "Utilise-les pour compléter ton\n"
	.string "POKéDEX!$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Pour remplir ton POKéDEX, tu dois\n"
	.string "capturer des POKéMON.\p"
	.string "Lance des POKé BALLS sur les\n"
	.string "POKéMON sauvages pour les attraper.$"

NewBarkTown_Lab_Text_Officer1:
	.string "J'ai entendu dire qu'un POKéMON\n"
	.string "avait été volé ici…\p"
	.string "Je recueillais justement des\n"
	.string "informations auprès du PROF. ORME.\p"
	.string "Le suspect serait un jeune homme\n"
	.string "aux longs cheveux rouges…\p"
	.string "Quoi?\p"
	.string "Tu as combattu un Dresseur qui\n"
	.string "correspond à ce signalement?\p"
	.string "Aurais-tu retenu son nom?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "Bien! Il s'appelle donc {RIVAL}?$"

NewBarkTown_Lab_Text_Officer2:
	.string "Merci pour ton aide dans cette\n"
	.string "enquête!$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "Tu as bien retenu son nom?!$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "Ah, {PLAYER}!\p"
	.string "Ton POKéDEX avance bien?\n"
	.string "Je suis occupé, mais appelle-moi\l"
	.string "et je regarderai tes progrès!$"
