PalletTown_Lab_hns_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_ROUTE28_SCIENTIST, 1
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "Comment avance ton POKéDEX?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "PROF.CHEN: Ah, {PLAYER}!\n"
	.string "C'est gentil d'être venu jusqu'à\l"
	.string "KANTO.\p"
	.string "Que penses-tu des Dresseurs\n"
	.string "d'ici? Ils sont coriaces, hein?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "Si tu repasses dans le coin,\n"
	.string "viens me revoir.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "PROF.CHEN: Ouah! Excellent!\p"
	.string "Tu as réuni les BADGES des ARÈNES\n"
	.string "de KANTO. Bravo!\p"
	.string "Je ne m'étais pas trompé\n"
	.string "sur ton compte.\p"
	.string "Écoute, {PLAYER}. Je vais faire\n"
	.string "le nécessaire pour que tu puisses\l"
	.string "aller au MONT ARGENTÉ.\p"
	.string "C'est une montagne où vivent\n"
	.string "de nombreux POKéMON sauvages.\p"
	.string "Elle est trop dangereuse pour un\n"
	.string "Dresseur ordinaire, donc fermée.\l"
	.string "Mais pour toi, nous pouvons faire\l"
	.string "une exception, {PLAYER}.\p"
	.string "Va au PLATEAU INDIGO. Tu pourras\n"
	.string "rejoindre le MONT ARGENTÉ de là.$"

PalletTown_Lab_Text_OakOpenIndigoPlateau:
	.string "Oh, à propos du PLATEAU INDIGO,\n"
	.string "avec tes 16 BADGES, la LIGUE de\l"
	.string "KANTO acceptera de nouveau\l"
	.string "ton défi pour le titre de\l"
	.string "CHAMPION.\p"
	.string "Mais attention, PETER et son\n"
	.string "CONSEIL 4 ne te feront aucun\l"
	.string "cadeau cette fois.\p"
	.string "Bonne chance, {PLAYER}!$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "PROF.CHEN: Hum? Tu ne cherches pas\n"
	.string "les BADGES des ARÈNES de KANTO?\p"
	.string "Les CHAMPIONS de KANTO sont aussi\n"
	.string "forts que ceux affrontés à JOHTO.\p"
	.string "Je te conseille de les défier.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "PROF.CHEN: Ah, tu réunis les\n"
	.string "BADGES des ARÈNES de KANTO.\p"
	.string "Ce doit être dur, mais cette\n"
	.string "expérience te sera très utile.\p"
	.string "Reviens quand tu les auras tous.\p"
	.string "J'aurai un cadeau pour toi.\p"
	.string "Courage, {PLAYER}!$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "L'émission radio POKéMON du PROF\n"
	.string "n'est pas diffusée à KANTO.\p"
	.string "Dommage, j'aimerais l'écouter.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Grâce à ton travail sur le POKéDEX\n"
	.string "les recherches du PROF avancent\l"
	.string "très bien.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "Ne le répète pas, mais l'émission\n"
	.string "du PROF.CHEN n'est pas en direct.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "Il y a un e-mail sur le PC.\p"
	.string "…\p"
	.string "PROF.CHEN, comment avancent vos\n"
	.string "recherches?\p"
	.string "De mon côté, je m'accroche.\p"
	.string "Il paraît que {PLAYER} commence\n"
	.string "à se faire un nom.\p"
	.string "J'en suis ravi.\p"
	.string "ORME, de BOURG GEON 8-)$"
