#ifndef _PKW_H
#define _PKW_H

class Pkw {
private:
    char *marke;
    unsigned long fgstnr;
    unsigned int leistung;

public:
    ~Pkw();
    Pkw(const char *m = "Mercedes", unsigned long f = 0, unsigned int l = 100);

    const char* getMarke() const;
    void setMarke(const char *m);
    unsigned long getFgstnr() const;
    void setFgstnr(unsigned long f);
    unsigned int getLeistung() const;
    void setLeistung(unsigned int l);

    bool operator<(const Pkw& other) const;
};

#endif
