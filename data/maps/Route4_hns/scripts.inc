Route4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK_HNS, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE_HNS, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON_HNS, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "J'élève mes POKéMON. Ça te dit\n"
	.string "un combat?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "Argh! J'ai perdu ce coup-ci…$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "Si tu veux faire monter un\n"
	.string "POKéMON précis, envoie-le en\l"
	.string "premier, puis change aussitôt.\p"
	.string "C'est comme ça qu'on fait.$"

Route4_Text_PicnickerHope_Seen:
	.string "J'ai le sentiment que je peux\n"
	.string "gagner.\p"
	.string "Voyons si j'ai raison!$"

Route4_Text_PicnickerHope_Beaten:
	.string "Oh, tu es bien trop fort.$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "Il paraît que des MÉLOFÉE\n"
	.string "apparaissent au MONT SÉLÉNITE.\p"
	.string "Mais où peuvent-ils bien être?$"

Route4_Text_PicnickerSharon_Seen:
	.string "Euh…\n"
	.string "Je…$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "……Je vais m'entraîner encore…$"

Route4_Text_MtMoonSquareSign:
	.string "NOUVELLE ENTRÉE DU MONT\n"
	.string "SÉLÉNITE SUITE À UN ÉBOULEMENT\p"
	.string "ATTENTION OÙ VOUS METTEZ LES\n"
	.string "PIEDS$"

