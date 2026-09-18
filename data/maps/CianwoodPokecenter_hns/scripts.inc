CianwoodPokecenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	@callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "Parmi les POKéMON Eau,\n"
	.string "TENTACOOL est le meilleur, et de\l"
	.string "loin !$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "Tu as l'air d'avoir besoin d'un\n"
	.string "POKéMON Eau.\p"
	.string "Tiens, prends celui-ci, j'en ai plein.$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "Tu as rencontré le POKéMANIAQUE ?\p"
	.string "Il se vante sans cesse de ses\n"
	.string "POKéMON rares.$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "Les Dresseurs de l'ARÈNE POKéMON\n"
	.string "d'ici sont de vraies brutes.\p"
	.string "Si je reste, ils pourraient\n"
	.string "s'en prendre à moi.\p"
	.string "Voici un conseil : le CHAMPION\n"
	.string "utilise le type COMBAT.\p"
	.string "Tu devrais donc le surprendre avec\n"
	.string "des POKéMON Psy.\p"
	.string "Mets ses POKéMON K.O. avant qu'ils\n"
	.string "n'utilisent leur force physique.\p"
	.string "Et ces rochers au centre de\n"
	.string "l'ARÈNE ?\p"
	.string "Si tu ne les bouges pas bien,\n"
	.string "tu n'atteindras pas le CHAMPION.\p"
	.string "Si tu bloques, sors d'ici.$"

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER} ! Tu as gagné !\n"
	.string "Je le savais rien qu'en te voyant !$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "J'adore montrer les POKéMON que\n"
	.string "j'ai élevés.\p"
	.string "Pas toi ?\p"
	.string "Je vais livrer plein de combats\n"
	.string "et montrer mes POKéMON !$"
