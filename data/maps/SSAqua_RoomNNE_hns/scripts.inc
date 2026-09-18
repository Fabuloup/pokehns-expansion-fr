SSAqua_RoomNNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN_HNS, SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL_HNS, SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "Je vais à KANTO\n"
    .string "tester mes talents.$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "Je voulais gagner!$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "Les Dresseurs de JOHTO\n"
    .string "peuvent affronter les\l"
    .string "CHAMPIONS de KANTO.$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "Je m'entraîne pour\n"
    .string "devenir MAÎTRE!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "Qu'est-ce qui nous\n"
    .string "sépare donc?$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "Je te battrai un\n"
    .string "de ces jours!$"
