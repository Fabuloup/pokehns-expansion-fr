RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "QUAGSIRE: Quag Quag$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "Hm? C'est un POKéDEX, n'est-ce\n"
	.string "pas? Puis-je le voir?\p"
	.string "Il y a tant d'espèces de\n"
	.string "POKéMON.\p"
	.string "Hmm? C'est quoi?\p"
	.string "Quel est donc ce POKéMON?\p"
	.string "Il ressemble aux étranges\n"
	.string "inscriptions sur les murs des\p"
	.string "RUINES.\p"
	.string "Si ces dessins sont bien des\n"
	.string "POKéMON, il doit y en avoir\n"
	.string "beaucoup d'autres.\p"
	.string "Je sais! Je vais améliorer ton\n"
	.string "POKéDEX. Suis-moi.$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "Que veux-tu? J'étudie, là,\n"
	.string "ne me dérange pas!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Pardon…\n"
	.string "Notre manque de vraie\p"
	.string "compréhension me désespère…$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "Les RUINES sont vieilles\n"
	.string "d'environ 1500 ans.\p"
	.string "Personne ne sait qui les a\n"
	.string "construites.\p"
	.string "On ne sait pas non plus si les\n"
	.string "statues de POKéMON ont un sens.\p"
	.string "Tout cela est un grand mystère…$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "Hmmm… C'est bizarre, ici.$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "J'aime réfléchir ici.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "PIERRE MYSTÈRE\n"
	.string "CHAMBRE du PANNEAU$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINES D'ALPHA\n"
	.string "Bienvenue aux visiteurs$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "RUINS OF ALPH RESEARCH CENTER\p"
	.string "THE AUTHORITY ON THE\n"
	.string "RUINS OF ALPH$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "While exploring the RUINS, we\n"
	.string "suddenly noticed an odd presence.\p"
	.string "We all got scared and ran away.\n"
	.string "You should be careful too.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "The RUINS hide a huge secret!\p"
	.string "…I think…$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "There are many kinds of UNOWN, so\n"
	.string "we use them for our secret codes.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A… H… E… A… D… Hmm…\p"
	.string "What?\p"
	.string "I'm decoding this message!$"
