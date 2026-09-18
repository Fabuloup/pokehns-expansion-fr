Route2_House_hns_MapScripts::
	.byte 0

Route2_House_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROUTE2_NUGGET, Route2_House_EventScript_ManAfter
	msgbox Route2_House_Text_Fisher, MSGBOX_DEFAULT 
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_ROUTE2_NUGGET
	release
	end

Route2_House_EventScript_ManAfter::
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_House_Text_Fisher:
	.string "Salut! Ouah, content de te voir.\p"
	.string "Tu es mon premier visiteur depuis\n"
	.string "bien longtemps.\p"
	.string "Je suis ravi! Laisse-moi\n"
	.string "t'offrir un petit cadeau.$"

Route2_House_Text_Fisher_GotNugget:
	.string "C'est une PÉPITE.\p"
	.string "Je n'ai pas de pépites de sagesse\n"
	.string "à offrir, alors ça fera\l"
	.string "l'affaire!$"
