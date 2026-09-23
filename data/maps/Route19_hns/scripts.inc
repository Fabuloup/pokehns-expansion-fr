Route19_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD_HNS, Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER_HNS, Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN_HNS, Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME_HNS, Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_EventScript_Item_Brine::
    finditem ITEM_TM_BRINE
    end

Route19_Text_SwimmermHaroldSeen:
	.string "As-tu déjà nagé dans la mer\n"
	.string "la nuit?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Glou…$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "La nuit, la mer devient noire. On\n"
	.string "croirait qu'elle va nous avaler.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Pff, pff… Encore… un petit peu…\p"
	.string "jusqu'à… PARMANIE…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "Je me noie!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "J'ai… demandé à ma copine de nager\n"
	.string "jusqu'à PARMANIE… Pff…$"

Route19_Text_SwimmerfDawnSeen:
	.string "Les mauviettes me dégoûtent!$"

Route19_Text_SwimmerfDawnBeaten:
	.string "Je te battrais à la nage…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "PARMANIE est à deux brasses des\n"
	.string "ÎLES ÉCUME…\p"
	.string "Pff, mon copain joue au gros dur,\n"
	.string "mais quelle mauviette!$"

Route19_Text_SwimmermJeromeSeen:
	.string "Nager? Je suis nul.\p"
	.string "Je barbote juste dans ces\n"
	.string "eaux peu profondes.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "Je pensais pouvoir gagner.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "Je nage peut-être mal, mais\n"
	.string "j'adore la mer.$"

Route19_Text_Fisher1:
	.string "Désolé. Cette route est en\n"
	.string "travaux.\p"
	.string "Pour aller à CRAMOIS'ÎLE,\n"
	.string "pars plutôt au sud de BOURG\n"
	.string "PALETTE.$"

Route19_Text_Kingler:
	.string "KRABBOSS: KIIIIIIIIIIING$"

Route19_Text_Fisher1_RocksCleared:
	.string "Je suis en sueur. À l'eau!$"

Route19_Text_Fisher2:
	.string "Mince, KRABBOSS bloque la\n"
	.string "plage.$"

Route19_Text_FisherBefore:
	.string "Pas de pêche tant que ces KRABBOSS\n"
	.string "ne seront pas partis.$"

Route19_Text_Fisher2_RocksCleared:
	.string "Ces KRABBOSS sont enfin partis!\p"
	.string "Je peux de nouveau pêcher.$"

Route19_Text_Sign:
	.string "ROUTE 19\p"
	.string "PARMANIE - ÎLES ÉCUME$"

Route19_Text_CarefulSwimmingSign:
	.string "Soyez prudent si vous nagez\n"
	.string "jusqu'aux ÎLES ÉCUME.\p"
	.string "POLICE DE PARMANIE$"
