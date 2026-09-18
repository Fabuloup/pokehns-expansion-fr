Route17_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY_HNS, Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten, Route17_EventScript_RegisterRiley
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchRiley
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterRiley::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_RileyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RILEY_HNS
	release
	end

Route17_EventScript_RematchRiley::
	trainerbattle_rematch TRAINER_RILEY_HNS, Route17_Text_RileyRematchIntro, Route17_Text_RileyRematchDefeat
	msgbox Route17_Text_RileyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_RILEY_2_HNS, Route17_EventScript_RematchRileyTryGiveItem
	end

Route17_EventScript_RematchRileyTryGiveItem::
	checkitem ITEM_TM_TOXIC
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_TOXIC
	closemessage
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL_HNS, Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten, Route17_EventScript_RegisterJoel
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchJoel
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterJoel::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JoelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEL_HNS
	release
	end

Route17_EventScript_RematchJoel::
	trainerbattle_rematch TRAINER_JOEL_HNS, Route17_Text_JoelRematchIntro, Route17_Text_JoelRematchDefeat
	msgbox Route17_Text_JoelPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_JOEL_2_HNS, Route17_EventScript_RematchJoelTryGiveItem
	end

Route17_EventScript_RematchJoelTryGiveItem::
	checkitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BRICK_BREAK
	closemessage
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN_HNS, Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES_HNS, Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten, Route17_EventScript_RegisterCharles
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchCharles
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterCharles::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CharlesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHARLES_HNS
	release
	end

Route17_EventScript_RematchCharles::
	trainerbattle_rematch TRAINER_CHARLES_HNS, Route17_Text_CharlesRematchIntro, Route17_Text_CharlesRematchDefeat
	msgbox Route17_Text_CharlesPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CHARLES_2_HNS, Route17_EventScript_RematchCharlesTryGiveItem
	end

Route17_EventScript_RematchCharlesTryGiveItem::
	checkitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BULK_UP
	closemessage
	end

Route17_Text_BikerRileySeen:
	.string "Hé, toi ! Tu viens de JOHTO ?$"

Route17_Text_BikerRileyBeaten:
	.string "Waouh, tu cognes fort !$"

Route17_Text_BikerRileyAfterBattle:
	.string "Ne te crois pas tout permis !$"

Route17_Text_BikerJoelSeen:
	.string "Waouh. Il est cool, ce VÉLO !$"

Route17_Text_BikerJoelBeaten:
	.string "Mais tu n'as pas que le style…$"

Route17_Text_BikerJoelAfterBattle:
	.string "J'ai du style, mais je suis nul.\n"
	.string "Alors je ne suis pas si cool.\p"
	.string "Je dois m'entraîner davantage…$"

Route17_Text_BikerGlennSeen:
	.string "Hé ! On fait un combat express ?$"

Route17_Text_BikerGlennBeaten:
	.string "Aïe ! Quel couple moteur !$"

Route17_Text_BikerGlennAfterBattle:
	.string "Rouler sans les mains, c'est cool\n"
	.string "sur la PISTE CYCLABLE.$"

Route17_Text_BikerCharlesSeen:
	.string "On est les stars de la route !$"

Route17_Text_BikerCharlesBeaten:
	.string "Argh ! C'est l'accident !$"

Route17_Text_BikerCharlesAfterBattle:
	.string "La conduite imprudente cause des\n"
	.string "accidents ! Ralentis !$"

Route17_Text_RileyRegister:
	.string "Pas mal pour un môme de JOHTO !$"

Route17_Text_RileyRematchIntro:
	.string "JOHTO n'a qu'un coup à jouer !$"

Route17_Text_RileyRematchDefeat:
	.string "Je me suis fait écraser…$"

Route17_Text_RileyPostRematch:
	.string "Je devrais peut-être m'entraîner\n"
	.string "à JOHTO, finalement.$"

Route17_Text_JoelRegister:
	.string "Tu es plutôt cool, finalement !\n"
	.string "Échangeons nos numéros !$"

Route17_Text_JoelRematchIntro:
	.string "Voyons qui est le plus cool !$"

Route17_Text_JoelRematchDefeat:
	.string "Toujours pas assez cool…$"

Route17_Text_JoelPostRematch:
	.string "Je m'entraînerai pour être aussi\n"
	.string "cool que toi, petit !$"

Route17_Text_CharlesRegister:
	.string "Tu brises les cœurs comme moi !\n"
	.string "Donne-moi ton numéro !$"

Route17_Text_CharlesRematchIntro:
	.string "Je ne suis pas qu'une star de la\n"
	.string "route, je brise aussi les cœurs !$"

Route17_Text_CharlesRematchDefeat:
	.string "Encore dans le décor !$"

Route17_Text_CharlesPostRematch:
	.string "J'ai rencontré ton pareil à UNYS.\n"
	.string "Ne te plante pas !$"
