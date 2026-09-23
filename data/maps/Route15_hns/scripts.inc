Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_HILLARY_2_HNS, Route15_EventScript_RematchHillaryTryGiveItem
	end

Route15_EventScript_RematchHillaryTryGiveItem::
	checkitem ITEM_TM_ENERGY_BALL
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_ENERGY_BALL
	closemessage
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP_HNS, Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY_HNS, Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY_HNS, Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY_HNS, Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten, Route15_EventScript_RegisterBilly
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBilly
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBilly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY_HNS
	release
	end

Route15_EventScript_RematchBilly::
	trainerbattle_rematch TRAINER_BILLY_HNS, Route15_Text_BillyRematchIntro, Route15_Text_BillyRematchDefeat
	msgbox Route15_Text_BillyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_BILLY_2_HNS, Route15_EventScript_RematchBillyTryGiveItem
	end

Route15_EventScript_RematchBillyTryGiveItem::
	checkitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_FACADE
	closemessage
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "Tu n'as rien oublié?$"

Route15_Text_TeacherColetteBeaten:
	.string "Kyaaah!$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Avant de devenir professeure,\n"
	.string "j'oubliais beaucoup de choses.$"

Route15_Text_TeacherHillarySeen:
	.string "Par beau temps, je pense que\n"
	.string "les enfants préfèrent jouer dans\l"
	.string "cour plutôt qu'étudier en classe.$"

Route15_Text_TeacherHillaryBeaten:
	.string "Je ne voulais pas perdre…$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "Étudier est important, mais\n"
	.string "l'exercice l'est tout autant.$"

Route15_Text_HillaryRegister:
	.string "Tu m'as donné une leçon!\n"
	.string "Puis-je avoir ton numéro?$"

Route15_Text_HillaryRematchIntro:
	.string "Cette fois, je vais t'instruire!$"

Route15_Text_HillaryRematchDefeat:
	.string "Il faut tout reprendre…$"

Route15_Text_HillaryPostRematch:
	.string "Éduquer les POKéMON, c'est comme\n"
	.string "les enfants. Il faut être patient!$"

Route15_Text_SchoolboyKippSeen:
	.string "Attends. Je dois appeler ma maman.$"

Route15_Text_SchoolboyKippBeaten:
	.string "Désolé, Maman! J'ai perdu!$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "Ma mère s'inquiète tant que je\n"
	.string "dois l'appeler tout le temps.$"

Route15_Text_SchoolboyTommySeen:
	.string "Combattons. Je ne perdrai pas!$"

Route15_Text_SchoolboyTommyBeaten:
	.string "J'ai oublié de faire mes devoirs!$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Sayonara! Je viens d'apprendre ça\n"
	.string "en cours de japonais.$"

Route15_Text_SchoolboyJohnnySeen:
	.string "Nous visitons la TOUR RADIO de\n"
	.string "LAVANVILLE en cours d'éducation.$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "Tu es terriblement fort!$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "J'en ai assez de marcher. Je dois\n"
	.string "faire une pause.$"

Route15_Text_SchoolboyBillySeen:
	.string "Mon cours préféré, c'est le sport!$"

Route15_Text_SchoolboyBillyBeaten:
	.string "Oh non! Comment ai-je pu perdre?$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "Si les POKéMON étaient une matière\n"
	.string "scolaire, je serais le meilleur!$"

Route15_Text_BillyRegister:
	.string "J'aurais dû écouter en classe.\n"
	.string "Je peux avoir ton numéro?$"

Route15_Text_BillyRematchIntro:
	.string "J'ai beaucoup étudié!\n"
	.string "Laisse-moi te montrer mes progrès!$"

Route15_Text_BillyRematchDefeat:
	.string "Je dois étudier davantage…$"

Route15_Text_BillyPostRematch:
	.string "Les livres ne font pas tout.\n"
	.string "Il me faut aussi combattre!$"

Route15_Text_Sign:
	.string "ROUTE 15\p"
	.string "PARMANIE - LAVANVILLE$"
