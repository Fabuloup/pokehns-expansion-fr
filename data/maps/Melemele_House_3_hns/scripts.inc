Melemele_House_3_hns_MapScripts::
	.byte 0


Melemele_House3_Woman::
	lock
	faceplayer
	msgbox Melemele_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Man::
	lock
	faceplayer
	msgbox Melemele_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Woman_Text_0:
	.string "La vie sur l'île est si paisible!\p"
	.string "Et mes petits-enfants ne sont\n"
	.string "qu'à un court trajet en bateau,\l"
	.string "à KANTO!$"

Melemele_House3_Man_Text_0:
	.string "Fichus touristes!\p"
	.string "Mon agent immobilier disait que\n"
	.string "ce serait calme… mais venir ici\l"
	.string "coûte moins cher que d'aller\l"
	.string "jusqu'à ALOLA.$"
