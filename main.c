#include "menu.h"
#include "door.h"
#include "cards.h"
#include "addRemove.h"
#include "fakeTestScanCard.h"
#include "safeinput.h"




int main(){

    CARDS cardArrey;
    cardArrey.allCards = NULL;
    cardArrey.cardAmount = 0;
    

    startCards(&cardArrey);
    system("cls");

    while(true){
        printMenu();

        char input[20];
        int option;
        if(!fgets(input, sizeof(input), stdin)){
            printf("Cannot read input!\n");
            continue;
        }

        if(sscanf(input, "%d", &option) != 1){
            printf("Enter valid number :)\n");
            continue;
        }
        
        system("cls");

        switch(option){
            case 1:
                remoteOpenDoor();
                break;

            case 2:
                listAllCards(&cardArrey);
                break;

            case 3:
                addRemove(&cardArrey);
                break;

            case 4:
                freeCards(&cardArrey);
                return 0;

            case 5:
                fakeTestScanCard(&cardArrey);
                break;
            
            default:
                printf("Option NOT valid. Please try again!\n");
        }
    } 

    return 0;
}