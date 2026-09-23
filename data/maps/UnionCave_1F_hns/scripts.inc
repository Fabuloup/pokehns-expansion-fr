UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "Tu vas à ÉCORCIA, n'est-ce pas?\p"
	.string "Voyons si mes POKéMON te jugent\n"
	.string "digne d'un combat.$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "Oh, oh, oh!$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "Parfait! C'est décidé.\p"
	.string "Je ne bougerai pas d'ici tant\n"
	.string "que mes POKéMON ne seront pas\l"
	.string "plus forts!$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "Je parcours la terre à la\n"
	.string "recherche de POKéMON.\p"
	.string "Toi aussi tu cherches des\n"
	.string "POKéMON?\p"
	.string "Alors tu es mon rival de\n"
	.string "collection!$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "Non… Mes pauvres POKéMON…$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "Parfois, on entend des cris de\n"
	.string "POKéMON venant du fond de la\l"
	.string "caverne.$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "Whoa! Tu m'as fait peur!\p"
	.string "Je me croyais seul dans le coin!$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "Whoa! J'me suis fait détruire!$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "On m'a persuadé d'acheter une\n"
	.string "QUEUE RAMOLOSS.\p"
	.string "J'ai des remords… Pauvre POKéMON.$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "L'ULTRASON de NOSFERAPTI rend mes\n"
	.string "POKéMON complètement fous.\p"
	.string "Et ça, c'est super lourd!$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "J'ai fait long feu!$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "Le week-end, on entend d'étranges\n"
	.string "cris venant du fond de la\l"
	.string "caverne.$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "Une caverne éclairée, ça ne fait\n"
	.string "pas peur.\p"
	.string "Et quand on est fort, les POKéMON\n"
	.string "non plus.$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "FLASH!$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "C'est le feu de mon POKéMON qui\n"
	.string "illumine cette caverne.$"
