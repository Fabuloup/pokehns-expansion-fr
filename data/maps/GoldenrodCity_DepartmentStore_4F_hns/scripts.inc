GoldenrodCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "Hé. J'adore les POKéMON forts.\p"
    .string "Je leur donne de la PROTÉINE pour\n"
    .string "gonfler leur ATTAQUE.$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "Le FER augmente la DÉFENSE de\n"
    .string "ton POKéMON.$"

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "Des rumeurs disaient que certains\n"
    .string "POKéMON n'évoluent qu'échangés\l"
    .string "par câble Game Link.\p"
    .string "Pfff…\p"
    .string "Quelle désinformation.\p"
    .string "J'en connais quelques-uns, des\n"
    .string "POKéMON en question:\l"
    .string "MACHOPEUR, KADABRA, SPECTRUM et,\l"
    .string "euh, GRAVALANCH,\l"
    .string "mais ils évoluent tous en\l"
    .string "montant de niveau.$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FDirectory:
    .string "Musclons vos POKéMON!\p"
    .string "4F PHARMACIE$"
