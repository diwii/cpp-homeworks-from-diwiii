/**
 * Balstoties uz clientData struktūras jauztaisa datu bāzi.
 * Jābūt galvenajam menu ar sekojošām izvēlnēm:
 *  Pievienot ierakstu
 *  Dzēst ierakstu
 *  Izvadīt visus ierakstus (tikai tos kas eksistē)
 *  Atrast ierakstu (pēc konta numura)
 *  Izmainīt konta balansu (ievadot konta numuru, un pozitīvo vai negatīvo vērtību, kas jāpiesummē esošai summai)
 *  Izvadīt parādniekus (jāizvada visi ieraksti ar negatīvo balansu)
 *  Saskaitīt ierakstus (izvadīt esošu ierakstu skaitu)
 *  Izveidot datu bāzes kopiju (veido failu ar DB kopiju)
 *  Iziet (izeja no programmas)
 * 
 * Speciālās prasības:
 *  Katrai operācijai jāizveido atsevišķu funkciju.
 *  Failā ir 100 ieraksti.
 *  Visām funkcijām jāatrodas atsevišķā header failā.
 *  Pēc katras operācijas izpildes programmai no jauna jāizvada galveno menu.
**/

#include <iostream>
#include <fstream>
#include <string>

#include "record/config.h"
#include "dummyRecords.h"
#include "menu.h"

using namespace std;

int main()
{
    fstream db;
    /**
     * Ja datubāzes fails netika atrasts, izveido datubāzes failu ar nosaukumu, kurš glabājas iekš DB_NAME.
     * Un aizpilda to ar RECORD_LENGTH dummy ierakstiem.
     **/
    db.open(DB_NAME);
    if (db.fail()) {
        cout << DB_NAME << " neatveras." << endl;
        cout << "Izveido datubāzes failu un aizpilda to ar " << RECORD_LENGTH << " dummy ierakstiem" << endl;

        dummyRecords();
    }
    db.close();

    // Nav izejas no cikla.
    while (1) {
        menu();
    }

    return 0;
}