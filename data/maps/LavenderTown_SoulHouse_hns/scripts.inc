LavenderTown_SoulHouse_hns_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "M. FUJI: Bienvenue.\p"
	.string "Hmm… Tu sembles élever tes\n"
	.string "POKéMON avec douceur et\l"
	.string "beaucoup d'amour.\p"
	.string "Ceux qui aiment les POKéMON\n"
	.string "viennent ici se recueillir sur\l"
	.string "les POKéMON disparus.\p"
	.string "Adresse une pensée aux âmes des\n"
	.string "POKéMON qui nous ont quittés.\p"
	.string "Je suis sûr que ça les rendra\n"
	.string "heureux.$"

SoulHouse_Text_Teacher:
	.string "Il y a d'autres tombes de\n"
	.string "POKéMON ici, je crois.\p"
	.string "Beaucoup de salles ne sont\n"
	.string "ouvertes qu'à M. FUJI.$"

SoulHouse_Text_Lass:
	.string "Je suis venue avec ma maman\n"
	.string "voir les tombes des POKéMON…$"

SoulHouse_Text_Granny:
	.string "Les POKéMON qui vivaient avec\n"
	.string "moi…\p"
	.string "Je les aimais comme mes\n"
	.string "petits-enfants…$"
