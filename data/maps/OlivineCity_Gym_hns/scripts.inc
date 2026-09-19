OlivineCity_Gym_hns_MapScripts::
	.byte 0

OlivineCity_Gym_EventScript_Gent::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Gent2
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Gent2::
	msgbox OlivineCity_Gym_Text_Gent2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow1::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC1
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveLeft4
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveLeft3
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveLeft2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveLeft1
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveLeft0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 6
	release
	end

OlivineCity_Gym_EventScript_MoveLeft0::
	turnobject VAR_TEMP_0, DIR_WEST
	return

OlivineCity_Gym_EventScript_MoveLeft1::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft2::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft3::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft4::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_Text_Gent:
	.string "Je savais que tu viendrais.\p"
	.string "Merci d'avoir aidé la CHAMPIONNE,\n"
	.string "mais combattre est autre chose.\p"
	.string "Vas-y!$"

OlivineCity_Gym_Text_Gent2:
	.string "Impressionnant!\n"
	.string "Poursuis ton voyage vers\l"
	.string "d'autres horizons.\p"
	.string "Puisque tu peux utiliser SURF, va\n"
	.string "l'essayer au LAC COLÈRE!$"

OlivineCity_Gym_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Lass2
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Lass2::
	msgbox OlivineCity_Gym_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow2::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC2
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveRight0
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveRight1
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveRight2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveRight3
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveRight4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 7
	release
	end

OlivineCity_Gym_EventScript_MoveRight0::
	turnobject VAR_TEMP_0, DIR_EAST
	return

OlivineCity_Gym_EventScript_MoveRight1::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight2::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight3::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight4::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_Text_Lass:
	.string "Héhé…\n"
	.string "J'ai vu tes capacités\l"
	.string "au PHARE.\p"
	.string "Il est temps de les montrer à\n"
	.string "JASMINE! Bonne chance!$"

OlivineCity_Gym_Text_Lass2:
	.string "Tu es incroyable…\n"
	.string "Avec un tel potentiel, vise\l"
	.string "encore plus haut.\p"
	.string "Es-tu allé à ACAJOU?$"

OlivineCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineCity_Gym_EventScript_GymGuideSick
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_GymGuideAfter
	msgbox OlivineCity_Gym_Text_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideSick::
	msgbox OlivineCity_Gym_Text_GymGuidePreText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideAfter::
	msgbox OlivineCity_Gym_Text_GymGuideWinText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymGuideText:
	.string "JASMINE utilise le type ACIER,\n"
	.string "récemment découvert.\p"
	.string "Elle possède non pas un,\n"
	.string "mais deux atouts.\p"
	.string "Le premier est un insecte d'acier\n"
	.string "qui peut augmenter son ATTAQUE.\p"
	.string "Le feu lui fait mal, mais il peut\n"
	.string "parfois encaisser de gros coups.\p"
	.string "Le second est un serpent de fer\n"
	.string "doté de capacités puissantes.\p"
	.string "Approche-le avec prudence.\p"
	.string "Il paraît lent, mais je l'ai vu\n"
	.string "frapper le premier, d'une manière\l"
	.string "surprenante.$"

OlivineCity_Gym_Text_GymGuideWinText:
	.string "C'était génial.\p"
	.string "Le type ACIER, hein?\p"
	.string "Quelle rencontre rapprochée avec\n"
	.string "l'inconnu!$"

OlivineCity_Gym_Text_GymGuidePreText:
	.string "JASMINE, la CHAMPIONNE, est au\n"
	.string "PHARE.\p"
	.string "Elle soigne un POKéMON malade.\p"
	.string "Un bon Dresseur doit savoir\n"
	.string "faire preuve de compassion.$"

OlivineCity_Gym_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Jasmine_Defeated
	msgbox OlivineCity_Gym_Text_JasmineSteelTypeIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_CianwoodCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_MahogCheckCianwood
	goto OlivineCity_Gym_EventScript_Jasmine_Battle1

OlivineCity_Gym_EventScript_JasmineVictory::
	message OlivineCity_Gym_Text_ReceivedMineralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OlivineCity_Gym_Text_JasmineBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_IRON_TAIL
	msgbox OlivineCity_Gym_Text_JasmineIronTailSpeech, MSGBOX_DEFAULT
	setvar VAR_OLIVINE_CITY_STATE, 8
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

OlivineCity_Gym_EventScript_CianwoodCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2

OlivineCity_Gym_EventScript_MahogCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2
	
OlivineCity_Gym_EventScript_Jasmine_Battle1::
	trainerbattle_no_intro TRAINER_JASMINE_1_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle2::
	trainerbattle_no_intro TRAINER_JASMINE_1_2_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle3::
	trainerbattle_no_intro TRAINER_JASMINE_1_3_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_JASMINE, OlivineCity_Gym_EventScript_Jasmine_Trade
	msgbox OlivineCity_Gym_Text_JasmineGoodLuck, MSGBOX_DEFAULT
	closemessage
	release
	end


OlivineCity_Gym_Text_JasmineSteelTypeIntro:
	.string "…Merci pour ton aide au\n"
	.string "PHARE…\p"
	.string "Mais ici, c'est différent.\n"
	.string "Permets-moi de me présenter.\p"
	.string "JASMINE, CHAMPIONNE D'ARÈNE.\n"
	.string "J'utilise le type ACIER.\p"
	.string "…Connais-tu le type ACIER?\p"
	.string "Il n'a été découvert que\n"
	.string "récemment.\p"
	.string "…Euh… Puis-je commencer?$"

OlivineCity_Gym_Text_JasmineBetterTrainer:
	.string "…Tu es meilleur Dresseur que moi,\n"
	.string "par ton talent et ta bonté.\p"
	.string "Selon les règles de la LIGUE,\n"
	.string "je te remets ce BADGE.$"

OlivineCity_Gym_Text_ReceivedMineralBadge:
	.string "{PLAYER} reçoit le BADGE MINÉRAL.$"

OlivineCity_Gym_Text_JasmineBadgeSpeech:
	.string "Le BADGE MINÉRAL augmente la \n"
	.string "DÉFENSE SPÉCIALE des POKéMON.\p"
	.string "…Euh… Prends aussi ceci…$"

OlivineCity_Gym_Text_JasmineIronTailSpeech:
	.string "…Cette CT permet d'apprendre\n"
	.string "QUEUE DE FER.$"

OlivineCity_Gym_Text_JasmineGoodLuck:
	.string "Euh… Je ne sais comment le dire,\n"
	.string "mais bonne chance…$"

OlivineCity_Gym_Text_JasmineRematchText:
	.string "…Félicitations, CHAMPION de JOHTO.\p"
	.string "Tu es devenu si fort…\p"
	.string "Je me demande si j'ai progressé.\p"
	.string "Veux-tu le vérifier?\p"
	.string "Veux-tu m'affronter à nouveau?$"

OlivineCity_Gym_Text_JasmineRematchDefeatText:
	.string "…Tu es meilleur Dresseur que moi,\n"
	.string "par ton talent et ta bonté.$"

OlivineCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Statue2
	msgbox OlivineCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Statue2::
	msgbox OlivineCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON D'OLIVILLE$"

OlivineCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON D'OLIVILLE\p"
	.string "DRESSEURS CERTIFIÉS PAR JASMINE:\n"
	.string "{PLAYER}$"

OlivineCity_Gym_EventScript_Jasmine_Trade::
	goto_if_set FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED, OlivineCity_Gym_EventScript_JasmineTradeCompleted
	setvar VAR_0x8005, INGAME_TRADE_STEELIX
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox OlivineCity_Gym_Text_JasmineWantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox OlivineCity_Gym_Text_JasmineTakeCare, MSGBOX_DEFAULT
	setflag FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_Gym_EventScript_JasmineDeclineTrade::
	msgbox OlivineCity_Gym_Text_JasmineDeclineTrade, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_EventScript_JasmineTradeCompleted::
	msgbox OlivineCity_Gym_Text_JasmineTradeCompleted, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_Text_JasmineWantToTrade:
	.string "…Euh, {PLAYER}…\n"
	.string "J'ai une demande à te faire.\p"
	.string "J'élève ce STEELIX depuis qu'il\n"
	.string "n'était qu'un petit ONIX.\p"
	.string "Mais RUSTY serait plus heureux\n"
	.string "avec un Dresseur comme toi.\p"
	.string "Échangerais-tu l'un de tes\n"
	.string "POKéMON contre mon RUSTY?$"

OlivineCity_Gym_Text_JasmineTakeCare:
	.string "…Merci.\n"
	.string "Sois gentil avec RUSTY…$"

OlivineCity_Gym_Text_JasmineDeclineTrade:
	.string "…Oh… Ce n'est pas grave.\n"
	.string "Je comprends…$"

OlivineCity_Gym_Text_JasmineTradeCompleted:
	.string "…Comment va RUSTY?\n"
	.string "J'espère que tu en prends soin…$"
