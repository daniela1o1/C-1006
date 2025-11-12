#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "addRemove.h"
#include "fileHandler.h"


void saveCardsToFile(const CARDS *cardArrey, const char *documentation){
    FILE *doc = fopen(documentation, "w"); 
    if(doc == NULL){
        perror("Could not open file for writing");
        return;
    }

    time_t t = time(NULL);
    fprintf(doc, "==CardDocumentation==\n");
    fprintf(doc, "Saved: %s\n", ctime(&t));

    for(int i = 0; i < cardArrey->cardAmount; i++){
        fprintf(doc, "Card %d:\n", i + 1);
        fprintf(doc, "Cardnumber: %d\n", cardArrey->allCards[i].cardNr);
        fprintf(doc, "Added to system: %s\n", cardArrey->allCards[i].addedToSystem);
        fprintf(doc, "Access: %s\n", cardArrey->allCards[i].haveAccess ? "YES :)" : "NO!");
        fprintf(doc, "-----------------------------\n");
    }

    fclose(doc);

    return;
}


int loadCardsFromFile(CARDS *cardArrey, const char *documentation){
    FILE *doc = fopen(documentation, "r");
    if(!doc){
        return 0;
    }

    char line[256];
    Card tempCard;
    cardArrey->allCards = NULL;
    cardArrey->cardAmount = 0;

    while(fgets(line, sizeof(line), doc)){
        if(strncmp(line, "Cardnumber: ", 12) == 0){
            tempCard.cardNr = atoi(line + 12);

            if(fgets(line, sizeof(line), doc)){
                line[strcspn(line, "\n")] = 0;
                strncpy(tempCard.addedToSystem, line + 17, sizeof(tempCard.addedToSystem));
            }

            if(fgets(line, sizeof(line), doc)){
                tempCard.haveAccess = (strstr(line, "YES") != NULL) ? 1 : 0;
            }

            fgets(line, sizeof(line), doc);

            Card *temp = realloc(cardArrey->allCards, (cardArrey->cardAmount + 1) * sizeof(Card));
            if(!temp){
                printf("Memory allocation failed!\n");
                fclose(doc);
                return -1;
            }

            cardArrey->allCards = temp;
            cardArrey->allCards[cardArrey->cardAmount] = tempCard;
            cardArrey->cardAmount++;
        }
    }

    fclose(doc);
    return 1;


}