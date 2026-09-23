// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("TALK POKéMON DE CHEN");
static const u8 sRadioStationName_PokedexShow[]     = _("ÉMISSION POKéDEX");
static const u8 sRadioStationName_PokemonMusic[]    = _("MUSIQUE POKéMON");
static const u8 sRadioStationName_LuckyChannel[]    = _("CHAÎNE CHANCE");
static const u8 sRadioStationName_BuenasPassword[]  = _("MOT DE PASSE DE BUENA");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("LIEUX ET GENS");
static const u8 sRadioStationName_LetsAllSing[]     = _("CHANTONS TOUS !");
static const u8 sRadioStationName_PokeFlute[]       = _("POKÉ FLÛTE");

static const u8 sRadioStationName_HoennSound[]  = _("SONS DE HOENN");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("Une mélodie POKéMON venue");
static const u8 sRadioText_Hoenn2[] = _("d'une région lointaine : HOENN !");
static const u8 sRadioText_Hoenn3[] = _("Des POKéMON sauvages de là-bas");
static const u8 sRadioText_Hoenn4[] = _("pourraient apparaître ici !");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("ÉMISSION POKéDEX DE CHEN !");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("CHEN : Aujourd'hui, ");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("MARY : TALK POKéMON DE CHEN !");
static const u8 sRadioText_OPT_WithMeMary[] = _("Avec moi, MARY !");
static const u8 sRadioText_OPT_OakPrefix[] = _("CHEN : ");
static const u8 sRadioText_OPT_SeenAround[] = _("se trouve près de");
static const u8 sRadioText_OPT_MaryPrefix[] = _("MARY : ");
static const u8 sRadioText_OPT_MaryIs[] = _(" est");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("CHAÎNE POKéMON");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("tout bonnement");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("incroyablement");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("à juste titre");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("indéniablement");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("terriblement");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("franchement");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("dangereusement");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("ô combien");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("malicieusement");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("singulièrement");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("totalement");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("à première vue");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("par nature");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("effrontément");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("complètement");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("vraiment");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("adorable.");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("étrange.");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("agréable.");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("plutôt audacieux.");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("effrayant.");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("chic et élégant !");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("puissant.");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("palpitant.");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("branché !");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("inspirant.");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("amical.");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("bouillant !");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("stimulant.");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("sur ses gardes.");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("ravissant.");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("rapide.");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("BEN : CHAÎNE MUSIQUE POKéMON !");
static const u8 sRadioText_BenIntro2[] = _("C'est moi, DJ BEN !");
static const u8 sRadioText_FernIntro[] = _("FERN : POKéMUSIQUE !");
static const u8 sRadioText_FernIntro2[] = _("Avec DJ FERN !");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("Aujourd'hui, ");
static const u8 sRadioText_BenFern_JamTo[] = _("alors dansons sur");
static const u8 sRadioText_BenFern_ChillTo[] = _("alors détendons-nous avec");
static const u8 sRadioText_BenFern_March[] = _("MARCHE POKéMON !");
static const u8 sRadioText_BenFern_Lullaby[] = _("BERCEUSE POKéMON !");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("REED : Yee-haw ! Ça va, vous ?");
static const u8 sRadioText_LC2[] = _("Que vous ayez le moral ou non,");
static const u8 sRadioText_LC3[] = _("ne ratez surtout pas");
static const u8 sRadioText_LC4[] = _("L'ÉMISSION DU NUMÉRO CHANCE !");
static const u8 sRadioText_LC5[] = _("Le numéro de la semaine est");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("Je répète !");
static const u8 sRadioText_LC_Match[] = _("S'il correspond, allez à");
static const u8 sRadioText_LC_Tower[] = _("la TOUR RADIO !");
static const u8 sRadioText_LC_Drag1[] = _("…À force de me répéter,");
static const u8 sRadioText_LC_Drag2[] = _("je commence à me lasser…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("LIEUX ET GENS ! Une émission");
static const u8 sRadioText_PnP_Intro2[] = _("présentée par DJ LILY !");
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("est adorable.");
static const u8 sRadioText_PnP_Lazy[]       = _("a tendance à paresser.");
static const u8 sRadioText_PnP_Happy[]      = _("est toujours de bonne humeur.");
static const u8 sRadioText_PnP_Noisy[]      = _("fait beaucoup de bruit.");
static const u8 sRadioText_PnP_Precocious[] = _("a beaucoup d'avance.");
static const u8 sRadioText_PnP_Bold[]       = _("ne manque pas d'audace.");
static const u8 sRadioText_PnP_Picky[]      = _("est très difficile !");
static const u8 sRadioText_PnP_SortOfOK[]   = _("n'est pas mal.");
static const u8 sRadioText_PnP_SoSo[]       = _("est sans plus.");
static const u8 sRadioText_PnP_Great[]       = _("est vraiment au top.");
static const u8 sRadioText_PnP_MyType[]      = _("est tout à fait mon type.");
static const u8 sRadioText_PnP_Cool[]        = _("a vraiment la classe, non ?");
static const u8 sRadioText_PnP_Inspiring[]   = _("donne de l'inspiration !");
static const u8 sRadioText_PnP_Weird[]       = _("est un peu étrange.");
static const u8 sRadioText_PnP_RightForMe[]  = _("me conviendrait bien, non ?");
static const u8 sRadioText_PnP_Odd[]         = _("est vraiment bizarre !");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
static const u8 sRadioText_Rocket1[]  = _("… …Hum, nous sommes");
static const u8 sRadioText_Rocket2[]  = _("la TEAM ROCKET !");
static const u8 sRadioText_Rocket3[]  = _("Après trois ans");
static const u8 sRadioText_Rocket4[]  = _("de préparation, nous");
static const u8 sRadioText_Rocket5[]  = _("renaissons enfin");
static const u8 sRadioText_Rocket6[]  = _("de nos cendres !");
static const u8 sRadioText_Rocket7[]  = _("GIOVANNI !");
static const u8 sRadioText_Rocket8[]  = _("Tu nous entends ?");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("BUENA : Ici BUENA !");
static const u8 sRadioText_Buena2[] = _("Le mot de passe du jour !");
static const u8 sRadioText_Buena3[] = _("Voyons… C'est");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1} !");
static const u8 sRadioText_Buena5[] = _("Ne l'oubliez pas ! Je suis à la");
static const u8 sRadioText_Buena6[] = _("TOUR RADIO DE DOUBLONVILLE !");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("BOURG GEON");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("VILLE GRIOTTE");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("ÉCORCIA");
static const u8 sRadioBuenaPassword_Flying[]          = _("VOL");
static const u8 sRadioBuenaPassword_Bug[]             = _("INSECTE");
static const u8 sRadioBuenaPassword_Grass[]           = _("PLANTE");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("TALK POKéMON");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("MUSIQUE POKéMON");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("CHAÎNE CHANCE");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("MARY : Ce soir, phénomène rare");
static const u8 sOPT_Report_Clefairy_1[]  = _("au TALK POKéMON !");
static const u8 sOPT_Report_Clefairy_2[]  = _("CHEN : Pleins feux sur le");
static const u8 sOPT_Report_Clefairy_3[]  = _("mystérieux MÉLOFÉE !");
static const u8 sOPT_Report_Clefairy_4[]  = _("Ils se réunissent au MONT");
static const u8 sOPT_Report_Clefairy_5[]  = _("SÉLÉNITE les soirs de pleine lune.");
static const u8 sOPT_Report_Clefairy_6[]  = _("MARY : Ils dansent en cercle !");
static const u8 sOPT_Report_Clefairy_7[]  = _("C'est étrange et adorable !");
static const u8 sOPT_Report_Clefairy_8[]  = _("CHEN : Un mystère éternel");
static const u8 sOPT_Report_Clefairy_9[]  = _("et un spectacle saisissant !");

static const u8 sOPT_Report_Lapras_0[]  = _("MARY : Un doux géant entre");
static const u8 sOPT_Report_Lapras_1[]  = _("en scène aujourd'hui !");
static const u8 sOPT_Report_Lapras_2[]  = _("CHEN : Ce passeur des mers,");
static const u8 sOPT_Report_Lapras_3[]  = _("c'est notre cher LOKHLASS !");
static const u8 sOPT_Report_Lapras_4[]  = _("On le voit aux CAVES JUMELLES,");
static const u8 sOPT_Report_Lapras_5[]  = _("mais pas ailleurs. Curieux !");
static const u8 sOPT_Report_Lapras_6[]  = _("MARY : Si rare et paisible !");
static const u8 sOPT_Report_Lapras_7[]  = _("Et il sait aussi chanter !");
static const u8 sOPT_Report_Lapras_8[]  = _("CHEN : On dit que son chant");
static const u8 sOPT_Report_Lapras_9[]  = _("apaise l'âme de l'océan.");

static const u8 sOPT_Report_Ampharos_0[]  = _("MARY : Heureuse de vous revoir !");
static const u8 sOPT_Report_Ampharos_1[]  = _("Place au TALK POKéMON !");
static const u8 sOPT_Report_Ampharos_2[]  = _("CHEN : Mettons en lumière");
static const u8 sOPT_Report_Ampharos_3[]  = _("notre ami PHARAMP !");
static const u8 sOPT_Report_Ampharos_4[]  = _("Sa queue brille dans le");
static const u8 sOPT_Report_Ampharos_5[]  = _("brouillard et guide les égarés.");
static const u8 sOPT_Report_Ampharos_6[]  = _("MARY : Puissant, élégant,");
static const u8 sOPT_Report_Ampharos_7[]  = _("et tellement sympathique !");
static const u8 sOPT_Report_Ampharos_8[]  = _("CHEN : Un héros de bien des");
static const u8 sOPT_Report_Ampharos_9[]  = _("histoires de phares !");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("MARY : Voici un drôle de spécimen");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("sur la ROUTE 36…");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("CHEN : SIMULARBRE ! On dirait");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("un arbre, mais il n'en est rien !");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("Il bloque la route et refuse");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("de bouger sans eau.");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("MARY : Il ne réagit qu'à la");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("CARAPUCE À O !");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("CHEN : Ce n'est pas un buisson,");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("mais un type ROC déguisé !");

static const u8 sOPT_Report_RedGyarados_0[]  = _("MARY : Notre histoire du jour");
static const u8 sOPT_Report_RedGyarados_1[]  = _("va secouer tout JOHTO !");
static const u8 sOPT_Report_RedGyarados_2[]  = _("CHEN : Des Dresseurs ont vu un");
static const u8 sOPT_Report_RedGyarados_3[]  = _("LÉVIATOR rouge au LAC COLÈRE !");
static const u8 sOPT_Report_RedGyarados_4[]  = _("Contrairement aux bleus habituels,");
static const u8 sOPT_Report_RedGyarados_5[]  = _("celui-ci est rouge vif !");
static const u8 sOPT_Report_RedGyarados_6[]  = _("MARY : On le dit lié à");
static const u8 sOPT_Report_RedGyarados_7[]  = _("d'étranges ondes radio !");
static const u8 sOPT_Report_RedGyarados_8[]  = _("CHEN : Une évolution mystérieuse…");
static const u8 sOPT_Report_RedGyarados_9[]  = _("Peut-être artificielle.");

static const u8 sOPT_Report_Unown_0[]  = _("MARY : Connaissez-vous les");
static const u8 sOPT_Report_Unown_1[]  = _("RUINES D'ALPHA ? Quel frisson !");
static const u8 sOPT_Report_Unown_2[]  = _("CHEN : D'étranges symboles");
static const u8 sOPT_Report_Unown_3[]  = _("couvrent les murs, tels des runes.");
static const u8 sOPT_Report_Unown_4[]  = _("On y trouve des ZARBI…");
static const u8 sOPT_Report_Unown_5[]  = _("tous en forme de lettres !");
static const u8 sOPT_Report_Unown_6[]  = _("MARY : Écrivent-ils des mots ?");
static const u8 sOPT_Report_Unown_7[]  = _("Ou veulent-ils nous effrayer ?");
static const u8 sOPT_Report_Unown_8[]  = _("CHEN : Un mystère de la nature,");
static const u8 sOPT_Report_Unown_9[]  = _("encore irrésolue aujourd'hui.");

static const u8 sOPT_Report_Snubbull_0[]  = _("MARY : Tout DOUBLONVILLE cherche");
static const u8 sOPT_Report_Snubbull_1[]  = _("partout !");
static const u8 sOPT_Report_Snubbull_2[]  = _("CHEN : Un SNUBBULL s'est échappé");
static const u8 sOPT_Report_Snubbull_3[]  = _("et court toujours !");
static const u8 sOPT_Report_Snubbull_4[]  = _("D'ordinaire timide et capricieux,");
static const u8 sOPT_Report_Snubbull_5[]  = _("on l'a vu près de la station.");
static const u8 sOPT_Report_Snubbull_6[]  = _("MARY : Il cherche peut-être");
static const u8 sOPT_Report_Snubbull_7[]  = _("l'amour… ou l'aventure !");
static const u8 sOPT_Report_Snubbull_8[]  = _("CHEN : Gardez l'œil ouvert");
static const u8 sOPT_Report_Snubbull_9[]  = _("et la laisse à portée !");

static const u8 sOPT_Report_Slowpoke_0[]  = _("MARY : Grande nouvelle d'ÉCORCIA");
static const u8 sOPT_Report_Slowpoke_1[]  = _("cette semaine !");
static const u8 sOPT_Report_Slowpoke_2[]  = _("CHEN : Les RAMOLOSS sont revenus");
static const u8 sOPT_Report_Slowpoke_3[]  = _("dans leur PUITS après la crise !");
static const u8 sOPT_Report_Slowpoke_4[]  = _("La TEAM ROCKET coupait");
static const u8 sOPT_Report_Slowpoke_5[]  = _("leurs queues ! Quelle horreur !");
static const u8 sOPT_Report_Slowpoke_6[]  = _("MARY : Mais un jeune Dresseur");
static const u8 sOPT_Report_Slowpoke_7[]  = _("courageux les a arrêtés !");
static const u8 sOPT_Report_Slowpoke_8[]  = _("CHEN : Les RAMOLOSS sont sauvés");
static const u8 sOPT_Report_Slowpoke_9[]  = _("et somnolent à nouveau.");

static const u8 sOPT_Report_LavenderTower_0[]  = _("MARY : La tour de LAVANVILLE");
static const u8 sOPT_Report_LavenderTower_1[]  = _("a changé de musique !");
static const u8 sOPT_Report_LavenderTower_2[]  = _("CHEN : L'ancienne tour hantée");
static const u8 sOPT_Report_LavenderTower_3[]  = _("est devenue une STATION RADIO !");
static const u8 sOPT_Report_LavenderTower_4[]  = _("Des habitants disent qu'elle");
static const u8 sOPT_Report_LavenderTower_5[]  = _("reste… inquiétante.");
static const u8 sOPT_Report_LavenderTower_6[]  = _("MARY : J'ai vu un FANTOMINUS");
static const u8 sOPT_Report_LavenderTower_7[]  = _("près du studio !");
static const u8 sOPT_Report_LavenderTower_8[]  = _("CHEN : Peut-être des parasites…");
static const u8 sOPT_Report_LavenderTower_9[]  = _("ou des spectres !");

static const u8 sOPT_Report_Tentacruel_0[]  = _("MARY : Étrange nouvelle des");
static const u8 sOPT_Report_Tentacruel_1[]  = _("TOURB'ÎLES aujourd'hui !");
static const u8 sOPT_Report_Tentacruel_2[]  = _("CHEN : Des TENTACRUEL encerclent");
static const u8 sOPT_Report_Tentacruel_3[]  = _("les entrées des grottes !");
static const u8 sOPT_Report_Tentacruel_4[]  = _("Ils sont énormes et presque");
static const u8 sOPT_Report_Tentacruel_5[]  = _("territoriaux.");
static const u8 sOPT_Report_Tentacruel_6[]  = _("MARY : Ils barrent le passage");
static const u8 sOPT_Report_Tentacruel_7[]  = _("sans attaquer…");
static const u8 sOPT_Report_Tentacruel_8[]  = _("CHEN : Comme s'ils protégeaient");
static const u8 sOPT_Report_Tentacruel_9[]  = _("un secret sous les vagues.");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
