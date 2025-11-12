#ifndef CARDS_H
#define CARDS_H

typedef struct{
    int cardNr;
    char addedToSystem[50];
    int haveAccess;
} Card;

typedef struct{
    Card *allCards; //arreyen
    int cardAmount;
}
CARDS; //lådan


//extern CARDS *listOfCards;
//extern int cardArrey.cardAmount;
//ta cardArrey (all data), allt annat(->/. osv är för att hitta specifik data i listofcards).
//kommer åt allCards eller cardAmount 
// cardArrey->allcards[].cardNr 

void listAllCards(CARDS *cardArrey); //Skriver ut alla kort
void startCards(CARDS *cardArrey); // Lista över ursprungliga kort
void saveCardsToFile(const CARDS *cardArrey, const char *documentation);
void freeCards(CARDS *cardArrey); // Frigör dynamiskt minne

#endif