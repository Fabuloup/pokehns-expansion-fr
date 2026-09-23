BattleFrontier_Lounge5_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns::
	.string "Héhé !\n"
	.string "Je lis l'esprit des POKéMON !\p"
	.string "S'il te plaît !\n"
	.string "Je peux voir tes POKéMON ?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns::
	.string "Boo !\n"
	.string "Radine !$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il aime combattre !\n"
	.string "Il combattra même s'il a très\l"
	.string "mal !$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il aime combattre !\n"
	.string "Mais s'il a trop mal, il\l"
	.string "s'inquiétera pour lui !$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il aime combattre !\n"
	.string "Mais s'il a trop mal, il\l"
	.string "deviendra fourbe !$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il se préserve !\n"
	.string "Mais s'il a trop mal, il\l"
	.string "ripostera !$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il se préserve !\n"
	.string "Il s'inquiète pour lui, qu'il ait\l"
	.string "mal ou non !$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il se préserve !\n"
	.string "Mais s'il a trop mal, il\l"
	.string "deviendra fourbe !$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il aime être fourbe !\n"
	.string "Mais s'il a trop mal, il\l"
	.string "ripostera !$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il aime être fourbe !\n"
	.string "Mais s'il a trop mal, il\l"
	.string "s'inquiétera pour lui !$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow_hns::
	.string "Hmhm…\p"
	.string "Il dit qu'il aime être fourbe !\n"
	.string "Il aime être fourbe même s'il a\l"
	.string "très mal !$"

BattleFrontier_Lounge5_Text_NatureGirlEgg_hns::
	.string "C'est idiot ! Un ŒUF dort !\n"
	.string "Je ne peux pas lui parler !$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns::
	.string "Comme c'est charmant !\n"
	.string "Cette petite dame prétend\l"
	.string "comprendre les POKéMON !$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns::
	.string "Cette petite fille dit quelque\n"
	.string "chose de profond.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns::
	.string "Je sais quelque chose !\p"
	.string "Elle va souvent à la maison\n"
	.string "rouge !$"
