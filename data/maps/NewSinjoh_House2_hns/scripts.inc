NewSinjoh_House2_hns_MapScripts::
	.byte 0


NewSinjoh_House2_EventScripts_DeskLady::
    lock
	msgbox NewSinjoh_House2_DeskLady_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_DeskLady_Text::
    .string "Bonjour, petit..\p"
	.string "Bienvenue dans le… enfin, on\n"
	.string "pourrait appeler ça la\l"
	.string "bibliothèque de Nouvelle Sinjoh.\p"
	.string "En vérité, c'est ici que nous\n"
	.string "conservons toutes les archives de\l"
	.string "l'histoire de notre ville, ainsi\l"
	.string "que la littérature importée\l"
	.string "d'autres régions..$"

NewSinjoh_House2_EventScript_Torkoal::
	lock
	faceplayer
	playmoncry SPECIES_TORKOAL, 0
	msgbox NewSinjoh_Hosue2_Text_CryTorkoal, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Hosue2_Text_CryTorkoal:
	.string "Tooor?$"

NewSinjoh_House2_EventScript_BookShelf_North::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_North MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_North:
    .string "Elle déborde de vieux ouvrages\n"
	.string "reliés en cuir.\p"
	.string "La langue est méconnaissable.$"

NewSinjoh_House2_EventScript_BookShelf_South::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_South MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_South:
    .string "Elle déborde de livres sur les\n"
	.string "POKéMON.\p"
	.string "Ils ont l'air plus récents et\n"
	.string "plus familiers.$"
