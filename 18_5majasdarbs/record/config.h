#include <string>
using namespace std;

const string DB_NAME = "client.data";
const int RECORD_LENGTH = 3;
const int TAB_WIDTH = 20;

struct clientData {
    int accNum = 0;
    char sur[15] = "";
    char name[10] = "";
    float balance = 0.00;
};