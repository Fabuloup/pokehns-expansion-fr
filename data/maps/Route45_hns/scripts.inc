Route45_hns_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK_HNS, Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL_HNS, Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY_HNS, Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten, Route45_EventScript_RegisterParry
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchParry
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterParry::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_ParryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PARRY_HNS
	release
	end

Route45_EventScript_RematchParry::
	trainerbattle_rematch TRAINER_PARRY_HNS, Route45_Text_ParryRematchIntro, Route45_Text_ParryRematchDefeat
	msgbox Route45_Text_ParryPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_HNS, Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI_HNS, Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten, Route45_EventScript_RegisterKenji
	goto_if_set FLAG_KENJI_HAS_ITEM_HNS, Route45_EventScript_KenjiGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchKenji
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterKenji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_KenjiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENJI_HNS
	release
	end

Route45_EventScript_RematchKenji::
	trainerbattle_rematch TRAINER_KENJI_HNS, Route45_Text_KenjiRematchIntro, Route45_Text_KenjiRematchDefeat
	msgbox Route45_Text_KenjiPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiGiveItem::
	msgbox Route45_Text_KenjiHasItem, MSGBOX_DEFAULT
	giveitem VAR_KENJI_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route45_EventScript_KenjiNoRoom
	clearflag FLAG_KENJI_HAS_ITEM_HNS
	msgbox Route45_Text_KenjiGaveItem, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiNoRoom::
	msgbox Route45_Text_KenjiNoRoom, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN_HNS, Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY_HNS, Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN_HNS, Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "Prépare-toi à tout!\p"
    .string "Voyons si tes POKéMON ont\n"
    .string "été bien élevés!$"

Route45_Text_HikerErikBeaten:
    .string "Oh, j'ai perdu!$"

Route45_Text_HikerErikAfter:
    .string "Je vais retourner à la ROUTE DE\n"
    .string "GLACE d'ÉBÈNELLE pour m'entraîner.$"

Route45_Text_HikerMichaelSeen:
    .string "Hé! Tu as du cran! Mais tu sais\n"
    .string "quoi?\p"
    .string "Pour ce qui est du pur\n"
    .string "courage, je suis le meilleur!$"

Route45_Text_HikerMichaelBeaten:
    .string "Mes POKéMON manquaient de cran!$"

Route45_Text_HikerMichaelAfter:
    .string "J'adore les PV PLUS! Miam!\p"
    .string "Je bois ceux de mes POKéMON !\p"
    .string "Je ne peux pas m'en empêcher!$"

Route45_Text_HikerParrySeen:
    .string "Mes POKéMON débordent d'énergie !$"

Route45_Text_HikerParryBeaten:
    .string "Wahaha! Je suis le grand perdant!$"

Route45_Text_HikerParryAfter:
    .string "Je ne suis pas très doué pour\n"
    .string "réfléchir, tu vois?\p"
    .string "Alors j'attaque à fond !$"

Route45_Text_ParryRegister:
    .string "Je ne suis pas très doué pour\n"
    .string "réfléchir, tu vois?\p"
    .string "Alors j'attaque à fond !$"

Route45_Text_ParryRematchIntro:
    .string "Mes POKéMON débordent d'énergie !$"

Route45_Text_ParryRematchDefeat:
    .string "Wahaha! Je suis le grand perdant!$"

Route45_Text_ParryPostRematch:
    .string "Je ne suis pas très doué pour\n"
    .string "réfléchir, tu vois?\p"
    .string "Alors j'attaque à fond !$"

Route45_Text_HikerTimothySeen:
    .string "Pourquoi gravir des montagnes?\p"
    .string "Parce qu'elles sont là.\p"
    .string "Pourquoi entraîner des POKéMON?\p"
    .string "Parce qu'ils sont là!$"

Route45_Text_HikerTimothyBeaten:
    .string "Les défaites… Elles sont là aussi!$"

Route45_Text_HikerTimothyAfter:
    .string "La plus belle chose de ma vie fut\n"
    .string "de découvrir les POKéMON.$"

Route45_Text_HikerParryGivesIron:
    .string "Je ne vois aucun moyen de gagner !\p"
    .string "Continue comme ça!\p"
    .string "Oh, et prends ceci. C'est le\n"
    .string "cadeau que tu n'avais pu prendre\n"
    .string "la dernière fois.$"

Route45_Text_BlackbeltKenjiSeen:
    .string "Je m'entraînais seul ici.\p"
    .string "Admire le fruit de mon travail!$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "Waaaaargh!$"

Route45_Text_BlackbeltKenjiAfter:
    .string "Il faut des mesures extrêmes.\p"
    .string "Je dois partir dans les collines\n"
    .string "m'entraîner seul.$"

Route45_Text_KenjiRegister:
    .string "Il faut des mesures extrêmes.\p"
    .string "Je dois partir dans les collines\n"
    .string "m'entraîner seul.$"

Route45_Text_KenjiRematchIntro:
    .string "Je m'entraînais seul ici.\p"
    .string "Admire le fruit de mon travail!$"

Route45_Text_KenjiRematchDefeat:
    .string "Waaaaargh!$"

Route45_Text_KenjiPostRematch:
    .string "Il faut des mesures extrêmes.\p"
    .string "Je dois partir dans les collines\n"
    .string "m'entraîner seul.$"

Route45_Text_KenjiHasItem:
    .string "Hé! Je fais une pause dans mon\n"
    .string "entraînement.\p"
    .string "J'ai trouvé un bon objet dehors.\n"
    .string "Tiens, prends-le!$"

Route45_Text_KenjiGaveItem:
    .string "Utilise-le bien!\p"
    .string "Je dois reprendre mon\n"
    .string "entraînement. Ooooaaaargh!$"

Route45_Text_KenjiNoRoom:
    .string "Hum, ton SAC est plein.\p"
    .string "Reviens avec de la place.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "Je vais encore m'entraîner un peu\n"
    .string "avant la pause déjeuner.$"

Route45_Text_BlackbeltKenjiNight:
    .string "Nous avons bien récupéré à midi,\p"
    .string "alors nous pouvons repartir !\p"
    .string "Nous allons encore nous entraîner!$"

Route45_Text_CooltrainermRyanSeen:
    .string "Que penses-tu de la façon\n"
    .string "d'élever les POKéMON?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "Tu as gagné mon respect.$"

Route45_Text_CooltrainermRyanAfter:
    .string "Je vois que tu élèves tes POKéMON\n"
    .string "avec soin.\p"
    .string "Le lien que tu crées te sauvera\n"
    .string "dans les moments difficiles.$"

Route45_Text_CooltrainerfKellySeen:
    .string "Quelle est ta stratégie de combat?\p"
    .string "Lancer de fortes capacités sans\n"
    .string "réfléchir est insensé.$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "Très bien. J'ai perdu.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "Je n'aime pas les capacités\n"
    .string "trop puissantes.\p"
    .string "Je veux gagner sans pour autant\n"
    .string "blesser les POKéMON.$"

Route45_Text_CamperQuentinSeen:
    .string "Je suis vraiment très fort!$"

Route45_Text_CamperQuentinBeaten:
    .string "J'étais fort sur la COLLINE…$"

Route45_Text_CamperQuentinAfter:
    .string "Tu connais la COLLINE DRESSEURS?\p"
    .string "Je n'y perds jamais, mais…$"

Route45_Text_Sign:
    .string "ROUTE 45\n"
    .string "ROUTE DE MONTAGNE DROIT DEVANT$"
