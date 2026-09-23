Route11_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN_HNS, Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON_HNS, Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN_HNS, Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL_HNS, Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_EventScript_Item_Grass_Knot::
    finditem ITEM_TM_GRASS_KNOT
    end

Route11_Text_Engineer:
	.string "J'ai vu un étrange POKéMON\n"
	.string "grimper aux arbres, mais ce\l"
	.string "n'était pas un FÉROSINGE…$"

Route11_Text_YoungsterOwenSeen:
	.string "On ne triche pas avec les POKéMON.\p"
	.string "Combattons à la loyale!$"

Route11_Text_YoungsterOwenBeaten:
	.string "Hein? Comment est-ce possible?$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "J'ai combattu loyalement et avec\n"
	.string "honneur.\p"
	.string "Je ne regrette rien.$"

Route11_Text_YoungsterJasonSeen:
	.string "Ça me gratte et me chatouille un\n"
	.string "peu quand je porte un short dans\l"
	.string "les hautes herbes.$"

Route11_Text_YoungsterJasonBeaten:
	.string "Aïe! Je me suis fait écraser!$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "Je vais attraper plus de POKéMON\n"
	.string "dans les hautes herbes.$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "…\p"
	.string "J'ai perdu les yeux fermés…$"

Route11_Text_PsychicFidelSeen:
	.string "Je le vois…\p"
	.string "Je vois tout ce qui te concerne…$"

Route11_Text_PsychicFidelBeaten:
	.string "Je n'avais pas prévu ta puissance…$"

Route11_Text_PsychicFidelAfterBattle:
	.string "La force des convictions…\p"
	.string "Tu es fort car tu crois en tes\n"
	.string "POKéMON.$"

Route11_Text_Sign:
	.string "ROUTE 11$"
