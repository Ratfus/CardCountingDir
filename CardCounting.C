#include "CardCounting.h"

int main()
{
    char **CardHand = NULL;
    PPGlobal_Cleanup=&CardHand;
    uint32_t MaxHands=GetMaxHands();
    CardStats CardStats=SetCards();
    PGlobal_TotalPlayedCleanup=&CardStats.TotalHandsPlayed;
    NewHand(&CardHand, MaxHands);
    HLINE;
    for(int i=0; i<MaxHands; i++)
    {
    fprintf(stdout, "\nHand Number %d)\n", i+1);
    *(CardHand+i)=GetString();
    CardStats.TotalCardsPlayed+=(strlen(*(CardHand+i))-1);
    TotalCardsPulled(*(CardHand+i), &CardStats);
    CardStats.RunningPointsHiLow=CalcHiLowCum(CardStats);
    PrintStats(CardStats);
    CardStats.TotalHandsPlayed++;
    }
    ShowAllCards(CardHand, CardStats.TotalHandsPlayed);
    printf("%s", *(CardHand+0));
    ExitFunction();
    return 0;
}

