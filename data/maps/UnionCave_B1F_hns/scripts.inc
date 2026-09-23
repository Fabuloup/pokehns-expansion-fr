UnionCave_B1F_hns_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP_HNS, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD_HNS, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW_HNS, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN_HNS, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "Ça fait longtemps que je n'ai\n"
	.string "pas eu de compagnie.\p"
	.string "Sois sympa… Un petit combat!$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "Uurggh…$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "Je suis perdu depuis longtemps…\p"
	.string "C'est pas trop grave, mais\n"
	.string "j'ai une de ces faims!$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "Ah bah ça alors! De la visite!$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "Wahahah! T'as du répondant!$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "Je vis ici, moi.\p"
	.string "Toi aussi, si ça te dit.\p"
	.string "Y'a de la place, tu sais.$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "Qui va là?\p"
	.string "Laisse-nous tranquilles, mes\n"
	.string "POKéMON et moi!$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "Va… Va-t'en!$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "Seul avec mes POKéMON.\n"
	.string "C'est la fête.$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "Je suis venu jusqu'ici pour mes\n"
	.string "études sur les POKéMON.\p"
	.string "Je vais te montrer mes trouvailles\n"
	.string "en vrai combat!$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "Démonstration sur moi-même!$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "Je devrais réunir et publier mes\n"
	.string "recherches.\p"
	.string "Je deviendrais peut-être aussi\n"
	.string "célèbre que le PROF. ORME.$"
