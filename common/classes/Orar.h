#ifndef ORAR_H
#define ORAR_H
#include <iostream>
using namespace std;

class Orar{
protected:
    string zi;
    int ora;

public:
    Orar(string, int);

    string getZi();
    void setZi(string);

    int getOra();
    void setOra(int);
};

#endif // ORAR_H
