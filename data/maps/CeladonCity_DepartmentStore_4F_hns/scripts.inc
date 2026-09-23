CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "Je viens acheter une LETTRE SURF\n"
	.string "pour ma copine.\p"
	.string "Quoi, il n'y en a plus?$"

CeladonDeptStore4F_Text_Youngster:
	.string "C'est le seul endroit où acheter\n"
	.string "une LETTRE AMOUR.\p"
	.string "Enfin, c'était. Ils disent qu'il\n"
	.string "n'y en a plus en stock.$"

CeladonDeptStore4F_Text_Directory:
	.string "Exprimez-vous par des cadeaux!\p"
	.string "4F: CADEAUX DU SAGE$"
