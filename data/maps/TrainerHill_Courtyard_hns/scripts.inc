TrainerHill_Courtyard_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "Waouh, la COLLINE est immense !\p"
	.string "Il doit y avoir beaucoup de sortes\n"
	.string "de POKéMON là-dedans !$"

BattleTowerOutsideBeautyText:
	.string "Dans les TENTES DE COMBAT, tu ne\n"
	.string "peux utiliser que trois POKéMON.\p"
	.string "C'est si dur de choisir lesquels\n"
	.string "envoyer au combat…$"

BattleTowerOutsideSailorText:
	.string "Héhéhé, j'ai séché le travail.\p"
	.string "Je ne repartirai pas sans gagner !\p"
	.string "Je dois tout remporter. Point !$"

BattleTowerOutsideSignText:
	.string "{UP_ARROW} ENTRÉE COLLINE DRESSEURS\p"
	.string "Gravissez les sommets, fougueux\n"
	.string "DRESSEURS !\p"
	.string "{RIGHT_ARROW} TENTES DE COMBAT.$"

BattleTower_Battle_Tent_Text_Factory:
	.string "TENTE DE COMBAT : USINE\n"
	.string "Trouvez le POKéMON ultime !$"

BattleTower_Battle_Tent_Text_Palace:
	.string "TENTE DE COMBAT : DÔME\n"
	.string "Admirez ces combats !$"

BattleTower_Battle_Tent_Text_Arena:
	.string "TENTE DE COMBAT : ARÈNE\n"
	.string "Place aux meilleures équipes !$"

BattleTowerOutsideText_Closed:
	.string "La COLLINE DRESSEURS est fermée\n"
	.string "pour réparations.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_LeftMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_RightMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_ElementalMoveTutor
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PowerClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "Salut ! Si tu cherches l'ÉCHANGE\n"
	.string "MIRACLE, il est désormais dans\l"
	.string "chaque CENTRE POKéMON. Amuse-toi !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Bonjour, voici le COMPTOIR\n"
	.string "D'ÉCHANGE.\p"
	.string "Nous échangeons vos Points Combat\n"
	.string "contre de superbes prix.\p"
	.string "Choisis un prix dans cette liste.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, ils sont si beaux !\n"
	.string "J'aimerais les avoir !\l"
	.string "De jolis coussins !\l"
	.string "De grandes PELUCHES !\l"
	.string "De petites PELUCHES !\l"
	.string "Je les veux tous !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Laisse faire maman !\p"
	.string "Si tu le veux, je ferai tout pour\n"
	.string "te l'offrir, mon cœur !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Si j'obtiens les objets d'ici,\n"
	.string "mes POKéMON seront plus forts.\p"
	.string "C'est certain !\n"
	.string "Aucun doute là-dessus !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hein ?\n"
	.string "Qu'est-ce que tu regardes ?\p"
	.string "Je n'aime pas que tu fixes ma\n"
	.string "peluche comme ça.\p"
	.string "Si tu la veux, trouve-t'en une !\n"
	.string "Pas vrai, LIPPOUTI ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Tu savais ?\p"
	.string "Plus ton record grandit dans les\n"
	.string "bâtiments de COMBAT, plus tu\l"
	.string "reçois de Points de Combat.$"
