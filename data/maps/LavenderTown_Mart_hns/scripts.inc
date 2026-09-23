LavenderTown_Mart_hns_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Pokefan::
	msgbox LavenderMart_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderMart_Text_Rocker, MSGBOX_NPC
	end

LavenderMart_Text_PokefanM:
	.string "REPOUSSE est indispensable pour\n"
	.string "explorer une grotte.\p"
	.string "J'adore explorer, et pourtant je\n"
	.string "n'ai pas encore vu toutes les\l"
	.string "grottes.$"

LavenderMart_Text_Rocker:
	.string "On m'a parlé d'un artisan qui\n"
	.string "fabrique des BALLS sur mesure à\l"
	.string "ÉCORCIA, une ville de JOHTO.\p"
	.string "J'aimerais bien en avoir.$"
