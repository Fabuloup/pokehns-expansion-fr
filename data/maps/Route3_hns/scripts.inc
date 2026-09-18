Route3_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS_HNS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN_HNS, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY_HNS, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT_HNS, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "Ah! Le temps est toujours aussi\n"
	.string "beau.$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "Il fait beau, mais je suis\n"
	.string "trempé…$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "Quand il pleut, j'ai du mal à\n"
	.string "m'enflammer…$"

Route3_Text_YoungsterWarren_Seen:
	.string "Hmmm… Je ne sais pas quoi\n"
	.string "faire…$"

Route3_Text_YoungsterWarren_Beaten:
	.string "Je savais que j'allais perdre…$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "Tu avais l'air fort.\p"
	.string "J'avais peur de t'affronter…$"

Route3_Text_YoungsterJimmy_Seen:
	.string "Je cours comme le vent!$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "Soufflé!$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "Je porte un short toute l'année.\p"
	.string "C'est ma règle de style.$"

Route3_Text_FirebreatherBurt_Seen:
	.string "Approche et regarde bien ça!$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "Aïe! Ça brûle!$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "Le meilleur cracheur de feu de\n"
	.string "KANTO, c'est moi.\p"
	.string "Mais pas le meilleur DRESSEUR…$"

Route3_Text_MtMoonSquareSign:
	.string "PLACE DU MONT SÉLÉNITE\p"
	.string "Il suffit de monter l'escalier.$"

