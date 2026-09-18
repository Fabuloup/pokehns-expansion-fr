SSAqua_RoomSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE_HNS, SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE_HNS, SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "J'essaie d'oublier mes peines.\n"
    .string "Battons-nous!$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "Mon coeur pleure…$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "Rien de tel qu'un voyage pour\n"
    .string "guérir un coeur brisé.\p"
    .string "Mais la traversée en NAVIRE est\n"
    .string "trop courte pour faire son deuil.$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "Je vais faire auditionner mes\n"
    .string "chansons à la STATION RADIO de\l"
    .string "DOUBLONVILLE.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "Ouille! Distorsion totale!$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "J'allais faire mes débuts à la\n"
    .string "TOUR DE COMBAT…\p"
    .string "Je devrais retourner à CARMIN SUR\n"
    .string "MER et reprendre mon\l"
    .string "entraînement…$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "À propos de la STATION RADIO,\n"
    .string "c'est quoi le numéro chance de\l"
    .string "la semaine?$"
