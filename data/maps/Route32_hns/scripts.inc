Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end
	
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "Hop! Hop!\n"
	.string "Ça urge ou quoi?$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "{PLAYER}, c'est ça?\n"
	.string "Un type avec des lunettes\p"
	.string "te cherchait.\p"
	.string "Va voir toi-même. Il t'attend\n"
	.string "au CENTRE POKéMON.$"

Route32_Text_CooltrainerM_SproutTower:
	.string "As-tu visité la TOUR CHÉTIFLOR?\p"
	.string "Si tu passes par MAUVILLE, on\n"
	.string "attend de toi que tu t'y\l"
	.string "entraînes.\p"
	.string "C'est la base pour un Dresseur!\p"
	.string "Va à la TOUR CHÉTIFLOR!$"

Route32_Text_CooltrainerM_VioletGym:
	.string "As-tu visité l'ARÈNE POKéMON?\p"
	.string "Tu peux y mettre tes POKéMON et\n"
	.string "toi-même à l'épreuve.\p"
	.string "C'est un passage obligé pour\n"
	.string "tout Dresseur!$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "Tu as de bons POKéMON, toi.\p"
	.string "Ça doit venir de l'entraînement\n"
	.string "que tu leur as donné autour de\l"
	.string "MAUVILLE.\p"
	.string "Les combats à l'ARÈNE ont dû\n"
	.string "beaucoup t'aider.\p"
	.string "En souvenir de MAUVILLE, accepte\n"
	.string "ceci.\p"
	.string "Cela augmente la puissance des\n"
	.string "capacités de type PLANTE.$"

Route32_Text_CooltrainerM_Experiences:
	.string "Ta visite à MAUVILLE te sera\n"
	.string "bénéfique pour la suite.$"

Route32_Text_SlowpokeTailOffer:
	.string "Hé toi! Ça te dit une bonne\n"
	.string "QUEUE RAMOLOSS, nourrissante\l"
	.string "et savoureuse?\p"
	.string "Pour toi, j'fais un prix:\n"
	.string "¥1,000,000!\p"
	.string "Tu vas la vouloir!$"

Route32_Text_ThoughtKidsLoaded:
	.string "Tss! Je croyais les gamins\n"
	.string "pleins aux as, de nos jours…$"

Route32_Text_RefusedSlowpokeTail:
	.string "T'en veux pas?\n"
	.string "Alors dégage. Ouste!$"

Route32_Text_FisherJustin_Seen:
	.string "Hééé!\p"
	.string "Tu m'as fait perdre mon poisson!$"

Route32_Text_FisherJustin_Beaten:
	.string "Splash!$"

Route32_Text_FisherJustin_After:
	.string "Du calme, du sang-froid…\n"
	.string "L'essence de la pêche et des\l"
	.string "POKéMON, c'est la même.$"

Route32_Text_FisherRalph1_Seen:
	.string "La pêche et les POKéMON, je\n"
	.string "gère les deux.\p"
	.string "C'est pas un gamin qui va me\n"
	.string "battre!$"

Route32_Text_FisherRalph1_Beaten:
	.string "Tss! J'ai voulu aller trop\n"
	.string "vite…$"

Route32_Text_FisherRalph1_After:
	.string "La pêche est une passion pour\n"
	.string "la vie.\p"
	.string "Et les POKéMON, des amis pour\n"
	.string "la vie!$"

Route32_Text_RalphRegister:
	.string "La pêche est une passion pour\n"
	.string "la vie.\p"
	.string "Et les POKéMON, des amis pour\n"
	.string "la vie!$"

Route32_Text_RalphRematchIntro:
	.string "La pêche et les POKéMON, je\n"
	.string "gère les deux.\p"
	.string "C'est pas un gamin qui va me\n"
	.string "battre!$"

Route32_Text_RalphRematchDefeat:
	.string "Tss! J'ai voulu aller trop\n"
	.string "vite…$"

Route32_Text_RalphPostRematch:
	.string "La pêche est une passion pour\n"
	.string "la vie.\p"
	.string "Et les POKéMON, des amis pour\n"
	.string "la vie!$"

Route32_Text_FisherHenry_Seen:
	.string "Mes POKéMON? Frais pêchés du\n"
	.string "matin!$"

Route32_Text_FisherHenry_Beaten:
	.string "TREMPETTE?$"

Route32_Text_FisherHenry_After:
	.string "Les POKéMON à peine pêchés ne\n"
	.string "font pas le poids face à ceux\l"
	.string "qu'on a bien élevés.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "Jamais vu par ici, toi.\n"
	.string "Tu te crois costaud?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "T'es fort!$"

Route32_Text_YoungsterAlbert_After:
	.string "Je serai le meilleur avec mes\n"
	.string "POKéMON préférés.\p"
	.string "Pas question de prendre les\n"
	.string "mêmes gros balèzes que tout\l"
	.string "le monde.$"

Route32_Text_YoungsterGordon_Seen:
	.string "J'ai trouvé de bons POKéMON\n"
	.string "dans les hautes herbes!\p"
	.string "Je crois qu'ils feront\n"
	.string "l'affaire!$"

Route32_Text_YoungsterGordon_Beaten:
	.string "Et ben ça alors. Je croyais\n"
	.string "gagner.$"

Route32_Text_YoungsterGordon_After:
	.string "Y'a plein de trucs qui\n"
	.string "s'accrochent dans l'herbe.$"

Route32_Text_CamperRoland_Seen:
	.string "Ce regard… Tu m'intrigues.$"

Route32_Text_CamperRoland_Beaten:
	.string "Hmmm. C'est décevant.$"

Route32_Text_CamperRoland_After:
	.string "Évite les regards si tu ne veux\n"
	.string "pas te battre.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Ah-ha. Ouais, et tu sais…\p"
	.string "Pardon? Un combat? J'suis au\n"
	.string "téléphone.\p"
	.string "Bon, d'accord. Mais fais vite.$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "Oh! Il faut que je passe mes\n"
	.string "nerfs!$"

Route32_Text_PicnickerLiz1_After:
	.string "J'avais une belle conversation…$"

Route32_Text_LizRegister:
	.string "J'avais une belle conversation…$"

Route32_Text_LizRematchIntro:
	.string "Ah-ha. Ouais, et tu sais…\p"
	.string "Pardon? Un combat? J'suis au\n"
	.string "téléphone.\p"
	.string "Bon, d'accord. Mais fais vite.$"

Route32_Text_LizRematchDefeat:
	.string "Oh! Il faut que je passe mes\n"
	.string "nerfs!$"

Route32_Text_LizPostRematch:
	.string "J'avais une belle conversation…$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "Ce BADGE! Il vient de MAUVILLE!\n"
	.string "T'as battu ALBERT?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "Je connais mes faiblesses.$"

Route32_Text_BirdKeeperPeter_After:
	.string "Je devrais m'entraîner encore\n"
	.string "à l'ARÈNE de MAUVILLE.$"

Route32_Text_RoarIntro:
	.string "GRAAAAA! LES GENS FUIENT QUAND\n"
	.string "JE HURLE! MAIS TOI, TU ES VENU!\p"
	.string "ÇA ME PLAÎT! TIENS, PRENDS ÇA!$"

Route32_Text_RoarOutro:
	.string "GRAAAAAH! C'EST HURLEMENT!\p"
	.string "MÊME LES POKéMON FUIENT DEVANT\n"
	.string "UN BON HURLEMENT!$"

Route32_Text_MeetFrieda:
	.string "VANESSA: Ouaiis!\p"
	.string "Je suis VANESSA, de la FAMILLE\n"
	.string "DES JOURS! Enchantée!\p"
	.string "Si tu devines mon jour préféré,\n"
	.string "tu auras une récompense.$"

Route32_Text_FriedaGivesGift:
	.string "Voilà un PIC VENIN pour toi!$"

Route32_Text_FriedaGaveGift:
	.string "VANESSA: Donne-le à un POKéMON\n"
	.string "qui a des capacités de type\l"
	.string "POISON.\p"
	.string "Oh!\p"
	.string "C'est terrible!\p"
	.string "Tu verras à quel point ça les\n"
	.string "améliore!$"

Route32_Text_FriedaFriday:
	.string "VANESSA: Ouais! Quel jour tu\n"
	.string "aimes, toi?\p"
	.string "Moi j'aime le vendredi, et\n"
	.string "oui!\p"
	.string "Pas toi? Hein? Pas toi?$"

Route32_Text_FriedaNope:
	.string "VANESSA: Pas celui-là!$"

Route32_Text_Sign1:
	.string "ROUTE 32\p"
	.string "MAUVILLE - ÉCORCIA$"

Route32_Text_Sign2:
	.string "RUINES D'ALPHA\n"
	.string "ENTRÉE EST$"

Route32_Text_Sign3:
	.string "CAVES JUMELLES\n"
	.string "TOUT DROIT$"
