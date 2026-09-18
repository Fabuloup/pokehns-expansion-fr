Route46_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY_HNS, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED_HNS, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_HNS, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten, Route46_EventScript_RegisterErin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route46_EventScript_RematchErin
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_RegisterErin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_ErinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERIN_HNS
	release
	end

Route46_EventScript_RematchErin::
	trainerbattle_rematch TRAINER_ERIN_HNS, Route46_Text_ErinRematchIntro, Route46_Text_ErinRematchDefeat
	msgbox Route46_Text_ErinPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "Très bien ! Je vais te montrer la\n"
	.string "force des POKéMON de montagne !$"

Route46_Text_HikerBaileyBeaten:
	.string "Pitié ! Tu m'as montré ta\n"
	.string "force !$"

Route46_Text_HikerBaileyAfterBattle:
	.string "C'est fini. Ça ne me dérange pas.\n"
	.string "Nous, les MONTAGNARDS, sommes ainsi.$"

Route46_Text_CamperTedSeen:
	.string "J'élève aussi des POKéMON !\p"
	.string "Tu combats contre moi ?$"

Route46_Text_CamperTedBeaten:
	.string "Quoi… ?$"

Route46_Text_CamperTedAfterBattle:
	.string "J'ai fait de mon mieux, mais ça\n"
	.string "n'a pas suffi.\p"
	.string "Pas d'excuse, j'admets ma défaite.$"

Route46_Text_PicnickerErinSeen:
	.string "J'élève aussi des POKéMON !\p"
	.string "Tu combats contre moi ?$"

Route46_Text_PicnickerErinBeaten:
	.string "Oh, mince !$"

Route46_Text_PicnickerErinAfterBattle:
	.string "J'ai visité beaucoup d'ARÈNES, mais\n"
	.string "celle de DOUBLONVILLE est ma préférée.\p"
	.string "Elle est remplie de jolies fleurs !$"

Route46_Text_ErinRegister:
	.string "J'ai visité beaucoup d'ARÈNES, mais\n"
	.string "celle de DOUBLONVILLE est ma préférée.\p"
	.string "Elle est remplie de jolies fleurs !$"

Route46_Text_ErinRematchIntro:
	.string "J'élève aussi des POKéMON !\p"
	.string "Tu combats contre moi ?$"

Route46_Text_ErinRematchDefeat:
	.string "Oh, mince !$"

Route46_Text_ErinPostRematch:
	.string "J'ai visité beaucoup d'ARÈNES, mais\n"
	.string "celle de DOUBLONVILLE est ma préférée.\p"
	.string "Elle est remplie de jolies fleurs !$"

Route46_Text_PicnickerErin2Beaten:
	.string "Oh… Je n'arrête pas de perdre !\p"
	.string "Je vais devoir faire plus d'efforts !\n"
	.string "En tout cas, merci de combattre\n"
	.string "encore et encore contre moi.\p"
	.string "Voici le cadeau dont je te\n"
	.string "parlais l'autre fois.$"

Route46_Text_Sign:
	.string "ROUTE 46\n"
	.string "ROUTE DE MONTAGNE$"
