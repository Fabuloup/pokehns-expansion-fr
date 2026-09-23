OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "Oh… Bonjour, {PLAYER}.\p"
	.string "Ces assiettes devant moi ne sont\n"
	.string "pas toutes à moi…\p"
	.string "Euh…\p"
	.string "En fait, la personne assise ici\n"
	.string "avant moi a beaucoup mangé…\p"
	.string "Si tu veux un autre combat,\n"
	.string "viens me voir au DOJO de\l"
	.string "SAFRANIA.$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "Hah! Tes POKéMON ont l'air bien\n"
	.string "légers!\p"
	.string "Ils n'ont pas la force de\n"
	.string "pousser des rochers.\p"
	.string "Tiens, utilise ceci et apprends-\n"
	.string "leur FORCE!$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "En mer, la seule chose sur qui\n"
	.string "compter, c'est soi-même!\p"
	.string "Je suis fier de mes muscles!\n"
	.string "Tu devrais t'entraîner comme moi!$"

OlivineCity_Text_CafeFishingGuru:
	.string "La carte du CAFÉ D'OLIVILLE est\n"
	.string "pleine de plats costauds pour\l"
	.string "les MARINS balèzes comme moi!$"

OlivineCity_Text_CafeSailor:
	.string "Chaque fois que je débarque en\n"
	.string "ville, je passe au CAFÉ\l"
	.string "D'OLIVILLE.\p"
	.string "Tout sur la carte me donne des\n"
	.string "forces. Je ne peux plus\l"
	.string "m'arrêter!$"

