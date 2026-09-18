OlivineCity_House2_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "Sur la route d'IRISIA, il y a\n"
	.string "quatre îles désertes.\p"
	.string "On y emmène les enfants pas\n"
	.string "sages, en punition!$"

OlivineCity_Text_PunishmentBoy:
	.string "Dès que je fais une bêtise, mon\n"
	.string "grand frère me fait peur.$"
