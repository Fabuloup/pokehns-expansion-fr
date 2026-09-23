SSAqua_RoomNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND_HNS, SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_HNS, SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "Tu es seul?\n"
    .string "Alors battons-nous!$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "C'est trop pour moi!$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "Je me demande s'il y a des\n"
    .string "montagnes à gravir à KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "Tu connais LILY?\n"
    .string "C'est une DJ en vue à KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "Gyaaaah!$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "LILY est sympa, mais\n"
    .string "LULA est la meilleure!\n"
    .string "Je veux écouter les\n"
    .string "émissions de radio\n"
    .string "de JOHTO!$"
