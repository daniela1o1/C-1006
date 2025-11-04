#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "addRemove.h"
#include "safeinput.h"


void addCards(CARDS *cardArrey){
    if (!cardArrey) 
    return;

    Card newCard;

    while(true){
        char input[20];
        if(GetInput("Enter cardnumber\nOr 'x' to cancel:", input, sizeof(input)) != INPUT_RESULT_OK)
        return;

        if(input[0] == 'X' || input[0] == 'x')
        return;

        long cardNr;
        if(!parseLong(input, &cardNr)){
            printf("Invalid input! Enter a number.\n");
            continue;
        }

        newCard.cardNr = (int)cardNr;
        break;
    }

    for(int i = 0; i < cardArrey->cardAmount; i++){
        if(cardArrey->allCards[i].cardNr == newCard.cardNr){
            printf("Card #%d already exists in the system!\n", newCard.cardNr);
            return;
        }
    }

    if(GetInput("Enter today's date (ex. 'Added to system: 25-11-03'): ",
                newCard.addedToSystem, sizeof(newCard.addedToSystem)) != INPUT_RESULT_OK){
        printf("Cannot read input.\n");
        return;
    }

    while(true){
        char input[10];
        if(GetInput("For access: Press 1. No access: Press 0.\nOr press X to cancel: ",
                input, sizeof(input)) != INPUT_RESULT_OK)
            return;

        if(input[0] == 'X' || input[0] == 'x')
        return;

        long access;
        if(!parseLong(input, &access) || (access != 0 && access != 1)){
            printf("Invalid input! Enter 1 or 0.\n");
            continue;
        }
        newCard.haveAccess = (int)access;
        break;
    }


Card *temp = realloc(cardArrey->allCards, (cardArrey->cardAmount + 1) * sizeof(Card)); 
if (!temp){
    printf("Memory-allocation failed!\n");
    return;
}

cardArrey->allCards = temp;
cardArrey->allCards[cardArrey->cardAmount] = newCard;
cardArrey->cardAmount++;

printf(" Card #%d added (%s, Access: %s)\n",
newCard.cardNr,
newCard.addedToSystem,
newCard.haveAccess ? "YES :)" : "NO!");


}

void removeCard(Card *cardArrey){

}

void changeAccess(Card *cardArrey){

}

void addRemove(CARDS *cardArrey){
    while(true){
        printf("\n=== Add/Remove/Change access ===\n");
        printf("1. Add new card\n");
        printf("2. Remove card\n");
        printf("3. Change access\n");
        printf("X. Back to main menu\n");

        char choice;
        if(GetInputChar("Select option: ", choice)) 
        continue;

        if(choice == 'X' || choice == 'x')
        break;

        switch(choice){
            case '1':
                addCards(cardArrey);
                break;

            case '2':
                removeCard(cardArrey);
                break;

            case '3':
                changeAccess(cardArrey);
                break;

            case 'X':
            case 'x':
            return;

            default:
            printf("Invalid option, try again!\n");
        }
    }

}
