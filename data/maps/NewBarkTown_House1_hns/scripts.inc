NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU est un POKéMON évolué.\p"
	.string "Les découvertes du PROF. ORME\n"
	.string "m'ont vraiment impressionnée.\p"
	.string "Il est célèbre pour ses recherches\n"
	.string "sur l'évolution des POKéMON.\p"
	.string "…Soupir…\p"
	.string "J'aimerais devenir chercheuse,\n"
	.string "moi aussi…$"


NewBarkTown_House1_Text_Neighbor:
	.string "Ma fille tient absolument à\n"
	.string "devenir l'assistante du PROF. ORME.\p"
	.string "Elle adore les POKéMON!\p"
	.string "Mais moi aussi, remarquez!$"
