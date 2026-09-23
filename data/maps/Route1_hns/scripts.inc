Route1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY_HNS, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN_HNS, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "Quand deux Dresseurs se croisent,\n"
	.string "la première chose à faire est de\l"
	.string "se battre.$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "Ohhh… Mon bilan est mauvais…$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "Entre Dresseurs, il va de soi\n"
	.string "qu'on se bat dès qu'on se croise.$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "Hé toi! On se bat?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "Au tapis…$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "Tu es fort.\p"
	.string "Tu t'es manifestement entraîné\n"
	.string "dur.$"

Route1_Text_Sign:
	.string "ROUTE 1\p"
	.string "BOURG PALETTE - JADIELLE$"
