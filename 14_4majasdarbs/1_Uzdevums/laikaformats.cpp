/**
 * 1. Uzdevums
 * 
 * Programma pieprasa laiku formātā hh:mm:ss un
 * pārbauda ievades korektumu, izvadot atbilstošu ziņojumu, piemēram:
 *  - 23:09:03 - pareizi,
 *  - 2:2:2 - nepareizs formāts,
 *  - 12:02:94 - nepareizs laiks,
 *  - 14.05.35 - nepareizs formāts,
 *  - qw2:we34 - nepareizs formāts.
**/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string input;
    string timeDigits;
    string errors = "\0";

    cout << "Ievadiet laiku formātā HH:MM:SS" << endl;
    getline(cin, input);

    if (input.length() > 8) {
        cout << "Max 8 simboli, tika ievadīti: " << input.length()
             << ", tiks pārbaudīti pirmie 8." << endl;
    }
    
    for ( int i = 0; i < 8 && i < input.length(); i++ ) {
        if ( (i+1) % 3 == 0 ) {
            if (input[i] != ':') {
                stringstream message;
                message << "Nepareizs formāts, laika cipari jāatdala ar \":\". Tika atdalīts ar -> " << input[i] << "|";
                errors.append(message.str());
            }
            continue;
        }

        if ( isdigit(input[i]) == 1 ) {
            timeDigits.append(1, input[i]);
        } else {
            stringstream message;
            message << "Nepareizs formāts -> " << input[i] << " <- nav cipars" << "|";
            errors.append(message.str());
        }
    }

    if (timeDigits.length() == 6) {

        int hh = stoi(timeDigits.substr(0,2));
        int mm = stoi(timeDigits.substr(2,2));
        int ss = stoi(timeDigits.substr(4,2));

        if (hh > 24) {
            stringstream message;
            message << "Nepareizs laiks, max 24h. -> " << hh << "|";
            errors.append(message.str());
        }
        if (mm > 59 || ss > 59) {
            stringstream message;
            message << "Nepareizs laiks, max 59 minutes vai sekundes. -> " << "minutes: " << mm << ", " << "sekundes: " << ss << "|";
            errors.append(message.str());
        }
    } else {
        stringstream message;
        message << "Nepieciešami 6 cipari -> HH:MM:SS.";
        errors.append(message.str());
    }
    
    if (errors.length() == 0) {
        cout << "Pareizi!" << endl;
        return 0;
    }

    int found = errors.find('|', 0);
    do {
        errors.replace(found, 1, "\n");
        found = errors.find('|', found+1);
    }
    while ( found != string::npos);

    cout << errors << endl;
    
    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0;
}