ReceptionGate_hns_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
    .string "JEANNINE: Je vais chez mon père\n"
    .string "lui apporter son déjeuner.\p"
    .string "Le CONSEIL 4 n'a pas une minute\n"
    .string "de repos, ni jour ni nuit.\l"
    .string "C'est un dur métier, tu sais?\p"
    .string "Si tu veux un autre combat, je\n"
    .string "serai au DOJO plus tard.$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_INDIGOJUNCTION_POLICEMAN
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "Seuls les DRESSEURS qui ont\n"
    .string "fait leurs preuves passent.$"

VictoryRoadGate_Text_Kimono:
    .string "Désolée petit, ce passage est\n"
    .string "fermé tant que personne ne\l"
    .string "s'occupe de ce POKéMON\l"
    .string "LÉGENDAIRE…$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "Tu n'as pas tous les BADGES\n"
    .string "d'ARÈNE de JOHTO.\p"
    .string "Désolé, je ne peux pas te\n"
    .string "laisser passer.$"

VictoryRoadGate_Text_EightBadges:
    .string "Oh! Les huit BADGES de JOHTO!\p"
    .string "Je t'en prie, passe donc!$"

VictoryRoadGate_Text_LeftBlackBelt:
    .string "Ce chemin mène au MONT ARGENT.\p"
    .string "Là-bas, tu verras des POKéMON\n"
    .string "d'une force effrayante.$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "Tu vas à la LIGUE POKéMON?\p"
    .string "Le CONSEIL 4 est d'une force\n"
    .string "effrayante, et il t'attend!$"
