AzaleaTown_KurtsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
	end

AzaleaTown_KurtsHouse_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
	.2byte 0

AzaleaTown_KurtsHouse_EventScript_KurtBefore::
	lock
	faceplayer
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	setvar VAR_AZALEA_TOWN_STATE, 2
	release
	end

AzaleaTown_KurtsHouse_EventScript_PlayerMove::
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl2::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5

	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl3::
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl4::
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_Girl5::
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_FAST_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	setvar VAR_AZALEA_TOWN_STATE, 4
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
	return

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
	msgbox KurtsHouse_Text_KurtAskYouHaveAnApricorn, MSGBOX_DEFAULT
	closemessage
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
AzaleaTown_KurtsHouse_EventScript_Kurt2::
	special CreateKurtBallShop
	waitstate
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_KurtCancel
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, AzaleaTown_KurtsHouse_EventScript_TurnWest
	call_if_eq VAR_FACING, DIR_WEST, AzaleaTown_KurtsHouse_EventScript_TurnEast
	call_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_TurnSouth
	goto_if_eq VAR_0x8005, 1, AzaleaTown_KurtsHouse_EventScript_SingularBall
	bufferitemname STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	msgbox KurtsHouse_Text_KurtFinishedPlural, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedPlural
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_TurnSouth::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_SOUTH
	return
AzaleaTown_KurtsHouse_EventScript_TurnWest::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_WEST
	return
AzaleaTown_KurtsHouse_EventScript_TurnEast::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_EAST
	return


AzaleaTown_KurtsHouse_EventScript_SingularBall::
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox KurtsHouse_Text_KurtFinishedSingular, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedSingular
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCancel::
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GS_BALL
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	playse SE_M_PETAL_DANCE
	waitse
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
	waitmovement 0
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 8
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
KurtsHouse_Text_BallAnyway:
	.string "Bref, je te fabrique des BALLS?$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	closemessage
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	closemessage
	end

AzaleaTownKurt_Movement_Look_Around:
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	delay_8
	face_left
	step_end

AzaleaTownKurt_Movement_Making_Ball:
	face_up
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	step_end

AzaleaTown_KurtsHouse_Movement_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KurtsHouse_Text_KurtGetStarted:
	.string "FARGAS: Je m'y mets tout de\n"
	.string "suite!$"

KurtsHouse_Text_KurtMakingBallsMustWait:
	.string "Hum? Qui es-tu?\p"
	.string "{PLAYER}? Tu voudrais que je\n"
	.string "fabrique des BALLS?\p"
	.string "Désolé, mais ça devra attendre.\p"
	.string "Connais-tu la TEAM ROCKET?\n"
	.string "Bah, peu importe.\p"
	.string "Je vais t'en toucher deux mots.\p"
	.string "La TEAM ROCKET est une bande de\n"
	.string "crapules qui utilisent les\l"
	.string "POKéMON pour leurs sales coups.\p"
	.string "Ils ont cessé d'opérer il y a de\n"
	.string "ça trois ans.\p"
	.string "Mais les voilà au PUITS, à\n"
	.string "couper les QUEUES de RAMOLOSS\l"
	.string "pour les revendre!\p"
	.string "Je m'en vais leur montrer de\n"
	.string "quel bois je me chauffe!\p"
	.string "Tenez bon, les RAMOLOSS! Le\n"
	.string "vieux FARGAS arrive!$"

KurtsHouse_Text_KurtHonoredToMakeBalls:
	.string "FARGAS: Salut, {PLAYER}!\p"
	.string "Quel courage tu as montré au\n"
	.string "PUITS!\p"
	.string "J'apprécie ton style!\p"
	.string "Ce serait un honneur de\n"
	.string "fabriquer des BALLS pour un\l"
	.string "Dresseur comme toi.\p"
	.string "C'est tout ce que j'ai pour le\n"
	.string "moment, mais prends-le.$"

KurtsHouse_Text_KurtBallsFromApricorns:
	.string "FARGAS: Je fais des BALLS à\n"
	.string "partir de BAIES.\p"
	.string "Décroche-les des arbres et\n"
	.string "rapporte-les moi.\p"
	.string "J'en ferai des POKé BALL.$"

KurtsHouse_Text_KurtAskYouHaveAnApricorn:
	.string "FARGAS: Tu as des BAIES pour\n"
	.string "moi?\p"
	.string "Parfait! Je vais en faire des\n"
	.string "POKé BALL.$"

KurtsHouse_Text_KurtThatsALetdown:
	.string "FARGAS: Je ne vois aucun\n"
	.string "{STR_VAR_1}!$"

KurtsHouse_Text_KurtFinishedPlural:
	.string "FARGAS: {PLAYER}!\n"
	.string "Tes {STR_VAR_1} sont prêtes!$"

KurtsHouse_Text_KurtObtainedPlural:
	.string "{PLAYER} obtient\n"
	.string "{STR_VAR_2} {STR_VAR_1}!$"

KurtsHouse_Text_KurtFinishedSingular:
	.string "FARGAS: {PLAYER}!\n"
	.string "Ta {STR_VAR_1} est prête. Tiens!$"

KurtsHouse_Text_KurtObtainedSingular:
	.string "{PLAYER} obtient\n"
	.string "la {STR_VAR_1}!$"

KurtsHouse_Text_KurtTurnedOutGreat:
	.string "FARGAS: Je suis content du\n"
	.string "résultat.\p"
	.string "Va attraper des POKéMON avec!$"

KurtsHouse_Text_KurtWhatIsThat:
	.string "C'est quoi donc?\p"
	.string "Je n'avais jamais vu ça.\p"
	.string "On dirait bien une POKé BALL,\n"
	.string "mais ça doit être autre chose.\p"
	.string "Je vais regarder ça pour toi.$"

KurtsHouse_Text_KurtImCheckingItNow:
	.string "Je fais mes recherches.$"

KurtsHouse_Text_KurtAhHaISee:
	.string "Ah-ha! Je vois! Donc…$"

KurtsHouse_Text_KurtThisBallStartedToShake:
	.string "{PLAYER}!\p"
	.string "La BALL s'est mise à bouger\n"
	.string "pendant que je l'examinais.\p"
	.string "Y'a du mystère là-dessous!$"

KurtsHouse_Text_Kurt_Whatwasthat:
	.string "C'était quoi, ce bruit?!\p"
	.string "Sortons voir ce qui se passe!$"

KurtsHouse_Text_GranddaughterSlowpokeGone:
	.string "Les RAMOLOSS sont partis…\n"
	.string "Ont-ils été enlevés par de\l"
	.string "vilains gredins?$"

KurtsHouse_Text_GranddaughterLonely:
	.string "Pépé a filé… Je suis si seule…$"

KurtsHouse_Text_GranddaughterSlowpokeBack:
	.string "Le RAMOLOSS que mon pôpa m'a\n"
	.string "donné est de retour!\p"
	.string "Et sa QUEUE repousse!$"

KurtsHouse_Text_GranddaughterDad:
	.string "Pôpa travaille à la SYLPHE SARL,\n"
	.string "où il étudie les POKé BALL.\p"
	.string "Je dois rester à la maison avec\n"
	.string "mon pépé et mon RAMOLOSS.$"

KurtsHouse_Text_GranddaughterHelp:
	.string "J'aide mon pépé, maintenant!\p"
	.string "On va te faire de belles BALLS,\n"
	.string "alors patiente un peu!$"

KurtsHouse_Text_GranddaughterFun:
	.string "C'est rigolo de faire des BALLS!$"

KurtsHouse_Text_GranddaughterSound:
	.string "Ce bruit, il venait du BOIS AUX\n"
	.string "CHÊNES????$"

KurtsHouse_Text_Forest:
	.string "Tu as vu le BOIS AUX CHÊNES?\n"
	.string "Il a l'air très agité.$"

KurtsHouse_Text_Slowpoke:
	.string "RAMOLOSS: …(bâille)…$"

KurtsHouse_Text_OakPhoto:
	.string "…Un jeune PROF. CHEN?$"

KurtsHouse_Text_CelebiStatue:
	.string "C'est une statue du protecteur\n"
	.string "de la forêt.$"
