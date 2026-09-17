VioletCity_House1_hns_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_EventScript_Rudy::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_ONIX, VioletCity_House1_Text_YouWillTradeWontYou, VioletCity_House1_EventScript_DeclineTrade, VioletCity_House1_EventScript_NotRequestedMon, VioletCity_House1_Text_MonYouTakeCare
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	release
	end

VioletCity_House1_EventScript_DeclineTrade::
	msgbox VioletCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VioletCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_TradeCompleted::
	msgbox VioletCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_Text_YouWillTradeWontYou:
	.string "Je collectionne les POKéMON!\n"
	.string "Tu as un {STR_VAR_1}?\p"
	.string "Veux-tu l'échanger contre mon\n"
	.string "{STR_VAR_2}?$"

VioletCity_House1_Text_MonYouTakeCare:
	.string "Youpi! J'ai un {STR_VAR_1}!\p"
	.string "{STR_VAR_2}, prends soin de toi!$"

VioletCity_House1_Text_ThisIsntAMon:
	.string "Euh, non, je ne crois pas.\n"
	.string "Ce n'est pas un {STR_VAR_1}.$"

VioletCity_House1_Text_YouWontTradeMe:
	.string "Tu ne veux pas l'échanger? Mince…$"

VioletCity_House1_Text_After:
	.string "Salut! Comment va mon ancien ONIX?$"

VioletCity_House1_Text_PokefanM:
	.string "Un POKéMON obtenu par échange\n"
	.string "grandit plus vite.\p"
	.string "Mais sans le bon BADGE d'ARÈNE,\n"
	.string "il risque de ne pas t'obéir.$"
