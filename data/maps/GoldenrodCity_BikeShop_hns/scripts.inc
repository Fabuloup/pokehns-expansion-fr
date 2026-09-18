GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "Rouler à VÉLO est aussi simple\n"
	.string "qu'appuyer sur un bouton si tu\l"
	.string "l'ENREGISTRES depuis le SAC.\p"
	.string "Pour aller plus vite, il faut\n"
	.string "d'abord t'arrêter!\p"
	.string "Ça peut sembler curieux, mais on\n"
	.string "ne change de vitesse qu'à\l"
	.string "l'arrêt.\p"
	.string "Appuie sur R à l'arrêt et, au\n"
	.string "prochain coup de pédale, tu\l"
	.string "iras bien plus vite!$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "…soupir… J'ai déménagé ici, mais\n"
    .string "je n'arrive pas à vendre mes\l"
    .string "BICYCLETTES. Pourquoi donc?\p"
    .string "Tu voudrais rouler à BICYCLETTE\n"
    .string "pour me faire de la publicité?$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "Vraiment? Génial!\p"
    .string "Donne-moi ton nom et ton numéro,\n"
    .string "et je te prête une BICYCLETTE.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER} emprunte une BICYCLETTE.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "Les affaires sont dures depuis\n"
	.string "notre déménagement de KANTO.\l"
	.string "Merci de ton aide!\p"
	.string "Tu peux bien mettre en avant\n"
	.string "notre technologie brevetée de\l"
	.string "changement de vitesse?\p"
	.string "Il suffit d'appuyer sur R quand\n"
	.string "tu es à l'arrêt sur ton VÉLO.\p"
	.string "Attention! Tu iras plus vite!$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "…soupir… Où est donc passée la\n"
    .string "gentillesse des gens…$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "Nouveauté!\p"
    .string "BICYCLETTES pliantes de premier\n"
    .string "choix!$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "Une BICYCLETTE toute neuve!$"
