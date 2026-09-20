Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitfanfare
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "BAOBA: SAPRISTI! Cette ombre\n"
	.string "était celle d'un POKéMON?\p"
	.string "Tu as pu bien l'observer?\n"
	.string "Je n'ai pas vu sa couleur…$"

Route39_Text_BaobaIntro::
	.string "Comme c'est étrange…\p"
	.string "…Oh!\n"
	.string "Ce que tu tiens, c'est…\l"
	.string "ce qu'on appelle… un POKéDEX!\p"
	.string "Cela faisait longtemps.\p"
	.string "Je m'appelle BAOBA!\n"
	.string "Je dirigeais le PARC SAFARI de\l"
	.string "PARMANIE, mais il devenait dépassé\l"
	.string "avec l'arrivée de nouveaux\l"
	.string "divertissements.\p"
	.string "Je suis parti à l'étranger étudier\n"
	.string "la technologie et ouvrir\l"
	.string "un PARC SAFARI dernier cri\l"
	.string "à IRISIA.\p"
	.string "Ce n'est peut-être pas\n"
	.string "une simple coïncidence.\p"
	.string "Échangeons nos numéros dans le\n"
	.string "POKéMATOS.\p"
	.string "Je pourrai t'appeler dès que le\n"
	.string "PARC SAFARI ouvrira, avant même\l"
	.string "tous les autres!$"

Route39_Text_Registered:
	.string "{PLAYER} enregistre BAOBA\n"
	.string "dans le POKéMATOS!$"


Route39_Text_WillCall:
	.string "BAOBA: Je te préviendrai bientôt\n"
	.string "sur le POKéMATOS!$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "Cette ombre… C'était peut-être un\n"
	.string "ROUCOOL géant?$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "ÉCRÉMEUH: Meeeuuh!$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "Je viens de rentrer à OLIVILLE.\p"
	.string "Que dirais-tu d'un combat POKéMON?$"

Route39_Text_SailorEugeneBeaten:
	.string "Aaaaargh!$"

Route39_Text_SailorEugeneAfter:
	.string "Mes POKéMON ont été capturés et\n"
	.string "élevés à l'étranger.\p"
	.string "Ils m'accompagnent durant\n"
	.string "mes longs voyages.$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "C'est le bon moment pour vanter\n"
	.string "mon PIKACHU!$"

Route39_Text_PokefanMDerekBeaten:
	.string "Je n'ai pas pu montrer\n"
	.string "mon PIKACHU…$"

Route39_Text_PokefanMDerekAfter:
	.string "Je n'écoute pas tes\n"
	.string "vantardises!\p"
	.string "Nous, les POKé FANS, refusons\n"
	.string "d'écouter les vantards!$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "Quels adorables POKéMON.\p"
	.string "Montrons-nous nos POKéMON\n"
	.string "en même temps.$"

Route39_Text_PokefanFRuthBeaten:
	.string "Perdre ne me dérange pas.$"

Route39_Text_PokefanFRuthAfter:
	.string "Tu connais les bébés\n"
	.string "POKéMON?\p"
	.string "Ils doivent être adorables!$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Voyons ce dont tes\n"
	.string "POKéMON sont capables.$"

Route39_Text_PsychicNormanBeaten:
	.string "Oh, tes POKéMON ont du\n"
	.string "potentiel.$"

Route39_Text_PsychicNormanAfter:
	.string "Tu sais que les POKéMON ont\n"
	.string "des talents différents?\p"
	.string "Les humains aussi.\n"
	.string "Chacun possède un potentiel\l"
	.string "différent.$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "Tu arrives pile au bon\n"
	.string "moment.\p"
	.string "Combattons.$"

Route39_Text_PokefanFJaimeBeaten:
	.string "Oh, quelle déception…$"

Route39_Text_PokefanFJaimeAfter:
	.string "J'ai rencontré NOCTALI la nuit\n"
	.string "ici même, sur la ROUTE 39.\p"
	.string "J'ignore pourquoi, mais il\n"
	.string "semble aimer quand je\l"
	.string "l'entraîne ici.\p"
	.string "Il devient plus amical en\n"
	.string "s'entraînant ici que\l"
	.string "n'importe où ailleurs.$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "ROUTE 39\p"
	.string "OLIVILLE - ROSALIA$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "FERME MEUMEU\p"
	.string "Goûtez notre lait frais et bon !$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "ASTUCE DRESSEUR\p"
	.string "Lance COUP D'BOULE sur un arbre\n"
	.string "pour faire tomber des POKéMON.\p"
	.string "Diverses espèces de POKéMON\n"
	.string "tombent des arbres.\p"
	.string "Lance COUP D'BOULE sur tout arbre\n"
	.string "que tu vois!$"

Route39_Text_DerekRegister:
	.string "Je n'écoute pas tes\n"
	.string "vantardises!\p"
	.string "Nous, les POKé FANS, refusons\n"
	.string "d'écouter les vantards!$"

Route39_Text_DerekHasItem:
	.string "Hé! En montrant mon\n"
	.string "PIKACHU, j'ai trouvé ceci.\p"
	.string "Tiens, c'est pour toi!$"

Route39_Text_DerekGaveItem:
	.string "Rien ne vaut PIKACHU!\n"
	.string "Tu es d'accord?$"

Route39_Text_DerekNoRoom:
	.string "Hum, ton SAC est plein.\p"
	.string "Reviens avec de la place.$"
