#include "CardCounting.h"

extern void UserMessages(int UserMessages_Message);

bool NewHand(char ***NewHand_CardHand, int NewHand_HandNumb)
{
    bool ReturnVal = EXIT_SUCCESS;
    if (!(*NewHand_CardHand))
    {
        *NewHand_CardHand = (char **)malloc(sizeof(char *)*(NewHand_HandNumb+1));
        if (!NewHand_CardHand)
            ReturnVal = EXIT_FAILURE;
    }
    return ReturnVal;
}




