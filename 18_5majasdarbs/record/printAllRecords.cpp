#include <iostream>
#include <fstream>
#include <iomanip>
#include "config.h"
#include "helperFunctions.h"
using namespace std;


int printAllRecords()
{
    fstream db;
    clientData client;

    cout << "Visi ieraksti: " << endl;

    db.open(DB_NAME, ios::in|ios::binary);
    db.read((char*)&client, sizeof(client));
    printRecordTitle();
    while (db) {
        if (client.accNum != 0) {
            printRecord(client);
        }
        db.read((char*)&client, sizeof(client));
    }
    db.close();

    return 0;
}