Route24_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 16, 8
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 16, 9
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31_HNS, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "Hé, gamin! Moi être genre membre\n"
	.string "de la TEAM ROCKET!\p"
	.string "Venir d'autre pays, Dresseur\n"
	.string "numéro un, moi!\p"
	.string "Moi penser, si énergie arrêter,\n"
	.string "grosse panique pour gens d'ici!\p"
	.string "Secrète être ma mission, alors te\n"
	.string "dire moi pas!\p"
	.string "Mais! Si toi gagner contre moi, un\n"
	.string "homme moi être et mon secret à toi\l"
	.string "moi dire.\p"
	.string "Hé, gamin! Combat commencer nous!$"

Route24_Text_RocketBeaten:
	.string "Aïe! Non, non, non, croire ça\n"
	.string "moi pas pouvoir!\p"
	.string "Très fort être toi! À ta hauteur\n"
	.string "moi pas être!$"

Route24_Text_RocketAfter:
	.string "OK. Mon secret dire à toi moi?\n"
	.string "PIÈCE MACHINE moi voler, cacher\l"
	.string "moi faire dans ARÈNE d'AZURIA.\p"
	.string "Dans eau mettre moi faire. Cherche\n"
	.string "dans eau au centre de l'ARÈNE.\p"
	.string "Mais toi oublier moi pas!\p"
	.string "Battre toi sûrement fera TEAM\n"
	.string "ROCKET.\p"
	.string "Venir de JOHTO ils feront, mes\n"
	.string "amis, oui. Se venger ils\l"
	.string "vont.$"

Route24_Text_RocketDisappears:
	.string "…\p"
	.string "Toi dire quoi? TEAM ROCKET partie\n"
	.string "pour toujours? Dissoute elle est\l"
	.string "toi dire?\p"
	.string "Oh non! Faire quoi maintenant\n"
	.string "moi?$"



Route24_Text_Woman:
	.string "Quelle jolie vue, n'est-ce pas?$"
Route24_Text_Man:
	.string "Je resterais ici toute ma vie.$"

Route24_Text_WomanRocket:
	.string "Personne ne me pousse!$"
Route24_Text_ManRocket:
	.string "Personne ne pousse ma copine!$"

Route24_Text_WomanAfterRocket:
	.string "Qu'est-ce qui lui a pris?$"
Route24_Text_ManAfterRocket:
	.string "C'était un membre ROCKET?$"
