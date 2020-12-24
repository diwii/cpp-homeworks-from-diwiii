/**
 * 1. Uzdevums
 * 
 * Ar gadījuma ģeneratora palīdzību aizpildiet
 * divdimensiju masīvu NxN ar skaitļiem intervālā 10-99,
 * un izvadiet to uz ekrānu.
 * Pagrieziet masīvu uz 90° pulksteņrādītāju virzienā.
 * Izvadiet rezultātu uz ekrānu.
**/

#include <iostream>
#include <ctime> // Bibliotēka manipulācijai ar Datuma un Laika informāciju.
using namespace std;

time_t t; // Mainīgais kurā saglabāsim laiku.
const int N = 3; // Masīva garums.

int main()
{
    srand((unsigned) time(&t)); // Inicializējam gadījumskaitļu ģenerātoru.
    int matrica[N][N] = {0}; // Inicializējam massīvu.

    /**
     * Aizpilda 2 dimensiju massīvu ar gadījumskaitļiem no 10 - 99.
    **/
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            matrica[i][j] = rand() % 90 + 10;
            cout << matrica[i][j] << " ";
        }
        // Katra ārējā cikla beigās ievietojam endl, lai masīvu vizualizētu kā matricu.
        cout << endl;
    }

    cout << endl;

    /**
     * Printējam massīvu itkā matrica būtu pagriezta uz 90 grādiem.
    **/
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << matrica[N-1-j][i] << " ";
        }
        cout << endl; 
    }

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0;
}