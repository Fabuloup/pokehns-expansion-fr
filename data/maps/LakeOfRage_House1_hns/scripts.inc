LakeOfRage_House1_hns_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
    .string "…Tu t'es égaré bien loin…\p"
    .string "J'ai médité ici. En moi, une\n"
    .string "nouvelle puissance s'est éveillée.\p"
    .string "Laisse-moi la partager avec tes\n"
    .string "POKéMON. Prends ceci, enfant.$"

HiddenPowerGuy_Text_Explanation:
    .string "Tu la vois? C'est PUISSANCE\n"
    .string "CACHÉE!\p"
    .string "Elle tire la puissance du POKéMON\n"
    .string "pour attaquer.\p"
    .string "Retiens bien: son type et sa\n"
    .string "puissance dépendent du POKéMON\l"
    .string "qui l'utilise.$"

HiddenPowerGuy_Text_Meditating:
    .string "Je médite…$"
