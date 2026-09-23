GoldenrodCity_DepartmentStore_7F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT_HNS
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F_HNS
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROOF_NERD
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
    .string "Ouf, je suis fatiguée.\p"
    .string "Je monte parfois sur le toit pour\n"
    .string "souffler entre deux boutiques.$"

GoldenrodDeptStore_Text_RoofFisher:
    .string "Pardon? Qui a dit qu'un adulte\n"
    .string "ne pouvait pas y jouer?\p"
    .string "Je reviendrai tous les jours\n"
    .string "collectionner toutes les poupées!$"

GoldenrodDeptStore_Text_RoofTwin:
    .string "Il y a des soldes ici de temps\n"
    .string "en temps.$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
    .string "Oh, ouah!$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
    .string "Tu veux bien arrêter de m'embêter?$"

GoldenrodDeptStore_Text_RoofPokefanM:
    .string "Il y a un truc que je veux\n"
    .string "vraiment, mais je n'ai pas assez\l"
    .string "d'argent…\p"
    .string "Je vais peut-être vendre les\n"
    .string "BAIES que j'ai ramassées…$"

GoldenrodDeptStore_Text_RoofTeacher:
    .string "Oh, tout est si bon marché!\p"
    .string "J'ai tellement acheté que mon SAC\n"
    .string "est plein à craquer!$"

GoldenrodDeptStore_Text_RoofBugCatcher:
    .string "Mes POKéMON sont toujours\n"
    .string "paralysés ou empoisonnés au pire\l"
    .string "moment…\p"
    .string "Alors je viens acheter des\n"
    .string "TOTAL SOIN.\p"
    .string "J'espère qu'il en reste?$"
