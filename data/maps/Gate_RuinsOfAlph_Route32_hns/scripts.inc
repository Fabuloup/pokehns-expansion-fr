Gate_RuinsOfAlph_Route32_hns_MapScripts::
	.byte 0


Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_Text_PokefanM:
	.string "Tu étudies les RUINES?\n"
	.string "Voilà un futur scientifique.$"

Gate_RuinsOfAlph_Route32_Text_Youngster:
	.string "Il y a des dessins sur des\n"
	.string "panneaux de pierre.\p"
	.string "J'ai essayé de les bouger.\n"
	.string "Je me demande ce que c'est.$"
