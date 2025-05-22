#include<stdlib.h>

#ifndef ENUMS
#define ENUMS
#define CARDSPERHAND 50
#define MAXSTRING 50
enum CardNumbers
{
    TWO = 0,
    THREE = 1,
    FOUR = 2,
    FIVE = 3,
    SIX = 4,
    SEVEN = 5,
    EIGHT = 6,
    NINE = 7,
    TEN = 8,
    JACK = 9,
    QUEEN = 10,
    KING = 11,
    ACE = 12,
};

const int Cards[13] =
    {
        [TWO] = '2',
        [THREE] = '3',
        [FOUR] = '4',
        [FIVE] = '5',
        [SIX] = '6',
        [SEVEN] = '7',
        [EIGHT] = '8',
        [NINE] = '9',
        [TEN] = 'T',
        [JACK] = 'J',
        [QUEEN] = 'Q',
        [KING] = 'K',
        [ACE] = 'A',
};

enum Messages
{
    ENTERCARDS = 100,
    EXITINGE = 101,
    ENTERMAXHANDS = 102,
    ENTERDSIZE=103,
    CARDSSTRTOOBIG=200,
    MEMALLOCERR=201,
    NEGCARDVALUE=202,
};

enum CardTypes
{
    LOWCARDS=0,
    MEDCARDS=1,
    HIGHCARDS=2,
};

const char * const CardTypes[3] =
{
        [LOWCARDS]="LOWCARDS",
        [MEDCARDS]="MEDCARDS",
        [HIGHCARDS]="HIGHCARDS",
};

typedef struct _CardStats
{
    uint32_t RunningPointsHiLow;
    uint32_t DecksInPlay;
    uint32_t TotalHandsPlayed;
    uint32_t TotalCardsPlayed;
    uint32_t CardsInDeck[ACE+1];
    uint32_t CardsDrawn[ACE+1];
    uint32_t CardsRemaining[ACE+1];
    uint32_t MaxHands;
    uint32_t CardTypes[HIGHCARDS+1];
}CardStats;

static int32_t Exit_Status=0;

#define HLINE HoriLine(50);
#endif
