BlackthornCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	setspeaker BlackthornCity_Text_ElmName
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_ElmName:
	.string "PROF. ORME$"

BlackthornCity_Text_BaobaCall:
	.string "BAOBA: {PLAYER}!\p"
	.string "C'est BAOBA.\p"
	.string "Je t'appelle pour t'annoncer que\n"
	.string "le PARC SAFARI s'est agrandi!\p"
	.string "Viens nous rendre visite!$"

BlackthornCity_Text_ElmCall:
	.string "PROF. ORME: Allô, {PLAYER}?\p"
	.string "J'ai quelque chose pour toi.\n"
	.string "Tu peux passer au LABO?\p"
	.string "À bientôt!$"

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
	.string "SANDRA, notre CHAMPIONNE, suit\n"
	.string "tes progrès avec attention.\p"
	.string "Mais elle n'affronte que ceux\n"
	.string "ayant déjà sept BADGES.$"

BlackthornCity_Text_ClairIsIn:
	.string "Sandra, notre\n"
	.string "Champion, vous\p"
	.string "attend. Vous aurez\n"
	.string "du mal à la battre.$"

BlackthornCity_Text_ClairIsBeaten:
	.string "Vous avez battu\p"
	.string "Sandra? Incroyable!\p"
	.string "Seul Peter avait\n"
	.string "réussi cet exploit!$"

BlackthornGrampsRefusesEntryText:
	.string "Seuls les Dresseurs\n"
	.string "confirmés peuvent\p"
	.string "s'entraîner ici. Partez.$"

BlackthornGrampsGrantsEntryText:
	.string "Si SANDRA donne son accord,\n"
	.string "son grand-père l'approuvera.\p"
	.string "Tu peux entrer.$"

BlackBeltText_VoicesInMyHead:
	.string "Aahhhh! Des voix dans ma\p"
	.string "tête! Hum? J'écoute ma radio!$"

BlackthornCooltrainerF1Text:
	.string "Tu vas aider ton POKéMON à\n"
	.string "se souvenir de capacités?$"

BlackthornYoungsterText:
	.string "Tous les experts en dragons\n"
	.string "vien- nent d'EBENELLE.$"

BlackthornCity_MeetSantosText:
	.string "SANTOS: …\p"
	.string "Je suis SANTOS, de la fratrie.\p"
	.string "À toi de deviner.$"

BlackthornCity_SantosGivesGiftText:
	.string "Tiens...$"

BlackthornCity_SantosGaveGiftText:
	.string "SAMUEL: ... RUNE SORT...\p"
	.string "Les attaques de type SPECTRE\p"
	.string "sont plus fortes. Ca va\p"
	.string "t'effrayer, tu verras...$"

BlackthornCity_SantosSaturdayText:
	.string "SAMUEL: ... A la prochaine,\p"
	.string "un autre samedi... Je\p"
	.string "n'aurai plus de cadeaux...$"

BlackthornCity_SantosNopeText:
	.string "SANTOS: Non.$"

BlackthornCooltrainerF2Text:
	.string "Tu as franchi la ROUTE DE GLACE?\p"
	.string "Tu dois être un sacré DRESSEUR!$"

BlackthornCitySignText:
	.string "Ebènelle Un coin\p"
	.string "de montagne reculé$"

BlackthornGymSignText:
	.string "Arène d'Ebènelle\n"
	.string "Champion: Sandra La\p"
	.string "Dompteuse de Dragons$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "MAISON DES FRÈRES CAPACITÉS$"

BlackthornCity_Text_DragonDenSign:
	.string "Antre du Dragon Tout droit$"

