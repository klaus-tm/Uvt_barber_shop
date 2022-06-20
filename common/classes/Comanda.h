#ifndef COMANDA_H
#define COMANDA_H
#include "Oferte.h"
#include "Orar.h"
#include <iostream>
using namespace std;

class Comanda: public Orar, public Oferte{
protected:
    string stadiu;

public:
    Comanda(string, string, int, int, int);

    string getStadiu();
    void setStadiu(string);
};

#endif // COMANDA_H
