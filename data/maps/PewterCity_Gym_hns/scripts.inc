PewterCity_Gym_hns_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_HNS, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK_HNS, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_SLIDE
	msgbox PewterCity_Gym_Text_Brock_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_BROCK, PewterCity_Gym_EventScript_Brock_Trade
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "PIERRE: Ouah! Un challenger de\n"
	.string "JOHTO, ça n'arrive pas souvent.\p"
	.string "Je suis PIERRE, CHAMPION d'ARGENTA\p"
	.string "J'utilise des POKéMON type ROCHE.\p"
	.string "Mes POKéMON résistent à la plupart\n"
	.string "des attaques physiques. Tu auras\l"
	.string "du mal à leur infliger des dégâts.\p"
	.string "En garde!$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "PIERRE: Les puissantes attaques de\n"
	.string "tes POKéMON ont brisé ma défense…\p"
	.string "Tu es plus fort que prévu…\p"
	.string "Tiens, prends ce BADGE.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} reçoit le BADGE ROCHE!$"

PewterCity_Gym_Text_Brock_GiveTM:
	.string "Tiens, prends aussi cette CT.$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "Elle contient ÉBOULEMENT.\p"
	.string "Des rochers tombent sur l'ennemi\n"
	.string "et peuvent l'apeurer.\p"
	.string "Utilise-la pour le stopper net.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "PIERRE: Merci, {PLAYER}. J'ai aimé\n"
	.string "t'affronter malgré ma déception.\l"
	.string "Ce fut un beau combat.\p"
	.string "Ce BADGE ROCHE rendra tes POKéMON\n"
	.string "encore plus puissants.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "PIERRE: Le monde est vaste. Il a\n"
	.string "de forts Dresseurs comme toi.\p"
	.string "Tu verras. Je deviendrai moi aussi\n"
	.string "bien plus fort.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "Les Dresseurs de l'ARÈNE ont des\n"
	.string "POKéMON de type ROCHE.\p"
	.string "Ce type possède une haute DÉFENSE.\p"
	.string "Les combats peuvent donc durer.\n"
	.string "Tu es prêt?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Je dois gagner ces combats…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "Hé, Dresseur de JOHTO! PIERRE est\n"
	.string "fort. Gare si tu ne le prends\l"
	.string "pas au sérieux.$"

PewterCity_Gym_Text_Guide:
	.string "Hé! Futur CHAMPION! Tu assures\n"
	.string "vraiment.\p"
	.string "Tu affrontes les CHAMPIONS d'ARÈNE\n"
	.string "de KANTO?\p"
	.string "Ils sont forts et motivés, comme\n"
	.string "les CHAMPIONS de JOHTO.$"

PewterCity_Gym_Text_Guide_Win:
	.string "Hé! Futur CHAMPION! Cette ARÈNE\n"
	.string "ne t'a pas beaucoup gêné.\p"
	.string "Ta façon de mener le combat était\n"
	.string "vraiment inspirante. Sans rire.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON D'ARGENTA\n"
    .string "CHAMPION: PIERRE\p"
	.string "DRESSEURS VAINQUEURS:\n"
	.string "BLUE, RED$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON D'ARGENTA\n"
    .string "CHAMPION: PIERRE\p"
    .string "DRESSEURS VAINQUEURS:\n"
	.string "BLUE, RED, {PLAYER}$"

PewterCity_Gym_EventScript_Brock_Trade::
	goto_if_set FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED, PewterCity_Gym_EventScript_BrockTradeCompleted
	ingame_trade INGAME_TRADE_BONSLY, PewterCity_Gym_Text_BrockWantToTrade, PewterCity_Gym_EventScript_BrockDeclineTrade, PewterCity_Gym_EventScript_BrockNotRequestedMon, PewterCity_Gym_Text_BrockTakeCare
	setflag FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED
	release
	end

PewterCity_Gym_EventScript_BrockDeclineTrade::
	msgbox PewterCity_Gym_Text_BrockDeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_Gym_Text_BrockNotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockTradeCompleted::
	msgbox PewterCity_Gym_Text_BrockTradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_BrockWantToTrade:
	.string "PIERRE: {PLAYER}, j'ai trouvé ce\n"
	.string "petit MANZAÏ en m'entraînant dans\l"
	.string "les montagnes.\p"
	.string "Il est mignon, mais je pense qu'il\n"
	.string "il lui faut un autre Dresseur.\p"
	.string "Tu échangerais un {STR_VAR_1}\n"
	.string "contre mon {STR_VAR_2}?$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "PIERRE: Merci! Prends bien soin de\n"
	.string "WOODY pour moi!$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "PIERRE: Non? Pas grave.\n"
	.string "WOODY et moi nous entraînerons.$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "Ce n'est pas un {STR_VAR_1}.\n"
	.string "Ce n'est pas ce que je cherche.$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "PIERRE: Comment va WOODY?\n"
	.string "Les MANZAÏ sont très robustes!$"
