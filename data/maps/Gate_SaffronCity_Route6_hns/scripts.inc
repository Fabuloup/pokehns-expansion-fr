Gate_SaffronCity_Route6_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "Bienvenue à SAFRANIA, berceau du\n"
	.string "TRAIN MAGNÉTIQUE!\p"
	.string "…C'est ce que je dirais\n"
	.string "d'habitude, mais le TRAIN\l"
	.string "MAGNÉTIQUE ne circule plus.\p"
	.string "Il n'est plus alimenté, car il y\n"
	.string "a un problème à la CENTRALE.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "Le TRAIN MAGNÉTIQUE est ce qui\n"
	.string "fait la renommée de SAFRANIA.$"
