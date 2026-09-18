Route33_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY_HNS, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_RegisterAnthony
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_RematchAnthony
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_RegisterAnthony::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route33_Text_AnthonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY_HNS
	release
	end

Route33_EventScript_RematchAnthony::
	trainerbattle_rematch TRAINER_ANTHONY_HNS, Route33_Text_AnthonyRematchIntro, Route33_Text_AnthonyRematchDefeat
	msgbox Route33_Text_AnthonyPostRematch, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "J'ai traversé le tunnel, mais\n"
	.string "il me reste encore pas mal\l"
	.string "d'énergie.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Whoa! Alors toi, t'es plus\n"
	.string "speed que moi!$"

Route33_Text_HikerAnthony2After:
	.string "Nous, MONTAGNARDS, sommes à\n"
	.string "l'aise dans la montagne.$"

Route33_Text_AnthonyRegister:
	.string "Nous, MONTAGNARDS, sommes à\n"
	.string "l'aise dans la montagne.$"

Route33_Text_AnthonyRematchIntro:
	.string "J'ai traversé le tunnel, mais\n"
	.string "il me reste encore pas mal\l"
	.string "d'énergie.$"

Route33_Text_AnthonyRematchDefeat:
	.string "Whoa! Alors toi, t'es plus\n"
	.string "speed que moi!$"

Route33_Text_AnthonyPostRematch:
	.string "Nous, MONTAGNARDS, sommes à\n"
	.string "l'aise dans la montagne.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hé! As-tu chopé un INSOLOURDO?\p"
	.string "Moi ouais, j'en ai un.\p"
	.string "Regarde-le bien à la lumière.\n"
	.string "Il a une drôle de bouille!$"

Route33_Text_Lass:
	.string "Pfff… Pff…\p"
	.string "Cette caverne était bien plus\n"
	.string "grande que je ne croyais.\p"
	.string "Chercher des MARILL m'a trop\n"
	.string "crevée, alors je suis sortie.$"
