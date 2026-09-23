Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "L'eau est chaude ici.\n"
	.string "Je suis bien détendu.\p"
	.string "D'accord, je t'affronte!$"

Route41_Text_SwimmermCharlieBeaten:
	.string "Mince! Ma peau est toute fripée!$"

Route41_Text_SwimmermCharlieAfter:
	.string "C'est relaxant de flotter\n"
	.string "comme ça, non?$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "Je suis un peu fatigué.\n"
	.string "Si je gagne, prête-moi ce POKéMON.$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "Pff, pff…$"

Route41_Text_SwimmermGeorgeAfter:
	.string "IRISIA est encore si loin.\p"
	.string "Mais retourner jusqu'à\n"
	.string "Revenir à OLIVILLE est dur aussi.\p"
	.string "Que faire?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "Tu vois ces îles entourées\n"
	.string "de tourbillons?\p"
	.string "Elles cachent forcément un secret!$"

Route41_Text_SwimmermBerkeBeaten:
	.string "Quel est le secret de ta\n"
	.string "force?$"

Route41_Text_SwimmermBerkeAfter:
	.string "La nuit était sombre et orageuse…\p"
	.string "J'ai vu un POKéMON géant s'envoler\n"
	.string "depuis les îles.\p"
	.string "Ses ailes argentées semaient\n"
	.string "des plumes derrière lui.$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Les vagues sont violentes ici.\p"
	.string "Elles t'épuisent pendant\n"
	.string "que tu nages.$"

Route41_Text_SwimmermKirkBeaten:
	.string "Je suis épuisé!$"

Route41_Text_SwimmermKirkAfter:
	.string "Les courants m'empêchent\n"
	.string "d'atteindre cette île.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "Tu cherches les secrets\n"
	.string "des TOURB'ÎLES?$"

Route41_Text_SwimmermMathewBeaten:
	.string "Oh, quelle endurance!$"

Route41_Text_SwimmermMathewAfter:
	.string "Un secret sur les TOURB'ÎLES…\p"
	.string "Il y fait un noir total!$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Je vais aux TOURB'ÎLES.\p"
	.string "Je pars explorer avec des amis.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "C'est comme ça qu'on fait?$"

Route41_Text_SwimmerfKayleeAfter:
	.string "Un grand POKéMON vivrait tout\n"
	.string "au fond des TOURB'ÎLES.\p"
	.string "Je me demande lequel.$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Tu as tellement d'allure,\n"
	.string "sur ton POKéMON.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "Je suis anéantie…$"

Route41_Text_SwimmerfSusieAfter:
	.string "Il n'y avait pas une chanson sur\n"
	.string "un garçon chevauchant un LOKHLASS?$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "Le temps est si beau que\n"
	.string "j'en suis toute rêveuse!$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "Oooh!$"

Route41_Text_SwimmerfDeniseAfter:
	.string "Le soleil abîme ta peau.\p"
	.string "Mais je n'utilise pas de crème.\p"
	.string "Je refuse de polluer l'eau.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Si tu dois te reposer,\n"
	.string "fais juste la planche.\p"
	.string "Tu reprendras ton souffle,\n"
	.string "et tu repartiras de plus belle.$"

Route41_Text_SwimmerfKaraBeaten:
	.string "Oh! Tu as plus d'énergie que moi.$"

Route41_Text_SwimmerfKaraAfter:
	.string "J'ai entendu des rugissements au\n"
	.string "fond des ÎLES.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "La nuit, les STARI se rassemblent\n"
	.string "près de la surface.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "Oh là là…$"

Route41_Text_SwimmerfWendyAfter:
	.string "Les groupes de STARI s'illuminent\n"
	.string "en même temps.\p"
	.string "C'est si beau que ça fait peur.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "TENTACRUEL: Cruooo…$"

Route41_Text_TentacruelAttack:
	.string "TENTACRUEL: CRUOOOOOO!$"

Route41_Text_TentacruelHeal:
	.string "TENTACRUEL utilise SOIN!\n"
	.string "Il récupère toute son énergie!$"
