#include <iostream>
#include <fstream>
#include <string>
#include "config.h"
using namespace std;

/**
 * Pieprasa faila nosaukumu, kurā saglabāt datubāzes kopiju.
 **/
void backup()
{
    cout << "Izviedot datubāzes kopiju." << endl;

    fstream dbIn;
    fstream dbOut;

    const int SIZE = sizeof(clientData);
    // Kopēšana notiks pa 36 baitiem, kas ir clientData vienas struktūras izmērs.
    char buffer[SIZE];
    // Kopijas faila nosaukums.
    string backupName;

    cout << "Kopijas nosaukums: " << endl;
    getline(cin, backupName);

    dbIn.open(DB_NAME, ios::in|ios::binary);
    dbOut.open(backupName, ios::out|ios::binary);

    while(dbIn) {
        dbIn.read(buffer, SIZE);
        // gcount() atgriež nolasīto baitu daudzumu write funkcijai, lai zinātu cik baitus jāieraksta
        dbOut.write(buffer, dbIn.gcount());
    }

    dbIn.close();
    dbOut.close();

    cout << "Kopija izveidot failā: " << backupName << endl;
}