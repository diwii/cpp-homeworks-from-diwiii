/**
 * 2. Uzdevums
 * 
 * Jāuzraksta spēli. Programma izdomā skaitli intervālā 0 – 100.
 * Lietotājam to skaitli ir jāuzmin ievadot minēšanas variantus uz klaviatūras.
 * Pēc katra mēģinājuma programma izvada vienu no trim ziņojumiem:
 * 1. “skaitlis ir lielāks par ievadīto”,
 * 2. “skaitlis ir mazāks par ievadīto”,
 * 3. “skaitlis uzminēts no N mēģinājuma”.
 * Maksimāls mēģinājumu skaits – 10.
 * Ja skaitlis nebija uzminēts no 10 mēģinājumiem programmai jāizvada ziņojumu:
 * “Jūs zaudējat! Pareizā atbilde N”
**/

#include <iostream> // Input/Output plūsmas atbalsts
#include <ctime> // Bibliotēka manipulācijai ar Datuma un Laika informāciju
using namespace std; // Izmantot nosaukumus no C++ standarta bibliotēkas

int main()
{
    time_t t; // Mainīgais kurā saglabāsim laiku. 

    srand((unsigned) time(&t)); // Inicializējam gadījumskaitļu ģenerātoru ar funkciju time(),
    // kas ieraksta laiku mainīgajā t. Laika vērtība tiek pārveidota unsigned int tipā.
    // Laiks ir uzņemts sekundēs.

    int skaitlis = rand() % 101; // Uzģenerējam Pseidogadījumskaitli!
    // RAND_MAX konstantes atlikums dalījumam ar 101.

    int ievaditais; // Saglabāsim lietotāja ievadītu skaitli.

    cout    << "Lai izietu no programmas ievadiet \"-1\"" << endl
            << "Uzminiet skaitli no 0-100." << endl;

    int counter = 0; // Saglabāsim cik reizes ir minēts.
    do {
        counter++; // Pieskaitam 1 pie minējumu skaita.
        
        if (counter <= 1) {
            cout << "Ievadiet skaitli: ";
        } else {
            cout << "Mēģiniet vēlreiz, ievadiet skaitli: ";
        }

        cin >> ievaditais;

        if (ievaditais == -1) {
            cout << "Izejam!" << endl;
            return 0;
        }
        // Ja uzminēts skaitlis izkrītam no cikla.
        if ( skaitlis == ievaditais ) {
            cout << "Skaitlis uzminēts no " << counter << ". mēģinājuma." << endl;
            counter = -1; // Izejot no cikla programma pārbaudīs šo mainīgo.
            break;
        }

        if ( skaitlis > ievaditais ) {
            cout << "Skaitlis ir lielāks par ievadīto." << endl;
        }

        if ( skaitlis < ievaditais ) {
            cout << "Skaitlis ir mazāks par ievadīto." << endl;
        }
    }
    while (counter < 10);

    if (counter == 10) {
        cout << "Jūs zaudējat! Pareizā atbilde: " << skaitlis << endl;
    }

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0; // Atgriež operētājsistēmai 0
}