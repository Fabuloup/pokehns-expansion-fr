VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "Je ne suis pas une pro de la GBA,\n"
	.string "mais j'adore les jeux POKéMON!\p"
	.string "Dans les vieux jeux, il fallait\n"
	.string "combattre plein de POKéMON\l"
	.string "sauvages pour gagner de l'EXP.\p"
	.string "Dans les jeux récents, le\n"
	.string "MULTI EXP fait monter tes POKéMON\l"
	.string "beaucoup trop vite.\p"
	.string "Ici, le MULTI EXP est équilibré\n"
	.string "pour amener tes POKéMON au bon\l"
	.string "niveau. Ou un peu au-dessus,\l"
	.string "selon le nombre de combats.\p"
	.string "Pour une expérience à l'ancienne,\n"
	.string "façon GÉN 1-4, désactive le\l"
	.string "MULTI EXP.\p"
	.string "Pour une expérience moderne,\n"
	.string "active-le.\p"
	.string "À toi de choisir comment jouer!$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "THÉOPHILE est mon nom!\p"
	.string "Sensationnels sont les POKéMON!\p"
	.string "T'apprendre je vais à devenir\n"
	.string "meilleur Dresseur!$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Certains POKéMON sont faibles au\n"
	.string "départ et demandent bien plus\l"
	.string "d'EXP que les autres pour\l"
	.string "devenir forts.\p"
	.string "EMBRYLEX, par exemple, est plutôt\n"
	.string "faible, mais il deviendra un\l"
	.string "puissant TYRANOCIF, au prix de\l"
	.string "beaucoup d'EXP.\p"
	.string "Seuls les Dresseurs les plus\n"
	.string "acharnés devraient élever un\l"
	.string "tel POKéMON.$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "Très bien! Ton éducation je\n"
	.string "ferai!\p"
	.string "En combat, le premier POKéMON\n"
	.string "de ta liste sort en premier!\p"
	.string "Changer l'ordre de la liste peut\n"
	.string "rendre le combat plus facile!\p"
	.string "En savoir plus, tu veux?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "Alors, on veut savoir comment\n"
	.string "bien élever ses p'tits POKéMON?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "Qu'il en soit ainsi! Ton\n"
	.string "éducation je ferai!\p"
	.string "Tout POKéMON qui participe au\n"
	.string "combat, même brièvement, gagne\l"
	.string "des points d'EXP.\p"
	.string "Mets en première ligne un POKéMON\n"
	.string "faible et change-le vite!\p"
	.string "Ainsi, les POKéMON faibles\n"
	.string "deviendront forts!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "Oh! Bon élève tu es!\n"
	.string "Plus rien je n'ai à t'apprendre!\p"
	.string "Si tu veux en savoir plus, parle\n"
	.string "aux élèves!$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "Les POKéMON qu'on croyait évoluer\n"
	.string "uniquement par échange peuvent\l"
	.string "aussi évoluer au niveau.\p"
	.string "MACHOPEUR et GRAVALANCH évoluent\n"
	.string "au Niv. 38, KADABRA et SPECTRUM\l"
	.string "au Niv. 42.\p"
	.string "Certains objets, comme la PEAU\n"
	.string "MÉTAL, font aussi évoluer des\l"
	.string "POKéMON tenus pendant qu'ils\l"
	.string "montent de niveau.$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "Les POKéMON notables d'une zone\n"
	.string "sont visibles sur le terrain!\p"
	.string "Mais pense à explorer les routes\n"
	.string "de JOUR comme de NUIT!$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "Les BAIES de JOHTO servent à\n"
	.string "soigner et à fabriquer des BALLS.\p"
	.string "Celles de KANTO servent à réduire\n"
	.string "les stats d'un POKéMON.\p"
	.string "Et le DOJO de KANTO aide les\n"
	.string "POKéMON à parfaire leurs stats\l"
	.string "individuelles.$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Sache que tes adversaires ont\n"
	.string "maintenant des équipes mieux\l"
	.string "réparties en types.\p"
	.string "Attends-toi à un voyage bien\n"
	.string "plus corsé!$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "Le tableau explique les CS des\n"
	.string "POKéMON.\p"
	.string "Une fois débloquée, une CS n'a\n"
	.string "plus besoin d'être apprise pour\l"
	.string "être utilisée.$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "C'est le cahier de ce gamin…\p"
	.string "Attrape les POKéMON en lançant\n"
	.string "des POKé BALLS.\p"
	.string "Tu peux en transporter six\n"
	.string "avec toi.\p"
	.string "Continuer à lire?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Avant de lancer une POKé BALL,\n"
	.string "affaiblis ta cible.\p"
	.string "Un POKéMON empoisonné ou brûlé\n"
	.string "est plus facile à attraper.\p"
	.string "Continuer à lire?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Certaines capacités rendent\n"
	.string "confus.\p"
	.string "Un POKéMON confus peut\n"
	.string "s'attaquer lui-même.\p"
	.string "Quitter le combat dissipe la\n"
	.string "confusion.\p"
	.string "Continuer à lire?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "Les gens qui attrapent et font\n"
	.string "combattre des POKéMON sont des\l"
	.string "Dresseurs POKéMON.\p"
	.string "Leur but est de visiter les\n"
	.string "ARÈNES POKéMON et de vaincre\l"
	.string "les autres Dresseurs.\p"
	.string "La page suivante est… blanche!\p"
	.string "Gamin: Hé-hé-hé…\p"
	.string "Je n'ai rien écrit d'autre…$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "Cette superbe machine imprime\n"
	.string "les données en autocollants!$"
