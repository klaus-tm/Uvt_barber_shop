#include "Oferte.h"
#include <iostream>
using namespace std;

Oferte::Oferte(string tip, int pret, int durata){
    this->tip = tip;
    this->pret = pret;
    this->durata = durata;
}

string Oferte::getTip(){
    return this->tip;
}

void Oferte::setTip(string tip){
    this->tip = tip;
}

int Oferte::getPret(){
    return this->pret;
}

void Oferte::setPret(int pret){
    this->pret = pret;
}

int Oferte::getDurata(){
    return this->durata;
}

void Oferte::setDurata(int durata){
    this->durata = durata;
}