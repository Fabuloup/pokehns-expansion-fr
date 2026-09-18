CeladonCity_DepartmentStore_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "Je suis Dresseur depuis peu.\p"
	.string "C'est mon fils qui m'a encouragé.\p"
	.string "Le choix d'objets pratiques\n"
	.string "m'impressionne.$"

CeladonDeptStore2F_Text_Youngster:
	.string "Mon père a du mal à retenir le\n"
	.string "nom des objets et la façon de\l"
	.string "les utiliser…$"

CeladonDeptStore2F_Text_Directory:
	.string "Des objets de premier choix pour\n"
	.string "les Dresseurs!\p"
	.string "2F: BOUTIQUE DRESSEUR$"

