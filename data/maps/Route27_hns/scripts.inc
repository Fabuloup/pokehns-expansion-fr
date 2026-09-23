Route27_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	setspeaker Route27_Text_BaobaName
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_Text_BaobaName:
	.string "BAOBA$"

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    setflag FLAG_VISITED_KANTO
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
    
    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_DragonClaw::
    finditem ITEM_TM_DRAGON_CLAW
    end

Route27_EventScript_Item_Destiny_Knot::
    finditem ITEM_DESTINY_KNOT
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE_HNS, Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN_HNS, Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA_HNS, Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten, Route27_EventScript_RegisterReena
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchReena
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterReena::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_ReenaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_REENA_HNS
	release
	end

Route27_EventScript_RematchReena::
	trainerbattle_rematch TRAINER_REENA_HNS, Route27_Text_ReenaRematchIntro, Route27_Text_ReenaRematchDefeat
	msgbox Route27_Text_ReenaPostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN_HNS, Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT_HNS, Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE_HNS, Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten, Route27_EventScript_RegisterJose
	goto_if_set FLAG_JOSE_HAS_ITEM_HNS, Route27_EventScript_JoseGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchJose
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterJose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_JoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOSE_HNS
	release
	end

Route27_EventScript_RematchJose::
	trainerbattle_rematch TRAINER_JOSE_HNS, Route27_Text_JoseRematchIntro, Route27_Text_JoseRematchDefeat
	msgbox Route27_Text_JosePostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseGiveItem::
	msgbox Route27_Text_JoseHasItem, MSGBOX_DEFAULT
	giveitem VAR_JOSE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route27_EventScript_JoseNoRoom
	clearflag FLAG_JOSE_HAS_ITEM_HNS
	msgbox Route27_Text_JoseGaveItem, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseNoRoom::
	msgbox Route27_Text_JoseNoRoom, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT_HNS, Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
    .string "Hé!$"

Route27_Text_FisherMessage:
    .string "Tu sais ce que tu viens de faire?\p"
    .string "Tu as fait ton premier pas à\n"
    .string "KANTO.\p"
    .string "Regarde la CARTE de ton POKéMATOS.$"

Route27_Text_CooltrainermBlakeSeen:
    .string "Tu as l'air plutôt fort.\n"
    .string "Laisse-moi t'affronter!$"

Route27_Text_CooltrainermBlakeBeaten:
    .string "Aïe!$"

Route27_Text_CooltrainermBlakeAfter:
    .string "Si tu triomphes de ce rude voyage,\n"
    .string "la vérité te sera révélée!\p"
    .string "Hé, pardon, je voulais juste dire\n"
    .string "quelque chose de classe.$"

Route27_Text_CooltrainermBrianSeen:
    .string "Hum? Tu es fort, pas vrai?$"

Route27_Text_CooltrainermBrianBeaten:
    .string "Comme je le pensais!$"

Route27_Text_CooltrainermBrianAfter:
    .string "Un bon Dresseur sait reconnaître\n"
    .string "les autres bons Dresseurs.$"

Route27_Text_CooltrainerfReenaSeen:
    .string "Ne sous-estime pas les POKéMON\n"
    .string "sauvages du coin.$"

Route27_Text_CooltrainerfReenaBeaten:
    .string "Oh! Tu es beaucoup trop fort!$"

Route27_Text_CooltrainerfReenaAfter:
    .string "Tu n'es qu'un enfant, mais il ne\n"
    .string "faut pas te sous-estimer non plus.$"

Route27_Text_ReenaRegister:
    .string "Tu n'es qu'un enfant, mais il ne\n"
    .string "faut pas te sous-estimer non plus.$"

Route27_Text_ReenaRematchIntro:
    .string "Ne sous-estime pas les POKéMON\n"
    .string "sauvages du coin.$"

Route27_Text_ReenaRematchDefeat:
    .string "Oh! Tu es beaucoup trop fort!$"

Route27_Text_ReenaPostRematch:
    .string "Tu n'es qu'un enfant, mais il ne\n"
    .string "faut pas te sous-estimer non plus.$"

Route27_Text_CooltrainerfMeganSeen:
    .string "Il est rare de voir quelqu'un ici.\p"
    .string "Tu t'entraînes tout seul?$"

Route27_Text_CooltrainerfMeganBeaten:
    .string "Oh! Tu es vraiment fort!$"

Route27_Text_CooltrainerfMeganAfter:
    .string "J'étudie les POKéMON avant et\n"
    .string "leur évolution.\p"
    .string "L'évolution rend vraiment les\n"
    .string "POKéMON plus forts.\p"
    .string "Mais les évolutions apprennent\n"
    .string "aussi les capacités plus tard.$"

Route27_Text_PsychicGilbertSeen:
    .string "Ne dis rien!\p"
    .string "Je vais deviner ce que tu penses.\p"
    .string "Mmmmmmm…\p"
    .string "Trouvé! Tu relèves le défi de la\n"
    .string "LIGUE POKéMON!$"

Route27_Text_PsychicGilbertBeaten:
    .string "Tu es trop fort!$"

Route27_Text_PsychicGilbertAfter:
    .string "Avec ton talent, tu réussiras à\n"
    .string "la LIGUE.\p"
    .string "C'est ce que dit ma prémonition.$"

Route27_Text_BirdKeeperJoseSeen:
    .string "Cui! Cui! Cui-cui!$"

Route27_Text_BirdKeeperJoseBeaten:
    .string "Cui!$"

Route27_Text_BirdKeeperJoseAfter:
    .string "Les ORNITHOLOGUES imitent les\n"
    .string "oiseaux pour guider leurs POKéMON.$"

Route27_Text_JoseRegister:
    .string "Les ORNITHOLOGUES imitent les\n"
    .string "oiseaux pour guider leurs POKéMON.$"

Route27_Text_JoseRematchIntro:
    .string "Cui! Cui! Cui-cui!$"

Route27_Text_JoseRematchDefeat:
    .string "Cui!$"

Route27_Text_JosePostRematch:
    .string "Les ORNITHOLOGUES imitent les\n"
    .string "oiseaux pour guider leurs POKéMON.$"

Route27_Text_JoseHasItem:
    .string "Hé! J'ai trouvé quelque chose de\n"
    .string "brillant en observant les oiseaux!\p"
    .string "Tiens, c'est pour toi!$"

Route27_Text_JoseGaveItem:
    .string "Je trouve toutes sortes de choses\n"
    .string "ici, sur la ROUTE 27.\p"
    .string "Je te préviendrai si je trouve\n"
    .string "autre chose!$"

Route27_Text_JoseNoRoom:
    .string "Hum, ton SAC est plein.\p"
    .string "Reviens quand tu auras une place.$"

TohjoFalls_Text_Sign:
    .string "CHUTES TOHJO\p"
    .string "LE LIEN ENTRE KANTO ET JOHTO$"

Route27_Text_FisherScottSeen:
    .string "Je me sens en pleine forme!\p"
    .string "Je pourrais même battre le\n"
    .string "MAÎTRE de la LIGUE!$"

Route27_Text_FisherScottBeaten:
    .string "Non! Pas dans ce combat!$"

Route27_Text_FisherScottAfter:
    .string "Comme à la pêche, avec les POKéMON\n"
    .string "tout est fini si on abandonne.$"
