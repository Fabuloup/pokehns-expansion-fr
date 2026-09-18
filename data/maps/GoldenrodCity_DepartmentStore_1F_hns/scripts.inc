GoldenrodCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "Bienvenue au CENTRE COMMERCIAL\n"
    .string "de DOUBLONVILLE.$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "Le CENTRE COMMERCIAL a un choix\n"
    .string "correct.\p"
    .string "Mais certains objets s'obtiennent\n"
    .string "uniquement en lots au CASINO.$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "J'ai encore envie de faire les\n"
    .string "boutiques aujourd'hui!$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "Maman est douée pour les bonnes\n"
    .string "affaires.\p"
    .string "Elle achète toujours moins cher.$"

GoldenrodDeptStore1_Text_Directory:
    .string "1F ACCUEIL\n"
	.string "VOUS ÊTES ICI.\p"
    .string "2F BOUTIQUE DRESSEUR\p"
    .string "3F COLLECTION DE COMBAT\p"
    .string "4F PHARMACIE\p"
    .string "5F COIN DES CT\p"
    .string "6F COIN TRANQUILLE\p"
    .string "PANORAMA DU TOIT$"
