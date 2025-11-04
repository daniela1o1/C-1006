#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Windows.h>
#include "cards.h"
#include "faketestscancard.h"
//#define BOLD "\033[1m"
//#define RESET "\033[0m"

// dword för att skapa en trådfunktion för lampan
// winapi för korrekt kommunikation med kompilatorn
// showLamp rensar upp i stacken när funktionen avslutas
DWORD WINAPI showLamp(void *param){ 
    Lamp *lampData = (Lamp*)param;

    if(lampData->greenLight)
    printf("\033[32mCURRENT LAMP: GREEN\033[0m\n");
    else
    printf("\033[31mCURRENT LAMP: RED\033[0m\n");

    fflush(stdout);
    printf("\033[F\033[K");
    fflush(stdout);

    free(lampData);
    return 0;

}

void fakeTestScanCard(CARDS *cardArrey){
    Lamp *lampData = malloc(sizeof(Lamp));
    lampData->greenLight = 1;

    //trådfunktion för att hantera lampan utan att frysa programmet
    DWORD threadId;
    HANDLE hThread = CreateThread(NULL, 0, showLamp, lampData, 0, &threadId); 
    if(hThread) CloseHandle(hThread);

    



    



}