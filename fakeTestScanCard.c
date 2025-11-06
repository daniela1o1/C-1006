#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Windows.h>
#include "cards.h"
#include "faketestscancard.h"
//#define BOLD "\033[1m"
//#define RESET "\033[0m"



Card *findCardByNumber(CARDS *cards, int cardNr){
    if(!cards) return NULL;
    for(int i = 0; i < cards->cardAmount; ++i){
        if(cards->allCards[i].cardNr == cardNr) return &cards->allCards[i];
    }
    return NULL;
}

void fakeTestScanCard(CARDS *cardArrey){

    if (!cardArrey) return;

    char buffer[64];
    fputs("Enter cardnumber: ", stdout);
    fflush(stdout);


    if(fgets(buffer, sizeof(buffer), stdin) == NULL){
        printf("\033[31mCURRENT LAMP: RED!\033[0m\n");
        sleep(3);
        return;
    }

    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n') 
        buffer[len - 1] = '\0';


    char *endptr;
    long val = strtol(buffer, &endptr, 10);
    if(endptr == buffer || *endptr != '\0'){
        printf("\033[31mCURRENT LAMP: RED!\033[0m\n");
        sleep(3);
        return;
    }

    int cardNr = (int)val;
     Card *found = findCardByNumber(cardArrey, cardNr);

     if (found && found->haveAccess)
        printf("\033[32mCURRENT LAMP: GREEN\033[0m\n");
    else
    printf("\033[31mCURRENT LAMP: RED\033[0m\n");

    fflush(stdout);
    sleep(3);

}