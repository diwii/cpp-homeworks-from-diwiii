/**
Template
**/

#include <iostream>
#include <fstream>
#include <string>

#include "record/hello.h"
#include "record/config.h"
#include "menu.h"

using namespace std;

int main()
{
    fstream db;
    // CREATE blank DB;
    db.open(DB_NAME);
    if (db.fail()) {
        cout << DB_NAME << " neatveras." << endl;
        cout << "Izveido datubazi un aizpilda to ar " << RECORD_LENGTH << " tukšiem ierakstiem" << endl;

        clientData blank = {0,"","",0};
        db.open(DB_NAME, ios::out|ios::binary);
        for (int i = 0; i<RECORD_LENGTH; i++) {
            db.write((char*)&blank, sizeof(clientData));
        }
        db.close();
    }
    db.close();

    hello();
    menu();
    // system("pause");
    return 0;
}