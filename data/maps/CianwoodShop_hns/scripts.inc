CianwoodShop_hns_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::	
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
	.string "Tes POKéMON ont l'air en forme.\p"
	.string "Quelque chose te tracasse?\p"
	.string "…\p"
	.string "Le POKéMON du PHARE est en\n"
	.string "difficulté?\p"
	.string "J'y suis!\p"
	.string "Ceci devrait faire l'affaire.$"

CianwoodCity_Text_ReceivedSecretpotion:
	.string "{PLAYER} reçoit la POTION\n"
	.string "SECRÈTE.$"

CianwoodCity_Text_PharmacistDescribePotion:
	.string "Ma POTION SECRÈTE est un peu trop\n"
	.string "puissante, je ne la donne qu'en\l"
	.string "cas d'urgence.$"
