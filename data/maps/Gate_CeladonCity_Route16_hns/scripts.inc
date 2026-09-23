Gate_CeladonCity_Route16_hns_MapScripts::
	.byte 0

Gate_CeladonCity_Route16_TriggerScript::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Gate_CeladonCity_Route16_NoBike
	goto_if_set FLAG_SYS_CYCLING_ROAD, Gate_CeladonCity_Route16_ExitCyclingRoad
	goto_if_unset FLAG_SYS_CYCLING_ROAD, Gate_CeladonCity_Route16_EnterCyclingRoad

Gate_CeladonCity_Route16_NoBike::
	msgbox Gate_CeladonCity_Route16_Text_TooDangerousToWalk_hns, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	clearflag FLAG_SYS_CYCLING_ROAD
	releaseall
	end

Gate_CeladonCity_Route16_EnterCyclingRoad::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	setflag FLAG_SYS_CYCLING_ROAD
	releaseall
	end

Gate_CeladonCity_Route16_ExitCyclingRoad::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	clearflag FLAG_SYS_CYCLING_ROAD
	releaseall
	end

Gate_CeladonCity_Route16_Text_TooDangerousToWalk_hns:
	.string "La PISTE CYCLABLE est interdite\n"
	.string "aux piétons. C'est trop dangereux.\p"
	.string "Revenez avec un VÉLO.$"
