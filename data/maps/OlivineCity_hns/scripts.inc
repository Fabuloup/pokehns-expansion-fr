OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	map_script_2 VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	setspeaker OlivineCity_Text_BaobaName
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_BaobaName:
	.string "BAOBA$"

OlivineCity_Text_Baoba:
	.string "{PLAYER}!\p"
	.string "Ici le GARDIEN BAOBA.\p"
	.string "Désolé de t'avoir fait attendre.\n"
	.string "Nous avons enfin ouvert le\l"
	.string "PARC SAFARI!\p"
	.string "Sais-tu où il se trouve?\p"
	.string "Tu connais la PORTE dans la grotte\n"
	.string "d'IRISIA?\p"
	.string "Traverse-la, puis marche un peu\n"
	.string "et tu verras bientôt apparaître\l"
	.string "le PARC SAFARI!\p"
	.string "Nous sommes un peu à l'écart, mais\n"
	.string "viens donc nous rendre visite!$"

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0
	
	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "Toi, encore?\n"
	.string "Inutile de te méfier.\p"
	.string "Je ne m'occupe pas des minables\n"
	.string "comme toi.\p"
	.string "En parlant de faibles, la\n"
	.string "CHAMPIONNE n'est pas là,\l"
	.string "car elle s'occuperait\l"
	.string "d'un POKéMON malade au\l"
	.string "PHARE.\p"
	.string "Pff! Quelle pleurnicheuse!\n"
	.string "Qu'elle abandonne ce POKéMON!\p"
	.string "Un POKéMON incapable de combattre\n"
	.string "ne vaut rien!\p"
	.string "Pourquoi ne pas t'entraîner au\n"
	.string "PHARE?\p"
	.string "Qui sait? Tu deviendras peut-être\n"
	.string "un Dresseur un peu moins mauvais!$"

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_ChargeBeam::
	finditem ITEM_TM_CHARGE_BEAM
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "CAFÉ D'OLIVILLE\n"
	.string "LES MARINS LES PLUS ROBUSTES\l"
	.string "Y FONT LE PLEIN D'ÉNERGIE$"

OlivineCity_Text_EonTicketWoman1:
	.string "Je m'appelle LULA!\p"
	.string "Je plaisante, mais j'adore\n"
	.string "son émission de radio!$"

OlivineCity_Text_EonTicketWoman2:
	.string "Tu dois être {PLAYER}!!!\p"
	.string "Incroyable! Le CHAMPION!\p"
	.string "J'ai entendu parler de toi dans\n"
	.string "l'émission de LULA!\p"
	.string "Tiens, prends ceci!$"

OlivineCity_Text_EonTicketWoman3:
	.string "Je n'arrive pas à croire que j'ai\n"
	.string "rencontré le CHAMPION!!!$"

OlivineCity_Text_Sailor1:
	.string "La nuit, les routes sombres\n"
	.string "sont dangereuses.\p"
	.string "Mais dans l'obscurité totale\n"
	.string "de la nuit, la mer est encore\l"
	.string "plus traîtresse!\p"
	.string "Sans la lumière du\n"
	.string "PHARE pour le guider,\l"
	.string "aucun navire ne peut voguer.$"

OlivineCity_Text_YoungsterPokegear:
	.string "Ce truc que tu as…\n"
	.string "C'est un POKéMATOS, non?\l"
	.string "Waouh, trop cool.$"

OlivineCity_Text_YoungsterPokedex:
	.string "Waouh, tu as un POKéDEX!\p"
	.string "C'est vraiment génial.$"

OlivineCity_Text_Sailor2:
	.string "La LIGUE classe JASMINE\n"
	.string "au sixième rang des\l"
	.string "CHAMPIONS les plus forts!\p"
	.string "Ha! N'importe quoi.\p"
	.string "Jamais FRÉDO ne pourrait\n"
	.string "blesser les POKéMON de type ACIER\l"
	.string "de JASMINE!\p"
	.string "De la pure bureaucratie.\p"
	.string "Elle est vraiment redoutable,\n"
	.string "ça ne fait aucun doute!$"

OlivineCity_Text_Sign:
	.string "OLIVILLE\p"
	.string "Le port ouvert sur le monde$"

OlivineCity_Text_PortSign:
	.string "PORT D'OLIVILLE\n"
	.string "EMBARCADÈRE DE L'AQUARIA$"

OlivineCity_Text_GymSign:
	.string "ARÈNE POKéMON D'OLIVILLE\n"
	.string "CHAMPIONNE: JASMINE\p"
	.string "La fille à la défense d'acier$"

OlivineCity_Text_LighthouseSign:
	.string "PHARE D'OLIVILLE\n"
	.string "Aussi appelé le PHARE\l"
	.string "SCINTILLANT$"

OlivineCity_Text_BattleTowerSign:
	.string "COLLINE DRESSEURS et\n"
	.string "TENTES DE COMBAT tout droit.\p"
	.string "Ouverture immédiate!$"

OlivineCity_Text_Machoke:
	.string "MACHOPEUR: CHO!$"
