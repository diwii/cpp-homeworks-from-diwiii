/**
 * 3. Uzdevums
 * 
 * Lietotājs izdomā skaitli no 0 - 100 un programma mēģina uzminēt.
 * Programmā nav jāievada minējamo skaitli.
 * Programmai ir jauzmin skaitli no 10 mēģinājumiem.
 * 
**/

#include <iostream> // Input/Output plūsmas atbalsts
using namespace std; // Izmantot nosaukumus no C++ standarta bibliotēkas

int main()
{
    int max = 100; // Maksimālais skaitlis.
    int min = 0; // Minimālais skaitlis.
    int skaitlis = (max - min) / 2; // Skaitlis ko programma izvadīs.
    char ievaditais; // Lietotāja ievadītā atbilde.

    cout << "Lai izietu no programmas ievadiet \"!\"" << endl;

    for (int counter = 1; counter <= 10; counter++) { // Sākam skaitīt ar 1, jo uzreiz tiek veikts pirmais minējums.
    
        cout    << "Mēģinājums: " << counter << endl   
                << "Programma izvēlētais skaitlis ir: " << skaitlis << endl
                << "Vai šis skaitlis ir" << endl
                << "lielāks (>), mazāks (<) vai vienāds (=) par jūsu izvēlēto skaitli: ";
        cin     >> ievaditais;

        switch(ievaditais) {
            case '!':
                // Beidzam programmu
                cout << "Izejam!" << endl;
                return 0;
            case '=':
                // Ja uzminēts skaitlis izejam no programmas
                cout << "Programma uzminēja skaitli no " << counter << ". mēģinājuma." << endl;
                return 0;
            case '>':
                min = skaitlis + 1; // Mainam minimālo robežu
                skaitlis = min + ( max - min-1 ) / 2; // Aprēķinam nākošo skaitli atkarībā no jaunajām robežām.
                break;
            case '<':
                max = skaitlis - 1; // Mainam maksimālo robežu
                skaitlis = min + ( max+1 - min ) / 2; // Aprēķinam nākošo skaitli atkarībā no jaunajām robežām.
                break;
            default:
                cout << endl << "Lūdzu izvēlieties vienu no (>),(<),(=),(!)." << endl;
                counter--;
        }
    }
    
    cout << "Jūs uzvarējāt! Programma neuzminēja skaitli ar 10 reizēm." << endl;

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0; // Atgriež operētājsistēmai 0
}