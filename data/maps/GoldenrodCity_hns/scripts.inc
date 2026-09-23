GoldenrodCity_hns_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SUNNY_DAY
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadenewbgm MUS_HG_ROCKET_TAKEOVER
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_Music2::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadedefaultbgm
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Trigger_MusicNotYet::
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	setspeaker GoldenrodCity_Text_ElmName
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROCKET_SCOUT
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "Voici l'ARÈNE de DOUBLONVILLE!\p"
	.string "Notre CHAMPIONNE BLANCHE n'est\n"
	.string "pas là pour le moment. Elle doit\l"
	.string "être à la TOUR RADIO.$"

GoldenrodCity_Text_Woman:
	.string "Je m'entraînais à l'ARÈNE de\n"
	.string "BLANCHE, mais ses pleurs me\l"
	.string "donnaient mal à la tête.$"

GoldenrodCity_Text_HikerDay:
	.string "Quand je suis entré au CASINO,\n"
	.string "il faisait nuit… Combien de\l"
	.string "temps j'y suis resté?!$"

GoldenrodCity_Text_HikerNight:
	.string "Quand je suis entré au CASINO,\n"
	.string "il faisait jour… Combien de\l"
	.string "temps j'y suis resté?!$"

GoldenrodCity_Text_Snubbull:
	.string "SNUBBULL: SNUUUBUUUULL!$"

GoldenrodCity_Text_MrMime:
	.string "............................$"

GoldenrodCity_Text_ElmName:
	.string "PROF. ORME$"

GoldenrodCity_Text_ElmCall:
	.string "PROF. ORME: Allô, {PLAYER}?\n"
	.string "Cet ŒUF a-t-il éclos?\p"
	.string "Une fois éclos, n'oublie pas de\n"
	.string "me l'amener au labo! Il faut\l"
	.string "que je le voie!$"

GoldenrodCity_Text_PokefanM:
	.string "On a bâti la nouvelle TOUR RADIO\n"
	.string "pour remplacer la vieille.$"

GoldenrodCity_Text_Youngster1:
	.string "Je sais qu'il y a un nouveau\n"
	.string "MAGASIN DE VÉLOS, mais je ne le\l"
	.string "trouve nulle part.$"

GoldenrodCity_Text_CooltrainerF1:
	.string "Cet homme en noir est déguisé en\n"
	.string "membre de la TEAM ROCKET?\p"
	.string "N'importe quoi!$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "Cet homme en noir était vraiment\n"
	.string "de la TEAM ROCKET? Incroyable!$"

GoldenrodCity_Text_CooltrainerF2:
	.string "La TOUR RADIO de DOUBLONVILLE\n"
	.string "est un sacré monument.\p"
	.string "Ils font une campagne en ce\n"
	.string "moment.\p"
	.string "Ils offrent une RADIO toute\n"
	.string "neuve si tu réussis leur quiz.$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "Oh, ton POKéMATOS fait déjà\n"
	.string "radio!$"

GoldenrodCity_Text_Youngster2:
	.string "Hé-hé-hé-hé…\p"
	.string "Je me suis fait gronder pour\n"
	.string "avoir joué au sous-sol du\l"
	.string "CENTRE COMMERCIAL.$"

GoldenrodCity_Text_Lass:
	.string "L'homme à l'intérieur note les\n"
	.string "surnoms de tes POKéMON.\p"
	.string "Il peut même les renommer.$"

GoldenrodCity_Text_Gramps:
	.string "Ouf! Cette ville est si grande\n"
	.string "que je ne trouve plus rien.$"

GoldenrodCity_Text_RocketScout1:
	.string "Alors c'est ça, la TOUR RADIO…$"

GoldenrodCity_Text_RocketScout2:
	.string "Qu'est-ce que tu veux, morveux?\n"
	.string "Dégage!$"

GoldenrodCity_Text_Rocket1:
	.string "Reste pas dans le passage!\n"
	.string "Du vent, gamin!$"

GoldenrodCity_Text_Rocket2:
	.string "Prendre la TOUR RADIO…\p"
	.string "Quoi? Ça ne te regarde pas!$"

GoldenrodCity_Text_Rocket3:
	.string "Les POKéMON? Juste des outils\n"
	.string "pour faire du fric!$"

GoldenrodCity_Text_Rocket4:
	.string "Notre rêve va bientôt se\n"
	.string "réaliser…\p"
	.string "Ça a été un long et rude\n"
	.string "combat…$"

GoldenrodCity_Text_Rocket5:
	.string "Hé, morveux! Tu n'as rien à\n"
	.string "faire ici! Fiche le camp!$"

GoldenrodCity_Text_Rocket6:
	.string "Viens donc goûter à la terreur\n"
	.string "de la TEAM ROCKET!$"

GoldenrodCity_Text_StationSign:
	.string "STATION de DOUBLONVILLE$"

GoldenrodCity_Text_RadioTowerSign:
	.string "TOUR RADIO de DOUBLONVILLE$"

GoldenrodCity_Text_DeptStoreSign:
	.string "Marchandises de premier choix\n"
	.string "pour POKéMON!\p"
	.string "CENTRE COMMERCIAL de\n"
	.string "DOUBLONVILLE$"

GoldenrodCity_Text_GymSign:
	.string "ARÈNE POKéMON de DOUBLONVILLE\n"
	.string "CHAMPIONNE: BLANCHE\p"
	.string "La fille qui est trop, trop\n"
	.string "bien!$"

GoldenrodCity_Text_CitySign:
	.string "DOUBLONVILLE\p"
	.string "La ville festive qui fleure bon\n"
	.string "la bonne humeur$"

GoldenrodCity_Text_BikeShopSign:
	.string "Dans la vie, pour avancer, faut\n"
	.string "pédaler!\l"
	.string "CYCLES À GOGO$"

GoldenrodCity_Text_GameCornerSign:
	.string "Votre espace de jeux!\p"
	.string "CASINO de DOUBLONVILLE$"

GoldenrodCity_Text_NameRaterSign:
	.string "LE NOTEUR DE NOM\p"
	.string "Faites évaluer les surnoms de\n"
	.string "vos POKéMON$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "ENTRÉE du SOUTERRAIN$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "ENTRÉE du SOUTERRAIN$"


GoldenrodCity_Text_FlowerShopSign:
	.string "Une fleur, la vie! FLEURISTE$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "Je peux apprendre à tes POKéMON\n"
	.string "de super capacités!\p"
	.string "Ça t'intéresse?$"

GoldenrodCity_Text_MoveTutorCost:
	.string "Ça te coûtera 1000 jetons.\n"
	.string "OK?$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "Dommage… Pourtant elles sont\n"
	.string "terribles!$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "Wahahah! Tu ne le regretteras\n"
	.string "pas!\p"
	.string "Quelle capacité veux-tu\n"
	.string "apprendre?$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "Dommage. Il va falloir que je\n"
	.string "prenne de l'argent chez moi…$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "Si tu comprends cette capacité,\n"
	.string "tu es un vrai Dresseur.$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "Wahahah! Adieu, gamin!$"

GoldenrodCity_Text_MoveTutorBut:
	.string "M-mais…$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "…Pas assez de jetons…$"
