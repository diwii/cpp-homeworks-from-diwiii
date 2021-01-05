#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

/**
 * Papildfunkcija select funkcijai.
 * 
 * Pārbauda vai nodotā client.accnum nav 0 un
 * vai client.balance < 0.
 **/
bool negativeRecords(clientData& client)
{
    if (client.accNum != 0 && client.balance < 0 ) return true;
    return false;
}

/**
 * Izvada visus ierakstus kuriem konta atlikums ir zem 0.
 **/
void printNegativeRecords()
{
    cout << "Parādnieki: " << endl;

    printRecordTitle();

    select(negativeRecords, printRecord);
}