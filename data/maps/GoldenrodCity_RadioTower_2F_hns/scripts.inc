GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "BUENA: Hein? Le mot de passe du\n"
	.string "jour? AIDE, bien sûr!$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "On peut écouter la radio\n"
	.string "partout. Branche-toi!$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "Accès réservé au-delà de ce\n"
	.string "point.$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "Les berceuses à la radio peuvent\n"
	.string "endormir les POKéMON.$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "Pourquoi vouloir s'emparer de la\n"
	.string "TOUR RADIO?$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "RONDOUDOU: Rondou…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "Désolé. Personnel autorisé\n"
	.string "uniquement au-delà.\p"
	.string "Ce n'était pas comme ça avant.\p"
	.string "Il y a quelque chose qui cloche\n"
	.string "avec le DIRECTEUR…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "Fais le tour, tu es chez toi.\p"
	.string "Le DIRECTEUR est redevenu\n"
	.string "gentil, comme avant.$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "Il y a trois ans, la TEAM ROCKET\n"
	.string "a été forcée de se dissoudre.\p"
	.string "Mais on fait notre retour ici!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "Gwah! Fais pas le malin!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "On ne te laissera pas gâcher\n"
	.string "notre grand retour!$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "On est la TEAM ROCKET, les\n"
	.string "exploiteurs de POKéMON!\p"
	.string "On adore être méchants! Peur?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "Tu te prends pour un héros?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "On n'est pas toujours méchants.\n"
	.string "On fait juste ce qu'on veut.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "Hé, hé! Reste hors de notre\n"
	.string "chemin!$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "Arggh. J'abandonne.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "Nos CADRES essaient de prendre\n"
	.string "le contrôle des lieux.\p"
	.string "Ils ont un grand plan. Je me\n"
	.string "demande bien lequel.$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "Hahaha!\p"
	.string "Quel ennui. C'était bien trop\n"
	.string "facile de prendre cet endroit!\p"
	.string "Allez, distrais-moi un peu!$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "Q-qui es-tu?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "Tu m'as battue, et je ne\n"
	.string "l'oublierai pas!$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "BUENA: Écoutez tous mon émission\n"
	.string "LE MOT DE PASSE!\p"
	.string "Écoute bien pour connaître le mot\n"
	.string "de passe du jour!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
	.string "BUENA: Bonjour!\p"
	.string "Alors, tu connais le mot de\n"
	.string "passe du jour?\p"
	.string "OK! C'est lequel?$"

GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
	.string "BUENA: Tu as trouvé!\p"
	.string "Tiens, prends {STR_VAR_1}\n"
	.string "en récompense!$"

GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
	.string "BUENA: Bzzt! Dommage!\p"
	.string "Réessaie demain!$"

GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
	.string "BUENA: Pas d'idée?\n"
	.string "Reviens quand tu seras prêt!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
	.string "BUENA: Tu as déjà deviné le mot\n"
	.string "de passe du jour!\p"
	.string "Rebranche-toi demain!$"

GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
	.string "BUENA: C'est la bonne réponse,\n"
	.string "mais ton SAC est plein!\p"
	.string "Fais de la place et reviens me\n"
	.string "voir!$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "2F VENTES$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "LA CHRONIQUE POKéMON DU\n"
	.string "PROF. CHEN\p"
	.string "L'émission la plus écoutée!$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "La Radio POKéMON, partout et à\n"
	.string "toute heure$"
