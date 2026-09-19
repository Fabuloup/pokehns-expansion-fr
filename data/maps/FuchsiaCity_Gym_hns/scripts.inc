FuchsiaCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Gym_OnTransition
	.byte 0

FuchsiaCity_Gym_OnTransition::
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_OnTransitionAfter
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_7
	call_if_defeated TRAINER_ALICE_HNS, FuchsiaCity_Gym_DefeatedAlice
	call_if_defeated TRAINER_LINDA_HNS, FuchsiaCity_Gym_DefeatedLinda
	call_if_defeated TRAINER_CINDY_HNS, FuchsiaCity_Gym_DefeatedCindy
	call_if_defeated TRAINER_BARRY_HNS, FuchsiaCity_Gym_DefeatedBarry
	end

FuchsiaCity_Gym_OnTransitionAfter::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	end

FuchsiaCity_Gym_DefeatedAlice::
	setflag FLAG_TEMP_2
	clearflag FLAG_TEMP_1
	return

FuchsiaCity_Gym_DefeatedLinda::
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_3
	return

FuchsiaCity_Gym_DefeatedCindy::
	setflag FLAG_TEMP_6
	clearflag FLAG_TEMP_5
	return

FuchsiaCity_Gym_DefeatedBarry::
	setflag FLAG_TEMP_8
	clearflag FLAG_TEMP_7
	return

FuchsiaCity_Gym_EventScript_Janine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_Janine_Defeated
	msgbox FuchsiaCity_Gym_Text_Janine_DisappointYou, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_JANINE_HNS, FuchsiaCity_Gym_Text_Janine_ToughOne
	message FuchsiaCity_Gym_Text_ReceivedSoulBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FuchsiaCity_Gym_Text_Janine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_POISON_JAB
	msgbox FuchsiaCity_Gym_Text_Janine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE14_GET
	setflag FLAG_DEFEATED_FUCHSIA_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 14
	call Common_EventScript_SetGymTrainers_hns
	removeobject LOCALID_FUCHSIAGYM_ALICE_J
	removeobject LOCALID_FUCHSIAGYM_CINDY_J
	removeobject LOCALID_FUCHSIAGYM_LINDA_J
	removeobject LOCALID_FUCHSIAGYM_BARRY_J
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	addobject LOCALID_FUCHSIAGYM_ALICE
	addobject LOCALID_FUCHSIAGYM_CINDY
	addobject LOCALID_FUCHSIAGYM_LINDA
	addobject LOCALID_FUCHSIAGYM_BARRY
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_3
	clearflag FLAG_TEMP_5
	clearflag FLAG_TEMP_7
	clearflag FLAG_HIDE_ROUTE22_JANINE
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Janine_Defeated::
	msgbox FuchsiaCity_Gym_Text_Janine_ApplyMyself, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_Text_Janine_DisappointYou:
	.string "Fufufufu…\p"
	.string "Désolée de te décevoir…\p"
	.string "Je plaisante!\p"
	.string "C'est bien moi!\p"
	.string "JEANNINE de l'ARÈNE DE PARMANIE!$"

FuchsiaCity_Gym_Text_Janine_ToughOne:
	.string "JEANNINE: Tu es coriace. Tu\n"
	.string "as vraiment gagné…\p"
	.string "Voici le BADGE ÂME. Prends-le.$"

FuchsiaCity_Gym_Text_ReceivedSoulBadge:
	.string "{PLAYER} reçoit le BADGE ÂME.$"

FuchsiaCity_Gym_Text_Janine_GiveTM:
	.string "JEANNINE: Tu es si fort! J'ai un\n"
	.string "cadeau spécial pour toi!$"

FuchsiaCity_Gym_Text_Janine_ExplainTM:
	.string "DIRECT TOXIK est de type Poison\n"
	.string "puissante qui peut empoisonner.$"

FuchsiaCity_Gym_Text_Janine_ApplyMyself:
	.string "JEANNINE: Je vais travailler dur\n"
	.string "pour améliorer mes talents.\p"
	.string "Je veux surpasser mon père,\n"
	.string "et toi aussi!$"

FuchsiaCity_Gym_EventScript_Alice_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_ALICE_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_ALICE_J
	clearflag FLAG_TEMP_1
	addobject LOCALID_FUCHSIAGYM_ALICE
	applymovement LOCALID_FUCHSIAGYM_ALICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_ALICE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_LassAlice_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ALICE_HNS, FuchsiaCity_Gym_Text_LassAlice_Beaten
	msgbox FuchsiaCity_Gym_Text_LassAlice_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Alice::
	msgbox FuchsiaCity_Gym_Text_LassAlice_After, MSGBOX_NPC
	end


FuchsiaCity_Gym_EventScript_Linda_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_LINDA_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_LINDA_J
	clearflag FLAG_TEMP_3
	addobject LOCALID_FUCHSIAGYM_LINDA
	applymovement LOCALID_FUCHSIAGYM_LINDA, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_LINDA, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_LassLinda_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LINDA_HNS, FuchsiaCity_Gym_Text_LassLinda_Beaten
	msgbox FuchsiaCity_Gym_Text_LassLinda_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Linda::
	msgbox FuchsiaCity_Gym_Text_LassLinda_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_Cindy_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_CINDY_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_CINDY_J
	clearflag FLAG_TEMP_5
	addobject LOCALID_FUCHSIAGYM_CINDY
	applymovement LOCALID_FUCHSIAGYM_CINDY, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_CINDY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CINDY_HNS, FuchsiaCity_Gym_Text_PicnickerCindy_Beaten
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Cindy::
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_Barry_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_BARRY_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_BARRY_J
	clearflag FLAG_TEMP_7
	addobject LOCALID_FUCHSIAGYM_BARRY
	applymovement LOCALID_FUCHSIAGYM_BARRY, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_BARRY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_CamperBarry_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BARRY_HNS, FuchsiaCity_Gym_Text_CamperBarry_Beaten
	msgbox FuchsiaCity_Gym_Text_CamperBarry_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Barry::
	msgbox FuchsiaCity_Gym_Text_CamperBarry_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_Text_LassAlice_Before:
	.string "Fufufu!\p"
	.string "Je suis JEANNINE, la CHAMPIONNE!\p"
	.string "Mais non! Je t'ai bien eu!$"

FuchsiaCity_Gym_Text_LassAlice_Beaten:
	.string "Je t'ai bien trompé…$"

FuchsiaCity_Gym_Text_LassAlice_After:
	.string "Comment trouver la vraie\n"
	.string "CHAMPIONNE?$"

FuchsiaCity_Gym_Text_LassLinda_Before:
	.string "Je t'ai eu! Hahaha!$"

FuchsiaCity_Gym_Text_LassLinda_Beaten:
	.string "Oh… J'ai perdu… Tu es fort…$"

FuchsiaCity_Gym_Text_LassLinda_After:
	.string "Alors? Déguisement parfait?$"

FuchsiaCity_Gym_Text_PicnickerCindy_Before:
	.string "Je suis JEANNINE!\p"
	.string "Comment as-tu su que c'était moi?\p"
	.string "Au combat!$"

FuchsiaCity_Gym_Text_PicnickerCindy_Beaten:
	.string "Zut! Je voulais gagner!$"

FuchsiaCity_Gym_Text_PicnickerCindy_After:
	.string "Tu dois commencer à fatiguer.$"

FuchsiaCity_Gym_Text_CamperBarry_Before:
	.string "Wahahaha!\p"
	.string "Eh oui! Je suis JEANNINE!$"

FuchsiaCity_Gym_Text_CamperBarry_Beaten:
	.string "Mon déguisement était réussi! Zut!$"

FuchsiaCity_Gym_Text_CamperBarry_After:
	.string "Hé, toi. Mon déguisement était\n"
	.string "mignon, pas vrai?$"

FuchsiaCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_GymGuyAfter
	msgbox FuchsiaCity_Gym_Text_Guide, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_GymGuyAfter::
	msgbox FuchsiaCity_Gym_Text_GuideWin, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE PARMANIE\n"
    .string "CHAMPIONNE: JEANNINE\p"
    .string "DRESSEURS VAINQUEURS:\n"
    .string "BLUE, RED$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE PARMANIE\n"
    .string "CHAMPIONNE: JEANNINE\p"
    .string "DRESSEURS VAINQUEURS:\n"
    .string "BLUE, RED, {PLAYER}$"

FuchsiaCity_Gym_Text_Guide:
	.string "Yo, futur CHAMPION!\p"
	.string "Oups! Regarde bien autour de toi.\p"
	.string "Tous les Dresseurs ressemblent à\n"
	.string "la CHAMPIONNE, JEANNINE.\p"
	.string "Laquelle est la vraie JEANNINE?$"

FuchsiaCity_Gym_Text_GuideWin:
	.string "Quel beau combat, Dresseur\n"
	.string "de JOHTO!$"
