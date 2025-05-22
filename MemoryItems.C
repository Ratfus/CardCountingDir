#include "CardCounting.h"

extern void UserMessages(uint32_t UserMessages_Message);
extern bool HandCalled;

void NewHand(char ***NewHand_CardHand, u_int32_t NewHand_HandNumb)
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

bool MegaFree(char ***MegaFree_CardHand, uint32_t CardHands)
{
    for(uint32_t i=0; i<CardHands; i++)
    {
        free(*(*MegaFree_CardHand));
        *(*MegaFree_CardHand)=NULL;
    }
    free(*MegaFree_CardHand);

    return EXIT_SUCCESS;
}



