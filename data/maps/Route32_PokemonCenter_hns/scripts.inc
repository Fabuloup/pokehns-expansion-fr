Route32_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32_HNS
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "C'est un bon endroit pour\n"
	.string "pêcher.\p"
	.string "Tu as vu des pêcheurs?\n"
	.string "Et toi, ça te tente?\p"
	.string "Tu veux une de mes CANNES?$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "Ha! C'est bien, mon petit.\p"
	.string "Te voilà pêcheur toi aussi!$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "Pêcher, c'est bien!\p"
	.string "Dès qu'il y a de l'eau, la mer\n"
	.string "ou un fleuve, essaie ta CANNE.$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "Ah. C'est bien dommage…$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "Yo, petit. Ça mord?$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "Que devrais-je faire tenir à mon\n"
	.string "POKéMON?\p"
	.string "Peut-être un objet qui augmente\n"
	.string "la puissance d'ATTAQUE…$"

