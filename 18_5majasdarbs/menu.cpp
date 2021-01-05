#include <iostream>
#include <fstream>
#include <string>

// #include "record/menuFunctions.h"
#include "record/storeRecord.h"
#include "record/removeRecord.h"
#include "record/printAllRecords.h"
#include "record/findRecord.h"
#include "record/editRecord.h"
using namespace std;

int getInput();

struct menuItem{
    string label;
    int index;
};

void printMenu();

void menu()
{
    printMenu();
    switch(getInput()) {
        case 1: storeRecord();
        break;
        case 2: removeRecord();
        break;
        case 3: printAllRecords();
        break;
        case 4: findRecord();
        break;
        case 5: editRecord();
        break;
    }
    // cout << "input: " << getInput() << endl;
}

void printMenu() {
    int N = 9;
    menuItem item[N];
    
    item[0].label = "(1) Pievienot ierakstu.";
    item[0].index = 1;
    item[1].label = "(2) Dzēst ierakstu.";
    item[1].index = 2;
    item[2].label = "(3) Izvadīt visus ierakstus.";
    item[2].index = 3;
    item[3].label = "(4) Atrast ierakstu.";
    item[3].index = 4;
    item[4].label = "(5) Izmainīt konta atlikumu.";
    item[4].index = 5;
    item[5].label = "(6) Izvadīt parādniekus.";
    item[5].index = 6;
    item[6].label = "(7) Saskaitīt ierakstus.";
    item[6].index = 7;
    item[7].label = "(8) Izveidot datubāzes kopiju.";
    item[7].index = 8;
    item[8].label = "(9) Iziet.";
    item[8].index = 9;

    // Izvada uz ekrāna menu list
    for (int i = 0; i<N; i++) {
        cout << item[i].label << endl;
    }
}

/**
 * Pārbauda vai ievadītais simbols ir viens no cipariem.
 **/
bool isBetween(char c)
{
    if ((int)c >= 48 && (int)c <= 57 ) return true;
    return false;
}
/**
 * Atgriež ievadīto ciparu.
 **/
int getInput()
{
    string input;
    char character = '\0';
    // Kamēr simbols nav viens no cipariem, pieprasa ievadi.
    while (!isBetween(character)) {
        // cin >> character;
        getline(cin, input);
        character = input.c_str()[0];
    }

    int i = atoi(&character);
    return i;
}