EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah. Tu pars à l'aventure avec\n"
	.string "tes POKéMON?\p"
	.string "Mais que serait l'aventure sans\n"
	.string "une chasse au trésor?\p"
	.string "J'ai raison, pas vrai?$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "Bien! Tu as compris le véritable\n"
	.string "esprit de l'aventure.\p"
	.string "Ça me plaît! Prends donc ceci.$"

Ecruteak_Text_ItemfinderExplanation:
	.string "De nombreux objets sont cachés\n"
	.string "un peu partout.\p"
	.string "Utilise le CHERCH'OBJET pour\n"
	.string "repérer les objets cachés près de\l"
	.string "toi.\p"
	.string "Il ne montre pas l'endroit exact,\n"
	.string "alors cherche par toi-même.\p"
	.string "Ah oui, il paraît qu'il y a des\n"
	.string "objets dans la TOUR CENDRÉE\l"
	.string "de ROSALIA.$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh… Chacun ses goûts, j'imagine…$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "ROSALIA est une très vieille cité.\n"
	.string "Son histoire se transmet depuis\l"
	.string "des générations dans ces livres.$"

Ecruteak_Text_HistoryBook:
	.string "HISTOIRE DE ROSALIA\p"
	.string "Tu veux le lire?$"

Ecruteak_Text_TwoTowers:
	.string "À ROSALIA, il y avait deux tours.\p"
	.string "Chacune abritait un puissant\n"
	.string "POKéMON volant.\p"
	.string "Mais l'une des tours fut réduite\n"
	.string "en cendres.\p"
	.string "On n'a revu aucun des deux\n"
	.string "POKéMON depuis…\p"
	.string "Continuer la lecture?$"

Ecruteak_Text_ThreeMon:
	.string "ROSALIA abritait aussi trois\n"
	.string "POKéMON qui parcouraient la ville.\p"
	.string "On disait qu'ils étaient nés de\n"
	.string "l'eau, de la foudre et du feu.\p"
	.string "Mais ils ne maîtrisaient pas leur\n"
	.string "immense pouvoir.\p"
	.string "On raconte donc que les trois\n"
	.string "partirent comme le vent vers\l"
	.string "les plaines.$"
