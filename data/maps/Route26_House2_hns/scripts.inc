Route26_House2_hns_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "Quelque chose est écrit ici.\p"
    .string "Lire?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "À mes frères et sœurs:\p"
    .string "Nous sommes fiers de servir les\n"
    .string "DRESSEURS POKéMON.\p"
    .string "Quand un DRESSEUR vous parle,\n"
    .string "donnez-lui quelque chose\l"
    .string "d'utile.\p"
    .string "Affectueusement,\n"
    .string "LUCIE\p"
    .string "Continuer la lecture?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "Lundi, LUCIE\n"
    .string "ROUTE 40\p"
    .string "Mardi, MARIE\n"
    .string "ROUTE 29\p"
    .string "Mercredi, HOMER\n"
    .string "LAC COLÈRE\p"
    .string "Jeudi, JÉROME\n"
    .string "ROUTE 36\p"
    .string "Vendredi, VANESSA\n"
    .string "ROUTE 32\p"
    .string "Samedi, SAMUEL\n"
    .string "EBENELLE\p"
    .string "Dimanche, DIMITRI\n"
    .string "ROUTE 37$"
