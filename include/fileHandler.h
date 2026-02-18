#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "cards.h"
#include "addRemove.h"

int loadCardsFromFile(CARDS *cardArrey, const char *documentation);
void saveCardsToFile(const CARDS *cardArrey, const char *documentation);

#endif