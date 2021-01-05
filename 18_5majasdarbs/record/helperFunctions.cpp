#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "config.h"
using namespace std;

/**
 * Pārbauda vai ieraksts eksistē.
 **/
bool recordExists()
{
    
}
/**
 * Atgriež skaitli, vai kļūda kamēr nav ievadīts skaitlis.
 **/
int getInputForInt()
{
    int i;
    cin >> i;
    while (cin.fail()) {
        cout << "Kļūda, ievadiet ciparus" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> i;
    }
    return i;
}
/**
 * Atgriež float, vai kļūda kamēr nav ievadīti cipari.
 **/
float getInputForFloat()
{
    float f;
    cin >> f;
    while (cin.fail()) {
        cout << "Kļūda, ievadiet ciparus" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> f;
    }
}
/**
 * Paņem no ievades noteiktu simbolu skaitu, vai kļūda
 * kamēr ievadīts pareizs simbolu skaits.
 **/
void setInputForChar(char* field, int size)
{
    string input;
    getline(cin, input);
    while (input.length() > size-1) {
        cout << "Max " << size-1 << " simboli, tika ievadīti: " << input.length() << endl;
        getline(cin, input);
    }
    strcpy(field, input.c_str());
}
/**
 * Konta nummura ievade
 **/
int requestRecordIndex()
{
    int index = 0;
    do {
        cout << "Ievadiet konta nummuru intervālā no 1 - "<< RECORD_LENGTH << endl;
        index = getInputForInt();
    } while (index < 1 || index > RECORD_LENGTH);

    return index;
}
/**
 * Izvada Ierakstu virsrakstus.
 **/
void printRecordTitle()
{
    cout    << setw(TAB_WIDTH) << "Konta nummurs"
            << setw(TAB_WIDTH) << "Uzvards"
            << setw(TAB_WIDTH) << "Vards"
            << setw(TAB_WIDTH) << "Konta atlikums"
            << endl;
}
/**
 * Izvada Ieraksta saturu.
 **/
void printRecord(clientData& client)
{
    cout    << setw(TAB_WIDTH) << client.accNum
            << setw(TAB_WIDTH) << client.sur
            << setw(TAB_WIDTH) << client.name
            << setw(TAB_WIDTH) << setprecision(2) << fixed << client.balance
            << endl;
}