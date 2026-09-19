LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE_HNS
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_HNS
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
    .string "{PLAYER}.\p"
    .string "Même ici, le froid m'endurcit.\p"
    .string "Si tu veux m'affronter à nouveau,\n"
    .string "viens au DOJO.$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE_HNS, LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND_HNS, LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON_HNS, LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS_HNS, LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Secret_Power::
    finditem ITEM_TM_SECRET_POWER
    end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "DRACOLOSSE: Gyafooha!$"

LakeOfRage_Text_LanceForcedToEvolve:
    .string "Ce lac regorge de LÉVIATOR,\n"
    .string "mais de rien d'autre…\p"
    .string "Les MAGIKARP sont donc forcés\n"
    .string "d'évoluer…$"

LakeOfRage_Text_LanceIntro1:
    .string "Les rumeurs t'ont amené\n"
    .string "ici?\p"
    .string "Tu es {PLAYER}? Je suis PETER,\n"
    .string "un Dresseur comme toi.$"

LakeOfRage_Text_LanceIntro2:
    .string "Cet homme m'a parlé\n"
    .string "de certaines rumeurs.\p"
    .string "Nous sommes donc venus enquêter…$"

LakeOfRage_Text_LanceIntro3:
    .string "J'ai vu ton combat\n"
    .string "tout à l'heure, {PLAYER}.\p"
    .string "Tu es visiblement un Dresseur\n"
    .string "très compétent.\p"
	.string "Peux-tu nous aider\n"
    .string "à enquêter?$"

LakeOfRage_Text_LanceRadioSignal:
    .string "PETER: Excellent!\p"
    .string "Il semble que les MAGIKARP du LAC\n"
    .string "soient forcés d'évoluer.\p"
    .string "Un étrange signal radio\n"
	.string "venu d'ACAJOU en est la cause.\p"
    .string "Nous t'attendrons,\n"
    .string "{PLAYER}.$"

LakeOfRage_Text_LanceRefused:
    .string "Oh… Si tu changes d'avis,\n"
    .string "viens nous aider.$"

LakeOfRage_Text_LanceAskHelp:
    .string "PETER: Hum? Tu vas nous aider\n"
    .string "alors?$"

LakeOfRage_Text_GyaradosCry:
    .string "LÉVIATOR: Gyashaa!$"

LakeOfRage_Text_Gramps:
    .string "Les LÉVIATOR sont furieux!\p"
    .string "C'est un mauvais présage!$"

LakeOfRage_Text_GrampsCleared:
    .string "Hahah! Les MAGIKARP mordent!$"

LakeOfRage_Text_SuperNerd:
	.string "On dit que ce lac fut créé\n"
    .string "par des LÉVIATOR déchaînés.\p"
    .string "Je me demande s'il y a un\n"
    .string "lien avec leur invasion\l"
    .string "actuelle?$"

LakeOfRage_Text_CooltrainerF:
	.string "Ai-je rêvé? J'ai vu un\n"
    .string "LÉVIATOR rouge dans le LAC…\p"
    .string "Mais les LÉVIATOR ne sont-ils pas\n"
    .string "d'ordinaire bleus?$"


LakeOfRage_Text_FisherAndreSeen:
	.string "Combattons avec le POKéMON\n"
    .string "que je viens d'attraper!$"

LakeOfRage_Text_FisherAndreBeaten:
	.string "Je suis pêcheur expert,\n"
	.string "mais piètre Dresseur de POKéMON…$"

LakeOfRage_Text_FisherAndreAfter:
    .string "À la pêche, je ne perds jamais! Je\n"
	.string "pêche des POKéMON sans arrêt.$"


LakeOfRage_Text_FisherRaymondSeen:
    .string "Quoi que je fasse, je ne prends\n"
    .string "que les mêmes POKéMON…$"

LakeOfRage_Text_FisherRaymondBeaten:
    .string "Ma ligne est toute emmêlée…$"

LakeOfRage_Text_FisherRaymondAfter:
	.string "Pourquoi je ne prends rien de bon\n"
    .string "POKéMON?$"

LakeOfRage_Text_CooltrainermAaronSeen:
    .string "Si un Dresseur en voit un autre,\n"
    .string "il doit le défier.\p"
    .string "Tel est notre destin.$"

LakeOfRage_Text_CooltrainermAaronBeaten:
    .string "Ouf… Beau combat.$"

LakeOfRage_Text_CooltrainermAaronAfter:
	.string "POKéMON et Dresseur gagnent\n"
	.string "en force à chaque combat.$"

LakeOfRage_Text_CooltrainerfLoisSeen:
    .string "Qu'est devenu le LÉVIATOR\n"
    .string "rouge?\p"
    .string "Il est parti?\p"
    .string "Oh, zut. Je suis venue pour\n"
    .string "rien?\p"
    .string "Je sais! Battons-nous!$"

LakeOfRage_Text_CooltrainerfLoisBeaten:
    .string "Bien joué!$"

LakeOfRage_Text_CooltrainerfLoisAfter:
    .string "À bien y penser, j'ai déjà vu un\n"
    .string "PAPILUSION rose.$"



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
    .string "WESLEY: Eh bien, bonjour!\p"
    .string "Je suis de la famille SEMAINE!\n"
    .string "Devine quel jour je préfère?$"

LakeOfRage_Text_WesleyGivesGift:
    .string "Enchanté. Accepte donc ce\n"
    .string "souvenir.$"

LakeOfRage_Text_WesleyGaveGift:
    .string "WESLEY: La CEINTURE NOIRE renforce\n"
    .string "les capacités de type Combat.$"

LakeOfRage_Text_WesleyWednesday:
    .string "WESLEY: Puisque tu m'as trouvé, tu\n"
    .string "as dû rencontrer mes frères et\l"
    .string "sœurs.\p"
    .string "Ou était-ce un coup de chance?$"

LakeOfRage_Text_WesleyNotWednesday:
    .string "WESLEY: Pas exactement...$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
    .string "LAC COLÈRE,\n"
    .string "aussi appelé LAC LÉVIATOR.$"

LakeOfRage_Text_FishingGuruSign:
    .string "MAISON DU MAÎTRE PÊCHEUR$"
