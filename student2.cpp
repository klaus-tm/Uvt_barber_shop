#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "common/classes/Oferte.cpp"
#include "common/classes/Orar.cpp"
#include "common/classes/Comanda.cpp"
#include <vector>
#include <string>
#include <dirent.h>
#include <windows.h>
#define GREEN 2
#define BLUE 3
#define RED 12
#define YELLOW 14
#define WHITE 15

using namespace std;

void set_color(int color_code)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}

vector<Comanda> programare;
vector<Oferte> oferte;
vector<Comanda> comenzi_acceptate;
vector<Comanda> comenzi_refuzate;

void citire_oferte()
{
    oferte.clear();
    ifstream fin("common/files/Oferte.txt", std::ios_base::app);
    string tip;
    int pret, durata;
    while(fin>>tip)
    {
        fin.ignore();
        fin>>pret>>durata;
        oferte.push_back(Oferte(tip, pret, durata));
    }
    fin.close();
}

void citire_comenzi_acceptate()
{
    ifstream fin("common/files/Comanda_acceptat.txt", std::ios_base::app);
    string tip, zi, status;
    int ora, pret, durata;
    while(fin>>tip)
    {
        fin.ignore();
        fin>>zi;
        fin.ignore();
        fin>>ora>>durata>>pret;
        fin>>status;
        fin.ignore();
        comenzi_acceptate.push_back(Comanda(tip, zi, ora, pret, durata));
    }
    fin.close();
}

void afisare_comanda_acceptata()
{
    int i=1;
    for(auto& comenzi_acceptate: comenzi_acceptate)
    {
        cout<<i<<" "<<comenzi_acceptate.getTip()<<" "<<comenzi_acceptate.getZi()<<" "<<comenzi_acceptate.getOra()<<" "<<comenzi_acceptate.getDurata()<<" "<<comenzi_acceptate.getPret()<<" "<<"accepted"<<"\n";
        i++;
    }
}

void citire_comenzi_refuzate()
{
    ifstream fin("common/files/Comanda_refuzat.txt", std::ios_base::app);
    string tip, zi, status;
    int ora, pret, durata;
    while(fin>>tip)
    {
        fin.ignore();
        fin>>zi;
        fin.ignore();
        fin>>ora>>durata>>pret;
        fin>>status;
        fin.ignore();
        comenzi_refuzate.push_back(Comanda(tip, zi, ora, pret, durata));
    }
    fin.close();
}

void afisare_comanda_refuzata()
{
    int i=1;
    for(auto& comanda: comenzi_refuzate)
    {
        cout<<i<<" "<<comanda.getTip()<<" "<<comanda.getZi()<<" "<<comanda.getOra()<<" "<<comanda.getDurata()<<" "<<comanda.getPret()<<" "<<"rejected"<<"\n";
        i++;
    }
}

void creare_comanda()
{
    ifstream fin("common/files/Oferte.txt");
    ofstream fout("common/files/Comanda_nou.txt", std::ios_base::app);

    string zi,tip;
    int ora,durata,pret;
    set_color(RED);
    cout<<"\n\nProgramul este de luni pana vineri, intre orele 09:00-19:00\n\n\n";
    set_color(WHITE);
    set_color(BLUE);
    cout<<"Introduceti ziua dorita: ";
    set_color(WHITE);
    cin>>zi; cin.ignore();
    if(zi=="sambata" || zi=="duminica")
    {
        set_color(RED);
        cout<<"Zi introdusa gresit"<<"\n\n";
        set_color(WHITE);
        return;
    }
    cout<<"\n";
    set_color(BLUE);
    cout<<"Introduceti ora dorita: ";
    set_color(WHITE);
    cin>>ora;
    if(ora<9 || ora>19)
    {
        set_color(RED);
        cout<<"Ora introdusa gresit"<<"\n\n";
        set_color(WHITE);
        return;
    }
    cout<<"\n";
    set_color(BLUE);
    cout<<"Introduceti tipul: ";
    set_color(WHITE);
    cin>>tip; cin.ignore();
    cout<<"\n\n";
    fout<<tip<<" ";
    fout<<zi<<" ";
    fout<<ora<<" ";
    int k=0;
    for (auto& oferte : oferte)
    {
        string tip_oferta=oferte.getTip();
        if(tip_oferta==tip)
            k=1;
    }

    if(k == 1)
        for (auto& oferte : oferte)
        {
            string tip_oferta=oferte.getTip();
            if(tip_oferta==tip)
            {
                fout<<oferte.getPret()<<" ";
                fout<<oferte.getDurata()<<" ";
                durata=oferte.getDurata();
                pret=oferte.getPret();
            }
        }
    else
    {
        set_color(RED);
        cout<<"Tipul ales nu este in oferte\n\n";
        set_color(WHITE);
        return;
    }

    string stadiu="pending";
    fout<<stadiu<<"\n";
    programare.push_back(Comanda(tip, zi, ora, pret, durata));
    fout.close();
    fin.close();
    set_color(BLUE);
    cout<<"Programare efectuata cu succes!\n\n";
    set_color(WHITE);
}

void afisare_comanda()
{

    for (auto& programare : programare)
    {
        cout<<" "<<programare.getTip()<<" "<<programare.getZi()<<" "<<programare.getOra()<<" "<<programare.getPret()<<" "<<programare.getDurata()<<" "<<programare.getStadiu()<<"\n";
    }
}

void afisare_oferte()
{
    for (auto& oferte : oferte)
        cout<<"Tip: "<<oferte.getTip()<<"  "<<"Pret: "<<oferte.getPret()<<"  "<<"Durata: "<<oferte.getDurata()<<"\n";
}

int main()
{
    int opt;
    while(1)
    {
        system("cls");
        int optiune;
        set_color(BLUE);
        cout<<"[===========UVT barber shop===========]\n\n\n";
        set_color(WHITE);
        set_color(RED);
        cout<<"Va rugam, introduceti numarul corespunzator optiunii!\n";
        set_color(WHITE);
        set_color(YELLOW);
        cout<<"1.";
        set_color(WHITE);
        cout<<"Programare\n";
        set_color(YELLOW);
        cout<<"2.";
        set_color(WHITE);
        cout<<"Istoric programari\n";
        cout<<"Alt numar va inchide aplicata\n";
        cout<<"Introduceti optiunea: ";
        cin>>optiune;
        cout<<endl<<endl;
        system("cls");
        if(optiune==1)
        {
            system("cls");
            set_color(BLUE);
            cout<<"[===========UVT barber shop===========]\n\n\n";
            set_color(WHITE);
            set_color(RED);
            cout<<"Se poate face o programare pe ora\n\n";
            set_color(WHITE);
            cout<<"Ofertele disponibile sunt: ";
            cout<<"\n";

            citire_oferte();
            afisare_oferte();
            creare_comanda();

            system("pause");
        }
        else if(optiune==2)
        {
            system("cls");
            set_color(BLUE);
            cout<<"===========UVT barber shop===========\n\n\n";
            set_color(WHITE);
            set_color(YELLOW);
            cout<<"1.";
            set_color(WHITE);
            cout<<"Programari acceptate\n";
            set_color(YELLOW);
            cout<<"2.";
            set_color(WHITE);
            cout<<"Programari refuzate\n";
            cout<<"Va rugam, folositi optiunile de mai sus: ";
            cin>>opt;
            system("cls");
            if(opt==1)
            {
                set_color(BLUE);
                cout<<"===========UVT barber shop===========\n\n\n";
                set_color(WHITE);
                set_color(RED);
                cout<<"Programari acceptate:\n\n";
                set_color(WHITE);
                citire_comenzi_acceptate();
                afisare_comanda_acceptata();
            }
            else if(opt==2)
            {
                set_color(BLUE);
                cout<<"===========UVT barber shop===========\n\n\n";
                set_color(WHITE);
                set_color(RED);
                cout<<"Programari refuzate:\n\n";
                set_color(WHITE);
                citire_comenzi_refuzate();
                afisare_comanda_refuzata();
            }
            else
            {
                set_color(RED);
                cout<<"Optiunea introdusa este gresita!";
                set_color(WHITE);
            }
            return 0;
        }
        else
        {
            set_color(RED);
            cout<<"Optiunea introdusa este gresita!";
            set_color(WHITE);
            return 0;
        }

    }

}
