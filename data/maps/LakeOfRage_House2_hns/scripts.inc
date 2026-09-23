LakeOfRage_House2_hns_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "Le LAC COLÈRE est en fait un\n"
    .string "cratère creusé par des LÉVIATOR.\p"
    .string "La pluie a rempli le cratère,\n"
    .string "formant ainsi le LAC.\p"
    .string "C'est l'histoire transmise par\n"
    .string "l'aïeul de mon grand-père.\p"
    .string "Autrefois, on y pêchait de\n"
    .string "vigoureux MAGICARPE, mais...\p"
    .string "Je ne comprends pas ce qui arrive.$"

LakeOfRage_House2_Text_MenInBlack:
    .string "Le LAC n'est plus normal depuis\n"
    .string "l'arrivée de ces hommes en noir.$"

LakeOfRage_House2_Text_LastMon:
    .string "Ne me donne pas ton dernier\n"
    .string "POKéMON!$"

LakeOfRage_House2_Text_WorldsLargest:
    .string "Le LAC COLÈRE est redevenu normal.\p"
    .string "Les MAGICARPE sont revenus.\p"
    .string "Je peux encore réaliser mon rêve:\n"
    .string "avoir le plus grand MAGICARPE.\p"
    .string "Je paierai 2 000¥ pour chaque\n"
	.string "MAGICARPE donné et 100 000¥ pour\l"
	.string "un MAGICARPE ÉNORME!$"

LakeOfRage_House2_Text_ForMe:
	.string "Alors... As-tu un MAGICARPE pour\n"
	.string "moi?$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "Ah, tu as un MAGICARPE! Voyons\n"
    .string "la taille de ce petit.$"

LakeOfRage_House2_Text_BigPayout:
    .string "Waouh! Celui-ci est exceptionnel!\p"
    .string "Je te tire mon chapeau!\p"
    .string "Voici un petit quelque chose pour\n"
	.string "tes efforts.$"

LakeOfRage_House2_Text_Bonus:
    .string "Le record est le plus important.\p"
    .string "Considère ceci comme un bonus!$"

LakeOfRage_House2_Text_TooShort:
    .string "Waouh! Celui-ci est exceptionnel!\p"
    .string "...J'aimerais le dire, mais j'en\n"
    .string "ai déjà vu un plus grand.\p"
    .string "Il vaut quand même quelque chose.$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "Quoi? Ce n'est pas un MAGICARPE!$"

LakeOfRage_House2_Text_Refused:
    .string "Oh... Tu n'en as pas trouvé un\n"
    .string "à me montrer? Une autre fois.$"
