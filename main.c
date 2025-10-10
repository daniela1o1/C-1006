#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>
#include "menu.h"
#include "door.h"
#include "cards.h"
#include "addRemove.h"


int main(){
    while(true){
        printMenu();
        int option;
        scanf("%d", &option);
        if(option == 1){
            remoteOpenDoor();
        }
        else if(option == 4){
            break;
        }
        else if(option == 2){
            listAllCards();
        }
        else if(option == 3){
            addRemove();
        }
    }
    return 0;
}