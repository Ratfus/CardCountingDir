#include "CardCounting.h"

extern uint32_t GetDeckSize(void);
extern uint32_t GetMaxHands(void);
extern uint32_t PrintStats(const CardStats CardStats_PrintStats);
extern uint32_t CalcHiLowCum(const CardStats CalcHiLowCum_CardStats);
extern CardStats SetCards(void);
extern void TotalCardsPulled(char * TotalHandPoints_CardHand, CardStats * TotalCardsPulled);


uint32_t MegaFree(char ***MegaFree_CardHand, uint32_t CardHands)
{
    for(uint32_t i=0; i<=CardHands; i++)
    {
        free(*(*MegaFree_CardHand));
        *(*MegaFree_CardHand)=NULL;
    }
    free(*MegaFree_CardHand);

    return EXIT_SUCCESS;
}

void ExitFunction(void)
{
    fprintf(stdout, "%s", "program terminated correctly");
    EXIT_SUCCESS;
    return;
}

int main()
{
    char **CardHand = NULL;
    uint32_t HandNumber=0;
    uint32_t MaxHands=GetMaxHands();
    CardStats CardStats=SetCards();
    if(EXIT_FAILURE==NewHand(&CardHand, HandNumber))perror("Error");
    for(int i=0; i<MaxHands; i++)
    {
    CardStats.TotalHandsPlayed++;
    fprintf(stdout, "\nHand Number %d)\n", i+1);
    *(CardHand+i)=GetString();
    CardStats.TotalCardsPlayed+=(strlen(*(CardHand+i))-1);
    TotalCardsPulled(*(CardHand+i), &CardStats);
    CardStats.RunningPointsHiLow=CalcHiLowCum(CardStats);
    PrintStats(CardStats);
    }
    MegaFree(&CardHand, CardStats.TotalHandsPlayed);


    void (*ExitFuncPtr)(void);
    ExitFuncPtr=ExitFunction;
    atexit(ExitFuncPtr);


    return 0;
}