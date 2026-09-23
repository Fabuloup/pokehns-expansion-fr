DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}… Alors, tu es là.\p"
    .string "Si tu penses pouvoir me suivre,\n"
    .string "rejoins-moi au DOJO de\l"
    .string "SAFRANIA.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
    .string "SANDRA: ATTENDS!\p"
    .string "Je suis désolée pour tout ça.\n"
    .string "Prends ceci en guise d'excuse.$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
    .string "DRACO-CHOC est une sorte de… euh…\n"
    .string "Laisse tomber!\p"
    .string "C'est une énorme vague d'énergie.\p"
    .string "Si tu n'en veux pas, tu n'es pas\n"
    .string "obligé de le prendre.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "Qu'y a-t-il? Tu ne vas pas\n"
    .string "à la LIGUE POKéMON?\l"
    .string "Vraiment?\p"
    .string "Une fois devenu MAÎTRE, tu\n"
    .string "pourras affronter à nouveau le\l"
    .string "CHAMPION de chaque ARÈNE.\p"
    .string "Va à la LIGUE POKéMON.\p"
    .string "Tu sais comment y aller?\p"
    .string "D'ici, va à BOURG GEON.\p"
    .string "Puis SURFE à l'est vers la LIGUE.\p"
    .string "La route est très difficile.\p"
    .string "Ne perds surtout pas à la LIGUE\n"
    .string "POKéMON!\p"
    .string "Sinon, ma défaite contre toi me\n"
    .string "fera encore plus mal!\p"
    .string "Donne tout ce que tu as.$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "AUTEL DRAGON En\p"
    .string "l'honneur des\n"
    .string "POKéMON dragons\p"
    .string "ayant vécu dans\n"
    .string "l'ANTRE du DRAGON.$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "…\n"
    .string "Quoi? {PLAYER}?\p"
    .string "…Non, je ne t'affronterai pas…\p"
    .string "Mes POKéMON ne sont pas prêts à\n"
    .string "te battre.\p"
    .string "Je ne peux pas trop les pousser.\p"
	.string "Je dois me discipliner pour être\n"
    .string "le plus grand des DRESSEURS…$"

DragonsDen_Cavern_Text_SilverTraining2:
    .string "....... Pffouiii...\p"
    .string "Ne croise plus\p"
    .string "jamais ma route...$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "Toi! Tu n'as pas le\n"
    .string "droit d'entrer ici!$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "Quelle puissance!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "Le TEMPLE est la demeure de notre\n"
    .string "MAÎTRE, chef du clan des dragons.\p"
    .string "Tu n'as pas le droit d'entrer!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "Tu n'as rien à faire ici!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "Inconcevable!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "Je vais bientôt avoir l'accord\n"
    .string "du MAÎTRE pour utili- ser des\p"
    .string "dragons. Et alors, je pour-\n"
    .string "rai rendre mon MAÎTRE fier en\l"
    .string "devenant un grand dresseur.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "On ne connaît pas cet inconnu.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "Ouille.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "J'ai eu l'impression\n"
    .string "de combattre Peter.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "Qui es-tu?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "Pas sympa.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "On va le dire! Le Maître\p"
    .string "ne sera pas content!$"
