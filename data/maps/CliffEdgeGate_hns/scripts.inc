CliffEdgeGate_hns_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "Tu savais? Il y a un PARC SAFARI\n"
	.string "juste à côté.\p"
	.string "C'est vraiment amusant!\n"
	.string "Tu y verras plein d'espèces de\l"
	.string "POKéMON, et tu peux tous les\l"
	.string "attraper!\p"
	.string "Aucune raison de ne pas y aller,\n"
	.string "non? C'est juste à côté.$"

CliffEdgeGate_Text_Expectations:
	.string "C'est bien que tout le monde\n"
	.string "l'attende avec impatience.\p"
	.string "Mais la dame de l'accueil en fait\n"
	.string "un peu trop…\p"
	.string "N'espère pas trop non plus!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "Tout est palpitant!\n"
	.string "Explorez pour trouver des POKéMON\l"
	.string "sauvages! Le PARC SAFARI du GARDE\l"
	.string "BAOBA est ouvert!$"

