#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

/**
 * Izmaina ierakstu
 **/
int editRecord()
{
    cout << "Izmainīt ierakstu" << endl;
    
    int index = requestRecordIndex() -1;

    clientData client = recordExists(index);

    if (client.accNum != -1) {
        printRecordTitle();
        printRecord(client);
        cout << "Ievadiet konta atlikumu: " << endl;
        client.balance = getInputForFloat();
        store(index, client); // Saglabā izmaiņas.
        cout << "Konta nr.: " << client.accNum << " atlikums izmainīts: " << client.balance << endl;
    } else {
        cout << "Ieraksts nav atrasts." << endl;
    }

    return 0;
}