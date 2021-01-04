#include <iostream>
#include <fstream>
#include "config.h"
using namespace std;

/**
 * Atrod ierakstu datubāzē, ja neatrada tad atgriež
 * client.accNum = -1;
 **/
clientData recordExists(const int& index)
{
    fstream db;
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
    fstream db;
    index *= sizeof(clientData);
    db.open(DB_NAME, ios::in|ios::out|ios::binary);
        db.seekp(index, db.beg);
        db.write((char*)&client, sizeof(client));
    db.close();
}

/**
 * Atgriež tukšu ieraksta pozīciju datubāzē.
 **/
int getEmptyRecord()
{
    fstream db;
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