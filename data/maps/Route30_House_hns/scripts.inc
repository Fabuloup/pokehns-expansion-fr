Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "En suivant ce chemin vers le nord,\n"
	.string "tu trouveras chez M. POKéMON.\p"
	.string "Mais avant, laisse-moi te parler\n"
	.string "des BAIES!\p"
	.string "Les POKéMON peuvent se soigner\n"
	.string "en mangeant des BAIES.\p"
	.string "Ils peuvent même manger une BAIE\n"
	.string "qu'ils tiennent pendant un combat.\p"
	.string "À ÉCORCIA, FARGAS transforme aussi\n"
	.string "les BAIES en BALLS.\p"
	.string "Tiens, je t'en offre une!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Cherche des BAIES dans les arbres.\n"
	.string "Elles repoussent en peu de temps.$"
