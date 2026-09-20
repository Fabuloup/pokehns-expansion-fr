Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
    .string "Aaargh!\p"
    .string "Tu m'as fait perdre un PTITARD!\n"
    .string "Comment vas-tu réparer ça?$"

Route44_Text_FisherWilton1Beaten:
    .string "Laisse tomber.$"

Route44_Text_FisherWiltonHugePoliwag:
    .string "Ce PTITARD qui s'est échappé…\n"
    .string "Il était énorme.\p"
    .string "Je jure qu'il devait bien faire\n"
    .string "cinq mètres de long!$"

Route44_Text_WiltonRegister:
    .string "Ce PTITARD qui s'est échappé…\n"
    .string "Il était énorme.\p"
    .string "Je jure qu'il devait bien faire\n"
    .string "cinq mètres de long!$"

Route44_Text_WiltonRematchIntro:
    .string "Aaargh!\p"
    .string "Tu m'as fait perdre un PTITARD!\n"
    .string "Comment vas-tu réparer ça?$"

Route44_Text_WiltonRematchDefeat:
    .string "Laisse tomber.$"

Route44_Text_WiltonPostRematch:
    .string "Ce PTITARD qui s'est échappé…\n"
    .string "Il était énorme.\p"
    .string "Je jure qu'il devait bien faire\n"
    .string "cinq mètres de long!$"

Route44_Text_WiltonHasItem:
    .string "Hé! J'ai pêché quelque chose\n"
    .string "qui n'est pas un POKéMON!\p"
    .string "Tiens, c'est pour toi!$"

Route44_Text_WiltonGaveItem:
    .string "Je te préviendrai si je\n"
    .string "repêche autre chose!$"

Route44_Text_WiltonNoRoom:
    .string "Hum, ton SAC est plein.\p"
    .string "Reviens avec de la place.$"

Route44_Text_FisherEdgarSeen:
    .string "Je pêche jusqu'à l'épuisement.\p"
    .string "Je combats aussi jusqu'à tomber.\p"
    .string "Voilà ma relation avec mes\n"
    .string "POKéMON.$"

Route44_Text_FisherEdgarBeaten:
    .string "Hummm… Ça ne va pas.$"

Route44_Text_FisherEdgarAfter:
    .string "Cent victoires pour 101 défaites.\p"
    .string "J'éviterai les combats un temps.$"

Route44_Text_BirdKeeperVance1Seen:
    .string "Tu connais les légendaires\n"
    .string "POKéMON oiseaux?$"

Route44_Text_BirdKeeperVance1Beaten:
    .string "Ouf! Tu es redoutable.$"

Route44_Text_BirdKeeperVanceBirds:
    .string "ARTIKODIN, ÉLECTHOR et SULFURA\n"
    .string "sont trois oiseaux légendaires.\p"
    .string "On dit qu'il existe d'autres\n"
    .string "oiseaux légendaires.$"

Route44_Text_VanceRegister:
    .string "ARTIKODIN, ÉLECTHOR et SULFURA\n"
    .string "sont trois oiseaux légendaires.\p"
    .string "On dit qu'il existe d'autres\n"
    .string "oiseaux légendaires.$"

Route44_Text_VanceRematchIntro:
    .string "Tu connais les légendaires\n"
    .string "POKéMON oiseaux?$"

Route44_Text_VanceRematchDefeat:
    .string "Ouf! Tu es redoutable.$"

Route44_Text_VancePostRematch:
    .string "ARTIKODIN, ÉLECTHOR et SULFURA\n"
    .string "sont trois oiseaux légendaires.\p"
    .string "On dit qu'il existe d'autres\n"
    .string "oiseaux légendaires.$"

Route44_Text_PsychicPhilSeen:
    .string "Cette fois, je vais gagner!$"

Route44_Text_PsychicPhilBeaten:
    .string "Argh… Quelle défaite choquante…$"

Route44_Text_PsychicPhilAfter:
    .string "Il est important d'avoir ses\n"
    .string "convictions avec soi.$"

Route44_Text_PokemaniacZachSeen:
    .string "Je ferai tout pour mettre la main\n"
    .string "sur des POKéMON rares!$"

Route44_Text_PokemaniacZachBeaten:
    .string "Oooh, tes POKéMON sont si\n"
    .string "attirants.$"

Route44_Text_PokemaniacZachAfter:
    .string "Un POKéMON de couleur étrange\n"
    .string "a plus de valeur.\p"
    .string "Quoi? Ce n'est pas vrai?$"

Route44_Text_CooltrainermAllenSeen:
    .string "Je vois que tu es un bon Dresseur\n"
    .string "rien qu'en te regardant.\p"
    .string "Je connais bien les POKéMON et je\n"
    .string "vois que toi aussi.$"

Route44_Text_CooltrainermAllenBeaten:
    .string "Pff ! J'ai perdu lamentablement.$"

Route44_Text_CooltrainermAllenAfter:
    .string "Ouah. Tu as beaucoup de BADGES.\p"
    .string "Pas étonnant que tu sois si fort.\p"
    .string "Je me demande si MORTIMER de\n"
    .string "s'entraîne toujours à ROSALIA.\p"
    .string "Il m'a vraiment écrasé.$"

Route44_Text_CooltrainerfCybilSeen:
    .string "Tu as l'air fort.\p"
    .string "Les bons Dresseurs recherchent\n"
    .string "de puissants adversaires.$"

Route44_Text_CooltrainerfCybilBeaten:
    .string "Non! Ça ne va pas du tout.$"

Route44_Text_CooltrainerfCybilAfter:
    .string "On progresse tous en livrant\n"
    .string "de nombreux combats.\p"
    .string "J'ai livré bien des combats pour\n"
    .string "ce que je suis: une experte.$"

Route44_Text_Sign1:
    .string "ROUTE 44\n"
    .string "ROUTE DE GLACE DROIT DEVANT$"

Route44_Text_Sign2:
    .string "ROUTE 44\p"
    .string "ACAJOU - ÉBÈNELLE$"
