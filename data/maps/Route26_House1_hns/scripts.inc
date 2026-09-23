Route26_House1_hns_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
    .string "Tes POKéMON ont l'air un peu\n"
    .string "fatigués.\p"
    .string "Tu devrais les laisser se\n"
    .string "reposer un moment.$"

Route26_Text_HealHouseKeepAtIt:
    .string "Voilà!\p"
    .string "Tes POKéMON ont belle allure!\p"
    .string "Continue comme ça!$"
