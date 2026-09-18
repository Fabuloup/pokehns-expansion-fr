Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
	
Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
	.string "Hé! Je cherche un FÉROSINGE!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Battu par un inconnu de passage!$"

Route34_Text_YoungsterSamuel_After:
	.string "Je vais m'entraîner encore plus\n"
	.string "dur.\p"
	.string "Après tout, je veux devenir\n"
	.string "CHAMPION d'ARÈNE.$"

Route34_Text_YoungsterIan_Seen:
	.string "Je suis le meilleur de ma classe\n"
	.string "en POKéMON.$"

Route34_Text_YoungsterIan_Beaten:
	.string "Non! Il y a de meilleurs\n"
	.string "Dresseurs…$"

Route34_Text_YoungsterIan_After:
	.string "Je travaille dur pour être la\n"
	.string "star de ma classe.$"

Route34_Text_CamperTodd_Seen:
	.string "J'ai confiance en ma façon\n"
	.string "d'élever les POKéMON.\p"
	.string "Tu veux voir?$"

Route34_Text_CamperTodd_Beaten:
	.string "J'ai raté mon entraînement?$"

Route34_Text_CamperTodd_After:
	.string "Je devrais peut-être en mettre\n"
	.string "un en PENSION, ou utiliser des\l"
	.string "objets…$"

Route34_Text_ToddRegister:
	.string "Je devrais peut-être en mettre\n"
	.string "un en PENSION, ou utiliser des\l"
	.string "objets…$"

Route34_Text_ToddRematchIntro:
	.string "J'ai confiance en ma façon\n"
	.string "d'élever les POKéMON.\p"
	.string "Tu veux voir?$"

Route34_Text_ToddRematchDefeat:
	.string "J'ai raté mon entraînement?$"

Route34_Text_ToddPostRematch:
	.string "Je devrais peut-être en mettre\n"
	.string "un en PENSION, ou utiliser des\l"
	.string "objets…$"

Route34_Text_GinaRegister:
	.string "Tu es bien trop fort pour un\n"
	.string "simple entraînement.$"

Route34_Text_PicnickerGina_Seen:
	.string "Tu es DRESSEUR?\p"
	.string "Faisons un combat d'entraînement.$"

Route34_Text_PicnickerGina_Beaten:
	.string "Oh non! Je n'arrive pas à\n"
	.string "gagner…$"

Route34_Text_PicnickerGina_After:
	.string "Tu es bien trop fort pour un\n"
	.string "simple entraînement.$"

Route34_Text_OfficerKeith_Seen:
	.string "Qui va là?\n"
	.string "Qu'est-ce que tu manigances?$"

Route34_Text_OfficerKeith_Win:
	.string "Tu es coriace, petit.$"

Route34_Text_OfficerKeith_After:
	.string "Bon, rien à signaler aujourd'hui.\p"
	.string "Sois sage et pas d'ennuis.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Je patrouille à la recherche\n"
	.string "d'individus suspects.$"

Route34_Text_PokefanBrandon_Seen:
	.string "Je viens de récupérer mon\n"
	.string "POKéMON à la PENSION.\p"
	.string "Voyons combien il a progressé!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "Pourquoi ça finit comme ça?$"

Route34_Text_PokefanBrandon_After:
	.string "Mon POKéMON est revenu avec de\n"
	.string "nouvelles capacités.\p"
	.string "Ça m'a complètement dérouté!$"

Route34_Text_Sign_IlexForest:
	.string "BOIS AUX CHÊNES\n"
	.string "APRÈS LA PORTE$"

Route34_Text_Sign_Route34:
	.string "ROUTE 34\n"
	.string "DOUBLONVILLE - ÉCORCIA\p"
	.string "BOIS AUX CHÊNES SUR LA ROUTE$"

Route34_Text_TrainerTips:
	.string "ASTUCE\p"
	.string "Les arbres à BAIES donnent de\n"
	.string "nouvelles BAIES plusieurs fois\l"
	.string "par jour.\p"
	.string "Notez quel arbre donne quelle\n"
	.string "BAIE.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "AMY: Kyaaah! Qui es-tu?!$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "AMY: Ohhh! Tu es trop fort!$"

Route34_Text_CooltrainerIrene_After1:
	.string "AMY: Ma soeur IRENE te fera\n"
	.string "payer ça!$"

Route34_Text_CooltrainerIrene_After2:
	.string "AMY: Elle est pas excellente,\n"
	.string "cette plage?\p"
	.string "C'est notre cachette secrète!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "MARIA: Mais…?\n"
	.string "Qu'est-ce que tu fais?$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "MARIA: Pardon AMY! Ma soeur\n"
	.string "chérie!$"

Route34_Text_CooltrainerJenn_After1:
	.string "MARIA: Ne crâne pas trop! Ma\n"
	.string "soeur IRENE est très forte!$"

Route34_Text_CooltrainerJenn_After2:
	.string "MARIA: Le soleil rend le corps\n"
	.string "plus fort.$"

Route34_Text_CooltrainerKate_Seen:
	.string "IRENE: Tu vas me payer ce que\n"
	.string "tu as fait à mes petites soeurs!$"

Route34_Text_CooltrainerKate_Beaten:
	.string "IRENE: Non! J'ai perdu!\n"
	.string "Incroyable!$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "IRENE: Tu es trop balèze.\n"
	.string "Nous n'avions aucune chance…\p"
	.string "Tiens, prends ceci!$"

Route34_Text_CooltrainerKate_After:
	.string "IRENE: Désolée de t'avoir sauté\n"
	.string "dessus.\p"
	.string "On ne pensait pas que quelqu'un\n"
	.string "nous trouverait ici. Tu nous as\l"
	.string "bien surprises.$"


Route34_Text_Sign_DayCare:
	.string "PENSION\p"
	.string "ON ÉLÈVE VOS POKéMON POUR VOUS!$"
