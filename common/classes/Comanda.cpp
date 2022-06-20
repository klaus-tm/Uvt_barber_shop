#include "Comanda.h"
#include "Oferte.h"
#include "Orar.h"
#include <iostream>
using namespace std;

Comanda::Comanda(string tip, string zi, int ora, int pret, int durata)
    : Oferte(tip, pret, durata), Orar(zi, ora){
    this->stadiu = "pending";
}

string Comanda::getStadiu(){
    return this->stadiu;
}

void Comanda::setStadiu(string stadiu)
{
    this->stadiu = stadiu;
}
