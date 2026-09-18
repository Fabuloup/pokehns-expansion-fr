Route28_House_hns_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_STEEL_WING, Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "Oh là là. Tu m'as trouvée.\p"
	.string "Ne parle de moi à personne, s'il\n"
	.string "te plaît.\p"
	.string "Je te donne ceci pour garder mon\n"
	.string "secret. D'accord?$"

Route28House_Text_Celebrity2:
	.string "C'est dur d'être une grande\n"
	.string "célébrité.\p"
	.string "Où que j'aille, on me poursuit.\p"
	.string "Je veux juste qu'on me laisse\n"
	.string "tranquille…$"

Route28House_Text_Fearow:
	.string "RAPASDEPIC: Rapaas!$"

