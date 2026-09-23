Melemele_House_6_hns_MapScripts::
	.byte 0


Melemele_House6_Hiker::
	lock
	faceplayer
	msgbox Melemele_House6_Hiker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_GameboyKid::
	lock
	faceplayer
	msgbox Melemele_House6_GameboyKid_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_Hiker_Text_0:
	.string "J'ai acheté cette maison pour\n"
	.string "explorer la nature avec mon fils…\p"
	.string "Il ne veut que jouer sur sa\n"
	.string "Game Boy Advance.$"

Melemele_House6_GameboyKid_Text_0:
	.string "J'ai un jeu sur ma Game Boy\n"
	.string "Advance où j'explore la région\l"
	.string "d'ALOLA!\p"
	.string "C'est comme en vrai.\p"
	.string "Ça s'appelle ULTRA ECLIPSE, de\n"
	.string "PHANTONOMY!\p"
	.string "Haha, regarde!\n"
	.string "Je chevauche une BRUYVERNE de\l"
	.string "glace!$"
