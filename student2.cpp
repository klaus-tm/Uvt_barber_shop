#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "common/classes/Oferte.h"
#include "common/classes/Orar.h"
#include "common/classes/Comanda.h"
#include <vector>
#include <string>

using namespace std;

vector<Comanda> programare;

void citire_comanda()
{
    ifstream fin("common/files/Comanda_nou.txt");
    string zi;
    string tip_frizura;
    int durata=0;
    int pret=0;
    int ora;
    while(fin>>zi)
    {
        fin.ignore();
        fin>>tip_frizura;
        fin>>ora;
        programare.push_back(Comanda(tip_frizura, zi, ora, pret, durata));
    }

    fin.close();
}

void afisare_comanda()
{
    for (auto& programare : programare)
    {
        cout << "Zi: " << programare.getZi()<<endl;
        cout << "Tip_frizura: " << programare.getTip()<<endl;
        cout << "Ora: " << programare.getOra()<<endl;
    }
}

int main()
{
    citire_comanda();
    cout<<"===========UVT barber shop===========\n\n\n";
    cout<<"Programarea facuta :"<<endl;
    afisare_comanda();
    cout<<endl;
    cout<<" este acceptata!\n";
    cout<<"Va multumim !";
}
//void creare_comanda(Comanda i)
//{
//    ofstream fout("common/classes/Comanda_nou.txt", std::ios_base::app);
//    fout<<i.get_zi()<<' '<<i.get_tip()<<' '<<i.get_ora()<<'\n';
//    fout.close();
//}