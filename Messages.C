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
        case(EXITINGE) :
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
        case(CARDSSTRTOOBIG) :
        {
            fprintf(stderr, "%s", "Card String too large:\n");
            break;
        }
        case(MEMALLOCERR) :
        {
            fprintf(stderr, "%s", "Error allocating memory: exiting\n");
            break;
        }
        case(NEGCARDVALUE) :
        {
            fprintf(stderr, "%s", "You can't have less than zero cards\n");
            break;
        }
    }
    return;
}


uint32_t ShowAllCards(char ** CardHand, const uint32_t ShowAllCards_HandsPlayed)
{
    uint32_t count=0;
    for(int i=0; i<=(ShowAllCards_HandsPlayed-1); i++)
    {
        *(*(CardHand+i)+strlen(*(CardHand+i))-1)='\0';
        fprintf(stdout, "%d)%s%s", i+1, *(CardHand+i), i<(ShowAllCards_HandsPlayed-1) ? ", " : "  ||" );
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