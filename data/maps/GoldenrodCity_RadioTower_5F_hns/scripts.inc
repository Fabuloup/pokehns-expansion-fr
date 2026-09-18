GoldenrodCity_RadioTower_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2_HNS, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "T-toi! Tu viens me secourir?$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "C'est ce que tu attendais?\p"
	.string "Raté! Je suis un imposteur!\p"
	.string "J'ai joué son rôle pour préparer\n"
	.string "notre prise de contrôle.\p"
	.string "Tu veux savoir où nous avons\n"
	.string "caché le vrai DIRECTEUR?\p"
	.string "Je te le dirai. Mais seulement si\n"
	.string "tu arrives à me battre!$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "Bon, bon. Je te dis où il est.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "Le boss a planqué le DIRECTEUR\n"
	.string "dans l'ENTREPÔT SOUTERRAIN.\p"
	.string "C'est tout au bout du\n"
	.string "SOUTERRAIN.\p"
	.string "Je suis un chic type: je te donne\n"
	.string "la CLÉ SOUS-SOL pour accéder à\l"
	.string "l'ENTREPÔT SOUTERRAIN.\p"
	.string "Mais ça m'étonnerait que tu ailles\n"
	.string "jusque-là.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "Le boss a planqué le DIRECTEUR\n"
	.string "dans l'ENTREPÔT SOUTERRAIN.\p"
	.string "C'est tout au bout du\n"
	.string "SOUTERRAIN.\p"
	.string "Tu peux utiliser la CLÉ SOUS-SOL\n"
	.string "pour y accéder.\p"
	.string "Mais ça m'étonnerait que tu ailles\n"
	.string "jusque-là.$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2_HNS GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER_HNS, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "Tu te souviens de moi, au REPAIRE\n"
	.string "d'ACAJOU?\p"
	.string "Mon boss m'a grondée, mais je\n"
	.string "suis plus forte.\p"
	.string "J'ai perdu ce jour-là, pas cette\n"
	.string "fois-ci.$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "Ce n'est pas possible!\p"
	.string "Je me suis battue, et j'ai quand\n"
	.string "même perdu…\p"
	.string "Je suis désolée, GIOVANNI…$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{PLAYER}, n'est-ce pas?\p"
	.string "Un morveux comme toi ne saurait\n"
	.string "apprécier la magnificence de la\l"
	.string "TEAM ROCKET.\p"
	.string "Dommage. J'admire vraiment ta\n"
	.string "puissance.$"

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "Oh? Tu es arrivé jusqu'ici?\p"
	.string "Tu dois être un sacré Dresseur.\p"
	.string "Nous comptons prendre cette\n"
	.string "STATION RADIO et annoncer notre\l"
	.string "retour.\p"
	.string "Cela devrait ramener notre boss\n"
	.string "GIOVANNI de son entraînement\l"
	.string "solitaire.\p"
	.string "Nous allons retrouver notre\n"
	.string "gloire d'antan…\p"
	.string "Je ne te laisserai pas contrarier\n"
	.string "nos plans minutieux!$"

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "Non! Pardonnez-moi, GIOVANNI!$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "Comment est-ce possible?\p"
	.string "Nos rêves sont réduits à néant.\p"
	.string "Je n'étais pas à la hauteur.\p"
	.string "Comme GIOVANNI avant moi, je\n"
	.string "dissous la TEAM ROCKET ici et\l"
	.string "maintenant.\p"
	.string "Adieu.$"

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "DIRECTEUR: {PLAYER}, merci!\p"
	.string "Ton courage a sauvé les POKéMON\n"
	.string "du pays tout entier.\p"
	.string "Ce n'est pas grand-chose, mais\n"
	.string "accepte ceci.$"

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "Il y avait autrefois une tour\n"
	.string "ici même, à DOUBLONVILLE.\p"
	.string "Mais elle était vieille et\n"
	.string "branlante.\p"
	.string "Nous l'avons remplacée par notre\n"
	.string "TOUR RADIO.\p"
	.string "Nous avons déterré cette aile\n"
	.string "pendant les travaux.\p"
	.string "On dit que toutes sortes de\n"
	.string "POKéMON vivaient jadis ici.\p"
	.string "Peut-être…\p"
	.string "Cette aile a un lien avec la TOUR\n"
	.string "CENDRÉE de ROSALIA…\p"
	.string "Bon, je retourne à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "Il y avait autrefois une tour\n"
	.string "ici même, à DOUBLONVILLE.\p"
	.string "Mais elle était vieille et\n"
	.string "branlante.\p"
	.string "Nous l'avons remplacée par notre\n"
	.string "TOUR RADIO.\p"
	.string "Nous avons déterré cette aile\n"
	.string "pendant les travaux.\p"
	.string "On dit que toutes sortes de\n"
	.string "POKéMON vivaient jadis ici.\p"
	.string "Peut-être…\p"
	.string "Cette aile a un lien avec les\n"
	.string "TOURB'ÎLES, près d'IRISIA…\p"
	.string "Bon, je retourne à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "Ah!\p"
	.string "Cela me fait penser…\p"
	.string "Cette aile que je t'ai donnée…\n"
	.string "Je crois qu'elle est liée aux\l"
	.string "POKéMON LÉGENDAIRES.\p"
	.string "Mais! Le POKéMON LÉGENDAIRE\n"
	.string "n'apparaîtra pas avec cette\l"
	.string "seule aile…\p"
	.string "Il faut apparemment autre chose…\n"
	.string "Quelque chose dans ce genre.\p"
	.string "Qu'est-ce que c'était donc…\p"
	.string "Impossible de m'en souvenir.$"

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "Tu attends quelque chose?\n"
	.string "C'est ce qu'on appelle un BLUFF.\p"
	.string "Cette fois, je retourne vraiment\n"
	.string "à mon BUREAU. Salut!$"

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "DIRECTEUR: Bonjour, {PLAYER}!\p"
	.string "Tu sais, j'adore les POKéMON.\p"
	.string "J'ai bâti cette TOUR RADIO pour\n"
	.string "exprimer cet amour.\p"
	.string "J'aimerais que les gens\n"
	.string "apprécient nos émissions.$"

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "BEN: Tu écoutes notre musique?$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "5F BUREAU DU   DIRECTEUR$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5F STUDIO 1$"
