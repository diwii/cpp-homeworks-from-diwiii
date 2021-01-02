/**
 * 1. Uzdevums
 * 
 * Uztaisīt spēli: “Vārdu minēšana”. 
 * Jāsagatavo masīvu ar vismaz 20 vārdiem.
 * Uzsākot spēli ar gadījuma ģeneratora palīdzību tiek izvēlēts viens no vārdiem.
 * Burtu skaitu jāatspoguļo ar atbilstošo punktu “.” skaitu un
 * pēc veiksmīga minējuma attiecīgā vietā punktu jāaizvieto ar burtu (vairākās vietās ja burti ir vairāki).
 * Burtu ievadei jānotiek bez “Enter” nospiešanas.
 * Par nepareizo burtu piešķir 1 soda punktu.
 * Spēle turpinās kamēr spēlētājs nesavāks 10 soda punktus, vai kamēr burtu vietā neievadīs “0”.
 * Pēc katra uzminēta vārda spēlētājam sadeg 5 soda punkti, ja tādi viņam ir
 * (nedrīkst būt negatīvs soda punktu skaits!).
 * Un piedāvāts nākamais vārds (vārdi nedrīkst atkārtoties!).
 * Spēles beigās jāizvada uzminēto vārdu skaitu. Vai apsveikumu ja bija uzminēti visi vārdi :)
 * 
**/

#include <iostream>
#include <string>
#include <ctime>
// #include <conio.h>
using namespace std;

time_t t;
bool loop = true;
const int N = 20;
const string words[N] {"cirvis", "gads", "ritenis", "ledusskapis", "zebra",
                        "ragavas", "zirgs", "gulta", "policists", "dators",
                        "traktors", "ziepes", "egle", "paugurs", "lelle",
                        "klints", "hidroelektrostacija", "burts", "olas", "oktobris"};
int used[N] {0}; // Lietotu indeksu massīvs.
int penalty = 0; // Soda punkti.
int score = 0; // Uzminēto vārdu skaits.

/**
 * Atgriež random indeksu massīvam "words".
 **/
int nextIndex();

/**
 * Sadedzina 5 soda punktus.
 **/
void burnPenalty();

int main()
{
    srand((unsigned) time(&t));

    char input; // Glabā ievadīto simbolu.
    int position = 0; // Meklēšanas sākumpozīcija.

    // Cikls atkārtojas tik reizes cik vārdu massīvā elementu.
    for (int i=0; i<N; i++) {
        // Paņem vārdu no vārdu massīva.
        string word = words[nextIndex()];
        // Izveido string kura garums ir mināmā vārda garums, un katrs string elements ir punkts.
        string hidden(word.length(), '.');

        cout << "Uzminēti vārdi: " << score << endl;
        if (!loop) break; // Iziet no cikla, ja nevajag turpināt.

        // Kamēr vārds nav uzminēts.
        while (word != hidden) {
            // Soda punkti
            cout << "Soda punkti: " << penalty << endl;
            if (penalty > 9) {
                loop = false; // Apturēt ciklu.
                break;
            }

            // cout << word << endl; // cheat
            cout << hidden << endl;
            // Ievade
            cin >> input;
            // input = getch();

            // Pārveido uz meklējamo frāzi.
            string character(&input);
            // Meklē burtu minamajā vārdā.
            position = word.find(character, 0);
            if (position == string::npos) {
                // Ja nav šāda burta
                penalty++;
                cout << "Vārdā nav burta -> " << character << '.' << endl;
                continue;
            } else {
                // Ja burts tika atrasts meklē nākamo.
                while (position != string::npos) {
                // Aizvito punktu ar burtu kurš tika atrasts.
                hidden = hidden.replace(position, 1, character);
                position = word.find(character, position+1);
                }
            }
        }
        // Vārds uzminēts
        if (!loop) break;
        score++;
        cout << endl << "Vārds uzminēts: " << '\"' << word << '\"' << endl;
        burnPenalty();
    }

    cout << "Spēle galā!" << endl;
    if (score == N) {
        cout << "Jūs uzvarējāt, uzminēti visi vārdi!" << endl;
    }
    // system("pause");
    return 0;
}

int nextIndex()
{
    int index;
    while (true) {
        index = rand() % N;
        if (used[index] == 0) {
            used[index] = 1;
            return index;
        }
    }
}

void burnPenalty()
{
    int before = penalty;
    penalty -= 5;
    if (penalty < 0) penalty = 0;
    cout << "Sadega: " << before - penalty << " soda punkti." << endl;
}