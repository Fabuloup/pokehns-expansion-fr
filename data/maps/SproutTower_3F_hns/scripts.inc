SproutTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN_HNS, SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL_HNS, SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY_HNS, SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI_HNS, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "ANCIEN: Tu es sans conteste un\n"
	.string "bon Dresseur.\p"
	.string "Comme promis, voici ta CS.\p"
	.string "Un conseil toutefois: traite tes\n"
	.string "POKéMON avec plus de gentillesse.\p"
	.string "Tu es bien trop âpre au combat.\p"
	.string "Les POKéMON ne sont pas des\n"
	.string "engins de guerre…$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "…\n"
	.string "…Pfeuh!\p"
	.string "On l'appelle l'ANCIEN, mais il\n"
	.string "est super nul.\p"
	.string "Ça n'a rien d'étonnant.\p"
	.string "Je ne me ferai jamais battre par\n"
	.string "des crétins qui racontent qu'il\l"
	.string "faut être gentil avec les\l"
	.string "POKéMON.\p"
	.string "Seuls comptent les POKéMON forts\n"
	.string "capables de gagner.\p"
	.string "Je me contrefiche des POKéMON\n"
	.string "faibles.$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{RIVAL} utilise une CORDE SORTIE!$"

SproutTower_Text_SageLi_Seen:
	.string "Bienvenue à toi, mon poussin!\p"
	.string "La TOUR CHÉTIFLOR est un lieu\n"
	.string "d'entraînement.\p"
	.string "Humains et POKéMON y éprouvent\n"
	.string "leurs liens pour bâtir ensemble\l"
	.string "des lendemains qui chantent.\p"
	.string "Je serai ton épreuve finale.\p"
	.string "Permets-moi de mesurer les liens\n"
	.string "entre tes POKéMON et toi!$"

SproutTower_Text_SageLi_Beaten:
	.string "Ah, excellent!$"

SproutTower_Text_SageLi_TakeFlash:
	.string "Toi et tes POKéMON n'aurez aucun\n"
	.string "mal à utiliser cette capacité.\p"
	.string "Prends donc cette CS FLASH.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "Le FLASH illumine les endroits\n"
	.string "les plus sombres.\p"
	.string "Mais pour l'utiliser en dehors\n"
	.string "des combats, il te faudra le\l"
	.string "BADGE de l'ARÈNE de MAUVILLE.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "Puisses-tu apprendre et grandir\n"
	.string "au fil de ton voyage.$"

SproutTower_Text_SageJin_Seen:
	.string "Je m'entraîne pour trouver la\n"
	.string "voie du POKéMON!$"

SproutTower_Text_SageJin_Beaten:
	.string "Mon entraînement est insuffisant…$"

SproutTower_Text_SageJin_AfterBattle:
	.string "Quand un POKéMON gagne en\n"
	.string "puissance, son Dresseur devient\l"
	.string "plus fort.\p"
	.string "Non, attends. C'est quand le\n"
	.string "Dresseur devient plus fort que\l"
	.string "ses POKéMON gagnent en puissance.$"

SproutTower_Text_SageTroy_Seen:
	.string "Montre-moi à quel point tu fais\n"
	.string "confiance à tes POKéMON.$"

SproutTower_Text_SageTroy_Beaten:
	.string "Oui, ta confiance est totale!$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "L'ANCIEN n'est plus très loin.$"

SproutTower_Text_SageNeal_Seen:
	.string "La CS de l'ANCIEN éclaire même\n"
	.string "les ténèbres les plus noires.$"

SproutTower_Text_SageNeal_Beaten:
	.string "J'en ai vu trente-six chandelles!$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "Que la lumière soit sur ta\n"
	.string "route.$"

SproutTower_Text_3F_Painting:
	.string "Une peinture saisissante d'un\n"
	.string "CHÉTIFLOR.$"
