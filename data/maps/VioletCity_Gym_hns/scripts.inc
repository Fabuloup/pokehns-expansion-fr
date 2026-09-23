VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "Je suis ALBERT, le CHAMPION de\n"
	.string "l'ARÈNE POKéMON de MAUVILLE!\p"
	.string "On dit qu'une bonne décharge\n"
	.string "électrique suffit à rogner les\l"
	.string "ailes des POKéMON de type VOL…\p"
	.string "Je n'autorise personne à insulter\n"
	.string "les POKéMON oiseaux!\p"
	.string "Je vais te montrer la vraie\n"
	.string "puissance des magnifiques\l"
	.string "POKéMON oiseaux!$"

VioletGym_Text_Falkner_WinLoss:
	.string "…Zut de flûte! Les POKéMON\n"
	.string "oiseaux adorés de mon papa…\p"
	.string "Très bien. Prends ceci.\p"
	.string "C'est le BADGE ZÉPHYR officiel\n"
	.string "de la LIGUE POKéMON.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} reçoit le BADGE ZÉPHYR.$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "Le BADGE ZÉPHYR augmente\n"
	.string "l'ATTAQUE des POKéMON.\p"
	.string "Il permet aussi aux POKéMON qui\n"
	.string "le peuvent d'utiliser FLASH à\l"
	.string "tout moment.\p"
	.string "Tiens, prends ça aussi.$"

VioletGym_Text_Falkner_TMExplain:
	.string "En utilisant une CT, un POKéMON\n"
	.string "apprend aussitôt une nouvelle\l"
	.string "capacité.\p"
	.string "Cette CT contient ATTERRISSAGE.\p"
	.string "Elle rend jusqu'à la moitié des\n"
	.string "PV maximum de ton POKéMON.\p"
	.string "Autrement dit, elle le soigne.$"

VioletGym_Text_Falkner_AfterFight:
	.string "Il y a des ARÈNES POKéMON dans\n"
	.string "les villes qui t'attendent.\p"
	.string "Tu devrais y mettre ton talent\n"
	.string "à l'épreuve.\p"
	.string "Moi, je vais m'entraîner plus\n"
	.string "dur pour devenir le plus grand\l"
	.string "maître des oiseaux!$"

VioletGym_Text_Falkner_Rematch:
	.string "Bravo pour ta victoire sur le\n"
	.string "CONSEIL 4!\p"
	.string "J'ai entraîné mes POKéMON de\n"
	.string "type VOL encore plus dur.\p"
	.string "Tu crois pouvoir affronter à\n"
	.string "nouveau la puissance des cieux?$"

VioletGym_Text_Falkner_RematchLoss:
	.string "Ouah… Tu m'as encore battu.\p"
	.string "Je vais m'entraîner plus dur pour\n"
	.string "devenir le plus grand maître des\l"
	.string "oiseaux!$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "Le mot clé, c'est le cran!\p"
	.string "Ici, on s'entraîne nuit et jour\n"
	.string "pour devenir maître des POKéMON\l"
	.string "oiseaux.\p"
	.string "Allez, viens!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "Yaaah!$"

VioletGym_Text_BirdKeeperRod_After:
	.string "Le talent d'ALBERT est bien\n"
	.string "réel!\p"
	.string "Ce n'est pas parce que tu m'as\n"
	.string "battu qu'il faut te vanter!$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "Montre-moi si tu as les épaules\n"
	.string "pour affronter ALBERT!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "Saperlipopette! C'est impossible!$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "C'est pathétique de perdre\n"
	.string "contre un Dresseur débutant…$"

VioletGym_Text_GymGuide_Intro:
	.string "Hé toi! Ça va? Je ne suis pas\n"
	.string "Dresseur, mais je peux te donner\l"
	.string "quelques conseils!\p"
	.string "Crois-moi! Quand on y croit, un\n"
	.string "rêve de MAÎTRE peut se réaliser.\p"
	.string "T'y crois? Alors écoute bien.\p"
	.string "L'as d'ALBERT est un hibou massif\n"
	.string "qui raffole des BAIES.\p"
	.string "Ce n'est pas le plus fort, mais\n"
	.string "il encaisse énormément.\p"
	.string "Les capacités de type ÉLECTRIK\n"
	.string "et ROCHE le blessent, mais méfie-\l"
	.string "toi de COUD'BOUE!\p"
	.string "Si tu veux plus d'aide, va voir\n"
	.string "l'ÉCOLE DES DRESSEURS.\p"
	.string "Les élèves là-bas s'y connaissent\n"
	.string "vraiment!$"

VioletGym_Text_GymGuide_Win:
	.string "Beau combat! Ne lâche pas prise\n"
	.string "et tu seras MAÎTRE en un rien\l"
	.string "de temps!$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON de MAUVILLE$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON de MAUVILLE\p"
	.string "DRESSEURS AGRÉÉS PAR ALBERT:\n"
	.string "{PLAYER}$"
