NewSinjoh_House1_hns_MapScripts::
	.byte 0


NewSinjoh__House1_EventScripts_Elizabeth::
    lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER, NewSinjoh_House1_EventScript_Elizabeth_AfterGift
    msgbox NewSinjoh_House1_Text_Looking4Celebi MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_House1_EventScript_Decline
    checkspecies SPECIES_CELEBI
    goto_if_eq VAR_RESULT, TRUE, NewSinjoh_House1_EventScript_GiveWooperPaldea
	msgbox NewSinjoh_House1_Text_NicePokemonButNotCelebi, MSGBOX_DEFAULT
    release
    end

NewSinjoh_House1_EventScript_Decline::
	msgbox NewSinjoh_House1_Text_Decline, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_House1_EventScript_GiveWooperPaldea::
	playse SE_PIN
    applymovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH
    msgbox NewSinjoh_House1_OffersWooper MSGBOX_DEFAULT
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WOOPER_PALDEA
    bufferspeciesname STR_VAR_1, SPECIES_WOOPER_PALDEA
    givemon SPECIES_WOOPER_PALDEA, 5
	call Common_EventScript_GiftMon
	setflag FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER
	closemessage
    release
    end

NewSinjoh_House1_Text_Looking4Celebi:
    .string "Salut, Dresseur !\p"
	.string "Tu viens de loin, de\n"
	.string "BOURG GEON ?\p"
	.string "J'ai une demande pour un Dresseur\n"
	.string "aussi voyageur que toi.\l"
	.string "Tu vois, mon POKéMON préféré au\n"
	.string "monde est le POKéMON fabuleux\l"
	.string "nommé CELEBI.\p"
	.string "Si tu en as un, tu voudrais bien\n"
	.string "me le montrer ?$"

NewSinjoh_House1_Text_NicePokemonButNotCelebi:
    .string "Ton POKéMON est formidable,\n"
	.string "mais ce n'est pas exactement\l"
	.string "celui que je cherchais…$"

NewSinjoh_House1_OffersWooper:
    .string "C'est ça ! Un vrai CELEBI vivant !!\p"
	.string "Merci de l'avoir amené jusqu'ici\n"
	.string "pour me le montrer.\p"
    .string "Ma copine en a attrapé quelques-\n"
	.string "uns de trop durant son voyage dans\l"
	.string "une région lointaine…\p"
    .string "Voici un AXOLOTO spécial pour te\n"
	.string "remercier, {PLAYER}.$"

NewSinjoh_House1_Text_Decline:
	.string "Quel dommage. Je voulais vraiment\n"
	.string "en voir un.$"

NewSinjoh_House1_Text_TakeCareOfWooper:
    .string "Prends bien soin de cet AXOLOTO,\n"
	.string "d'accord ?$"

NewSinjoh_House1_EventScript_Elizabeth_AfterGift::
	msgbox NewSinjoh_House1_Text_GoodToSeeYouAgain MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Text_GoodToSeeYouAgain:
    .string "Ça me fait plaisir de te revoir,\n"
	.string "{PLAYER}.\p"
	.string "Tu prends bien soin de cet\n"
	.string "AXOLOTO ?$"

NewSinjoh_House1_Bookshelf::
    lock
	msgbox NewSinjoh_House1_Bookshelf_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Bookshelf_Text:
    .string "Une étagère remplie de jeux\n"
	.string "vidéo et de BD !$"

NewSinjoh_House1_Eevee::
    lock
	faceplayer
	playmoncry SPECIES_EEVEE, 0
	msgbox NewSinjoh_House1_Text_Eevee_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_House1_Text_Eevee_Cry:
    .string "Évo Évo ?$"
