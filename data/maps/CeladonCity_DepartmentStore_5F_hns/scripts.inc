CeladonCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FRUSTRATION, CeladonDeptStore5_EventScript_Receptionist_Already
	msgbox CeladonDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, FRIENDSHIP_50_TO_99, CeladonDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	msgbox CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_Already::
	msgbox CeladonDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore_Text_5FReceptionistOhYourMon:
    .string "Bonjour. Oh, ton POKéMON…$"

CeladonDeptStore_Text_5FReceptionistWait:
    .string "Attends, je t'ai déjà donné\n"
    .string "cette CT!$"

CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "Ce n'est pas mal, mais ce n'est\l"
	.string "pas bon non plus.\p"
	.string "Toi, le DRESSEUR, tu dois y\n"
	.string "mettre plus d'efforts.$"

CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "Il a l'air maléfique. Que dis-tu\n"
    .string "de cette CT en échange?$"

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "{PLAYER}. Je ne m'attendais pas\n"
	.string "à te voir ici.\p"
	.string "Je viens chercher du matériel\n"
	.string "pour mes POKéMON Oiseau.\p"
	.string "Si tu veux m'affronter à\n"
	.string "nouveau, je serai au DOJO de\l"
	.string "SAFRANIA.$"

CeladonDeptStore5F_Text_Gentleman:
	.string "Je veux acheter des objets qui\n"
	.string "augmentent les stats des\l"
	.string "POKéMON, mais je n'ai pas assez\l"
	.string "d'argent…$"

CeladonDeptStore5F_Text_Sailor:
	.string "Je veux des PP PLUS pour\n"
	.string "augmenter les PP des capacités.\l"
	.string "Mais ça ne s'achète pas…$"

CeladonDeptStore5F_Text_Teacher:
	.string "Utiliser des objets sur eux rend\n"
	.string "les POKéMON heureux.\p"
	.string "Mais ils détestent certains\n"
	.string "objets…$"

CeladonDeptStore5F_Text_Directory:
	.string "5F: PHARMACIE$"
