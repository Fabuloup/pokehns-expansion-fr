VermilionCity_House1_hns_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_Fisher::
	msgbox VermilionCity_House1_Text_FishingDude, MSGBOX_NPC
	end
VermilionCity_House1_EventScript_Photo::
	msgbox VermilionCity_House1_Text_Photo, MSGBOX_NPC
	end
VermilionCity_House1_Text_FishingDude:
	.string "Je suis le PÊCHEUR, l'aîné des\n"
	.string "FRÈRES PÊCHEURS.\p"
	.string "Tu as rencontré le GOUROU DE LA\n"
	.string "PÊCHE au LAC COLÈRE?\p"
	.string "Il rêve de voir la plus grande\n"
	.string "MAGICARPE du monde.\p"
	.string "Si ça ne t'ennuie pas, montre-lui\n"
	.string "les MAGICARPE que tu attrapes.\p"
	.string "Qui sait, tu attraperas\n"
	.string "peut-être celle de ses rêves.$"

VermilionCity_House1_Text_Photo:
	.string "Une photo de gens qui pêchent…\p"
	.string "Ils ont l'air de bien s'amuser…$"
