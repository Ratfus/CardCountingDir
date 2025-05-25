#include "CardCounting.h"

extern bool HandCalled;  //Determine if any hands were played for free
char *** PPGlobal_Cleanup;  //Pointer to card hands for free
uint32_t * PGlobal_TotalPlayedCleanup;  //Global pointer to how many hands played for free

bool global_MegaFree()  //Cleanup Function 
{
    fprintf(stdout, "Freeing %d items\n", * PGlobal_TotalPlayedCleanup);
    for(uint32_t i=0; i<((* PGlobal_TotalPlayedCleanup)); i++)
    {
        free((*(*PPGlobal_Cleanup+i)));
    }
    free((*PPGlobal_Cleanup));
    return EXIT_SUCCESS;
}

void NewHand(char ***NewHand_CardHand, u_int32_t NewHand_HandNumb)  //Set up max total hands to play
{
    bool ReturnVal = EXIT_SUCCESS;
    if (!(*NewHand_CardHand))
    {
        *NewHand_CardHand = (char **)malloc(sizeof(char *)*(NewHand_HandNumb+1));
        if (!*NewHand_CardHand)
        {
            Exit_Status=MEMALLOCERR;
            UserMessages(MEMALLOCERR);
            ExitFunction();
        }
        HandCalled=1;
    }
    return;
}

bool MegaFree(char ***MegaFree_CardHand, uint32_t CardHands)  //Not used function
{
    for(uint32_t i=0; i<CardHands; i++)
    {
        free(*(*MegaFree_CardHand));
        *(*MegaFree_CardHand)=NULL;
    }
    free(*MegaFree_CardHand);

    return EXIT_SUCCESS;
}



