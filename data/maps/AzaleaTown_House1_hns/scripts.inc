AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "Tous les RAMOLOSS ont disparu de\n"
	.string "la ville.\p"
	.string "Le protecteur de la forêt est\n"
	.string "peut-être en colère contre nous…\p"
	.string "C'est mauvais signe. Mieux vaut\n"
	.string "rester à l'abri.$"

CharcoalKiln_Text_Boss2:
	.string "Les RAMOLOSS sont de retour…$"

CharcoalKiln_Text_Boss3:
	.string "Les RAMOLOSS sont de retour…\p"
	.string "Mais mon APPRENTI n'est pas\n"
	.string "revenu du BOIS AUX CHÊNES.\p"
	.string "Où est encore passé ce fainéant?$"

CharcoalKiln_Text_Boss4:
	.string "Tu as chassé la TEAM ROCKET et\n"
	.string "tu es entré en solo dans le BOIS\l"
	.string "AUX CHÊNES?\p"
	.string "Ça, c'est du cran! J'aime ça.\n"
	.string "Viens t'entraîner avec nous.$"

CharcoalKiln_Text_Apprentice1:
	.string "Où sont donc passés tous les\n"
	.string "RAMOLOSS?\p"
	.string "Ils jouent quelque part?$"

CharcoalKiln_Text_Apprentice2:
	.string "Les RAMOLOSS sont revenus!$"

CharcoalKiln_Text_Apprentice3:
	.string "Désolé, j'ai oublié de te\n"
	.string "remercier.\p"
	.string "Voici du CHARBON que j'ai\n"
	.string "fabriqué.\p"
	.string "Un POKéMON de type FEU sera\n"
	.string "ravi de le tenir.$"

CharcoalKiln_Text_Apprentice4:
	.string "Les RAMOLOSS sont revenus, et en\n"
	.string "plus tu as retrouvé CANARTICHO.\p"
	.string "T'es le plus cool, mec!$"

CharcoalKiln_Text_Farfetchd:
	.string "CANARTICHO: Kwaa!$"
