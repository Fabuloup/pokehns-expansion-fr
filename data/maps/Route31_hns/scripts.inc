Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "L'ANTRE NOIRE…\p"
	.string "Si un POKéMON pouvait l'éclairer,\n"
	.string "je l'explorerais.$"

Route31_Text_BugCatcherWade1_Seen:
	.string "J'ai attrapé plein de POKéMON.\n"
	.string "Affronte-moi!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "Aaaaaaaaah!$"

Route31_Text_BugCatcherWade1_After:
	.string "Tu peux attraper des POKéMON même\n"
	.string "si tu en as déjà six sur toi.\p"
	.string "Ils seront envoyés automatiquement\n"
	.string "dans ta BOÎTE.$"

Route31_Text_SleepyMan:
	.string "… Nnngneuh… Hein?\p"
	.string "J'ai trop marché aujourd'hui\n"
	.string "en cherchant des POKéMON.\p"
	.string "J'ai mal aux pieds et sommeil…\p"
	.string "Si j'étais un POKéMON sauvage,\n"
	.string "je serais facile à attraper…\p"
	.string "…Zzzz…$"

Route31_Text_SleepyManGotMail:
	.string "…Zzzz… Hein?\p"
	.string "Quoi? Tu as une LETTRE\n"
	.string "pour moi?$"

Route31_Text_SleepyManFail:
	.string "…Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} confie le POKéMON\n"
	.string "qui tient la LETTRE.$"

Route31_Text_ReadingMail:
	.string "Voyons voir…\p"
	.string "Merci de me l'avoir apportée.\p"
	.string "Mon ami est quelqu'un de bien,\n"
	.string "et toi aussi!\p"
	.string "J'aimerais te rendre la pareille!\p"
	.string "Je sais! Prends donc ceci!$"

Route31_Text_DescribeRest:
	.string "…Zzzz…\p"
	.string "…Hmm… REPOS!\p"
	.string "Pour récupérer vite, rien ne vaut\n"
	.string "un peu de REPOS, tu vois?\p"
	.string "Elle l'endort et restaure ses PV.$"

Route31_Text_WrongMail:
	.string "Cette LETTRE n'est pas pour moi.$"

Route31_Text_MissingMail:
	.string "Pourquoi ce POKéMON est spécial?\p"
	.string "Il ne tient aucune LETTRE.$"

Route31_Text_DeclinedToHandOverMail:
	.string "Quoi? Tu ne veux rien?$"

Route31_Text_CantTakeLastMon:
	.string "Si je te prends ce POKéMON,\n"
	.string "avec qui vas-tu combattre?$"

Route31_Text_Youngster:
	.string "J'ai trouvé un bon POKéMON dans\n"
	.string "l'ANTRE NOIRE.\p"
	.string "Je vais l'entraîner pour affronter\n"
	.string "ALBERT.\p"
	.string "C'est le CHAMPION de l'ARÈNE\n"
	.string "de MAUVILLE.$"

Route31_Text_Sign:
	.string "ROUTE 31\p"
	.string "MAUVILLE - VILLE GRIOTTE$"

Route31_Text_WadeRegister:
	.string "Tu es incroyable! Je t'aime bien!\p"
	.string "Je cherche des POKéMON ici\n"
	.string "tous les jours.\p"
	.string "Dans les hautes herbes, je trouve\n"
	.string "toutes sortes de BAIES.\p"
	.string "Si tu veux, je peux en partager.$"

Route31_Text_WadeRematchIntro:
	.string "Je t'attendais.\n"
	.string "Combattons!$"

Route31_Text_WadeRematchDefeat:
	.string "Aaaaaaaaah!$"

Route31_Text_WadePostRematch:
	.string "Je t'appellerai dès que je trouve\n"
	.string "une chose qui pourrait te plaire.$"

Route31_Text_WadeHasItem:
	.string "Hé! Je te cherchais!\p"
	.string "J'ai trouvé quelque chose dans\n"
	.string "les hautes herbes.\p"
	.string "Tiens, c'est pour toi!$"

Route31_Text_WadeGaveItem:
	.string "Je te préviendrai si je trouve\n"
	.string "autre chose!$"

Route31_Text_WadeNoRoom:
	.string "Hmm, ton SAC a l'air plein.\p"
	.string "Reviens avec de la place!$"

Route31_Text_DarkCaveSign:
	.string "ANTRE NOIRE$"
