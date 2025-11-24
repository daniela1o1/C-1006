# Card Access Simulator

A lightweight C-based system for simulating card access control.  
Users can fake-scan cards, add/remove cards, modify access levels, 
and list all cards stored in the system.

The project demonstrates secure memory handling using malloc, 
realloc, and free, as well as robust input handling via safe input 
functions to avoid buffer overflows and crashes.

## 📌 Features

- Fake card scanning to simulate door access
- Add new cards to the system
- Remove existing cards
- Modify access levels
- List all stored cards
- Dynamic memory management using `malloc`, `realloc`, and `free`
- Safe input routines for preventing buffer overflow


## Example Screenshot

<p align="center"><strong>Admin Menu</strong></p>
<p align="center">
<img src="images/AdminMenu.png.png" width="350">
<p align="center"><strong>Add/Remove/Menu</strong></p>
<p align="center">
<img src="images/AddRemoveMenu.png.png" width="350">
<p align="center"><strong>List of Cards</strong></p>
<p align="center">
<img src="images/ListCards.png.png" width="350">



##  Getting Started

### Requirements
- GCC-compiler

### Code examples

Below are small code snippets showing how the system handles safe input,
adding cards, and saving/loading card data.

---

## 🔒 Safe User Input
```c
char input[20];
long number;

// Loop until user enters a valid number
while (true) {
    if (GetInput("Enter card number: ", input, sizeof(input)) != INPUT_RESULT_OK)
        break;

    if (parseLong(input, &number)) {
        printf("You entered: %ld\n", number);
        break;
    }

    printf("Invalid number! Try again.\n");
}
```
## Adding new card (simplified example)
```c
Card newCard;
newCard.cardNr = 1234;
newCard.haveAccess = 1;

// Expand list
Card *temp = realloc(cards->allCards,
                     (cards->cardAmount + 1) * sizeof(Card));

if (!temp) {
    printf("Memory allocation failed!\n");
    return;
}

cards->allCards = temp;
cards->allCards[cards->cardAmount] = newCard;
cards->cardAmount++;
```
## 💾 Saving Cards to File
```c
saveCardsToFile(cards, "documentation.txt");
```
## 📂 Loading Cards at Startup
```c
loadCardsFromFile(cards, "documentation.txt");
```
## 📋 Example of saved file format
==CardDocumentation==
Saved: Wed Feb 12 15:24:10 2025

Card 1:
Cardnumber: 1234
Added to system: 2025-02-12
Access: YES :)
__________________________






