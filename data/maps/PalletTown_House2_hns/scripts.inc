PalletTown_House2_hns_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "NINA: Salut! Mon petit frère\n"
	.string "est le CHAMPION de l'ARÈNE de\l"
	.string "JADIELLE.\p"
	.string "Mais il s'absente si souvent\n"
	.string "que ça pose problème aux\l"
	.string "DRESSEURS.$"

PalletTown_House2_Text_OfferGrooming:
	.string "NINA: Salut! Tu tombes bien.\n"
	.string "J'allais prendre le thé.\p"
	.string "Tu te joins à moi?\p"
	.string "Oh, tes POKéMON sont un peu\n"
	.string "sales.\p"
	.string "Tu veux que j'en bichonne un?$"

PalletTown_House2_Text_WhichMon:
	.string "NINA: Lequel dois-je bichonner?$"

PalletTown_House2_Text_Alright:
	.string "NINA: D'accord, il sera\n"
	.string "resplendissant en un clin d'œil.$"

PalletTown_House2_Text_AllDone:
	.string "NINA: Et voilà! C'est fini.\p"
	.string "Tu vois? {STR_VAR_1} est beau,\n"
	.string "non?\p"
	.string "C'est un POKéMON si mignon.$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "NINA: Je prends toujours le thé\n"
	.string "à cette heure-ci. Joins-toi à\l"
	.string "moi.$"

PalletTown_House2_Text_Refused:
	.string "NINA: Tu ne veux pas que j'en\n"
	.string "bichonne un?\p"
	.string "Bon, prenons juste le thé.$"

PalletTown_House2_Text_CantGroomEgg:
	.string "NINA: Oh, désolée. Je ne peux\n"
	.string "vraiment pas bichonner un ŒUF.$"
