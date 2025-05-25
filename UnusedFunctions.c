
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