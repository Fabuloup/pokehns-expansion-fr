BattleFrontier_OutsideEast_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition_hns
	.byte 0

BattleFrontier_OutsideEast_OnResume_hns:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker_hns::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac_hns::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1_hns::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin_hns::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM_hns::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo_hns::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo_hns::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1_hns::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl_hns::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM_hns::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2_hns::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2_hns::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hns::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper_hns::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign_hns:
	.string "TOUR DE COMBAT\n"
	.string "Enchaînez les\l"
	.string "victoires!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns:
	.string "PALACE DE COMBAT Gardez\n"
	.string "un œil sur vos POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign_hns:
	.string "DOJO DE COMBAT Que les\n"
	.string "équipes se forment!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns:
	.string "PYRAMIDE DE COMBAT Découvrez\n"
	.string "l'aventure du COMBAT QUETE!$"

BattleFrontier_OutsideEast_Text_RankingHallSign_hns:
	.string "HALL DE CLASSEMENT Jetez un\n"
	.string "œil aux records des meilleurs!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns:
	.string "SERVICE D'ECHANGE Echangez\n"
	.string "vos POINTS DE COMBAT!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns:
	.string "Waouh! C'est immense!\n"
	.string "La TOUR DE COMBAT est\p"
	.string "un endroit unique. Il ne\n"
	.string "ressemble à aucun autre.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns:
	.string "Ma grande ambition est de\n"
	.string "conquérir la ZONE DE COMBAT\l"
	.string "et la LIGUE POKéMON. Si\p"
	.string "mon rêve se réalise… Je\p"
	.string "demanderai à MIMI si elle\n"
	.string "veut bien être mon amie!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns:
	.string "La PYRAMIDE DE COMBAT est trop\n"
	.string "rude! Je n'arrive pas au sommet!\p"
	.string "Je n'ai plus le choix… Je vais\n"
	.string "tenter de l'escalader dehors.$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns:
	.string "Je m'épanouis dans l'obscurité…\n"
	.string "Oui… Ce qui compte à mes yeux?\l"
	.string "La PYRAMIDE DE COMBAT… J'aime me\p"
	.string "promener dans l'obscurité la plus\n"
	.string "totale, au bord du désespoir.$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns:
	.string "J'ai veillé toute la semaine,\n"
	.string "mais j'ai formé l'équipe ultime!\p"
	.string "Je ne me vois vraiment pas perdre.\n"
	.string "Direction le DOJO DE COMBAT!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns:
	.string "Tu es ici grâce à SCOTT? Il\n"
	.string "est bizarre, quand même, non?\p"
	.string "Il est très fort pour repérer\n"
	.string "les DRESSEURS qui ont du\p"
	.string "talent, oui… Mais je ne l'ai\n"
	.string "absolument jamais vu se battre.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns:
	.string "ZIGG! Je crois en toi,\n"
	.string "mon bébé! Je te préparerai\p"
	.string "tout ce que tu voudras si\n"
	.string "tu gagnes, mon petit ZIGG!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns:
	.string "ZIGZATON a l'air absent…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns:
	.string "On me traite de fouineur,\n"
	.string "mais je n'y peux rien.\p"
	.string "Ton chapeau est de travers!\n"
	.string "Oh, un déchet par terre!\l"
	.string "Mince, c'est bientôt le dîner!\p"
	.string "Je ne sais pas si je pourrai me\n"
	.string "contenter d'observer au PALACE…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns:
	.string "Je n'en ai peut-être pas l'air,\n"
	.string "mais j'ai battu un CHAMPION.\p"
	.string "Qui sait? Je devrais peut-être\n"
	.string "chercher à nouveau la gloire.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns:
	.string "Sur mon VELO, je suis\n"
	.string "rapide. Aux combats\p"
	.string "aussi! Je gagne mes\n"
	.string "combats en un clin d'œil!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns:
	.string "Je suis plus forte que\n"
	.string "mon père aux POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns:
	.string "Allez, mon bébé! Va gagner\n"
	.string "pour papa! Tu ressembles\p"
	.string "à ta mère, tu vas les\n"
	.string "mener par le bout du nez!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns:
	.string "Je viens de très loin,\n"
	.string "j'avais entendu dire qu'il\l"
	.string "y avait une jolie fille\p"
	.string "au DOJO DE COMBAT. Tu\n"
	.string "sais ce que j'ai trouvé\p"
	.string "à la place? Un ramassis\n"
	.string "de fanas d'arts martiaux!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns:
	.string "Des fois, je vois un vieil homme\n"
	.string "à l'air très important qui entre\p"
	.string "ici. Il a des POKéMON magnifiques.\n"
	.string "Il a l'air très gentil.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns:
	.string "Tu la connais, la légende\n"
	.string "de la PYRAMIDE DE COMBAT?\p"
	.string "Quand un DRESSEUR sûr de lui\n"
	.string "atteindra le sommet doré, un\l"
	.string "homme apparaîtra parmi les\p"
	.string "hommes. Tu ne connais pas\n"
	.string "cette légende? Pas étonnant,\l"
	.string "je viens de l'inventer! Il\p"
	.string "y a un sens caché, tu sais.\n"
	.string "Désolé, motus et bouche cousue!$"

BattleFrontier_OutsideEast_Text_GotWipedOut_hns:
	.string "Mince, alors! C'est la\n"
	.string "première fois que je perds!\p"
	.string "Je me suis fait écraser\n"
	.string "comme un moucheron! Et en\p"
	.string "plus, on vient me dire que\n"
	.string "je n'ai aucun talent! Mince…$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns:
	.string "Cet homme a dû se battre\n"
	.string "contre un DRESSEUR horriblement\l"
	.string "fort à la TOUR DE COMBAT. Et\p"
	.string "maintenant, regarde-le… Si tu\p"
	.string "décides d'aller à la TOUR DE\n"
	.string "COMBAT, fais bien attention.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns:
	.string "Chouette! J'ai enfin assez\n"
	.string "de POINTS DE COMBAT! Je pense\p"
	.string "que je vais les échanger\n"
	.string "contre une autre POUPEE!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns:
	.string "Ah oui, d'accord!\n"
	.string "Voilà le HALL DU CLASSEMENT!\p"
	.string "J'aimerais entrer dans l'histoire\n"
	.string "comme grand champion et laisser\l"
	.string "mon nom ici pour la postérité.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns:
	.string "Avec toi, rien n'est impossible.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns:
	.string "Oh, mon chéri! Tu es formidable!\p"
	.string "Je ne veux plus attendre! Allons\p"
	.string "vite dans une SALLE DE COMBAT\n"
	.string "MULTI! Si nous allons dans\p"
	.string "le SALON DE COMBAT ensemble,\n"
	.string "ils vont tous trembler devant\l"
	.string "la force de notre amour. Ils\p"
	.string "vont tous s'effondrer comme\n"
	.string "des dominos devant nous!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns:
	.string "La ZONE DE COMBAT n'est pas\n"
	.string "réservée qu'aux bons DRESSEURS.\p"
	.string "Il paraît que des gens ayant\n"
	.string "d'autres aptitudes ont été invités\p"
	.string "aussi. Ce SCOTT… Peut-être qu'il\p"
	.string "avait une idée derrière la tête\n"
	.string "en construisant cet endroit…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns:
	.string "Pardon, petit. As-tu\n"
	.string "une bonne vue? Il y a un\p"
	.string "arbre bizarre là-bas. J'ai\n"
	.string "l'impression qu'il bouge.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns:
	.string "Pardon, petit. As-tu une\n"
	.string "bonne mémoire? Il me semble\p"
	.string "qu'il y avait un arbre\n"
	.string "bizarre là-bas, avant.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns:
	.string "… Je l'ai vu! J'ai vu un\n"
	.string "POKéMON du genre gluant\p"
	.string "avec une longue queue!\n"
	.string "Il se cachait derrière\p"
	.string "un rocher et n'arrêtait\n"
	.string "pas de me regarder!$"
