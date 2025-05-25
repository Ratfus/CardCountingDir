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

bool global_MegaFree()
{
    free((*PPGlobal_Cleanup));
    for(uint32_t i=0; i<((* PGlobal_TotalPlayedCleanup)); i++)
    {
        free((*(*PPGlobal_Cleanup+i)));
    }
    return EXIT_SUCCESS;
}

void ExitFunction(void)
{
    if(HandCalled)global_MegaFree();
    if(Exit_Status==0)fprintf(stdout, "%s", "No Issues Detected\n");
    if(Exit_Status>100 && Exit_Status<200)fprintf(stdout, "%s", "Program Ran Correctly, but terminated");
    if(Exit_Status>200)
    {
    fprintf(stdout, "%s", "Program Had Issues\n");
    perror("System Issues Include:");
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
    HLINE;
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
    //MegaFree(&CardHand, CardStats.TotalHandsPlayed);
    return 0;
}