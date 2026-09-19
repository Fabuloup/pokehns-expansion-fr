BattleFrontier_Lounge2_hns_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice_hns::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews_hns
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews_hns::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle_hns::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble_hns::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns::
	.string "Bonjour! Si tu veux des infos\n"
	.string "sur la ZONE DE COMBAT, tu es\p"
	.string "au bon endroit. Je suis en\n"
	.string "quelque sorte le MORDU DE LA\p"
	.string "ZONE! Toi, tu es un DRESSEUR,\n"
	.string "n'est-ce pas? Je serais ravi\p"
	.string "de partager mes infos sur\n"
	.string "la ZONE DE COMBAT avec toi.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns::
	.string "Bonjour! Je parierais que tu es\n"
	.string "là pour me faire parler un peu!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight_hns::
	.string "Alors? Alors? Alors?\p"
	.string "Mes informations vous ont été\n"
	.string "très utiles, n'est-ce pas?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest_hns::
	.string "Voyons voir…\p"
	.string "Il paraît que {STR_VAR_1}\n"
	.string "est l'endroit le plus en vue.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns::
	.string "Voyons voir…\p"
	.string "Il paraît que la TOUR DE COMBAT\n"
	.string "{STR_VAR_1} est très en vue.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere_hns::
	.string "Vous ne le saviez sûrement pas!\p"
	.string "Un CERVEAU DE LA ZONE choisi par\n"
	.string "SCOTT se trouve justement ici.\p"
	.string "Une mystérieuse DRESSEUSE nommée\n"
	.string "l'AS DU SALON dirige les lieux.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons_hns::
	.string "As-tu affronté l'AS DU SALON?\p"
	.string "Pour évaluer son adversaire, elle\n"
	.string "utilise apparemment ces POKéMON:\p"
	.string "Un POKéMON SOLEIL de type PSY,\n"
	.string "un POKéMON VOLCAN de type FEU,\l"
	.string "et un POKéMON PIONCEUR NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons_hns::
	.string "As-tu affronté l'AS DU SALON quand\n"
	.string "elle est sérieuse? Quand elle\p"
	.string "se bat à fond, elle utilise les\n"
	.string "POKéMON suivants: Un POKéMON EON\p"
	.string "de type DRAGON/PSY, un POKéMON\n"
	.string "FOUDRE de type ÉLECTRIK et un\l"
	.string "POKéMON PIONCEUR de type NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere_hns::
	.string "Je vais t'apprendre quelque\p"
	.string "chose! Un des DRESSEURS que SCOTT\n"
	.string "appelle CERVEAUX DE LA ZONE est\p"
	.string "ici. C'est l'extravagant DRESSEUR\n"
	.string "surnommé l'AS DU DÔME.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons_hns::
	.string "As-tu affronté l'AS DU DÔME?\p"
	.string "Quand il ménage son adversaire,\n"
	.string "il utilise ces trois POKéMON:\p"
	.string "Un POKéMON DRAGON DRAGON/VOL,\n"
	.string "un POKéMON POISSONBOUE EAU/SOL,\l"
	.string "et un POKéMON FLAMME FEU/VOL.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons_hns::
	.string "As-tu affronté l'AS DU DÔME\n"
	.string "quand il se bat sérieusement?\p"
	.string "Quand il veut faire preuve de\n"
	.string "stratégie, il utilise ces trois\p"
	.string "POKéMON: Un POKéMON EON de type\n"
	.string "DRAGON/PSY, un POKéMON POISSONBOUE\l"
	.string "de type EAU/SOL et un POKéMON\l"
	.string "PATTEFER de type ACIER/PSY.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere_hns::
	.string "Je vais t'apprendre quelque\p"
	.string "chose! Un des DRESSEURS que SCOTT\n"
	.string "appelle CERVEAUX DE LA ZONE est\p"
	.string "ici. C'est l'étrange DRESSEUR\n"
	.string "surnommé CHEF USINE.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons_hns::
	.string "As-tu déjà affronté le CHEF\n"
	.string "USINE? Tu sais… Au combat,\p"
	.string "il doit utiliser trois\n"
	.string "POKéMON de location. Il se\p"
	.string "bat dans les mêmes conditions\n"
	.string "que les autres, en fait.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons_hns::
	.string "As-tu affronté le CHEF USINE\n"
	.string "quand il se bat sérieusement?\p"
	.string "Même à fond, il reçoit toujours\n"
	.string "trois POKéMON de location.\p"
	.string "Il combat presque dans les mêmes\n"
	.string "conditions que toi.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere_hns::
	.string "Je vais t'apprendre quelque\p"
	.string "chose! Un des DRESSEURS que SCOTT\n"
	.string "appelle CERVEAUX DE LA ZONE est\p"
	.string "ici. C'est la terrifiante\n"
	.string "DRESSEUSE surnommée REINE PIKE.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons_hns::
	.string "Tu as déjà affronté la REINE\n"
	.string "PIKE? Quand elle est de\p"
	.string "bonne humeur, elle utilise ces\n"
	.string "POKéMON: Un POKéMON SERPACROC\p"
	.string "de type POISON, un POKéMON\n"
	.string "POURRI de type INSECTE/ROCHE et\l"
	.string "un POKéMON TENDRE de type EAU.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons_hns::
	.string "Tu as déjà affronté la REINE\n"
	.string "PIKE quand elle est énervée?\p"
	.string "Quand elle est vraiment agressive,\n"
	.string "elle utilise ces trois POKéMON:\p"
	.string "Un POKéMON SERPACROC de type\n"
	.string "POISON, Un POKéMON SERPENFER\l"
	.string "de type ACIER/SOL et un POKéMON\l"
	.string "TERRIFIANT de type EAU/VOL.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere_hns::
	.string "Je vais t'apprendre quelque\p"
	.string "chose! Un des DRESSEURS que SCOTT\n"
	.string "appelle CERVEAUX DE LA ZONE est\p"
	.string "ici. C'est la redoutable DRESSEUSE\n"
	.string "surnommée MAGNAT ARÈNE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons_hns::
	.string "As-tu déjà affronté le MAGNAT\n"
	.string "ARÈNE?\p"
	.string "Pour évaluer le talent adverse,\n"
	.string "elle utiliserait ces POKéMON:\p"
	.string "Un UNICORNE INSECTE/COMBAT,\n"
	.string "un POKéMON LUNE TÉNÈBRES,\l"
	.string "et un MUE INSECTE/SPECTRE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons_hns::
	.string "As-tu déjà affronté le MAGNAT\n"
	.string "ARÈNE? Si elle ne veut laisser\p"
	.string "aucune chance à l'adversaire,\n"
	.string "elle utilise ces POKéMON: Un\p"
	.string "POKéMON LUNE de type TÉNÈBRES,\n"
	.string "un POKéMON OMBRE de type\l"
	.string "SPECTRE/POISON et un POKéMON\l"
	.string "CHAMPIGNON de type PLANTE/COMBAT.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere_hns::
	.string "Je vais t'apprendre quelque\p"
	.string "chose! Un des DRESSEURS que SCOTT\n"
	.string "appelle CERVEAUX DE LA ZONE est\p"
	.string "ici. C'est le sinistre DRESSEUR\n"
	.string "surnommé GUIDE PALAIS.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons_hns::
	.string "As-tu déjà affronté le GUIDE\n"
	.string "PALAIS?\p"
	.string "Pour tester l'esprit adverse, on\n"
	.string "dit qu'il utilise ces POKéMON:\p"
	.string "Un CHOVSOURIS POISON/VOL,\n"
	.string "un FAINÉANT NORMAL et un\l"
	.string "POKéMON TRANSPORT EAU/GLACE.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons_hns::
	.string "Tu as déjà combattu le\n"
	.string "GUIDE PALAIS? Quand il se\p"
	.string "bat à fond, il utilise ces\n"
	.string "POKéMON: Un POKéMON LÉGENDAIRE\p"
	.string "de type FEU, un POKéMON\n"
	.string "FAINÉANT de type NORMAL et un\l"
	.string "POKéMON AURORE de type EAU.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere_hns::
	.string "Je vais t'apprendre quelque\p"
	.string "chose! Un des DRESSEURS que SCOTT\n"
	.string "appelle CERVEAUX DE LA ZONE est\p"
	.string "ici. C'est l'intrépide DRESSEUR\n"
	.string "surnommé ROI PYRAMIDE.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons_hns::
	.string "As-tu déjà affronté le ROI\n"
	.string "PYRAMIDE? Quand il veut évaluer\p"
	.string "l'adversaire, il utilise ces\n"
	.string "POKéMON: Un POKéMON PIC ROCHEUX\p"
	.string "de type ROCHE, un POKéMON\n"
	.string "ICEBERG de type GLACE et un\l"
	.string "POKéMON FER de type ACIER.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons_hns::
	.string "As-tu déjà affronté le ROI\n"
	.string "PYRAMIDE quand il se bat pour\p"
	.string "de bon? Quand il est gonflé à\n"
	.string "bloc, il utilise ces POKéMON:\p"
	.string "Un POKéMON GLACIAIRE de type\n"
	.string "GLACE/VOL, un POKéMON ELECTRIQUE\l"
	.string "de type ÉLECTRIK/VOL et un\l"
	.string "POKéMON FLAMME de type FEU/VOL.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1_hns::
	.string "Oui, il y a plein d'endroits\n"
	.string "où faire des COMBATS DUO. Mais\p"
	.string "il vaut mieux commencer par\n"
	.string "les SALLES DE COMBAT DUO de la\p"
	.string "TOUR DE COMBAT! C'est là que tu\n"
	.string "apprendras ce qu'est un COMBAT\l"
	.string "DUO dans la ZONE DE COMBAT.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2_hns::
	.string "Fais bien attention à toi. Il\p"
	.string "paraît que certains DRESSEURS\n"
	.string "développent des stratégies\l"
	.string "spéciales pour les COMBATS DUO.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3_hns::
	.string "Quand tu y maîtriseras\n"
	.string "les COMBATS DUO,\l"
	.string "tu pourrais essayer\l"
	.string "d'en faire ailleurs.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice_hns::
	.string "Toutes sortes de DRESSEURS\n"
	.string "se trouvent dans le SALON\p"
	.string "DE COMBAT. Il se peut que tu\n"
	.string "rencontres des amis ou encore\l"
	.string "des fans! Ouvre les yeux!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice_hns::
	.string "Si tu es avec un ami, va dans la\n"
	.string "SALLE DE COMBAT MULTI LINK.\p"
	.string "Avec un partenaire puissant,\n"
	.string "tu affronteras de rudes rivaux!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower_hns::
	.string "Quelle capacité de synthèse!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns::
	.string "Quel talent d'observation!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns::
	.string "Quelle force de persuasion!\n"
	.string "Mon mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns::
	.string "C'est quoi, cet endroit?\n"
	.string "J'ai un peu peur…$"

