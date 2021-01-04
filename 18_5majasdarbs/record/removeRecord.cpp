#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"
using namespace std;

/**
 * Izdzēš
 **/
int removeRecord()
{
    cout << "Izdzēst ierakstu" << endl;
    int index = 0;
    do {
        cout << "Ievadiet konta nummuru intervālā no 1 - "<< RECORD_LENGTH << endl;
        index = getInputForInt();
    } while (index < 1 || index > RECORD_LENGTH);

    clientData client = recordExists(index-1);
    clientData blank = {0,"","",0};

    if (client.accNum != -1) {
        index = client.accNum -1;
        store(index, blank); // Saglabā tukšu ierakstu.
        cout << "Ieraksts ar konta nr.: " << client.accNum << " izdzēsts!" << endl;
    } else {
        cout << "Ieraksts nav atrasts." << endl;
    }

    return 0;
}