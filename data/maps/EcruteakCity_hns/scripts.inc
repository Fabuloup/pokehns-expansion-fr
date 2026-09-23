EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "BADABOUM!!$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL}: Comment...? C'est\n"
	.string "possible? J'ai perdu face à de\l"
	.string "FILLES KIMONO...?$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL}: Tu me regardais,\n"
	.string "{PLAYER}...\p"
	.string "Ouais, c'est ça!\p"
	.string "Je n'aurais jamais cru que battre\n"
	.string "cinq FILLES KIMONO soit si dur...\p"
	.string "Elles m'ont mis en pièces...\p"
	.string "...\p"
	.string "Tu es sûrement venu pour la\n"
	.string "même raison, pas vrai?\p"
	.string "Ne prends pas la grosse tête parce\n"
	.string "que tu as vaincu la TEAM ROCKET!\p"
	.string "Ces FILLES KIMONO sont vraiment\n"
	.string "très fortes.\p"
	.string "Essaie donc de les battre.\p"
	.string "Mais je ne rentre pas. Je ne veux\n"
	.string "pas te voir gagner.$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "ÉVOLI: Vooo!$"

EcruteakCity_Text_Vulpix:
	.string "GOUPIX: Gouuu Pix!$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "Oh non. Oh non…\p"
	.string "Ma fille a disparu.\p"
	.string "Non… Elle n'a pas pu aller à la\n"
	.string "TOUR CENDRÉE.\p"
	.string "Je lui interdisais d'en approcher…\p"
	.string "Des gens semblent y disparaître…\p"
	.string "Oh, que faire…?$"

EcruteakCity_Text_Gramps1:
	.string "ROSALIA avait jadis deux tours:\n"
	.string "l'une à l'est, l'autre à l'ouest.$"

EcruteakCity_Text_Gramps2:
	.string "Alors, mon enfant. As-tu appris à\n"
	.string "danser comme les FILLES KIMONO?\p"
	.string "Il paraît qu'au THÉÂTRE DE DANSE,\n"
	.string "un vieil excentrique te donnera\l"
	.string "quelque chose de bien.$"

EcruteakCity_Text_Lass1:
	.string "Je vais m'entraîner au THÉÂTRE DE\n"
	.string "DANSE. Tu viens avec moi?$"

EcruteakCity_Text_Lass2:
	.string "La tour qui se dressait ici…\p"
	.string "Ma grand-mère disait qu'elle était\n"
	.string "bien plus haute autrefois.\p"
	.string "On dit qu'elle est hantée.$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Trois grands POKéMON sont partis\n"
	.string "chacun ailleurs. Qui étaient-ils?$"

EcruteakCity_Text_Fisher:
	.string "J'ai entendu une rumeur sur le\n"
	.string "PHARE D'OLIVILLE.\p"
	.string "Le POKéMON qui sert de balise est\n"
	.string "tombé malade. Ils semblent avoir\l"
	.string "besoin d'aide.$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "Le POKéMON du PHARE D'OLIVILLE\n"
	.string "est guéri.\p"
	.string "Les bateaux peuvent de nouveau\n"
	.string "prendre la mer de nuit.$"

EcruteakCity_Text_Youngster:
	.string "On dit que les POKéMON s'agitent\n"
	.string "au LAC COLÈRE. J'aimerais voir ça.$"

EcruteakCity_Text_Gramps3:
	.string "Il y a très longtemps…\p"
	.string "Cette tour brûla. Trois POKéMON\n"
	.string "sans nom y périrent.\p"
	.string "Un POKéMON couleur arc-en-ciel\n"
	.string "les ramena alors à la vie…\p"
	.string "Cette légende est transmise par\n"
	.string "CHAMPIONS D'ARÈNE de ROSALIA.\p"
	.string "Moi?\p"
	.string "J'étais Dresseur il y a longtemps.\n"
	.string "Hohoho!$"

EcruteakCity_Text_SageGym:
	.string "Le Champion MORTIMER n'est pas là\n"
	.string "pour le moment. Il est peut-être à\l"
	.string "la TOUR CENDRÉE.$"

EcruteakCity_Text_Sign:
	.string "ROSALIA\n"
	.string "Ville historique\p"
	.string "Quand le passé rejoint le présent$"

EcruteakCity_Text_TinTowerSign:
	.string "TOUR FERRAILLE\p"
	.string "On dit qu'un POKéMON légendaire\n"
	.string "y niche.$"

EcruteakCity_Text_OfficeSign:
	.string "Contrôle de la TOUR FERRAILLE\p"
	.string "Accès interdit aux indignes.$"

EcruteakCity_Text_GymSign:
	.string "ARÈNE POKéMON DE ROSALIA\n"
	.string "CHAMPION: MORTIMER\p"
	.string "Le mystique qui voit l'avenir$"

EcruteakCity_Text_DanceTheaterSign:
	.string "THÉÂTRE DE DANSE DE ROSALIA$"

EcruteakCity_Text_BurnedTowerSign:
	.string "TOUR CENDRÉE\p"
	.string "Détruite par un incendie\n"
	.string "mystérieux.\p"
	.string "Lieu dangereux, restez à l'écart.$"
