/**
 * 2. Uzdevums
 * 
 * Saprogrammējiet spēli "Krustiņi un nullīši".
 * Programma nodrošina spēles laukumu diviem spēlētājiem,
 * pārbauda gājienu korektumu, seko situācijai uz laukuma, un izvada uzvārētāju.
 * Programma spēlē pret cilvēku, katrā gājienā meklējot visizdevīgāko variantu esošā situācijā.
 * Sākumā piedāvā izvēlaties – spēlēt pret cilvēku, vai pret datoru. Spēles beigās piedāvā uzspēlēt vēlreiz.
**/

#include <iostream>
#include <ctime>
using namespace std;


time_t t; // Mainīgais kurā saglabāsim laiku.

bool loop = true;
bool dators = false;
bool datorsOnly = false;

const int N = 3; // Rindas elementu skaits. (rindas garums, rindas platums, matricas platums, matricas kolonnu skaits)
const int speletajs1 = 1;
const int speletajs2 = -1;
int speletajs = 0; // Aktīvais spēlētājs.

/**
 * Inicializējam spēles laukuma massīvu, globāli, lai funkcijām būtu ērtāka piekļuve.
**/
int laukums[N*N] = {0};

/**
 * Ja spēlētājs nav izvēlēts = 0, tad ar
 * gadījumskaitļu ģeneratora palīdzību no massīva izvēlas un iestata spēlētāju.
 * 
 * Ja spēlētājs ir izvēlēts, tad iestata otru spēlētāju.
**/
void nakamaisSpeletajs()
{
    if (speletajs == 0) {
        // Izvēlas kurš pirmais sāk.
        int speletaji[2] = {speletajs1,speletajs2};
        int index = rand() % 2;
        speletajs = speletaji[index];
    }

    if (speletajs == speletajs1) {
        speletajs = speletajs2;
    } else {
        speletajs = speletajs1;
    }
}

/**
 * Atgriež kvadrāt matricas rindas summu.
 * 
 * Cikla iterācija sākas ar matricas platums(N) * rindas nummurs.
 * Cikls pārstāj darboties, ja sasniegts matricas platums.
**/
int horizontal(int rinda)
{
    int sum = 0;

    for (int i = N*rinda; i < N+N*rinda; i++) {
        sum+= *(laukums+i);
    }
    return sum;
}

/**
 * Atgriež kvadrāt matricas vienas kolonnas elementu summu.
 * 
 * Cikla sākums vienāds ar kolonnas nummuru.
 * Iterācijas solis ir matricas platums (N).
**/
int vertical(int kolonna)
{
    int sum = 0;

    for (int i = kolonna; i < N*N; i+=N) {
        sum+= *(laukums+i);
    }
    return sum;
}

/**
 * Atgriež kvadrāt matricas galvenās diagonāles elementu summu.
 * 
 * Iterācijas solis ir matricas platums(N) +1, tātad tiek atrasts
 * katrs N+1 elements.
**/
int mainDiagonal()
{
    int sum = 0;

    for (int i = 0; i < N*N; i+=N+1) {
        sum+= *(laukums+i);
    }
    return sum;
}

/**
 * Atgriež kvadrāt matricas blakus diagonāles summu.
 * 
 * Iterāciju sākam ar elementu N-1, tādā veidā izlaižot pirmo matricas elementu,
 * un beidzam ar N*N-1, izlaižot pēdējo elementu.
**/
int oppositeDiagonal()
{
    int sum = 0;

    for (int i = N-1; i < N*N-1; i+=N-1) {
        sum += *(laukums+i);
    }
    return sum;
}

/**
 * Pārveido koordinātes no 2d uz 1d
 * Atgriež pozīciju massīvā.
**/
int convertCords(int rinda, int kolonna, int platums)
{
    return platums * rinda - (platums - kolonna) -1; // -1 lai sāktos ar 0;
}
/**
 * Pārbauda vai pozīcija massīvā ir brīva.
**/
bool available(int index)
{
    if ( *(laukums+index) == 0 ) return true;
    return false;
}
bool isBetween(char c)
{
    if ((int)c >= 49 && (int)c <= 51 ) return true;
    return false;
}
int toInt(char input)
{
    int integer = -48;
    return integer += input;
}
/**
 * Ja uzvar X atgriež 1,
 * Ja uzvar O atgriež -1,
 * Ja neizšķirts 0,
 **/
int checkWinner()
{
    // Diagonāles
    if ( mainDiagonal() == 3 || oppositeDiagonal() == 3 ) {
        return 1;
    }
    if ( mainDiagonal() == -3 || oppositeDiagonal() == -3 ) {
        return -1;
    }
    
    // Horizontāles, Vertikāles.
    for (int i=0; i<N; i++) {
        if ( horizontal(i) == -3 || vertical(i) == -3 ) {
            return -1;
        }
        if ( horizontal(i) == 3 || vertical(i) == 3 ) {
            return 1;
        }
    }

    // Saskaita brīvos laukus.
    int brivie = 0;
    for (int i = 0; i < N*N; i++) {
        if (available(i)) brivie++;
    }
    if (brivie == 0) {
        return 0; // Neizšķirts.
    }
    return -999;
}

/**
 * Palīg funkcija minimax algoritmam.
 * Iestata sākuma bestscori, katram spēlētājam savu.
 **/
int setBestScore()
{
    if (speletajs == speletajs1) return -99;
    return 99;
}

/**
 * Minimax algoritms.
 * Tiek izsaukts atkārtoti katram fake gājienam, lai noskaidrotu gājiena punktu skaitu.
 * 
 * Pārbauda vai spēle ir galā un var atgriest punktus.
 * Minimax() imitēs otra spēlētāja gājienus, meklējot izdevīgākos.
 * Izejot cauri ciklam iestata atpakaļ uz iepriekšējo spēlētāju un atgriež labāko punktu skaitu.
 **/
int minimax()
{
    // Pārbauda vai spēle galā.
    int score = checkWinner();
    // Atgriež punktus, vienu no 3 variantiem '1', '-1', '0'. 
    if ( score != -999) return score;

    // Iestata nākamo spēlētāju.
    nakamaisSpeletajs();
    int bestScore = setBestScore(); // 99 vai -99 atkarībā no aktīvā spēlētāja.

    // Cikls "laukuma" massīva garumā.
    for (int i = 0; i < N*N; i++) {
        // Ja pozīcija laukuma massīvā ir brīva.
        if (available(i)) {
            // Veic fake gājienu.
            *(laukums+i) = speletajs;
            // Balstoties uz veiktā gājiena noskaidrojam punktus, kurus atgriež minimax.
            int score = minimax();
            // Undo fake gājienu.
            *(laukums+i) = 0;

            if (speletajs == speletajs1 && score > bestScore) {
                bestScore = score;
            }
            if (speletajs == speletajs2 && score < bestScore) {
                bestScore = score;
            }
        }
    }
    // Pirms punktu atgriešanas, iestatam spēlētāju uz iepriekšējo.
    nakamaisSpeletajs();
    return bestScore;
}

/**
 * Aprēķina nākamo gājienu.
 * Tiek veikts cikls laukuma massīvam.
 * Pārbauda visas brīvās pozīcijas massīvā.
 * Atrod labāko gājienu balstoties uz minimax algoritma punktiem.
 **/
void datoraGajiens(int& index)
{
    int bestScore = setBestScore(); // 99 vai -99 atkarībā no aktīvā spēlētāja.
    int labakaisGajiens = 0;

    // Cikls "laukuma" massīva garumā.
    for (int i = 0; i < N*N; i++) {
        // Ja pozīcija laukuma massīvā ir brīva.
        if (available(i)) {
            // Veic fake gājienu.
            *(laukums+i) = speletajs;
            // Balstoties uz veiktā gājiena noskaidrojam punktus, kurus atgriež minimax.
            int score = minimax();
            // Undo fake gājienu.
            *(laukums+i) = 0;

            if (speletajs == speletajs1 && score > bestScore) {
                bestScore = score;
                labakaisGajiens = i;
            }
            if (speletajs == speletajs2 && score < bestScore) {
                bestScore = score;
                labakaisGajiens = i;
            }
        }
    }
    index = labakaisGajiens; // iestata labākā gājiena pozīciju.
}

/**
 * Ievade
**/
int getInput(int& index)
{
    if (dators && speletajs == speletajs2 || datorsOnly) {
        datoraGajiens(index);
        return 0;
    }

    while ( loop ) {
        char userInput1;
        char userInput2;

        // Koordinātes var ievadīt "22", "2 2", "2 enter 2"; 
        cin >> userInput1 >> userInput2; // Paņem 2 simbolus no inputa
        /**
         * Ignorē nākamos 1000 simbolus,
         * gadījumā ja cikls ir atsācies un ir ievadīts vairāk par 2 simboliem,
         * input buferī nesaglabāsies nekas.
         **/
        cin.ignore(1000, '\n');

        // Izejam uz menu.
        if (userInput1 == '!' || userInput2 == '!') {
            cout << "Izeju!" << endl;
            loop = false;
            break;
        }

        if (isBetween(userInput1) && isBetween(userInput2)) {
            index = convertCords(toInt(userInput1), toInt(userInput2), 3);
            break;
        } else {
            cout << "Koordinātēm jāsastāv no cipariem. 1 - 3" << endl;
            continue;
        }
    }
    return 0;
}

/**
 * Nākamais gājiens
**/
void gajiens()
{
    if (speletajs == speletajs1) {
        cout << "X gājiens, ";
    } else {
        cout << "O gājiens, ";
    }
    cout << "ievadiet koordinātes (rinda)(kolonna):" << endl;

    while ( loop ) {
        int index = 0;
        getInput(index);

        if (available(index)) {
            *(laukums+index) = speletajs;
            break;
        } else {
            // Kā pārveidot atpakaļ uz koordinātēm i, j?
            // cout << "Koordinātes " << koordinate[0] +1 << "," << koordinate[1] +1 << " aizņemtas!" << endl;
            cout << "Koordinātes aizņemtas!" << endl;
            continue;
        }
    }
}

/**
 * Izvada spēles laukumu.
**/
void coutField()
{
    for (int i = 0; i < N*N; i++) {
        // Ja iterācija dalās ar massīva garumu un nav 0 izvadam linebreak.
        if (i % N == 0 && i != 0) cout << endl;

        switch(*(laukums+i)) {
            case -1:
                cout << "[ O ]";
                break;
            case 1:
                cout << "[ X ]";
                break;
            default:
                cout << "[   ]";
        }
    }
    cout << endl;
}

int main()
{
    srand((unsigned) time(&t)); // Inicializējam gadījumskaitļu ģenerātoru.
    
    char izvele;
    while (izvele != '!') {
        
        loop = true;
        dators = false;
        datorsOnly = false;
        for (int i=0; i<N*N; i++) *(laukums+i) = 0; // Atjauno lauku.
        speletajs = 0;

        /**
         * Galvenā izvēlne.
         **/
        cout << "Mazdrusciņ desas?" << endl
        << "(1) Spēlēt pret datoru" << endl
        << "(2) Spēlēt pret cilvēku" << endl
        << "(3) Dators pret datoru" << endl
        << "(!!) Iziet" << endl;
        cin >> izvele;

        switch (izvele) {
            case '1':
                dators = true;
            break;
            case '2':
                dators = false;
            break;
            case '3':
                datorsOnly = true;
            break;
            case '!':
                cout << "Izeju!" << endl;
            return 0;
        }

        while ( loop ) {

            nakamaisSpeletajs(); // Iegūstam nākamo spēlētāju.
            coutField(); // Izvada spēles laukumu.

            switch (checkWinner()) {
                case 0:
                    cout << "Neizšķirts" << endl;
                    loop = false;
                    continue; // Vai tā drīkst??
                case 1:
                    cout << "Uzvarēja X" << endl;
                    loop = false;
                    continue;
                case -1:
                    cout << "Uzvarēja O" << endl;
                    loop = false;
                    continue;
            }

            gajiens();
        }
    }

    return 0;
}