/**
 * Nolasa vārdus un uzvārdus no names.txt, surnames.txt.
 * Uzģenerē random konta atlikumus.
 * Izveido ierakstus datubāzē.
**/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

#include "record/config.h"

using namespace std;

time_t t;

/**
 * Ierakstu daudzums.
 **/
const int N = RECORD_LENGTH;

/**
 * Failu nosaukumi kur glabājas vārdi un uzvārdi.
 **/
const string NAME_FILE = "dummy/names.txt";
const string SURN_FILE = "dummy/surnames.txt";

/**
 * Nolasa vārdus no faila un saglabā name[], surname[] massīvos.
 **/
void readNamesFromFile();
string name[N]; // Vārdu massīvs.
string surname[N]; // Uzvārdu massīvs.

/**
 * Atgriež random indeksu massīviem, atgriesto indeksu saglabā massīvā used.
 **/
int nextIndex(int* used);
int usedName[N] = {0}; // Lietotu indeksu massīvs.
int usedSur[N] = {0}; // Lietotu indeksu massīvs.

/**
 * Atgriež random skaitli: int, float, negatīvs, pozitīvs.
 **/
float randBalance();

// struct clientData
// {
//     int accNum;
//     char sur[15];
//     char name[10];
//     float balance;
// };

/**
 * Cikls saliek datus vienā clientData struktūrā un saglabā client[] massīvā.
 **/
void generateClient();
clientData client[N];

/**
 * Ieraksta Datubāzē.
 **/
void writeClientToDB();

void dummyRecords()
{
    srand((unsigned) time(&t));

    readNamesFromFile();

    generateClient();

    writeClientToDB();
}

void readNamesFromFile()
{
    fstream name_f;
    fstream surname_f;

    name_f.open(NAME_FILE, ios::in);
    surname_f.open(SURN_FILE, ios::in);
    
    if (name_f.good() && surname_f.good()) {
        for (int i = 0; i<N || name_f.fail() || surname_f.fail(); i++) {
            getline(name_f, name[i]);
            getline(surname_f, surname[i]);
        }
    } else {
        cout << "error, dis not wok!" << endl;
        exit(1);
    }

    name_f.close();
    surname_f.close();
}

int nextIndex(int* used)
{
    int index;
    while (true) {
        index = rand() % N;
        if (used[index] == 0) {
            used[index] = 1;
            return index;
        }
    }
}

float randBalance()
{
    int sign = rand() % 2;
    int whole = rand() % 2001;
    float f = rand() % 100 / (double(100));
    
    f += whole;
    if (sign) f*=-1;

    return f;
}

void generateClient() {
    for (int i=0; i<N; i++) {
        client[i].accNum = i +1;
        strcpy(client[i].name, name[nextIndex(usedName)].c_str());
        strcpy(client[i].sur, surname[nextIndex(usedSur)].c_str());
        client[i].balance = randBalance();
    }
}

void writeClientToDB()
{
    fstream db;
    db.open(DB_NAME, ios::out|ios::binary);

    for (int i = 0; i<N; i++) {
        db.write((char*)&client[i], sizeof(clientData));
    }
    
    db.close();
}