OlivineCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "Le MARIN du CAFÉ D'OLIVILLE, à\n"
	.string "côté, est très généreux.\p"
	.string "Il a appris FORCE à mon POKéMON.\p"
	.string "Il déplace maintenant de gros\n"
	.string "rochers sans effort.$"

OlivineCity_Text_PokecenterTeacher:
	.string "Il y a quelqu'un à IRISIA, de\n"
	.string "l'autre côté de la mer.\p"
	.string "Je l'ai entendu se vanter sans\n"
	.string "cesse de ses POKéMON rares.$"
