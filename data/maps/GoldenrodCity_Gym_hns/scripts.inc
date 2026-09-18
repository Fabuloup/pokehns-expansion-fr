GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON de DOUBLONVILLE$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON de DOUBLONVILLE\p"
	.string "DRESSEURS AGRÉÉS PAR BLANCHE:\n"
	.string "{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
    .string "Salut! Je suis BLANCHE!\p"
    .string "Tout le monde était à fond dans\n"
    .string "les POKéMON, alors moi aussi!\p"
    .string "Les POKéMON sont trop mignons!\p"
    .string "Tu veux te battre? Je te préviens,\n"
    .string "je suis douée!$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
    .string "Snif…\p"
    .string "…Ouiiiiiin! T'es méchant!\p"
    .string "Faut pas être sérieux comme ça!\n"
    .string "Espèce de… de gamin!$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
    .string "Ouiiiiiin!\p"
    .string "Ouiiiiiin!\p"
    .string "…Snif, hic… …Méchant!$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
    .string "…Snif…\p"
    .string "Quoi? Qu'est-ce que tu veux?\n"
    .string "Un BADGE?\p"
    .string "Ah oui, c'est vrai. J'avais\n"
    .string "oublié. Voici le BADGE PLAINE.$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
    .string "{PLAYER} reçoit le BADGE PLAINE.$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
    .string "Le BADGE PLAINE permet à tes\n"
    .string "POKéMON d'utiliser FORCE hors\l"
    .string "des combats.\p"
    .string "Il augmente aussi la DÉFENSE de\n"
	.string "tes POKéMON.\p"
    .string "Oh, tu peux prendre ça aussi!$"

GoldenrodCity_Gym_Text_WhitneyAttract:
    .string "C'est ATTRACTION! Elle exploite\n"
    .string "tout le charme d'un POKéMON.\p"
    .string "Parfait pour une mignonne comme\n"
    .string "moi, non?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
    .string "Ah, ça fait du bien de pleurer!$"

GoldenrodCity_Gym_Text_WhitneyRematch:
    .string "Salut! C'est toi!\p"
    .string "Ouah, MAÎTRE de JOHTO maintenant?\p"
    .string "Tu es vraiment incroyable!\p"
    .string "Je veux voir à quel point tu es\n"
    .string "fort.\p"
    .string "Ça te dit, une revanche?$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "Ouiiiiiin!\p"
    .string "Ouiiiiiin!\p"
    .string "…Snif, hic… …Méchant!$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "Ne te fie pas à l'air mignon de\n"
    .string "mes POKéMON.\p"
    .string "Ils peuvent te réduire en miettes!$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "Zut… Je te croyais faible…$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "Mes POKéMON me trouvent mignonne?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
    .string "Je préfère les POKéMON mignons\n"
    .string "aux POKéMON forts.\p"
    .string "Mais les miens sont forts ET\n"
    .string "mignons!$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
    .string "Oh non, non, non!$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
    .string "J'essaie de battre BLANCHE,\n"
    .string "mais… C'est déprimant.\p"
    .string "Ça va! Si je perds, je\n"
    .string "m'entraînerai plus la prochaine\l"
    .string "fois!$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
    .string "Oh non. Tu as fait pleurer\n"
    .string "BLANCHE.\p"
    .string "Ce n'est rien. Elle va s'arrêter.\n"
    .string "Elle pleure toujours quand elle\l"
    .string "perd.$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
    .string "Oh, quel mignon petit Dresseur!\p"
    .string "Je t'aime bien, mais je ne vais\n"
    .string "rien te laisser!$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
    .string "Voyons voir… Oups, c'est fini?$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
    .string "Ouah, tu dois être fort pour\n"
    .string "m'avoir battue! Continue!$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
    .string "Donne tout ce que tu as, sinon\n"
    .string "je t'écrase!$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
    .string "Non! Oh, MIAOUSS, pardon!$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
    .string "J'ai appris à MIAOUSS des\n"
    .string "capacités pour tous les types…$"

GoldenrodCity_Gym_Text_GymGuide:
    .string "Yo! Futur MAÎTRE!\p"
    .string "Cette ARÈNE est celle de\n"
    .string "BLANCHE, spécialiste des POKéMON\l"
    .string "de type NORMAL.\p"
    .string "Méfie-toi de son équipe mignonne.\p"
    .string "Certains POKéMON de cette ARÈNE\n"
    .string "sont aussi du tout nouveau type\l"
    .string "FÉE.\p"
    .string "Va voir ROUTE 34 s'il te faut du\n"
    .string "type COMBAT ou POISON.$"

GoldenrodCity_Gym_Text_GymGuideWin:
    .string "Tu as gagné? Super! J'étais trop\n"
    .string "occupé à admirer ces dames.$"

