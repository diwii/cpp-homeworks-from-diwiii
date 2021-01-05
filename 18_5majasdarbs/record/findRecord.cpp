#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

void findRecord()
{
    cout << "Atrast ierakstu" << endl;

    int index = requestRecordIndex() -1;

    clientData client = recordExists(index);

    if (client.accNum != -1) { // Pārbauda vai ieraksts atrasts
        printRecordTitle();
        printRecord(client);
    } else {
        cout << "Ieraksts nav atrasts." << endl;
    }
}