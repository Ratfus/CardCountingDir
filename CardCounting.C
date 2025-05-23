#include "CardCounting.h"

extern uint32_t GetDeckSize(void);
extern uint32_t GetMaxHands(void);
extern uint32_t PrintStats(const CardStats CardStats_PrintStats);
extern uint32_t CalcHiLowCum(const CardStats CalcHiLowCum_CardStats);
extern CardStats SetCards(void);
extern void TotalCardsPulled(char * TotalHandPoints_CardHand, CardStats * TotalCardsPulled);
extern bool MegaFree(char ***MegaFree_CardHand, uint32_t CardHands);
extern void NewHand(char ***NewHand_CardHand, uint32_t NewHand_HandNumb);

char *** PPGlobal_Cleanup;
uint32_t * PGlobal_TotalPlayedCleanup;
bool HandCalled=0;

uint32_t global_MegaFree()
{
    free((*PPGlobal_Cleanup));
    int i=0;
    for(; i<((* PGlobal_TotalPlayedCleanup)); i++)
    {
        free((*(*PPGlobal_Cleanup+i)));
    }
    return i;
}

void ExitFunction(void)
{
    if(HandCalled)fprintf(stdout, "Successfully freed: %d items\n", global_MegaFree());
    else fprintf(stdout, "Nothing to free\n");

    if(Exit_Status==0)fprintf(stdout, "%s", "No Issues Detected\n");
    if(Exit_Status>100 && Exit_Status<200)fprintf(stdout, "%s", "Program Ran Correctly, but terminated");
    if(Exit_Status>200)
    {
    fprintf(stdout, "%s", "Program Had Issues\b\n");
    perror("System Issues Include");
    }
    errno=0;
    exit(Exit_Status);
    return;
}

int main()
{
    char **CardHand = NULL;
    PPGlobal_Cleanup=&CardHand;
    uint32_t MaxHands=GetMaxHands();
    CardStats CardStats=SetCards();
    PGlobal_TotalPlayedCleanup=&CardStats.TotalHandsPlayed;
    NewHand(&CardHand, MaxHands);
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
    HLINE;
    ExitFunction();
    return 0;
}