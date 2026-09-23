GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "Je perds tout le temps et mes\n"
    .string "POKéMON finissent K.O.…\p"
    .string "C'est peut-être pour ça qu'ils\n"
    .string "ne m'aiment pas beaucoup…$"

GoldenrodHappinessRater_Text_Twin:
    .string "Quand j'utilise un objet sur mon\n"
    .string "POKéMON, il a l'air trop content!$"
