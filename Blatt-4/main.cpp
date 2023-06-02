#include <iostream>
#include "pkw.h"

int main() {
    using namespace std;
    Pkw p1("Beetle", 1001, 115);
    Pkw p2("Golf", 1002, 120);
    
    cout << "> Marke: " << p1.getMarke() << endl;
    cout << "> Fahrgestellnummer: " << p1.getFgstnr() << endl;
    cout << "> Leistung: " << p1.getLeistung() << endl;
    p1.setMarke("Volkswagen");
    cout << "> Neue Marke: " << p1.getMarke() << endl;

    if (p1 < p2)
        cout << "> p1 ist kleiner als p2" << endl;
    else
        cout << "> p2 ist kleiner gleich p1" << endl;
    
    return 0;
}
