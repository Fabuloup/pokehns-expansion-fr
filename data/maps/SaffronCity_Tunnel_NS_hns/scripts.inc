SaffronCity_Tunnel_NS_hns_MapScripts::
	.byte 0

SaffronCity_Tunnel_NS_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION, SaffronCity_Tunnel_NS_EventScript_BaldingManAfter
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Tunnel_NS_EventScript_BaldingManDetected
	closemessage
	release
	end

SaffronCity_Tunnel_NS_EventScript_BaldingManDetected::
	playse SE_PIN
	applymovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected, MSGBOX_DEFAULT
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION
SaffronCity_Tunnel_NS_EventScript_BaldingManAfter::
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveTm, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Tunnel_NS_Text_BaldingManIntro:
	.string "N'aie pas peur, je ne suis pas\n"
	.string "quelqu'un de mauvais.\p"
	.string "Un endroit comme celui-ci…\n"
	.string "attire les gens malveillants.\p"
	.string "Ils finiraient par causer\n"
	.string "des problèmes…\p"
	.string "Rien que d'y penser,\n"
	.string "ça me met en colère!$"

SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected:
	.string "Ah!\n"
	.string "C'est un BONBON RAGE!\p"
	.string "Tu peux me le donner?\n"
	.string "S'il te plaît!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar:
	.string "{PLAYER} donne le BONBON RAGE\n"
	.string "à l'homme du SOUTERRAIN.\p"
	.string "Miam!\p"
	.string "Quel supplice!\p"
	.string "Mais qu'est-ce que c'est bon!\p"
	.string "Miam miam!\p"
	.string "Raaah! Ça me met en colère!\p"
	.string "Miam miam!\p"
	.string "Raaah…\p"
	.string "................... Pfiou!\p"
	.string "Je me sens bien mieux!\n"
	.string "Merci pour ton bonbon!\l"
	.string "Tiens, prends ceci!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveTm:
	.string "La CT64 contient……\p"
	.string "tic-\n"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic……\l"
	.string "......................\l"
	.string "......................\l"
	.string "BA-BOUM!!!$"
