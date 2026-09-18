BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "EUSINE: Moi, c'est EUSINE.\p"
	.string "Je suis sur la piste d'un\n"
	.string "POKéMON nommé SUICUNE.\p"
	.string "Et toi, tu es…?\p"
	.string "{PLAYER}? Enchanté!\p"
	.string "On m'a dit que SUICUNE serait\n"
	.string "dans cette TOUR CENDRÉE, alors\l"
	.string "je suis venu voir.\p"
	.string "Mais où peut-il bien être?$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "EUSINE: On m'a dit que SUICUNE\n"
	.string "serait dans cette TOUR CENDRÉE,\l"
	.string "alors je suis venu voir.\p"
	.string "Mais où peut-il bien être?$"

BurnedTower_1FMortyText:
	.string "MORTIMER: Le CHAMPION de\n"
	.string "l'ARÈNE de ROSALIA se doit\l"
	.string "d'étudier ceux qu'on dit\l"
	.string "légendaires: SUICUNE, ENTEI\l"
	.string "et RAIKOU.\p"
	.string "EUSINE est ici, alors j'ai\n"
	.string "décidé de fouiller la TOUR\l"
	.string "avec lui.$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "..............................\p"
	.string "…Ah, c'est toi.\p"
	.string "Je cherchais les POKéMON\n"
	.string "légendaires qui nicheraient\l"
	.string "ici.\p"
	.string "Mais il n'y a rien du tout!\p"
	.string "Rien, après tout ce mal pour\n"
	.string "venir dans ce trou à rats?\l"
	.string "Pas question!\p"
	.string "Tout ça, c'est ta faute!$"

BurnedTowerSilver_WinText:
	.string "…Hmpf!\p"
	.string "J'ai perdu uniquement parce\n"
	.string "que mes POKéMON sont d'une\l"
	.string "faiblesse affligeante.\p"
	.string "Pathétique.$"

BurnedTowerSilver_AfterText1:
	.string "…Bah, peu importe.\p"
	.string "De toute façon, tu n'arriverais\n"
	.string "jamais à capturer un POKéMON\l"
	.string "légendaire.$"

BurnedTowerSilver_LossText:
	.string "…Hmpf!\p"
	.string "C'est pour ça que je déteste\n"
	.string "affronter des mauviettes.\l"
	.string "Quelle perte de temps.$"

BurnedTowerSilver_AfterText2:
	.string "Hmpf!\p"
	.string "Tu tombes dans un trou?\n"
	.string "Quel génie!\p"
	.string "Bien fait pour toi!$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "Pas d'inquiétude!\p"
	.string "Nous, les cracheurs de feu, on\n"
	.string "connaît la vraie puissance du\l"
	.string "feu mieux que quiconque!$"
BurnedTower_Text_NardBeaten:
	.string "Merci pour ce combat brûlant!$"
BurnedTower_Text_NardAfter:
	.string "Si cette tour a brûlé, c'est\n"
	.string "que la foudre l'a frappée.\p"
	.string "Le feu que je crache est\n"
	.string "minuscule à côté…$"

BurnedTower_Text_RichardoSeen:
	.string "Je m'entraîne au vol dans la\n"
	.string "TOUR CENDRÉE! N'essaie pas ça\l"
	.string "chez toi!$"
BurnedTower_Text_RichardoBeaten:
	.string "Pfffffffffffffff.$"
BurnedTower_Text_RichardoAfter:
	.string "La vie de bandit n'est\n"
	.string "peut-être pas faite pour moi…$"
