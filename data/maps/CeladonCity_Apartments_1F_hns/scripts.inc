CeladonCity_Apartments_1F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "Mes chers POKéMON me tiennent\n"
	.string "compagnie, je ne me sens jamais\l"
	.string "seule.\p"
	.string "MIAOUSS rapporte même de l'argent.$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "APPARTEMENT DU GÉRANT\n"
	.string "MANOIR DE CÉLADOPOLE$"
