#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "cards.h"
#include "safeinput.h"
#include "fileHandler.h"



void startCards(CARDS *cardArrey){
    if(loadCardsFromFile(cardArrey, "documentation.txt") > 0){
    printf("List all original cards in system: \n");
        return;
    }
    

    cardArrey->cardAmount = 5;
    cardArrey->allCards = malloc(cardArrey->cardAmount * sizeof(Card));
    if(!cardArrey->allCards){
        printf("Failed memory-allocation!\n");
        exit(1);
    }

    time_t t = time(NULL);
    struct tm tm_info;
    localtime_s(&tm_info, &t);
    char today[20];
    strftime(today, sizeof(today), "%Y-%m-%d", &tm_info);

    
    // Startlista med kort
    //cardArrey->allCards[0].cardNr = 1990;
    //strcpy(cardArrey->allCards[0].addedToSystem, today); 
    //cardArrey->allCards[0].haveAccess = 1;

    //cardArrey->allCards[1].cardNr = 1991;
    //strcpy(cardArrey->allCards[1].addedToSystem, today);
    //cardArrey->allCards[1].haveAccess = 1;

    //cardArrey->allCards[2].cardNr = 1992;
    //strcpy(cardArrey->allCards[2].addedToSystem, today);
    //cardArrey->allCards[2].haveAccess = 1;

    //cardArrey->allCards[3].cardNr = 1993;
    //strcpy(cardArrey->allCards[3].addedToSystem, today);
    //cardArrey->allCards[3].haveAccess = 0;

    //cardArrey->allCards[4].cardNr = 1994;
    //strcpy(cardArrey->allCards[4].addedToSystem, today);
    //cardArrey->allCards[4].haveAccess = 0;


    saveCardsToFile(cardArrey, "documentation.txt");
     
    return;
}

void listAllCards(CARDS *cardArrey){
    
    for (int i = 0; i < cardArrey->cardAmount; i++)
    {
        printf("%d %s - %s\n", 
            cardArrey->allCards[i].cardNr, 
            cardArrey->allCards[i].addedToSystem, 
            cardArrey->allCards[i].haveAccess ? "Access :)" : "No access!!");
    }
    char input[20];
    GetInput("Press any button to continue: ", input, sizeof(input));
    printf("\n");
    
    system("cls");
    return;
}

void freeCards(CARDS *cardArrey){
    free(cardArrey->allCards);
    cardArrey->allCards = NULL;
    cardArrey->cardAmount = 0;


    return;
}