CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Teacher::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_FishingGuru::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_Fisher1::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Fisher2::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_GymGuide::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Gramps::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonGameCorner_Text_PokefanM:
	.string "Les machines à sous sont toutes\n"
	.string "à la pointe.$"

CeladonGameCorner_Text_Teacher:
	.string "C'est cette machine que je veux.\p"
	.string "Elle m'a ruiné hier, alors elle\n"
	.string "devrait payer aujourd'hui.$"

CeladonGameCorner_Text_FishingGuru:
	.string "Je pense que cette machine va\n"
	.string "payer…\p"
	.string "Les chances varient selon les machines.$"

CeladonGameCorner_Text_Fisher1:
	.string "Gahahaha !\p"
	.string "Les Jetons n'arrêtent pas d'arriver !\p"
	.string "Hm ? Quoi, gamin ? Tu veux jouer ?\p"
	.string "Je partage ma chance avec toi !$"

CeladonGameCorner_Text_Fisher2:
	.string "Gahahaha !\p"
	.string "Ça me fait plaisir de faire de bonnes\n"
	.string "actions pour les autres !$"

CeladonGameCorner_Text_GymGuide:
	.string "Hé ! Futur CHAMPION !\p"
	.string "Tu joues aussi aux machines à sous ?\p"
	.string "J'essaie d'avoir assez de Jetons pour\n"
	.string "un POKéMON en prix.\p"
	.string "Mais je n'en ai pas encore assez…$"

CeladonGameCorner_Text_PokefanF:
	.string "La roulette…\p"
	.string "Je la préfère aux machines, car il est\n"
	.string "plus facile d'en évaluer les chances.\p"
	.string "Mais les gains sont bien plus faibles.$"

CeladonGameCorner_Text_Gramps:
	.string "Hmmm… Les chances sont sûrement\n"
	.string "meilleures en misant tout sur le bleu,\l"
	.string "mais… que faire ?$"

CeladonGameCorner_Text_Woman:
	.string "Je n'arrête pas de gagner !$"
