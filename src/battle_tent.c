#include "global.h"
#include "battle_tent.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "random.h"
#include "item.h"
#include "battle_factory_screen.h"
#include "frontier_util.h"
#include "string_util.h"
#include "constants/battle_frontier.h"
#include "constants/battle_tent.h"
#include "constants/battle_tent_trainers.h"
#include "constants/battle_tent_mons.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"

// This file's functions.
static void InitVerdanturfTentChallenge(void);
static void GetVerdanturfTentPrize(void);
static void SetVerdanturfTentPrize(void);
static void SetVerdanturfTentTrainerGfx(void);
static void BufferVerdanturfTentTrainerIntro(void);
static void SaveVerdanturfTentChallenge(void);
static void SetRandomVerdanturfTentPrize(void);
static void GiveVerdanturfTentPrize(void);
static void InitFallarborTentChallenge(void);
static void GetFallarborTentPrize(void);
static void SetFallarborTentPrize(void);
static void SaveFallarborTentChallenge(void);
static void SetRandomFallarborTentPrize(void);
static void GiveFallarborTentPrize(void);
static void BufferFallarborTentTrainerName(void);
static void InitSlateportTentChallenge(void);
static void GetSlateportTentPrize(void);
static void SetSlateportTentPrize(void);
static void SaveSlateportTentChallenge(void);
static void SetRandomSlateportTentPrize(void);
static void GiveSlateportTentPrize(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void GenerateOpponentMons(void);
static void GenerateInitialRentalMons(void);

/*
 * Battle Tents are mini versions of particular Battle Frontier facilities
 * As such they each share some scripts and functions with their counterpart
 *
 * Verdanturf Battle Tent: Battle Palace
 * Fallarbor Battle Tent:  Battle Arena
 * Slateport Battle Tent:  Battle Factory
 *
 */

static u16 sRandMonId;

void static (*const sVerdanturfTentFuncs[])(void) =
{
    [VERDANTURF_TENT_FUNC_INIT]               = InitVerdanturfTentChallenge,
    [VERDANTURF_TENT_FUNC_GET_PRIZE]          = GetVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_SET_PRIZE]          = SetVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_SET_OPPONENT_GFX]   = SetVerdanturfTentTrainerGfx,
    [VERDANTURF_TENT_FUNC_GET_OPPONENT_INTRO] = BufferVerdanturfTentTrainerIntro,
    [VERDANTURF_TENT_FUNC_SAVE]               = SaveVerdanturfTentChallenge,
    [VERDANTURF_TENT_FUNC_SET_RANDOM_PRIZE]   = SetRandomVerdanturfTentPrize,
    [VERDANTURF_TENT_FUNC_GIVE_PRIZE]         = GiveVerdanturfTentPrize
};

static const u16 sVerdanturfTentRewards[] = {ITEM_NEST_BALL};

#if IS_HNS
static const u8 *const sSlateportTentIntroTextsHns[] =
{
    COMPOUND_STRING("Que vais-je devenir demain ?"),
    COMPOUND_STRING("Mauvaise nouvelle ! C'est un\ncombat sans pitié !"),
    COMPOUND_STRING("En avant ! Mes POKéMON adorent\nl'eau !"),
    COMPOUND_STRING("Ouais ! Ça va tourner !"),
    COMPOUND_STRING("On discutera après ma victoire."),
    COMPOUND_STRING("Ma beauté vous intimide-t-elle ?"),
    COMPOUND_STRING("Allez ! Trouve-moi un BARBICHA !"),
    COMPOUND_STRING("Graaah ! Graaah !"),
    COMPOUND_STRING("Une petite danse pour vous\nplaire !"),
    COMPOUND_STRING("Je veux courir partout !"),
    COMPOUND_STRING("Admirez mon attaque confuse !"),
    COMPOUND_STRING("Écoutez... Vous n'êtes pas très\nfort."),
    COMPOUND_STRING("...... ?"),
    COMPOUND_STRING("GOUPIX, XATU, NOCTALI... euh..."),
    COMPOUND_STRING("Je vais savourer ce combat !"),
    COMPOUND_STRING("Cet Œuf a un éclat délicieux !"),
    COMPOUND_STRING("Les POKéMON avant l'argent\net la famille !"),
    COMPOUND_STRING("J'adore votre allure coriace !"),
    COMPOUND_STRING("Ma malédiction brisera votre\nesprit !"),
    COMPOUND_STRING("Hein ? Vous avez dit combat ?"),
    COMPOUND_STRING("Désolé, vous allez déguster !"),
    COMPOUND_STRING("Je veux juste des POKéMON mignons."),
    COMPOUND_STRING("Des jouets ! Il me faut plus de\njouets !"),
    COMPOUND_STRING("Mmm, délicieux... Je me demande\nquoi ?"),
    COMPOUND_STRING("Pas de bavardage. On y va !"),
    COMPOUND_STRING("Monsieur l'arbitre, vous avez\nnotre confiance."),
    COMPOUND_STRING("Venez chez moi, d'accord ?"),
    COMPOUND_STRING("Je me fiche du match qui nous\nattend."),
    COMPOUND_STRING("Oh, je me sens gluant de partout."),
    COMPOUND_STRING("Je suis fâchée contre mon père...")
};

static const u8 *const sFallarborTentIntroTextsHns[] =
{
    COMPOUND_STRING("Je dois être au régime tous les\njours."),
    COMPOUND_STRING("Je n'aurai jamais assez d'argent."),
    COMPOUND_STRING("Ma façon de combattre est bizarre."),
    COMPOUND_STRING("Regardez mon Métronome, puis dodo."),
    COMPOUND_STRING("Si je gagne, donnez-moi un POKéMON\npour ma collection."),
    COMPOUND_STRING("Mon nom est vraiment mystérieux."),
    COMPOUND_STRING("Je suis le meilleur héros de\ntous !"),
    COMPOUND_STRING("Le monde est un concours de\nforce !"),
    COMPOUND_STRING("Vous êtes un bon Dresseur ?\nIncroyable !"),
    COMPOUND_STRING("Mes POKéMON ont le poil soyeux !"),
    COMPOUND_STRING("J'ai un pouvoir de prémonition."),
    COMPOUND_STRING("Vos POKéMON ne peuvent pas me\nbattre."),
    COMPOUND_STRING("Vos POKéMON sont plutôt sauvages !"),
    COMPOUND_STRING("Montrez-moi ce que vous valez."),
    COMPOUND_STRING("Vous voyez ma puissance ?"),
    COMPOUND_STRING("Un mensonge peut être gentil..."),
    COMPOUND_STRING("Un Professeur POKéMON ne se\nrepose pas."),
    COMPOUND_STRING("Ahaha ! Oui ! Un monde de POKéMON\nplein d'amour !"),
    COMPOUND_STRING("Vous... vous... vous... Allez !"),
    COMPOUND_STRING("On dirait que vous êtes très bon."),
    COMPOUND_STRING("Mon pouvoir caché m'enthousiasme !"),
    COMPOUND_STRING("Vous plaisantez, j'espère ?"),
    COMPOUND_STRING("Vous ne vous croyez pas très\nrapide ?"),
    COMPOUND_STRING("Ne faites pas de vacarme !"),
    COMPOUND_STRING("J'ai vraiment envie de faire la\nfête."),
    COMPOUND_STRING("Mon PC est ma Base Secrète !"),
    COMPOUND_STRING("Ce n'est pas très joli, mais\nj'essaie."),
    COMPOUND_STRING("Je ne suis pas assez fort pour ça."),
    COMPOUND_STRING("Pas de radio ni de télévision."),
    COMPOUND_STRING("Je veux faire les magasins !")
};

static const u8 *const sVerdanturfTentIntroTextsHns[] =
{
    COMPOUND_STRING("Pas un jour sans de fausses\nlarmes."),
    COMPOUND_STRING("Vous ignorez à quel point je\nm'ennuie."),
    COMPOUND_STRING("Je pars bientôt en vacances."),
    COMPOUND_STRING("Je suis intelligent ! Si je perds,\nje m'autodétruis."),
    COMPOUND_STRING("J'en ai assez d'être une idole."),
    COMPOUND_STRING("Ma beauté ne vous étonne pas ?"),
    COMPOUND_STRING("Allez, je vais combattre\nsérieusement."),
    COMPOUND_STRING("Oh oui ! Encore un combat\nexaltant !"),
    COMPOUND_STRING("Admirez ma superbe danse !"),
    COMPOUND_STRING("C'est triste de partir seul en\nvacances."),
    COMPOUND_STRING("Vous êtes vraiment fort ?"),
    COMPOUND_STRING("C'est un cauchemar pour vous."),
    COMPOUND_STRING("Cette fête dure pour toujours !"),
    COMPOUND_STRING("Je veux la collection de films\ndu monde."),
    COMPOUND_STRING("Je vais vous ménager."),
    COMPOUND_STRING("J'ai l'air coriace, non ?"),
    COMPOUND_STRING("Oui ! Mes POKéMON !"),
    COMPOUND_STRING("Oui ! Allez, je suis prête !"),
    COMPOUND_STRING("Vous allez me mettre la pression ?"),
    COMPOUND_STRING("Un combat n'est pas très cool."),
    COMPOUND_STRING("Danger ! Je sens le danger !"),
    COMPOUND_STRING("Barrière ! Maintenant, venez !"),
    COMPOUND_STRING("Je promets de fuir si je perds."),
    COMPOUND_STRING("C'est tendance, un combat, non ?"),
    COMPOUND_STRING("Le soleil du matin me rend fort."),
    COMPOUND_STRING("Je fais les choses à mon rythme."),
    COMPOUND_STRING("Vous ne devriez pas lambiner."),
    COMPOUND_STRING("Rien de tout ça n'a de sens."),
    COMPOUND_STRING("J'adore cette adorable idole\ntélé !"),
    COMPOUND_STRING("Ma fabuleuse mignonnerie est\nà la mode.")
};
#endif

void static (*const sFallarborTentFuncs[])(void) =
{
    [FALLARBOR_TENT_FUNC_INIT]              = InitFallarborTentChallenge,
    [FALLARBOR_TENT_FUNC_GET_PRIZE]         = GetFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_SET_PRIZE]         = SetFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_SAVE]              = SaveFallarborTentChallenge,
    [FALLARBOR_TENT_FUNC_SET_RANDOM_PRIZE]  = SetRandomFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_GIVE_PRIZE]        = GiveFallarborTentPrize,
    [FALLARBOR_TENT_FUNC_GET_OPPONENT_NAME] = BufferFallarborTentTrainerName
};

static const u16 sFallarborTentRewards[] = {ITEM_HYPER_POTION};

void static (*const sSlateportTentFuncs[])(void) =
{
    [SLATEPORT_TENT_FUNC_INIT]                   = InitSlateportTentChallenge,
    [SLATEPORT_TENT_FUNC_GET_PRIZE]              = GetSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SET_PRIZE]              = SetSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SAVE]                   = SaveSlateportTentChallenge,
    [SLATEPORT_TENT_FUNC_SET_RANDOM_PRIZE]       = SetRandomSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_GIVE_PRIZE]             = GiveSlateportTentPrize,
    [SLATEPORT_TENT_FUNC_SELECT_RENT_MONS]       = SelectInitialRentalMons,
    [SLATEPORT_TENT_FUNC_SWAP_RENT_MONS]         = SwapRentalMons,
    [SLATEPORT_TENT_FUNC_GENERATE_OPPONENT_MONS] = GenerateOpponentMons,
    [SLATEPORT_TENT_FUNC_GENERATE_RENTAL_MONS]   = GenerateInitialRentalMons
};

static const u16 sSlateportTentRewards[] = {ITEM_FULL_HEAL};

// code
void CallVerdanturfTentFunction(void)
{
    sVerdanturfTentFuncs[gSpecialVar_0x8004]();
}

static void InitVerdanturfTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetVerdanturfTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.verdanturfTentPrize;
}

static void SetVerdanturfTentPrize(void)
{
    gSaveBlock2Ptr->frontier.verdanturfTentPrize = gSpecialVar_0x8006;
}

static void SetVerdanturfTentTrainerGfx(void)
{
    TRAINER_BATTLE_PARAM.opponentA = (u32)((Random() % 255) * 5) / 64;
    SetBattleFacilityTrainerGfxId(TRAINER_BATTLE_PARAM.opponentA, 0);
}

static void BufferVerdanturfTentTrainerIntro(void)
{
#if IS_HNS
    if (TRAINER_BATTLE_PARAM.opponentA < NUM_BATTLE_TENT_TRAINERS)
    {
        const u8 *const *introTexts = sVerdanturfTentIntroTextsHns;

        switch (VarGet(VAR_FRONTIER_FACILITY))
        {
        case FRONTIER_FACILITY_FACTORY:
            introTexts = sSlateportTentIntroTextsHns;
            break;
        case FRONTIER_FACILITY_ARENA:
            introTexts = sFallarborTentIntroTextsHns;
            break;
        }
        StringCopy(gStringVar4, introTexts[TRAINER_BATTLE_PARAM.opponentA]);
    }
#else
    if (TRAINER_BATTLE_PARAM.opponentA < FRONTIER_TRAINERS_COUNT)
        FrontierSpeechToString(gFacilityTrainers[TRAINER_BATTLE_PARAM.opponentA].speechBefore);
#endif
}

static void SaveVerdanturfTentChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomVerdanturfTentPrize(void)
{
    gSaveBlock2Ptr->frontier.verdanturfTentPrize = sVerdanturfTentRewards[Random() % ARRAY_COUNT(sVerdanturfTentRewards)];
}

static void GiveVerdanturfTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.verdanturfTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.verdanturfTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.verdanturfTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void CallFallarborTentFunction(void)
{
    sFallarborTentFuncs[gSpecialVar_0x8004]();
}

static void InitFallarborTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetFallarborTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.fallarborTentPrize;
}

static void SetFallarborTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fallarborTentPrize = gSpecialVar_0x8006;
}

static void SaveFallarborTentChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomFallarborTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fallarborTentPrize = sFallarborTentRewards[Random() % ARRAY_COUNT(sFallarborTentRewards)];
}

static void GiveFallarborTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.fallarborTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.fallarborTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.fallarborTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void BufferFallarborTentTrainerName(void)
{
    GetFrontierTrainerName(gStringVar1, TRAINER_BATTLE_PARAM.opponentA);
}

void CallSlateportTentFunction(void)
{
    sSlateportTentFuncs[gSpecialVar_0x8004]();
}

static void InitSlateportTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetSlateportTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.slateportTentPrize;
}

static void SetSlateportTentPrize(void)
{
    gSaveBlock2Ptr->frontier.slateportTentPrize = gSpecialVar_0x8006;
}

static void SaveSlateportTentChallenge(void)
{
    ClearEnemyPartyAfterChallenge();
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetRandomSlateportTentPrize(void)
{
    gSaveBlock2Ptr->frontier.slateportTentPrize = sSlateportTentRewards[Random() % ARRAY_COUNT(sSlateportTentRewards)];
}

static void GiveSlateportTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.slateportTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.slateportTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.slateportTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void SelectInitialRentalMons(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

bool8 InSlateportBattleTent(void)
{
    return gMapHeader.regionMapSectionId == MAPSEC_SLATEPORT_CITY
           && (gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_CORRIDOR || gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_BATTLE_ROOM);
}

static void GenerateInitialRentalMons(void)
{
    s32 i, j;
    u8 firstMonId;
    u16 monSetId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    firstMonId = 0;
    gFacilityTrainers = gSlateportBattleTentTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    gFacilityTrainerMons = gSlateportBattleTentMons;
    currSpecies = SPECIES_NONE;
    i = 0;
    while (i != PARTY_SIZE)
    {
        // Cannot have two Pokémon of the same species.
        monSetId = Random() % NUM_SLATEPORT_TENT_MONS;
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            if (monIds[j] == monSetId)
                break;
            if (species[j] == gFacilityTrainerMons[monSetId].species)
            {
                if (currSpecies == SPECIES_NONE)
                    currSpecies = gFacilityTrainerMons[monSetId].species;
                else
                    break;
            }
        }
        if (j != i + firstMonId)
            continue;

        // Cannot have two same held items.
        for (j = firstMonId; j < i + firstMonId; j++)
        {
            if (heldItems[j] != 0 && heldItems[j] == gFacilityTrainerMons[monSetId].heldItem)
            {
                if (gFacilityTrainerMons[monSetId].species == currSpecies)
                    currSpecies = SPECIES_NONE;
                break;
            }
        }
        if (j != i + firstMonId)
            continue;

        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monSetId;
        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gFacilityTrainerMons[monSetId].heldItem;
        monIds[i] = monSetId;
        i++;
    }
}

static void GenerateOpponentMons(void)
{
    u16 trainerId;
    s32 i, j, k;
    const u16 *monSet;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    s32 numMons = 0;

    gFacilityTrainers = gSlateportBattleTentTrainers;
    gFacilityTrainerMons = gSlateportBattleTentMons;

    while (1)
    {
        do
        {
            // Choose a random trainer, ensuring no repeats in this challenge
            trainerId = Random() % NUM_BATTLE_TENT_TRAINERS;
            for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
            {
                if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                    break;
            }
        } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

        TRAINER_BATTLE_PARAM.opponentA = trainerId;
        monSet = gFacilityTrainers[TRAINER_BATTLE_PARAM.opponentA].monSet;
        while (monSet[numMons] != 0xFFFF)
            numMons++;
        if (numMons > 8)
            break;
        numMons = 0;
    }

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < TENT_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = TRAINER_BATTLE_PARAM.opponentA;

    monSet = gFacilityTrainers[TRAINER_BATTLE_PARAM.opponentA].monSet;
    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        sRandMonId = monSet[Random() % numMons];

        // Ensure none of the opponent's Pokémon are the same as the potential rental Pokémon for the player
        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (gFacilityTrainerMons[sRandMonId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        // Ensure this species hasn't already been chosen for the opponent
        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[sRandMonId].species)
                break;
        }
        if (k != i)
            continue;

        // Ensure held items don't repeat on the opponent's team
        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gFacilityTrainerMons[sRandMonId].heldItem)
                break;
        }
        if (k != i)
            continue;

        // Successful selection
        species[i] = gFacilityTrainerMons[sRandMonId].species;
        heldItems[i] = gFacilityTrainerMons[sRandMonId].heldItem;
        gFrontierTempParty[i] = sRandMonId;
        i++;
    }
}
