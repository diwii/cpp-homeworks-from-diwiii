/**
 * 1. Uzdevums
 * Sauksim skaitli par palindromu ja lasot to no otras puses tas nemainās.
 * 
 * b. Uzrakstiet programmu kas izvada visus 6-ciparu palindromus.
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
    int skaitlis = 100000; // Skaitīšana sāksies ar 0.
    int otradi; // Tiks saglabāts skaitlis no otras puses.

    int pedejaiscipars; // Saglabās ievadītā skaitļa pēdējo ciparu.
    int temp; // Saglabāsies skaitlis ar kuru tiek veiktas manipulācijas.

    while (skaitlis < 1000000) {
        
        temp = skaitlis;
        otradi = 0; // Parūpējas, lai katrā iterācijā skaitlis būtu 0.

        // Cikls atkārtosies līdz pagaidu mainīgajā būs skaitlis lielāks par nulli.
        while (temp > 0) {
            // Izmantojot modulo operatoru noskaidrojam dotā skaitļa pēdējo ciparu.
            pedejaiscipars = temp % 10;

            // Pareizinam esošo skaitli ar 10,
            // lai tas būtu par vienu desmitu tālāk par pieskaitāmo pēdējo ciparu.
            otradi = otradi * 10 + pedejaiscipars;

            // Pagaidu maingā skaitli dalam ar 10, lai samazinātu pagaidu skaitli par 1 desmitu.
            // Tā kā tas ir integer datu tips, skaitlis tiek dalīts un saglabāts bez atlikuma.
            temp = temp / 10;
        }

        if (skaitlis == otradi) {
            cout << skaitlis << endl;
        }

        skaitlis++;
    }

    // system("pause"); Operētājsistēmas specifiska komanda/konstrukcija.
    return 0; // Atgriež operētājsistēmai 0
}