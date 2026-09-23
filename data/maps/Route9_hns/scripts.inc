Route9_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN_HNS, Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI_HNS, Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA_HNS, Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID_HNS, Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM_HNS, Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY_HNS, Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_EventScript_Item_Flash_Cannon::
    finditem ITEM_TM_FLASH_CANNON
    end

Route9_Text_CamperDeanSeen:
	.string "Je suis venu explorer le TUNNEL\n"
	.string "ROCHEUX.$"

Route9_Text_CamperDeanBeaten:
	.string "Ouh là ! Dangereux, mec !$"

Route9_Text_CamperDeanAfter:
	.string "Mes POKéMON ont été blessés avant\n"
	.string "même d'entrer dans le TUNNEL ROCHEUX.\p"
	.string "Je ferais mieux de les amener au\n"
	.string "CENTRE POKéMON tout de suite.$"

Route9_Text_PicnickerHeidiSeen:
	.string "Tu as déjà fait un pique-nique ?\p"
	.string "C'est tellement amusant !$"

Route9_Text_PicnickerHeidiBeaten:
	.string "Ohhhh !$"

Route9_Text_PicnickerHeidiAfter:
	.string "On prépare plein de bonnes choses\n"
	.string "qu'on partage ensuite.\p"
	.string "C'est délicieux !$"

Route9_Text_CamperSidSeen:
	.string "Hé, toi ! Ne jette pas tes déchets !$"

Route9_Text_CamperSidBeaten:
	.string "Je disais juste que…$"

Route9_Text_CamperSidAfter:
	.string "Désolé. Tu ne jetais rien. C'était\n"
	.string "mon erreur.$"

Route9_Text_PicnickerEdnaSeen:
	.string "Les gens ne devraient pas laisser\n"
	.string "leurs déchets derrière eux.$"

Route9_Text_PicnickerEdnaBeaten:
	.string "Ohh… J'ai perdu…$"

Route9_Text_PicnickerEdnaAfter:
	.string "Économiser l'énergie est important,\n"
	.string "mais l'environnement l'est encore\l"
	.string "davantage.$"

Route9_Text_HikerTimSeen:
	.string "Elle arrivera du MONT ARGENT\n"
	.string "quand elle arrivera…\p"
	.string "Le MONT ARGENT est à JOHTO, non ?$"

Route9_Text_HikerTimBeaten:
	.string "J'étais trop occupé à chanter…$"

Route9_Text_HikerTimAfter:
	.string "Les combats demandent de la concentration.$"

Route9_Text_HikerSidneySeen:
	.string "Je vais te dire un secret.\p"
	.string "Mais d'abord, on combat !$"

Route9_Text_HikerSidneyBeaten:
	.string "Oh, zut ! J'ai perdu…$"

Route9_Text_HikerSidneyAfter:
	.string "La CENTRALE est de l'autre côté\n"
	.string "d'une petite rivière.$"

Route9_Text_Sign:
	.string "ROUTE 9\p"
	.string "AZURIA - TUNNEL ROCHEUX$"
