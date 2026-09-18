MtMortar_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO_HNS, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "Hé!\p"
	.string "Je suis le ROI DU KARATÉ!\n"
	.string "Je m'entraîne seul dans le noir!\p"
	.string "Toi! Affronte-moi!\n"
	.string "Hwaaargh!$"

MountMortar4_Text_KiyoWin:
	.string "Waaaargh!\n"
	.string "Je suis battu!$"

MountMortar4_Text_KiyoTyrogueReward:
	.string "Je… Je suis anéanti…\p"
	.string "Mon entraînement ne suffit\n"
	.string "toujours pas…\p"
	.string "Mais une défaite est une\n"
	.string "défaite. Je le reconnais.\p"
	.string "En preuve de ta victoire, je te\n"
	.string "donne un POKéMON Combat\l"
	.string "très rare.$"

MountMortar4_Text_ReceiveTyrogue:
	.string "{PLAYER} reçoit DEBUGANT.$"

MountMortar4_Text_KiyoGotTyrogue:
	.string "DEBUGANT est de type Combat.\p"
	.string "Il évolue en un POKéMON plus\n"
	.string "robuste.\p"
	.string "Continue à travailler dur.\n"
	.string "Je m'entraînerai aussi.\p"
	.string "Adieu!$"

MountMortar4_Text_KiyoFullParty:
	.string "Ton équipe est complète!$"
