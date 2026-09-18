Route20_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE_HNS, Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten, Route20_EventScript_RegisterNicole
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RematchNicole
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_RegisterNicole::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_NicoleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLE_HNS
	release
	end

Route20_EventScript_RematchNicole::
	trainerbattle_rematch TRAINER_NICOLE_HNS, Route20_Text_NicoleRematchIntro, Route20_Text_NicoleRematchDefeat
	msgbox Route20_Text_NicolePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_NICOLE_2_HNS, Route20_EventScript_RematchNicoleTryGiveItem
	end

Route20_EventScript_RematchNicoleTryGiveItem::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_HEART_SCALE
	closemessage
	end

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI_HNS, Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_HNS, Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "DENNIS: SHAAAAAAAA!$"

Route20_Text_Headlocker:
	.string "Un POKéMON rare vit sur cette\n"
	.string "route.\p"
	.string "Et il porte parfois un objet\n"
	.string "d'évolution rare.\p"
	.string "C'est doublement rare!\p"
	.string "Je dois finir mon POKéDEX, alors\n"
	.string "je pêche ici depuis des heures!$"

Route20_Text_Seel:
	.string "OTARIA: Ota ota!$"

Route20_Text_Dewgong:
	.string "LAMANTINE: Lamaaa!$"

Route20_Text_SeafoamSign:
	.string "ÎLES ÉCUME$"

Route20_Text_NicoleRegister:
	.string "Ton POKéMON nage vite!\n"
	.string "Donne-moi ton numéro!$"

Route20_Text_NicoleRematchIntro:
	.string "À force de nager, mon POKéMON est\n"
	.string "plus fort! Battons-nous!$"

Route20_Text_NicoleRematchDefeat:
	.string "Encore emporté...$"

Route20_Text_NicolePostRematch:
	.string "Victoire ou défaite, mes POKéMON\n"
	.string "et moi gardons la forme!$"

Route20_Text_SwimmerfNicoleSeen:
	.string "Je me sens si léger dans l'eau.$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "Oh non!$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "La natation fait travailler tout\n"
	.string "le corps.\p"
	.string "C'est vraiment bon pour la santé.$"

Route20_Text_SwimmerfLoriSeen:
	.string "Quelle collection impressionnante\n"
	.string "de BADGES! Affrontons-nous!$"

Route20_Text_SwimmerfLoriBeaten:
	.string "Non!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "SURF n'est plus la seule CS\n"
	.string "utilisée sur l'eau.$"

Route20_Text_SwimmermCameronSeen:
	.string "Impossible de nager jusqu'à\n"
	.string "JOHTO, j'imagine.$"

Route20_Text_SwimmermCameronBeaten:
	.string "Aïe!$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "Je nage aussi bien dans la mer\n"
	.string "que dans les étangs et rivières.$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "Que dit ce panneau?\p"
	.string "CHAMPION DE CRAMOIS'ÎLE: AUGUSTE$"
