SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_Blaine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	msgbox SeafoamIslands_Gym_Text_Blaine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CRAMOIS'ÎLE\n"
    .string "CHAMPION : AUGUSTE\p"
	.string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CRAMOIS'ÎLE\n"
    .string "CHAMPION : AUGUSTE\p"
    .string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED, {PLAYER}$"

SeafoamIslands_Gym_Text_Blaine_GiveTM:
	.string "Prends aussi ceci !$"

SeafoamIslands_Gym_Text_Blaine_ExplainTM:
	.string "Cette CT contient\n"
	.string "la terrible SURCHAUFFE !\p"
	.string "La chaleur extrême brûle l'ennemi,\n"
	.string "mais réduit ensuite ta puissance.\p"
	.string "Ton prochain adversaire, j'espère,\n"
	.string "aura un ANTI-BRÛLE ! Waaah !$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "AUGUSTE : Waaah !\p"
	.string "Mon ARÈNE de CRAMOIS'ÎLE a brûlé.\p"
	.string "Mes POKéMON de feu et moi\n"
	.string "sommes à la rue depuis l'éruption.\p"
	.string "Waaah !\p"
	.string "Mais me revoilà CHAMPION D'ARÈNE\n"
	.string "ici, dans cette grotte.\p"
	.string "Si tu me bats, je te donnerai\n"
	.string "un BADGE.\p"
	.string "Mieux vaut avoir un ANTI-BRÛLE !$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "AUGUSTE : Superbe. Je brûle…\p"
	.string "Tu as gagné le BADGE VOLCAN !$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} reçoit le BADGE VOLCAN.$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "AUGUSTE : J'ai perdu cette fois,\n"
	.string "mais je gagnerai la prochaine.\p"
	.string "Quand je rebâtirai mon ARÈNE de\n"
	.string "CRAMOIS'ÎLE, on prendra revanche.$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "AUGUSTE : Mes POKéMON FEU seront\n"
	.string "encore plus forts.\p"
	.string "Tu verras !$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "AUGUSTE : Waouh !\p"
	.string "Je vois que tu es devenu le MAÎTRE\n"
	.string "de KANTO !\p"
	.string "C'est brûlant !\p"
	.string "Ton talent est au sommet.\p"
	.string "Je suis toujours prêt à combattre.\p"
	.string "Tu veux une revanche ?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "AUGUSTE : Quel talent enflammé !\p"
	.string "Tu as réduit mes défenses en\n"
	.string "cendres.$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "Yo !\p"
	.string "… Hein ? C'est déjà fini ?\p"
	.string "Désolé, désolé !\p"
	.string "L'ARÈNE de CRAMOIS'ÎLE avait\n"
	.string "disparu, j'ignorais où te trouver.\p"
	.string "Mais tu es très fort même sans mes\n"
	.string "conseils. Je te savais gagnant !$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "Une ARÈNE peut être partout\n"
	.string "si son CHAMPION est présent.\p"
	.string "Pas besoin d'un bâtiment.$"
