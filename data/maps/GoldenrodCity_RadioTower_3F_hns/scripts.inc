GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "La fente pour la CARTE\n"
	.string "MAGNÉTIQUE.$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER} insère la CARTE\n"
	.string "MAGNÉTIQUE.$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "La grille est ouverte.$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "3F PERSONNEL$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "MUSIQUE POKéMON, animée par le\n"
	.string "DJ BEN$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "Nous avons les enregistrements\n"
	.string "des cris de tous les POKéMON\l"
	.string "découverts à ce jour.\p"
	.string "Environ 400 espèces, je crois.$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "Pour les Dresseurs, les POKéMON\n"
	.string "sont des partenaires chéris.\p"
	.string "C'est horrible que la TEAM ROCKET\n"
	.string "cherche à les contrôler.$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "On émet 24 heures sur 24 pour\n"
	.string "proposer des programmes\l"
	.string "divertissants.\p"
	.string "Je ferai de mon mieux pour tenir\n"
	.string "le rythme, moi aussi!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "Le boss de la TEAM ROCKET s'est\n"
	.string "enfermé.\p"
	.string "Mais le DIRECTEUR peut ouvrir.\p"
	.string "Il est au cinquième étage.\p"
	.string "Sauve-le, je t'en prie!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "Le DIRECTEUR est sain et sauf?$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "Merci! Tu es mon héros!\p"
	.string "Voici un petit gage de ma\n"
	.string "reconnaissance.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "C'est ZÉNITH.\p"
	.string "Elle renforce les capacités de\n"
	.string "type FEU pendant un moment.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "Tu as été tout simplement\n"
	.string "merveilleux!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "J'ai reçu des ordres stricts.\p"
	.string "Je dois écraser quiconque défie\n"
	.string "la TEAM ROCKET!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "Quoi?!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "J'ai failli à ma mission…\p"
	.string "APOLLO va être furieux…$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "C'est grisant d'ordonner à des\n"
	.string "POKéMON de commettre des crimes.$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "Tu plaisantes!$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "Perdre me met de mauvais poil!\p"
	.string "Zut! Je déteste les POKéMON\n"
	.string "inutiles!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "Pourquoi le volet s'est-il\n"
	.string "ouvert? Tu y es pour quelque\l"
	.string "chose?$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "Je suis fichu!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "Quoi?! Tu as franchi nos hommes\n"
	.string "dans le SOUTERRAIN?\p"
	.string "Comment as-tu fait?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "Un gamin inconnu qui rôde ici?\p"
	.string "Qui es-tu?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "Tss! Je t'ai sous-estimé!$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "Bwahahaha…\p"
	.string "D'ici, je peux émettre un signal\n"
	.string "aussi puissant que je veux.$"

