/**
 * 2. Uzdevums
 * 
 * Kādā autostāvvietā minimāla maksa par auto novietošanu ir 2Ls.
 * Gadījumā ja auto paliek stāvvietā ilgāk par 3 stundām,
 * papildus jāmaksā 0,50Ls par katru stundu. 
 * Bet maksimāla diennakts maksa ir 10Ls.
 * Jāuzraksta funkciju, lai ievadot stundu skaitu saņemtu maksu par autostāvvietu
 * (pieņemsim ka neviens neatstāj mašīnu vairāk ka uz vienu diennakti).
 * 
 * Piemērs:
 * 1,5 -> 2,00
 * 4,0 -> 2,50
 * 24,0 -> 10,00
**/

#include <iostream> // Input/Output plūsmas atbalsts
using namespace std; // Izmantot nosaukumus no C++ standarta bibliotēkas

double maksa(double stundas)
{
    // Ja nenovietoja auto.
    if (stundas <= 0) return 0;

    double maksa = 2.00;

    while(stundas > 3 && maksa < 10 ) {
        maksa += 0.50;
        stundas -= 1;
    }

    return maksa;
} 

int main()
{
    cout << "Ievadiet autostāvvietas stundas: ";
    double stundas;
    cin >> stundas;

    cout << "Maksa par autostāvvietu: " << maksa(stundas) << endl;  

    return 0;
}