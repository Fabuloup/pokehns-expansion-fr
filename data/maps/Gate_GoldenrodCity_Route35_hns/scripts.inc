Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "Excuse-moi, petit! Tu peux me\n"
	.string "rendre un service?\p"
	.string "Tu peux apporter ce POKéMON avec\n"
	.string "sa LETTRE à mon ami?\p"
	.string "Il est sur la ROUTE 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "Tu veux bien? Parfait! Merci!\p"
	.string "Mon pote est un gros gars qui\n"
	.string "roupille tout le temps.\p"
	.string "Tu le reconnaîtras tout de suite!$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER} reçoit un POKéMON avec\n"
	.string "une LETTRE.$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "Mets-le bien en tête d'équipe\n"
	.string "quand tu trouveras mon ami!\p"
	.string "ROUTE 31!\p"
	.string "Ah oui. Un arbre bizarre bloquait\n"
	.string "la route.\p"
	.string "Je me demande si c'est dégagé.$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "Tu ne peux pas porter un POKéMON\n"
	.string "de plus…$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "Oh… Tant pis, alors…$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "Merci, petit! Tu as fait la\n"
	.string "livraison pour moi!\p"
	.string "Tiens, pour ta peine!$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "Mon pote roupillait, hein? Hé,\n"
	.string "qu'est-ce que je disais?$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "Un arbre étrange bloque la route.\p"
	.string "Il gigote si on lui parle.\p"
	.string "Il paraît qu'il s'est déchaîné\n"
	.string "quand on l'a arrosé avec une\l"
	.string "CARAPUCE À O.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "J'aime bien la Berceuse POKéMON\n"
	.string "qu'ils passent à la radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "Je me demande combien d'espèces\n"
	.string "de POKéMON existent dans le monde.\p"
	.string "Il y a trois ans, le PROF. CHEN\n"
	.string "parlait de 150 espèces.\p"
	.string "Mais on m'a dit récemment qu'il y\n"
	.string "en avait plus de 400!$"
