#include <iostream>
#include <fstream>
#include <iomanip>
#include "config.h"
using namespace std;


int selectAllRecords()
{
    fstream db;
    clientData client;
    int w = 20;
    cout << "Visi ieraksti: " << endl;

    db.open(DB_NAME, ios::in|ios::binary);

    db.read((char*)&client, sizeof(client));
    cout << "db good: " << db.good() << endl;
    cout    << setw(w) << "Konta nummurs"
            << setw(w) << "Uzvards"
            << setw(w) << "Vards"
            << setw(w) << "Konta atlikums"
            << endl;
    while (db) {
        if (client.accNum != 0) {
            cout    << setw(w) << client.accNum
                    << setw(w) << client.sur
                    << setw(w) << client.name
                    << setw(w) << setprecision(2) << fixed << client.balance
                    << endl;
        }
        db.read((char*)&client, sizeof(client));
    }
    db.close();

    return 0;
}