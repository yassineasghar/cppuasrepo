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
    return 0;
}
