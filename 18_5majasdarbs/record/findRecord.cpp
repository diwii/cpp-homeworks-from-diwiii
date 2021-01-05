#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

int findRecord()
{
    cout << "Atrast ierakstu" << endl;

    int index = requestRecordIndex() -1;

    clientData client = recordExists(index);

    if (client.accNum != -1) {
        printRecordTitle();
        printRecord(client);
    } else {
        cout << "Ieraksts nav atrasts." << endl;
    }
    return 0;
}