Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "TEA: LEA et moi sommes\n"
	.string "inséparables!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "TEA & LEA: Nnn… Un peu trop\n"
	.string "fort.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "TEA: Je devine ce que pensent ma\n"
	.string "soeur et mes POKéMON.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "LEA: TEA et moi sommes\n"
	.string "inséparables!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "TEA & LEA: Nnn… Un peu trop\n"
	.string "fort.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "LEA: Nous partageons les mêmes\n"
	.string "sentiments que nos POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "Un POKéMON endormi ne peut rien\n"
	.string "faire.\p"
	.string "Je vais te montrer à quel point\n"
	.string "c'est terrifiant!$"

Route37_Text_PsychicGreg_Beaten:
	.string "J'ai perdu. C'est bien triste…$"

Route37_Text_PsychicGreg_After:
	.string "Endormir ou paralyser les POKéMON\n"
	.string "sont de bonnes tactiques.$"

Route37_Text_Sunny_Meet:
	.string "DIMITRI: Salut!\p"
	.string "Moi c'est DIMITRI, de la FAMILLE\n"
	.string "DES JOURS!\p"
	.string "Si tu devines mon jour préféré,\n"
	.string "tu auras une récompense.$"

Route37_Text_Sunny_GiveGift1:
	.string "On m'a dit de te donner ceci si\n"
	.string "je te voyais!$"

Route37_Text_Sunny_GiveGift2:
	.string "On m'a dit de te donner ceci si\n"
	.string "je te voyais!$"

Route37_Text_Sunny_GaveGift:
	.string "DIMITRI: Ce truc…\p"
	.string "Euh…\p"
	.string "… C'était quoi déjà…\p"
	.string "…\p"
	.string "Oh! Je me souviens!\p"
	.string "Un POKéMON qui connaît des\n"
	.string "capacités ÉLECTRIK devrait le\l"
	.string "tenir.\p"
	.string "Ma soeur LUCIE dit que ça\n"
	.string "renforce les capacités ÉLECTRIK!$"

Route37_Text_Sunny_Sunday:
	.string "DIMITRI: Mes frères et soeurs\n"
	.string "sont LUCIE, MARIE, HOMER, JÉROME,\l"
	.string "VANESSA et SAMUEL.\p"
	.string "Ils sont tous plus vieux que moi!$"

Route37_Text_Sunny_NotSunday:
	.string "DIMITRI: On n'est pas dimanche?\n"
	.string "Euh… J'ai oublié!$"

Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ROSALIA TOUT DROIT$"
