AlolaWater_hns_MapScripts::
	.byte 0


Alola_MelemeleSea_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_2_HNS, Alola_MelemeleSea_TrainerBattleSwimmer_Text_0, Alola_MelemeleSea_TrainerBattleSwimmer_Text_1
	msgbox Alola_MelemeleSea_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_MelemeleSea_TrainerBattleSwimmer_Text_0:
	.string "Que d'eau libre par ici!$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_1:
	.string "Aïe,\nje me suis claqué un muscle…$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_2:
	.string "Les courants sont forts ici.\n"
	.string "Ça doit attirer des POKéMON\l"
	.string "puissants!$"
