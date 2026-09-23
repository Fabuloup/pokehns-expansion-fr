SlowpokeWell_B1F_hns_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "FARGAS: Salut, {PLAYER}!\p"
	.string "Le garde a décampé quand je lui\n"
	.string "ai crié dessus.\p"
	.string "Et puis je suis tombé dans le\n"
	.string "PUITS.\p"
	.string "Je me suis reçu sur le dos, je\n"
	.string "ne peux plus bouger.\p"
	.string "Pfff! Si j'étais en forme, mes\n"
	.string "POKéMON les auraient punis…\p"
	.string "C'est vraiment trop bête.\p"
	.string "{PLAYER}, va leur montrer ce que\n"
	.string "tu as dans le ventre à ma place!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "FARGAS: Bravo, {PLAYER}!\p"
	.string "La TEAM ROCKET a décampé.\p"
	.string "Mon dos va mieux aussi.\n"
	.string "Allez, on sort d'ici.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "Grrah! Je montais la garde\n"
	.string "là-haut quand un vieux dingue\l"
	.string "est venu me crier dessus.\p"
	.string "Il m'a fichu une telle trouille\n"
	.string "que je suis tombé ici.\p"
	.string "Tu sais quoi? Je vais calmer mes\n"
	.string "nerfs sur toi!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "Grrah! C'est pas mon jour!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Bah oui, on coupe les queues\n"
	.string "des RAMOLOSS et on les vend.\p"
	.string "Tout ce qu'on fait, c'est pour\n"
	.string "le profit.\p"
	.string "Et oui! On est la TEAM ROCKET,\n"
	.string "et on ferait n'importe quoi\l"
	.string "pour le pognon!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "Kesstu veux?\p"
	.string "Si tu viens gêner notre travail,\n"
	.string "n'attends aucune pitié!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "Tu t'en sors bien aujourd'hui,\n"
	.string "mais attends la prochaine fois!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Oui, la TEAM ROCKET a été\n"
	.string "dissoute il y a trois ans.\p"
	.string "Le boss est entré dans la\n"
	.string "clandestinité.\p"
	.string "Mais on a continué nos affaires\n"
	.string "dans l'ombre!\p"
	.string "Un petit obstacle comme toi ne\n"
	.string "gênera pas notre mission.\p"
	.string "Je te conseille de bien redouter\n"
	.string "ce qui va suivre!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Hé-hé-hé!\n"
	.string "Arrêter de voler les QUEUES?\p"
	.string "Ça va pas la tête!\n"
	.string "Si on t'écoutait, la réputation\l"
	.string "de la TEAM ROCKET serait ruinée!$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Heu…\n"
	.string "Trop fort…$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "On a besoin de sous, d'accord,\n"
	.string "mais vendre des QUEUES de\l"
	.string "RAMOLOSS?\p"
	.string "C'est pas facile d'être SBIRE\n"
	.string "de la TEAM ROCKET!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "Arrêter de voler les QUEUES?\p"
	.string "C'est ça, essaie donc de tous\n"
	.string "nous battre!$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "Sale môme!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "Les QUEUES de RAMOLOSS, ça\n"
	.string "repousse vite!\p"
	.string "Alors où est le mal à les\n"
	.string "vendre?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "Un RAMOLOSS à la QUEUE coupée…\p"
	.string "Hein? Il a une LETTRE.\n"
	.string "La lire?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} lit la LETTRE.\p"
	.string "Sois sage et occupe-toi bien de\n"
	.string "la maison avec pépé et RAMOLOSS.\p"
	.string "Bisous. Papa$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "Un RAMOLOSS à la QUEUE coupée…$"
