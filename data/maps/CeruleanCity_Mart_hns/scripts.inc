CeruleanCity_Mart_hns_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "Tu croiseras beaucoup de\n"
	.string "Dresseurs sur la route du CAP\l"
	.string "AZURIA.\p"
	.string "Ils veulent se mesurer aux\n"
	.string "autres Dresseurs.$"

CeruleanMart_Text_CooltrainerF:
	.string "ONDINE est à peu près la seule\n"
	.string "en ville à pouvoir battre les\l"
	.string "Dresseurs du CAP AZURIA.$"
