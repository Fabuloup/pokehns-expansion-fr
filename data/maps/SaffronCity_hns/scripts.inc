SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "BAOBA$"

SaffronCity_Text_Baoba:
	.string "DIRECTEUR BAOBA : {PLAYER} !\p"
	.string "C'est le DIRECTEUR BAOBA.\p"
	.string "Je t'appelle pour te dire que le\n"
	.string "PARC SAFARI s'est encore agrandi !\p"
	.string "Enfin, mon PARC SAFARI est\n"
	.string "entièrement terminé !\p"
	.string "Tu te souviens où il est, hein ?\p"
	.string "Juste à l'ouest d'IRISIA !\n"
	.string "À bientôt !$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "J'adore GOUPIX ! :D$"

SaffronCity_Text_Lass1:
	.string "Une fillette experte dans l'art\n"
	.string "d'imiter les gens vit ici.\p"
	.string "Elle imite même les autres.\n"
	.string "C'est déroutant.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La COPIEUSE semblait malheureuse.\p"
	.string "Elle a perdu sa POKéPOUPÉE\n"
	.string "préférée, un MÉLOFÉE.$"

SaffronCity_Text_PokefanM:
	.string "Tu viens de JOHTO ?\p"
	.string "Tu peux rentrer vite si le TRAIN\n"
	.string "MAGNÉTIQUE fonctionne.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "Tu viens de JOHTO ?\p"
	.string "Tu peux rentrer vite en prenant\n"
	.string "le TRAIN MAGNÉTIQUE.$"

SaffronCity_Text_CooltrainerM:
	.string "Je suis allé à l'ARÈNE, impatient\n"
	.string "d'affronter des Dresseurs…\p"
	.string "Mais je suis entré dans l'ancienne\n"
	.string "ARÈNE juste à côté.\p"
	.string "J'étais vraiment gêné.$"

SaffronCity_Text_CooltrainerF:
	.string "Voici la SYLPHE SARL, célèbre pour\n"
	.string "ses produits POKéMON.\p"
	.string "Autrefois, la TEAM ROCKET voulait\n"
	.string "s'emparer de l'entreprise.$"

SaffronCity_Text_Fisher:
	.string "Miam… Miam…\p"
	.string "Il paraît que de gros ennuis se\n"
	.string "préparent à la CENTRALE.\p"
	.string "Miam… Miam…$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "Miam… Miam…\p"
	.string "Il paraît qu'il y a eu de gros\n"
	.string "ennuis à la CENTRALE.\p"
	.string "Miam… Miam… Aaah, je suis repu !$"

SaffronCity_Text_Youngster1:
	.string "Entrer pour la première fois dans\n"
	.string "une ruelle me rend un peu nerveux.$"

SaffronCity_Text_Youngster2:
	.string "À JADIELLE, la SALLE DE CONCOURS\n"
	.string "réunit des Dresseurs venus de\l"
	.string "partout.$"

SaffronCity_Text_Lass2:
	.string "Notre ville a eu droit à une\n"
	.string "émission de radio.\p"
	.string "C'est agréable d'entendre vanter\n"
	.string "sa ville, mais aussi un peu\l"
	.string "gênant.$"

SaffronCity_Text_Sign:
	.string "SAFRANIA\p"
	.string "La brillante cité du commerce$"

SaffronCity_Text_GymSign:
	.string "SAFRANIA\n"
	.string "ARÈNE POKéMON\l"
	.string "CHAMPIONNE : MORGANE\p"
	.string "Maîtresse des POKéMON PSY !$"

SaffronCity_Text_FightingDojoSign:
	.string "Bienvenue à tous !\n"
	.string "DOJO$"

SaffronCity_Text_SilphCoSign:
	.string "SYLPHE SARL\n"
	.string "IMMEUBLE DE BUREAUX$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "MAISON DE MONSIEUR\n"
	.string "PSY$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "SAFRANIA\n"
	.string "GARE DU TRAIN MAGNÉTIQUE$"
