Route34_DayCare_hns_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	lock
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE1_WINDOW
	release
	end

Route34_DayCare_Bookshelf2::
	lock
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE2_WINDOW
	release
	end

Route34_DayCare_Bookshelf3::
	lock
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE3_WINDOW
	release
	end

Route34_DayCare_Bookshelf4::
	lock
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE4_WINDOW
	release
	end

Route34_DayCare_Text_Bookshelf1:
	.string "Une encyclopédie des BÉBÉS\n"
	.string "POKéMON!\p"
	.string "TOME 1: TOUT SUR LES TALENTS$"

Route34_DayCare_Text_Bookshelf2:
	.string "Une encyclopédie des BÉBÉS\n"
	.string "POKéMON!\p"
	.string "TOME 2: LES TYPES TYPIQUES$"

Route34_DayCare_Text_Bookshelf3:
	.string "Une encyclopédie des BÉBÉS\n"
	.string "POKéMON!\p"
	.string "TOME 3: LES CRIS DES BÉBÉS$"

Route34_DayCare_Text_Bookshelf4:
	.string "Une encyclopédie des BÉBÉS\n"
	.string "POKéMON!\p"
	.string "TOME 4: DES GESTES ADORABLES$"

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	setvar VAR_0x8005, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	case 8, Route34_DayCare_EventScript_GiveMantyke
	case 9, Route34_DayCare_EventScript_GiveBonsly
	case 10, Route34_DayCare_EventScript_GiveHappiny
	case 11, Route34_DayCare_EventScript_GiveMimeJr
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMantyke::
	giveoddegg 8
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveBonsly::
	giveoddegg 9
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveHappiny::
	giveoddegg 10
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMimeJr::
	giveoddegg 11
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
	.string "Je suis le fils du couple de la\n"
	.string "PENSION.\p"
	.string "Un ŒUF BIZARRE a été trouvé avec\n"
	.string "les POKéMON d'un DRESSEUR, mais\l"
	.string "personne n'en voulait…\p"
	.string "Je te le proposerais bien…\n"
	.string "Mais comment savoir si tu en\l"
	.string "prendras soin?$"

Route34_DayCare_Text_ClerkNoRoom:
	.string "On dirait que tu ne peux pas\n"
	.string "porter un POKéMON de plus, de\l"
	.string "toute façon.$"

Route34_DayCare_Text_ClerkQuestion:
	.string "Réponds à ma question.\n"
	.string "Que t'inspire cet ŒUF BIZARRE?$"

Route34_DayCare_Text_Rejection:
	.string "Hmm, je crois que cet ŒUF n'est\n"
	.string "pas pour toi.\p"
	.string "Ce serait irresponsable de ma\n"
	.string "part de confier un ŒUF aussi\l"
	.string "précieux à quelqu'un de si peu\l"
	.string "calé sur les BÉBÉS POKéMON!$"

Route34_DayCare_Text_ReceivedOddEgg:
	.string "{PLAYER} reçoit l'ŒUF BIZARRE.$"

Route34_DayCare_Text_TakeCare:
	.string "Je savais que tu étais le bon\n"
	.string "Dresseur. Prends-en bien soin!$"

Route34_DayCare_Text_ClerkAfter:
	.string "On voit beaucoup d'œufs de ce\n"
	.string "genre par ici.\p"
	.string "Celui-là avait pourtant quelque\n"
	.string "chose de différent.$"

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
	.string "MÉTAMORPH: Morph!$"

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_HG_OBTAIN_EGG
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_ClosedForChallenge::
	msgbox Route34_DayCare_Text_ClosedForChallenge, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Text_ClosedForChallenge:
	.string "Désolée, nous ne pouvons pas\n"
	.string "garder ton POKéMON pendant un\l"
	.string "défi à équipe limitée!$"

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Je suis l'HOMME de la PENSION.\p"
	.string "Je m'occupe des précieux POKéMON\n"
	.string "des DRESSEURS.\p"
	.string "Si tu veux que j'élève ton\n"
	.string "POKéMON, parles-en à ma femme.$"

Route34_Text_DoYouWantEgg:
	.string "Ah, c'est toi!\p"
	.string "Nous élevions ton POKéMON et,\n"
	.string "ma foi, quelle surprise!\p"
	.string "Ton POKéMON avait un ŒUF!\p"
	.string "On ignore comment il est arrivé\n"
	.string "là, mais ton POKéMON l'avait.\p"
	.string "Tu le veux, n'est-ce pas?$"

Route34_Text_YourMonIsDoingFine:
	.string "Ah, c'est toi! Content de te\n"
	.string "voir. Ton {STR_VAR_1} va bien.$"

Route34_Text_IllKeepIt:
	.string "Eh bien, je le garde.\n"
	.string "Merci!$"

Route34_Text_YouHaveNoRoomForIt:
	.string "Tu n'as pas de place pour lui…\n"
	.string "Reviens quand tu en auras fait.$"

Route34_Text_ReceivedEgg:
	.string "{PLAYER} reçoit l'ŒUF de\n"
	.string "l'HOMME de la PENSION.$"

Route34_Text_TakeGoodCareOfIt:
	.string "Prends-en bien soin.$"

Route34_Text_FriendlyWithOtherTrainersMon:
	.string "Au fait, ton {STR_VAR_1} avait\n"
	.string "l'air de bien s'entendre avec le\l"
	.string "{STR_VAR_3} de {STR_VAR_2}.\p"
	.string "J'ai même cru le voir recevoir\n"
	.string "une LETTRE.$"

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Si tu veux récupérer ton\n"
	.string "POKéMON, parles-en à ma femme.$"

Route34_Text_YourMonsAreDoingFine:
	.string "Ah, c'est toi! Ton {STR_VAR_1} et\n"
	.string "ton {STR_VAR_2} vont bien.$"

Route34_Text_IWillKeepDoYouWantIt:
	.string "Je vais vraiment le garder.\n"
	.string "Tu le veux, n'est-ce pas?$"

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Je suis la DAME de la PENSION.\p"
	.string "Nous pouvons élever des POKéMON\n"
	.string "pour toi.\p"
	.string "Tu veux qu'on en élève un?$"

Route34_DayCare_Text_WhichMonShouldWeRaise:
	.string "Quel POKéMON devons-nous élever\n"
	.string "pour toi?$"

Route34_DayCare_Text_WellRaiseYourMon:
	.string "Parfait, nous allons élever ton\n"
	.string "{STR_VAR_1} un moment.\p"
	.string "Reviens le chercher plus tard.$"

Route34_DayCare_Text_WeCanRaiseOneMore:
	.string "Nous pouvons élever deux de tes\n"
	.string "POKéMON.\p"
	.string "Tu veux qu'on en élève un autre?$"

Route34_DayCare_Text_HusbandWasLookingForYou:
	.string "Mon mari te cherchait.$"

Route34_DayCare_Text_FineThenComeAgain:
	.string "Oh, très bien.\n"
	.string "Reviens quand tu veux.$"

Route34_DayCare_Text_NotEnoughMoney:
	.string "Tu n'as pas assez d'argent…$"

Route34_DayCare_Text_TakeOtherOneBackToo:
	.string "Tu reprends l'autre aussi?$"

Route34_DayCare_Text_ComeAgain:
	.string "Très bien.\n"
	.string "Reviens quand tu veux.$"

Route34_DayCare_Text_GoodToSeeYou:
	.string "Ah, c'est toi! Contente de te\n"
	.string "voir. Ton POKéMON ne peut que\l"
	.string "bien se porter!$"

Route34_DayCare_Text_YourMonHasGrownXLevels:
	.string "Ton {STR_VAR_1} a gagné\n"
	.string "{STR_VAR_2} niveaux.$"

Route34_DayCare_Text_YourTeamIsFull:
	.string "Ton équipe POKéMON est pleine.\n"
	.string "Fais de la place, puis reviens\l"
	.string "me voir.$"

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
	.string "Quel POKéMON veux-tu reprendre?$"

Route34_DayCare_Text_ItWillCostX:
	.string "Si tu veux récupérer ton\n"
	.string "{STR_VAR_1}, ça coûtera\l"
	.string "¥{STR_VAR_2}.$"

Route34_DayCare_Text_HeresYourMon:
	.string "Parfait!\n"
	.string "Voici ton POKéMON.$"

Route34_DayCare_Text_TookBackMon:
	.string "{PLAYER} reprend {STR_VAR_1} à la\n"
	.string "DAME de la PENSION.$"

Route34_DayCare_Text_YouHaveJustOneMon:
	.string "Oh? Mais tu n'as qu'un seul\n"
	.string "POKéMON.\p"
	.string "Reviens une autre fois.$"

Route34_DayCare_Text_TakeYourMonBack:
	.string "Tu reprends ton POKéMON?$"

Route34_DayCare_Text_WhatWillYouBattleWith:
	.string "Si tu me laisses ce POKéMON,\n"
	.string "avec quoi vas-tu combattre?\p"
	.string "Reviens une autre fois.$"

Route34_DayCare_Text_YoullBeLeftWithJustOne:
	.string "Hein?\n"
	.string "Allons, allons.\p"
	.string "Si tu me laisses ce POKéMON, il\n"
	.string "ne t'en restera qu'un seul.\p"
	.string "Tu ferais mieux d'en attraper\n"
	.string "d'autres, j'ose le dire.$"
