LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "Bienvenue! N'hésitez pas à visiter\n"
	.string "tout cet étage.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Désolé, seul le rez-de-chaussée\n"
	.string "se visite.\p"
	.string "Depuis que la TOUR RADIO de JOHTO\n"
	.string "a été occupée par des criminels,\l"
	.string "nous avons dû renforcer\l"
	.string "la sécurité.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Beaucoup de gens travaillent dur\n"
	.string "dans cette TOUR RADIO.\p"
	.string "Ils doivent tout donner pour\n"
	.string "produire de bonnes émissions.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "Oh, non, non, non!\p"
	.string "Plus d'émission depuis l'arrêt\n"
	.string "de la CENTRALE.\p"
	.string "Tous mes efforts pour lancer cette\n"
	.string "station seront vains si je ne peux\l"
	.string "plus émettre.\p"
	.string "Je suis ruiné!$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah! C'est toi, {PLAYER}, qui as\n"
	.string "résolu le problème de la CENTRALE?\p"
	.string "Grâce à toi, je n'ai pas perdu mon\n"
	.string "travail.\p"
	.string "Tu m'as vraiment sauvé\n"
	.string "la mise!\p"
	.string "Accepte ceci en remerciement.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} obtient la\n"
	.string "CARTE EXTENSION!$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "Avec ça, tu peux écouter les\n"
	.string "programmes radio de KANTO.\p"
	.string "Gahahahaha!$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Salut!\p"
	.string "Je suis le DIRECTEUR MUSICAL!\p"
	.string "Hein? Ta RADIO ne capte pas\n"
	.string "mes programmes. Quel dommage!\p"
	.string "Avec une CARTE EXTENSION,\n"
	.string "tu pourrais les écouter. Va en\l"
	.string "chercher une!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "Salut!\p"
	.string "Je suis le DIRECTEUR MUSICAL!\p"
	.string "Je suis responsable des superbes\n"
	.string "mélodies diffusées sur les ondes.\p"
	.string "Ne reste pas vieux jeu. Cueille la\n"
	.string "musique dans les airs!$"

LavenderTown_RadioStation_Text_Directory:
	.string "RDC ACCUEIL 1ER VENTES\p"
	.string "2E PERSONNEL 3E PRODUCTION\p"
	.string "4E BUREAU DU DIRECTEUR$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Réveillez les POKéMON au doux\n"
	.string "son de la POKé FLÛTE sur\l"
	.string "le CANAL 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Ouah! Une étagère pleine de CD et\n"
	.string "de vidéos POKéMON.\p"
	.string "Ce doit être la bibliothèque\n"
	.string "de référence.$"
