/**
 * 1. Uzdevums
 * Sauksim skaitli par palindromu ja lasot to no otras puses tas nemainās.
 * 
 * a. Uzrakstiet programmu kas pēc dotā ievadītā n pārbauda vai tas ir palindroms.
**/

#include <iostream> // Input/Output plūsmas atbalsts
using namespace std; // Izmantot nosaukumus no C++ standarta bibliotēkas

/*
 * Galvenā programmas funkcija
 * int nozīmē ka programma atgriezīs operetājsistēmai veselo skaitli.
*/
int main() // Galvenā programmas funkcija
{
    // Mainīgo definēšana
    int skaitlis = 0; // Tiks saglabāts ievadītais skaitlis.
    int otradi = 0; // Tiks saglabāts skaitlis no otras puses.

    cout << "Ievadiet skaitli:";
    cin >> skaitlis;

    int pedejaiscipars = 0; // Saglabās ievadītā skaitļa pēdējo ciparu.
    int temp = skaitlis; // Saglabāsies skaitlis ar kuru tiek veiktas manipulācijas.

    // Cikls atkārtosies līdz pagaidu mainīgajā būs skaitlis lielāks par nulli.
    while (temp > 0) {
        // Izmantojot modulo operatoru noskaidrojam ievadītā skaitļa pēdējo ciparu.
        pedejaiscipars = temp % 10;
        // Pareizinam esošo skaitli ar 10,
        // lai tas būtu par vienu desmitu tālāk par pieskaitāmo pēdējo ciparu.
        otradi = otradi * 10 + pedejaiscipars;
        // Pagaidu maingā skaitli dalam ar 10, lai samazinātu pagaidu skaitli par 1 desmitu.
        // Tā kā tas ir integer datu tips, skaitlis tiek dalīts un saglabāts bez atlikuma.
        temp = temp / 10;
    }

    cout << "Skiatlis no otras puses: " << otradi << endl;

    if (skaitlis == otradi) {
        cout << "Ievadītais skaitlis ir palindroms." << endl;
    } else {
        cout << "Ievadītais skaitlis nav palindroms." << endl;
    }

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0; // Atgriež operētājsistēmai 0
}