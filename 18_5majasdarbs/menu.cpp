#include <iostream>
#include <string>

#include "record/config.h"
#include "record/storeRecord.h"
#include "record/removeRecord.h"
#include "record/printAllRecords.h"
#include "record/findRecord.h"
#include "record/editRecord.h"
#include "record/printNegativeRecords.h"
#include "record/countRecords.h"
#include "record/backup.h"
using namespace std;

int getInput();
void printMenu();

/**
 * Izvada menu, gaida ievadi.
 * Izsauc funkciju balstoties uz ievadīto skaitli.
 **/
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
        case 6: printNegativeRecords();
        break;
        case 7: countRecords();
        break;
        case 8: backup();
        break;
        case 9: exit(0);
        break;
    }
}

/**
 * Izvada menu tekstus.
 */
void printMenu() {

    string line(TAB_WIDTH*4, '-');
    cout << line << endl;
    
    cout    << "(1) Pievienot ierakstu." << endl
            << "(2) Dzēst ierakstu." << endl
            << "(3) Izvadīt visus ierakstus." << endl
            << "(4) Atrast ierakstu." << endl
            << "(5) Izmainīt konta atlikumu." << endl
            << "(6) Izvadīt parādniekus." << endl
            << "(7) Saskaitīt ierakstus." << endl
            << "(8) Izveidot datubāzes kopiju." << endl
            << "(9) Iziet." << endl;
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
 * Pārbauda vai ievadītais simbols ir cipars.
 * Atgriež ievadīto ciparu.
 * Kļūda kamēr simbols nav cipars.
 **/
int getInput()
{
    string input;
    char character = '\0';
    // Kamēr simbols nav viens no cipariem, pieprasa ievadi.
    while (!isBetween(character)) {
        getline(cin, input);
        character = input.c_str()[0];
    }

    int i = atoi(&character);
    return i;
}