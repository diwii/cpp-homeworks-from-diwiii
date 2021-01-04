#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

int findRecord()
{
    int index = 0;
    do {
        cout << "Ievadiet konta nummuru intervālā no 1 - "<< RECORD_LENGTH << endl;
        index = getInputForInt();
    } while (index < 1 || index > RECORD_LENGTH);

    clientData client = recordExists(index-1);

    if (client.accNum != -1) {
        printRecordTitle();
        printRecord(client);
    } else {
        cout << "Ieraksts nav atrasts." << endl;
    }
    return 0;
}