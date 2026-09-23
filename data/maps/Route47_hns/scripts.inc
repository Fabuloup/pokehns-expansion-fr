Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "Désirer ce qu'ont les autres…\n"
	.string "C'est humain.\p"
	.string "Mais un combat reste un combat,\n"
	.string "alors allons-y!$"

Route47_Text_HikerBeaten::
	.string "Wahaha!$"

Route47_Text_HikerAfter::
	.string "Après un combat, il faut toujours\n"
	.string "partir dans un grand rire!$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "Je n'aime pas les grandes foules,\n"
	.string "alors je campe ici avec mes\l"
	.string "POKéMON!$"

Route47_Text_CamperBeaten::
	.string "Je devrais aller plus loin dans\n"
	.string "la montagne, je suppose…$"

Route47_Text_CamperAfter::
	.string "À plus!$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "THOM: Un plus un font deux. Mais\n"
	.string "ensemble, nous sommes bien\l"
	.string "plus forts!\p"
	.string "KAE: Nous ne sommes pas un couple\n"
	.string "ennuyeux comme les autres!$"

Route47_Text_Couple1Beaten::
	.string "THOM: Je ne m'attendais pas à ça.\l"
	.string "KAE: Toi aussi, tu es spécial!$"

Route47_Text_Couple1After1::
	.string "THOM: Ta puissance semble\n"
	.string "impossible à prévoir!$"

Route47_Text_Couple1After2::
	.string "KAE: Je te croyais simple Dresseur\n"
	.string "solitaire. Quelle erreur!$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "DUFF: Veiller sur ma petite amie\n"
	.string "fait bondir mon cœur!\p"
	.string "EDA: Mes sentiments pour mon\n"
	.string "petit ami sont aussi vastes et\l"
	.string "profonds que l'océan!$"

Route47_Text_Couple2Beaten::
	.string "DUFF: Je n'étais pas à ta hauteur…\l"
	.string "EDA: Tu es vraiment incroyable…$"

Route47_Text_Couple2After1::
	.string "DUFF: Merci pour ce combat\n"
	.string "impressionnant! Salut!$"

Route47_Text_Couple2After2::
	.string "EDA: Toi aussi, trouve-toi un\n"
	.string "partenaire merveilleux!$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "Eh bien, bonjour!\p"
	.string "On dit qu'au-delà de ce trou se\n"
	.string "dressait une immense tour montant\l"
	.string "jusqu'au ciel.\p"
	.string "C'était, dit-on, une étrange tour\n"
	.string "dont la moitié était encastrée\l"
	.string "dans la falaise.\p"
	.string "Elle ne montait pas seulement vers\n"
	.string "le ciel, elle plongeait aussi très\l"
	.string "profond sous terre!\p"
	.string "La rumeur dit qu'elle atteignait\n"
	.string "même le fond de l'océan!\p"
	.string "En bref, ces ruines reliaient\n"
	.string "autrefois le ciel, la terre et la\l"
	.string "mer entre eux…\p"
	.string "La majeure partie s'est effondrée,\n"
	.string "et seuls subsistent aujourd'hui\l"
	.string "l'entrée et l'intérieur, où tu\l"
	.string "verras d'étranges motifs.$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "LOUPIO: Piou!$"
