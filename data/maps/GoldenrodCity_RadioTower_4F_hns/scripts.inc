GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "LANCE: Attends une seconde!\p"
	.string "N'es-tu pas celui qui nous a\n"
	.string "gênés au PUITS RAMOLOSS?\p"
	.string "Je vois… Tu fais tout ça pour me\n"
	.string "mettre en colère.\l"
	.string "Fais bien attention!\p"
	.string "Mais puisque tu sembles y tenir,\n"
	.string "je vais te montrer toute la\l"
	.string "fureur d'un CADRE ROCKET!$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Pfff…$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "LANCE: Tu as gagné cette fois…\n"
	.string "Mais tu n'as fait qu'attiser\p"
	.string "la fureur de la TEAM ROCKET.$"

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "J'écoutais la radio pendant que\n"
	.string "j'étais aux RUINES.\p"
	.string "J'y ai entendu une émission bien\n"
	.string "étrange.$"

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "LULA: Pourquoi? Pourquoi\n"
	.string "dois-je endurer ça?\p"
	.string "MIAOUSS, au secours!$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "LULA: Oh! Tu es mon petit\n"
	.string "sauveur!\p"
	.string "Accepte ceci en remerciement.$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "LULA: C'est pratique pour\n"
	.string "esquiver les attaques adverses.$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "LULA: Écoute-moi dans la\n"
	.string "CHRONIQUE POKéMON du PROF. CHEN!$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MIAOUSS: Miaouss…$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "Tu comptes sauver le DIRECTEUR?\p"
	.string "Impossible, parce que je vais te\n"
	.string "battre!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "Non! Incroyable!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "Je n'y crois pas! J'ai été battu!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "Halte! On me surnomme la\n"
	.string "forteresse de la TEAM ROCKET!\p"
	.string "Tu ne feras pas un pas de plus!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "La forteresse est tombée!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "Tu as gagné mon respect, alors\n"
	.string "voici un conseil.\p"
	.string "Il n'est pas trop tard. Tu peux\n"
	.string "encore faire demi-tour.$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "Si je trouve les POKéMON\n"
	.string "mignons?\p"
	.string "Je trouverai les miens mignons…\p"
	.string "quand ils auront battu les tiens!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "Oh non! Ils sont si nuls!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "Je m'adore, je suis si belle!\p"
	.string "On s'en fiche, des POKéMON!$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "Excellent.\p"
	.string "Cette TOUR RADIO servira notre\n"
	.string "grand dessein.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "Hmmm…\p"
	.string "Tout grand plan a ses accrocs.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "Crois-tu sincèrement pouvoir\n"
	.string "arrêter la TEAM ROCKET?$"

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "4F PRODUCTION$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "4F STUDIO 2$"
