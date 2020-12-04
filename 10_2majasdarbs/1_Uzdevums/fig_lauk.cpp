/**
 * 1. Uzdevums
 * 
 * Aprakstiet funkciju double circle_area(double R) 
 * kura aprēķina riņķa laukumu, (R - riņķa rādiuss).
 * Izmantojot to, aprēķiniet iesvītrotās figūras laukumu, pieprasot R1 un R2.
**/

#include <iostream>
using namespace std;

// Deklarē konstanti
const double PI = 3.14159;

// Aprēķina un atgriež riņķa laukumu
double circle_area(double R)
{
    return PI*(R*R);
}
/**
 * Aprēķina figūras laukumu.
 * No lielā(L1) riņķa laukuma atņemam mazo(L2) riņķa laukumu un
 * pieskaitam 2 reiz mazākos(L3) riņķa laukumus.
**/
double figure_area(double R1, double R2)
{
    // Sadala L2 radiusu, kas ir L3 diametrs, lai iegūtu R3.
    double R3 = R2/2;
    return circle_area(R1) - circle_area(R2) + (2 * circle_area(R3));
}

int main()
{
    double R1, R2;

    cout << "Ievadiet radiusu R1: ";
    cin >> R1;
    cout << "Ievadiet radiusu R2: ";
    cin >> R2;

    cout << "Figūras laukums: " << figure_area(R1,R2) << " kvadrātā"<< endl;

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0; // Atgriež operētājsistēmai 0
}