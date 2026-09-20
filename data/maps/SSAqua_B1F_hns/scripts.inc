SSAqua_B1F_hns_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "Beurk !\n"
    .string "J'aurais pas dû regarder !$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Hé, petit. Tu peux aller\n"
	.string "chercher mon collègue ?\p"
	.string "Ce fainéant doit se la couler\n"
	.string "douce quelque part !\p"
	.string "J'irais bien le chercher, mais je\n"
	.string "suis de service.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "Oh là là…\p"
	.string "Le CAPITAINE va être furieux…$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "Merci, petit ! Je l'ai bien\n"
	.string "grondé, il ne traînera plus !$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "Une petite fille ?\p"
	.string "Je l'ai peut-être vue passer.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "La salle à manger est devant.\p"
	.string "L'escalier au fond mène à\n"
	.string "la cabine du CAPITAINE.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF_HNS, SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "Rien ne vaut un combat pendant\n"
	.string "ma pause.$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "Gagné ou perdu, pause terminée !$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "Je ne peux pas gagner sans\n"
	.string "combattre sérieusement.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA_HNS, SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "Je m'ennuie. On se bat ?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "Aïe ! Tu es trop fort !$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "SAFRANIA, CÉLADOPOLE… Il y a\n"
	.string "plein de grandes villes à KANTO.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ_HNS, SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "Beurk… J'ai le mal de mer !$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "Je ne peux plus bouger…$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "Plus jamais le bateau.\n"
	.string "La prochaine fois,\p"
	.string "je prends le TRAIN MAGNÉTIQUE.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT_HNS, SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "C'est ici qu'on bosse, matelot !$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "J'ai perdu sur mon terrain…$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "Nous avons différents passagers\n"
	.string "de CARMIN SUR MER à\p"
	.string "OLIVILLE.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH_HNS, SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "Même en pleine mer, je ne peux\n"
	.string "pas pêcher !\p"
	.string "Quel ennui ! Battons-nous !$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "Je… Je ne m'ennuie plus…$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "Je compte pêcher depuis\n"
	.string "le quai de CARMIN SUR MER.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI_HNS, SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "Je renforce mes jambes en\n"
	.string "résistant\p"
	.string "au roulis du bateau !$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "Le roulis m'a renversé !$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "Je n'ai pas trouvé le MAÎTRE\n"
	.string "KARATÉ à JOHTO.\p"
	.string "Il s'entraînerait dans une\n"
	.string "grotte quelque part.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH_HNS, SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "Je suis un marin !\p"
	.string "Mais j'entraîne des POKéMON pour\n"
	.string "devenir le MAÎTRE !$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "Mon manque d'entraînement se voit…$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "Huit BADGES ! Ils prouvent que\n"
	.string "tu as vaincu\p"
	.string "les CHAMPIONS D'ARÈNE.\p"
	.string "Pas étonnant que tu sois si fort !$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY_HNS, SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "Ne touche pas à mes\n"
	.string "élèves !$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "Aaaah !$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "Nous visitons les RUINES près\n"
	.string "de MAUVILLE.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE_HNS, SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "Tu connais les RUINES D'ALPHA ?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "Yaaah !$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "Les radios captent des signaux\n"
	.string "étranges dans les RUINES.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_HNS, SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "Il y a d'étranges panneaux de\n"
	.string "pierre aux RUINES D'ALPHA.$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "Je me suis fait avoir !$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "J'ai lu qu'il y avait quatre\n"
	.string "panneaux de pierre.$"
