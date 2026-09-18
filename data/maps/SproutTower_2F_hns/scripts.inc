SproutTower_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO_HNS, SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND_HNS, SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "Même après un combat rude, la\n"
	.string "TOUR ne cédera pas.$"

SproutTower_Text_SageNico_Beaten:
	.string "Je me suis battu, mais je suis\n"
	.string "trop faible.$"

SproutTower_Text_SageNico_AfterBattle:
	.string "Le pilier flexible protège la\n"
	.string "TOUR de tout, même des séismes.$"

SproutTower_Text_SageEdmond_Seen:
	.string "…Ondoyer comme les feuilles\n"
	.string "dans le vent…$"

SproutTower_Text_SageEdmond_Beaten:
	.string "Oh! Je suis faible!$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "J'ai essayé de copier les doux\n"
	.string "mouvements de CHÉTIFLOR en\l"
	.string "combat…\p"
	.string "Mais je manque d'entraînement.$"

SproutTower_Text_2F_Statue:
	.string "Une statue de POKéMON…\p"
	.string "Elle a l'air très distinguée.$"
