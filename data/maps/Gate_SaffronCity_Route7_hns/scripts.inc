Gate_SaffronCity_Route7_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "Tu as entendu parler de\n"
	.string "l'accident à la CENTRALE?\p"
	.string "Elle se trouve à l'est, près de\n"
	.string "LAVANVILLE.$"

Route7_Text_SaffronGuard_Serious:
	.string "Je prends mon rôle de GARDE très\n"
	.string "au sérieux.\p"
	.string "Hé! Tu as un POKéDEX.\p"
	.string "D'accord. Tu peux passer.$"
