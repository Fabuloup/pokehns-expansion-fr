BattleFrontier_Lounge6_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader_hns::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted_hns
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns, BattleFrontier_Lounge6_EventScript_DeclineTrade_hns, BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade_hns::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted_hns::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns:
	.string "Mon POKéMON est un {STR_VAR_2}.\n"
	.string "Tu connais?\l"
	.string "Il est mignon et très gentil.\p"
	.string "Ce petit-là, je peux l'échanger\n"
	.string "la tête haute!\p"
	.string "Tu m'échanges un {STR_VAR_1}\n"
	.string "contre mon {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns:
	.string "Oh, il est adorable!\n"
	.string "Merci!\l"
	.string "Je promets d'en prendre soin!\p"
	.string "Oh! J'espère que tu prendras\n"
	.string "soin de mon {STR_VAR_2} aussi!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns:
	.string "Oh, désolée!\n"
	.string "Je ne veux échanger contre rien\l"
	.string "d'autre qu'un {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo_hns:
	.string "Oh, tu ne veux pas?\n"
	.string "Ce n'est pas grave.\l"
	.string "Reviens nous voir, d'accord?$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns:
	.string "Hihi!\n"
	.string "Un SKITTY est bien plus mignon\l"
	.string "que prévu. Je suis ravie!$"
