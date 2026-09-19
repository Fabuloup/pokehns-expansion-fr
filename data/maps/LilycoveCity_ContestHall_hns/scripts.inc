@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_hns_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1_hns::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2_hns::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl_hns::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor_hns::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1_hns::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1_hns::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear_hns, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns:
	.string "Ce POKéMON a déjà gagné en BEAUTÉ\n"
	.string "BEAUTÉ ici.\p"
	.string "Devine! Aujourd'hui, je l'ai\n"
	.string "fait gagner en INTELLIGENCE!\p"
	.string "Même moi, mon talent m'effraie…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns:
	.string "J'ai fait beaucoup de CONCOURS,\n"
	.string "je commence à saisir le système.\p"
	.string "Dans un CONCOURS SANG-FROID,\n"
	.string "les capacités cool plaisent.\p"
	.string "Mais les capacités fines ou\n"
	.string "mignonnes plaisent peu au jury.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns:
	.string "Le vainqueur de tout à l'heure\n"
	.string "avait beaucoup de {POKEBLOCK}S.\p"
	.string "Peut-on gagner avec autant\n"
	.string "de ces choses?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns:
	.string "Ouah, cet endroit est immense!\p"
	.string "Cette tension dans l'air… Rien à\n"
	.string "pas comme un hall de campagne.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns:
	.string "MC: POKéMON INTELLIGENTS et\n"
	.string "DRESSEURS, êtes-vous prêts?!\p"
	.string "Donnez tout ce que vous avez!\n"
	.string "Place aux démonstrations!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns:
	.string "JUGE: Ce CONCOURS vous plaît-il?\p"
	.string "Revenez avec trois amis, et\n"
	.string "vous pourrez tous participer!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest_hns:
	.string "Aïe aïe aïe…\n"
	.string "Je me suis trompé de CONCOURS.\p"
	.string "J'ai inscrit ce robuste POKéMON au\n"
	.string "CONCOURS INTELLIGENCE…\p"
	.string "Allez, impressionne-les avec un\n"
	.string "ÉCLATE-ROC plein de finesse.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns:
	.string "J'ai usé des années et ma sagesse\n"
	.string "sagesse pour rendre ce POKéMON\l"
	.string "intelligent.\p"
	.string "Le POKéMON d'un jeune blanc-bec ne\n"
	.string "le vaincra pas facilement.\p"
	.string "Ma chère épouse, tu vois ça?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns:
	.string "Ça y est!\p"
	.string "Si mon POKéMON joue finement,\n"
	.string "le public atteindra son apogée!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns:
	.string "Oh, non, mon Dieu!\p"
	.string "Son VAMPIRISME est si mignon\n"
	.string "que je l'ai joué sans arrêt!\p"
	.string "Mais ces vilaines personnes ne\n"
	.string "l'apprécient pas du tout!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns:
	.string "Kyaaaah! Tu es magnifique, Papi!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns:
	.string "Même avec les mêmes POKéMON,\n"
	.string "les DRESSEURS choisissent tous\l"
	.string "des capacités différentes.\p"
	.string "C'est comme les styles de combat,\n"
	.string "chacun a le sien.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns:
	.string "Je trouve les POKéMON bien plus\n"
	.string "intelligents que leurs DRESSEURS.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns:
	.string "Après tout, j'adore toujours les\n"
	.string "CONCOURS INTELLIGENCE.\p"
	.string "Ce vert si intellectuel…\n"
	.string "C'est tellement… Tellement… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns:
	.string "MC: Vous entrez aussi en CONCOURS\n"
	.string "BEAUTÉ? Bonne chance!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns:
	.string "JUGE: Ah, chaque POKéMON ici est\n"
	.string "un modèle de beauté parfaite!\p"
	.string "J'ai presque oublié de les noter!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns:
	.string "Un POKéMON aussi beau…\n"
	.string "Il n'y en a pas deux comme lui.\p"
	.string "Tous les regards seront rivés sur\n"
	.string "ma beauté.$"

LilycoveCity_ContestHall_Text_OverdidGrooming_hns:
	.string "Ouinnn!\p"
	.string "J'ai bien brossé mon POKéMON\n"
	.string "avec soin pour ce CONCOURS…\p"
	.string "Mais j'en ai trop fait…\n"
	.string "Son pelage est tout ébouriffé…\p"
	.string "Que faire?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns:
	.string "Cette ONDE BORÉALE éblouit\n"
	.string "que le JUGE ne pourra pas la voir.\p"
	.string "Euh, une seconde…\n"
	.string "Ça ne servira donc à rien!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns:
	.string "Ce joli POKéMON me ressemble comme\n"
	.string "comme moi quand j'étais jeune.\p"
	.string "À ces mots, mon mari a recraché\n"
	.string "le café qu'il buvait.\p"
	.string "J'ai dit quelque chose de drôle?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns:
	.string "Tu sais, gagner un CONCOURS\n"
	.string "BEAUTÉ me rend bien sûr\l"
	.string "heureux. Plus que d'habitude.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns:
	.string "Wahahahah!\p"
	.string "Regarde-moi tous ces\n"
	.string "beaux POKéMON!\l"
	.string "J'adore tout ce qui brille!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns:
	.string "La beauté seule ne suffit pas\n"
	.string "toujours pour gagner.\p"
	.string "Il faut bichonner ton POKéMON pour\n"
	.string "qu'il brille comme le mien.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns:
	.string "MC: Oh! Bonjour!\n"
	.string "Un CONCOURS est en cours!\p"
	.string "Inscrivez-vous d'abord au\n"
	.string "comptoir, puis entrez, d'accord?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns:
	.string "JUGE: Oh, quelles démonstrations\n"
	.string "charmantes et gracieuses!\p"
	.string "Oh là là! Quel adorable\n"
	.string "TOURNIQUET!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns:
	.string "Oh non… Mon adorable AZURILL a été\n"
	.string "distrait par un autre POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns:
	.string "Mon POKéMON perd chaque combat,\n"
	.string "mais en CONCOURS, attention à lui!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns:
	.string "La DANSE FLEURS de mon POKéMON est\n"
	.string "d'une élégance merveilleuse.\p"
	.string "Nul ne troublera sa\n"
	.string "prestation.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns:
	.string "Tous les POKéMON sont adorables.\p"
	.string "Mais si mon POKéMON faisait\n"
	.string "une démonstration gracieuse…\p"
	.string "Elle serait tellement plus\n"
	.string "mignonne que les autres.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest_hns:
	.string "Mon enfant est dans ce CONCOURS.$"

LilycoveCity_ContestHall_Text_ComeOnDear_hns:
	.string "Allez, mon cœur. Vas-y!\n"
	.string "Ton POKéMON est le meilleur!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns:
	.string "Je trouve cette fille là-bas\n"
	.string "la plus mignonne du lot.\p"
	.string "Comment? On juge les\n"
	.string "POKéMON sur leur apparence?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns:
	.string "Oh, tous ces adorables POKéMON\n"
	.string "me donnent envie d'en avoir un!\p"
	.string "Je vais en attraper!$"

LilycoveCity_ContestHall_Text_BeautyContestStage_hns:
	.string "SCÈNE DU CONCOURS BEAUTÉ\n"
	.string "LAISSEZ-VOUS SÉDUIRE!$"

LilycoveCity_ContestHall_Text_CuteContestStage_hns:
	.string "SCÈNE DU CONCOURS GRÂCE\n"
	.string "CRAQUEZ POUR CES POKéMON!$"

LilycoveCity_ContestHall_Text_SmartContestStage_hns:
	.string "SCÈNE DU CONCOURS INTELLIGENCE\n"
	.string "ADMIREZ CES POKéMON MALINS!$"
