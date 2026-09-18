CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
    .string "AUGUSTE : Je n'abandonnerai jamais\n"
	.string "avant d'avoir reconstruit\l"
	.string "l'ARÈNE de CRAMOIS'ÎLE !\p"
	.string "Je serai au DOJO KARATÉ\n"
	.string "d'ici là.$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
    .string "Tu es qui ?\p"
	.string "Bon, on voit bien que tu es un\n"
	.string "Dresseur…\p"
	.string "Je m'appelle BLUE.\p"
	.string "J'ai été CHAMPION, mais seulement\n"
	.string "pendant peu de temps…\p"
	.string "Ce fichu RED m'a eu…\p"
	.string "Enfin, tu veux quoi ? Me défier,\n"
	.string "ou quelque chose comme ça ?\p"
	.string "…Je déteste le dire, mais je n'ai\n"
	.string "pas envie de combattre maintenant.\p"
	.string "Regarde bien autour de toi…\p"
	.string "Un volcan entre en éruption et,\n"
	.string "d'un coup, une ville disparaît.\p"
	.string "On peut gagner ou perdre avec des\n"
	.string "POKéMON. Mais si la nature\l"
	.string "bouge, on peut tout perdre vite.\p"
	.string "…\p"
	.string "C'est comme ça…\p"
	.string "Mais je reste un Dresseur.\p"
	.string "Quand je vois un adversaire fort,\n"
	.string "j'ai envie de combattre.\p"
	.string "Si tu veux me défier, il te faut\n"
	.string "d'abord 15 BADGES.\p"
	.string "Je t'affronterai alors.$"

CinnabarIsland_Text_Blue:
    .string "Tu es qui ?\p"
	.string "Bon, on voit bien que tu es un\n"
	.string "Dresseur…\p"
	.string "Je m'appelle BLUE.\p"
	.string "J'ai été CHAMPION, mais seulement\n"
	.string "pendant peu de temps…\p"
	.string "Ce fichu RED m'a eu…\p"
	.string "Enfin, tu veux quoi ? Me défier,\n"
	.string "ou quelque chose comme ça ?\p"
	.string "…Je déteste le dire, mais je n'ai\n"
	.string "pas envie de combattre maintenant.\p"
	.string "Regarde bien autour de toi…\p"
	.string "Un volcan entre en éruption et,\n"
	.string "d'un coup, une ville disparaît.\p"
	.string "On peut gagner ou perdre avec des\n"
	.string "POKéMON. Mais si la nature\l"
	.string "bouge, on peut tout perdre vite.\p"
	.string "…\p"
	.string "C'est comme ça…\p"
	.string "Mais je reste un Dresseur.\p"
	.string "Quand je vois un adversaire fort,\n"
	.string "j'ai envie de combattre.\p"
	.string "Si tu veux me défier, viens à\n"
	.string "l'ARÈNE de JADIELLE.\p"
	.string "Je t'affronterai alors.$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "Un avis est affiché…\p"
	.string "L'ARÈNE de CRAMOIS'ÎLE a déménagé\n"
	.string "aux ÎLES ÉCUME.\p"
	.string "AUGUSTE$"

CinnabarIsland_Text_Sign:
	.string "CRAMOIS'ÎLE\p"
	.string "La ville ardente aux désirs brûlants$"
