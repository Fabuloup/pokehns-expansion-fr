CeladonCity_Apartments_2F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} allume le PC.\p"
	.string "…\p"
	.string "Quelqu'un était en train d'écrire\n"
	.string "un e-mail.\p"
	.string "… J'espère que tu viendras visiter\n"
	.string "KANTO.\p"
	.string "Je pense que tu seras surpris par\n"
	.string "tous les changements survenus ici.\p"
	.string "Tu verras beaucoup de POKéMON\n"
	.string "qui ne sont pas originaires de\l"
	.string "JOHTO.\p"
	.string "Au PRODUCTEUR\p"
	.string "…$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "BUREAU DE DÉVELOPPEMENT\n"
	.string "HEART & SOUL$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "Salut tout le monde, Patch 15…\p"
	.string "Pardon, je veux dire…\p"
	.string "Salut! Je suis le\n"
	.string "DIRECTEUR DU JEU!\p"
	.string "J'ai créé les cartes, les décors,\n"
	.string "les scripts et bien plus encore.\p"
	.string "Mais je n'aurais rien fait sans\n"
	.string "les autres développeurs et les\l"
	.string "testeurs.\p"
	.string "Merci d'avoir joué! J'espère que\n"
	.string "POKéMON HEART & SOUL t'a plu.$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "Nous travaillons à recréer ce jeu\n"
	.string "avec pokeemerald-expansion!$"

CeladonMansion2F_Text_TixoRebel:
	.string "Tu connais THE EGGENING?\n"
	.string "C'était un bug des tests qui\l"
	.string "changeait des POKéMON au hasard\l"
	.string "en ŒUFS!\p"
	.string "C'est moi qui l'ai corrigé!$"

CeladonMansion2F_Text_Phant:
	.string "J'adore les DEMAKES!\p"
	.string "Tu as joué à SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH?\l"
	.string "Je l'ai traduit!\p"
	.string "Pour mon prochain DEMAKE, je pense\n"
	.string "m'attaquer à ALOLA!$"

CeladonMansion2F_Text_Exclsior:
	.string "J'ai créé les sprites de surf\n"
	.string "propres à chaque POKéMON!\p"
	.string "Comme le projet est OPEN SOURCE,\n"
	.string "tu peux aussi ajouter tes propres\l"
	.string "fonctionnalités!$"

CeladonMansion2F_Text_DaniRaibow:
	.string "Salut!\p"
	.string "Je me débrouille bien pour repérer\n"
	.string "les problèmes et corriger les plus\l"
	.string "petits.\p"
    .string "Tu veux entendre une blague?\p"
    .string "PETER a tenté d'apprendre\n"
    .string "DRACO-SOUFFLE à DRACOLOSSE.\p"
    .string "Mais avec VITESSE EXTRÊME,\n"
    .string "DRACOLOSSE allait trop vite pour\l"
    .string "reprendre son souffle!$"
