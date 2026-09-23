MtMortar_1F_North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Protector::
    finditem ITEM_PROTECTOR
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER_HNS, MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS_HNS, MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "Je ne perdrai pas cette fois!$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "J'ai perdu contre un gamin…?$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "Il y a quelque temps, un type en\n"
	.string "karaté voulait se battre.\p"
	.string "Il était ridiculement fort.\n"
	.string "Il nous a mis une raclée.\p"
	.string "Il est parti plus loin en disant\n"
	.string "que c'était pour son\l"
	.string "entraînement.\p"
	.string "Je me demande comment il va.$"

MountMortar2_Text_SupernerdMarkusSeen:
	.string "Hey! HUGH!$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "Je t'ai pris pour quelqu'un\n"
	.string "d'autre…$"

MountMortar2_Text_SupernerdMarkusAfter:
	.string "Je suis venu explorer le MONT\n"
	.string "CREUSET, mais j'ai perdu mon\l"
	.string "coéquipier…\p"
	.string "Tu n'aurais pas croisé un\n"
	.string "Dresseur avec un HYPOCÉAN qui\l"
	.string "connaît CASCADE?$"
