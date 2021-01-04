#include <iostream>
#include "config.h"
#include "helperFunctions.h"
#include "dbFunctions.h"

using namespace std;

/**
 * Ievāc datus kurus ierakstīt datubāzē.
 **/
void storeRecord()
{
    clientData client;

    int index = getEmptyRecord();
    // Pārbauda vai datubāze pilna.
    if (index >= RECORD_LENGTH) {
        cout << "Datubāze pilna" << endl;
    } else {
        // Iestata accNum atkarībā no pozīcijas datubāzē +1
        client.accNum = index +1;

        cout << "Ievadiet lietotāja vārdu: " << endl;
        setInputForChar(client.name, sizeof(client.name));

        cout << "Ievadiet lietotāja uzvārdu: " << endl;
        setInputForChar(client.sur, sizeof(client.sur));

        cout << "Ievadiet lietotāja naudu: " << endl;
        client.balance = getInputForFloat();
        // setInputForFloat(client.balance);

        // Ieraksta failā:
        store(index, client);
        cout << "Ieraksts pievienots, konta nr.: " << client.accNum << endl;
    }
}