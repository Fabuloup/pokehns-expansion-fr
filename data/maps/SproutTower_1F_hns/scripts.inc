SproutTower_1F_hns_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW_HNS, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "Nous montons la garde dans cette\n"
	.string "tour.\p"
	.string "Nous y exprimons notre gratitude\n"
	.string "envers tous les POKéMON.$"

SproutTower_Text_SageChow_Beaten:
	.string "M-Merci!$"

SproutTower_Text_SageChow_AfterBattle:
	.string "Tous les êtres vivent grâce à\n"
	.string "une entente.\p"
	.string "Nous devons toujours en être\n"
	.string "reconnaissants.$"

SproutTower_Text_1F_Sage1:
	.string "Celui ou celle qui arrivera au\n"
	.string "sommet recevra une CS.$"

SproutTower_Text_1F_Sage2:
	.string "La TOUR CHÉTIFLOR a été bâtie\n"
	.string "il y a longtemps pour entraîner\l"
	.string "les POKéMON.$"

SproutTower_Text_1F_Granny:
	.string "Un CHÉTIFLOR haut de 30 mètres…\p"
	.string "On raconte que c'est en fait le\n"
	.string "pilier central d'ici.$"

SproutTower_Text_1F_Teacher:
	.string "Vois-tu le pilier trembler?\p"
	.string "On s'entraîne sec au-dessus.$"

SproutTower_Text_1F_Statue:
	.string "Une statue de POKéMON…\p"
	.string "Elle a l'air très distinguée.$"
