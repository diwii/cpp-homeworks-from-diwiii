#include <iostream>
#include <fstream>
#include "config.h"
#include "helperFunctions.h"
using namespace std;

fstream db;

/**
 * Atrod ierakstu datubāzē, ja neatrada tad atgriež
 * client.accNum = -1;
 **/
clientData recordExists(const int& index)
{
    clientData client;

    db.open(DB_NAME, ios::in|ios::binary);
    db.seekg(index*sizeof(client), db.beg);
    db.read((char*)&client, sizeof(clientData));
    db.close();

    if (client.accNum != 0) return client;
    
    client.accNum = -1;
    return client;
}

/**
 * Veic ierakstu Datubāzē.
 **/
void store(int& index, clientData& client)
{
    index *= sizeof(clientData);

    db.open(DB_NAME, ios::in|ios::out|ios::binary);
    db.seekp(index, db.beg);
    db.write((char*)&client, sizeof(clientData));
    db.close();
}

/**
 * Atgriež tukšu ieraksta pozīciju datubāzē.
 **/
int getEmptyRecord()
{
    clientData client;
    int index = 0;
    
    db.open(DB_NAME, ios::in|ios::binary);
    for (index; index < RECORD_LENGTH; index++) {

        db.seekg(index*sizeof(client), db.beg);
        db.read((char*)&client, sizeof(client));

        if (client.accNum == 0) break;
    }
    db.close();

    return index;
}
/**
 * Izvēlas ierakstus kuri atbilst padotās "opt" funkcijas prasībām.
 * Izpilda padotās doOpt funkcijas uzdevumus.
 **/
void select(selectOption opt, doOption doOpt)
{
    clientData client;

    db.open(DB_NAME, ios::in|ios::binary);
    db.read((char*)&client, sizeof(client));
    while (db) {
        if (opt(client)) {
            doOpt(client);
            // printRecord(client);
        }
        db.read((char*)&client, sizeof(client));
    }
    db.close();
}
/**
 * Papildfunkcija select funkcijai.
 * 
 * Pārbauda vai nodotā client.accnum nav 0 un atgriež true.
 **/
bool allRecords(clientData& client)
{
    if (client.accNum != 0 ) return true;
    return false;
}