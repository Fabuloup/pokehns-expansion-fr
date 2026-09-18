SSAqua_RoomSSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE_HNS, SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN_HNS, SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "Je vais à KANTO pour faire des\n"
    .string "spectacles de crache-feu!$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "Pschit… La flamme est minuscule…$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "Le feu doit être faible en mer.\n"
    .string "Ça n'a rien à voir? Vraiment?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "Je vais chez ma mamie pour\n"
    .string "attraper des insectes!$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "Ooh, ouah. Tu es coriace!$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "On trouve plein de POKéMON dans\n"
    .string "les arbres de JOHTO!$"
