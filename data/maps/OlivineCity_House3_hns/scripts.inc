OlivineCity_House3_hns_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "OLIVILLE est au bord de la mer!\p"
	.string "Et au bord de la mer, il y a\n"
	.string "forcément du poisson!\p"
	.string "Je pêche ici depuis 30 ans.\p"
	.string "Tu veux affronter la mer et\n"
	.string "t'essayer à la pêche?$"

OlivineCity_Text_GiveGoodRod:
	.string "Ah, hahah! Voilà un futur\n"
	.string "pêcheur!$"

OlivineCity_Text_GaveGoodRod:
	.string "Le poisson n'est pas que dans la\n"
	.string "mer: il est partout où il y a\l"
	.string "de l'eau.\p"
	.string "Au fait, ton POKéDEX indique les\n"
	.string "groupes de pêche des POKéMON.\p"
	.string "Des lieux différents peuvent\n"
	.string "abriter les mêmes poissons.$"

OlivineCity_Text_DontWantGoodRod:
	.string "Quooooi? Tu n'aimes pas pêcher!?\n"
	.string "C'est incompréhensible!$"

OlivineCity_Text_HaveGoodRod:
	.string "Alors, ça mord?\n"
	.string "Tu as sorti la grosse prise?$"
