ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
	.string "CHEN$"

ViridianCity_Text_OakCall:
	.string "CHEN : Ah, {PLAYER} !\p"
	.string "Viens me voir dans mon\n"
	.string "LABO à BOURG PALETTE\l"
	.string "quand tu en auras l'occasion.$"

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "Hé, petit ! Je viens de boire un\n"
	.string "double expresso. Je suis à bloc !\p"
	.string "Il faut que je parle à quelqu'un,\n"
	.string "alors tu feras l'affaire !\p"
	.string "Je n'en ai pas l'air, mais\n"
	.string "j'étais un as de la capture.\p"
	.string "Tu me crois ?$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "Bien, bien. Oui, j'étais vraiment\n"
	.string "quelqu'un d'extraordinaire,\l"
	.string "te le dire !$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "Quoi ? Petit vaurien !\p"
	.string "Si j'étais un peu plus jeune, je\n"
	.string "t'en apprendrais de belles. Pff !$"

ViridianCity_Text_GrampsNearGym:
	.string "Cette ARÈNE est restée sans chef\n"
	.string "jusqu'à récemment.\p"
	.string "Un jeune de BOURG PALETTE en est\n"
	.string "le CHAMPION, souvent absent.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "Vas-tu affronter le\n"
	.string "CHAMPION ?\p"
	.string "Bonne chance. Il t'en faudra.$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "…Zzzzz…\p" 
	.string "Bâille !\p"
	.string "J'ai dû m'assoupir au soleil.\p"
	.string "Quoi ? Je te rappelle quelqu'un ?\p"
	.string "Je ne sais pas, tiens, prends ça.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
	.string "Bâille !\p"
	.string "J'ai dû m'assoupir au soleil.\p"
	.string "…J'ai rêvé d'un SOPORIFIK qui\n"
	.string "dévorait mon rêve. Bizarre, hein ?\p"
	.string "Hein ? Qu'est-ce que c'est ?\p"
	.string "D'où vient cette CT ?\p"
	.string "C'est effrayant ! Tiens, tu peux\n"
	.string "prendre cette CT.$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "La CT42 contient DÉVORÊVE…\p"
	.string "…Zzzzz…$"

ViridianCity_Text_Youngster:
	.string "Il paraît que beaucoup d'objets\n"
	.string "traînent dans la FORÊT DE JADE.$"

ViridianCity_Text_Sign:
	.string "JADIELLE\p"
	.string "L'éternel paradis vert$"

ViridianCity_Text_GymSign:
	.string "ARÈNE POKéMON DE JADIELLE\n"
	.string "CHAMPION : …\p"
	.string "Le reste du texte est illisible…$"

ViridianCity_Text_WelcomeSign:
	.string "BIENVENUE À JADIELLE,\p"
	.string "PORTE DU PLATEAU INDIGO$"

ViridianCity_Text_TrainerHouseSign:
	.string "MAISON DU DRESSEUR\p"
	.string "Le club des combats de haut niveau$"
