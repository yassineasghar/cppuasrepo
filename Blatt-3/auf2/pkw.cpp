#include <iostream>
#include <cstring>
#include "pkw.h"

using namespace std;
Pkw::Pkw(const char *m, unsigned long f, unsigned int l) {
    marke = new char[strlen(m) + 1];
    strcpy(marke, m);
    fgstnr = f;
    leistung = l;
    cout << "Pkw der Marke " << marke << " mit Fahrgestellnummer " << fgstnr
              << " und Leistung " << leistung << " erzeugt." << endl;
}

Pkw::Pkw() {
    delete[] marke;
}

const char* Pkw::getMarke() const {
    return marke;
}

void Pkw::setMarke(const char *m) {
    delete[] marke;
    marke = new char[strlen(m) + 1];
    strcpy(marke, m);
}

unsigned long Pkw::getFgstnr() const {
    return fgstnr;
}

void Pkw::setFgstnr(unsigned long f) {
    fgstnr = f;
}

unsigned int Pkw::getLeistung() const {
    return leistung;
}

void Pkw::setLeistung(unsigned int l) {
    leistung = l;
}
