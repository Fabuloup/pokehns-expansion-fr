VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "Lorsqu'on vient de capturer un\n"
	.string "POKéMON, il peut être faible.\p"
	.string "Mais il finira par devenir\n"
	.string "fort.\p"
	.string "Il est important de traiter ses\n"
	.string "POKéMON avec amour.$"

VioletCity_Mart_Text_CooltrainerM:
	.string "Les POKéMON peuvent porter des\n"
	.string "objets, comme une POTION ou un\n"
	.string "ANTIDOTE.\p"
	.string "Mais ils ne savent pas utiliser\n"
	.string "seuls les objets fabriqués par\n"
	.string "les humains.$"
