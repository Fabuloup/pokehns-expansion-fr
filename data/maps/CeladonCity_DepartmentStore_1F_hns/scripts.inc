CeladonCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "Bonjour! Bienvenue au CENTRE\n"
    .string "COMMERCIAL de CÉLADOPOLE!\p"
    .string "Le plan est affiché au mur.$"

CeladonDeptStore_Text_1FGentleman:
    .string "Ce CENTRE COMMERCIAL appartient à\n"
    .string "la même chaîne que celui de\l"
    .string "DOUBLONVILLE.\p"
    .string "Ils ont été rénovés en même\n"
    .string "temps.$"

CeladonDeptStore_Text_1FTeacher:
    .string "C'est ma première fois ici.\p"
    .string "C'est si grand…\p"
    .string "J'ai peur de me perdre.$"

CeladonDeptStore_Text_1FDirectory:
    .string "1F: ACCUEIL\p"
    .string "2F: BOUTIQUE DRESSEUR\p"
    .string "3F: BOUTIQUE CT\p"
    .string "4F: CADEAUX DU SAGE\p"
    .string "5F: PHARMACIE\p"
    .string "6F: PLACE DU TOIT$"
