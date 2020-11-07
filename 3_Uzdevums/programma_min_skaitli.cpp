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

    cout << "Lai izietu no programmas ievadiet \"-1\"" << endl;

    string ievaditais; // Lietotāja ievadītā atbilde.

    int counter = 0; // Minējumu skaits.
    do {
        counter++; // Pieskaitam 1 pie minējumu skaita.

        cout    << "Programma izvēlētais skaitlis ir: " << skaitlis << endl
                << "Vai šis skaitlis ir" << endl
                << "lielāks (>), mazāks (<) vai vienāds(=) ar jūsu izvēlēto skaitli: ";
        cin     >> ievaditais;
        
        if (ievaditais == "-1") {
            cout << "Izejam!" << endl;
            return 0;
        }

        // Ja uzminēts skaitlis izkrītam no cikla.
        if (ievaditais == "=") {
            cout << "Programma uzminēja skaitli no " << counter << ". mēģinājuma." << endl;
            counter = -1; // Izejot no cikla programma pārbaudīs šo mainīgo.
            break; // Izejam no cikla
        }

        // Skaitlis ir lielāks
        if (ievaditais == ">" || ievaditais == "lielāks" || ievaditais == "lielaks") {
            min = skaitlis + 1; // Mainam minimālo robežu
            skaitlis = min + ( max - min-1 ) / 2; // Aprēķinam nākošo skaitli atkarībā no jaunajām robežām.
        }

        // Skaitlis ir mazāks
        if (ievaditais == "<" || ievaditais == "mazāks" || ievaditais == "mazaks") {
            max = skaitlis - 1; // Mainam maksimālo robežu
            skaitlis = min + ( max+1 - min ) / 2; // Aprēķinam nākošo skaitli atkarībā no jaunajām robežām.
        }
    }
    while (counter < 10);

    if (counter != -1) {
        cout << "Jūs uzvarējāt! Programma neuzminēja skaitli ar 10 reizēm." << endl;
    }

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0; // Atgriež operētājsistēmai 0
}