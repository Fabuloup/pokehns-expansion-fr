PewterCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY_HNS
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "…Ouais, et l'ARÈNE de\n"
	.string "CRAMOIS'ÎLE a disparu.\p"
	.string "Ça m'a vraiment sidéré.\p"
	.string "…Oui? Je téléphone. Va-t'en!$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "RONDOUDOU: Pouu poupouu.$"

PewterCity_PokemonCenter_EventScript_Mondo::
	lock
	faceplayer
	goto_if_set FLAG_PEWTER_NPC_TRADE_COMPLETED, PewterCity_PokemonCenter_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HAUNTER, PewterCity_PokemonCenter_Text_WantToTrade, PewterCity_PokemonCenter_EventScript_DeclineTrade, PewterCity_PokemonCenter_EventScript_NotRequestedMon, PewterCity_PokemonCenter_Text_TakeCare
	setflag FLAG_PEWTER_NPC_TRADE_COMPLETED
	release
	end

PewterCity_PokemonCenter_EventScript_DeclineTrade::
	msgbox PewterCity_PokemonCenter_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_PokemonCenter_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_TradeCompleted::
	msgbox PewterCity_PokemonCenter_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_Text_WantToTrade:
	.string "Je voyage partout à la recherche\n"
	.string "d'un bon {STR_VAR_1}.\p"
	.string "Tu m'en échanges un contre mon\n"
	.string "{STR_VAR_2}?$"

PewterCity_PokemonCenter_Text_TakeCare:
	.string "Merci beaucoup!\n"
	.string "Prends soin de mon {STR_VAR_1}!$"

PewterCity_PokemonCenter_Text_DeclineTrade:
	.string "Non? Dommage…\n"
	.string "Mon SPECTRUM t'aurait plu.$"

PewterCity_PokemonCenter_Text_NotRequestedMon:
	.string "Hmm, ce n'est pas un\n"
	.string "{STR_VAR_1}. Ce n'est pas ce que\l"
	.string "je cherche.$"

PewterCity_PokemonCenter_Text_TradeCompleted:
	.string "Alors, ce SPECTRUM?\n"
	.string "C'est un sacré farceur!$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "La plupart des POKéMON somnolent\n"
	.string "s'ils entendent chanter un\l"
	.string "RONDOUDOU.\p"
	.string "Certaines capacités ne peuvent\n"
	.string "servir qu'à un POKéMON endormi.$"
