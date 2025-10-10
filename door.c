#include <stdio.h>
#include <unistd.h>
#include <Windows.h>
#include <stdlib.h>

void remoteOpenDoor(){
    printf("CURRENT LAMP: Green \n");
    fflush(stdout);
    sleep(3);

    printf("\r%22s\r", "");
    fflush(stdout);
}