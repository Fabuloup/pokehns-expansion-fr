Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "Maison de M. POKéMON$"

Route30_Text_UseTackle:
	.string "Allez, RATTATA!\p"
	.string "CHARGE!$"

Route30_Text_ThisIsABigBattle:
	.string "Quoi? C'est un grand combat!\n"
	.string "Laisse-moi tranquille!$"

Route30_Text_YoungsterJoey1Seen:
	.string "Je viens de perdre. Je cherche\n"
	.string "d'autres POKéMON.\p"
	.string "Attends! Tu as l'air faible!\n"
	.string "Allez, combattons!$"

Route30_Text_YoungsterJoey1Beaten:
	.string "Argh! J'ai encore perdu!\n"
	.string "Zut alors!$"

Route30_Text_YoungsterJoey1After:
	.string "Me faut-il plus de POKéMON pour\n"
	.string "mieux combattre?\p"
	.string "Non! Je resterai avec celui-ci,\n"
	.string "quoi qu'il arrive!$"

Route30_Text_YoungsterMikeySeen:
	.string "Tu es Dresseur de POKéMON,\n"
	.string "pas vrai?\p"
	.string "Alors, on doit se battre!$"

Route30_Text_YoungsterMikeyBeaten:
	.string "C'est bizarre.\n"
	.string "J'avais gagné avant.$"

Route30_Text_YoungsterMikeyAfter:
	.string "Devenir un bon Dresseur,\n"
	.string "c'est vraiment difficile.\p"
	.string "Je vais affronter d'autres gens\n"
	.string "pour m'améliorer.$"

Route30_Text_BugCatcherDonSeen:
	.string "Au lieu d'un POKéMON Insecte,\n"
	.string "j'ai trouvé un Dresseur!$"

Route30_Text_BugCatcherDonBeaten:
	.string "Argh! Tu es trop fort!$"

Route30_Text_BugCatcherDonAfter:
	.string "J'ai utilisé ma dernière POKé BALL\n"
	.string "en attrapant des POKéMON.\p"
	.string "J'aurais dû en acheter plus…$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "La maison de M. POKéMON?\n"
	.string "C'est un peu plus loin.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "Tout le monde s'amuse à combattre!\p"
	.string "Tu devrais essayer!$"

Route30_Text_CooltrainerF:
	.string "Je ne suis pas Dresseuse.\p"
	.string "Mais si tu croises le regard d'un\n"
	.string "Dresseur, prépare-toi à combattre.$"

Route30_Text_Sign:
	.string "ROUTE 30\p"
	.string "MAUVILLE - VILLE GRIOTTE$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "MAISON DE M. POKéMON\n"
	.string "TOUT DROIT!$"

Route30_Text_MrPokemonsHouseSign:
	.string "MAISON DE M. POKéMON$"

Route30_Text_TrainerTips:
	.string "ASTUCE\p"
	.string "On ne vole pas les POKéMON\n"
	.string "des autres!\p"
	.string "Les POKé BALLS ne se lancent\n"
	.string "que sur les POKéMON sauvages!$"

Route30_Text_JoeyRegister:
	.string "Tu te débrouilles bien!\p"
	.string "Mon RATTATA est toujours prêt\n"
	.string "à se battre.\p"
	.string "C'est mon seul POKéMON. Avec lui,\n"
	.string "je deviendrai un grand Dresseur!\p"
	.string "On se combattra encore un jour!$"

Route30_Text_JoeyRematchIntro:
	.string "Cette fois, ce sera différent!\n"
	.string "Combattons!$"

Route30_Text_JoeyRematchDefeat:
	.string "Argh! J'ai encore perdu!\n"
	.string "Zut alors!$"

Route30_Text_JoeyPostRematch:
	.string "J'étudie les capacités de mon\n"
	.string "RATTATA et j'élabore\l"
	.string "quelques stratégies.\p"
	.string "Dès que j'en trouve une bonne,\n"
	.string "on se bat!$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "J'ai encore perdu…\n"
	.string "Tu es vraiment fort!\p"
	.string "Ah oui, j'allais oublier.\n"
	.string "Je dois te donner ceci.\p"
	.string "Utilise-le pour devenir encore\n"
	.string "plus fort, d'accord?\p"
	.string "Moi aussi, je vais progresser.$"

Route30_Text_ElmName:
	.string "PROF. ORME$"

Route30_Text_Elm_Disaster:
	.string "PROF. ORME: A-allô? {PLAYER}?\n"
	.string "C'est une catastrophe!\p"
	.string "Euh… C'est affreux!\p"
	.string "Que dois-je faire? C'est…\n"
	.string "Oh non…\p"
	.string "Reviens ici tout de suite!$"


Route30_Text_Poliwag:
	.string "PTITARD: Ptitard!$"
