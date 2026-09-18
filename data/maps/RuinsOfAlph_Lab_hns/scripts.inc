RuinsOfAlph_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

RuinsOfAlph_Lab_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RuinsOfAlph_Lab_EventScript_Scientist1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Lab_Text_Scientist1, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_Lab_EventScript_Scientist2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Lab_Text_Scientist2, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_Lab_EventScript_Fossils::
	lock
	msgbox RuinsOfAlph_Lab_Text_Fossils, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Lab_Text_Scientist1:
	.string "Les RUINES ont environ 1500 ans.\p"
	.string "Mais on ignore pourquoi elles ont\n"
	.string "été bâties, et par qui.$"

RuinsOfAlph_Lab_Text_Scientist2:
	.string "D'étranges figures sont dessinées\n"
	.string "sur les murs des RUINES.\p"
	.string "Ce sont sûrement les clés du\n"
	.string "mystère des RUINES.$"

RuinsOfAlph_Lab_Text_Fossils:
	.string "Des fossiles trouvés dans les\n"
	.string "RUINES. Il y en a peut-être\l"
	.string "d'autres ailleurs…$"


RuinsOfAlph_Lab_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RuinsOfAlph_Lab_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RuinsOfAlph_Lab_EventScript_StillRegenerating
	msgbox RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeClawFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeHelixFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeDomeFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeOldAmber
	release
	end

@ This whole section has needless duplication and could be condensed considerably
RuinsOfAlph_Lab_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveRootFossil
	end

RuinsOfAlph_Lab_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeClawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveClawFossil
	end

RuinsOfAlph_Lab_EventScript_GiveClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeHelixFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveHelixFossil
	end

RuinsOfAlph_Lab_EventScript_GiveHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeDomeFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveDomeFossil
	end

RuinsOfAlph_Lab_EventScript_GiveDomeFossil::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_DOME_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeOldAmber::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveOldAmber
	end

RuinsOfAlph_Lab_EventScript_GiveOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_OLD_AMBER
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
	release
	end

RuinsOfAlph_Lab_EventScript_DeclineGiveFossil::
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2::
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo2, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_StillRegenerating::
	msgbox RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RuinsOfAlph_Lab_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RuinsOfAlph_Lab_EventScript_AnorithReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, RuinsOfAlph_Lab_EventScript_OmanyteReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, RuinsOfAlph_Lab_EventScript_KabutoReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, RuinsOfAlph_Lab_EventScript_AeroReady
	end

RuinsOfAlph_Lab_EventScript_LileepReady::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveLileep
	end

RuinsOfAlph_Lab_EventScript_AnorithReady::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveAnorith
	end

RuinsOfAlph_Lab_EventScript_OmanyteReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveOmanyte
	end

RuinsOfAlph_Lab_EventScript_KabutoReady::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveKabuto
	end

RuinsOfAlph_Lab_EventScript_AeroReady::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileep::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveLileepParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveLileepPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingLileep::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorith::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
	end

RuinsOfAlph_Lab_EventScript_TransferAnorithToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	end

RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC::
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	call_if_unset FLAG_BADGE04_GET, RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto
	call_if_set FLAG_BADGE04_GET, RuinsOfAlph_Lab_EventScript_GiveLateKabuto
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto::
	givemon SPECIES_KABUTO, 5
	return

RuinsOfAlph_Lab_EventScript_GiveLateKabuto::
	givemon SPECIES_KABUTO, 20
	return

RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferKabutoToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveAero::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAeroParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAeroPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveAeroParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveAeroPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferAeroToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingAero::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end


RuinsOfAlph_Lab_EventScript_ChooseFossil::
	message RuinsOfAlph_Lab_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_HNS, FALSE
	switch VAR_RESULT
	case 0, RuinsOfAlph_Lab_EventScript_ChooseClawFossil
	case 1, RuinsOfAlph_Lab_EventScript_ChooseRootFossil
	case 2, RuinsOfAlph_Lab_EventScript_ChooseHelixFossil
	case 3, RuinsOfAlph_Lab_EventScript_ChooseDomeFossil
	case 4, RuinsOfAlph_Lab_EventScript_ChooseOldAmber
	case 5, RuinsOfAlph_Lab_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RuinsOfAlph_Lab_EventScript_CancelFossilSelect
	end

RuinsOfAlph_Lab_EventScript_ChooseClawFossil::
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveClawFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseRootFossil::
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveRootFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseHelixFossil::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveHelixFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseDomeFossil::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveDomeFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseOldAmber::
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveOldAmber
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_CancelFossilSelect::
	release
	end

RuinsOfAlph_Lab_EventScript_WorkOnNext::
	msgbox RuinsOfAlph_Lab_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_Text_DeviceForTalkingToPokemon:
	.string "Nous développons un appareil pour\n"
	.string "parler aux POKéMON.\p"
	.string "Mais nous n'avons pas eu beaucoup\n"
	.string "de succès…$"

RuinsOfAlph_Lab_Text_DevelopingNewBalls:
	.string "Je développe de nouveaux types de\n"
	.string "POKé BALL…\p"
	.string "Mais je n'avance pas beaucoup…$"

RuinsOfAlph_Lab_Text_WeFinallyMadeNewBalls:
	.string "Nous avons enfin créé de nouveaux\n"
	.string "types de POKé BALL!\p"
	.string "La BIS BALL facilite la capture\n"
	.string "des POKéMON déjà attrapés.\p"
	.string "La CHRONO BALL capture d'autant\n"
	.string "mieux que le combat dure.\p"
	.string "Les deux sont fièrement mises au\n"
	.string "point par la DEVON SARL.\p"
	.string "Essaie-les donc!$"

RuinsOfAlph_Lab_Text_IMadePokenav:
	.string "C'est moi qui ai fait le POKéNAV!\p"
	.string "Comme ingénieur, quelle chance\n"
	.string "d'avoir créé une telle merveille!$"

RuinsOfAlph_Lab_Text_WowThatsAPokenav:
	.string "Oh, ça alors!\n"
	.string "C'est un POKéNAV!\p"
	.string "Il est né du souhait de notre\n"
	.string "PRÉSIDENT de comprendre les\l"
	.string "sentiments des POKéMON.\p"
	.string "Veux-tu que je te décrive ses\n"
	.string "fonctions en détail?\p"
	.string "Non, non. Tu comprendras vite en\n"
	.string "essayant le POKéNAV toi-même.$"

RuinsOfAlph_Lab_Text_DeviceToVisualizePokemonDreams:
	.string "J'essaie de mettre au point un\n"
	.string "appareil qui reproduit en images\l"
	.string "les rêves des POKéMON…\p"
	.string "Mais ça n'avance pas fort.$"

RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils:
	.string "J'essayais de mettre au point un\n"
	.string "appareil capable de ressusciter\l"
	.string "les POKéMON fossiles…\p"
	.string "Et ça marche!$"

RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife:
	.string "Attends! Ce truc que tu as là…\n"
	.string "C'est un fossile de POKéMON?\p"
	.string "Tu veux ramener ce POKéMON à la\n"
	.string "vie?\p"
	.string "J'en suis capable avec mon tout\n"
	.string "nouveau RÉGÉNÉRATEUR DE FOSSILE.$"

RuinsOfAlph_Lab_Text_OhIsThatSo:
	.string "Ah bon, vraiment?\p"
	.string "Mon savoir-faire technique est\n"
	.string "remarquable, je t'assure.$"

RuinsOfAlph_Lab_Text_OhIsThatSo2:
	.string "Oh, tu n'as pas ce fossile.\n"
	.string "Reviens si tu arrives à le\l"
	.string "trouver.$"

RuinsOfAlph_Lab_Text_TwoFossilsPickOne:
	.string "Oh, en voilà une surprise!\n"
	.string "Tu as plus d'un fossile?\p"
	.string "Hélas, ma machine ne régénère\n"
	.string "qu'un POKéMON à la fois.\p"
	.string "Quel fossile veux-tu régénérer?$"

RuinsOfAlph_Lab_Text_HandedFossilToResearcher:
	.string "Excellent!\n"
	.string "Faisons ça tout de suite.\p"
	.string "{PLAYER} confie le {STR_VAR_1} au\n"
	.string "CHERCHEUR DES RUINES.$"

RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime:
	.string "Le RÉGÉNÉRATEUR DE FOSSILE que\n"
	.string "j'ai créé est incroyable.\p"
	.string "Mais il a un défaut: il met très\n"
	.string "longtemps à agir.\p"
	.string "Alors, euh… Si tu allais faire\n"
	.string "un tour en attendant?$"

RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife:
	.string "Merci d'avoir patienté!\p"
	.string "Ton POKéMON fossile a été ramené\n"
	.string "à la vie!\p"
	.string "Le fossile était un POKéMON\n"
	.string "ancien. Un {STR_VAR_2}!$"

RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} reçoit {STR_VAR_2} du\n"
	.string "CHERCHEUR.$"

@ Unused
RuinsOfAlph_Lab_Text_TooManyPokemon:
	.string "Oh non, tu as trop de POKéMON.\n"
	.string "Tu n'as plus de place pour lui.$"

RuinsOfAlph_Lab_Text_DevelopNewPokenavFeature:
	.string "J'essaie de développer une\n"
	.string "nouvelle fonction pour le\l"
	.string "POKéNAV…\p"
	.string "Mais ça n'avance pas fort.$"

RuinsOfAlph_Lab_Text_WhatToWorkOnNext:
	.string "Bon, sur quoi vais-je travailler\n"
	.string "maintenant?\p"
	.string "Notre société nous laisse\n"
	.string "concrétiser nos inspirations.\p"
	.string "On ne peut rêver meilleur cadre\n"
	.string "pour un ingénieur.$"


