OlivineCity_Mart_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "Tes POKéMON connaissent-ils déjà\n"
	.string "la capacité qui permet de porter\l"
	.string "les gens sur l'eau?$"

OlivineCity_Text_MartLass:
	.string "Mon PAPILUSION vient de mon\n"
	.string "copain, outre-mer.\p"
	.string "Il portait une LETTRE de lui.\p"
	.string "Tu veux savoir ce qu'elle dit?\p"
	.string "Voyons voir… Non! C'est un\n"
	.string "secret!$"
