Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "Je termine mes préparatifs pour\n"
    .string "la LIGUE POKéMON.$"

Route26_Text_CooltrainermJakeBeaten:
    .string "J'ai tout raté!$"

Route26_Text_CooltrainermJakeAfter:
    .string "Gagner à la LIGUE ne sera pas\n"
    .string "facile.\p"
    .string "Je dois encore m'entraîner.\p"
    .string "Il paraît que le CONSEIL 4 de la\n"
    .string "LIGUE surpasse les CHAMPIONS.$"

Route26_Text_CooltrainermGavenSeen:
    .string "Les combats ardus nous rendent\n"
    .string "plus puissants.$"

Route26_Text_CooltrainermGavenBeaten:
    .string "Argh! La vie est encore plus dure!$"

Route26_Text_CooltrainermGavenAfter:
    .string "Pour gagner la LIGUE POKéMON, il\n"
    .string "faut traverser la ROUTE VICTOIRE.\p"
    .string "Mais elle est très difficile.\p"
    .string "Presque personne n'y va!$"

Route26_Text_GavenRegister:
    .string "Pour gagner la LIGUE POKéMON, il\n"
    .string "faut traverser la ROUTE VICTOIRE.\p"
    .string "Mais elle est très difficile.\p"
    .string "Presque personne n'y va!$"

Route26_Text_GavenRematchIntro:
    .string "Les combats ardus nous rendent\n"
    .string "plus puissants.$"

Route26_Text_GavenRematchDefeat:
    .string "Argh! La vie est encore plus dure!$"

Route26_Text_GavenPostRematch:
    .string "Pour gagner la LIGUE POKéMON, il\n"
    .string "faut traverser la ROUTE VICTOIRE.\p"
    .string "Mais elle est très difficile.\p"
    .string "Presque personne n'y va!$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Si tu es arrivé jusqu'ici,\n"
    .string "tu dois être fort.\p"
    .string "Je vais tout donner dans ce\n"
    .string "combat!$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "Non! Je n'y crois pas!$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "J'ai vaincu huit CHAMPIONS,\n"
    .string "alors j'avais confiance.\p"
    .string "Je ferai mieux la prochaine fois.$"

Route26_Text_CooltrainerfBethSeen:
    .string "J'ai perdu face à {RIVAL}.\p"
    .string "Il était très fort, mais…\p"
    .string "On aurait dit qu'il devait\n"
    .string "gagner à tout prix.\p"
    .string "J'ai eu pitié de ses POKéMON.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "Les POKéMON ne sont pas des armes.$"

Route26_Text_CooltrainerfBethAfter:
    .string "Les POKéMON sont de précieux\n"
    .string "partenaires pour la vie.$"

Route26_Text_BethRegister:
    .string "Les POKéMON sont de précieux\n"
    .string "partenaires pour la vie.$"

Route26_Text_BethRematchIntro:
    .string "J'ai perdu face à {RIVAL}.\p"
    .string "Mais je ne perdrai pas contre toi!$"

Route26_Text_BethRematchDefeat:
    .string "Les POKéMON ne sont pas des armes.$"

Route26_Text_BethPostRematch:
    .string "Les POKéMON sont de précieux\n"
    .string "partenaires pour la vie.$"

Route26_Text_PsychicRichardSeen:
    .string "Ouah, regarde tous ces BADGES!\n"
    .string "Je suis impressionné.\p"
    .string "Mais les réunir ne te suffit\n"
    .string "pas, n'est-ce pas?$"

Route26_Text_PsychicRichardBeaten:
    .string "Beau combat!$"

Route26_Text_PsychicRichardAfter:
    .string "Humains et POKéMON grandissent\n"
    .string "grâce à leurs expériences.\p"
    .string "Ne deviens ni paresseux ni imbu.$"

Route26_Text_Sign:
    .string "ROUTE 26\p"
    .string "LIGUE POKéMON\n"
    .string "PORTAIL D'ACCUEIL$"
