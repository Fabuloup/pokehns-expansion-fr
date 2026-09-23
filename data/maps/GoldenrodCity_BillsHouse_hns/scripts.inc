GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
    .string "LEO: Salut, {PLAYER}! Rends-nous\n"
    .string "service et prends cet ÉVOLI.\p"
    .string "On nous l'a confié pendant que\n"
    .string "je travaillais sur mon système.\p"
    .string "Quelqu'un doit s'en occuper, mais\n"
    .string "je n'aime pas sortir.\p"
    .string "Je peux compter sur toi pour\n"
    .string "jouer avec lui, {PLAYER}?$"

BillHouse_Text_CountingOnYou:
    .string "LEO: Je savais que tu\n"
    .string "accepterais!\p"
    .string "Bravo! Tu es quelqu'un de bien!\p"
    .string "Bon, je compte sur toi.\p"
    .string "Prends-en bien soin!$"

BillHouse_Text_ReceivedEevee:
    .string "{PLAYER} reçoit ÉVOLI!$"

BillHouse_Text_EeveeMayEvolve:
    .string "LEO: Le PROF. ORME affirme\n"
    .string "qu'ÉVOLI pourrait évoluer de\l"
    .string "façons nouvelles et inconnues.$"

BillHouse_Text_PartyFull:
    .string "Houlà, attends. Tu ne peux pas\n"
    .string "porter plus de POKéMON.$"

BillHouse_Text_NoEevee:
    .string "Oh… Que faire, alors?$"

BillHouse_Text_PopWontWork:
    .string "LEO: Mon père ne travaille pas.\n"
    .string "Il passe ses journées à\l"
    .string "traînasser.\p"
    .string "Il commence à me donner mal à\n"
    .string "la tête…$"

BillHouse_Text_MomBeforeEcruteak:
    .string "Oh, tu collectionnes les POKéMON?\n"
    .string "Mon fils LEO est un expert.\p"
    .string "On vient de l'appeler au CENTRE\n"
    .string "POKéMON de ROSALIA.\p"
    .string "Mon mari, lui, est parti au\n"
    .string "CASINO sans qu'on l'appelle…$"

BillHouse_Text_MomAfterEcruteak:
    .string "Mon mari était autrefois un\n"
    .string "POKéMANIAC réputé.\p"
    .string "LEO doit tenir de son père.$"

BillHouse_Text_SisterUsefulNumber:
    .string "Tu es DRESSEUR?\p"
    .string "J'ai un numéro de téléphone bien\n"
    .string "utile pour toi.$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER} enregistre le numéro de\n"
    .string "LEO.$"

BillHouse_Text_SisterRefusedNumber:
    .string "Mon frère a créé le système de\n"
    .string "stockage POKéMON sur PC.\p"
    .string "J'allais te donner son numéro…$"

BillHouse_Text_SisterPhoneFull:
    .string "Tu ne peux plus enregistrer de\n"
    .string "numéros.$"

BillHouse_Text_SisterStorageSystem:
    .string "Mon grand frère LEO a créé le\n"
    .string "système de stockage POKéMON sur\l"
    .string "PC.$"
