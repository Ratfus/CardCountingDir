#include "CardCounting.h"

int32_t CardLookup(char CardLookup_Card)
{
    for (uint32_t i = 0; i <= ACE; i++)
    {
        if (Cards[i] == CardLookup_Card)
            return i;
    }
    return -1;
}

int32_t GetValue_HiLow(const char GetValue_Card)
{
    int32_t GetValue_CardNumb = CardLookup(GetValue_Card);
    assert(GetValue_CardNumb <= ACE + 1);
    if (GetValue_CardNumb >= TWO && GetValue_CardNumb <= ACE)
    {
        if (GetValue_CardNumb <= 6)
            return 1;
        if (GetValue_CardNumb > 6 && GetValue_CardNumb < TEN)
            return 0;
        if (GetValue_CardNumb >= TEN)
            return -1;
    }
    return -69;
}

int32_t TotalHandPoints(char *TotalHandPoints_CardHand)
{
    int32_t Handpoints = 0;
    for (int i = 0; i < strlen(TotalHandPoints_CardHand); i++)
    {
        if (GetValue_HiLow(TotalHandPoints_CardHand[i]) == -69)
        {
            fputs("Error", stdout);
        }
        Handpoints += GetValue_HiLow(TotalHandPoints_CardHand[i]);
    }
    return Handpoints;
}

int32_t TotalPlayHiLow(char **const CardHand, const uint32_t ShowAllCards_MaxHands)
{
    int32_t count = 0;
    for (int i = 0; i < ShowAllCards_MaxHands; i++)
    {
        count += TotalHandPoints(*(CardHand + i));
    }
    return count;
}

uint32_t PrintStats(const CardStats CardStats_PrintStats)
{
    uint32_t TotalCards = 0;
    float TestVar = 0;
    for (int i = 0; i <= ACE; i++)
    {
        TotalCards += CardStats_PrintStats.CardsInDeck[i];
    }
    assert(TotalCards == (CardStats_PrintStats.DecksInPlay * 52));
    fprintf(stdout, "Current High Low Value: %d, Total Cards Played: %d, Remaining Cards: %d\n", CardStats_PrintStats.RunningPointsHiLow, CardStats_PrintStats.TotalCardsPlayed, TotalCards-CardStats_PrintStats.TotalCardsPlayed);
    fprintf(stdout, "\nCard Percentages of remaining:\n");
    for (int i = 0; i <= ACE; i++)
    {
        fprintf(stdout, "%c)%.2f%%%c ", Cards[i], ((float)CardStats_PrintStats.CardsRemaining[i] / ((float)TotalCards - (float)CardStats_PrintStats.TotalHandsPlayed)) * 100, i < (ACE) ? ',' : '\n');
        TestVar += ((float)CardStats_PrintStats.CardsRemaining[i] / ((float)TotalCards - (float)CardStats_PrintStats.TotalCardsPlayed)) * 100;
    }
    fprintf(stdout, "Total: %.2f\n", TestVar);
    assert(abs(TestVar - 100) <= 10);
    fprintf(stdout, "\nCard's Remaining:\n");
    for (int i = 0; i <= ACE; i++)
    {
        fprintf(stdout, "%c)%d%c ", Cards[i], CardStats_PrintStats.CardsRemaining[i], i <= (ACE) ? ',' : '\n');
    }
    TestVar=0;
    fprintf(stdout, "\n\nPercentages Remaining By Type:\n");
    for (int i = 0; i <= HIGHCARDS; i++)
    {
        fprintf(stdout, "%s)%.2f%%%c ", CardTypes[i], ((float)CardStats_PrintStats.CardTypes[i]/((float)TotalCards - (float)CardStats_PrintStats.TotalCardsPlayed)) * 100, i < HIGHCARDS ? ',' : '\n');
        TestVar+=((float)CardStats_PrintStats.CardTypes[i]/((float)TotalCards - (float)CardStats_PrintStats.TotalCardsPlayed)) * 100;
    }
    fprintf(stdout, "Total: %.2f", TestVar);
    assert(abs(TestVar-100)<=10);
    HLINE;
    return TotalCards;
}

uint32_t CalcHiLowCum(const CardStats CalcHiLowCum_CardStats)
{
    uint32_t TotalCardPoints = 0;
    for (int i = 0; i <= ACE; i++)
    {
        TotalCardPoints += CalcHiLowCum_CardStats.CardsDrawn[i] * GetValue_HiLow(Cards[i]);
    }
    return TotalCardPoints;
}

void TotalCardsPulled(char *TotalHandPoints_CardHand, CardStats *TotalCardsPulled)
{
    uint16_t CardLookupInt = 0;
    for (int i = 0; i <= strlen(TotalHandPoints_CardHand); i++)
    {
        CardLookupInt = 0;
        if (CardLookup(TotalHandPoints_CardHand[i]) > -1)
        {
            CardLookupInt = CardLookup(TotalHandPoints_CardHand[i]);
            TotalCardsPulled->CardsDrawn[CardLookupInt]++;
            TotalCardsPulled->CardsRemaining[CardLookupInt]--;
            if(TotalCardsPulled->CardsRemaining[CardLookupInt]>(UINT32_MAX-1))
            {
                exit(-69);
            }
        }
    }
    TotalCardsPulled->CardTypes[LOWCARDS]=0;
    TotalCardsPulled->CardTypes[MEDCARDS]=0;
    TotalCardsPulled->CardTypes[HIGHCARDS]=0;
    for (int i = 0; i <= ACE; i++)
    {
        if (i <= SIX)
            TotalCardsPulled->CardTypes[LOWCARDS] += *(TotalCardsPulled->CardsRemaining + i);
        if (i > SIX && i < TEN)
            TotalCardsPulled->CardTypes[MEDCARDS] += *(TotalCardsPulled->CardsRemaining + i);
        if (i >= TEN)
            TotalCardsPulled->CardTypes[HIGHCARDS] += *(TotalCardsPulled->CardsRemaining + i);
    }
    return;
}