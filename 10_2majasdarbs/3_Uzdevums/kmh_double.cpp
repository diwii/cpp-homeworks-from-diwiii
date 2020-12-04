/**
 * 3. Uzdevums
 * 
 * Aprakstiet funkciju int vms(int Vkmh)
 * kura pārveido ātrumu Vkmh no km/h metros sekundē.
 * Izmantojiet šo funkciju citā funkcijā
 * int meet_time(int kmh1, int kmh2, int km)
 * kur kmh1 un kmh2 divu pretī braucošu objektu ātrumi,
 * un km attālums starp objektiem. Funkcija atgriež objektu tikšanas laiku sekundēs.
**/

#include <iostream>
using namespace std;

/**
 * Pārveido km/h uz m/s.
 * Atgriežot double datu tipu iegūst precīzāku pārveidojumu.
 */
double Vms(int Vkmh)
{
    return Vkmh / 3.6;
}
/**
 * Atgriež tikšanās laiku sekundēs.
**/
int meet_time(int kmh1, int kmh2, int km)
{
    // Pārveido attāluma kilometrus metros.
    double attalums = km * 1000;
    return attalums / (Vms(kmh1)+Vms(kmh2));
}

int main()
{
    int kmh1, kmh2, km;

    cout << "attālums(km): ";
    cin >> km;
    cout << "1.objekta ātrums(kmh): ";
    cin >> kmh1;
    cout << "2.objekta ātrums(kmh): ";
    cin >> kmh2;

    cout << "Objekti satiksies pēc " << meet_time(kmh1, kmh2, km) << " sekundēm." << endl;

    return 0;
}