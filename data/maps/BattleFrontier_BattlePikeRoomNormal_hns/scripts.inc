BattleFrontier_BattlePikeRoomNormal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp_hns
	.byte 0

BattleFrontier_BattlePikeRoomNormal_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom_hns
	.2byte 0

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom_hns::
	setvar VAR_TEMP_0, 1
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom_hns
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom_hns
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom_hns
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom_hns
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom_hns
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom_hns::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_SINGLE
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle_hns
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY_HNS, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle_hns::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom_hns::
	lockall
	delay 16
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer_hns, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_SINGLE
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle_hns::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer_hns
	waitmovement 0
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth_hns, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom_hns::
	delay 22
	lockall
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer_hns
	waitmovement 0
	pike_prequeenheal
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal_hns
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon_hns
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster_hns, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hnsForLucy_hns
	waitmovement 0
	playse SE_PIKE_CURTAIN_CLOSE
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed_hns
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed_hns
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed_hns
	delay 4
	waitse
	delay 60
	playse SE_PIKE_CURTAIN_OPEN
	delay 65
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed_hns
	showobjectat LOCALID_PIKE_ROOM_NPC_1, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL_HNS
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed_hns
	delay 4
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen_hns
	waitse
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter_hns
	waitmovement 0
	pike_getbrainstatus
	switch VAR_RESULT
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold_hns
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver_hns
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold_hns
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen_hns, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle_hns
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsSilver_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsSilver_hns::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass_hns, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear_hns, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold_hns::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain_hns, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle_hns
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsGold_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hnsGold_hns::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass_hns, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget_hns, MSGBOX_DEFAULT
	closemessage
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy_hns::
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2_hns
	waitmovement 0
	pike_get PIKE_DATA_WIN_STREAK
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom_hns
	waitstate
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne_hns, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo_hns, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom_hns::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns
	waitmovement 0
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth_hns
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns
	waitmovement 0
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom_hns::
	lockall
	delay 16
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1_hns
	waitmovement 0
	pike_gettrainerintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2_hns
	waitmovement 0
	pike_gettrainerintro 1
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_DOUBLE
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle_hns
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost_hns
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle_hns::
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom_hns::
	lockall
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut_hns
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer_hns
	waitmovement 0
	pike_getstatusmon
	copyvar VAR_0x8004, VAR_RESULT
	call_if_eq VAR_0x8004, PIKE_STATUSMON_KIRLIA, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack_hns
	call_if_eq VAR_0x8004, PIKE_STATUSMON_DUSCLOPS, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack_hns
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled_hns, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop_hns, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_TOXIC, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_PARALYSIS, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_SLEEP, BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis_hns
	pike_flashscreen
	waitstate
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC_hns
	waitmovement 0
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough_hns, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside_hns
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack_hns::
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop_hns, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	pike_getstatus
	call_if_eq VAR_RESULT, PIKE_STATUS_FREEZE, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam_hns
	call_if_eq VAR_RESULT, PIKE_STATUS_BURN, BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp_hns
	pike_flashscreen
	waitstate
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon_hns
	waitmovement 0
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC_hns
	waitmovement 0
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough_hns, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside_hns
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp_hns::
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp_hns
	waitmessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle_hns::
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2_hns
	waitmovement 0
	dofacilitytrainerbattle FACILITY_BATTLE_PIKE_SINGLE
	waitstate
	return

BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit_hns:
	walk_up
	walk_up
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hns:
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon_hns:
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer_hns:
	walk_down
	face_left
	delay_16
	delay_16
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer_hns:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_left
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC_hns:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside_hns:
	walk_left
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight_hns:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer_hns:
	walk_down
	walk_down
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1_hns:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2_hns:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp_hns:
	face_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight_hns:
	walk_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft_hns:
	walk_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer_hns:
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer_hns:
	face_left
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit_hns:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	set_invisible
	walk_up
	step_end

@ For approaching Lucy and exiting room after defeating Lucy
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2_hns:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hnsForLucy_hns:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter_hns:
	set_visible
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside_hns:
	walk_left
	face_right
	step_end

BattleFrontier_BattlePikeRoomNormal_EventScript_NPC_hns::
	pike_getroomtype
	switch VAR_RESULT
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC_hns
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC_hns
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC_hns
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC_hns::
	lock
	faceplayer
	pike_getnpcmsg
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine_hns, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC_hns::
	pike_healonetwomons
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons_hns
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon_hns
	playfanfare MUS_HEAL
	waitfanfare
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell_hns, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon_hns, MSGBOX_DEFAULT
	closemessage
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons_hns, MSGBOX_DEFAULT
	closemessage
	return

@ Dusclops or Kirlia
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon_hns::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence_hns, MSGBOX_DEFAULT
	closemessage
	release
	applymovement LOCALID_PIKE_ROOM_NPC_2, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight_hns
	waitmovement 0
	end

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed_hns::
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, TRUE
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, TRUE
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, TRUE
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, TRUE
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, TRUE
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, FALSE
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, TRUE
	special DrawWholeMapView
	return

BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp_hns:
	walk_up
	walk_up
	step_end

@ Unused
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth_hns:
	.string "Bienvenue… Félicitations pour\n"
	.string "votre chance…\p"
	.string "Je vais soigner vos POKéMON…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns:
	.string "Pourvu que la chance ne vous\n"
	.string "abandonne pas pour le reste du\l"
	.string "COMBAT HASARD…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon_hns:
	.string "Ah, tu en as de la chance, je suis\n"
	.string "de bonne humeur.\p"
	.string "Je vais soigner un de tes POKéMON.$"

BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell_hns:
	.string "Bonne chance à toi. Adieu.$"

@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons_hns:
	.string "Excusez-moi...\p"
	.string "Un combat vous tenterait? Je\n"
	.string "soignerai vos POKéMON si vous\l"
	.string "gagnez.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe_hns:
	.string "Très bien... Commençons,\n"
	.string "voulez-vous?$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou_hns:
	.string "Je vois... Quel manque de\n"
	.string "sportivité...$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised_hns:
	.string "Magnifique...\p"
	.string "Comme promis, je vais soigner tous\n"
	.string "vos POKéMON.$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell_hns2_hns:
	.string "Bonne chance à toi. Adieu.$"

BattleFrontier_BattlePikeRoomNormal_Text_WatchOut_hns:
	.string "Oh, non!\p"
	.string "Attention!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop_hns:
	.string "Non, KIRLIA! Arrête immédiatement!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop_hns:
	.string "TERACLOPE, enfin! Arrête\n"
	.string "immédiatement!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic_hns:
	.string "KIRLIA utilise TOXIK!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis_hns:
	.string "KIRLIA utilise HYPNOSE!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave_hns:
	.string "KIRLIA utilise CAGE-ECLAIR!$"

BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp_hns:
	.string "KIRLIA utilise FEU FOLLET!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp_hns:
	.string "TERACLOPE utilise FEU FOLLET!$"

BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam_hns:
	.string "TERACLOPE utilise LASER GLACE!$"

BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough_hns:
	.string "Par ici! Ça suffit!$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia_hns:
	.string "Je suis vraiment désolé…\p"
	.string "Mon KIRLIA est de nature TIMIDE…$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops_hns:
	.string "Je suis vraiment désolé…\p"
	.string "Mon TERACLOPE est de nature\n"
	.string "TIMIDE…$"

BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled_hns:
	.string "Il attaque sans prévenir quand il\n"
	.string "est surpris…\p"
	.string "Tes POKéMON et toi allez bien?$"

BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine_hns:
	.string "Ce qui est arrivé est navrant…\n"
	.string "J'espère que tes POKéMON et toi\l"
	.string "allez bien.$"

BattleFrontier_BattlePikeRoomNormal_Text_Silence_hns:
	.string "... ... ... ... ... ...... ... ...\n"
	.string "... ... ...$"

BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer_hns:
	.string "Bienvenue…\p"
	.string "Ici, vous allez affronter un\n"
	.string "DRESSEUR plutôt coriace…$"

BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth_hns:
	.string "Magnifique…\p"
	.string "Pour vous récompenser, je vais\n"
	.string "soigner vos POKéMON…$"

BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge_hns2_hns:
	.string "Pourvu que la chance ne vous\n"
	.string "abandonne pas pour le reste du\l"
	.string "COMBAT HASARD…$"

BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen_hns:
	.string "Je suis CHARLINE… C'est moi qui\n"
	.string "commande ici… On m'appelle la\l"
	.string "REINE VENIN…\p"
	.string "Comme tu dois le savoir, tu vas\n"
	.string "devoir essayer de me battre…\p"
	.string "Bon, ne reste pas là à bayer aux\n"
	.string "corneilles. Dépêche-toi, voyons…$"

BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck_hns:
	.string "J'espère que tu n'as pas encore\n"
	.string "épuisé toute ta chance…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass_hns:
	.string "CHARLINE: … … … … … … Montre-moi\n"
	.string "ton PASSE ZONE…$"

BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol_hns:
	.string "Le SYMBOLE CHANCE a été ajouté sur\n"
	.string "le PASSE ZONE!$"

BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear_hns:
	.string "Ce sera tout… Tu peux disposer…$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain_hns:
	.string "CHARLINE: Encore toi…\p"
	.string "… … … … … …\p"
	.string "J'ai dû en écraser plus d'un pour\n"
	.string "arriver là où je suis…\p"
	.string "Je ne me sens pas obligée de\n"
	.string "continuer à perdre contre toi…\p"
	.string "… … … … … … Bien… Allons-y…$"

BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn_hns:
	.string "Allez! On se bouge!$"

BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass_hns:
	.string "CHARLINE: … … … … … …\p"
	.string "PASSE ZONE…$"

BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine_hns:
	.string "Le SYMBOLE CHANCE a pris une\n"
	.string "couleur dorée!$"

BattleFrontier_BattlePikeRoomNormal_Text_IWontForget_hns:
	.string "J'ai une très bonne mémoire… Et je\n"
	.string "ne pardonne jamais…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal_hns:
	.string "Bienvenue…\p"
	.string "Hi, hi, hi… Ce n'est pas votre\n"
	.string "jour de chance…\p"
	.string "Si vous aviez choisi une autre\n"
	.string "salle, vos POKéMON auraient pu\l"
	.string "être soignés…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne_hns:
	.string "Bienvenue…\p"
	.string "Comme vous avez choisi cette\n"
	.string "salle, je vais soigner un de vos\l"
	.string "POKéMON…$"

BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo_hns:
	.string "Bienvenue…\p"
	.string "Comme vous avez choisi cette\n"
	.string "salle, je vais soigner deux de vos\l"
	.string "POKéMON…$"

@ Unused
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons_hns:
	.string "Bienvenue...\p"
	.string "Hi hi... Vous avez beaucoup de\n"
	.string "chance...\p"
	.string "Puisque vous avez choisi cette\n"
	.string "salle, tous vos POKéMON seront\l"
	.string "soignés...$"

BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster_hns:
	.string "Je vais appeler la patronne…$"

BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons_hns:
	.string "Ah, c'est ton jour de chance, je\n"
	.string "suis de bonne humeur.\p"
	.string "Je vais soigner deux de tes\n"
	.string "POKéMON!$"
