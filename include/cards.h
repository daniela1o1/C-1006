#ifndef CARDS_H
#define CARDS_H

typedef struct{
    int cardNr;
    char addedToSystem[50];
    int haveAccess;
} Card;

typedef struct{
    Card *allCards; 
    int cardAmount;
}
CARDS; 


void listAllCards(CARDS *cardArrey); 
void startCards(CARDS *cardArrey); 
void saveCardsToFile(const CARDS *cardArrey, const char *documentation);
void freeCards(CARDS *cardArrey); 

#endif