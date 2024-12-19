#include "global.h"
#include "gflib.h"
#include "berry.h"
#include "daycare.h"
#include "event_data.h"
#include "load_save.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokedex.h"
#include "script_pokemon_util.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "random.h"

static void CB2_ReturnFromChooseHalfParty(void);
static void CB2_ReturnFromChooseBattleTowerParty(void);

void HealPlayerParty(void)
{
    u8 i, j;
    u8 ppBonuses;
    u8 arg[4];
    u16 maxHP;

    // restore HP.
    for(i = 0; i < gPlayerPartyCount; i++)
    {
        if(IsMapTypeOutdoors(GetCurrentMapType())&&GetAilmentFromStatus(GetMonData(&gPlayerParty[i], MON_DATA_STATUS)) == AILMENT_PSN)continue;
        maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, arg);
        ppBonuses = GetMonData(&gPlayerParty[i], MON_DATA_PP_BONUSES);

        // restore PP.
        for(j = 0; j < MAX_MON_MOVES; j++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j), ppBonuses, j);
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, arg);
        }

        // since status is u32, the four 0 assignments here are probably for safety to prevent undefined data from reaching SetMonData.
        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, arg);
    }
}

static void ChangeMonSpecies(u16 species, u8 limit) {
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u32 level = GetMonData(mon, MON_DATA_LEVEL);
    u32 ivs = GetMonData(mon, MON_DATA_IVS);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 moves[4] = {};
    s32 i;
    if (level < limit) {//evolution failed
        gSpecialVar_0x8009 = SPECIES_NONE;
        return;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
        moves[i] = (u16) GetMonData(mon, MON_DATA_MOVE1 + i);
    CreateMonWithIVsPersonality(mon, species, (u8) level, ivs, personality);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, moves[i], i);
    gSpecialVar_0x8009 = species;
}

#define BST(info) (info->baseHP + info->baseAttack + info->baseDefense\
                 + info->baseSpeed + info->baseSpAttack + info->baseSpDefense)
#define IS_TYPE(type)(rep->types[0] == type || rep->types[1] == type)
static void PickRandomEvo(u16 *species, u16 *evos) {
    s32 i, last = 0;
    const struct SpeciesInfo *src = &gSpeciesInfo[*species], *rep;
    u8 types[] = {src->types[0], src->types[1]};
    u16 srcBST = (90 * BST(src)) / 100, repBST;
    for (i = 1; i < NUM_SPECIES; i++) {
        rep = &gSpeciesInfo[i];
        repBST = BST(rep);
        if ((IS_TYPE(types[0]) || IS_TYPE(types[1])) && repBST > srcBST && repBST < 580)
            evos[last++] = i;
    }
    do {
        i = Random() % last;
    } while (!evos[i] || *species == evos[i]);//force change
    *species = evos[i];
}

void EvolveMon(void) {
    u16 species = gSpecialVar_Result;
    u16 *evos = NULL;
    switch (species) {
        case SPECIES_LICKITUNG:
            species = SPECIES_LICKILICKY;
            evos = calloc(140, sizeof(u16));
            break;
        case SPECIES_TANGELA:
            species = SPECIES_TANGROWTH;
            evos = calloc(130, sizeof(u16));
            break;
        case SPECIES_AIPOM:
            species = SPECIES_AMBIPOM;
            evos = calloc(140, sizeof(u16));
            break;
        case SPECIES_YANMA:
            species = SPECIES_YANMEGA;
            evos = calloc(200, sizeof(u16));
            break;
        case SPECIES_PILOSWINE:
            species = SPECIES_MAMOSWINE;
            evos = calloc(140, sizeof(u16));
            break;
        case SPECIES_GLIGAR:
            species = SPECIES_GLISCOR;
            evos = calloc(190, sizeof(u16));
            break;
        case SPECIES_SNEASEL:
            species = SPECIES_WEAVILE;
            evos = calloc(140, sizeof(u16));
            break;
        case SPECIES_PORYGON2:
            species = SPECIES_PORYGON_Z;
            evos = calloc(140, sizeof(u16));
            break;
        case SPECIES_DUSCLOPS:
            species = SPECIES_DUSKNOIR;
            evos = calloc(70, sizeof(u16));
            break;
        default:
            return;
    }
    PickRandomEvo(&species, evos);
    free(evos);
    ChangeMonSpecies(species, 10);
}

void UseIceRock(void) {
    u16 species = SPECIES_GLACEON;
    u16 *evos = calloc(60, sizeof(u16));
    PickRandomEvo(&species, evos);
    free(evos);
    ChangeMonSpecies(species, 0);
}

void UseMossRock(void) {
    u16 species = SPECIES_LEAFEON;
    u16 *evos = calloc(130, sizeof(u16));
    PickRandomEvo(&species, evos);
    free(evos);
    ChangeMonSpecies(species, 0);
}

u8 ScriptGiveMon(u16 species, u8 level, u16 item, u32 unused1, u32 unused2, u8 unused3)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon *mon = AllocZeroed(sizeof(struct Pokemon));

    CreateMon(mon, species, level, 32, 0, 0, OT_ID_PLAYER_ID, 0);
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(mon);
    nationalDexNum = SpeciesToNationalPokedexNum(species);

    switch(sentToPc)
    {
    case MON_GIVEN_TO_PARTY:
    case MON_GIVEN_TO_PC:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    }

    Free(mon);
    return sentToPc;
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon *mon = AllocZeroed(sizeof(struct Pokemon));
    bool8 isEgg;
    bool8 sentToPc;

    CreateEgg(mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(mon, MON_DATA_IS_EGG, &isEgg);

    sentToPc = GiveMonToPlayer(mon);
    Free(mon);
    return sentToPc;
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

static bool8 CheckPartyMonHasHeldItem(u16 item)
{
    int i;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, u16 item)
{
    u8 heldItem[2];

    ZeroEnemyPartyMons();
    CreateMon(&gEnemyParty[0], species, level, 32, 0, 0, OT_ID_PLAYER_ID, 0);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot)
{
    if (monIndex > PARTY_SIZE)
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

// Note: When control returns to the event script, gSpecialVar_Result will be
// TRUE if the party selection was successful.
void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
//    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseMonsForBattle(CHOOSE_MONS_FOR_CABLE_CLUB_BATTLE);
}

static void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChooseBattleTowerPlayerParty(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseBattleTowerParty;
    InitChooseMonsForBattle(CHOOSE_MONS_FOR_BATTLE_TOWER);
}

static void CB2_ReturnFromChooseBattleTowerParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        LoadPlayerParty();
        gSpecialVar_Result = FALSE;
        break;
    default:
        ReducePlayerPartyToThree();
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToThree(void)
{
    struct Pokemon * party = AllocZeroed(3 * sizeof(struct Pokemon));
    int i;

    // copy the selected pokemon according to the order.
    for (i = 0; i < 3; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 3 with the order copied to.
    for (i = 0; i < 3; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
    Free(party);
}
