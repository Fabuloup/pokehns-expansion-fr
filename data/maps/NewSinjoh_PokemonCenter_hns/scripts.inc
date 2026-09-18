NewSinjoh_PokemonCenter_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_PokemonCenter_OnTransition
    .byte 0

NewSinjoh_PokemonCenter_OnTransition: 
    setrespawn HEAL_LOCATION_NEW_SINJOH_HNS
    end

NewSinjoh_EventScript_Artist::
	lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT, NewSinjoh_EventScript_ZoomLens_Gotten
	msgbox NewSinjoh_Text_Artist, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_EventScript_ZoomLens_No
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	giveitem ITEM_ZOOM_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT
	release
	end

NewSinjoh_PokemonCenter_EventScript_Skiier::
	lock
	faceplayer
	msgbox NewSinjoh_PokemonCenter_Text_Skiier, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_POKEMONCENTER_SKIIER, DIR_NORTH
	release
	end

NewSinjoh_PokemonCenter_hns_Map::
	lockall
	setvar VAR_0x8000, 1 @ SCREENSHOT_SINJOH_MAP
	msgbox NewSinjoh_PokemonCenter_hns_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

NewSinjoh_PokemonCenter_Text_Skiier:
	.string "La neige rend l'endroit\n"
	.string "difficile à parcourir.\p"
	.string "Tout se ressemble.\p"
	.string "Heureusement, cette carte aide\n"
	.string "beaucoup!\p"
	.string "Quelle belle région!$"

NewSinjoh_Text_Artist:
	.string "J'ai trouvé une grande\n"
	.string "inspiration dans ce village\l"
	.string "caché!\p"
	.string "Tu ne trouves pas le paysage\n"
    .string "à couper le souffle?$"

Text_ItemGiveaway:
	.string "Je vois!\n"
	.string "Tu dois être artiste aussi!\p"
	.string "J'ai justement quelque chose en\n"
	.string "trop qui t'aidera à voir les\l"
    .string "petits détails de la vie!$"

NewSinjoh_Text_Artist_No:
    .string "Tu ne serais pas du genre\n"
    .string "anti-touriste, si?\n"
	.string "La beauté est faite pour être\l"
	.string "partagée.$"

NewSinjoh_EventScript_ZoomLens_No::
	msgbox NewSinjoh_Text_Artist_No, MSGBOX_DEFAULT
	release
	end

NewSinjoh_EventScript_ZoomLens_Gotten::
	msgbox Text_WasGiven_ZoomLensAlready, MSGBOX_DEFAULT
	release
	end

Text_WasGiven_ZoomLensAlready:
	.string "J'espère que cette lentille te\n"
	.string "plaira!$"

NewSinjoh_EventScript_FemAce::
	msgbox NewSinjoh_Text_FemAce, MSGBOX_NPC
	end

NewSinjoh_Text_FemAce:
	.string "Nous n'avons pas beaucoup de\n"
	.string "confort moderne à NEW SINJOH.\p"
	.string "Mais au moins, nous avons ce\n"
	.string "CENTRE POKéMON.$"


NewSinjoh_PokemonCenter_hns_Text_0:
	.string "{PLAYER} observe de plus près\n"
	.string "la carte de SINJOH.$"
