#ifndef OFERTE_H
#define OFERTE_H
#include <iostream>
using namespace std;

class Oferte{
protected:
    string tip;
    int pret, durata;

public:
    Oferte(string, int, int);

    string getTip();
    void setTip(string);

    int getPret();
    void setPret(int);

    int getDurata();
    void setDurata(int);
};

#endif // OFERTE_H
