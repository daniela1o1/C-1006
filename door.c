#include <stdio.h>
#include <unistd.h>
#include <Windows.h>
#include <stdlib.h>


void remoteOpenDoor(){

    printf("\033[32mCURRENT LAMP: Green\033[0m\n");
    fflush(stdout);
    sleep(3);
    system("cls");

    printf("CURRENT LAMP: OFF!\n");
    sleep(3);
    system("cls");
    fflush(stdout);
    
}
    