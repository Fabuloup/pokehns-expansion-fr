Gate_Route31_VioletCity_hns_MapScripts::
	.byte 0

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "Salut! As-tu visité la\n"
	.string "TOUR CHÉTIFLOR?$"

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "J'ai vu un adorable POKéMON\n"
	.string "par là.\p"
	.string "Il ressemblait beaucoup à PIKACHU!$"
