Warning: truncated output (original token count: 64987)
Total output lines: 6518

#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "challenge_menu.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_end_turn.h"
#include "battle_hold_effects.h"
#include "battle_interface.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_pyramid.h"
#include "battle_scripts.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "battle_gimmick.h"
#include "berry.h"
#include "bg.h"
#include "data.h"
#include "debug.h"
#include "decompress.h"
#include "dexnav.h"
#include "dma3.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "frontier_util.h"
#include "field_weather.h"
#include "follower_npc.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokerus.h"
#include "random.h"
#include "randomizer.h"
#include "nuzlocke.h"
#include "recorded_battle.h"
#include "roamer.h"
#include "safari_zone.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "test/battle.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_pools.h"
#include "trig.h"
#include "tv.h"
#include "util.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_partner.h"
#include "constants/battle_setup.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainer_slide.h"
#include "constants/trainers.h"
#include "constants/weather.h"
#include "cable_club.h"
#include "test/test_runner_battle.h"

extern const struct BgTemplate gBattleBgTemplates[];
extern const struct WindowTemplate *const gBattleWindowTemplates[];

static void CB2_InitBattleInternal(void);
static void CB2_PreInitMultiBattle(void);
static void CB2_PreInitIngamePlayerPartnerBattle(void);
static void CB2_HandleStartMultiPartnerBattle(void);
static void CB2_HandleStartMultiBattle(void);
static void CB2_HandleStartBattle(void);
static void TryCorrectShedinjaLanguage(struct Pokemon *mon);
static u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer);
static void BattleMainCB1(void);
static void CB2_EndLinkBattle(void);
static void EndLinkBattleInSteps(void);
static void CB2_InitAskRecordBattle(void);
static void CB2_AskRecordBattle(void);
static void AskRecordBattle(void);
static void SpriteCB_MoveWildMonToRight(struct Sprite *sprite);
static void SpriteCB_WildMonShowHealthbox(struct Sprite *sprite);
static void SpriteCB_WildMonAnimate(struct Sprite *sprite);
static void SpriteCB_AnimFaintOpponent(struct Sprite *sprite);
void SpriteCB_BlinkVisible(struct Sprite *sprite);
static void SpriteCB_Idle(struct Sprite *sprite);
static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite);
static void TurnValuesCleanUp(bool8 var0);
static void SpriteCB_BounceEffect(struct Sprite *sprite);
static void BattleStartClearSetData(void);
static void DoBattleIntro(void);
static void TryDoEventsBeforeFirstTurn(void);
static void HandleTurnActionSelectionState(void);
static void RunTurnActionsFunctions(void);
static void SetActionsAndBattlersTurnOrder(void);
static void UpdateBattlerPartyOrdersOnSwitch(enum BattlerId battler);
static bool8 AllAtActionConfirmed(void);
static void TryChangeTurnOrder(void);
static void TryChangingTurnOrderEffects(struct BattleCalcValues *calcValues, u32 *quickClawRandom, u32 *quickDrawRandom);
static void CheckChangingTurnOrderEffects(void);
static void FreeResetData_ReturnToOvOrDoEvolutions(void);
static void ReturnFromBattleToOverworld(void);
static void TryEvolvePokemon(void);
static void WaitForEvoSceneToFinish(void);
static void HandleEndTurn_ContinueBattle(void);
static void HandleEndTurn_BattleWon(void);
static void HandleEndTurn_BattleLost(void);
static void HandleEndTurn_RanFromBattle(void);
static void HandleEndTurn_MonFled(void);
static void HandleEndTurn_FinishBattle(void);
static u32 Crc32B (const u8 *data, u32 size);
static u32 GeneratePartyHash(const struct Trainer *trainer, u32 i);

EWRAM_DATA u16 gBattle_BG0_X = 0;
EWRAM_DATA u16 gBattle_BG0_Y = 0;
EWRAM_DATA u16 gBattle_BG1_X = 0;
EWRAM_DATA u16 gBattle_BG1_Y = 0;
EWRAM_DATA u16 gBattle_BG2_X = 0;
EWRAM_DATA u16 gBattle_BG2_Y = 0;
EWRAM_DATA u16 gBattle_BG3_X = 0;
EWRAM_DATA u16 gBattle_BG3_Y = 0;
EWRAM_DATA u16 gBattle_WIN0H = 0;
EWRAM_DATA u16 gBattle_WIN0V = 0;
EWRAM_DATA u16 gBattle_WIN1H = 0;
EWRAM_DATA u16 gBattle_WIN1V = 0;
EWRAM_DATA u8 gDisplayedStringBattle[425] = {0}; // Increased in size to fit Juan's defeat text (SootopolisCity_Gym_1F_Text_JuanDefeat)
EWRAM_DATA u8 gBattleTextBuff1[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff2[TEXT_BUFF_ARRAY_COUNT] = {0};
EWRAM_DATA u8 gBattleTextBuff3[TEXT_BUFF_ARRAY_COUNT + 13] = {0};   // expanded for stupidly long z move names
EWRAM_DATA u32 gBattleTypeFlags = 0;
EWRAM_DATA u8 gBattleEnvironment = 0;
EWRAM_DATA struct MultiPartnerMenuPokemon gMultiPartnerParty[MULTI_PARTY_SIZE] = {0};
EWRAM_DATA static struct MultiPartnerMenuPokemon *sMultiPartnerPartyBuffer = NULL;
EWRAM_DATA u8 *gBattleAnimBgTileBuffer = NULL;
EWRAM_DATA u8 *gBattleAnimBgTilemapBuffer = NULL;
EWRAM_DATA u32 gBattleControllerExecFlags = 0;
EWRAM_DATA u8 gBattlersCount = 0;
EWRAM_DATA u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerPositions[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gActionsByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA enum BattlerId gBattlerByTurnOrder[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA enum BattlerId gBattlersBySpeed[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrentTurnActionNumber = 0;
EWRAM_DATA u8 gCurrentActionFuncId = 0;
EWRAM_DATA struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerSpriteIds[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gCurrMovePos = 0;
EWRAM_DATA u8 gChosenMovePos = 0;
EWRAM_DATA u16 gCurrentMove = 0;
EWRAM_DATA u16 gChosenMove = 0;
EWRAM_DATA u16 gCalledMove = 0;
EWRAM_DATA s32 gBideDmg[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedItem = 0;
EWRAM_DATA enum Ability gLastUsedAbility = 0;
EWRAM_DATA enum BattlerId gBattlerAttacker = 0;
EWRAM_DATA enum BattlerId gBattlerTarget = 0;
EWRAM_DATA enum BattlerId gBattlerFainted = 0;
EWRAM_DATA enum BattlerId gEffectBattler = 0;
EWRAM_DATA enum BattlerId gPotentialItemEffectBattler = 0;
EWRAM_DATA u8 gAbsentBattlerFlags = 0;
EWRAM_DATA u8 gMultiHitCounter = 0;
EWRAM_DATA const u8 *gBattlescriptCurrInstr = NULL;
EWRAM_DATA u8 gChosenActionByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA const u8 *gSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA const u8 *gPalaceSelectionBattleScripts[MAX_BATTLERS_COUNT] = {NULL};
EWRAM_DATA u16 gLastPrintedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastLandedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastHitByType[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedMoveType[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastResultingMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLockedMoves[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gLastUsedMove = 0;
EWRAM_DATA u8 gLastHitBy[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gChosenMoveByBattler[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u32 gHitMarker = 0;
EWRAM_DATA u8 gBideTarget[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u32 gSideStatuses[NUM_BATTLE_SIDES] = {0};
EWRAM_DATA struct SideTimer gSideTimers[NUM_BATTLE_SIDES] = {0};
EWRAM_DATA u16 gPauseCounterBattle = 0;
EWRAM_DATA u16 gPaydayMoney = 0;
EWRAM_DATA u8 gBattleCommunication[BATTLE_COMMUNICATION_ENTRIES_COUNT] = {0};
EWRAM_DATA u8 gBattleOutcome = 0;
EWRAM_DATA struct ProtectStruct gProtectStructs[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct SpecialStatus gSpecialStatuses[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u16 gBattleWeather = 0;
EWRAM_DATA u16 gIntroSlideFlags = 0;
EWRAM_DATA u8 gSentPokesToOpponent[2] = {0};
EWRAM_DATA struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleScripting gBattleScripting = {0};
EWRAM_DATA struct BattleStruct *gBattleStruct = NULL;
EWRAM_DATA struct StartingStatuses gStartingStatuses = {0};
EWRAM_DATA struct AiThinkingStruct *gAiThinkingStruct = NULL;
EWRAM_DATA struct AiLogicData *gAiLogicData = NULL;
EWRAM_DATA struct AiPartyData *gAiPartyData = NULL;
EWRAM_DATA struct BattleHistory *gBattleHistory = NULL;
EWRAM_DATA struct AiBattleData *gAiBattleData = NULL;

EWRAM_DATA u8 *gLinkBattleSendBuffer = NULL;
EWRAM_DATA u8 *gLinkBattleRecvBuffer = NULL;
EWRAM_DATA struct BattleResources *gBattleResources = NULL;
EWRAM_DATA u8 gActionSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gMoveSelectionCursor[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerStatusSummaryTaskId[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gBattlerInMenuId = 0;
EWRAM_DATA bool8 gDoingBattleAnim = FALSE;
EWRAM_DATA u32 gTransformedPersonalities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA bool8 gTransformedShininess[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gPlayerDpadHoldFrames = 0;
EWRAM_DATA struct BattleSpriteData *gBattleSpritesDataPtr = NULL;
EWRAM_DATA struct MonSpritesGfx *gMonSpritesGfxPtr = NULL;
EWRAM_DATA u16 gBattleMovePower = 0;
EWRAM_DATA u16 gMoveToLearn = 0;
EWRAM_DATA u32 gFieldStatuses = 0;
EWRAM_DATA struct FieldTimer gFieldTimers = {0};
EWRAM_DATA u16 gBattleTurnCounter = 0;
EWRAM_DATA enum BattlerId gBattlerAbility = 0;
EWRAM_DATA struct QueuedStatBoost gQueuedStatBoosts[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA bool8 gHasFetchedBall = FALSE;
EWRAM_DATA u16 gLastUsedBall = 0;
EWRAM_DATA u16 gLastThrownBall = 0;
EWRAM_DATA u16 gBallToDisplay = 0;
EWRAM_DATA bool8 gLastUsedBallMenuPresent = FALSE;
EWRAM_DATA u8 gPartyCriticalHits[PARTY_SIZE] = {0};
EWRAM_DATA static u8 sTriedEvolving = 0;
EWRAM_DATA u8 gCategoryIconSpriteId = 0;

COMMON_DATA MainCallback gPreBattleCallback1 = NULL;
COMMON_DATA void (*gBattleMainFunc)(void) = NULL;
COMMON_DATA struct BattleResults gBattleResults = {0};
COMMON_DATA u8 gLeveledUpInBattle = 0;
COMMON_DATA u8 gHealthboxSpriteIds[MAX_BATTLERS_COUNT] = {0};
COMMON_DATA u8 gMultiUsePlayerCursor = 0;
COMMON_DATA u8 gNumberOfMovesToChoose = 0;

static const struct ScanlineEffectParams sIntroScanlineParams16Bit =
{
    &REG_BG3HOFS, SCANLINE_EFFECT_DMACNT_16BIT, 1
};

// unused
static const struct ScanlineEffectParams sIntroScanlineParams32Bit =
{
    &REG_BG3HOFS, SCANLINE_EFFECT_DMACNT_32BIT, 1
};

static const u8 sText_ShedinjaJpnName[] = _("ヌケニン"); // Nukenin

const struct OamData gOamData_BattleSpriteOpponentSide =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct OamData gOamData_BattleSpritePlayerSide =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 2,
    .affineParam = 0,
};

static const s8 sCenterToCornerVecXs[8] ={-32, -16, -16, -32, -32};

#include "data/types_info.h"

// [TRAINER_CLASS_XYZ] = { _("name"), <money=5>, <ball=BALL_POKE> }
const struct TrainerClass gTrainerClasses[TRAINER_CLASS_COUNT] =
{
    [TRAINER_CLASS_PKMN_TRAINER_1] = { _("{PKMN} TRAINER") },
    [TRAINER_CLASS_PKMN_TRAINER_2] = { _("{PKMN} TRAINER") },
    [TRAINER_CLASS_HIKER] = { _("HIKER"), 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_ULTRA : BALL_POKE },
    [TRAINER_CLASS_TEAM_AQUA] = { _("TEAM AQUA") },
    [TRAINER_CLASS_PKMN_BREEDER] = { _("{PKMN} BREEDER"), 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_HEAL : BALL_FRIEND },
    [TRAINER_CLASS_COOLTRAINER] = { _("COOLTRAINER"), 12, BALL_ULTRA },
    [TRAINER_CLASS_BIRD_KEEPER] = { _("BIRD KEEPER"), 8 },
    [TRAINER_CLASS_COLLECTOR] = { _("COLLECTOR"), 15, BALL_PREMIER },
    [TRAINER_CLASS_SWIMMER_M] = { _("SWIMMER♂"), 2, BALL_DIVE },
    [TRAINER_CLASS_TEAM_MAGMA] = { _("TEAM MAGMA") },
    [TRAINER_CLASS_EXPERT] = { _("EXPERT"), 10 },
    [TRAINER_CLASS_AQUA_ADMIN] = { _("AQUA ADMIN"), 10 },
    [TRAINER_CLASS_BLACK_BELT] = { _("BLACK BELT"), 8, BALL_ULTRA },
    [TRAINER_CLASS_AQUA_LEADER] = { _("AQUA LEADER"), 20, BALL_MASTER },
    [TRAINER_CLASS_HEX_MANIAC] = { _("HEX MANIAC"), 6 },
    [TRAINER_CLASS_AROMA_LADY] = { _("AROMA LADY"), 10 },
    [TRAINER_CLASS_RUIN_MANIAC] = { _("RUIN MANIAC"), 15 },
    [TRAINER_CLASS_INTERVIEWER] = { _("INTERVIEWER"), 12 },
    [TRAINER_CLASS_TUBER_F] = { _("TUBER"), 1 },
    [TRAINER_CLASS_TUBER_M] = { _("TUBER"), 1 },
    [TRAINER_CLASS_LADY] = { _("LADY"), 50 },
    [TRAINER_CLASS_BEAUTY] = { _("BEAUTY"), 20, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_GREAT : BALL_POKE },
    [TRAINER_CLASS_RICH_BOY] = { _("RICH BOY"), 50 },
    [TRAINER_CLASS_POKEMANIAC] = { _("POKéMANIAC"), 15 },
    [TRAINER_CLASS_GUITARIST] = { _("GUITARIST"), 8 },
    [TRAINER_CLASS_KINDLER] = { _("KINDLER"), 8 },
    [TRAINER_CLASS_CAMPER] = { _("CAMPER"), 4 },
    [TRAINER_CLASS_PICNICKER] = { _("PICNICKER"), 4 },
    [TRAINER_CLASS_BUG_MANIAC] = { _("BUG MANIAC"), 15 },
    [TRAINER_CLASS_PSYCHIC] = { _("PSYCHIC"), 6 },
    [TRAINER_CLASS_GENTLEMAN] = { _("GENTLEMAN"), 20, BALL_LUXURY },
    [TRAINER_CLASS_ELITE_FOUR] = { _("ELITE FOUR"), 25, BALL_ULTRA },
    [TRAINER_CLASS_LEADER] = { _("LEADER"), 25, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_ULTRA : BALL_POKE },
    [TRAINER_CLASS_SCHOOL_KID] = { _("SCHOOL KID") },
    [TRAINER_CLASS_SR_AND_JR] = { _("SR. AND JR."), 4 },
    [TRAINER_CLASS_WINSTRATE] = { _("WINSTRATE"), 10 },
    [TRAINER_CLASS_POKEFAN] = { _("POKéFAN"), 20 },
    [TRAINER_CLASS_YOUNGSTER] = { _("YOUNGSTER"), 4 },
    [TRAINER_CLASS_CHAMPION] = { _("CHAMPION"), 50, BALL_ULTRA },
    [TRAINER_CLASS_FISHERMAN] = { _("FISHERMAN"), 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_DIVE : BALL_LURE },
    [TRAINER_CLASS_TRIATHLETE] = { _("TRIATHLETE"), 10 },
    [TRAINER_CLASS_DRAGON_TAMER] = { _("DRAGON TAMER"), 12 },
    [TRAINER_CLASS_NINJA_BOY] = { _("NINJA BOY"), 3 },
    [TRAINER_CLASS_BATTLE_GIRL] = { _("BATTLE GIRL"), 6 },
    [TRAINER_CLASS_PARASOL_LADY] = { _("PARASOL LADY"), 10 },
    [TRAINER_CLASS_SWIMMER_F] = { _("SWIMMER♀"), 2, BALL_DIVE },
    [TRAINER_CLASS_TWINS] = { _("TWINS"), 3 },
    [TRAINER_CLASS_SAILOR] = { _("SAILOR"), 8 },
    [TRAINER_CLASS_COOLTRAINER_2] = { _("COOLTRAINER"), 5, BALL_ULTRA },
    [TRAINER_CLASS_MAGMA_ADMIN] = { _("MAGMA ADMIN"), 10 },
    [TRAINER_CLASS_RIVAL] = { _("{PKMN} TRAINER"), 15 },
    [TRAINER_CLASS_BUG_CATCHER] = { _("BUG CATCHER"), 4 },
    [TRAINER_CLASS_PKMN_RANGER] = { _("{PKMN} RANGER"), 12 },
    [TRAINER_CLASS_MAGMA_LEADER] = { _("MAGMA LEADER"), 20, BALL_MASTER },
    [TRAINER_CLASS_LASS] = { _("LASS"), 4 },
    [TRAINER_CLASS_YOUNG_COUPLE] = { _("YOUNG COUPLE"), 8 },
    [TRAINER_CLASS_OLD_COUPLE] = { _("OLD COUPLE"), 10 },
    [TRAINER_CLASS_SIS_AND_BRO] = { _("SIS AND BRO"), 3 },
    [TRAINER_CLASS_SALON_MAIDEN] = { _("SALON MAIDEN"), 5, BALL_ULTRA },
    [TRAINER_CLASS_DOME_ACE] = { _("DOME ACE") },
    [TRAINER_CLASS_PALACE_MAVEN] = { _("PALACE MAVEN") },
    [TRAINER_CLASS_ARENA_TYCOON] = { _("ARENA TYCOON") },
    [TRAINER_CLASS_FACTORY_HEAD] = { _("FACTORY HEAD") },
    [TRAINER_CLASS_PIKE_QUEEN] = { _("PIKE QUEEN") },
    [TRAINER_CLASS_PYRAMID_KING] = { _("PYRAMID KING") },
    [TRAINER_CLASS_RS_PROTAG] = { _("{PKMN} TRAINER") },

    [TRAINER_CLASS_YOUNGSTER_FRLG] =       { _("YOUNGSTER"), 4 },
    [TRAINER_CLASS_BUG_CATCHER_FRLG] =     { _("BUG CATCHER"), 3 },
    [TRAINER_CLASS_LASS_FRLG] =            { _("LASS"), 4 },
    [TRAINER_CLASS_SAILOR_FRLG] =          { _("SAILOR"), 8 },
    [TRAINER_CLASS_CAMPER_FRLG] =          { _("CAMPER"), 5 },
    [TRAINER_CLASS_PICNICKER_FRLG] =       { _("PICNICKER"), 5 },
    [TRAINER_CLASS_POKEMANIAC_FRLG] =      { _("POKéMANIAC"), 12 },
    [TRAINER_CLASS_SUPER_NERD_FRLG] =      { _("SUPER NERD"), 6 },
    [TRAINER_CLASS_HIKER_FRLG] =           { _("HIKER"), 9 },
    [TRAINER_CLASS_BIKER_FRLG] =           { _("BIKER"), 5 },
    [TRAINER_CLASS_BURGLAR_FRLG] =         { _("BURGLAR"), 22 },
    [TRAINER_CLASS_ENGINEER_FRLG] =        { _("ENGINEER"), 12 },
    [TRAINER_CLASS_FISHERMAN_FRLG] =       { _("FISHERMAN"), 9, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_DIVE : BALL_LURE },
    [TRAINER_CLASS_SWIMMER_M_FRLG] =       { _("SWIMMER♂"), 1 },
    [TRAINER_CLASS_CUE_BALL_FRLG] =        { _("CUE BALL"), 6 },
    [TRAINER_CLASS_GAMER_FRLG] =           { _("GAMER"), 18 },
    [TRAINER_CLASS_BEAUTY_FRLG] =          { _("BEAUTY"), 18 },
    [TRAINER_CLASS_SWIMMER_F_FRLG] =       { _("SWIMMER♀"), 1, BALL_DIVE },
    [TRAINER_CLASS_PSYCHIC_FRLG] =         { _("PSYCHIC"), 5 },
    [TRAINER_CLASS_ROCKER_FRLG] =          { _("ROCKER"), 6 },
    [TRAINER_CLASS_JUGGLER_FRLG] =         { _("JUGGLER"), 10 },
    [TRAINER_CLASS_TAMER_FRLG] =           { _("TAMER"), 10 },
    [TRAINER_CLASS_BIRD_KEEPER_FRLG] =     { _("BIRD KEEPER"), 6 },
    [TRAINER_CLASS_BLACK_BELT_FRLG] =      { _("BLACK BELT"), 6, BALL_ULTRA },
    [TRAINER_CLASS_RIVAL_EARLY_FRLG] =     { _("RIVAL"), 4 },
    [TRAINER_CLASS_SCIENTIST_FRLG] =       { _("SCIENTIST"), 12 },
    [TRAINER_CLASS_BOSS_FRLG] =            { _("BOSS"), 25 },
    [TRAINER_CLASS_LEADER_FRLG] =          { _("LEADER"), 25 },
    [TRAINER_CLASS_TEAM_ROCKET_FRLG] =     { _("TEAM ROCKET"), 8 },
    [TRAINER_CLASS_COOLTRAINER_FRLG] =     { _("COOLTRAINER"), 9, BALL_ULTRA },
    [TRAINER_CLASS_ELITE_FOUR_FRLG] =      { _("ELITE FOUR"), 25, BALL_ULTRA },
    [TRAINER_CLASS_GENTLEMAN_FRLG] =       { _("GENTLEMAN"), 18, BALL_LUXURY },
    [TRAINER_CLASS_RIVAL_LATE_FRLG] =      { _("RIVAL"), 9 },
    [TRAINER_CLASS_CHAMPION_FRLG] =        { _("CHAMPION"), 25 },
    [TRAINER_CLASS_CHANNELER_FRLG] =       { _("CHANNELER"), 8 },
    [TRAINER_CLASS_TWINS_FRLG] =           { _("TWINS"), 3 },
    [TRAINER_CLASS_COOL_COUPLE_FRLG] =     { _("COOL COUPLE"), 6 },
    [TRAINER_CLASS_YOUNG_COUPLE_FRLG] =    { _("YOUNG COUPLE"), 7 },
    [TRAINER_CLASS_CRUSH_KIN_FRLG] =       { _("CRUSH KIN"), 6 },
    [TRAINER_CLASS_SIS_AND_BRO_FRLG] =     { _("SIS AND BRO"), 1 },
    [TRAINER_CLASS_PKMN_PROF_FRLG] =       { _("{PKMN} PROF."), 25 },
    [TRAINER_CLASS_PLAYER_FRLG] =          { _("{PKMN} TRAINER"), 1 },
    [TRAINER_CLASS_CRUSH_GIRL_FRLG] =      { _("CRUSH GIRL"), 6 },
    [TRAINER_CLASS_TUBER_FRLG] =           { _("TUBER"), 1 },
    [TRAINER_CLASS_PKMN_BREEDER_FRLG] =    { _("{PKMN} BREEDER"), 7, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_HEAL : BALL_FRIEND },
    [TRAINER_CLASS_PKMN_RANGER_FRLG] =     { _("{PKMN} RANGER"), 9 },
    [TRAINER_CLASS_AROMA_LADY_FRLG] =      { _("AROMA LADY"), 7 },
    [TRAINER_CLASS_RUIN_MANIAC_FRLG] =     { _("RUIN MANIAC"), 12 },
    [TRAINER_CLASS_LADY_FRLG] =            { _("LADY"), 50 },
    [TRAINER_CLASS_PAINTER_FRLG] =         { _("PAINTER"), 4 },

    // HnS Trainer Classes
    [TRAINER_CLASS_ARENA_TYCOON_HNS] =     { _("MAGNAT ARÈNE") },
    [TRAINER_CLASS_BATTLE_GIRL_HNS] =      { _("COMBATTANTE"), 6 },
    [TRAINER_CLASS_BEAUTY_HNS] =           { _("CANON"), 20 },
    [TRAINER_CLASS_BIKER_HNS] =            { _("MOTARD") },
    [TRAINER_CLASS_BIRD_KEEPER_HNS] =      { _("ORNITHOLOGUE"), 8 },
    [TRAINER_CLASS_BLACK_BELT_HNS] =       { _("KARATÉKA"), 8, BALL_ULTRA },
    [TRAINER_CLASS_BUG_CATCHER_HNS] =      { _("SCOUT"), 4 },
    [TRAINER_CLASS_BURGLAR_HNS] =          { _("CAMBRIOLEUR") },
    [TRAINER_CLASS_CAMPER_HNS] =           { _("CAMPEUR"), 4 },
    [TRAINER_CLASS_CHAMPION_HNS] =         { _("CHAMPION"), 50, BALL_ULTRA },
    [TRAINER_CLASS_COLLECTOR_HNS] =        { _("COLLECTEUR"), 15, BALL_PREMIER },
    [TRAINER_CLASS_COOLTRAINER_HNS] =      { _("TOPDRESSEUR"), 12, BALL_ULTRA },
    [TRAINER_CLASS_DOME_ACE_HNS] =         { _("AS DU DÔME") },
    [TRAINER_CLASS_DRAGON_TAMER_HNS] =     { _("DRACOLOGUE"), 12 },
    [TRAINER_CLASS_ELITE_FOUR_HNS] =       { _("CONSEIL 4"), 25, BALL_ULTRA },
    [TRAINER_CLASS_EXPERT_HNS] =           { _("EXPERT"), 10 },
    [TRAINER_CLASS_FACTORY_HEAD_HNS] =     { _("CHEF USINE") },
    [TRAINER_CLASS_FIREBREATHER_HNS] =     { _("CRACHE-FEU") },
    [TRAINER_CLASS_FISHERMAN_HNS] =        { _("PÊCHEUR"), 10, B_TRAINER_CLASS_POKE_BALLS >= GEN_8 ? BALL_DIVE : BALL_LURE },
    [TRAINER_CLASS_GENTLEMAN_HNS] =        { _("GENTLEMAN"), 20, BALL_LUXURY },
    [TRAINER_CLASS_GUITARIST_HNS] =        { _("GUITARISTE"), 8 },
    [TRAINER_CLASS_HEX_MANIAC_HNS] =       { _("MYSTIMANIAC"), 6 },
    [TRAINER_CLASS_HIKER_HNS] =            { _("MONTAGNARD"), 10 },
    [TRAINER_CLASS_JUGGLER_HNS] =          { _("JONGLEUR") },
    [TRAINER_CLASS_KIMONO_GIRL_HNS] =      { _("FILLE KIMONO") },
    [TRAINER_CLASS_LASS_HNS] =             { _("FILLETTE"), 4 },
    [TRAINER_CLASS_LEADER_HNS] =           { _("CHAMPION"), 25 },
    [TRAINER_CLASS_LEADER_KANTO_HNS] =     { _("CHAMPION"), 25 },
    [TRAINER_CLASS_MYSTERY_MAN_HNS] =      { _("MYSTIQUE") },
    [TRAINER_CLASS_OFFICER_HNS] =          { _("AGENT") },
    [TRAINER_CLASS_PALACE_MAVEN_HNS] =     { _("GUIDE PALAIS") },
    [TRAINER_CLASS_PARASOL_LADY_HNS] =     { _("MISS PARASOL"), 10 },
    [TRAINER_CLASS_PICNICKER_HNS] =        { _("PIQUE-NIQUE"), 4 },
    [TRAINER_CLASS_PIKE_QUEEN_HNS] =       { _("REINE PIKE") },
    [TRAINER_CLASS_PKMN_TRAINER_1_HNS] =   { _("DRES. {PKMN}") },
    [TRAINER_CLASS_POKEFAN_HNS] =          { _("POKéFAN"), 20 },
    [TRAINER_CLASS_POKEMANIAC_HNS] =       { _("POKéMANIAC"), 15 },
    [TRAINER_CLASS_PSYCHIC_HNS] =          { _("KINÉSISTE"), 6 },
    [TRAINER_CLASS_PSYCHIC_M_HNS] =        { _("KINÉSISTE"), 6 },
    [TRAINER_CLASS_RIVAL_HNS] =            { _("RIVAL"), 15 },
    [TRAINER_CLASS_ROCKET_ADMIN_HNS] =     { _("CADRE ROCKET") },
    [TRAINER_CLASS_SAGE_HNS] =             { _("SAGE") },
    [TRAINER_CLASS_SAILOR_HNS] =           { _("MARIN"), 8 },
    [TRAINER_CLASS_SALON_MAIDEN_HNS] =     { _("AS DU SALON"), 5, BALL_ULTRA },
    [TRAINER_CLASS_SCHOOL_KID_HNS] =       { _("ÉCOLIER") },
    [TRAINER_CLASS_SKIER_HNS] =            { _("SKIEUR"), 10 },
    [TRAINER_CLASS_SUPER_NERD_HNS] =       { _("INTELLO"), 8 },
    [TRAINER_CLASS_SWIMMER_F_HNS] =        { _("NAGEUSE♀"), 2, BALL_DIVE },
    [TRAINER_CLASS_SWIMMER_M_HNS] =        { _("NAGEUR♂"), 2, BALL_DIVE },
    [TRAINER_CLASS_TEAM_ROCKET_HNS] =      { _("ROCKET") },
    [TRAINER_CLASS_TWINS_HNS] =            { _("JUMELLES"), 3 },
    [TRAINER_CLASS_YOUNG_COUPLE_HNS] =     { _("JEUNE COUPLE"), 8 },
    [TRAINER_CLASS_YOUNGSTER_HNS] =        { _("GAMIN"), 4 },
    [TRAINER_CLASS_PROFESSOR_HNS] =        { _("{PKMN} PROF."), 25, BALL_FRIEND},
    [TRAINER_CLASS_DEVELOPER_HNS] =        { _("DÉVELOPPEUR"), 50, BALL_MASTER},
    [TRAINER_CLASS_PYRAMID_KING_HNS] =     { _("ROI PYRAMIDE") },
};

static void (*const sTurnActionsFuncsTable[])(void) =
{
    [B_ACTION_USE_MOVE]               = HandleAction_UseMove,
    [B_ACTION_USE_ITEM]               = HandleAction_UseItem,
    [B_ACTION_SWITCH]                 = HandleAction_Switch,
    [B_ACTION_RUN]                    = HandleAction_Run,
    [B_ACTION_SAFARI_WATCH_CAREFULLY] = HandleAction_WatchesCarefully,
    [B_ACTION_SAFARI_BALL]            = HandleAction_SafariZoneBallThrow,
    [B_ACTION_SAFARI_POKEBLOCK]       = HandleAction_ThrowPokeblock,
    [B_ACTION_SAFARI_GO_NEAR]         = HandleAction_GoNear,
    [B_ACTION_SAFARI_RUN]             = HandleAction_SafariZoneRun,
    [B_ACTION_WALLY_THROW]            = HandleAction_WallyBallThrow,
    [B_ACTION_EXEC_SCRIPT]            = HandleAction_RunBattleScript,
    [B_ACTION_TRY_FINISH]             = HandleAction_TryFinish,
    [B_ACTION_FINISHED]               = HandleAction_ActionFinished,
    [B_ACTION_NOTHING_FAINTED]        = HandleAction_NothingIsFainted,
    [B_ACTION_THROW_BALL]             = HandleAction_ThrowBall,
};

static void (*const sEndTurnFuncsTable[])(void) =
{
    [0]                           = HandleEndTurn_ContinueBattle,
    [B_OUTCOME_WON]               = HandleEndTurn_BattleWon,
    [B_OUTCOME_LOST]              = HandleEndTurn_BattleLost,
    [B_OUTCOME_DREW]              = HandleEndTurn_BattleLost,
    [B_OUTCOME_RAN]               = HandleEndTurn_RanFromBattle,
    [B_OUTCOME_PLAYER_TELEPORTED] = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_FLED]          = HandleEndTurn_MonFled,
    [B_OUTCOME_CAUGHT]            = HandleEndTurn_FinishBattle,
    [B_OUTCOME_NO_SAFARI_BALLS]   = HandleEndTurn_FinishBattle,
    [B_OUTCOME_FORFEITED]         = HandleEndTurn_FinishBattle,
    [B_OUTCOME_MON_TELEPORTED]    = HandleEndTurn_FinishBattle,
};

const u8 gStatusConditionString_PoisonJpn[] = _("どく$$$$$");
const u8 gStatusConditionString_SleepJpn[] = _("ねむり$$$$");
const u8 gStatusConditionString_ParalysisJpn[] = _("まひ$$$$$");
const u8 gStatusConditionString_BurnJpn[] = _("やけど$$$$");
const u8 gStatusConditionString_IceJpn[] = _("こおり$$$$");
const u8 gStatusConditionString_ConfusionJpn[] = _("こんらん$$$");
const u8 gStatusConditionString_LoveJpn[] = _("メロメロ$$$");

const u8 *const gStatusConditionStringsTable[][2] =
{
    {gStatusConditionString_PoisonJpn, gText_Poison},
    {gStatusConditionString_SleepJpn, gText_Sleep},
    {gStatusConditionString_ParalysisJpn, gText_Paralysis},
    {gStatusConditionString_BurnJpn, gText_Burn},
    {gStatusConditionString_IceJpn, gText_Ice},
    {gStatusConditionString_ConfusionJpn, gText_Confusion},
    {gStatusConditionString_LoveJpn, gText_Love}
};

void CB2_InitBattle(void)
{
    if (!gTestRunnerEnabled)
        MoveSaveBlocks_ResetHeap();
    AllocateBattleResources();
    AllocateBattleSpritesData();
    AllocateMonSpritesGfx();
    RecordedBattle_ClearFrontierPassFlag();

#if T_SHOULD_RUN_MOVE_ANIM
    gLoadFail = FALSE;
#endif // T_SHOULD_RUN_MOVE_ANIM

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            CB2_InitBattleInternal();
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        {
            HandleLinkBattleSetup();
            SetMainCallback2(CB2_PreInitMultiBattle);
        }
        else
        {
            SetMainCallback2(CB2_PreInitIngamePlayerPartnerBattle);
        }
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
    else
    {
        CB2_InitBattleInternal();
    }
}

static void CB2_InitBattleInternal(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);

    CpuFill32(0, (void *)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1));
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    gBattle_WIN0H = DISPLAY_WIDTH;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId < TRAINER_PARTNER(PARTNER_NONE))
    {
        gBattle_WIN0V = DISPLAY_HEIGHT - 1;
        gBattle_WIN1H = DISPLAY_WIDTH;
        gBattle_WIN1V = 32;
    }
    else
    {
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
        ScanlineEffect_Clear();
        if (B_FAST_INTRO_NO_SLIDE == FALSE && !gTestRunnerHeadless && gSaveBlock3Ptr->challengeSettings.fastIntro)
        {
            for (i = 0; i < DISPLAY_HEIGHT / 2; i++)
            {
                gScanlineEffectRegBuffers[0][i] = 0xF0;
                gScanlineEffectRegBuffers[1][i] = 0xF0;
            }

            for (; i < DISPLAY_HEIGHT; i++)
            {
                gScanlineEffectRegBuffers[0][i] = 0xFF10;
                gScanlineEffectRegBuffers[1][i] = 0xFF10;
            }

            ScanlineEffect_SetParams(sIntroScanlineParams16Bit);
        }
    }

    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;

    if (!DEBUG_OVERWORLD_MENU || (DEBUG_OVERWORLD_MENU && !gIsDebugBattle))
        gBattleEnvironment = BattleSetup_GetEnvironmentId();
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        gBattleEnvironment = BATTLE_ENVIRONMENT_BUILDING;
    if (TestRunner_Battle_GetForcedEnvironment())
        gBattleEnvironment = TestRunner_Battle_GetForcedEnvironment() - 1;

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ResetTasks();
    if (B_FAST_INTRO_NO_SLIDE == FALSE && !gTestRunnerHeadless && gSaveBlock3Ptr->challengeSettings.fastIntro)
        DrawBattleEntryBackground();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
    SetVBlankCallback(VBlankCB_Battle);
    SetUpBattleVarsAndBirchZigzagoon();

    if ((IsMultibattleTest() && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    || (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    || (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        SetMainCallback2(CB2_HandleStartMultiBattle);
    else
        SetMainCallback2(CB2_HandleStartBattle);

    if (!DEBUG_OVERWORLD_MENU || (DEBUG_OVERWORLD_MENU && !gIsDebugBattle))
    {
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)))
        {
            CreateNPCTrainerParty(&gEnemyParty[0], TRAINER_BATTLE_PARAM.opponentA, TRUE);
            if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                CreateNPCTrainerParty(&gEnemyParty[PARTY_SIZE / 2], TRAINER_BATTLE_PARAM.opponentB, FALSE);
            SetWildMonHeldItem();
            CalculateEnemyPartyCount();

            if (gSaveBlock3Ptr->challengeSettings.tx_Challenges_Mirror
             && (gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE)))
            {
                if (!gSaveBlock3Ptr->challengeSettings.tx_Challenges_Mirror_Thief)
                {
                    for (i = 0; i < PARTY_SIZE; i++)
                        gPlayerPartyBackup[i] = gPlayerParty[i];
                }
                for (i = 0; i < PARTY_SIZE; i++)
                    gPlayerParty[i] = gEnemyParty[i];
            }
        }
    }

    gMain.inBattle = TRUE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        AdjustFriendship(&gPlayerParty[i], FRIENDSHIP_EVENT_LEAGUE_BATTLE);

        // Apply party-wide start-of-battle form changes for both sides.
        TryFormChange(&gPlayerParty[i], FORM_CHANGE_BEGIN_BATTLE);
        TryFormChange(&gEnemyParty[i], FORM_CHANGE_BEGIN_BATTLE);
    }

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
    {
        TryFormChange(&gEnemyParty[0], FORM_CHANGE_BEGIN_WILD_ENCOUNTER);
        if (IsDoubleBattle())
            TryFormChange(&gEnemyParty[1], FORM_CHANGE_BEGIN_WILD_ENCOUNTER);
    }

    #if TESTING
    gPlayerPartyCount = CalculatePartyCount(gPlayerParty);
    gEnemyPartyCount = CalculatePartyCount(gEnemyParty);
    #endif

    gBattleCommunication[MULTIUSE_STATE] = 0;
}

#define BUFFER_PARTY_VS_SCREEN_STATUS(party, flags, i)                      \
    for ((i) = 0; (i) < PARTY_SIZE; (i)++)                                  \
    {                                                                       \
        u16 species = GetMonData(&(party)[(i)], MON_DATA_SPECIES_OR_EGG);   \
        u16 hp = GetMonData(&(party)[(i)], MON_DATA_HP);                    \
        u32 status = GetMonData(&(party)[(i)], MON_DATA_STATUS);            \
                                                                            \
        if (species == SPECIES_NONE)                                        \
            continue;                                                       \
                                                                            \
        /* Is healthy mon? */                                               \
        if (species != SPECIES_EGG && hp != 0 && status == 0)               \
            (flags) |= 1 << (i) * 2;                                        \
                                                                            \
        if (species == SPECIES_NONE) /* Redundant */                        \
            continue;                                                       \
                                                                            \
        /* Is Egg or statused? */                                           \
        if (hp != 0 && (species == SPECIES_EGG || status != 0))             \
            (flags) |= 2 << (i) * 2;                                        \
                                                                            \
        if (species == SPECIES_NONE) /* Redundant */                        \
            continue;                                                       \
                                                                            \
        /* Is fainted? */                                                   \
        if (species != SPECIES_EGG && hp == 0)                              \
            (flags) |= 3 << (i) * 2;                                        \
    }

// For Vs Screen at link battle start
static void BufferPartyVsScreenHealth_AtStart(void)
{
    u16 flags = 0;
    s32 i;

    BUFFER_PARTY_VS_SCREEN_STATUS(gPlayerParty, flags, i);
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsLo = flags;
    *(&gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi) = flags >> 8;
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi |= FlagGet(FLAG_SYS_FRONTIER_PASS) << 7;
}

static void SetPlayerBerryDataInBattleStruct(void)
{
    s32 i;
    struct BattleStruct *battleStruct = gBattleStruct;
    struct BattleEnigmaBerry *battleBerry = &battleStruct->multiBuffer.linkBattlerHeader.battleEnigmaBerry;

    if (IsEnigmaBerryValid() == TRUE)
    {
    #if FREE_ENIGMA_BERRY == FALSE
        for (i = 0; i < BERRY_NAME_LENGTH; i++)
            battleBerry->name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];

        battleBerry->holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        battleBerry->holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
    #endif //FREE_ENIGMA_BERRY
    }
    else
    {
        const struct Berry *berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY_E_READER));

        for (i = 0; i < BERRY_NAME_LENGTH; i++)
            battleBerry->name[i] = berryData->name[i];
        battleBerry->name[i] = EOS;

        for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            battleBerry->itemEffect[i] = 0;

        battleBerry->holdEffect = HOLD_EFFECT_NONE;
        battleBerry->holdEffectParam = 0;
    }
}

static void SetAllPlayersBerryData(void)
{
    s32 i, j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        if (IsEnigmaBerryValid() == TRUE)
        {
        #if FREE_ENIGMA_BERRY == FALSE
            for (i = 0; i < BERRY_NAME_LENGTH; i++)
            {
                gEnigmaBerries[0].name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
                gEnigmaBerries[2].name[i] = gSaveBlock1Ptr->enigmaBerry.berry.name[i];
            }
            gEnigmaBerries[0].name[i] = EOS;
            gEnigmaBerries[2].name[i] = EOS;

            for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            {
                gEnigmaBerries[0].itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];
                gEnigmaBerries[2].itemEffect[i] = gSaveBlock1Ptr->enigmaBerry.itemEffect[i];
            }

            gEnigmaBerries[0].holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            gEnigmaBerries[2].holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            gEnigmaBerries[0].holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
            gEnigmaBerries[2].holdEffectParam = gSaveBlock1Ptr->enigmaBerry.holdEffectParam;
        #endif //FREE_ENIGMA_BERRY
        }
        else
        {
            const struct Berry *berryData = GetBerryInfo(ItemIdToBerryType(ITEM_ENIGMA_BERRY_E_READER));

            for (i = 0; i < BERRY_NAME_LENGTH; i++)
            {
                gEnigmaBerries[0].name[i] = berryData->name[i];
                gEnigmaBerries[2].name[i] = berryData->name[i];
            }
            gEnigmaBerries[0].name[i] = EOS;
            gEnigmaBerries[2].name[i] = EOS;

            for (i = 0; i < BERRY_ITEM_EFFECT_COUNT; i++)
            {
                gEnigmaBerries[0].itemEffect[i] = 0;
                gEnigmaBerries[2].itemEffect[i] = 0;
            }

            gEnigmaBerries[0].holdEffect = HOLD_EFFECT_NONE;
            gEnigmaBerries[2].holdEffect = HOLD_EFFECT_NONE;
            gEnigmaBerries[0].holdEffectParam = 0;
            gEnigmaBerries[2].holdEffectParam = 0;
        }
    }
    else
    {
        s32 numPlayers;
        struct BattleEnigmaBerry *src;
        enum BattlerId battler;

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                numPlayers = 2;
            else
                numPlayers = 4;

            for (i = 0; i < numPlayers; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);
                battler = gLinkPlayers[i].id;

                for (j = 0; j < BERRY_NAME_LENGTH; j++)
                    gEnigmaBerries[battler].name[j] = src->name[j];
                gEnigmaBerries[battler].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                    gEnigmaBerries[battler].itemEffect[j] = src->itemEffect[j];

                gEnigmaBerries[battler].holdEffect = src->holdEffect;
                gEnigmaBerries[battler].holdEffectParam = src->holdEffectParam;
            }
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                src = (struct BattleEnigmaBerry *)(gBlockRecvBuffer[i] + 2);

                for (j = 0; j < BERRY_NAME_LENGTH; j++)
                {
                    gEnigmaBerries[i].name[j] = src->name[j];
                    gEnigmaBerries[i + 2].name[j] = src->name[j];
                }
                gEnigmaBerries[i].name[j] = EOS;
                gEnigmaBerries[i + 2].name[j] = EOS;

                for (j = 0; j < BERRY_ITEM_EFFECT_COUNT; j++)
                {
                    gEnigmaBerries[i].itemEffect[j] = src->itemEffect[j];
                    gEnigmaBerries[i + 2].itemEffect[j] = src->itemEffect[j];
                }

                gEnigmaBerries[i].holdEffect = src->holdEffect;
                gEnigmaBerries[i + 2].holdEffect = src->holdEffect;
                gEnigmaBerries[i].holdEffectParam = src->holdEffectParam;
                gEnigmaBerries[i + 2].holdEffectParam = src->holdEffectParam;
            }
        }
    }
}

// This was inlined in Ruby/Sapphire
static void FindLinkBattleMaster(u8 numPlayers, u8 multiPlayerId)
{
    u8 found = 0;

    // If player 1 is playing the minimum version, player 1 is mas…44987 tokens truncated…          SwapTurnOrder(i, j);
            }
        }
    }
}

static void TryChangingTurnOrderEffects(struct BattleCalcValues *calcValues, u32 *quickClawRandom, u32 *quickDrawRandom)
{
    enum BattlerId battler1 = calcValues->battlerAtk;
    enum BattlerId battler2 = calcValues->battlerDef;
    enum Ability ability1 = calcValues->abilities[calcValues->battlerAtk];
    enum Ability ability2 = calcValues->abilities[calcValues->battlerDef];
    enum HoldEffect holdEffectBattler1 = calcValues->holdEffects[calcValues->battlerAtk];
    enum HoldEffect holdEffectBattler2 = calcValues->holdEffects[calcValues->battlerDef];

    // Battler 1
    // Quick Draw
    if (ability1 == ABILITY_QUICK_DRAW && !IsBattleMoveStatus(gChosenMoveByBattler[battler1]) && quickDrawRandom[battler1])
        gProtectStructs[battler1].quickDraw = TRUE;
    // Quick Claw and Custap Berry
    if (!gProtectStructs[battler1].quickDraw
     && ((holdEffectBattler1 == HOLD_EFFECT_QUICK_CLAW && quickClawRandom[battler1])
     || (holdEffectBattler1 == HOLD_EFFECT_CUSTAP_BERRY && HasEnoughHpToEatBerry(battler1, ability1, 4, gBattleMons[battler1].item))))
        gProtectStructs[battler1].usedCustapBerry = TRUE;

    // Battler 2
    // Quick Draw
    if (ability2 == ABILITY_QUICK_DRAW && !IsBattleMoveStatus(gChosenMoveByBattler[battler2]) && quickDrawRandom[battler2])
        gProtectStructs[battler2].quickDraw = TRUE;
    // Quick Claw and Custap Berry
    if (!gProtectStructs[battler2].quickDraw
     && ((holdEffectBattler2 == HOLD_EFFECT_QUICK_CLAW && quickClawRandom[battler2])
     || (holdEffectBattler2 == HOLD_EFFECT_CUSTAP_BERRY && HasEnoughHpToEatBerry(battler2, ability2, 4, gBattleMons[battler2].item))))
        gProtectStructs[battler2].usedCustapBerry = TRUE;
}

static void CheckChangingTurnOrderEffects(void)
{
    enum BattlerId i, battler;

    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleStruct->quickClawBattlerId < gBattlersCount)
        {
            battler = gBattlerAttacker = gBattleStruct->quickClawBattlerId;
            gBattleStruct->quickClawBattlerId++;
            if (gChosenActionByBattler[battler] == B_ACTION_USE_MOVE
             && GetMoveEffect(gChosenMoveByBattler[battler]) != EFFECT_FOCUS_PUNCH   // quick claw message doesn't need to activate here
             && (gProtectStructs[battler].usedCustapBerry || gProtectStructs[battler].quickDraw)
             && !(gBattleMons[battler].status1 & STATUS1_SLEEP)
             && !(gBattleMons[gBattlerAttacker].volatiles.truantCounter)
             && !(gProtectStructs[battler].noValidMoves))
            {
                if (gProtectStructs[battler].usedCustapBerry)
                {
                    gLastUsedItem = gBattleMons[battler].item;
                    PREPARE_ITEM_BUFFER(gBattleTextBuff1, gLastUsedItem);
                    if (GetBattlerHoldEffect(battler) == HOLD_EFFECT_CUSTAP_BERRY)
                    {
                        // don't record berry since its gone now
                        BattleScriptExecute(BattleScript_CustapBerryActivation);
                    }
                    else
                    {
                        RecordItemEffectBattle(battler, GetBattlerHoldEffect(battler));
                        BattleScriptExecute(BattleScript_QuickClawActivation);
                    }
                }
                else if (gProtectStructs[battler].quickDraw)
                {
                    gBattlerAbility = battler;
                    gLastUsedAbility = gBattleMons[battler].ability;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    RecordAbilityBattle(battler, gLastUsedAbility);
                    BattleScriptExecute(BattleScript_QuickDrawActivation);
                }
                return;
            }
        }
    }

    // setup stuff before turns/actions
    TryClearRageAndFuryCutter();

    // Prevents trainer slides triggering a turn late if another slide took priority on the previous turn
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        for (enum TrainerSlideType slideId = 0; slideId < TRAINER_SLIDE_COUNT; slideId++)
        {
            MarkInitializedTrainerSlidesAsPlayed(i, slideId);
        }
    }

    gCurrentTurnActionNumber = 0;
    gCurrentActionFuncId = gActionsByTurnOrder[0];
    gBattleStruct->dynamicMoveType = 0;
    gBattleStruct->effectsBeforeUsingMoveDone = FALSE;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattleStruct->battlerState[i].focusPunchBattlers = FALSE;
        gBattleStruct->battlerState[i].ateBoost = FALSE;
        gSpecialStatuses[i].gemBoost = FALSE;
    }

    gBattleMainFunc = RunTurnActionsFunctions;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleResources->battleScriptsStack->size = 0;
}

static void RunTurnActionsFunctions(void)
{
    if (gBattleOutcome != 0)
        gCurrentActionFuncId = B_ACTION_FINISHED;

    // Mega Evolve / Focus Punch-like moves after switching, items, running, but before using a move.
    if (gCurrentActionFuncId == B_ACTION_USE_MOVE && !gBattleStruct->effectsBeforeUsingMoveDone)
    {
        if (!IsPursuitTargetSet())
        {
            if (TryDoGimmicksBeforeMoves())
                return;
            else if (TryDoMoveEffectsBeforeMoves())
                return;
            gBattleStruct->effectsBeforeUsingMoveDone = TRUE;
        }
        else
        {
            if (TryActivateGimmick(gBattlerByTurnOrder[gCurrentTurnActionNumber]))
                return;
        }
    }

    gBattleStruct->savedTurnActionNumber = gCurrentTurnActionNumber;
    sTurnActionsFuncsTable[gCurrentActionFuncId]();

    if (gCurrentTurnActionNumber >= gBattlersCount) // everyone did their actions, turn finished
        gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
}

static void HandleEndTurn_BattleWon(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        gSpecialVar_Result = gBattleOutcome;
        gBattleTextBuff1[0] = gBattleOutcome;
        gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
        gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_EREADER_TRAINER))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_FrontierTrainerBattleWon;

        // This branch covers three things at once: the Battle Frontier, Trainer Hill, and
        // the Battle Tents in Trainer Hill's courtyard (which set BATTLE_TYPE_PALACE/ARENA/
        // FACTORY, all inside the BATTLE_TYPE_FRONTIER mask). The Frontier is a Hoenn
        // institution and stays on the Emerald themes throughout; Trainer Hill and the Tents
        // are Johto and take the HG ones, matching what GetBattleBGM gives them. They are
        // told apart by map section, since the battle type flags do not separate the Tents
        // from the Frontier proper.
        if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
        {
            // Brains only ever appear in the Battle Frontier, so this is always Emerald.
            PlayBGM(MUS_VICTORY_GYM_LEADER);
        }
    #if IS_HNS
        else if (gMapHeader.regionMapSectionId == MAPSEC_TRAINER_HILL)
        {
            PlayBGM(MUS_HG_VICTORY_TRAINER);
        }
    #endif
        else
        {
            PlayBGM(MUS_VICTORY_TRAINER);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        BattleStopLowHpSound();
        gBattlescriptCurrInstr = BattleScript_LocalTrainerBattleWon;

        switch (GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA))
        {
        case TRAINER_CLASS_ELITE_FOUR:
        case TRAINER_CLASS_CHAMPION:
        // HnS uses its own class constants for these, so without them the Johto/Kanto
        // Elite Four and Champions fell through to the ordinary trainer victory theme.
        case TRAINER_CLASS_ELITE_FOUR_HNS:
        case TRAINER_CLASS_CHAMPION_HNS:
        case TRAINER_CLASS_PKMN_TRAINER_1_HNS:
        // Same for FR/LG, which has no separate league victory theme at all - its
        // Elite Four and Champion share the Gym Leader one.
        case TRAINER_CLASS_ELITE_FOUR_FRLG:
        case TRAINER_CLASS_CHAMPION_FRLG:
        #if IS_HNS
            // Steven is an Emerald guest, so he keeps the Emerald league victory theme
            // to match the Emerald champion battle theme GetBattleBGM gives him. No
            // facility check needed here, the Frontier and Trainer Hill are handled by
            // the branch above, so opponentA is always a real gTrainers id at this point.
            if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_STEVEN_HNS)
                PlayBGM(MUS_VICTORY_LEAGUE);
            else
                PlayBGM(MUS_HG_VICTORY_GYM_LEADER);
        #elif IS_FRLG
            PlayBGM(MUS_RG_VICTORY_GYM_LEADER);
        #else
            PlayBGM(MUS_VICTORY_LEAGUE);
        #endif
            break;
        case TRAINER_CLASS_TEAM_AQUA:
        case TRAINER_CLASS_TEAM_MAGMA:
        case TRAINER_CLASS_AQUA_ADMIN:
        case TRAINER_CLASS_AQUA_LEADER:
        case TRAINER_CLASS_MAGMA_ADMIN:
        case TRAINER_CLASS_MAGMA_LEADER:
            PlayBGM(MUS_VICTORY_AQUA_MAGMA);
            break;
        case TRAINER_CLASS_LEADER:
        case TRAINER_CLASS_LEADER_HNS:
        case TRAINER_CLASS_LEADER_KANTO_HNS:
        case TRAINER_CLASS_LEADER_FRLG:
        #if IS_HNS
            PlayBGM(MUS_HG_VICTORY_GYM_LEADER);
        #elif IS_FRLG
            PlayBGM(MUS_RG_VICTORY_GYM_LEADER);
        #else
            PlayBGM(MUS_VICTORY_GYM_LEADER);
        #endif
            break;
        default:
        #if IS_HNS
            PlayBGM(MUS_HG_VICTORY_TRAINER);
        #else
            PlayBGM(MUS_VICTORY_TRAINER);
        #endif
            break;
        }
    }
    else
    {
        gBattlescriptCurrInstr = BattleScript_PayDayMoneyAndPickUpItems;
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_BattleLost(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        {
            if (gBattleOutcome & B_OUTCOME_LINK_BATTLE_RAN)
            {
                gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeitedLinkBattle;
                gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
                gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
            }
            else
            {
                gBattlescriptCurrInstr = BattleScript_FrontierLinkBattleLost;
                gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
            }
        }
        else
        {
            gBattleTextBuff1[0] = gBattleOutcome;
            gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            gBattlescriptCurrInstr = BattleScript_LinkBattleWonOrLost;
            gBattleOutcome &= ~B_OUTCOME_LINK_BATTLE_RAN;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && GetTrainerBattleMode() == TRAINER_BATTLE_EARLY_RIVAL)
        {
            if (GetRivalBattleFlags() & RIVAL_BATTLE_HEAL_AFTER)
                gBattleCommunication[MULTISTRING_CHOOSER] = 1; // Dont do white out text
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 2; // Do white out text
            gBattlerAttacker = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        }
        gBattlescriptCurrInstr = BattleScript_LocalBattleLost;
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_RanFromBattle(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
    }
    else if (CanPlayerForfeitNormalTrainerBattle())
    {
        gBattlescriptCurrInstr = BattleScript_ForfeitBattleGaveMoney;
        gBattleOutcome = B_OUTCOME_FORFEITED;
    }
    else
    {
        switch (gProtectStructs[gBattlerAttacker].fleeType)
        {
        default:
            gBattlescriptCurrInstr = BattleScript_GotAwaySafely;
            break;
        case FLEE_ITEM:
            gBattlescriptCurrInstr = BattleScript_SmokeBallEscape;
            break;
        case FLEE_ABILITY:
            gBattlescriptCurrInstr = BattleScript_RanAwayUsingMonAbility;
            break;
        }
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_MonFled(void)
{
    gCurrentActionFuncId = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);
    gBattlescriptCurrInstr = BattleScript_WildMonFled;

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void HandleEndTurn_FinishBattle(void)
{
    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        // Both of these loops are keyed by the party index each mon had at the START of the
        // battle (gBattleStruct->itemLost and gBattleStruct->partyState). They must run before
        // anything that reorders gPlayerParty, or they apply to the wrong mons. The Mirror
        // party restore and the Nuzlocke fainted-mon deletion below both reorder it.
        // Held items must be restored before the form revert, since item-based form changes
        // (plates, drives, Rusted Sword, Griseous Orb) read the mon's held item.
        if (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE || B_RESTORE_HELD_BATTLE_ITEMS >= GEN_9)
            TryRestoreHeldItems();

        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            bool32 changedForm = TryRevertPartyMonFormChange(i);

            // Recalculate the stats of every party member before the end
            if (!changedForm && B_RECALCULATE_STATS >= GEN_5)
                CalculateMonStats(&gPlayerParty[i]);
        }

        if (gSaveBlock3Ptr->challengeSettings.tx_Challenges_Mirror
         && !gSaveBlock3Ptr->challengeSettings.tx_Challenges_Mirror_Thief
         && (gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE)))
        {
            for (u32 j = 0; j < PARTY_SIZE; j++)
                gPlayerParty[j] = gPlayerPartyBackup[j];
        }

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_CATCH_TUTORIAL
                                  | BATTLE_TYPE_FRONTIER))
            && !(gBattleTypeFlags & BATTLE_TYPE_GHOST && IsGhostBattleWithoutScope()))
        {
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            {
                if (IsOnPlayerSide(battler))
                {
                    if (gBattleResults.playerMon1Species == SPECIES_NONE)
                    {
                        gBattleResults.playerMon1Species = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);
                        GetMonData(GetBattlerMon(battler), MON_DATA_NICKNAME, gBattleResults.playerMon1Name);
                    }
                    else
                    {
                        gBattleResults.playerMon2Species = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);
                        GetMonData(GetBattlerMon(battler), MON_DATA_NICKNAME, gBattleResults.playerMon2Name);
                    }
                }
            }
            TryPutPokemonTodayOnAir();
        }

        if (gIsFishingEncounter && IsMonShiny(&gEnemyParty[0]))
            gChainFishingDexNavStreak = 0;

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_TRAINER_HILL
                                  | BATTLE_TYPE_FRONTIER)))
        {
            for (enum BattleSide side = 0; side < NUM_BATTLE_SIDES; side++)
            {
                struct Pokemon *party = GetSideParty(side);

                if (side == B_SIDE_PLAYER && !B_PARTNER_MONS_MARKED_SEEN)
                    continue;

                for (u32 partySlot = 0; partySlot < PARTY_SIZE; partySlot++)
                {
                    if (gBattleStruct->partyState[side][partySlot].sentOut)
                        HandleSetPokedexFlagFromMon(&party[partySlot], FLAG_SET_SEEN);
                }
            }
        }

        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_TRAINER
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_CATCH_TUTORIAL))
            && gBattleResults.shinyWildMon)
        {
            TryPutBreakingNewsOnAir();
        }

        if (IsNuzlockeEasyActive())
        {
            if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                        | BATTLE_TYPE_LINK_IN_BATTLE
                                        | BATTLE_TYPE_FIRST_BATTLE
                                        | BATTLE_TYPE_CATCH_TUTORIAL
                                        | BATTLE_TYPE_INGAME_PARTNER
                                        | BATTLE_TYPE_TOWER_LINK_MULTI
                                        | BATTLE_TYPE_RECORDED_LINK
                                        | BATTLE_TYPE_FRONTIER
                                        | BATTLE_TYPE_TRAINER_HILL)))
                NuzlockeDeleteFaintedPartyPokemon();
        }
        if (IsNuzlockeActive())
        {
            if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                        | BATTLE_TYPE_LINK_IN_BATTLE
                                        | BATTLE_TYPE_FIRST_BATTLE
                                        | BATTLE_TYPE_CATCH_TUTORIAL
                                        | BATTLE_TYPE_INGAME_PARTNER
                                        | BATTLE_TYPE_TOWER_LINK_MULTI
                                        | BATTLE_TYPE_RECORDED_LINK
                                        | BATTLE_TYPE_FRONTIER
                                        | BATTLE_TYPE_TRAINER_HILL)))
                NuzlockeDeleteFaintedPartyPokemon();
            if (!(gBattleTypeFlags & (BATTLE_TYPE_DOUBLE
                                        | BATTLE_TYPE_LINK
                                        | BATTLE_TYPE_TRAINER
                                        | BATTLE_TYPE_FIRST_BATTLE
                                        | BATTLE_TYPE_LINK_IN_BATTLE
                                        | BATTLE_TYPE_MULTI
                                        | BATTLE_TYPE_BATTLE_TOWER
                                        | BATTLE_TYPE_CATCH_TUTORIAL
                                        | BATTLE_TYPE_LEGENDARY
                                        | BATTLE_TYPE_ROAMER
                                        | BATTLE_TYPE_TWO_OPPONENTS
                                        | BATTLE_TYPE_INGAME_PARTNER
                                        | BATTLE_TYPE_TOWER_LINK_MULTI
                                        | BATTLE_TYPE_RECORDED_LINK)))
            {
                // An off-type mon under the One Type Challenge could never have been
                // caught, so it must not burn the route's Nuzlocke encounter.
                // The Safari Zone / Bug Contest suspend the one-encounter-per-zone
                // rule, so a catch there must not burn the zone either.
                if (!NuzlockeIsSpeciesClauseActive && !OneTypeChallengeCaptureBlocked
                 && !IsNuzlockeCaptureSuspended())
                    NuzlockeFlagSet(NuzlockeGetCurrentRegionMapSectionId());
            }
            NuzlockeIsCaptureBlocked = FALSE;
            NuzlockeIsSpeciesClauseActive = FALSE;
            OneTypeChallengeCaptureBlocked = FALSE;
        }

        BeginFastPaletteFade(3);
        FadeOutMapMusic(5);
        RecordedBattle_SetPlaybackFinished();
        if (gTestRunnerEnabled)
            TestRunner_Battle_AfterLastTurn();
        // Clear battle mon species to avoid a bug on the next battle that causes
        // healthboxes loading incorrectly due to it trying to create a Mega Indicator
        // if the previous battler would've had it.
        for (enum BattlerId i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            gBattleMons[i].species = SPECIES_NONE;
        }

        // Set Battle Controllers to BATTLE_CONTROLLER_NONE
        for (enum BattlerId i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            gBattlerBattleController[i] = BATTLE_CONTROLLER_NONE;
        }

        gBattleMainFunc = FreeResetData_ReturnToOvOrDoEvolutions;
        gCB2_AfterEvolution = BattleMainCB2;
    }
    else
    {
        if (gBattleControllerExecFlags == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

static void FreeResetData_ReturnToOvOrDoEvolutions(void)
{
    if (!gPaletteFade.active)
    {
        gIsFishingEncounter = FALSE;
        gIsSurfingEncounter = FALSE;
        if (gDexNavSpecies && (gBattleOutcome == B_OUTCOME_WON || gBattleOutcome == B_OUTCOME_CAUGHT))
        {
            IncrementDexNavChain();
            TryIncrementSpeciesSearchLevel();
        }
        else
            gSaveBlock3Ptr->dexNavChain = 0;

        ClearCurrentTrainerWantRematchVsSeeker();
        gDexNavSpecies = SPECIES_NONE;
        ResetSpriteData();
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | BATTLE_TYPE_FIRST_BATTLE
                                  | BATTLE_TYPE_SAFARI
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_CATCH_TUTORIAL))
            && (B_EVOLUTION_AFTER_WHITEOUT >= GEN_6
                || gBattleOutcome == B_OUTCOME_WON
                || gBattleOutcome == B_OUTCOME_CAUGHT))
        {
            gBattleMainFunc = TryEvolvePokemon;
        }
        else
        {
            gBattleMainFunc = ReturnFromBattleToOverworld;
            return;
        }
    }

    FreeAllWindowBuffers();
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        // To account for Battle Factory and Slateport Battle Tent, enemy parties are zeroed out in the facilitites respective src/xxx.c files
        // The ZeroEnemyPartyMons() call happens in SaveXXXChallenge function (eg. SaveFactoryChallenge)
        if (!(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_ROAMER)))
        {
            ZeroEnemyPartyMons();
        }
        ResetDynamicAiFunctions();
        FreeMonSpritesGfx();
        FreeBattleResources();
        FreeBattleSpritesData();
    }
}

static void TryEvolvePokemon(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!(sTriedEvolving & (1u << i)))
        {
            bool32 canStopEvo = TRUE;
            enum EvolutionMode mode = EVO_MODE_BATTLE_SPECIAL;
            u32 evolutionItemArg = i;
            u32 species = GetEvolutionTargetSpecies(&gPlayerParty[i], mode, evolutionItemArg, NULL, &canStopEvo, CHECK_EVO);
            sTriedEvolving |= 1u << i;

            if (species == SPECIES_NONE && (gLeveledUpInBattle & (1u << i)))
            {
                gLeveledUpInBattle &= ~(1u << i);
                mode = EVO_MODE_BATTLE_ONLY;
                evolutionItemArg = gLeveledUpInBattle;
                species = GetEvolutionTargetSpecies(&gPlayerParty[i], mode, evolutionItemArg, NULL, &canStopEvo, CHECK_EVO);
            }

            if (species != SPECIES_NONE)
            {
                FreeAllWindowBuffers();
                gBattleMainFunc = WaitForEvoSceneToFinish;
                GetEvolutionTargetSpecies(&gPlayerParty[i], mode, evolutionItemArg, NULL, &canStopEvo, DO_EVO);
                EvolutionScene(&gPlayerParty[i], species, canStopEvo, i);
                return;
            }
        }
    }
    sTriedEvolving = 0;
    gLeveledUpInBattle = 0;
    gBattleMainFunc = ReturnFromBattleToOverworld;
}

static void WaitForEvoSceneToFinish(void)
{
    if (gMain.callback2 == BattleMainCB2)
        gBattleMainFunc = TryEvolvePokemon;
}

static void ReturnFromBattleToOverworld(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        CalculatePlayerPartyCount();
        RandomlyGivePartyPokerus();
        PartySpreadPokerus();
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gReceivedRemoteLinkPlayers)
        return;

    gSpecialVar_Result = gBattleOutcome;
    gMain.inBattle = FALSE;
    gMain.callback1 = gPreBattleCallback1;

    if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
    {
        UpdateRoamerHPStatus(&gEnemyParty[0]);
        ZeroEnemyPartyMons();

#ifndef BUGFIX
        if ((gBattleOutcome & B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT)
#else
        if ((gBattleOutcome == B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT) // Bug: When Roar is used by roamer, gBattleOutcome is B_OUTCOME_PLAYER_TELEPORTED (5).
#endif                                                                               // & with B_OUTCOME_WON (1) will return TRUE and deactivates the roamer.
            SetRoamerInactive(gEncounteredRoamerIndex);
    }

    m4aSongNumStop(SE_LOW_HEALTH, FlagGet(FLAG_SYS_GBS_ENABLED));
    SetMainCallback2(gMain.savedCallback);
}

void RunBattleScriptCommands_PopCallbacksStack(void)
{
    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        if (gBattleResources->battleCallbackStack->size != 0)
            gBattleResources->battleCallbackStack->size--;
        gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
    }
    else
    {
        if (gBattleControllerExecFlags == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

void RunBattleScriptCommands(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
}

enum Type TrySetAteType(enum Move move, enum BattlerId battlerAtk, enum Ability attackerAbility)
{
    enum Type ateType = TYPE_NONE;

    switch (GetMoveEffect(move))
    {
    case EFFECT_TERA_BLAST:
        if (GetActiveGimmick(battlerAtk) == GIMMICK_TERA)
            return ateType;
        break;
    case EFFECT_TERA_STARSTORM:
        if (gBattleMons[battlerAtk].species == SPECIES_TERAPAGOS_STELLAR)
            return ateType;
        break;
    case EFFECT_HIDDEN_POWER:
    case EFFECT_WEATHER_BALL:
    case EFFECT_NATURAL_GIFT:
    case EFFECT_CHANGE_TYPE_ON_ITEM:
    case EFFECT_REVELATION_DANCE:
    case EFFECT_TERRAIN_PULSE:
        return ateType;
    default:
        break;
    }

    switch (attackerAbility)
    {
    case ABILITY_PIXILATE:
        ateType = TYPE_FAIRY;
        break;
    case ABILITY_REFRIGERATE:
        ateType = TYPE_ICE;
        break;
    case ABILITY_AERILATE:
        ateType = TYPE_FLYING;
        break;
    case ABILITY_GALVANIZE:
        ateType = TYPE_ELECTRIC;
        break;
    default:
        ateType = TYPE_NONE;
        break;
    }

    return ateType;
}

// Returns TYPE_NONE if type doesn't change.
enum Type GetDynamicMoveType(struct Pokemon *mon, enum Move move, enum BattlerId battler, enum MonState state)
{
    enum Type moveType = GetMoveType(move);
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    u32 species, heldItem;
    enum Type type1, type2, type3;
    enum Ability ability;
    enum HoldEffect holdEffect;
    enum Gimmick gimmick = GetActiveGimmick(battler);

    if (state == MON_IN_BATTLE)
    {
        if (moveEffect == EFFECT_STRUGGLE)
            return TYPE_MYSTERY;

        species = gBattleMons[battler].species;
        heldItem = gBattleMons[battler].item;
        holdEffect = GetBattlerHoldEffect(battler);
        ability = GetBattlerAbility(battler);
        type1 = gBattleMons[battler].types[0];
        type2 = gBattleMons[battler].types[1];
        type3 = gBattleMons[battler].types[2];
    }
    else
    {
        species = GetMonData(mon, MON_DATA_SPECIES);
        heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
        holdEffect = GetItemHoldEffect(heldItem);
        ability = GetMonAbility(mon);
        type1 = GetSpeciesType(species, 0);
        type2 = GetSpeciesType(species, 1);
        type3 = TYPE_MYSTERY;
    }

    switch (moveEffect)
    {
    case EFFECT_WEATHER_BALL:
        if (state == MON_IN_BATTLE)
        {
            if (HasWeatherEffect())
            {
                if (gBattleWeather & B_WEATHER_RAIN && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                    return TYPE_WATER;
                else if (gBattleWeather & B_WEATHER_SANDSTORM)
                    return TYPE_ROCK;
                else if (gBattleWeather & B_WEATHER_SUN && holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                    return TYPE_FIRE;
                else if (gBattleWeather & B_WEATHER_ICY_ANY)
                    return TYPE_ICE;
                else
                    return moveType;
            }
        }
        else
        {
            switch (gWeatherPtr->currWeather)
            {
            case WEATHER_DROUGHT:
                if (holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                    return TYPE_FIRE;
                break;
            case WEATHER_RAIN:
            case WEATHER_RAIN_THUNDERSTORM:
            case WEATHER_DOWNPOUR:
                if (holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA)
                    return TYPE_WATER;
                break;
            case WEATHER_SNOW:
                return TYPE_ICE;
            case WEATHER_SANDSTORM:
                return TYPE_ROCK;
            }
            return moveType;
        }
        break;
    case EFFECT_HIDDEN_POWER:
        {
            u32 typeBits = 0;
            if (state == MON_IN_BATTLE)
            {
                typeBits = ((gBattleMons[battler].hpIV & 1) << 0)
                        | ((gBattleMons[battler].attackIV & 1) << 1)
                        | ((gBattleMons[battler].defenseIV & 1) << 2)
                        | ((gBattleMons[battler].speedIV & 1) << 3)
                        | ((gBattleMons[battler].spAttackIV & 1) << 4)
                        | ((gBattleMons[battler].spDefenseIV & 1) << 5);
            }
            else
            {
                typeBits = ((GetMonData(mon, MON_DATA_HP_IV) & 1) << 0)
                        | ((GetMonData(mon, MON_DATA_ATK_IV) & 1) << 1)
                        | ((GetMonData(mon, MON_DATA_DEF_IV) & 1) << 2)
                        | ((GetMonData(mon, MON_DATA_SPEED_IV) & 1) << 3)
                        | ((GetMonData(mon, MON_DATA_SPATK_IV) & 1) << 4)
                        | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 1) << 5);
            }

            u32 hpTypes[NUMBER_OF_MON_TYPES] = {0};
            u32 i, hpTypeCount = 0;
            for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
            {
                if (gTypesInfo[i].isHiddenPowerType)
                    hpTypes[hpTypeCount++] = i;
            }
            moveType = ((hpTypeCount - 1) * typeBits) / 63;
            return ((hpTypes[moveType] | F_DYNAMIC_TYPE_IGNORE_PHYSICALITY) & 0x3F);
        }
        break;
    case EFFECT_CHANGE_TYPE_ON_ITEM:
        if (holdEffect == GetMoveEffectArg_HoldEffect(move))
            return GetItemSecondaryId(heldItem);
        break;
    case EFFECT_REVELATION_DANCE:
        if (gimmick != GIMMICK_Z_MOVE)
        {
            enum Type teraType;
            if (gimmick == GIMMICK_TERA && ((teraType = GetMonData(mon, MON_DATA_TERA_TYPE)) != TYPE_STELLAR))
                return teraType;
            else if (type1 != TYPE_MYSTERY && !(gBattleMons[battler].volatiles.roostActive && type1 == TYPE_FLYING))
                return type1;
            else if (type2 != TYPE_MYSTERY && !(gBattleMons[battler].volatiles.roostActive && type2 == TYPE_FLYING))
                return type2;
            else if (gBattleMons[battler].volatiles.roostActive)
                return (B_ROOST_PURE_FLYING >= GEN_5 ? TYPE_NORMAL : TYPE_MYSTERY);
            else if (type3 != TYPE_MYSTERY)
                return type3;
            else
                return TYPE_MYSTERY;
        }
        break;
    case EFFECT_RAGING_BULL:
        switch (species)
        {
        case SPECIES_TAUROS_PALDEA_COMBAT:
        case SPECIES_TAUROS_PALDEA_BLAZE:
        case SPECIES_TAUROS_PALDEA_AQUA:
            return GetSpeciesType(species, 1);
        }
        break;
    case EFFECT_IVY_CUDGEL:
        switch (species)
        {
        case SPECIES_OGERPON_WELLSPRING:
        case SPECIES_OGERPON_WELLSPRING_TERA:
        case SPECIES_OGERPON_HEARTHFLAME:
        case SPECIES_OGERPON_HEARTHFLAME_TERA:
        case SPECIES_OGERPON_CORNERSTONE:
        case SPECIES_OGERPON_CORNERSTONE_TERA:
            return GetSpeciesType(species, 1);
        }
        break;
    case EFFECT_NATURAL_GIFT:
        if (GetItemPocket(heldItem) == POCKET_BERRIES)
            return gNaturalGiftTable[ITEM_TO_BERRY(heldItem)].type;
        else
            return moveType;
    case EFFECT_TERRAIN_PULSE:
        if (state == MON_IN_BATTLE)
        {
            if (IsAnyTerrainAffected(battler, GetBattlerAbility(battler), GetBattlerHoldEffect(battler), gFieldStatuses))
            {
                if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
                    return TYPE_ELECTRIC;
                else if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
                    return TYPE_GRASS;
                else if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
                    return TYPE_FAIRY;
                else if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
                    return TYPE_PSYCHIC;
                else //failsafe
                    return moveType;
            }
        }
        else
        {
            switch (gWeatherPtr->currWeather)
            {
            case WEATHER_RAIN_THUNDERSTORM:
                if (B_THUNDERSTORM_TERRAIN)
                    return TYPE_ELECTRIC;
                break;
            case WEATHER_FOG_HORIZONTAL:
            case WEATHER_FOG_DIAGONAL:
                if (B_OVERWORLD_FOG >= GEN_8)
                    return TYPE_FAIRY;
                break;
            }
            return moveType;
        }
        break;
    case EFFECT_TERA_BLAST:
        if (gimmick == GIMMICK_TERA)
            return GetMonData(mon, MON_DATA_TERA_TYPE);
        break;
    case EFFECT_TERA_STARSTORM:
        if (species == SPECIES_TERAPAGOS_STELLAR)
            return TYPE_STELLAR;
        break;
    case EFFECT_NATURE_POWER:
        if (state == MON_IN_BATTLE)
            return GetMoveType(GetNaturePowerMove());
        break;
    default:
        break;
    }

    if (IsSoundMove(move) && ability == ABILITY_LIQUID_VOICE)
    {
        return TYPE_WATER;
    }
    else if (moveEffect == EFFECT_AURA_WHEEL
          && species == SPECIES_MORPEKO_HANGRY
          && ability != ABILITY_NORMALIZE)
    {
        return TYPE_DARK;
    }
    else if (moveType == TYPE_NORMAL
          && ability != ABILITY_NORMALIZE
          && gimmick != GIMMICK_DYNAMAX
          && gimmick != GIMMICK_Z_MOVE)
    {
        u32 ateType = TrySetAteType(move, battler, ability);
        if (ateType != TYPE_NONE && state == MON_IN_BATTLE)
            gBattleStruct->battlerState[battler].ateBoost = TRUE;
        return ateType;
    }
    else if (moveEffect != EFFECT_CHANGE_TYPE_ON_ITEM
          && moveEffect != EFFECT_TERRAIN_PULSE
          && moveEffect != EFFECT_NATURAL_GIFT
          && moveEffect != EFFECT_HIDDEN_POWER
          && moveEffect != EFFECT_WEATHER_BALL
          && ability == ABILITY_NORMALIZE
          && gimmick != GIMMICK_Z_MOVE)
    {
        if (state == MON_IN_BATTLE && gimmick != GIMMICK_DYNAMAX)
            gBattleStruct->battlerState[battler].ateBoost = TRUE;
        return TYPE_NORMAL;
    }

    return TYPE_NONE;
}

void SetTypeBeforeUsingMove(enum Move move, enum BattlerId battler)
{
    enum Type moveType;
    u32 heldItem = gBattleMons[battler].item;
    enum HoldEffect holdEffect = GetBattlerHoldEffect(battler);

    gBattleStruct->dynamicMoveType = 0;
    gBattleStruct->battlerState[battler].ateBoost = FALSE;
    gSpecialStatuses[battler].gemBoost = FALSE;

    moveType = GetDynamicMoveType(GetBattlerMon(battler),
                                  move,
                                  battler,
                                  MON_IN_BATTLE);

    if (moveType != TYPE_NONE)
        gBattleStruct->dynamicMoveType = moveType | F_DYNAMIC_TYPE_SET;

    moveType = GetBattleMoveType(move);
    if ((gFieldStatuses & STATUS_FIELD_ION_DELUGE && moveType == TYPE_NORMAL)
     || gBattleMons[battler].volatiles.electrified)
        gBattleStruct->dynamicMoveType = TYPE_ELECTRIC | F_DYNAMIC_TYPE_SET;

    // Check if a gem should activate.
    u32 effect = GetMoveEffect(move);
    if (holdEffect == HOLD_EFFECT_GEMS
        && GetBattleMoveType(move) == GetItemSecondaryId(heldItem)
        && effect != EFFECT_PLEDGE
        && effect != EFFECT_OHKO)
    {
        gSpecialStatuses[battler].gemParam = GetBattlerHoldEffectParam(battler);
        gSpecialStatuses[battler].gemBoost = TRUE;
    }
}

// Queues stat boosts for a given battler for totem battles
void ScriptSetTotemBoost(struct ScriptContext *ctx)
{
    enum BattlerId battler = VarGet(ScriptReadHalfword(ctx));
    u32 stat;
    u32 i;

    Script_RequestEffects(SCREFF_V1);

    for (i = 0; i < (NUM_BATTLE_STATS - 1); i++)
    {
        stat = VarGet(ScriptReadHalfword(ctx));
        if (stat)
        {
            gQueuedStatBoosts[battler].stats |= (1 << i);
            gQueuedStatBoosts[battler].statChanges[i] = stat;
            gQueuedStatBoosts[battler].stats |= 0x80;  // used as a flag for the "totem flared to life" script
        }
    }
}

bool32 IsWildMonSmart(void)
{
#if B_SMART_WILD_AI_FLAG != 0
    return (FlagGet(B_SMART_WILD_AI_FLAG));
#else
    return FALSE;
#endif
}

s32 Factorial(s32 n)
{
    s32 f = 1, i;
    for (i = 2; i <= n; i++)
        f *= i;
    return f;
}

bool32 CanPlayerForfeitNormalTrainerBattle(void)
{
    if (!B_RUN_TRAINER_BATTLE)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_INVALID)
        return FALSE;

    return (gBattleTypeFlags & BATTLE_TYPE_TRAINER);
}

bool32 DidPlayerForfeitNormalTrainerBattle(void)
{
    if (!CanPlayerForfeitNormalTrainerBattle())
        return FALSE;

    return (gBattleOutcome == B_OUTCOME_FORFEITED);
}

// Wins the battle instantly. Used in the battle debug with LIST_ITEM_INSTANT_WIN
void BattleDebug_WonBattle(void)
{
    gBattleOutcome |= B_OUTCOME_WON;
    gBattleMainFunc = sEndTurnFuncsTable[gBattleOutcome & 0x7F];
}
