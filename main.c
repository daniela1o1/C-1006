#include "menu.h"
#include "door.h"
#include "cards.h"
#include "addRemove.h"
#include "fakeTestScanCard.h"
#include "safeinput.h"

// _getch(); tar emot input utan enter

int main(){

    CARDS cardArrey;
    cardArrey.allCards = NULL;
    cardArrey.cardAmount = 0;
    

    startCards(&cardArrey);
    system("cls");

    while(true){
        printMenu();

        char input[20];
        long option;
        INPUT_RESULT result = GetInput("Select option: ", input, sizeof(input));

        if(result == INPUT_RESULT_NO_INPUT){
            printf("Invalid input, try again!\n");
            continue;
        }
        else if(result == INPUT_RESULT_TOO_LONG){
            printf("Input too long, try again!\n");
            continue;
        }

        if (!parseLong(input, &option)){
            printf("Enter a valid number!\n");
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
                sleep(3);
                system("cls");
                break;
        }
    } 
}