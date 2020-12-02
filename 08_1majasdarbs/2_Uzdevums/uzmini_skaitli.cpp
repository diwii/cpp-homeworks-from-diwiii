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
    // RAND_MAX konstantes atlikums dalījumam ar 101. Intervālā no 0-100 ir 101 skaitlis.

    cout    << "Lai izietu no programmas ievadiet \"-1\"" << endl
            << "Uzminiet skaitli no 0-100." << endl;

    for (int counter = 1; counter <= 10; counter++) {
        
        cout << "Mēģinājums: " << counter << endl;

        if (counter == 1) cout << "Ievadiet skaitli: ";
        else cout << "Mēģiniet vēlreiz, ievadiet skaitli: ";

        int ievaditais; // Saglabāsim lietotāja ievadītu skaitli.
        cin >> ievaditais;
        
        // Beidzam programmu
        if (ievaditais == -1) {
            cout << "Izejam!" << endl;
            return 0; 
        }
        
        // Ja uzminēts skaitlis izejam no programmas
        if ( skaitlis == ievaditais ) {
            cout << "Skaitlis uzminēts no " << counter << ". mēģinājuma." << endl;
            return 0;
        }

        if (skaitlis > ievaditais) cout << "Skaitlis ir lielāks par ievadīto." << endl;
        else cout << "Skaitlis ir mazāks par ievadīto." << endl;
        
    }
    
    cout << "Jūs zaudējat! Pareizā atbilde: " << skaitlis << endl;

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0; // Atgriež operētājsistēmai 0
}