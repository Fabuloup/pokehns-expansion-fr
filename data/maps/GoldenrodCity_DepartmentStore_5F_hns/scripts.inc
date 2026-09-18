GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "Bonjour. Oh, votre POKéMON…$"

GoldenrodDeptStore_Text_5FReceptionistWait:
    .string "Attendez, je vous ai déjà donné\n"
    .string "cette CT!$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "Pas mal, mais pas terrible.\p"
	.string "En tant que DRESSEUR, vous devez\n"
	.string "faire plus d'efforts.$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "Il vous est très attaché.\p"
    .string "Cette capacité devrait être\n"
    .string "parfaite pour un duo comme vous.$"

GoldenrodDeptStore_Text_5FLass:
    .string "En journée, une dame vient\n"
    .string "examiner les POKéMON.\p"
    .string "Elle offre même des CT!$"

GoldenrodDeptStore_Text_5FPokefanM:
    .string "On ne peut pas renommer un\n"
    .string "POKéMON obtenu par échange.\p"
    .string "Son nom reflète les sentiments de\n"
    .string "son Dresseur d'origine.$"

GoldenrodDeptStore_Text_Girl:
	.string "La dame m'a donné RETOUR!\n"
    .string "Mon POKéMON m'aime vraiment!$"

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
    .string "Personnalisez vos POKéMON\p"
    .string "5F COIN DES CT$"
