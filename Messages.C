#include "CardCounting.h"


void UserMessages(uint32_t UserMessages_Message)
{
    switch(UserMessages_Message)
    {
        case(ENTERCARDS):
        {
            fprintf(stdout, "%s", "Please Input Valid Card String (Include E to Exit):");
            break;
        }
        case(EXITINGMSG) :
        {
            fprintf(stdout, "%s\n", "Exiting due to E");
            break;
        }
        case(ENTERMAXHANDS) :
        {
            fprintf(stdout, "%s", "Enter the max hands (Enter 'E' to Exit):");
            break;
        }
        case(ENTERDSIZE) :
        {
            fprintf(stdout, "%s", "Enter the deck size (Enter 'E' to Exit):");
            break;
        }
    }
    return;
}


uint32_t ShowAllCards(char ** CardHand, const uint32_t ShowAllCards_MaxHands)
{
    uint32_t count=0;
    for(int i=0; i<ShowAllCards_MaxHands; i++)
    {
        fprintf(stdout, "%d) %s", i, *(CardHand+i), stdout);
        count=i;
    }
    return count;
}

void HoriLine(const int LineSize)
{
fputs("\n\n", stdout);
for(int i=0; i<LineSize; i++)fputc('*', stdout);
fputc('\n', stdout);
return;
}