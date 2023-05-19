#include <iostream>
#include "pkw.h"

int main() {
    using namespace std;
    Pkw p1("Beetle", 1001, 115);
    
    cout << "Marke: " << p1.getMarke() << endl;
    cout << "Fahrgestellnummer: " << p1.getFgstnr() << endl;
    cout << "Leistung: " << p1.getLeistung() << endl;
    p1.setMarke("Volkswagen");
    cout << "Neue Marke: " << p1.getMarke() << endl;

    Pkw p2("TOYOTA", 1010, 110);
    cout << "Marke: " << p2.getMarke() << endl;
    cout << "Fahrgestellnummer: " << p2.getFgstnr() << endl;
    cout << "Leistung: " << p2.getLeistung() << endl;
    p2.setMarke("Audi");
    cout << "Neue Marke: " << p2.getMarke() << endl;
    
    return 0;
}
