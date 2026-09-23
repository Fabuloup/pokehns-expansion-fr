NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "Regarde mon sac!\p"
	.string "J'ai imprimé mes préférés depuis\n"
	.string "mon POKéDEX et je les ai collés\l"
	.string "dessus.$"

NationalPark_Normal_Text_PokefanF:
	.string "C'est une LETTRE de ma fille.\n"
	.string "Ça me remonte le moral.$"

NationalPark_Normal_Text_Teacher1:
	.string "Un peu d'attention, je vous prie!\p"
	.string "…Oups, je dois arrêter de penser\n"
	.string "comme une enseignante.\p"
	.string "Tu dois être Dresseur POKéMON.\p"
	.string "Puisque tu travailles si dur,\n"
	.string "prends donc ceci.$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "Fais tenir cette VIVE GRIFFE à un\n"
	.string "POKéMON.\p"
	.string "Il frappera parfois en premier\n"
	.string "pendant le combat.$"

NationalPark_Normal_Text_Youngster1:
	.string "Je joue avec des autocollants\n"
	.string "imprimés depuis mon POKéDEX.$"

NationalPark_Normal_Text_Youngster2:
	.string "Si je gagne, je récupère\n"
	.string "l'autocollant POKéDEX de l'autre.$"

NationalPark_Normal_Text_Teacher2:
	.string "Je me promène dans le PARC, mais\n"
	.string "jamais dans les hautes herbes.\p"
	.string "Les Dresseurs veulent toujours se\n"
	.string "battre…\p"
	.string "Tu as dû livrer bien des combats.\n"
	.string "Laisse-moi soigner tes POKéMON.$"

NationalPark_Normal_Text_Persian:
	.string "PERSIAN: Fufushaa!$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "Le monde des POKéMON est vaste.\p"
	.string "Il reste plein de choses qu'on\n"
	.string "ignore.\p"
	.string "Mais j'en sais plus que toi!$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "Q-q-quoi?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple…\p"
	.string "Il existe 92 sortes de CT.\p"
	.string "Les POKéMON échangés montent de\n"
	.string "niveau plus vite.$"

NationalPark_Normal_Text_JackRegister:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple…\p"
	.string "Il existe 92 sortes de CT.\p"
	.string "Les POKéMON échangés montent de\n"
	.string "niveau plus vite.$"

NationalPark_Normal_Text_JackRematchIntro:
	.string "J'ai appris plein de choses\n"
	.string "depuis notre dernier combat!$"

NationalPark_Normal_Text_JackRematchDefeat:
	.string "Q-q-quoi?$"

NationalPark_Normal_Text_JackPostRematch:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple…\p"
	.string "Il existe 92 sortes de CT.\p"
	.string "Les POKéMON échangés montent de\n"
	.string "niveau plus vite.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "Mes POKéMON sont adorables.\p"
	.string "Laisse-moi te dire à quel point\n"
	.string "ils font ma fierté.$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "Je te bats en fierté, mais…$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "Je dois dire que tes POKéMON sont\n"
	.string "mignons aussi.$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "On adore nos POKéMON, même s'ils\n"
	.string "ne nous aiment pas.\p"
	.string "C'est ça, être un FAN.$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "M-mes POKéMON!$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "J'ai perdu le combat, mais mes\n"
	.string "POKéMON gagnent le prix des plus\l"
	.string "adorables.$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "Hé? Pourquoi tu me fixes?\p"
	.string "Oh, un combat?$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "…Hmmm…$"

NationalPark_Normal_Text_LassKrise_After:
	.string "Je croyais que tu me fixais parce\n"
	.string "que je suis mignonne!$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "PLACE DE LA DÉTENTE\n"
	.string "PARC NATUREL$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "Qu'est-ce que cet avis?\p"
	.string "Merci de ne combattre que dans\n"
	.string "les hautes herbes.\p"
	.string "BUREAU DU GARDE DU PARC NATUREL$"

NationalPark_Normal_Text_TrainerTips:
	.string "ASTUCE\p"
	.string "Imprime une LETTRE en l'ouvrant,\n"
	.string "puis appuie sur START.$"

NationalPark_Normal_Text_BeverlyRegister:
	.string "Je dois dire que tes POKéMON sont\n"
	.string "mignons aussi.$"

NationalPark_Normal_Text_BeverlyHasItem:
	.string "Oh, bonjour! J'ai quelque chose\n"
	.string "pour toi.\p"
	.string "Accepte-le en gage de ma\n"
	.string "reconnaissance!$"

NationalPark_Normal_Text_BeverlyGaveItem:
	.string "Mes adorables POKéMON et moi\n"
	.string "t'encouragerons!$"

NationalPark_Normal_Text_BeverlyNoRoom:
	.string "Hmm, ton SAC est plein.\p"
	.string "Reviens quand tu auras de la\n"
	.string "place.$"
