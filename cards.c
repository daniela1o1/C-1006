#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"



void startCards(CARDS *cardArrey){

    printf("List all original cards in system: ");

    // Börjar med 5 kort
    cardArrey->cardAmount = 5;
    cardArrey->allCards = malloc(cardArrey->cardAmount * sizeof(Card));
    if(!cardArrey->allCards){
        printf("Failed memory-allocation!\n");
        exit(1);
    }
    
    // Startlista med kort
    cardArrey->allCards[0].cardNr = 1990;
    strcpy(cardArrey->allCards[0].addedToSystem, "Added to system: 25-10-15"); 
    cardArrey->allCards[0].haveAccess = 1;

    cardArrey->allCards[1].cardNr = 1991;
    strcpy(cardArrey->allCards[1].addedToSystem, "Added to system: 25-10-25");
    cardArrey->allCards[1].haveAccess = 1;

    cardArrey->allCards[2].cardNr = 1992;
    strcpy(cardArrey->allCards[2].addedToSystem, "Added to system: 25-10-25");
    cardArrey->allCards[2].haveAccess = 1;

    cardArrey->allCards[3].cardNr = 1993;
    strcpy(cardArrey->allCards[3].addedToSystem, "Added to system: 25-10-29");
    cardArrey->allCards[3].haveAccess = 0;

    cardArrey->allCards[4].cardNr = 1994;
    strcpy(cardArrey->allCards[4].addedToSystem, "Added to system: 25-10-29");
    cardArrey->allCards[4].haveAccess = 0;

     

    }

void listAllCards(CARDS *cardArrey){

    for (int i = 0; i < cardArrey->cardAmount; i++)
    {
        printf("%d %s - %s\n", 
            cardArrey->allCards[i].cardNr, 
            cardArrey->allCards[i].addedToSystem, 
            cardArrey->allCards[i].haveAccess ? "Access :)" : "No access!!");
    }

}

void freeCards(CARDS *cardArrey){
    free(cardArrey->allCards);


}