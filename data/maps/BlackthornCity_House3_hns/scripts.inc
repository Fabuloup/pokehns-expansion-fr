BlackthornCity_House3_hns_MapScripts::
	.byte 0

BlackthornCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox BlackthornCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Hum… Ah, oui, je suis l'EFFACEUR\n"
	.string "DE CAPACITES. Je fais oublier\p"
	.string "leurs capacités aux POKéMON.\p"
	.string "Tu veux que je le fasse?$"

BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "Quel POKéMON doit oublier ça?$"

BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "Oublier quelle capacité?$"

BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} ne connaît qu'une capacité\n"
	.string "et ne peut donc pas l'oublier…$"

BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Hum! {STR_VAR_1} et sa capacité\n"
	.string "{STR_VAR_2}? Il faut l'oublier?$"

BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "C'est une réussite parfaite!\p"
	.string "{STR_VAR_1} a complètement oublié\n"
	.string "{STR_VAR_2}.$"

BlackthornCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Reviens si d'autres capacités\n"
	.string "doivent être oubliées.$"

BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "Quoi? Les OEUFS ne\n"
	.string "connaissent pas de capacité.$"

BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "Hum!\p"
	.string "Ton {STR_VAR_1} ne semble pas vouloir\n"
	.string "oublier SURF.$"

BlackthornCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	faceplayer
	specialvar VAR_RESULT, IsRandomMovesActivated
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer
	goto_if_set FLAG_TEMP_1, BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp:
	.string "Désolé, je ne peux rien faire.$"

BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Je suis le MAÎTRE DES CAPACITÉS.\p"
	.string "Je connais toutes les capacités\n"
	.string "apprises par les POKéMON et peux\l"
	.string "les leur enseigner.\p"
	.string "Je peux en apprendre une à l'un\n"
	.string "de tes POKéMON, si tu veux.\p"
	.string "Il me faut une ÉCAILLE COEUR.\n"
	.string "Je les collectionne.$"

BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! Une véritable ÉCAILLE COEUR!\n"
	.string "C'est exactement ce qu'il me faut!\p"
	.string "Laisse-moi deviner: tu veux que\n"
	.string "j'enseigne une capacité?$"

BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Quel POKéMON doit être entraîné?$"

BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Quelle attaque dois-je enseigner?$"

BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Désolé…\p"
	.string "Je n'ai rien à enseigner\n"
	.string "à ce POKéMON.$"

BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} donne une ÉCAILLE COEUR\n"
	.string "en échange.$"

BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "Si ton POKéMON doit apprendre,\n"
	.string "reviens avec une ÉCAILLE COEUR.$"

BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Quoi? Mais je ne peux pas\n"
	.string "apprendre une attaque à un OEUF.$"



