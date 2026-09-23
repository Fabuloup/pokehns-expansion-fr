ViridianCity_Gym_hns_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE_HNS, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	msgbox ViridianCity_Gym_Text_LeaderBlue_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_TRICK_ROOM
	msgbox ViridianCity_Gym_Text_LeaderBlue_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	setvar VAR_OAK_MT_SILVER_CALL, 1
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "BLUE : Tu en redemandes déjà ?\p"
	.string "Si tu veux me réaffronter, viens\n"
	.string "au DOJO !$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "BLUE : Yo ! Enfin là, hein ?\p"
	.string "Pas d'humeur à CRAMOIS'ÎLE,\p"
	.string "mais je suis prêt à t'affronter.\p"
	.string "…\p"
	.string "Tu dis avoir conquis toutes les\n"
	.string "ARÈNES de JOHTO ?\p"
	.string "Hé ! Les ARÈNES de JOHTO doivent\n"
	.string "être plutôt minables.\p"
	.string "Hé, ne t'en fais pas.\p"
	.string "Je saurai si tu es fort en\n"
	.string "t'affrontant maintenant.\p"
	.string "Prêt, MAÎTRE de JOHTO ?$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "BLUE : Quoi ?\p"
	.string "Comment ai-je pu perdre ainsi ?\p"
	.string "…\p"
	.string "Tss, d'accord… Tiens, prends ça :\n"
	.string "le BADGE TERRE.$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER} reçoit le BADGE TERRE.$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "BLUE : …\p"
	.string "D'accord, j'avais tort. Tu es\n"
	.string "vraiment un bon Dresseur.\p"
	.string "Mais un jour, je te battrai.\p"
	.string "Ne l'oublie pas !$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "Emporte ceci.$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "C'est DISTORSION.\p"
	.string "Tous les POKéMON changent d'ordre.\n"
	.string "Les lents avant les rapides.\p"
	.string "Utilise-la pour tout renverser.$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "BLUE : Écoute-moi.\p"
	.string "Ne perds pas avant que je t'aie\n"
	.string "battu. Compris ?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "Yo, futur MAÎTRE !\p"
	.string "Ça va ? Tu sembles bien lancé.\n"
	.string "Continue.\p"
	.string "Le CHAMPION D'ARÈNE a affronté le\n"
	.string "MAÎTRE il y a trois ans.\p"
	.string "Ce n'est pas un adversaire facile.\p"
	.string "Donne tout ce que tu as !$"

ViridianCity_Gym_Text_Guide_Win:
	.string "Tu es vraiment coriace…\p"
	.string "Quel combat inspirant !\n"
	.string "J'en ai les larmes aux yeux.$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE JADIELLE\n"
    .string "CHAMPION : BLUE\p"
	.string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE JADIELLE\n"
    .string "CHAMPION : BLUE\p"
    .string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED, {PLAYER}$"
