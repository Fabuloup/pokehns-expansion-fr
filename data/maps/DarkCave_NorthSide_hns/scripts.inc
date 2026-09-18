DarkCave_NorthSide_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_NorthSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "Whoa! Tu m'as fait peur!\p"
    .string "J'avais mes LUNETTES NOIRES, je\n"
    .string "ne t'ai pas vu du tout.\p"
    .string "Ce que je fais ici?\p"
    .string "Hé, ne t'en occupe pas.\p"
    .string "Je te donne une paire de\n"
    .string "LUNETTES NOIRES, alors oublie\n"
    .string "que tu m'as vu, d'accord?$"

DarkCave2_Text_Nerd2:
    .string "Les LUNETTES NOIRES renforcent\n"
    .string "les capacités de type TÉNÈBRES.$"
