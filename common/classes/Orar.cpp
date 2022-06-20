#include "Orar.h"
#include <iostream>
using namespace std;

Orar::Orar(string zi, int ora){
    this->zi = zi;
    this->ora = ora;
}

string Orar::getZi(){
    return this->zi;
}

void Orar::setZi(string zi){
    this->zi = zi;
}

int Orar::getOra(){
    return this->ora;
}

void Orar::setOra(int ora){
    this->ora = ora;
}
