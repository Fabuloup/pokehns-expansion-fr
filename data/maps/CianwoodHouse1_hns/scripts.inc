CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "Je ne me souviens même plus de\n"
	.string "la dernière fois qu'on m'a rendu\l"
	.string "visite.\p"
	.string "Quand j'étais jeune, moi aussi,\n"
	.string "j'étais Dresseur de POKéMON.\l"
	.string "J'ai tenté d'atteindre la tour et\l"
	.string "de plonger au fond de l'océan.\p"
	.string "Je me suis donné beaucoup de mal\n"
	.string "pour bien des choses.\p"
	.string "Mais aujourd'hui, je me repose en\n"
	.string "écoutant les vagues et le vent\l"
	.string "sur cette plage.$"

CianwoodCity_Text_BellTowerStory:
	.string "Connais-tu la TOUR FERRAILLE\n"
	.string "de ROSALIA?\p"
	.string "Au sommet se trouvent des cloches\n"
	.string "appelées GLAS TRANSPARENTS.\p"
	.string "Elles ne produisent aucun son,\n"
	.string "même sous les vents violents.\p"
	.string "Il n'existe qu'un moyen de les\n"
	.string "faire sonner.\p"
	.string "Il faut obtenir un autre\n"
	.string "GLAS TRANSPARENT, identique à ceux\l"
	.string "du sommet.\p"
	.string "Je suis parti à sa recherche\n"
	.string "quand j'étais jeune.\l"
	.string "Mais je n'en ai jamais trouvé…$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "Connais-tu les TOURB'ÎLES?\p"
	.string "Au pied de leur cascade se\n"
	.string "trouvent des GLAS TEMPÊTE.\p"
	.string "On ne les entend pas sonner,\n"
	.string "même sous les vagues déchaînées.\p"
	.string "Il n'existe qu'un moyen de les\n"
	.string "faire sonner.\p"
	.string "Il faut obtenir un autre\n"
	.string "GLAS TEMPÊTE, identique à ceux\l"
	.string "près de la cascade.\p"
	.string "Je suis parti à sa recherche\n"
	.string "quand j'étais jeune.\l"
	.string "Mais je n'en ai jamais trouvé…$"

CianwoodCity_Text_ClearBellReaction:
	.string "Oh! Tu as réussi à obtenir un\n"
	.string "GLAS TRANSPARENT?\p"
	.string "Ce vieux rêve que j'avais…\n"
	.string "Je vois…\p"
	.string "Tu l'as réalisé…\n"
	.string "…\l"
	.string "… Je l'entends!\p"
	.string "Le tintement des cloches porté par\n"
	.string "le vent, depuis la direction de\l"
	.string "la TOUR FERRAILLE…$"

CianwoodCity_Text_TidalBellReaction:
	.string "Oh! Tu as réussi à obtenir un\n"
	.string "GLAS TEMPÊTE?\p"
	.string "Ce vieux rêve que j'avais…\n"
	.string "Je vois…\p"
	.string "Tu l'as réalisé…\n"
	.string "…\l"
	.string "… Je l'entends!\p"
	.string "Le tintement des cloches porté par\n"
	.string "la brise marine, depuis la\l"
	.string "direction des TOURB'ÎLES…$"
