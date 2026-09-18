BattleFrontier_RankingHall_hns_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_DomeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PikeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ShowRecords_hns::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant_hns::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign_hns::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn_hns::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hns::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy_hns::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall_hns:
	.string "Voici le HALL DES RECORDS.\p"
	.string "C'est ici que nous honorons les\n"
	.string "DRESSEURS immortels qui ont laissé\l"
	.string "de grands records aux épreuves de\l"
	.string "la ZONE DE COMBAT.$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns:
	.string "Records du DÔME, du BROCHET\n"
	.string "et de l'USINE DE COMBAT$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns:
	.string "Records du PALAIS, de l'ARÈNE\n"
	.string "et de la PYRAMIDE DE COMBAT$"

BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns:
	.string "Salut, ton nom est sur la liste?$"

BattleFrontier_RankingHall_Text_WowThatsSuper_hns:
	.string "Ouah, c'est génial!\n"
	.string "Je vais devoir m'accrocher aussi!$"

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns:
	.string "Ah bon?\p"
	.string "Si tu voyais le nom d'un ami\n"
	.string "là-haut, ça te motiverait, non?$"

BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns:
	.string "Hmm…\n"
	.string "Mon nom n'y est pas…\p"
	.string "Normal, je n'ai encore relevé\n"
	.string "aucun défi.$"

