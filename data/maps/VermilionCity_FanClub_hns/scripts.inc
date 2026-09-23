VermilionCity_FanClub_hns_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "Je suis le PRÉSIDENT du FAN CLUB\n"
	.string "POKéMON.\p"
	.string "J'ai élevé plus de 150 POKéMON.\p"
	.string "Je suis exigeant en matière de\n"
	.string "POKéMON.\p"
	.string "Es-tu venu entendre parler de\n"
	.string "mon POKéMON ?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "Bien ! Alors écoute !\p"
	.string "Mon GALOPA préféré…\p"
	.string "Il est… mignon… adorable… malin…\n"
	.string "à en mourir…\l"
	.string "et puis… incroyable… oh… tu le\l"
	.string "penses aussi ?…\l"
	.string "Trop… sauvage… magnifique…\l"
	.string "gentil…\l"
	.string "je l'adore !\p"
	.string "Je le serre… quand… il dort… chaud\n"
	.string "et douillet…\l"
	.string "Oh, et… spectaculaire…\l"
	.string "ravissant… vraiment divin…\p"
	.string "Oups ! Regarde l'heure !\n"
	.string "Je t'ai retenu trop longtemps !$"

PokemonFanClub_Text_Chairman_Gift:
	.string "Merci de m'avoir écouté.\n"
	.string "Je veux que tu prennes ceci !$"

PokemonFanClub_Text_Chairman_Candy:
	.string "C'est un SUPER BONBON qui rend\n"
	.string "les POKéMON plus forts.\p"
	.string "Je préfère renforcer mes POKéMON\n"
	.string "en combattant, alors tu peux\l"
	.string "le garder.$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "Bonjour, {PLAYER} !\p"
	.string "Tu reviens entendre parler de mon\n"
	.string "POKéMON ?\p"
	.string "Non ? Oh… J'avais d'autres\n"
	.string "histoires à raconter…$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "Quelle déception…\p"
	.string "Reviens si tu veux écouter.$"

PokemonFanClub_Text_Receptionist:
	.string "Notre PRÉSIDENT est intarissable\n"
	.string "sur les POKéMON…$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "J'adore voir MÉLOFÉE agiter son\n"
	.string "doigt quand il essaie d'utiliser\l"
	.string "MÉTRONOME.\p"
	.string "C'est si adorable !$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "J'adore MÉLOFÉE, mais je n'ai\n"
	.string "jamais pu en attraper.\p"
	.string "Alors je me contente d'une\n"
	.string "POKéPOUPÉE que j'ai trouvée.$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "Oh, je vois. La fille qui a perdu\n"
	.string "cette POKéPOUPÉE est triste…\p"
	.string "OK. Peux-tu rapporter cette\n"
	.string "POKéPOUPÉE à la pauvre fillette ?\p"
	.string "Un jour, je me lierai avec un vrai\n"
	.string "MÉLOFÉE. Aucun souci !$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "Tu verras. Je me lierai d'amitié\n"
	.string "avec un vrai MÉLOFÉE.$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "Regarde mon adorable MACRONIUM !\p"
	.string "Sa feuille est vraiment adorable !$"

PokemonFanClub_Text_ClefairyDoll:
	.string "C'est un MÉLOFÉE ! Hein ?\p"
	.string "Ah, oui. C'est une POKéPOUPÉE\n"
	.string "MÉLOFÉE.$"

PokemonFanClub_Text_Bayleef:
	.string "MACRONIUM : Macrooo !$"

PokemonFanClub_Text_Listen:
	.string "Écoutons tous poliment les\n"
	.string "autres Dresseurs.$"

PokemonFanClub_Text_Bragging:
	.string "Si quelqu'un se vante, réponds-lui\n"
	.string "en te vantant aussi !$"
