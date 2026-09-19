CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "Oh, {PLAYER}.\n"
    .string "La fontaine est ravissante, non?\p"
    .string "Si vous voulez un autre combat,\n"
    .string "je serai au DOJO.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
	.string "Ce TARTARD est mon\p"
	.string "partenaire. Peut-il évoluer\n"
	.string "en un POKéMON grenouille?$"

CeladonCity_Text_Poliwrath:
	.string "TARTARD: Tarr!$"

CeladonCity_Text_Teacher1:
	.string "J'ai encore perdu aux machines…\p"
	.string "Nous aussi, les filles, on y joue.\p"
	.string "Tu devrais essayer.$"

CeladonCity_Text_Gramps1:
	.string "Des TADMORV apparaissent ici.\p"
	.string "Tu vois l'étang devant cette\n"
	.string "maison? Ils y vivent maintenant.\p"
	.string "D'où viennent-ils? C'est vraiment\n"
	.string "un sérieux problème…$"

CeladonCity_Text_Gramps2:
	.string "Hihi! Cette ARÈNE est géniale!\n"
	.string "C'est réservé aux filles! Youpi!$"

CeladonCity_Text_Youngster1:
	.string "Tu veux connaître un secret?\p"
	.string "Le MANOIR CÉLADON a une\n"
	.string "porte cachée à l'arrière.$"

CeladonCity_Text_Youngster2:
	.string "Il y a un concours de\n"
	.string "bouffe au restaurant.\p"
	.string "Rien que de les regarder\n"
	.string "me donne mal au coeur...$"

CeladonCity_Text_Teacher2:
	.string "Le CENTRE COMMERCIAL de CÉLADOPOLE\n"
	.string "propose le plus grand choix.\p"
	.string "Si tu n'y trouves pas ton bonheur,\n"
	.string "tu ne le trouveras nulle part.\p"
	.string "Euh… On dirait une vendeuse.$"

CeladonCity_Text_Lass:
	.string "J'ai mal\n"
	.string "au crâne.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "CELADOPOLE La ville\p"
	.string "aux rêves arc-en-ciel$"

CeladonGym_Text_Sign:
	.string "CHAMPION d'ARÈNE de\n"
	.string "CELADOPOLE: ERIKA La\p"
	.string "princesse de la nature$"

CeladonCity_Text_DeptStoreSign:
	.string "Y'a de tout au CENTRE\n"
	.string "COMMERCIAL de CELADOPOLE!$"

CeladonCity_Text_MansionSign:
	.string "MANOIR CÉLADON$"

CeladonCity_Text_GameCornerSign:
	.string "Le terrain de jeu de tous:\n"
	.string "CASINO DE CÉLADOPOLE$"

CeladonCity_Text_TrainerTips:
	.string "ASTUCE DRESSEUR\p"
	.string "GARDE-STATS protège les POKéMON\n"
	.string "contre les capacités spéciales\l"
	.string "comme LANCE-FLAMMES et SURF.\p"
	.string "Achetez vos objets au CENTRE\n"
	.string "COMMERCIAL DE CÉLADOPOLE!$"
