MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON D'ACAJOU$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON D'ACAJOU\p"
	.string "DRESSEURS CERTIFIÉS PAR FRÉDO:\n"
	.string "{PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
	.string "Les POKéMON vivent bien des choses\n"
	.string "au cours de leur vie, comme nous.\p"
	.string "Moi aussi, j'ai beaucoup vu\n"
	.string "et souffert dans ma vie.\p"
	.string "Comme je suis ton aîné, laisse-moi\n"
	.string "te montrer ce que je veux dire.\p"
	.string "Je côtoie les POKéMON depuis\n"
	.string "avant ta naissance.\p"
	.string "Je ne perds pas facilement.\p"
	.string "Moi, FRÉDO, Dresseur de l'hiver,\n"
	.string "je vais te montrer ma puissance!$"

MahoganyTown_Gym_Text_PryceImpressed:
	.string "Ah, ta maîtrise\n"
	.string "m'impressionne.\p"
	.string "Avec ta volonté, je sais que tu\n"
	.string "surmonteras tous les obstacles.\p"
	.string "Tu mérites ce BADGE!$"

MahoganyTown_Gym_Text_ReceivedBadge:
	.string "{PLAYER} reçoit le BADGE GLACIER.$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
	.string "Ce BADGE renforce l'ATTAQUE SPÉ.\n"
	.string "des POKéMON.\p"
	.string "Il permet aussi à tes POKéMON\n"
	.string "d'utiliser SIPHON pour franchir\l"
	.string "de vrais tourbillons.\p"
	.string "Et ceci… Un cadeau de ma part!$"

MahoganyTown_Gym_Text_HailSpeech:
	.string "Cette CT contient GRÊLE.\p"
	.string "Elle inflige des dégâts à chaque\n"
	.string "tour pendant 5 tours.\p"
	.string "Elle illustre la rigueur\n"
	.string "de l'hiver.$"

MahoganyTown_Gym_Text_CherishPokemon:
	.string "Quand glace et neige fondent,\n"
	.string "le printemps arrive.\p"
	.string "Tes POKéMON et toi resterez\n"
	.string "ensemble pendant bien des années.\p"
	.string "Chéris chaque instant avec eux!$"

MahoganyTown_Gym_Text_PryceRematch:
	.string "Ah, CHAMPION de JOHTO!\p"
	.string "Ton talent est vraiment\n"
	.string "remarquable.\p"
	.string "Je suis impressionné.\p"
	.string "Mais même aujourd'hui, nous avons\n"
	.string "à apprendre l'un de l'autre.\p"
	.string "Moi, FRÉDO, Dresseur de l'hiver,\n"
	.string "j'ai encore des tours en réserve.\p"
	.string "Veux-tu prendre ta revanche?$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
	.string "Ah, une fois encore, ta maîtrise\n"
	.string "m'impressionne.\p"
	.string "Avec ta volonté, je sais que tu\n"
	.string "surmonteras tous les obstacles.$"

MahoganyTown_Gym_Text_Guide:
	.string "FRÉDO est un vétéran qui entraîne\n"
	.string "des POKéMON depuis près de 50 ans.\p"
	.string "Son équipe solide peut répondre\n"
	.string "à tout ce que tu lui\l"
	.string "opposeras.\p"
	.string "Le Feu est un bon début,\n"
	.string "mais méfie-toi de la pluie!$"

MahoganyTown_Gym_Text_GuideWin:
	.string "FRÉDO est fort, mais toi,\n"
	.string "tu es exceptionnel!\p"
	.string "Quel combat brûlant, malgré\n"
	.string "l'écart des générations!$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
	.string "Je vais geler tes POKéMON,\n"
	.string "tu ne pourras plus rien faire!$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
	.string "Zut. Je n'ai rien pu faire.$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
	.string "Je crois qu'une capacité permet\n"
	.string "à un POKéMON d'agir même\l"
	.string "gelé.$"

MahoganyTown_Gym_Text_BoarderBradSeen:
	.string "Le sol de l'ARÈNE est glissant.\p"
	.string "C'est amusant, pas vrai?\p"
	.string "Mais hé, nous ne sommes pas ici\n"
	.string "pour jouer!$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
	.string "Tu vois comme nous sommes sérieux?$"

MahoganyTown_Gym_Text_BoarderBradAfter:
	.string "Cette ARÈNE est géniale.\n"
	.string "J'adore surfer sur la neige avec\l"
	.string "mes POKéMON!$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
	.string "Je connais le secret de FRÉDO.$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
	.string "D'accord. Le secret de FRÉDO...$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
	.string "Le secret du pouvoir de FRÉDO…\p"
	.string "Chaque jour, il médite sous une\n"
	.string "pour fortifier son esprit\l"
	.string "et son corps.$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
	.string "Pour atteindre le CHAMPION FRÉDO,\n"
	.string "réfléchis avant de glisser.$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
	.string "Au ski, je ne perdrais jamais!$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
	.string "Sans une glisse précise,\n"
	.string "tu n'iras pas loin dans l'ARÈNE.$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
	.string "Admire mon virage parallèle!$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
	.string "Non! Tu m'as fait chuter!$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
	.string "Je n'aurais pas dû me vanter\n"
	.string "de mes talents de skieuse…$"
