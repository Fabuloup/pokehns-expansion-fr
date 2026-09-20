SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "MORGANE : Je savais que tu venais…\p"
	.string "Il y a trois ans, j'ai eu une\n"
	.string "vision de ton arrivée.\p"
	.string "Tu convoites mon BADGE.\p"
	.string "Je n'aime pas combattre, mais mon\n"
	.string "devoir de CHAMPIONNE est de donner\l"
	.string "un BADGE à quiconque s'en montre\l"
	.string "digne.\p"
	.string "Puisque tu le souhaites, je vais\n"
	.string "te montrer mon pouvoir psychique !$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "MORGANE : Ton pouvoir…\p"
	.string "Il dépasse de loin mes prévisions…\p"
	.string "Peut-être est-il impossible de\n"
	.string "tout prédire de l'avenir…\p"
	.string "D'accord, tu gagnes. Tu mérites\n"
	.string "le BADGE MARAIS.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} reçoit le BADGE MARAIS.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "MORGANE : Le BADGE MARAIS révèle\n"
	.string "tes pouvoirs subliminaux…\p"
	.string "Même si j'ai mal prédit ta\n"
	.string "puissance, je sais une chose\l"
	.string "avec certitude.\p"
	.string "Tu deviendras un MAÎTRE célèbre\n"
	.string "et bien-aimé !$"

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "Tiens, prends aussi ceci.$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "Elle contient ÉCHANGE.\p"
	.string "Cette capacité échange ton talent\n"
	.string "avec celui de l'adversaire.\p"
	.string "Utilise-la judicieusement...$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "MORGANE : Ton amour pour tes\n"
	.string "POKéMON a surpassé mes pouvoirs\l"
	.string "psychiques…\p"
	.string "Le pouvoir de l'amour est aussi,\n"
	.string "je crois, un pouvoir psychique…$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "MORGANE : Ah, le MAÎTRE de KANTO.\p"
	.string "J'ai senti ton retour.\p"
	.string "Ton pouvoir a énormément grandi.\p"
	.string "Même maintenant, je sens ton aura.\p"
	.string "Tu veux une revanche ?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "MORGANE : Ton amour pour tes\n"
	.string "POKéMON a encore surpassé mes\l"
	.string "pouvoirs psychiques…$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "La puissance de tous ceux que\n"
	.string "tu as vaincus vient à moi !$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Fort… Bien trop fort…$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "D'où vient ton pouvoir ?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "Le pouvoir psychique est celui\n"
	.string "de ton âme.$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "Ton âme est plus puissante que\n"
	.string "la mienne !$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "Tu as renforcé ton âme, pas\n"
	.string "seulement tes capacités.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "Fufufufu… Je le vois clairement.\p"
	.string "Je peux voir dans ton âme !$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "Même en te lisant, j'ai perdu…$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "Zut ! J'avais oublié avoir prédit\n"
	.string "ma défaite face à toi.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "Le DOJO voisin était autrefois\n"
	.string "l'ARÈNE de cette ville.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "Je ne faisais pas le poids…$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "Le MAÎTRE KARATÉ, chef du DOJO,\n"
	.string "a été totalement écrasé par\l"
	.string "MORGANE.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "Yo, futur MAÎTRE !\p"
	.string "Un Dresseur aussi doué que toi\n"
	.string "n'a pas besoin qu'on lui explique\l"
	.string "comment affronter les POKéMON\l"
	.string "PSY, pas vrai ?\p"
	.string "J'attends beaucoup de toi !\p"
	.string "Bonne chance !$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "Encore un combat fantastique !$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE SAFRANIA\n"
    .string "CHAMPIONNE : MORGANE\p"
	.string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE SAFRANIA\n"
    .string "CHAMPIONNE : MORGANE\p"
    .string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED, {PLAYER}$"
