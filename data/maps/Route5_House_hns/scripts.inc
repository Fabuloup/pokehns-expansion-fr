Route5_House_hns_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "Eeyaaaah!\p"
	.string "Je sens une ombre sinistre\n"
	.string "planer au-dessus de toi.\l"
	.string "Prends ceci pour la conjurer!$"

Route5_House_Text_Granny2:
	.string "Tu étais en danger de mort, mais\n"
	.string "te voilà protégé.$"

Route5_House_Text_Woman:
	.string "Ma grand-mère conjure ce qu'elle\n"
	.string "prend pour de mauvais esprits.\p"
	.string "Désolée qu'elle t'ait effrayé.$"
