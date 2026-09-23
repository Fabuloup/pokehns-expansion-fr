GoldenrodCity_UndergroundStorage_hns_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19_HNS, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12_HNS, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3_HNS, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
    .string "Comment es-tu arrivé jusqu'ici?\p"
    .string "Tant pis. Je vais devoir me\n"
    .string "débarrasser de toi.$"

RadioTowerBasement_Text_GruntM24Beaten:
    .string "C'est moi qu'on a jeté…$"

RadioTowerBasement_Text_GruntM24After:
    .string "La TEAM ROCKET continuera, en\n"
    .string "attendant le retour de GIOVANNI.\p"
    .string "On fera tout ce qu'il faudra.$"

RadioTowerBasement_Text_GruntM14Seen:
    .string "Tu n'iras pas plus loin!\p"
    .string "Je n'ai aucune pitié pour mes\n"
    .string "ennemis, même les morveux!$"

RadioTowerBasement_Text_GruntM14Beaten:
    .string "Bon sang!$"

RadioTowerBasement_Text_GruntM14After:
    .string "J'ai perdu…\p"
    .string "Pardonnez-moi, GIOVANNI!$"

RadioTowerBasement_Text_GruntM15Seen:
    .string "Hé-hé-hé! Regardez qui voilà!\p"
    .string "Prêt? Je suis vraiment costaud\n"
    .string "maintenant!$"

RadioTowerBasement_Text_GruntM15Beaten:
    .string "Hé-hé-hé! Tu es vraiment doué!\p"
    .string "La TEAM ROCKET, c'est juste un\n"
    .string "boulot, mais je vois bien que ça\l"
    .string "fait du mal aux gens.\p"
    .string "Ça suffit, je m'en vais.\p"
    .string "Merci beaucoup. Pardon GIOVANNI!$"

RadioTowerBasement_Text_GruntM15After:
    .string "Hé-hé-hé! C'était génial!\n"
    .string "Je me souviendrai de toi!$"

RadioTowerBasement_Text_DirectorIntro:
    .string "DIRECTEUR: Qui? Quoi? Tu es venu\n"
    .string "me secourir?\p"
    .string "Merci!\p"
    .string "La TOUR RADIO!\p"
    .string "Que se passe-t-il là-bas?\p"
    .string "Prise par la TEAM ROCKET?\p"
    .string "Tiens. Prends cette CARTE\n"
    .string "MAGNÉTIQUE.$"

RadioTowerBasement_Text_DirectorCardKey:
    .string "DIRECTEUR: Utilise-la pour ouvrir\n"
    .string "les volets du 3F.$"

RadioTowerBasement_Text_DirectorAfter:
    .string "Je t'en supplie, aide-nous.\p"
    .string "Impossible de savoir ce qu'ils\n"
    .string "feront s'ils contrôlent\l"
    .string "l'émetteur.\p"
    .string "Ils pourraient même contrôler les\n"
    .string "POKéMON avec un signal spécial!\p"
    .string "Tu es le seul à qui je puisse\n"
    .string "faire appel.\p"
    .string "Sauve la TOUR RADIO, je t'en\n"
    .string "prie…\p"
    .string "Et tous les POKéMON du pays!$"
