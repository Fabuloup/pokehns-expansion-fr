BlackthornCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY_HNS, BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN_HNS, BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL_HNS, BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_HNS, BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_HNS, BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1_HNS, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers_hns
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
    .string "Je suis SANDRA. Je suis\p"
    .string "la reine des dragons.\p"
    .string "Je peux même tenir\n"
    .string "tête au CONSEIL des 4\p"
    .string "de la LIGUE. Tu veux\p"
    .string "toujours te battre?\p"
    .string "...Bon. C'est parti! Je\n"
    .string "vais pas y aller mollo!$"

BlackthornGym_Text_ClairWinText:
    .string "Perdu? J'y crois\p"
    .string "pas!! Il y a sûrement\n"
    .string "une erreur...$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
    .string "Je refuse de l'admettre.\p"
    .string "J'ai peut-être perdu, mais tu n'es\n"
    .string "pas prêt pour la LIGUE POKéMON.\p"
    .string "Je sais. Relève l'épreuve des\n"
    .string "dresseurs de dragons.\p"
    .string "Derrière cette ARÈNE se trouve\n"
    .string "l'ANTRE DU DRAGON.\p"
    .string "Un petit sanctuaire se trouve en\n"
    .string "son centre. Vas-y.\p"
    .string "Si tu prouves que tu as renoncé\n"
    .string "à tes idéaux paresseux, je te\l"
    .string "reconnaîtrai comme un DRESSEUR\l"
    .string "digne d'un BADGE!$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
    .string "Et alors? On a\p"
    .string "peur maintenant?$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
    .string "Tu en as mis du temps!\p"
    .string "Tiens! Prends ça!$"

BlackthornGym_Text_ClairText_DescribeTM:
    .string "Elle contient DRACOGRIFFE.\p"
    .string "Tu devineras bien son effet.$"

BlackthornGym_Text_ClairText_League:
    .string "Qu'est-ce qui ne va pas?\p"
    .string "Tu ne vas pas à la LIGUE\n"
    .string "POKéMON?\p"
    .string "Tu ignores où elle se trouve?\p"
    .string "Pars d'ici vers BOURG GEON.\p"
    .string "Puis SURFE vers l'est. La route\n"
    .string "est très difficile.\p"
    .string "Ne perds surtout pas à la LIGUE\n"
    .string "POKéMON!\p"
    .string "Sinon, ma défaite contre toi me\n"
    .string "fera encore plus mal!\p"
    .string "Donne tout ce que tu as.$"

BlackthornGym_Text_ClairAfterLeague:
    .string "Tu as réussi, alors?\p"
    .string "Tu es désormais MAÎTRE DE JOHTO.$"

BlackthornGym_Text_ClairRematchText:
    .string "Tu as réussi, alors?\p"
    .string "Tu es désormais MAÎTRE DE JOHTO.\p"
	.string "Tu as prouvé ta force. Peux-tu\n"
    .string "encore me vaincre?\p"
    .string "Comme Maître Dragon, je ne me\n"
    .string "retiendrai pas.\p"
    .string "Pas cette fois.\p"
    .string "Tu veux une revanche?$"

BlackthornGym_Text_ClairRematchDefeatText:
    .string "J'ai perdu?\p"
    .string "Encore?\p"
    .string "Je n'y crois pas. Il doit y avoir\n"
    .string "une erreur…$"

BlackthornGym_Text_CooltrainermCodySeenText:
    .string "Je peux enfin utiliser les POKéMON\n"
    .string "de type DRAGON!$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
    .string "Zut! Si j'avais un DRACOLOSSE!$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
	.string "Notre clan ne peut utiliser\n"
    .string "les POKéMON dragons qu'après\l"
    .string "l'autorisation du MAÎTRE.$"

BlackthornGym_Text_CooltrainerfFranSeenText:
    .string "Un dresseur quelconque\n"
    .string "ne passera pas! SANDRA\p"
    .string "ne le permettrait pas!$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
    .string "Pffff. Perdu...$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
    .string "Oulà! La SANDRA elle sera furax!$"

BlackthornGym_Text_CooltrainermPaulSeenText:
    .string "Premier combat contre des dragons?\p"
    .string "Je vais te montrer leur force!$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
    .string "Mes POKéMON dragon ont perdu?$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
    .string "PETER voulait\n"
    .string "te revoir?\p"
    .string "Mensonge!$"

BlackthornGym_Text_CooltrainermMikeSeenText:
    .string "Mes chances de perdre?\n"
    .string "Même pas une sur mille!$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
    .string "Je ne suis plus très bon en maths.$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
    .string "Je connais enfin mes faiblesses.\p"
    .string "Merci de me les avoir montrées!$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
    .string "Le type Dragon regroupe des\p"
    .string "POKéMON sacrés, pleins de vie.\p"
    .string "Tu ne pourras pas les battre\n"
    .string "si tu ne te donnes pas à fond.$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
    .string "Bien joué!$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
    .string "Les dragons sont faibles face\n"
    .string "aux attaques de type DRAGON.$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_GymGuy3
	msgbox BlackthornGym_Text_GuideGotoDragonsDen, MSGBOX_DEFAULT
	release
	end

BlackthornGym_EventScript_GymGuy3::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
    .string "Yo! Futur CHAMPION!\p"
    .string "Le voyage a été long, mais nous\n"
    .string "y sommes presque! Compte sur moi!\p"
    .string "SANDRA admire le Maître Dragon\n"
    .string "PETER, mais elle a su créer son\l"
    .string "propre style avec une équipe\l"
    .string "originale composée de dragons\l"
    .string "venus de la mer.\p"
    .string "Les dragons sont vulnérables\n"
    .string "aux capacités de type GLACE,\l"
    .string "mais il te faudra aussi des\l"
    .string "capacités DRAGON ou de type FÉE\l"
    .string "pour gagner.$"
    .string "Tu peux le faire!$"

BlackthornGym_Text_GuideGotoDragonsDen:
	.string "Bravo, tu as battu SANDRA!\p"
	.string "Mais elle est un peu mauvaise\n"
	.string "perdante.\p"
	.string "Tu dois aller à l'ANTRE DU DRAGON\n"
	.string "si tu veux obtenir ce BADGE!$"

BlackthornGym_Text_GuideWinText:
    .string "Bien joué! Beau combat!\p"
    .string "Il ne reste plus que le\n"
    .string "challenge de la LIGUE\p"
    .string "POKéMON. Tu es sur le point\n"
    .string "de devenir MAÎTRE POKéMON!$"


BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "Arène d'Ebènelle$"

BlackthornGym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON D'ÉBÈNELLE\p"
	.string "DRESSEURS CERTIFIÉS DE SANDRA:\n"
	.string "{PLAYER}$"
