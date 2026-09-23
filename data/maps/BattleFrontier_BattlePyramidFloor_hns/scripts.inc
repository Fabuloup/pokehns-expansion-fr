BattleFrontier_BattlePyramidFloor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition_hns
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame_hns:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume_hns:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY_HNS, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition_hns:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor_hns::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop_hns
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR_HNS, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP_HNS, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle_hns::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall_hns::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBall_hnsEnd_hns
	pyramid_hideitem
BattlePyramid_FindItemBall_hnsEnd_hns::
	end

BattlePyramid_Retire_hns::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText_hns:
	.string "C'est le message d'essai.$"

gText_BattlePyramidConfirmRest_hns::
	.string "Votre quête à la PYRAMIDE DE\n"
	.string "COMBAT sera sauvegardée pour que\l"
	.string "vous puissiez faire une pause. OK?$"

gText_BattlePyramidConfirmRetire_hns::
	.string "Voulez-vous vraiment abandonner\n"
	.string "votre quête à la PYRAMIDE?$"

BattlePyramid_Text_ExitHintUp1_hns::
	.string "Pour sortir de ce niveau, il faut\n"
	.string "aller dans cette direction: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft1_hns::
	.string "Pour sortir de ce niveau, il faut\n"
	.string "aller dans cette direction: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight1_hns::
	.string "Pour sortir de ce niveau, il faut\n"
	.string "aller dans cette direction: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown1_hns::
	.string "Pour sortir de ce niveau, il faut\n"
	.string "aller dans cette direction: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp2_hns::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2_hns::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2_hns::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2_hns::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3_hns::
	.string "Va dans la direction {UP_ARROW} pour\n"
	.string "sortir.$"

BattlePyramid_Text_ExitHintLeft3_hns::
	.string "Va dans la direction {LEFT_ARROW} pour\n"
	.string "sortir.$"

BattlePyramid_Text_ExitHintRight3_hns::
	.string "Va dans la direction {RIGHT_ARROW} pour\n"
	.string "sortir.$"

BattlePyramid_Text_ExitHintDown3_hns::
	.string "Va dans la direction {DOWN_ARROW} pour\n"
	.string "sortir.$"

BattlePyramid_Text_ExitHintUp4_hns::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4_hns::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4_hns::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4_hns::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5_hns::
	.string "La sortie? C'est par là, mon\n"
	.string "petit: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5_hns::
	.string "La sortie? C'est par là, mon\n"
	.string "petit: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5_hns::
	.string "La sortie? C'est par là, mon\n"
	.string "petit: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5_hns::
	.string "La sortie? C'est par là, mon\n"
	.string "petit: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6_hns::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6_hns::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6_hns::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6_hns::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste huit objets à trouver.$"

BattlePyramid_Text_SevenItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste sept objets à trouver.$"

BattlePyramid_Text_SixItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste six objets à trouver.$"

BattlePyramid_Text_FiveItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste cinq objets à trouver.$"

BattlePyramid_Text_FourItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste quatre objets à trouver.$"

BattlePyramid_Text_ThreeItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste trois objets à trouver.$"

BattlePyramid_Text_TwoItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste deux objets à trouver.$"

BattlePyramid_Text_OneItemRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il reste un objet à trouver.$"

BattlePyramid_Text_ZeroItemsRemaining1_hns::
	.string "Tu cherches des objets?\p"
	.string "Il n'y a plus d'objets à trouver!$"

BattlePyramid_Text_EightItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a huit objets à trouver.$"

BattlePyramid_Text_SevenItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a sept objets à trouver.$"

BattlePyramid_Text_SixItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a six objets à trouver.$"

BattlePyramid_Text_FiveItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a cinq objets à trouver.$"

BattlePyramid_Text_FourItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a quatre objets à trouver.$"

BattlePyramid_Text_ThreeItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a trois objets à trouver.$"

BattlePyramid_Text_TwoItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a deux objets à trouver.$"

BattlePyramid_Text_OneItemRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il y a un objet à trouver.$"

BattlePyramid_Text_ZeroItemsRemaining2_hns::
	.string "Tu as gagné, alors je vais te\n"
	.string "confier un petit secret!\p"
	.string "Il n'y a plus d'objets à trouver.$"

BattlePyramid_Text_EightItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste huit objets\n"
	.string "à ramasser par terre.$"

BattlePyramid_Text_SevenItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste sept objets\n"
	.string "à ramasser par terre.$"

BattlePyramid_Text_SixItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste six objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_FiveItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste cinq objets\n"
	.string "à ramasser par terre.$"

BattlePyramid_Text_FourItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste quatre\n"
	.string "objets à ramasser par terre.$"

BattlePyramid_Text_ThreeItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste trois objets\n"
	.string "à ramasser par terre.$"

BattlePyramid_Text_TwoItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste deux objets\n"
	.string "à ramasser par terre.$"

BattlePyramid_Text_OneItemRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il reste un objet à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_ZeroItemsRemaining3_hns::
	.string "Comment se porte ton stock\n"
	.string "d'objets?\p"
	.string "Je dirais qu'il ne reste plus\n"
	.string "d'objets à ramasser par terre.$"

BattlePyramid_Text_EightItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste huit objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_SevenItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste sept objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_SixItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste six objets à\n"
	.string "ramasser.$"

BattlePyramid_Text_FiveItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste cinq objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_FourItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste quatre\n"
	.string "objets à ramasser.$"

BattlePyramid_Text_ThreeItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste trois objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_TwoItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste deux objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_OneItemRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il reste un objet à\n"
	.string "ramasser.$"

BattlePyramid_Text_ZeroItemsRemaining4_hns::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu'il ne reste aucun\n"
	.string "objet à ramasser.$"

BattlePyramid_Text_EightItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "huit objets à trouver…$"

BattlePyramid_Text_SevenItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "sept objets à trouver…$"

BattlePyramid_Text_SixItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "six objets à trouver…$"

BattlePyramid_Text_FiveItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "cinq objets à trouver…$"

BattlePyramid_Text_FourItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "quatre objets à trouver…$"

BattlePyramid_Text_ThreeItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "trois objets à trouver…$"

BattlePyramid_Text_TwoItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "deux objets à trouver…$"

BattlePyramid_Text_OneItemRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il y a\n"
	.string "un objet à trouver…$"

BattlePyramid_Text_ZeroItemsRemaining5_hns::
	.string "A ce niveau de la PYRAMIDE, il n'y\n"
	.string "a pas d'objets à trouver…$"

BattlePyramid_Text_EightItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste huit à ce\n"
	.string "niveau.$"

BattlePyramid_Text_SevenItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste sept à ce\n"
	.string "niveau.$"

BattlePyramid_Text_SixItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste six à ce\n"
	.string "niveau.$"

BattlePyramid_Text_FiveItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste cinq à ce\n"
	.string "niveau.$"

BattlePyramid_Text_FourItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste quatre à\n"
	.string "ce niveau.$"

BattlePyramid_Text_ThreeItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste trois à ce\n"
	.string "niveau.$"

BattlePyramid_Text_TwoItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste deux à ce\n"
	.string "niveau.$"

BattlePyramid_Text_OneItemRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il en reste un à ce\n"
	.string "niveau.$"

BattlePyramid_Text_ZeroItemsRemaining6_hns::
	.string "Est-ce que tu as trouvé des\n"
	.string "objets?\p"
	.string "Je pense qu'il n'en reste plus à\n"
	.string "ce niveau.$"

BattlePyramid_Text_SevenTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore sept DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_SixTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore six DRESSEURS à\n"
	.string "battre!$"

BattlePyramid_Text_FiveTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore cinq DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_FourTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore quatre\n"
	.string "DRESSEURS à battre!$"

BattlePyramid_Text_ThreeTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore trois DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_TwoTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore deux DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_OneTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore un DRESSEUR à\n"
	.string "battre!$"

BattlePyramid_Text_ZeroTrainersRemaining1_hns::
	.string "Tu as été formidable!\p"
	.string "Il n'y a plus de DRESSEUR à\n"
	.string "battre!$"

BattlePyramid_Text_SevenTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Mais il y a sept autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_SixTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Mais il y a six autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_FiveTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Mais il y a cinq autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_FourTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Mais il y a quatre autres\n"
	.string "DRESSEURS! Tu ne résisteras pas!$"

BattlePyramid_Text_ThreeTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Mais il y a trois autres\n"
	.string "DRESSEURS! Tu ne résisteras pas!$"

BattlePyramid_Text_TwoTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Mais il y a deux autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_OneTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Mais il y a un autre DRESSEUR! Tu\n"
	.string "ne résisteras pas!$"

BattlePyramid_Text_ZeroTrainersRemaining2_hns::
	.string "C'est rageant!\p"
	.string "Il ne reste plus de DRESSEUR!$"

BattlePyramid_Text_SevenTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il reste sept DRESSEURS à ce\n"
	.string "niveau. Arriveras-tu à tous les\l"
	.string "battre?$"

BattlePyramid_Text_SixTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il reste six DRESSEURS à ce\n"
	.string "niveau. Arriveras-tu à tous les\l"
	.string "battre?$"

BattlePyramid_Text_FiveTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il reste cinq DRESSEURS à ce\n"
	.string "niveau. Arriveras-tu à tous les\l"
	.string "battre?$"

BattlePyramid_Text_FourTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il reste quatre DRESSEURS à ce\n"
	.string "niveau. Arriveras-tu à tous les\l"
	.string "battre?$"

BattlePyramid_Text_ThreeTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il reste trois DRESSEURS à ce\n"
	.string "niveau. Arriveras-tu à tous les\l"
	.string "battre?$"

BattlePyramid_Text_TwoTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il reste deux DRESSEURS à ce\n"
	.string "niveau. Arriveras-tu à tous les\l"
	.string "battre?$"

BattlePyramid_Text_OneTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il reste un DRESSEUR à ce niveau.\n"
	.string "Arriveras-tu à le battre?$"

BattlePyramid_Text_ZeroTrainersRemaining3_hns::
	.string "C'est impressionnant!\p"
	.string "Il ne reste plus de DRESSEURS à ce\n"
	.string "niveau.$"

BattlePyramid_Text_SevenTrainersRemaining4_hns::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux sept autres DRESSEURS du\l"
	.string "niveau.$"

BattlePyramid_Text_SixTrainersRemaining4_hns::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux six autres DRESSEURS du\l"
	.string "niveau.$"

BattlePyramid_Text_FiveTrainersRemaining4_hns::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux cinq autres DRESSEURS du\l"
	.string "niveau.$"

BattlePyramid_Text_FourTrainersRemaining4_hns::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux quatre autres DRESSEURS du\l"
	.string "niveau.$"

BattlePyramid_Text_ThreeTrainersRemaining4_hns::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux trois autres DRESSEURS du\l"
	.string "niveau.$"

BattlePyramid_Text_TwoTrainersRemaining4_hns::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux deux autres DRESSEURS du\l"
	.string "niveau.$"

BattlePyramid_Text_OneTrainersRemaining4_hns::
	.string "Peut-être réussiras-tu à résister\n"
	.string "au dernier DRESSEUR du niveau.$"

BattlePyramid_Text_ZeroTrainersRemaining4_hns::
	.string "Tu as résisté à tous les DRESSEURS\n"
	.string "du niveau. Il n'en reste aucun.$"

BattlePyramid_Text_SevenTrainersRemaining5_hns::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "sept autres DRESSEURS.$"

BattlePyramid_Text_SixTrainersRemaining5_hns::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "six autres DRESSEURS.$"

BattlePyramid_Text_FiveTrainersRemaining5_hns::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "cinq autres DRESSEURS.$"

BattlePyramid_Text_FourTrainersRemaining5_hns::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "quatre autres DRESSEURS.$"

BattlePyramid_Text_ThreeTrainersRemaining5_hns::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "trois autres DRESSEURS.$"

BattlePyramid_Text_TwoTrainersRemaining5_hns::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "deux autres DRESSEURS.$"

BattlePyramid_Text_OneTrainersRemaining5_hns::
	.string "Si ça se trouve, tu vas battre le\n"
	.string "dernier DRESSEUR.$"

BattlePyramid_Text_ZeroTrainersRemaining5_hns::
	.string "Tu te bats à la perfection.\p"
	.string "Il ne reste aucun DRESSEUR à\n"
	.string "battre.$"

BattlePyramid_Text_SevenTrainersRemaining6_hns::
	.string "Je me demande si tu vas battre les\n"
	.string "sept autres DRESSEURS!$"

BattlePyramid_Text_SixTrainersRemaining6_hns::
	.string "Je me demande si tu vas battre les\n"
	.string "six autres DRESSEURS!$"

BattlePyramid_Text_FiveTrainersRemaining6_hns::
	.string "Je me demande si tu vas battre les\n"
	.string "cinq autres DRESSEURS!$"

BattlePyramid_Text_FourTrainersRemaining6_hns::
	.string "Je me demande si tu vas battre les\n"
	.string "quatre autres DRESSEURS!$"

BattlePyramid_Text_ThreeTrainersRemaining6_hns::
	.string "Je me demande si tu vas battre les\n"
	.string "trois autres DRESSEURS!$"

BattlePyramid_Text_TwoTrainersRemaining6_hns::
	.string "Je me demande si tu vas battre les\n"
	.string "deux autres DRESSEURS!$"

BattlePyramid_Text_OneTrainersRemaining6_hns::
	.string "Je me demande si tu vas battre le\n"
	.string "dernier DRESSEUR!$"

BattlePyramid_Text_ZeroTrainersRemaining6_hns::
	.string "Il n'y a plus de DRESSEUR à battre\n"
	.string "ici…$"
