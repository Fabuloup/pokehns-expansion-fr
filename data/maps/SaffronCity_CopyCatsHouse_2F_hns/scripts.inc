SaffronCity_CopyCatsHouse_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_CopyCatsHouse_2F_OnTransition
	.byte 0

SaffronCity_CopyCatsHouse_2F_OnTransition::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	end

@VAR_FAN_CLUB_CLEFAIRY

SaffronCity_CopyCatsHouse_2F_EventScript_Dodrio::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODRIO, CRY_MODE_NORMAL
	msgbox Copycat_Text_Dodrio1, MSGBOX_DEFAULT
	waitmoncry
	msgbox Copycat_Text_Dodrio2, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Dolls::
	msgbox Copycat_Text_2FDoll, MSGBOX_SIGN
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 3, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 2, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnDoll
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Female

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_1, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_QuickMimicking, MSGBOX_NPC
	closemessage
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_1, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_QuickMimicking, MSGBOX_NPC
	closemessage
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Female

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_2, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Worried, MSGBOX_NPC
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 1
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_2, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Worried, MSGBOX_NPC
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 1
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnDoll::
	msgbox Copycat_Text_GiveDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	removeitem ITEM_LOST_ITEM
	clearflag FLAG_HIDE_COPYCAT_CLEFAIRY_DOLL
	addobject LOCALID_COPYCAT_CLEFAIRY
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Copycat_Text_GivePass, MSGBOX_DEFAULT
	giveitem ITEM_PASS
	msgbox Copycat_Text_ExplainPass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 3
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Female

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_3, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_ItsAScream, MSGBOX_NPC
	closemessage
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_3, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_ItsAScream, MSGBOX_NPC
	closemessage
	end

Copycat_Text_Male_1:
	.string "{PLAYER} : Tu aimes les POKéMON ?\p"
	.string "{PLAYER} : Non, c'est moi !\p"
	.string "{PLAYER} : Hein ? Tu es bizarre !$"

Copycat_Text_QuickMimicking:
	.string "COPIEUSE : Cesser d'imiter ?\p"
	.string "Mais c'est mon hobby préféré !$"

Copycat_Text_Male_2:
	.string "{PLAYER} : J'ai appris que tu\n"
	.string "avais perdu ta POKéPOUPÉE.\p"
	.string "{PLAYER} : Si je la trouve,\n"
	.string "tu me donnes un PASSE ?\p"
	.string "{PLAYER} : Je vais te la retrouver.\p"
	.string "Tu crois l'avoir perdue en allant\n"
	.string "à CARMIN SUR MER ?$"

Copycat_Text_Worried:
	.string "COPIEUSE : Pardon ?\p"
	.string "Je ne devrais pas décider de ce\n"
	.string "que tu dois faire ?\p"
	.string "Mais je m'inquiète… Et si\n"
	.string "quelqu'un la trouvait ?$"

Copycat_Text_GiveDoll:
	.string "COPIEUSE : Youpi ! C'est ma\n"
	.string "POKéPOUPÉE MÉLOFÉE !\p"
	.string "Tu vois l'accroc à la couture de\n"
	.string "la patte droite ? La preuve !$"

Copycat_Text_GivePass:
	.string "OK. Voici le PASSE du TRAIN\n"
	.string "MAGNÉTIQUE, comme promis !$"

Copycat_Text_ExplainPass:
	.string "COPIEUSE : C'est le PASSE du\n"
	.string "TRAIN MAGNÉTIQUE.\p"
	.string "Un employé des chemins de fer me\n"
	.string "l'a donné quand ils ont rasé notre\l"
	.string "vieille maison pour la GARE.$"

Copycat_Text_Male_3:
	.string "{PLAYER} : Merci beaucoup pour\n"
	.string "le PASSE !\p"
	.string "{PLAYER} : Pardon ?\p"
	.string "{PLAYER} : C'est drôle d'imiter\n"
	.string "tous mes gestes ?$"

Copycat_Text_ItsAScream:
	.string "COPIEUSE : Oui ! Très drôle !$"

Copycat_Text_Dodrio1:
	.string "DODRIO : Gii giii !$"

Copycat_Text_Dodrio2:
	.string "MIROIR, MIROIR AU MUR,\n"
	.string "QUI EST LA PLUS BELLE ?$"

Copycat_Text_2FDoll:
	.string "C'est un POKéMON rare ! Hein ?\p"
	.string "Ce n'est qu'une poupée…$"
