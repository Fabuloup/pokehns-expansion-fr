SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
	.string "PIERRE : Hum ?$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
	.string "PIERRE : {PLAYER} !\p"
	.string "Je reconnaîtrais ces yeux partout.\p"
	.string "Que fais-tu si loin au nord ?\p"
	.string ".............\p"
	.string "Les KIMONOS du NOUVEAU SINJOH\n"
	.string "t'envoient nous aider dans notre\l"
	.string "enquête.\p"
	.string "Dans ce cas, laisse-moi te mettre\n"
	.string "au courant.$"

SinjohRuins_Lab_Text_StevenIntroCutscene3:
	.string "PIERRE : Quand j'ai entendu parler\n"
	.string "de ces ruines, j'ai dû venir les\l"
	.string "voir moi-même.\p"
	.string "J'ai réuni une équipe de DEVON\n"
	.string "et nous sommes partis en\l"
	.string "expédition.\p"
	.string "Qui sait ce que nous trouverons\n"
	.string "enfoui ici.\p"
	.string "Nous avons déjà beaucoup\n"
	.string "appris.$"

SinjohRuins_Lab_Text_StevenIntroCutscene4:
	.string "LINGUISTE : La traduction complète\n"
	.string "des glyphes trouvés aux ruines\l"
	.string "m'échappe encore, mais j'ai pu\l"
	.string "en comprendre certains aspects.\p"
	.string "Il existe 17 PLAQUES singulières.\p"
	.string "Elles sont liées aux ruines, mais\n"
	.string "nous n'en avons trouvé qu'une\l"
	.string "pour l'instant.\p"
	.string "Les autres seraient gardées par\n"
	.string "des POKéMON et des Dresseurs\l"
	.string "d'une puissance prodigieuse.$"

SinjohRuins_Lab_Text_StevenIntroCutscene5:
	.string "PIERRE : Voilà, {PLAYER}.\p"
	.string "Les POKéMON NOBLES qui gardent les\n"
	.string "PLAQUES restantes sont trop forts\l"
	.string "pour mon équipe, j'en ai peur.\p"
	.string "Et je dois rester ici pour diriger\n"
	.string "les recherches.\p"
	.string "Mais je pense que tu peux réussir.\n"
	.string "Vas-tu nous aider ?$"

SinjohRuins_Lab_Text_StevenIntroCutscene6:
	.string "Excellent.\p"
	.string "Les glyphes disent que les PLAQUES\n"
	.string "sont aux mains de POKéMON NOBLES\l"
	.string "et de forts Dresseurs de SINJOH.\p"
	.string "J'appellerai ton POKéMATOS si nous\n"
	.string "apprenons quelque chose.\p"
	.string "Merci, {PLAYER}.$"

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
	.string "Tu es sûr ?\p"
	.string "Qui sait ce que nous trouverons\n"
	.string "enfoui ici.\p"
	.string "Tu ne veux pas reconsidérer ?$"

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
	.string "PIERRE : {PLAYER} !\p"
	.string "Je crois savoir ce qui va se\n"
	.string "passer quand les 17 PLAQUES seront\l"
	.string "réunies.\p"
	.string "Je sens...\l"
	.string ".....................$"

SinjohRuins_Lab_Text_FinalPlateScene2:
	.string "PIERRE : Je dois voir ça de mes\n"
	.string "propres yeux !\p"
	.string "Dehors, {PLAYER} !$"

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
	.string "PIERRE : Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLAQUES pour l'instant.\n"
	.string "Pas mal du tout.\p"
	.string "Je l'avoue, j'ai hâte de voir\n"
	.string "ce qui se passera lorsqu'elles\l"
	.string "seront toutes réunies.\p"
	.string "Voyons ce que tu trouveras.$"

SinjohRuins_Lab_Text_StevenFindPlates3:
	.string "PIERRE : Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLAQUES pour l'instant.\n"
	.string "Pas mal du tout.\p"
	.string "As-tu déjà exploré cette\n"
	.string "chambre ?\l"
	.string "Tout cela est bien mystérieux.$"

SinjohRuins_Lab_Text_StevenFindPlates9:
	.string "PIERRE : Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLAQUES pour l'instant.\n"
	.string "Tu progresses très bien.\p"
	.string "Les chambres qui se sont ouvertes\n"
	.string "ressemblent étonnamment à une\l"
	.string "série de chambres de la région\l"
	.string "de HOENN.\p"
	.string "Chacune abritait également un\n"
	.string "POKéMON légendaire.\p"
	.string "Mais à HOENN, seules 3 ont été\n"
	.string "découvertes.\p"
	.string "Et ici, il y en a au moins 6.\p"
	.string "Qui sait ce que nous trouverons.$"

SinjohRuins_Lab_Text_StevenAfterAll:
	.string "PIERRE : {PLAYER} !\p"
	.string "Cette expédition aura été\n"
	.string "l'expérience d'une vie.\p"
	.string "Dès que j'ai connu ces ruines,\n"
	.string "j'avais ce pressentiment.\p"
	.string "Je pressentais une découverte\n"
	.string "incroyable.\p"
	.string "Mes prédictions se réalisent.\p"
	.string "Merci pour toute ton aide,\n"
	.string "Maître.\p"
	.string "Où iras-tu maintenant ?\p"
	.string "J'espère que nous nous reverrons.$"

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
    .string "Le radar pénétrant révèle\n"
	.string "6 chambres souterraines dans cette\l"
	.string "vallée.\p"
	.string "5 semblent proches de la surface,\n"
	.string "et 1 est enfouie encore\l"
	.string "plus profondément.$"
SinjohRuins_Lab_Text_GeologistDuring:
	.string "Tout ce temps, j'ai dirigé mon\n"
	.string "matériel vers le bas pour observer\l"
	.string "le sous-sol.\p"
	.string "Alors qu'il fallait clairement le\n"
	.string "pointer vers le haut !$"
SinjohRuins_Lab_Text_GeologistAfter:
	.string "Ces PLAQUES étaient liées au plus\n"
	.string "puissant des POKéMON ??\p"
	.string "J'aurais aimé mieux les étudier.$"

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
    .string "Argh....\n"
	.string "Il y a tant de glyphes à\l"
	.string "traduire..\p"
	.string "Nous n'avons rien de tel dans\n"
	.string "la région de HOENN.$"
SinjohRuins_Lab_Text_LinguistDuring:
    .string "Imagine ma surprise en\n"
	.string "traduisant le glyphe !\p"
	.string "J'ai vérifié trois et quatre fois\n"
	.string "avant de le dire à PIERRE !\p"
	.string "Je veux dire, vraiment, le Dieu\n"
	.string "des POKéMON ?\p"
	.string "C'est incroyable.$"
SinjohRuins_Lab_Text_LinguistAfter:
    .string "Cette expédition a été un\n"
	.string "plaisir, {PLAYER}.\p"
	.string "Merci d'avoir fait tout le\n"
	.string "travail de terrain.$"

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
	.string "L'existence d'une civilisation\n"
    .string "dans cette zone bouleverse notre\l"
	.string "compréhension de l'histoire.\p"
	.string "Beaucoup des objets trouvés ont\n"
	.string "plus de mille ans.\p"
	.string "La datation correspond à celle\n"
	.string "d'objets trouvés à SINNOH.\p"
	.string "Mais cette flûte trouvée...\n"
	.string "Elle semble bien plus ancienne.$"
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "Ces plaques...\n"
	.string "Le lien avec la région de\l"
	.string "SINNOH...\l"
	.string "Cette flûte....\l"
	.string "Tout commence à s'éclaircir.$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
	.string "La valeur historique de ce que\n"
	.string "tu nous as aidés à déterrer ici\l"
	.string "est inestimable, \l"
	.string "{PLAYER}.\p"
	.string "Vraiment, merci.$"

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
    .string "Graouh !!$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
    .string "On dirait la BALL de CANINOS..\n"
	.string "Mieux vaut ne pas y toucher.$"

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
    .string "Regarde ce magnifique spécimen !\p"
	.string "Ce CANINOS ne ressemble\n"
	.string "à aucune autre dans le\l"
	.string "monde.\p"
	.string "L'analyse ADN révèle un ancêtre\n"
	.string "commun avec les CANINOS\l"
	.string "d'autres régions.\p"
	.string "Son caractère et son type\n"
	.string "diffèrent beaucoup.\p"
	.string "Les écrits anciens de SINNOH sur\n"
	.string "CANINOS semblent concorder.\p"
	.string "Cette espèce occupait peut-être\n"
	.string "un territoire bien plus vaste,\l"
	.string "jusqu'au nord de l'antique SINNOH.$"
SinjohRuins_Lab_Text_BiologistDuring:
	.string "Si la créature en haut de ces\n"
	.string "marches est vraiment le Dieu\l"
	.string "de tous les POKéMON, serait-elle\l"
	.string "leur premier ancêtre commun ?$"
SinjohRuins_Lab_Text_BiologistAfter:
	.string "J'ai pu recueillir tant de données\n"
	.string "sur les formes régionales et\l"
	.string "l'évolution divergente grâce à\l"
	.string "cette expédition. Merci,\l"
	.string "{PLAYER}.$"

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
	.string "J'ai parcouru ces terres sauvages\n"
	.string "pendant dix ans.\p"
	.string "Non, plutôt vingt ans.\p"
	.string "Puis j'ai trouvé ces grands\n"
	.string "piliers de pierre et ce temple\l"
	.string "sinistre.\p"
	.string "Ce sont les RUINES SINJOH.\n"
	.string "Enfin, paraît-il.\p"
	.string "J'ignorais la ville à l'époque.\p"
	.string "Je n'en ai parlé qu'à quelques\n"
	.string "amis. Mais la rumeur va vite.\p"
	.string "Je ne pensais pas que la zone\n"
	.string "attirerait tant l'attention.\p"
	.string "Ça me fait un drôle d'effet.\n"
	.string "Tu vois ?$"
SinjohRuins_Lab_Text_HikerDuringAfter:
	.string "Ne le dis à personne, {PLAYER},\n"
	.string "mais j'ai vu ce temple au sommet\l"
	.string "de la montagne quand j'ai\l"
	.string "découvert cet endroit.\p"
	.string "Je l'ai gardé pour moi.\p"
	.string "J'en ai déjà trop dit sur\n"
	.string "ces ruines.\p"
	.string "Au moins, tout semble s'être\n"
	.string "bien terminé.$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
    .string "Journal 1 : 3 mai 1975\p"
	.string "Nous sommes arrivés sur le site\n"
	.string "des ruines.\p"
	.string "Le froid mordant du MONT ARGENTÉ\n"
	.string "se fait sentir jusque\l"
	.string "dans cette vallée...\p"
	.string "L'équipe principale d'excavation\n"
	.string "traversera bientôt la montagne..\l"
	.string "J'ai hâte de voir ce qui attend\l"
	.string "sous nos pieds !$"

SinjohRuins_Lab_Text_Note2:
    .string "Journal 2 : 10 mai 1975\p"
	.string "Une semaine de fouilles n'a donné\n"
	.string "aucun résultat.\p"
	.string "La glace est très épaisse,\n"
	.string "et la roche détruit tout notre\l"
	.string "matériel.\p"
	.string "Même MACKOGNEUR n'a pas réussi à\n"
	.string "l'entamer.\p"
	.string "Quel est cet endroit ?\p"
	.string "Nous devons le découvrir.$"

SinjohRuins_Lab_Text_Note3:
    .string "Journal 3 : 14 mai 1975\p"
	.string "On n'avance pas dans la vie en\n"
	.string "restant là sans rien faire.\p"
	.string "Je ne suis qu'un ouvrier.\p"
	.string "Mais j'ai eu une idée pour\n"
	.string "traverser la glace.\p"
	.string "Ou plutôt, la faire fondre.\p"
	.string "Il nous faut des POKéMON FEU,\n"
	.string "beaucoup de POKéMON FEU.\p"
	.string "Mais comment les faire venir ici\n"
	.string "depuis SINNOH ?$"

SinjohRuins_Lab_Text_Note4:
    .string "Journal 4 : 21 mai 1975\p"
	.string "Nous avons été très occupés.\p"
	.string "Mon idée nous a permis de franchir\n"
	.string "la glace. Mais les POKéMON FEU ne\l"
	.string "viennent pas de chez nous.\p"
	.string "Le chef a voulu les prendre ici.\p"
	.string "Une source chaude a été trouvée\n"
	.string "près d'un village....\p"
	.string "Et pris ce qu'il nous fallait...\p"
	.string "J'en ai honte. Mais le progrès\n"
	.string "exige parfois des sacrifices.\p"
	.string "La glace a donc disparu.\p"
	.string "6 chambres et un temple fermé\n"
	.string "au centre.\p"
	.string "L'architecture de la structure \n"
	.string "principale évoque l'ancien peuple\l"
	.string "Célestica...\p"
	.string "Nos ancêtres, avant leur exil.\p"
	.string "Le chef veut ouvrir ce temple au\n"
	.string "plus vite...$"

SinjohRuins_Lab_Text_Note5:
	.string "Journal 5 : 2 juin 1975\p"
	.string "Nous avons réussi à l'ouvrir...\p"
	.string "Je pensais être fou de joie...\p"
	.string "Mais nous avons perdu des hommes\n"
	.string "dans l'énergie jaillie du\l"
	.string "temple.\p"
	.string "Sans parler des POKéMON qui nous\n"
	.string "ont aidés à l'ouvrir.\l"
	.string "Que Dieu ait leur âme...\p"
	.string "........................\p"
	.string "Quoi qu'il en soit.\p"
	.string "Le temple est ouvert, mais nous\n"
	.string "n'avons que plus de questions.\p"
	.string "Il n'y a aucun POKéMON légendaire\n"
	.string "à l'intérieur. Aucun trésor.\p"
	.string "Nos vivres commencent à manquer\n"
	.string "et nos efforts n'ont rien\l"
	.string "rapporté...$"

SinjohRuins_Lab_Text_Note6:
	.string "Journal 6 : 10 juin 1975\p"
    .string "L'expédition est terminée.\n"
	.string "Les autres hommes plient bagage.\p"
	.string "Mais je ne peux pas.\p"
	.string "Je ne peux abandonner la mission.\n"
	.string "Pas après toutes nos pertes.\p"
	.string "Je vais rester ici.$"

SinjohRuins_Lab_Text_Note7:
	.string "Journal 7 : 10 septembre 1975\p"
	.string "Voilà des mois que nous sommes\n"
	.string "arrivés. Que je suis arrivé.\p"
	.string "Les autres hommes sont partis.\p"
	.string "Il ne reste que moi et les\n"
	.string "POKéMON capturés pour nous aider\l"
	.string "dans le travail.\p"
	.string "Je les entraîne pour qu'ils\n"
	.string "deviennent plus forts.\p"
	.string "Surtout mon TYPHLOSION.\p"
	.string "Nous devons découvrir ce qui est\n"
	.string "sous le temple.$"

SinjohRuins_Lab_Text_Note8:
	.string "Journal 8 : 15 septembre 1975\p"
	.string "Échec.\p"
	.string "......................\p"
	.string "Mes POKéMON....\p"
	.string "Ensemble, mes 6 POKéMON ont\n"
	.string "réussi à briser\n"
	.string "un faux mur dans le temple.\p"
	.string "Mais il nous attendait...\p"
	.string "Une sorte de titan géant...\p"
	.string "L'énergie qu'il a libérée était\n"
	.string "semblable à la première fois.\p"
	.string "Ils ont tous été détruits...\p"
	.string "Et pire encore, cette bête\n"
	.string "a refermé le mur.\p"
	.string "Je ne peux pas rentrer.\n"
	.string "Ils ne me reconnaîtront plus...\p"
	.string "Cet endroit m'a changé...\p"
	.string "Je vais parler aux\n"
	.string "villageois.\p"
	.string "Ils ignorent ce que j'ai fait.\p"
	.string "Les autres hommes étant partis\n"
	.string "depuis longtemps, ils me croiront\l"
	.string "simple randonneur égaré.\p"
	.string "Il ne me reste aucun autre endroit\n"
	.string "qu'ici.$"

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
    .string "C'est une vitrine soigneusement\n"
	.string "remplie d'échantillons\l"
	.string "et d'objets anciens !$"

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
   .string "Labo de radiographie et tirage.$"


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
   .string "C'est un objet ancien trouvé\n"
   .string "dans les ruines !$"


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
	.string "La FLÛTE AZUR réagit.\n"
	.string "Jouer de la flûte ?$"

SinjohRuins_Lab_Text_DropedItem:
	.string "Le noble {STR_VAR_1} a laissé\n"
	.string "tomber un objet...$"

SinjohRuins_Lab_Text_StevenName:
	.string "PIERRE$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
	.string "PIERRE : {PLAYER}.\p"
	.string "Nous venons de ressentir une\n"
	.string "secousse aux ruines.\p"
	.string "Tous vont bien, rassure-toi.\p"
	.string "C'est intriguant, une chambre\n"
	.string "souterraine sous les ruines vient\l"
	.string "de s'ouvrir.\p"
	.string "Les marques à l'intérieur me\n"
	.string "rappellent quelque chose de HOENN.\p"
	.string "Tu devrais venir voir quand\n"
	.string "tu pourras.$"

SinjohRuins_Lab_Text_StevenCall6Plates:
	.string "PIERRE : {PLAYER}.\p"
	.string "Comment avance la recherche ?\p"
	.string "Nous avons eu une autre secousse.\n"
	.string "Cette fois, une seconde chambre\l"
	.string "s'est ouverte.\p"
	.string "J'ai demandé au géologue de garder\n"
	.string "ses instruments prêts au cas où\l"
	.string "cela recommencerait.\p"
	.string "Plus on creuse... Plus les\n"
	.string "questions s'accumulent.$"

SinjohRuins_Lab_Text_StevenCall9Plates:
	.string "PIERRE : {PLAYER}.\p"
	.string "Encore une secousse aux ruines.\p"
	.string "Les données révèlent quelque chose\n"
	.string "d'intrigant.\p"
	.string "Ce n'était pas un séisme.\p"
	.string "Une énergie s'est accumulée\n"
	.string "sous terre et a fendu la\l"
	.string "roche de l'intérieur.\p"
	.string "Quelle peut en être la cause...\n"
	.string "Je l'ignore vraiment.$"

SinjohRuins_Lab_Text_StevenCall12Plates:
	.string "PIERRE : {PLAYER}.\p"
	.string "Encore une secousse. Encore une\n"
	.string "chambre qui s'ouvre.\p"
	.string "Nous ne comprenons toujours pas\n"
	.string "le rythme de ces événements.\p"
	.string "Dis, {PLAYER}... Tu ne fais rien\n"
	.string "qui puisse provoquer tout\l"
	.string "cela, n'est-ce pas ?\p"
	.string "Non, ça ne tient pas.$"

SinjohRuins_Lab_Text_StevenCall15Plates:
	.string "PIERRE : {PLAYER}.\p"
	.string "Tu viens de trouver une PLAQUE ?\p"
	.string ".................\p"
	.string "Évidemment.\p"
	.string "Les POKéMON légendaires tapis\n"
	.string "dans ces ruines... Ils réagissent\l"
	.string "à toi, n'est-ce pas ?\p"
	.string "Comme s'ils voulaient être vus.\p"
	.string "Mes prédictions se réalisent.\n"
	.string "Je n'aurais jamais dû\l"
	.string "douter de toi.$"

SinjohRuins_Lab_Text_StevenCall16Plates:
	.string "PIERRE : {PLAYER}.\p"
	.string "Nous y sommes presque. Je le sens.\p"
	.string "..................\p"
	.string "Tu devrais venir voir cela de\n"
	.string "tes propres yeux.$"
