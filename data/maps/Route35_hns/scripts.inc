Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "Je récupère des données POKéMON\n"
	.string "à la radio. Je me débrouille.$"

Route35_Text_CamperIvanBeaten:
	.string "J'abandonne!$"

Route35_Text_CamperIvanAfter:
	.string "La musique à la radio change\n"
	.string "l'humeur des POKéMON sauvages.$"

Route35_Text_CamperElliotSeen:
	.string "Je vais montrer à ma copine que\n"
	.string "j'assure!$"

Route35_Text_CamperElliotBeaten:
	.string "Tu aurais pu perdre, pour moi…$"

Route35_Text_CamperElliotAfter:
	.string "Je me suis humilié devant ma\n"
	.string "copine…$"

Route35_Text_PicnickerBrookeSeen:
	.string "Mon copain est faible, je ne peux\n"
	.string "pas compter sur lui.$"

Route35_Text_PicnickerBrookeBeaten:
	.string "Oh là là! Tu es si fort!$"

Route35_Text_PicnickerBrookeAfter:
	.string "Je compte plus sur mes POKéMON\n"
	.string "que sur mon copain.$"

Route35_Text_PicnickerKimSeen:
	.string "Tu vas à l'ARÈNE? Moi aussi!$"

Route35_Text_PicnickerKimBeaten:
	.string "Oh. Je n'ai pas pu gagner…$"

Route35_Text_PicnickerKimAfter:
	.string "Les BADGES d'ARÈNE sont jolis.\n"
	.string "Je les collectionne.$"

Route35_Text_BirdKeeperBryanSeen:
	.string "Quelles BALLS utilises-tu?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "Aïe! Pas assez rapide!$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Certains POKéMON fuient aussitôt.\p"
	.string "Essaie de les attraper avec la\n"
	.string "SPEED BALL de FARGAS.\p"
	.string "Dès que je trouve une BAIE\n"
	.string "WILLIA, je l'apporte à FARGAS.\p"
	.string "Il en fait une BALL sur mesure.$"

Route35_Text_JugglerIrwinSeen:
	.string "Admire ma dextérité avec les\n"
	.string "BALLS!$"

Route35_Text_JugglerIrwinBeaten:
	.string "Ouf! Quelle décharge!$"

Route35_Text_JugglerIrwinAfter:
	.string "J'allais t'éblouir avec mon\n"
	.string "POKéMON vedette.\p"
	.string "Mais ta prouesse m'a électrisé!$"

Route35_Text_BugCatcherArnieSeen:
	.string "J'irais n'importe où s'il y a des\n"
	.string "POKéMON Insecte.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "Hein? Je n'aurais pas dû perdre…$"

Route35_Text_BugCatcherArnieAfter:
	.string "Mon MIMITOSS m'a fait gagner le\n"
	.string "Concours de Capture du PARC\l"
	.string "NATUREL.$"

Route35_Text_IrwinRegister:
	.string "J'allais t'éblouir avec mon\n"
	.string "POKéMON vedette.\p"
	.string "Mais ta prouesse m'a électrisé!$"

Route35_Text_ArnieRegister:
	.string "Mon MIMITOSS m'a fait gagner le\n"
	.string "Concours de Capture du PARC\l"
	.string "NATUREL.$"

Route35_Text_ArnieRematchIntro:
	.string "J'irais n'importe où s'il y a des\n"
	.string "POKéMON Insecte.$"

Route35_Text_ArnieRematchDefeat:
	.string "Hein? Je n'aurais pas dû perdre…$"

Route35_Text_ArniePostRematch:
	.string "Mon MIMITOSS m'a fait gagner le\n"
	.string "Concours de Capture du PARC\l"
	.string "NATUREL.$"

Route35_Text_BugCatcherArnieYanma:
	.string "Ouah… Regarde tous ces YANMA!\p"
	.string "J'en reste cloué sur place.$"

Route35_Text_FirebreatherWaltSeen:
	.string "Je m'entraîne à cracher le feu.$"

Route35_Text_FirebreatherWaltBeaten:
	.string "Aïe! Je me suis roussi le bout\n"
	.string "du nez!$"

Route35_Text_FirebreatherWaltAfter:
	.string "La Marche POKéMON à la radio\n"
	.string "attire les POKéMON sauvages.$"

Route35_Text_OfficerDirkSeen:
	.string "Le danger rôde la nuit!$"

Route35_Text_OfficerDirkBeaten:
	.string "Oups!$"

Route35_Text_OfficerDirkAfter:
	.string "Tu sais, la nuit a ses charmes.\p"
	.string "Mais n'en abuse pas, d'accord?$"

Route35_Text_OfficerDirkTough:
	.string "Tes POKéMON ont l'air costauds.\p"
	.string "Tu peux aller partout sans\n"
	.string "crainte.$"

Route35_Text_Sign:
	.string "ROUTE 35$"

Route35_Text_Sign2:
	.string "PORTE DU PARC NATUREL$"
