#include <string>
using namespace std;

/**
 * Datubāzes faila nosaukums.
 **/
const string DB_NAME = "client.data";
/**
 * Datubāzes ierakstu tilpums.
 **/
const int RECORD_LENGTH = 100;
/**
 * iomanip platums starp kolonnām.
 **/
const int TAB_WIDTH = 20;
/**
 * Datubāzes ieraksta struktūra.
 **/
struct clientData {
    int accNum = 0;
    char sur[15] = "";
    char name[10] = "";
    float balance = 0.00;
};
/**
 * Select record funkciju prototipi,
 * dod iespēju padot funkciju kā argumentu.
 **/
typedef bool selectOption(clientData& client);
typedef void doOption(clientData& client);