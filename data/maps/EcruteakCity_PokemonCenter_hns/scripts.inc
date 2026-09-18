EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "Salut, je suis LÉO. Et toi ?\p"
	.string "Hmm, {PLAYER}, c'est ça ?\n"
	.string "Tu arrives au bon moment.$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "Je viens de finir les réglages de\n"
	.string "mon SYSTÈME DE STOCKAGE POKéMON.\p"
	.string "Tu connais le PC où tu stockes\n"
	.string "tous tes POKéMON ?\p"
	.string "Je l'ai conçu moi-même !\p"
	.string "Maintenant qu'il est installé, mon\n"
	.string "PC fonctionne dans tous les\l"
	.string "CENTRES POKéMON de JOHTO et KANTO.\p"
	.string "Je dois vite rentrer à\n"
	.string "DOUBLONVILLE voir les miens. Passe\l"
	.string "quand tu veux !\p"
	.string "Salut !$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "La danse des FILLES KIMONO est\n"
	.string "merveilleuse.\p"
	.string "Tout comme leur façon d'utiliser\n"
	.string "leurs POKéMON.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "Tu veux sûrement combattre plus de\n"
	.string "gens, non ?\p"
	.string "Il existe un lieu où les Dresseurs\n"
	.string "se rassemblent.\p"
	.string "Où ça ?\p"
	.string "Un peu après OLIVILLE.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "MORTIMER, le CHAMPION, est très\n"
	.string "trop cool.\p"
	.string "Ses POKéMON sont aussi très forts.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "LAC COLÈRE…\p"
	.string "L'apparition d'une horde de\n"
	.string "LÉVIATOR…\p"
	.string "Je sens un complot, c'est sûr !$"
