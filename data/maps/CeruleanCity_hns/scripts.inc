CeruleanCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "Voici la CAVERNE AZUR.\p"
    .string "Des POKéMON très puissants vivent\n"
    .string "à l'intérieur.\p"
    .string "Seul un DRESSEUR exceptionnel peut\n"
    .string "être autorisé à y entrer.\p"
    .string "Il faut déjà être assez fort pour\n"
    .string "devenir MAÎTRE DE LA LIGUE\l"
    .string "POKéMON DE KANTO.\p"
    .string "Et il faut aussi avoir accompli\n"
    .string "un grand exploit.$"

CeruleanCity_Text_CooltrainerM1:
	.string "Si tu cherches la\p"
	.string "Centrale de Kanto, suis\n"
	.string "la Route 9 jusqu'au\p"
	.string "bout, à l'est. Il paraît\n"
	.string "qu'ils ont un problème...$"

CeruleanCity_Text_CooltrainerM2:
	.string "Tu collectionnes tous les\n"
	.string "POKéMON différents? Ca doit\p"
	.string "pas être super facile... Mais\n"
	.string "ça doit être rigolo, non?$"

CeruleanCity_Text_SuperNerd:
	.string "Le CAP au Nord est un bon\n"
	.string "endroit pour un rencard!\p"
	.string "Les filles adorent ça!$"

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "FLAGADOSS: Gaaa?$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_CITY_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_CITY_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "Mon FLAGADOSS et moi on\n"
	.string "va trop bien ensemble!$"

CeruleanCity_Text_CooltrainerF2:
	.string "FLAGADOSS! Lance CHOC MENTAL!$"

CeruleanCity_Text_CooltrainerF3:
	.string "....$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "Je suis un grand admirateur\n"
	.string "d'ONDINE, de l'ARÈNE D'AZURIA.$"

CeruleanCity_Text_Fisher_RocketTip:
	.string "J'ai vu ce drôle de type\n"
	.string "aller vers le CAP d'AZURIA.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "La grotte au nord de la ville\n"
	.string "abrite des POKéMON très puissants.$"

CeruleanCity_Text_Youngster2:
	.string "Quoi? Mon CHERCH'OBJET\p"
	.string "vient de sonner...$"

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "AZURIA Entourée d'une\p"
	.string "étrange aura bleue$"

CeruleanCity_Text_GymSign:
	.string "Arène d'Azuria\n"
	.string "Champion:\n"
	.string "Ondine Notre\p"
	.string "sirène favorite!$"

CeruleanCity_Text_BikeShopSign:
	.string "Il y a une affiche...\p"
	.string "Les CYCLES A GOGO sont à\n"
	.string "DOUBLON- VILLE à JOHTO...$"

CeruleanCity_Text_PoliceSign:
	.string "Il y a une affiche...\p"
	.string "Attention aux voleurs!\n"
	.string "Construisons notre\l"
	.string "bonheur ensemble!\p"
	.string "Police d'Azuria$"

CeruleanCity_Text_CapeSign:
	.string "CAP d'AZURIA\n"
	.string "Tout droit$"

CeruleanCity_Text_LockedDoor:
	.string "C'est fermé...$"

