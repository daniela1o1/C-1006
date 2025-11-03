#ifndef FAKETESTSCANCARD_H
#define FAKETESTSCANCARD_H

typedef struct { // gör en egen struct för att inte behöva pausa programmet med 'fflush'
    int greenLight; //1 = grön, 0 = röd lampa

}Lamp;

void fakeTestScanCard(CARDS *cardArrey);

#endif