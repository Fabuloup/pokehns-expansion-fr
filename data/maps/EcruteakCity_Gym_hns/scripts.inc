EcruteakCity_Gym_hns_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "Arène de Rosalia$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE ROSALIA\p"
	.string "DRESSEURS CERTIFIÉS DE MORTIMER:\n"
	.string "{PLAYER}$"

MortyIntroText:
	.string "Merci d'être venu.\p"
	.string "Ici, à ROSALIA, les POKéMON\n"
	.string "ont toujours été vénérés.\p"
	.string "On raconte qu'un POKéMON aux\n"
	.string "couleurs de l'arc-en-ciel apparaît\l"
	.string "devant un vrai DRESSEUR.\p"
	.string "J'ai cru cette histoire et me suis\n"
	.string "entraîné ici en secret.\p"
	.string "Ainsi, je vois désormais ce que\n"
	.string "les autres ne voient pas.\p"
	.string "Encore un peu…\p"
	.string "Avec un peu plus d'efforts, je\n"
	.string "verrai l'avenir où je rencontre\l"
	.string "le POKéMON arc-en-ciel.\p"
	.string "Tu vas m'aider à atteindre\n"
	.string "ce niveau!$"

MortyWinLossText:
	.string "Je ne suis pas encore au niveau…\p"
	.string "Très bien. Ce BADGE est à toi.$"

Text_ReceivedFogBadge:
	.string "{PLAYER} reçoit le BADGE BRUME.$"

MortyText_FogBadgeSpeech:
	.string "Grâce au BADGE BRUME, les POKéMON\n"
	.string "jusqu'au niveau 50 t'obéiront.\p"
	.string "De plus, tout POKéMON connaissant\n"
	.string "SURF pourra l'utiliser à tout\l"
	.string "moment.\p"
	.string "Je veux aussi te donner ceci.$"

MortyText_ShadowBallSpeech:
	.string "C'est BALL'OMBRE.\n"
	.string "Elle inflige des dégâts et peut\l"
	.string "baisser la DÉF. SPÉ.\p"
	.string "Utilise-la si elle te convient.$"

MortyFightDoneText:
	.string "Je vois…\p"
	.string "Ton voyage t'a mené dans des\n"
	.string "contrées lointaines.\p"
	.string "Tu as vu plus de choses que\n"
	.string "moi-même.\p"
	.string "Je t'envie pour cela…$"

MortyRematchText:
	.string "Ah, le MAÎTRE DE JOHTO!\n"
	.string "Merci d'être venu.\p"
	.string "Tu as montré force et talent,\n"
	.string "mais as-tu progressé depuis\l"
	.string "notre dernier combat?\p"
	.string "Depuis, je m'entraîne avec mes\n"
	.string "POKéMON de type SPECTRE.\p"
	.string "Voyons si tu peux encore vaincre\n"
	.string "les ombres.\p"
	.string "Tu veux une revanche?$"

Morty_RematchDefeatText:
	.string "Je ne suis pas encore au niveau…\p"
	.string "Tu as vu plus de choses que\n"
	.string "moi-même.\p"
	.string "Je t'envie pour cela…$"

SageJeffreySeenText:
	.string "J'ai passé le printemps avec mes\n"
	.string "POKéMON.\p"
	.string "Puis l'été, l'automne et l'hiver…\p"
	.string "Le printemps est revenu.\n"
	.string "Cela fait bien longtemps.$"

SageJeffreyBeatenText:
	.string "Victoires et défaites, j'ai\n"
	.string "connu les deux.$"

SageJeffreyAfterBattleText:
	.string "D'où viennent les POKéMON?$"

SagePingSeenText:
	.string "Peux-tu infliger des\n"
	.string "dégâts à nos POKéMON?$"

SagePingBeatenText:
	.string "Ah! Bien joué!$"

SagePingAfterBattleText:
	.string "Nos POKéMON sont de type SPECTRE.\p"
	.string "Les attaques de type NORMAL ne\n"
	.string "peuvent pas les blesser!$"

MediumMarthaSeenText:
	.string "Je vais gagner!$"

MediumMarthaBeatenText:
	.string "Et bah non, j'ai perdu!$"

MediumMarthaAfterBattleText:
	.string "Celui qui veut le plus gagner\n"
	.string "finira par l'emporter!$"

MediumGraceSeenText:
	.string "Perdu dans nos couloirs obscurs?\n"
	.string "Bats-moi si tu veux un indice!$"

MediumGraceBeatenText:
	.string "Kk-kkoi?$"

MediumGraceAfterBattleText:
	.string "Bien. Je vais révéler le secret\n"
	.string "des ombres.\p"
	.string "Le chemin est juste devant\n"
	.string "tes yeux!$"

EcruteakCity_GymGuideText:
	.string "Salut CHAMPION! Tu approches\n"
	.string "de la moitié du parcours!\p"
	.string "Les DRESSEURS utilisent des\n"
	.string "POKéMON SPECTRE et TÉNÈBRES.\p"
	.string "MORTIMER maîtrise les SPECTRES,\n"
	.string "mais méfie-toi de son cerf\l"
	.string "mystique.\p"
	.string "On dit qu'il provoque d'étranges\n"
	.string "cauchemars…$"

EcruteakCity_GymGuideWinText:
	.string "Ouf, {PLAYER}. Tu as assuré!\p"
	.string "Je tremblais dans un coin,\n"
	.string "mort de peur!$"

EcruteakCity_GymClosedText:
	.string "MORTIMER, le\n"
	.string "CHAM- PION,\p"
	.string "est absent. Tu\n"
	.string "dois partir.\p"
	.string "Hohohoho.$"
