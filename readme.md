# Card Access Simulator (Schoolproject)

# Card Access Simulator 

A modular C program simulating a basic card-based door access system.

This project was built as part of my programming course and focuses on:
- Modular C design
- File handling
- Structured project organization
- Makefile-based build system

---

## Features

- Add and remove access cards
- Simulate scanning a card
- Door open/close logic
- File-based storage
- Input validation (safe input handling)

---

## 🏗 Project Structure

C-1006/
├── src/ # Source files (.c)
├── include/ # Header files (.h)
├── Makefile
├── README.md
└── .gitignore


The project uses separate compilation and object files.

---

## 🔧 Build

```bash
make

make run

./card_simulator

make clean



## Example Screenshots

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
- GCC compiler
- Standard C libraries (stdlib.h, stdio.h, string.h, time.h, errno.h)
- POSIX-compatible system for sleep() (or Windows using Sleep() from windows.h)
- Terminal/console with standard input/output support
- Optional: text editor to view saved files (documentation.txt)

### Code examples

Below are small code snippets showing how the system handles safe input,
adding cards, and saving/loading card data.

---

## Safe User Input
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
## Saving Cards to File
```c
saveCardsToFile(cards, "documentation.txt");
```
## Loading Cards at Startup
```c
loadCardsFromFile(cards, "documentation.txt");
```
## Suggestions for Improvement

- Add the ability to log all card scans with timestamps
- Make the program portable between Windows and Linux/macOS
- Implement a password-protected admin menu
- Enhance the menu with colors or ASCII symbols for better readability
- Add error handling for file read/write operations
- Include unit tests for critical functions like safe input and card management
- Allow batch import/export of cards from/to a file
- Add encryption to stored card data






