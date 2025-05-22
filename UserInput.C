#include "CardCounting.h"

extern void UserMessages(uint32_t UserMessages_Message);
extern void HoriLine(const int LineSize);
extern void ExitFunction(void);

int CheckForExit(const char * const CheckString)
{
    for(int i=0; i<=strlen(CheckString); i++)
    {
        if(CheckString[i]=='E' || CheckString[i]=='e')  //Terminate if user enters E
        {
            UserMessages(EXITINGE);
            Exit_Status=EXITINGE;
            ExitFunction();
        }
    }
    return EXIT_SUCCESS;
}

uint32_t GetDeckSize(void)
{
    char DeckSizeChar[MAXSTRING]="\0";
    char *endPTR=NULL;
    uint32_t GetDeckSize_DeckSize=-1;
    while(GetDeckSize_DeckSize>100 || GetDeckSize_DeckSize<=0)
    {
    UserMessages(ENTERDSIZE);
    fgets(DeckSizeChar, MAXSTRING, stdin);
    CheckForExit(DeckSizeChar);
    if(!(GetDeckSize_DeckSize=strtol(DeckSizeChar, &endPTR, 10)))perror("Entry Error");
    }
    fputs("Ok\n", stdout);
    HLINE;
    return GetDeckSize_DeckSize;
}

uint32_t GetMaxHands(void)
{
    char MaxHandsChar[MAXSTRING]="\0";
    char *endPTR=NULL;
    uint32_t MaxHands_MaxHandsInt=-1;
    while(MaxHands_MaxHandsInt>100 || MaxHands_MaxHandsInt<=0)
    {
    UserMessages(ENTERMAXHANDS);
    fgets(MaxHandsChar, MAXSTRING, stdin);
    CheckForExit(MaxHandsChar);
    if(!(MaxHands_MaxHandsInt=strtol(MaxHandsChar, &endPTR, 10)))perror("Entry Error");
    }
    fputs("Ok\n", stdout);
    HLINE;
    return MaxHands_MaxHandsInt;
}

void FormatString(char *String)
{
    for (int i = 0; i < strlen(String); i++)
    {
        *(String + i) = toupper(*(String + i));
    }
}

bool VerifyString(const char * const VerifyString_CardString)
{
    for(int i=0; i<strlen(VerifyString_CardString)-1; i++)
    {
        CheckForExit(VerifyString_CardString);
        for(int Card=TWO; Card<=ACE; Card++)
        {
        if(VerifyString_CardString[i]==Cards[Card])break;
        if(Card==ACE)return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

char *GetString(void)
{
    char *GetString_CardString = NULL;
    GetString_CardString = (char *)malloc(sizeof(char) * CARDSPERHAND);
    
    while(VerifyString(GetString_CardString))
    {
    UserMessages(ENTERCARDS);
    fgets(GetString_CardString, CARDSPERHAND, stdin);
    if(strlen(GetString_CardString)>CARDSPERHAND)
    {
    Exit_Status=CARDSSTRTOOBIG;
    UserMessages(CARDSSTRTOOBIG);
    ExitFunction();
    }
    FormatString(GetString_CardString);
    }
    return GetString_CardString;
}

CardStats SetCards(void)
{
    CardStats SetCards_CardStats={0};
    SetCards_CardStats.DecksInPlay=GetDeckSize();
    for(int i=0; i<=ACE; i++)
    {
        SetCards_CardStats.CardsRemaining[i]=SetCards_CardStats.CardsInDeck[i]=(SetCards_CardStats.DecksInPlay*4);
        SetCards_CardStats.CardsDrawn[i]=0;
    }
    return SetCards_CardStats;
}