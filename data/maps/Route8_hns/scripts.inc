Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "On est de la FÉDÉRATION POKéMON\n"
	.string "de KANTO.\p"
	.string "On va t'écraser sous nos roues !$"

Route8_Text_BikerDwayneBeaten:
	.string "Dé-désolé !$"

Route8_Text_BikerDwayneAfter:
	.string "La FÉDÉRATION POKéMON de KANTO\n"
	.string "ne tombera jamais !$"

Route8_Text_BikerHarrisSeen:
	.string "Les flics ont fermé le\n"
	.string "PASSAGE SOUTERRAIN !\p"
	.string "Ça me rend dingue !$"

Route8_Text_BikerHarrisBeaten:
	.string "P-pardonne-moi !$"

Route8_Text_BikerHarrisAfter:
	.string "Vaincu par un môme de\n"
	.string "JOHTO…$"

Route8_Text_BikerZekeSeen:
	.string "On est la FÉDÉRATION POKéMON\n"
	.string "de KANTO !\n"
	.string "Ça roule !$"

Route8_Text_BikerZekeBeaten:
	.string "Aïe ! Désolé !$"

Route8_Text_BikerZekeAfter:
	.string "On va éviter de gêner les gens\n"
	.string "à présent…$"

Route8_Text_SupernerdSamSeen:
	.string "Comment marche le TRAIN MAGNET ?$"

Route8_Text_SupernerdSamBeaten:
	.string "Je veux voir le TRAIN\n"
	.string "MAGNET…$"

Route8_Text_SupernerdSamAfter:
	.string "La force des aimants est géniale !$"

Route8_Text_SupernerdTomSeen:
	.string "Hm… Tu as beaucoup de BADGES.$"

Route8_Text_SupernerdTomBeaten:
	.string "Comme prévu… Tu es fort !$"

Route8_Text_SupernerdTomAfter:
	.string "Les BADGES D'ARÈNE donnent des\n"
	.string "avantages en combat.$"

Route8_Text_LockedDoor:
	.string "C'est fermé…$"

Route8_Text_UndergroundPathSign:
	.string "Le prospectus est déchiré.\p"
	.string "Impossible de le lire…$"
