CeladonCity_Gym_hns_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA_HNS, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_Erika_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	msgbox CeladonCity_Gym_Text_Erika_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA: Bonjour... Belle\n"
	.string "journée, non? C'est beau\p"
	.string "la vie. Moi je suis ERIKA,\p"
	.string "CHAMPIONNE de l'ARÈNE\n"
	.string "de CELADO- POLE. ...Oh?\p"
	.string "Tu viens de JOHTO? C'est\n"
	.string "bien... ...Quoi? Tu\p"
	.string "veux te battre? Mais il\n"
	.string "faut le dire!!! J'vais\p"
	.string "te casser ta face!!!$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA: Oh! J'ai perdu... Toi\p"
	.string "t'es un p'tit tigre... Voilà\p"
	.string "pour toi: le BADGE PRISME...$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} reçoit le BADGE PRISME.$"

CeladonCity_Gym_Text_Erika_GiveTM:
	.string "ERIKA: Ce combat était tout à fait\n"
	.string "charmant.\p"
	.string "Il m'a inspirée. Je souhaite que\n"
	.string "vous preniez cette CT.$"

CeladonCity_Gym_Text_Erika_ExplainTM:
	.string "Elle contient GIGA-SANGSUE.\p"
	.string "Cette capacité draine la moitié\n"
	.string "des dégâts infligés afin de\l"
	.string "soigner votre POKéMON.\p"
	.string "Utilisez-la si vous le souhaitez…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "ERIKA: La défaite laisse un goût\n"
	.string "amer…\p"
	.string "Rencontrer des DRESSEURS forts\n"
	.string "me pousse à progresser…$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA: Oh, bonjour.\p"
	.string "Quelle surprise, MAÎTRE DE KANTO!\p"
	.string "Quel plaisir de vous revoir.\p"
	.string "Votre voyage a dû être vraiment\n"
	.string "passionnant.\p"
	.string "Même les Maîtres aiment les défis.\p"
	.string "Voulez-vous une revanche?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA: La défaite laisse toujours\n"
	.string "un goût amer…\p"
	.string "Rencontrer des DRESSEURS forts\n"
	.string "me pousse à progresser…$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE_HNS, CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "Ça t'étonne, une Arène\n"
	.string "remplie de filles?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "Ouiiiiin!$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "J'ai juste manqué d'attention!$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA_HNS, CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "Un combat? Heu...non.\n"
	.string "... Allez, d'accord!$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "C'est fini?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "T'en as plein des BADGES.\n"
	.string "Comment je pouvais gagner, moi?!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_HNS, CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "Tu regardes les fleurs ou\n"
	.string "c'est moi que tu mates?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "C'est pas bien!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "Comment devenir une\n"
	.string "belle fille comme ERIKA?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "ERIKA nous a ap-\n"
	.string "pris plein de trucs!$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Oh... On a perdu.$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "ERIKA! Venge-nous!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "On doit protéger la grande ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "Nooooonn....$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "ERIKA est bien plus forte!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CÉLADOPOLE\n"
    .string "CHAMPIONNE: ERIKA\p"
    .string "VAINQUEURS:\n"
    .string "BLUE, RED$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CÉLADOPOLE\n"
    .string "CHAMPIONNE: ERIKA\p"
    .string "VAINQUEURS:\n"
    .string "BLUE, RED, {PLAYER}$"
