#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

/**
 * Aizvieto ierakstu ar tukšu ierakstu.
 **/
int removeRecord()
{
    cout << "Izdzēst ierakstu" << endl;
    
    int index = requestRecordIndex() -1;

    clientData client = recordExists(index);
    clientData blank = {0,"","",0};

    if (client.accNum != -1) {
        store(index, blank); // Saglabā tukšu ierakstu.
        cout << "Ieraksts ar konta nr.: " << client.accNum << " izdzēsts!" << endl;
    } else {
        cout << "Ieraksts nav atrasts." << endl;
    }

    return 0;
}