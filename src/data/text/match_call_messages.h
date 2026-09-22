#if IS_HNS
// HnS rematch trainer check page text — currently unused (check page disabled).
// Rematch slot → HnS trainer mapping kept here for reference if re-enabled.
// REMATCH_ROSE         = Joey (Youngster, Route 30)
// REMATCH_ANDRES       = Wade (Bug Catcher, Route 31)
// REMATCH_DUSTY        = Ralph (Fisherman, Route 32)
// REMATCH_LOLA         = Liz (Picnicker, Route 32)
// REMATCH_RICKY        = Anthony (Hiker, Route 33)
// REMATCH_LILA_AND_ROY = Todd (Camper, Route 34)
// REMATCH_CRISTIN      = Gina (Picnicker, Route 34)
// REMATCH_BROOKE       = Irwin (Juggler, Route 35)
// REMATCH_WILTON       = Arnie (Bug Catcher, Route 35)
// REMATCH_VALERIE      = Alan (School Kid, Route 36)
// REMATCH_CINDY        = Dana (Lass, Route 38)
// REMATCH_THALIA       = Chad (School Kid, Route 38)
// REMATCH_JESSICA      = Derek (Pokefan, Route 39)
// REMATCH_WINSTON      = Tully (Fisherman, Route 42)
// REMATCH_STEVE        = Brent (Pokemaniac, Route 43)
// REMATCH_TONY         = Tiffany (Picnicker, Route 43)
// REMATCH_NOB          = Vance (Bird Keeper, Route 44)
// REMATCH_KOJI         = Wilton (Fisherman, Route 44)
// REMATCH_FERNANDO     = Kenji (Black Belt, Route 45)
// REMATCH_DALTON       = Parry (Hiker, Route 45)
// REMATCH_BERNIE       = Erin (Picnicker, Route 46)
// REMATCH_ETHAN        = Jack (School Kid, National Park)
// REMATCH_JOHN_AND_JAY = Beverly (Parasol Lady, National Park)
// REMATCH_JEFFREY      = Huey (Sailor, Lighthouse)
// REMATCH_CAMERON      = Gaven (Cooltrainer, Route 26)
// REMATCH_JACKI        = Beth (Cooltrainer, Route 26)
// REMATCH_WALTER       = Jose (Bird Keeper, Route 27)
// REMATCH_KAREN        = Reena (Cooltrainer, Route 27)
// Crystal phone text reference: pokecrystal/data/phone/text/<name>_caller.asm
#else
const u8 gText_MatchCallAromaLady_Rose_Strategy[] = _("Apaiser les esprits combatifs.");
const u8 gText_MatchCallAromaLady_Rose_Pokemon[] = _("Des POKéMON PLANTE parfumés.");
const u8 gText_MatchCallAromaLady_Rose_Intro1[] = _("Les arômes apaisants font du");
const u8 gText_MatchCallAromaLady_Rose_Intro2[] = _("bien au corps et à l'esprit.");

const u8 gText_MatchCallRuinManiac_Andres_Strategy[] = _("Je ne suis pas très doué.");
const u8 gText_MatchCallRuinManiac_Andres_Pokemon[] = _("Mes partenaires d'exploration.");
const u8 gText_MatchCallRuinManiac_Andres_Intro1[] = _("Je recherche des ruines et");
const u8 gText_MatchCallRuinManiac_Andres_Intro2[] = _("des reliques sous-marines.");

const u8 gText_MatchCallRuinManiac_Dusty_Strategy[] = _("Écraser par la puissance !");
const u8 gText_MatchCallRuinManiac_Dusty_Pokemon[] = _("De robustes POKéMON ROC.");
const u8 gText_MatchCallRuinManiac_Dusty_Intro1[] = _("En quête de savoir ancien,");
const u8 gText_MatchCallRuinManiac_Dusty_Intro2[] = _("je parcours le monde.");

const u8 gText_MatchCallTuber_Lola_Strategy[] = _("Je vais faire de mon mieux !");
const u8 gText_MatchCallTuber_Lola_Pokemon[] = _("Des POKéMON bons nageurs.");
const u8 gText_MatchCallTuber_Lola_Intro1[] = _("J'aimerais savoir nager");
const u8 gText_MatchCallTuber_Lola_Intro2[] = _("sans utiliser de bouée.");

const u8 gText_MatchCallTuber_Ricky_Strategy[] = _("Aucune idée. Je vais essayer.");
const u8 gText_MatchCallTuber_Ricky_Pokemon[] = _("Mes amis les POKéMON EAU.");
const u8 gText_MatchCallTuber_Ricky_Intro1[] = _("Ce n'est pas que je ne sais");
const u8 gText_MatchCallTuber_Ricky_Intro2[] = _("pas nager. J'aime ma bouée.");

const u8 gText_MatchCallSisAndBro_LilaAndRoy_Strategy[] = _("On se répartit les tâches.");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Pokemon[] = _("On aime les POKéMON amicaux.");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Intro1[] = _("Frère et sœur, on profite");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Intro2[] = _("ensemble de nos POKéMON.");

const u8 gText_MatchCallCooltrainer_Cristin_Strategy[] = _("Finir avec une capacité forte !");
const u8 gText_MatchCallCooltrainer_Cristin_Pokemon[] = _("Un mélange de types variés.");
const u8 gText_MatchCallCooltrainer_Cristin_Intro1[] = _("Je veux devenir la meilleure");
const u8 gText_MatchCallCooltrainer_Cristin_Intro2[] = _("DRESSEUSE !");

const u8 gText_MatchCallCooltrainer_Brooke_Strategy[] = _("Exploiter les faiblesses.");
const u8 gText_MatchCallCooltrainer_Brooke_Pokemon[] = _("L'équilibre est essentiel.");
const u8 gText_MatchCallCooltrainer_Brooke_Intro1[] = _("Mon but est de devenir");
const u8 gText_MatchCallCooltrainer_Brooke_Intro2[] = _("MAÎTRE POKéMON.");

const u8 gText_MatchCallCooltrainer_Wilton_Strategy[] = _("Déstabiliser l'adversaire.");
const u8 gText_MatchCallCooltrainer_Wilton_Pokemon[] = _("Le type n'a aucune importance.");
const u8 gText_MatchCallCooltrainer_Wilton_Intro1[] = _("Je suis le meilleur élève");
const u8 gText_MatchCallCooltrainer_Wilton_Intro2[] = _("de l'ÉCOLE DE DRESSEURS.");

const u8 gText_MatchCallHexManiac_Valerie_Strategy[] = _("Une lente et longue souffrance.");
const u8 gText_MatchCallHexManiac_Valerie_Pokemon[] = _("Effrayants la nuit.");
const u8 gText_MatchCallHexManiac_Valerie_Intro1[] = _("Je vois des choses que les");
const u8 gText_MatchCallHexManiac_Valerie_Intro2[] = _("autres ne voient pas…");

const u8 gText_MatchCallLady_Cindy_Strategy[] = _("Tout pour gagner.");
const u8 gText_MatchCallLady_Cindy_Pokemon[] = _("Un type magnifique !");
const u8 gText_MatchCallLady_Cindy_Intro1[] = _("Chez moi, j'ai une piscine");
const u8 gText_MatchCallLady_Cindy_Intro2[] = _("réservée à mes POKéMON.");

const u8 gText_MatchCallBeauty_Thalia_Strategy[] = _("Tu tomberas sous mon charme !");
const u8 gText_MatchCallBeauty_Thalia_Pokemon[] = _("Des POKéMON EAU matures.");
const u8 gText_MatchCallBeauty_Thalia_Intro1[] = _("Je rêve de faire le tour");
const u8 gText_MatchCallBeauty_Thalia_Intro2[] = _("du monde sur un paquebot.");

const u8 gText_MatchCallBeauty_Jessica_Strategy[] = _("Je vais t'égarer.");
const u8 gText_MatchCallBeauty_Jessica_Pokemon[] = _("Mignons, évidemment.");
const u8 gText_MatchCallBeauty_Jessica_Intro1[] = _("J'adore le PARC SAFARI.");
const u8 gText_MatchCallBeauty_Jessica_Intro2[] = _("J'y retourne toujours.");

const u8 gText_MatchCallRichBoy_Winston_Strategy[] = _("Une stratégie ? Pourquoi faire ?");
const u8 gText_MatchCallRichBoy_Winston_Pokemon[] = _("Il m'a coûté une fortune !");
const u8 gText_MatchCallRichBoy_Winston_Intro1[] = _("Comme je suis riche, je dors");
const u8 gText_MatchCallRichBoy_Winston_Intro2[] = _("dans un lit POKéMON sur mesure.");

const u8 gText_MatchCallPokeManiac_Steve_Strategy[] = _("Terrasser par la force.");
const u8 gText_MatchCallPokeManiac_Steve_Pokemon[] = _("J'ai mis la nuit à l'attraper.");
const u8 gText_MatchCallPokeManiac_Steve_Intro1[] = _("Les POKéMON grands, forts");
const u8 gText_MatchCallPokeManiac_Steve_Intro2[] = _("et musclés sont les meilleurs…");

const u8 gText_MatchCallSwimmer_Tony_Strategy[] = _("Fonce à toute vitesse !");
const u8 gText_MatchCallSwimmer_Tony_Pokemon[] = _("Un POKéMON EAU qui déménage !");
const u8 gText_MatchCallSwimmer_Tony_Intro1[] = _("Quand je ne peux pas nager,");
const u8 gText_MatchCallSwimmer_Tony_Intro2[] = _("je soulève de la fonte.");

const u8 gText_MatchCallBlackBelt_Nob_Strategy[] = _("Une pluie de coups !");
const u8 gText_MatchCallBlackBelt_Nob_Pokemon[] = _("Le type COMBAT.");
const u8 gText_MatchCallBlackBelt_Nob_Intro1[] = _("Sans vouloir me vanter, je");
const u8 gText_MatchCallBlackBelt_Nob_Intro2[] = _("brise dix tuiles d'un coup !");

const u8 gText_MatchCallBlackBelt_Koji_Strategy[] = _("Admire la force du karaté !");
const u8 gText_MatchCallBlackBelt_Koji_Pokemon[] = _("Mes partenaires d'entraînement !");
const u8 gText_MatchCallBlackBelt_Koji_Intro1[] = _("Réglons les problèmes du");
const u8 gText_MatchCallBlackBelt_Koji_Intro2[] = _("monde à mains nues !");

const u8 gText_MatchCallGuitarist_Fernando_Strategy[] = _("Du rock à couper le souffle !");
const u8 gText_MatchCallGuitarist_Fernando_Pokemon[] = _("Électricité et gros son !");
const u8 gText_MatchCallGuitarist_Fernando_Intro1[] = _("Mes compositions vont te");
const u8 gText_MatchCallGuitarist_Fernando_Intro2[] = _("donner un sacré choc !");

const u8 gText_MatchCallGuitarist_Dalton_Strategy[] = _("Je vais t'électriser !");
const u8 gText_MatchCallGuitarist_Dalton_Pokemon[] = _("Ils sont de type ÉLECTRIK !");
const u8 gText_MatchCallGuitarist_Dalton_Intro1[] = _("Je veux émouvoir les gens");
const u8 gText_MatchCallGuitarist_Dalton_Intro2[] = _("avec des chansons sincères.");

const u8 gText_MatchCallKindler_Bernie_Strategy[] = _("Tout réduire en cendres !");
const u8 gText_MatchCallKindler_Bernie_Pokemon[] = _("Des POKéMON qui brûlent tout.");
const u8 gText_MatchCallKindler_Bernie_Intro1[] = _("Quand tu allumes un feu,");
const u8 gText_MatchCallKindler_Bernie_Intro2[] = _("garde toujours de l'eau près.");

const u8 gText_MatchCallCamper_Ethan_Strategy[] = _("Tenir bon jusqu'au bout !");
const u8 gText_MatchCallCamper_Ethan_Pokemon[] = _("J'élève tous les POKéMON.");
const u8 gText_MatchCallCamper_Ethan_Intro1[] = _("Les POKéMON élevés en pleine");
const u8 gText_MatchCallCamper_Ethan_Intro2[] = _("nature deviennent forts !");

const u8 gText_MatchCallOldCouple_JohnAndJay_Strategy[] = _("Notre amour nous fait gagner.");
const u8 gText_MatchCallOldCouple_JohnAndJay_Pokemon[] = _("On les a depuis bien des années.");
const u8 gText_MatchCallOldCouple_JohnAndJay_Intro1[] = _("En cinquante ans de mariage,");
const u8 gText_MatchCallOldCouple_JohnAndJay_Intro2[] = _("on a choyé bien des POKéMON.");

const u8 gText_MatchCallBugManiac_Jeffrey_Strategy[] = _("Attaquer par vagues !");
const u8 gText_MatchCallBugManiac_Jeffrey_Pokemon[] = _("Les POKéMON INSECTE sont top.");
const u8 gText_MatchCallBugManiac_Jeffrey_Intro1[] = _("Chaque jour, je vais en forêt");
const u8 gText_MatchCallBugManiac_Jeffrey_Intro2[] = _("attraper des POKéMON INSECTE.");

const u8 gText_MatchCallPsychic_Cameron_Strategy[] = _("Étourdir et rendre confus !");
const u8 gText_MatchCallPsychic_Cameron_Pokemon[] = _("Ceux aux pouvoirs étranges.");
const u8 gText_MatchCallPsychic_Cameron_Intro1[] = _("Je vois parfaitement");
const u8 gText_MatchCallPsychic_Cameron_Intro2[] = _("ce que tu penses !");

const u8 gText_MatchCallPsychic_Jacki_Strategy[] = _("Combattre à pleine puissance.");
const u8 gText_MatchCallPsychic_Jacki_Pokemon[] = _("Des POKéMON pleins de mystères.");
const u8 gText_MatchCallPsychic_Jacki_Intro1[] = _("Quand nous avons parlé,");
const u8 gText_MatchCallPsychic_Jacki_Intro2[] = _("j'utilisais la télépathie.");

const u8 gText_MatchCallGentleman_Walter_Strategy[] = _("Calme et maîtrise.");
const u8 gText_MatchCallGentleman_Walter_Pokemon[] = _("Des POKéMON très distingués.");
const u8 gText_MatchCallGentleman_Walter_Intro1[] = _("Chaque jour, nous dégustons");
const u8 gText_MatchCallGentleman_Walter_Intro2[] = _("un thé d'importation.");

const u8 gText_MatchCallSchoolKid_Karen_Strategy[] = _("Je combats avec ma tête.");
const u8 gText_MatchCallSchoolKid_Karen_Pokemon[] = _("J'aime tous les POKéMON !");
const u8 gText_MatchCallSchoolKid_Karen_Intro1[] = _("Papa me donne de l'argent");
const u8 gText_MatchCallSchoolKid_Karen_Intro2[] = _("si j'ai une excellente note.");

const u8 gText_MatchCallSchoolKid_Jerry_Strategy[] = _("Mon savoir fait la loi !");
const u8 gText_MatchCallSchoolKid_Jerry_Pokemon[] = _("Tous les POKéMON malins !");
const u8 gText_MatchCallSchoolKid_Jerry_Intro1[] = _("Plus tard, je veux devenir");
const u8 gText_MatchCallSchoolKid_Jerry_Intro2[] = _("chercheur en POKéMON.");

const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Strategy[] = _("On en discute d'abord.");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Pokemon[] = _("Des POKéMON qu'on aime ensemble.");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Intro1[] = _("Aînée et cadette, nous sommes");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Intro2[] = _("deux élèves fans de POKéMON !");

const u8 gText_MatchCallPokefan_Isabel_Strategy[] = _("Allez-y, mes chéris !");
const u8 gText_MatchCallPokefan_Isabel_Pokemon[] = _("Je les aime tous sans exception.");
const u8 gText_MatchCallPokefan_Isabel_Intro1[] = _("Je combats même quand je fais");
const u8 gText_MatchCallPokefan_Isabel_Intro2[] = _("les courses pour le dîner.");

const u8 gText_MatchCallPokefan_Miguel_Strategy[] = _("Je combats avec amour !");
const u8 gText_MatchCallPokefan_Miguel_Pokemon[] = _("Un POKéMON élevé avec amour !");
const u8 gText_MatchCallPokefan_Miguel_Intro1[] = _("Il faut établir une relation");
const u8 gText_MatchCallPokefan_Miguel_Intro2[] = _("de confiance avec son POKéMON.");

const u8 gText_MatchCallExpert_Timothy_Strategy[] = _("Je devine tes capacités !");
const u8 gText_MatchCallExpert_Timothy_Pokemon[] = _("L'essence du type COMBAT.");
const u8 gText_MatchCallExpert_Timothy_Intro1[] = _("Je ne vais pas encore céder");
const u8 gText_MatchCallExpert_Timothy_Intro2[] = _("ma place aux jeunes !");

const u8 gText_MatchCallExpert_Shelby_Strategy[] = _("Attaquer tout en se défendant.");
const u8 gText_MatchCallExpert_Shelby_Pokemon[] = _("Le type COMBAT.");
const u8 gText_MatchCallExpert_Shelby_Intro1[] = _("Avec l'âge, j'ai développé");
const u8 gText_MatchCallExpert_Shelby_Intro2[] = _("mon propre style de combat.");

const u8 gText_MatchCallYoungster_Calvin_Strategy[] = _("Je fais ce que je peux.");
const u8 gText_MatchCallYoungster_Calvin_Pokemon[] = _("J'utilise plusieurs types.");
const u8 gText_MatchCallYoungster_Calvin_Intro1[] = _("Je m'entraînerai jusqu'à");
const u8 gText_MatchCallYoungster_Calvin_Intro2[] = _("battre un CHAMPION D'ARÈNE.");

const u8 gText_MatchCallFisherman_Elliot_Strategy[] = _("Je combats avec patience.");
const u8 gText_MatchCallFisherman_Elliot_Pokemon[] = _("Des POKéMON EAU au combat !");
const u8 gText_MatchCallFisherman_Elliot_Intro1[] = _("Je suis le seul au monde à");
const u8 gText_MatchCallFisherman_Elliot_Intro2[] = _("avoir pris un POKéMON énorme !");

const u8 gText_MatchCallTriathlete_Isaiah_Strategy[] = _("Exploiter le terrain !");
const u8 gText_MatchCallTriathlete_Isaiah_Pokemon[] = _("Vive le type EAU !");
const u8 gText_MatchCallTriathlete_Isaiah_Intro1[] = _("Je ne perdrai pas face à un");
const u8 gText_MatchCallTriathlete_Isaiah_Intro2[] = _("NAGEUR qui traîne sur la plage !");

const u8 gText_MatchCallTriathlete_Maria_Strategy[] = _("La vitesse avant tout !");
const u8 gText_MatchCallTriathlete_Maria_Pokemon[] = _("J'utilise un POKéMON rapide.");
const u8 gText_MatchCallTriathlete_Maria_Intro1[] = _("Un marathon, c'est un défi");
const u8 gText_MatchCallTriathlete_Maria_Intro2[] = _("contre soi-même.");

const u8 gText_MatchCallTriathlete_Abigail_Strategy[] = _("La Défense est essentielle.");
const u8 gText_MatchCallTriathlete_Abigail_Pokemon[] = _("Mon POKéMON est robuste.");
const u8 gText_MatchCallTriathlete_Abigail_Intro1[] = _("J'ai commencé pour maigrir,");
const u8 gText_MatchCallTriathlete_Abigail_Intro2[] = _("puis je me suis prise au jeu.");

const u8 gText_MatchCallTriathlete_Dylan_Strategy[] = _("Frapper avant d'être frappé !");
const u8 gText_MatchCallTriathlete_Dylan_Pokemon[] = _("Un POKéMON qui court vite !");
const u8 gText_MatchCallTriathlete_Dylan_Intro1[] = _("À force de courir, tu ne");
const u8 gText_MatchCallTriathlete_Dylan_Intro2[] = _("feras plus qu'un avec le vent.");

const u8 gText_MatchCallTriathlete_Katelyn_Strategy[] = _("À l'attaque sans retenue !");
const u8 gText_MatchCallTriathlete_Katelyn_Pokemon[] = _("Les POKéMON EAU dominent !");
const u8 gText_MatchCallTriathlete_Katelyn_Intro1[] = _("Je dois nager plus de dix");
const u8 gText_MatchCallTriathlete_Katelyn_Intro2[] = _("kilomètres chaque jour.");

const u8 gText_MatchCallTriathlete_Benjamin_Strategy[] = _("Pousser, encore et toujours !");
const u8 gText_MatchCallTriathlete_Benjamin_Pokemon[] = _("La force de l'ACIER.");
const u8 gText_MatchCallTriathlete_Benjamin_Intro1[] = _("Si tu transpires, pense à");
const u8 gText_MatchCallTriathlete_Benjamin_Intro2[] = _("boire régulièrement.");

const u8 gText_MatchCallTriathlete_Pablo_Strategy[] = _("Puiser dans la force de l'EAU.");
const u8 gText_MatchCallTriathlete_Pablo_Pokemon[] = _("Des POKéMON EAU endurcis.");
const u8 gText_MatchCallTriathlete_Pablo_Intro1[] = _("Entraîner ses POKéMON, oui,");
const u8 gText_MatchCallTriathlete_Pablo_Intro2[] = _("mais sans se négliger.");

const u8 gText_MatchCallDragonTamer_Nicolas_Strategy[] = _("Tout repose sur leur puissance !");
const u8 gText_MatchCallDragonTamer_Nicolas_Pokemon[] = _("Admire la force des DRAGONS !");
const u8 gText_MatchCallDragonTamer_Nicolas_Intro1[] = _("Un jour, je serai le plus fort");
const u8 gText_MatchCallDragonTamer_Nicolas_Intro2[] = _("et j'entrerai dans la légende !");

const u8 gText_MatchCallBirdKeeper_Robert_Strategy[] = _("Admire ma technique !");
const u8 gText_MatchCallBirdKeeper_Robert_Pokemon[] = _("Des oiseaux au vol élégant.");
const u8 gText_MatchCallBirdKeeper_Robert_Intro1[] = _("POKéMON oiseaux, portez mon");
const u8 gText_MatchCallBirdKeeper_Robert_Intro2[] = _("amour à cette jeune fille !");

const u8 gText_MatchCallNinjaBoy_Lao_Strategy[] = _("Tu vas souffrir du poison !");
const u8 gText_MatchCallNinjaBoy_Lao_Pokemon[] = _("Des POKéMON venimeux.");
const u8 gText_MatchCallNinjaBoy_Lao_Intro1[] = _("Je suis un entraînement");
const u8 gText_MatchCallNinjaBoy_Lao_Intro2[] = _("rigoureux pour devenir ninja.");

const u8 gText_MatchCallBattleGirl_Cyndy_Strategy[] = _("Le premier coup décide de tout !");
const u8 gText_MatchCallBattleGirl_Cyndy_Pokemon[] = _("Des POKéMON COMBAT rapides.");
const u8 gText_MatchCallBattleGirl_Cyndy_Intro1[] = _("Si mes POKéMON perdent,");
const u8 gText_MatchCallBattleGirl_Cyndy_Intro2[] = _("je continuerai le combat !");

const u8 gText_MatchCallParasolLady_Madeline_Strategy[] = _("Allez, mes POKéMON !");
const u8 gText_MatchCallParasolLady_Madeline_Pokemon[] = _("Je peux élever n'importe lequel.");
const u8 gText_MatchCallParasolLady_Madeline_Intro1[] = _("Les UV sont les ennemis de");
const u8 gText_MatchCallParasolLady_Madeline_Intro2[] = _("la peau. Protège-toi.");

const u8 gText_MatchCallSwimmer_Jenny_Strategy[] = _("Aucune pitié !");
const u8 gText_MatchCallSwimmer_Jenny_Pokemon[] = _("De mignons POKéMON EAU.");
const u8 gText_MatchCallSwimmer_Jenny_Intro1[] = _("J'ai beaucoup trop de fans.");
const u8 gText_MatchCallSwimmer_Jenny_Intro2[] = _("On m'a interviewée à la télé.");

const u8 gText_MatchCallPicnicker_Diana_Strategy[] = _("Je pense à tout et à rien.");
const u8 gText_MatchCallPicnicker_Diana_Pokemon[] = _("J'aime tous les POKéMON.");
const u8 gText_MatchCallPicnicker_Diana_Intro1[] = _("Qu'est-ce qui se trouve");
const u8 gText_MatchCallPicnicker_Diana_Intro2[] = _("derrière cette colline ?");

const u8 gText_MatchCallTwins_AmyAndLiv_Strategy[] = _("On combat ensemble !");
const u8 gText_MatchCallTwins_AmyAndLiv_Pokemon[] = _("On s'entraîne ensemble !");
const u8 gText_MatchCallTwins_AmyAndLiv_Intro1[] = _("On aime les mêmes POKéMON,");
const u8 gText_MatchCallTwins_AmyAndLiv_Intro2[] = _("mais pas les mêmes desserts.");

const u8 gText_MatchCallSailor_Ernest_Strategy[] = _("Je m'impose par la force !");
const u8 gText_MatchCallSailor_Ernest_Pokemon[] = _("Les types EAU et COMBAT.");
const u8 gText_MatchCallSailor_Ernest_Intro1[] = _("Les marins ont le sang chaud !");
const u8 gText_MatchCallSailor_Ernest_Intro2[] = _("Un problème ?");

const u8 gText_MatchCallSailor_Cory_Strategy[] = _("Toujours prêt à combattre !");
const u8 gText_MatchCallSailor_Cory_Pokemon[] = _("Je préfère les POKéMON EAU !");
const u8 gText_MatchCallSailor_Cory_Intro1[] = _("Pour crier bien fort, inspire");
const u8 gText_MatchCallSailor_Cory_Intro2[] = _("profondément avec le ventre !");

const u8 gText_MatchCallCollector_Edwin_Strategy[] = _("Protéger les POKéMON du danger.");
const u8 gText_MatchCallCollector_Edwin_Pokemon[] = _("J'adore les POKéMON rares.");
const u8 gText_MatchCallCollector_Edwin_Intro1[] = _("Je veux collectionner tous");
const u8 gText_MatchCallCollector_Edwin_Intro2[] = _("les POKéMON rares du monde.");

const u8 gText_MatchCallPkmnBreeder_Lydia_Strategy[] = _("Je mise sur la puissance.");
const u8 gText_MatchCallPkmnBreeder_Lydia_Pokemon[] = _("Mes POKéMON sont mes enfants.");
const u8 gText_MatchCallPkmnBreeder_Lydia_Intro1[] = _("Élever des POKéMON demande");
const u8 gText_MatchCallPkmnBreeder_Lydia_Intro2[] = _("du savoir et de l'amour.");

const u8 gText_MatchCallPkmnBreeder_Isaac_Strategy[] = _("Attaquer sans retenue !");
const u8 gText_MatchCallPkmnBreeder_Isaac_Pokemon[] = _("Je peux élever n'importe lequel.");
const u8 gText_MatchCallPkmnBreeder_Isaac_Intro1[] = _("Je leur donne des {POKEBLOCK}S");
const u8 gText_MatchCallPkmnBreeder_Isaac_Intro2[] = _("pour gagner les CONCOURS.");

const u8 gText_MatchCallPkmnBreeder_Gabrielle_Strategy[] = _("J'élève mes POKéMON avec soin.");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Pokemon[] = _("Des POKéMON plaisants à élever.");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Intro1[] = _("Traite chaque POKéMON que");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Intro2[] = _("tu rencontres avec respect.");

const u8 gText_MatchCallPkmnRanger_Catherine_Strategy[] = _("Je crois en mes POKéMON.");
const u8 gText_MatchCallPkmnRanger_Catherine_Pokemon[] = _("J'aime les POKéMON forts.");
const u8 gText_MatchCallPkmnRanger_Catherine_Intro1[] = _("Avec mes POKéMON, je me forme");
const u8 gText_MatchCallPkmnRanger_Catherine_Intro2[] = _("aux opérations de sauvetage.");

const u8 gText_MatchCallPkmnRanger_Jackson_Strategy[] = _("Attaquer par vagues !");
const u8 gText_MatchCallPkmnRanger_Jackson_Pokemon[] = _("J'utilise plusieurs types.");
const u8 gText_MatchCallPkmnRanger_Jackson_Intro1[] = _("Ceux qui détruisent la nature");
const u8 gText_MatchCallPkmnRanger_Jackson_Intro2[] = _("ne méritent aucun pardon !");

const u8 gText_MatchCallLass_Haley_Strategy[] = _("Tu vas voir mon courage !");
const u8 gText_MatchCallLass_Haley_Pokemon[] = _("Je préfère les POKéMON mignons !");
const u8 gText_MatchCallLass_Haley_Intro1[] = _("Après un combat, je prends");
const u8 gText_MatchCallLass_Haley_Intro2[] = _("toujours un bain avec eux.");

const u8 gText_MatchCallBugCatcher_James_Strategy[] = _("Attaquer à la vitesse éclair !");
const u8 gText_MatchCallBugCatcher_James_Pokemon[] = _("Les POKéMON INSECTE sont les\nmeilleurs !");
const u8 gText_MatchCallBugCatcher_James_Intro1[] = _("Pour attraper des POKéMON");
const u8 gText_MatchCallBugCatcher_James_Intro2[] = _("INSECTE, lève-toi tôt.");

const u8 gText_MatchCallHiker_Trent_Strategy[] = _("Je combats avec puissance.");
const u8 gText_MatchCallHiker_Trent_Pokemon[] = _("Des POKéMON au corps robuste.");
const u8 gText_MatchCallHiker_Trent_Intro1[] = _("Je prépare la randonnée");
const u8 gText_MatchCallHiker_Trent_Intro2[] = _("d'aujourd'hui depuis un mois.");

const u8 gText_MatchCallHiker_Sawyer_Strategy[] = _("J'aime quand ça chauffe !");
const u8 gText_MatchCallHiker_Sawyer_Pokemon[] = _("Des POKéMON brûlants !");
const u8 gText_MatchCallHiker_Sawyer_Intro1[] = _("J'adore les POKéMON, mais");
const u8 gText_MatchCallHiker_Sawyer_Intro2[] = _("aussi les randonnées !");

const u8 gText_MatchCallYoungCouple_LoisAndHal_Strategy[] = _("Une stratégie pleine d'amour !");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Pokemon[] = _("Des POKéMON pleins d'amour !");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Intro1[] = _("On s'aime à la folie !");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Intro2[] = _("Et ce sera pour toujours !");

const u8 gText_MatchCallPkmnTrainer_Wally_Strategy[] = _("On donne tout ce qu'on a.");
const u8 gText_MatchCallPkmnTrainer_Wally_Pokemon[] = _("Le premier POKéMON que j'ai pris.");
const u8 gText_MatchCallPkmnTrainer_Wally_Intro1[] = _("Mon POKéMON et moi sommes");
const u8 gText_MatchCallPkmnTrainer_Wally_Intro2[] = _("devenus plus forts ensemble.");

const u8 gText_MatchCallRockinWhiz_Roxanne_Strategy[] = _("Une puissante attaque ROC.");
const u8 gText_MatchCallRockinWhiz_Roxanne_Pokemon[] = _("Je préfère les POKéMON solides.");
const u8 gText_MatchCallRockinWhiz_Roxanne_Intro1[] = _("Diriger une grande ARÈNE");
const u8 gText_MatchCallRockinWhiz_Roxanne_Intro2[] = _("implique bien des responsabilités.");

const u8 gText_MatchCallTheBigHit_Brawly_Strategy[] = _("Attaquer au corps à corps !");
const u8 gText_MatchCallTheBigHit_Brawly_Pokemon[] = _("Les POKéMON COMBAT dominent !");
const u8 gText_MatchCallTheBigHit_Brawly_Intro1[] = _("Le monde attend que je sois");
const u8 gText_MatchCallTheBigHit_Brawly_Intro2[] = _("la prochaine grande vague !");

const u8 gText_MatchCallSwellShock_Wattson_Strategy[] = _("J'ai choisi de vous électriser.");
const u8 gText_MatchCallSwellShock_Wattson_Pokemon[] = _("Attention à la décharge !");
const u8 gText_MatchCallSwellShock_Wattson_Intro1[] = _("Il ne faut jamais truquer");
const u8 gText_MatchCallSwellShock_Wattson_Intro2[] = _("un match. Même moi, jamais.");

const u8 gText_MatchCallPassionBurn_Flannery_Strategy[] = _("Combattre avec agressivité.");
const u8 gText_MatchCallPassionBurn_Flannery_Pokemon[] = _("Brûlants de passion !");
const u8 gText_MatchCallPassionBurn_Flannery_Intro1[] = _("Les sources chaudes effacent");
const u8 gText_MatchCallPassionBurn_Flannery_Intro2[] = _("toute la fatigue du jour !");

const u8 gText_MatchCallReliableOne_Dad_Strategy[] = _("J'adapte mon style avec souplesse.");
const u8 gText_MatchCallReliableOne_Dad_Pokemon[] = _("Élevés de façon équilibrée.");
const u8 gText_MatchCallReliableOne_Dad_Intro1[] = _("Chaque jour, je viens de chez");
const u8 gText_MatchCallReliableOne_Dad_Intro2[] = _("moi à pied en trente minutes.");

const u8 gText_MatchCallSkyTamer_Winona_Strategy[] = _("Je tire parti de la vitesse.");
const u8 gText_MatchCallSkyTamer_Winona_Pokemon[] = _("De gracieux danseurs du ciel.");
const u8 gText_MatchCallSkyTamer_Winona_Intro1[] = _("Mon idéal serait de vivre");
const u8 gText_MatchCallSkyTamer_Winona_Intro2[] = _("en harmonie avec la nature.");

const u8 gText_MatchCallMysticDuo_TateAndLiza_Strategy[] = _("On combat en coopération.");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Pokemon[] = _("Des POKéMON toujours amicaux.");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Intro1[] = _("Papa a du mal à nous");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Intro2[] = _("différencier toutes les deux !");

const u8 gText_MatchCallDandyCharm_Juan_Strategy[] = _("J'emploie la majesté de l'eau.");
const u8 gText_MatchCallDandyCharm_Juan_Pokemon[] = _("Des POKéMON tout en élégance !");
const u8 gText_MatchCallDandyCharm_Juan_Intro1[] = _("L'admiration des belles dames");
const u8 gText_MatchCallDandyCharm_Juan_Intro2[] = _("me remplit d'énergie !");

const u8 gText_MatchCallEliteFour_Sidney_Strategy[] = _("L'attaque avant la défense !");
const u8 gText_MatchCallEliteFour_Sidney_Pokemon[] = _("Les beautés des TÉNÈBRES.");
const u8 gText_MatchCallEliteFour_Sidney_Intro1[] = _("On me traitait de voyou, mais");
const u8 gText_MatchCallEliteFour_Sidney_Intro2[] = _("je siège au CONSEIL 4 !");

const u8 gText_MatchCallEliteFour_Phoebe_Strategy[] = _("Troubler et rendre confus.");
const u8 gText_MatchCallEliteFour_Phoebe_Pokemon[] = _("Rien n'est jamais certain.");
const u8 gText_MatchCallEliteFour_Phoebe_Intro1[] = _("Je me demande comment va");
const u8 gText_MatchCallEliteFour_Phoebe_Intro2[] = _("ma grand-mère au MT. PYRE.");

const u8 gText_MatchCallEliteFour_Glacia_Strategy[] = _("Je m'aide avec des objets.");
const u8 gText_MatchCallEliteFour_Glacia_Pokemon[] = _("Une passion brûlante et glacée !");
const u8 gText_MatchCallEliteFour_Glacia_Intro1[] = _("Le type GLACE se renforce");
const u8 gText_MatchCallEliteFour_Glacia_Intro2[] = _("mieux dans cette région chaude.");

const u8 gText_MatchCallEliteFour_Drake_Strategy[] = _("Maîtriser de fortes capacités.");
const u8 gText_MatchCallEliteFour_Drake_Pokemon[] = _("La force brute des DRAGONS !");
const u8 gText_MatchCallEliteFour_Drake_Intro1[] = _("Je me consacre aux POKéMON");
const u8 gText_MatchCallEliteFour_Drake_Intro2[] = _("qui m'ont sauvé.");

const u8 gText_MatchCallChampion_Wallace_Strategy[] = _("Dignité et respect.");
const u8 gText_MatchCallChampion_Wallace_Pokemon[] = _("Je préfère les POKéMON gracieux.");
const u8 gText_MatchCallChampion_Wallace_Intro1[] = _("J'incarne aussi bien la beauté");
const u8 gText_MatchCallChampion_Wallace_Intro2[] = _("que l'intelligence.");
#endif

#if IS_HNS
// Check page disabled for HnS trainers — table left empty.
// To re-enable: add MCFLAVOR entries here and set HasCheckPage_Trainer to TRUE.
const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] = {0};
#else
const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] =
{
    [REMATCH_ROSE] = MCFLAVOR(AromaLady_Rose),
    [REMATCH_ANDRES] = MCFLAVOR(RuinManiac_Andres),
    [REMATCH_DUSTY] = MCFLAVOR(RuinManiac_Dusty),
    [REMATCH_LOLA] = MCFLAVOR(Tuber_Lola),
    [REMATCH_RICKY] = MCFLAVOR(Tuber_Ricky),
    [REMATCH_LILA_AND_ROY] = MCFLAVOR(SisAndBro_LilaAndRoy),
    [REMATCH_CRISTIN] = MCFLAVOR(Cooltrainer_Cristin),
    [REMATCH_BROOKE] = MCFLAVOR(Cooltrainer_Brooke),
    [REMATCH_WILTON] = MCFLAVOR(Cooltrainer_Wilton),
    [REMATCH_VALERIE] = MCFLAVOR(HexManiac_Valerie),
    [REMATCH_CINDY] = MCFLAVOR(Lady_Cindy),
    [REMATCH_THALIA] = MCFLAVOR(Beauty_Thalia),
    [REMATCH_JESSICA] = MCFLAVOR(Beauty_Jessica),
    [REMATCH_WINSTON] = MCFLAVOR(RichBoy_Winston),
    [REMATCH_STEVE] = MCFLAVOR(PokeManiac_Steve),
    [REMATCH_TONY] = MCFLAVOR(Swimmer_Tony),
    [REMATCH_NOB] = MCFLAVOR(BlackBelt_Nob),
    [REMATCH_KOJI] = MCFLAVOR(BlackBelt_Koji),
    [REMATCH_FERNANDO] = MCFLAVOR(Guitarist_Fernando),
    [REMATCH_DALTON] = MCFLAVOR(Guitarist_Dalton),
    [REMATCH_BERNIE] = MCFLAVOR(Kindler_Bernie),
    [REMATCH_ETHAN] = MCFLAVOR(Camper_Ethan),
    [REMATCH_JOHN_AND_JAY] = MCFLAVOR(OldCouple_JohnAndJay),
    [REMATCH_JEFFREY] = MCFLAVOR(BugManiac_Jeffrey),
    [REMATCH_CAMERON] = MCFLAVOR(Psychic_Cameron),
    [REMATCH_JACKI] = MCFLAVOR(Psychic_Jacki),
    [REMATCH_WALTER] = MCFLAVOR(Gentleman_Walter),
    [REMATCH_KAREN] = MCFLAVOR(SchoolKid_Karen),
    [REMATCH_JERRY] = MCFLAVOR(SchoolKid_Jerry),
    [REMATCH_ANNA_AND_MEG] = MCFLAVOR(SrAndJr_AnnaAndMeg),
    [REMATCH_ISABEL] = MCFLAVOR(Pokefan_Isabel),
    [REMATCH_MIGUEL] = MCFLAVOR(Pokefan_Miguel),
    [REMATCH_TIMOTHY] = MCFLAVOR(Expert_Timothy),
    [REMATCH_SHELBY] = MCFLAVOR(Expert_Shelby),
    [REMATCH_CALVIN] = MCFLAVOR(Youngster_Calvin),
    [REMATCH_ELLIOT] = MCFLAVOR(Fisherman_Elliot),
    [REMATCH_ISAIAH] = MCFLAVOR(Triathlete_Isaiah),
    [REMATCH_MARIA] = MCFLAVOR(Triathlete_Maria),
    [REMATCH_ABIGAIL] = MCFLAVOR(Triathlete_Abigail),
    [REMATCH_DYLAN] = MCFLAVOR(Triathlete_Dylan),
    [REMATCH_KATELYN] = MCFLAVOR(Triathlete_Katelyn),
    [REMATCH_BENJAMIN] = MCFLAVOR(Triathlete_Benjamin),
    [REMATCH_PABLO] = MCFLAVOR(Triathlete_Pablo),
    [REMATCH_NICOLAS] = MCFLAVOR(DragonTamer_Nicolas),
    [REMATCH_ROBERT] = MCFLAVOR(BirdKeeper_Robert),
    [REMATCH_LAO] = MCFLAVOR(NinjaBoy_Lao),
    [REMATCH_CYNDY] = MCFLAVOR(BattleGirl_Cyndy),
    [REMATCH_MADELINE] = MCFLAVOR(ParasolLady_Madeline),
    [REMATCH_JENNY] = MCFLAVOR(Swimmer_Jenny),
    [REMATCH_DIANA] = MCFLAVOR(Picnicker_Diana),
    [REMATCH_AMY_AND_LIV] = MCFLAVOR(Twins_AmyAndLiv),
    [REMATCH_ERNEST] = MCFLAVOR(Sailor_Ernest),
    [REMATCH_CORY] = MCFLAVOR(Sailor_Cory),
    [REMATCH_EDWIN] = MCFLAVOR(Collector_Edwin),
    [REMATCH_LYDIA] = MCFLAVOR(PkmnBreeder_Lydia),
    [REMATCH_ISAAC] = MCFLAVOR(PkmnBreeder_Isaac),
    [REMATCH_GABRIELLE] = MCFLAVOR(PkmnBreeder_Gabrielle),
    [REMATCH_CATHERINE] = MCFLAVOR(PkmnRanger_Catherine),
    [REMATCH_JACKSON] = MCFLAVOR(PkmnRanger_Jackson),
    [REMATCH_HALEY] = MCFLAVOR(Lass_Haley),
    [REMATCH_JAMES] = MCFLAVOR(BugCatcher_James),
    [REMATCH_TRENT] = MCFLAVOR(Hiker_Trent),
    [REMATCH_SAWYER] = MCFLAVOR(Hiker_Sawyer),
    [REMATCH_KIRA_AND_DAN] = MCFLAVOR(YoungCouple_LoisAndHal),
    [REMATCH_WALLY_VR] = MCFLAVOR(PkmnTrainer_Wally),
    [REMATCH_ROXANNE] = MCFLAVOR(RockinWhiz_Roxanne),
    [REMATCH_BRAWLY] = MCFLAVOR(TheBigHit_Brawly),
    [REMATCH_WATTSON] = MCFLAVOR(SwellShock_Wattson),
    [REMATCH_FLANNERY] = MCFLAVOR(PassionBurn_Flannery),
    [REMATCH_NORMAN] = MCFLAVOR(ReliableOne_Dad),
    [REMATCH_WINONA] = MCFLAVOR(SkyTamer_Winona),
    [REMATCH_TATE_AND_LIZA] = MCFLAVOR(MysticDuo_TateAndLiza),
    [REMATCH_JUAN] = MCFLAVOR(DandyCharm_Juan),
    [REMATCH_SIDNEY] = MCFLAVOR(EliteFour_Sidney),
    [REMATCH_PHOEBE] = MCFLAVOR(EliteFour_Phoebe),
    [REMATCH_GLACIA] = MCFLAVOR(EliteFour_Glacia),
    [REMATCH_DRAKE] = MCFLAVOR(EliteFour_Drake),
    [REMATCH_WALLACE] = MCFLAVOR(Champion_Wallace),
};
#endif
