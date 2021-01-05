#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

/**
 * Izvada visus ierakstus.
 **/
void printAllRecords()
{
    cout << "Visi ieraksti: " << endl;
    
    printRecordTitle();

    select(allRecords, printRecord);
}