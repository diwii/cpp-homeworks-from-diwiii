#include <iostream>
#include "config.h"
#include "dbFunctions.h"
using namespace std;

int totalRecords = 0;

/**
 * Argumentfunkcija select funkcijai
 * Ja funkcija tiek izsaukta pieskaita +1 iekš totalRecords.
 **/
void recordCounter(clientData& client)
{
    totalRecords++;
}

/**
 * Saskaita un izvada ierakstus datubāzē.
 **/
void countRecords()
{
    select(allRecords, recordCounter);
    cout << "Ieraksti datubāzē: " << totalRecords << endl;
}