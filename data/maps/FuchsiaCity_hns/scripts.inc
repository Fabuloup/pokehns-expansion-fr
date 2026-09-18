FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "BAOBA$"

FuchsiaCity_Text_Baoba:
	.string "BAOBA: {PLAYER}!\p"
	.string "C'est le GARDIEN BAOBA.\p"
	.string "Il s'est passé quelque chose\n"
	.string "d'affreux! Mon ancien PARC SAFARI\l"
	.string "de PARMANIE a été rouvert!\p"
	.string "Et il aurait de nouveaux POKéMON\n"
	.string "exotiques!\p"
	.string "Cela nuit à mes affaires!\p"
	.string "{PLAYER}, explore le nouveau PARC\n"
	.string "SAFARI et attrape un POKéMON à me\l"
	.string "montrer. Je dois étudier ces\l"
	.string "ces POKéMON “exotiques”.\p"
	.string "S'il te plaît, {PLAYER}, mon affaire\n"
	.string "dépend de toi!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "Un membre du CONSEIL 4 dirigeait\n"
	.string "autrefois l'ARÈNE de PARMANIE.$"

FuchsiaCity_Text_PokefanM:
	.string "La fille de KOGA lui a succédé à\n"
	.string "l'ARÈNE quand il a rejoint le\l"
	.string "CONSEIL 4.$"

FuchsiaCity_Text_Teacher:
	.string "Le PARC SAFARI a une nouvelle\n"
	.string "direction.\p"
	.string "Et il regorge de nouveaux POKéMON!$"

FuchsiaCity_Text_Sign:
	.string "PARMANIE\p"
	.string "La passion en rose!$"

FuchsiaCity_Text_GymSign:
	.string "ARÈNE POKéMON DE PARMANIE\n"
	.string "CHAMPIONNE: JEANNINE\p"
	.string "La maîtresse ninja du poison$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "Il y a un avis...\p"
	.string "Le BUREAU DU PARC SAFARI est fermé\n"
	.string "jusqu'à nouvel ordre.$"

FuchsiaCity_Text_SafariZone:
	.string "PARC SAFARI\n"
	.string "DÉSORMAIS PROPRIÉTÉ DE\l"
	.string "DEVON SARL$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "Le GARDIEN voyage à l'étranger.\p"
	.string "Le PARC SAFARI est donc fermé.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "Déchets interdits.\p"
	.string "Veuillez emporter vos détritus.$"
