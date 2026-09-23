Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Appuie sur A ou B pour revenir.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "Les POKéMON se cachent dans les\n"
	.string "hautes herbes. Ils peuvent surgir!$"

Route29_Text_OldMan2:
	.string "Je t'ai déjà croisé plusieurs fois.\n"
	.string "Combien de POKéMON as-tu attrapés?\p"
	.string "Veux-tu que je t'explique comment\n"
	.string "attraper les POKéMON?$"

Route29_Text_OldManExplanation:
	.string "Affaiblis d'abord le POKéMON pour\n"
	.string "pouvoir l'attraper plus facilement.\p"
	.string "Ensuite, lance-lui une BALL depuis\n"
	.string "ton SAC. N'importe laquelle ira!\p"
	.string "Pour en apprendre davantage, va à\n"
	.string "l'ÉCOLE des DRESSEURS de MAUVILLE!\p"
	.string "Les élèves en savent beaucoup\n"
	.string "sur les POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Oh, très bien.\p"
	.string "Explore chaque route pour trouver\n"
	.string "différentes espèces de POKéMON.\p"
	.string "Ton POKéDEX indique aussi où\n"
	.string "tu peux les rencontrer!\p"
	.string "Pour en apprendre davantage, va à\n"
	.string "l'ÉCOLE des DRESSEURS de MAUVILLE!\p"
	.string "Les élèves en savent beaucoup\n"
	.string "sur les POKéMON.$"

Route29_Text_Youngster:
	.string "Salut. Comment vont tes POKéMON?\p"
	.string "S'ils sont faibles ou incapables\n"
	.string "de combattre, évite les herbes.$"

Route29_Text_Lass:
	.string "Tu vois ces rebords?\n"
	.string "Ça fait peur de sauter de là.\p"
	.string "Mais tu peux rejoindre BOURG GEON\n"
	.string "sans traverser les hautes herbes.$"

Route29_Text_Girl:
	.string "Je voulais faire une pause, alors\n"
	.string "j'ai sauvegardé ma progression.$"

Route29_Text_Boy_WaitingForDay:
	.string "J'attends les POKéMON qui\n"
	.string "n'apparaissent que dans la journée.$"

Route29_Text_Boy_WaitingForNight:
	.string "J'attends les POKéMON qui\n"
	.string "n'apparaissent que la nuit.$"

Route29_Text_MeetTuscany:
	.string "MARIE: Il me semble que c'est la\n"
	.string "première fois que l'on se rencontre.\p"
	.string "Je suis MARIE, de la famille des Jours.\p"
	.string "Devine mon jour préféré et je\n"
	.string "t'offrirai une récompense.$"

Route29_Text_TuscanyNope:
	.string "Pas tout à fait!$"

Route29_Text_TuscanyGivesGift:
	.string "Oui! Pour fêter notre rencontre,\n"
	.string "accepte ce MOUCHOIR SOIE en\l"
	.string "cadeau.$"

Route29_Text_TuscanyGaveGift:
	.string "MARIE: Il est adorable,\n"
	.string "tu ne trouves pas?\p"
	.string "Il renforce les capacités de\n"
	.string "type NORMAL.\p"
	.string "Je suis sûre qu'il te sera utile.$"

Route29_Text_TuscanyTuesday:
	.string "MARIE: As-tu rencontré LUCIE,\n"
	.string "ma grande sœur?\p"
	.string "Ou mon petit frère HOMER?\p"
	.string "Je suis la troisième d'une famille\n"
	.string "de sept enfants.$"

Route29_Text_Sign1:
	.string "ROUTE 29\p"
	.string "VILLE GRIOTTE - BOURG GEON$"
