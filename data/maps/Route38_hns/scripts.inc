Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "Volez haut dans le ciel,\n"
	.string "mes chers POKéMON oiseaux!$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "J'ai envie de m'envoler\n"
	.string "au loin maintenant.$"

Route38_Text_BirdKeeperTobyAfter:
	.string "Je compte m'entraîner à IRISIA\n"
	.string "pour apprendre VOL à mes POKéMON.$"

Route38_Text_SchoolboyChad1Seen:
	.string "Laisse-moi essayer ce que\n"
	.string "j'ai appris aujourd'hui.$"

Route38_Text_SchoolboyChad1Beaten:
	.string "Je n'ai pas assez étudié,\n"
	.string "on dirait.$"

Route38_Text_SchoolboyChadAfter:
	.string "J'ai tant de contrôles à\n"
	.string "passer que j'ai peu de\l"
	.string "temps pour les POKéMON.\p"
	.string "Alors quand je peux jouer,\n"
	.string "je me concentre vraiment.$"

Route38_Text_ChadRegister:
	.string "J'ai tant de contrôles à\n"
	.string "passer que j'ai peu de\l"
	.string "temps pour les POKéMON.\p"
	.string "Alors quand je peux jouer,\n"
	.string "je me concentre vraiment.$"

Route38_Text_ChadRematchIntro:
	.string "Laisse-moi essayer ce que\n"
	.string "j'ai appris aujourd'hui.$"

Route38_Text_ChadRematchDefeat:
	.string "Je n'ai pas assez étudié,\n"
	.string "on dirait.$"

Route38_Text_ChadPostRematch:
	.string "J'ai tant de contrôles à\n"
	.string "passer que j'ai peu de\l"
	.string "temps pour les POKéMON.\p"
	.string "Alors quand je peux jouer,\n"
	.string "je me concentre vraiment.$"

Route38_Text_LassDana1Seen:
	.string "Tu sembles doué avec les\n"
	.string "POKéMON.\p"
	.string "Si c'est vrai, peux-tu\n"
	.string "me donner des conseils?$"

Route38_Text_LassDana1Beaten:
	.string "Je vois. On peut donc\n"
	.string "combattre ainsi.$"

Route38_Text_LassDanaAfter:
	.string "Je sais quelque chose de bien!\p"
	.string "Le lait de la FERME MEUMEU est\n"
	.string "réputé pour son goût.$"

Route38_Text_BeautyValerieSeen:
	.string "Salut! Quel adorable\n"
	.string "Dresseur!\p"
	.string "Puis-je voir tes POKéMON?$"

Route38_Text_BeautyValerieBeaten:
	.string "Je suis ravie d'avoir vu\n"
	.string "tes POKéMON!$"

Route38_Text_BeautyValerieAfter:
	.string "Voir des POKéMON semble\n"
	.string "apaiser mes nerfs.$"

Route38_Text_SailorHarrySeen:
	.string "J'ai voyagé à l'étranger,\n"
	.string "alors je connais toutes sortes de\l"
	.string "POKéMON!$"

Route38_Text_SailorHarryBeaten:
	.string "Ton talent est de classe mondiale!$"

Route38_Text_SailorHarryAfter:
	.string "Toutes sortes de gens dans\n"
	.string "le monde vivent heureux avec les\l"
	.string "POKéMON.$"

Route38_Text_BeautyOliviaSeen:
	.string "Ne trouves-tu pas que mes POKéMON\n"
	.string "et moi sommes magnifiques?$"

Route38_Text_BeautyOliviaBeaten:
	.string "Nous buvons du LAIT MEUMEU\n"
	.string "chaque jour.$"

Route38_Text_BeautyOliviaAfter:
	.string "Le LAIT MEUMEU est bon pour\n"
	.string "la beauté et la santé,\p"
	.string "mais malheureusement, ils\n"
	.string "ne vendent qu'une bouteille.$"

Route38_Text_Sign:
	.string "ROUTE 38\p"
	.string "OLIVILLE - ROSALIA$"

Route38_Text_TrainerTips:
	.string "ASTUCE DRESSEUR\p"
	.string "Si un POKéMON tente\n"
	.string "d'évoluer, tu peux l'arrêter.\p"
	.string "Appuie sur le Bouton B pendant\n"
	.string "l'évolution pour l'annuler.\p"
	.string "Cela surprend le POKéMON\n"
	.string "et stoppe son évolution.$"


Route38_Text_WaterSign:
	.string "BAIGNADE ET PÊCHE INTERDITES.\n"
	.string "EAU RÉSERVÉE À L'AGRICULTURE.\p"
	.string "-CONSEIL DE ROSALIA$"

Route38_Text_DanaRegister:
	.string "Je sais quelque chose de bien!\p"
	.string "Le lait de la FERME MEUMEU est\n"
	.string "réputé pour son goût.$"

Route38_Text_DanaRematchIntro:
	.string "Tu sembles doué avec les\n"
	.string "POKéMON.\p"
	.string "Si c'est vrai, peux-tu\n"
	.string "me donner des conseils?$"

Route38_Text_DanaRematchDefeat:
	.string "Je vois. On peut donc\n"
	.string "combattre ainsi.$"

Route38_Text_DanaPostRematch:
	.string "Je sais quelque chose de bien!\p"
	.string "Le lait de la FERME MEUMEU est\n"
	.string "réputé pour son goût.$"

Route38_Text_DanaHasItem:
	.string "Hé! J'ai trouvé quelque chose\n"
	.string "d'intéressant!\p"
	.string "Tiens, c'est pour toi!$"

Route38_Text_DanaGaveItem:
	.string "Je te préviendrai si je trouve\n"
	.string "autre chose!$"

Route38_Text_DanaNoRoom:
	.string "Hum, ton SAC est plein.\p"
	.string "Reviens quand tu auras une place.$"
