TrainerHill_Roof_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Roof_hns_OnLoad
	.byte 0

TrainerHill_Roof_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

TrainerHill_Roof_hns_EventScript_Owner::
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_Arrived
	case 1, TrainerHill_Roof_hns_EventScript_GivePrize
	case 2, TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_hns_EventScript_Arrived::
	msgbox TrainerHill_Roof_hns_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_hns_EventScript_GivePrize::
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_hns_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_hns_EventScript_CheckFinalTime
TrainerHill_Roof_hns_EventScript_ReceivePrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_NoRoomForPrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_CheckFinalTime::
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_NewRecord
	case 1, TrainerHill_Roof_hns_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
TrainerHill_Roof_hns_EventScript_NewRecord::
	msgbox TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_NoNewRecord::
	msgbox TrainerHill_Roof_hns_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_EndSpeakToOwner::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_Text_YouFinallyCameBravo:
	.string "Hm ! Hm !\p"
	.string "Tu es enfin là !\n"
	.string "Oui, tu es arrivé !\p"
	.string "Attends ! Ne dis rien !\n"
	.string "Je sais pourquoi tu es venu seul\l"
	.string "jusqu'ici !\p"
	.string "Tu voulais voir le propriétaire de\n"
	.string "la COLLINE DES DRESSEURS, car…\p"
	.string "Tu veux faire équipe avec moi !\n"
	.string "Wouhou !\p"
	.string "…Hein ?\n"
	.string "Ce n'est pas ça ?\p"
	.string "Quoi qu'il en soit, je t'ai observé\n"
	.string "en montant. Quel combat merveilleux !$"

TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift:
	.string "Pour une personne merveilleuse comme\n"
	.string "toi, j'ai un cadeau merveilleux,\l"
	.string "et de l'argent pour tes efforts !$"

TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis:
	.string "Tu as trop d'objets !\n"
	.string "Reviens chercher ceci plus tard !$"

TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly:
	.string "Attends ! Tu serais arrivé ici\n"
	.string "incroyablement vite ?\p"
	.string "Formidable ! Tu n'avais pas à te\n"
	.string "presser autant pour me voir !\p"
	.string "C'est merveilleux. J'actualise les\n"
	.string "temps à l'accueil !$"

TrainerHill_Roof_hns_Text_YouWerentVeryQuick:
	.string "Mais, oh…\n"
	.string "Tu n'as pas été très rapide.$"

TrainerHill_Roof_hns_Text_ArriveZippierNextTime:
	.string "Je serais plus content si tu\n"
	.string "arrivais plus vite la prochaine fois.\p"
	.string "Alors, je serai ravi de faire équipe\n"
	.string "avec toi !\p"
	.string "À bientôt, amigo !$"
