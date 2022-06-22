#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <list>
#include "common/classes/Oferte.cpp"
#include "common/classes/Orar.cpp"
#include "common/classes/Comanda.cpp"

using namespace std;

list<Oferte>oferte;
list<Comanda>comenzi;

void cooldown(int seconds){
    clock_t start = clock();
    clock_t period = seconds * CLOCKS_PER_SEC;
    clock_t elapsed;

    do {
        elapsed = clock() - start;
    } while(elapsed < period);
}
//lucru la oferte
int verificare_duplicate(string tip_cautat){
    oferte.clear();
    ifstream fin("common/files/Oferte.txt", std::ios_base::app);
    string tip; int pret, durata;
    while(fin>>tip){
        fin.ignore();
        fin>>pret>>durata;
        oferte.push_back(Oferte(tip, pret, durata));
    }
    fin.close();
    for(auto& oferta: oferte){
        if(oferta.getTip() == tip_cautat)
            return 1;
    }
    return 0;
}
void creare_oferta(Oferte o){
    ofstream fout("common/files/Oferte.txt", std::ios_base::app);
    fout<<o.getTip()<<" "<<o.getPret()<<" "<<o.getDurata()<<"\n";
    fout.close();
}
void citire_oferte(){
    oferte.clear();
    ifstream fin("common/files/Oferte.txt", std::ios_base::app);
    string tip; int pret, durata;
    while(fin>>tip){
        fin.ignore();
        fin>>pret>>durata;
        oferte.push_back(Oferte(tip, pret, durata));
    }
    fin.close();
    int i=1;
    for(auto& oferta: oferte){
        cout<<i<<" "<<oferta.getTip()<<" "<<oferta.getPret()<<" "<<oferta.getDurata()<<"\n";
        i++;
    }
}
void modificare_pret(string tip, int pret){
    for(auto& oferta: oferte){
        if(oferta.getTip() == tip){
            oferta.setPret(pret);
            break;
        }
    }
    ofstream ofs;
    ofs.open("common/files/Oferte.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofstream fout("common/files/Oferte.txt", std::ios_base::app);
    for(auto& oferta: oferte){
        fout<<oferta.getTip()<<" "<<oferta.getPret()<<" "<<oferta.getDurata()<<"\n";
    }
    fout.close();
}
void modificare_durata(string tip, int durata){
    for(auto& oferta: oferte){
        if(oferta.getTip() == tip){
            oferta.setDurata(durata);
            break;
        }
    }
    ofstream ofs;
    ofs.open("common/files/Oferte.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofstream fout("common/files/Oferte.txt", std::ios_base::app);
    for(auto& oferta: oferte){
        fout<<oferta.getTip()<<" "<<oferta.getPret()<<" "<<oferta.getDurata()<<"\n";
    }
    fout.close();
}
void stergere_oferta(string tip){
    for(auto iter = oferte.begin(); iter != oferte.end(); iter++){
        if(iter->getTip() == tip){
            oferte.erase(iter);
            break;
        }
    }
    ofstream ofs;
    ofs.open("common/files/Oferte.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofstream fout("common/files/Oferte.txt", std::ios_base::app);
    for(auto& oferta: oferte){
        fout<<oferta.getTip()<<" "<<oferta.getPret()<<" "<<oferta.getDurata()<<"\n";
    }
    fout.close();
}

//lucru la comenzi
void citire_comenzi(){
    comenzi.clear();
    ifstream fin("common/files/Comanda_nou.txt", std::ios_base::app);
    string tip, zi, status; int ora, pret, durata;
    while(fin>>tip){
        fin.ignore();
        fin>>zi;
        fin.ignore();
        fin>>ora>>durata>>pret;
        fin>>status;
        fin.ignore();
        comenzi.push_back(Comanda(tip, zi, ora, pret, durata));
    }
    fin.close();
    int i=1;
    for(auto& comanda: comenzi){
        cout<<i<<" "<<comanda.getTip()<<" "<<comanda.getZi()<<" "<<comanda.getOra()<<" "<<comanda.getDurata()<<" "<<comanda.getPret()<<" "<<comanda.getStadiu()<<"\n";
        i++;
    }
}
void acceptare_comanda(string tip, string zi){
    for(auto& comanda: comenzi){
        if(comanda.getTip() == tip and comanda.getZi() == zi)
            comanda.setStadiu("accepted");
    }
    ofstream ofs;
    ofs.open("common/files/Comanda_nou.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofstream nouOut("common/files/Comanda_nou.txt", std::ios_base::app);
    ofstream acceptOut("common/files//Comanda_acceptat.txt", std::ios_base::app);
    for(auto& comanda: comenzi){
        if(comanda.getStadiu() == "pending")
            nouOut<<comanda.getTip()<<" "<<comanda.getZi()<<" "<<comanda.getOra()<<" "<<comanda.getDurata()<<" "<<comanda.getPret()<<" "<<comanda.getStadiu()<<"\n";
        else if(comanda.getStadiu() == "accepted")
            acceptOut<<comanda.getTip()<<" "<<comanda.getZi()<<" "<<comanda.getOra()<<" "<<comanda.getDurata()<<" "<<comanda.getPret()<<" "<<comanda.getStadiu()<<"\n";
    }
    nouOut.close();
    acceptOut.close();
}
void refuzare_comanda(string tip, string zi){
    for(auto& comanda: comenzi){
        if(comanda.getTip() == tip and comanda.getZi() == zi)
            comanda.setStadiu("declined");
    }
    ofstream ofs;
    ofs.open("common/files/Comanda_nou.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofstream nouOut("common/files/Comanda_nou.txt", std::ios_base::app);
    ofstream declineOut("common/files//Comanda_refuzat.txt", std::ios_base::app);
    for(auto& comanda: comenzi){
        if(comanda.getStadiu() == "pending")
            nouOut<<comanda.getTip()<<" "<<comanda.getZi()<<" "<<comanda.getOra()<<" "<<comanda.getDurata()<<" "<<comanda.getPret()<<" "<<comanda.getStadiu()<<"\n";
        else if(comanda.getStadiu() == "declined")
            declineOut<<comanda.getTip()<<" "<<comanda.getZi()<<" "<<comanda.getOra()<<" "<<comanda.getDurata()<<" "<<comanda.getPret()<<" "<<comanda.getStadiu()<<"\n";
    }
    nouOut.close();
    declineOut.close();
}
void citire_zi(string ziCautata){
    comenzi.clear();
    ifstream fin("common/files/Comanda_acceptat.txt", std::ios_base::app);
    string tip, zi, status; int ora, pret, durata;
    while(fin>>tip){
        fin.ignore();
        fin>>zi;
        fin.ignore();
        fin>>ora>>durata>>pret;
        fin>>status;
        fin.ignore();
        comenzi.push_back(Comanda(tip, zi, ora, pret, durata));
    }
    fin.close();
    int i=1;
    for(auto& comanda: comenzi){
        comanda.setStadiu("accepted");
    }
    for(auto& comanda: comenzi){
        if(comanda.getZi() == ziCautata){
            cout<<i<<" "<<comanda.getTip()<<" "<<comanda.getZi()<<" "<<comanda.getOra()<<" "<<comanda.getDurata()<<" "<<comanda.getPret()<<" "<<comanda.getStadiu()<<"\n";
            i++;
        }
    }
}
int main(){
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice;
    while(1){
        //meniu
        system("cls");

        //screen
        SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"UVT barber shop"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~=\n\n\n"
        <<"=========================================================\n";
        SetConsoleTextAttribute(hc, 7); cout<<"Choose what you want to use:\n";
        SetConsoleTextAttribute(hc, 1); cout<<"1. Offers\n";
        SetConsoleTextAttribute(hc, 3); cout<<"2. Appointments\n";
        SetConsoleTextAttribute(hc, 5); cout<<"3. EXIT\n";
        SetConsoleTextAttribute(hc, 2); cout<<"=========================================================\n";
        SetConsoleTextAttribute(hc, 7); cout<<"Enter your choice:";
            //end of screen

        cin>>choice;
        if(choice == 1){
            int user_choice;
            system("cls");

            //screen
            SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"Offers"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~=\n\n\n"
            <<"================================================\n";
            SetConsoleTextAttribute(hc, 7); cout<<"Choose what you want to do:\n";
            SetConsoleTextAttribute(hc, 1); cout<<"1. Create Offer\n";
            SetConsoleTextAttribute(hc, 3); cout<<"2. Modify an offer\n";
            SetConsoleTextAttribute(hc, 5); cout<<"3. Delete an offer\n";
            SetConsoleTextAttribute(hc, 7); cout<<"4. GO BACK TO MENU\n";
            SetConsoleTextAttribute(hc, 2); cout<<"================================================\n";
            SetConsoleTextAttribute(hc, 7); cout<<"Enter your choice:";
            cin>>user_choice;
            if(user_choice == 1){
                string tip; int pret, durata; int k=0;
                //screen
                while(k == 0){
                    system("cls");
                    SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"Offers"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~=\n\n\n"
                    <<"================================================\n";
                    SetConsoleTextAttribute(hc, 1); cout<<"PLease insert the type of cut:\n"; cin>>tip; cin.ignore();
                    if(verificare_duplicate(tip) == 0){
                        SetConsoleTextAttribute(hc, 3); cout<<"Please insert the price of the cut:\n"; cin>>pret;
                        SetConsoleTextAttribute(hc, 5); cout<<"PLease insert the duration of the cut\n"; cin>>durata;
                        cooldown(1);
                        creare_oferta(Oferte(tip, pret, durata)); k++;
                        SetConsoleTextAttribute(hc, 7); cout<<"New offer added! Press again to return to menu\n";
                        SetConsoleTextAttribute(hc, 2); cout<<"================================================\n";
                    }
                    else{
                        SetConsoleTextAttribute(hc, 7); cout<<"PLease insert a non duplicate offer!\n";
                        system("pause");
                    }
                }

                system("pause");
            }
            else if(user_choice == 2) {
                system("cls");
                string modify, tip;
                SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"Offers"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~=\n\n\n"
                <<"================================================\n";
                SetConsoleTextAttribute(hc, 7); cout<<"Current offers:\n";
                citire_oferte();
                SetConsoleTextAttribute(hc, 1); cout<<"Please insert the offer you want to modify: "; cin>>tip; cin.ignore();
                SetConsoleTextAttribute(hc, 3); cout<<"Please insert what modification you want to make(price/duration): "; cin>>modify;
                if(modify == "price"){
                    int pret;
                    SetConsoleTextAttribute(hc, 5); cout<<"Please insert the new price: "; cin>>pret;
                    modificare_pret(tip, pret);
                    cooldown(1);
                    SetConsoleTextAttribute(hc, 7); cout<<"Modification complete! Press again to return to menu\n";
                    SetConsoleTextAttribute(hc, 2); cout<<"================================================\n";
                }
                else if(modify == "duration"){
                    int durata;
                    SetConsoleTextAttribute(hc, 5); cout<<"Please insert the new duration: "; cin>>durata;
                    modificare_durata(tip, durata);
                    cooldown(1);
                    SetConsoleTextAttribute(hc, 7); cout<<"Modification complete! Press again to return to menu\n";
                    SetConsoleTextAttribute(hc, 2); cout<<"================================================\n";
                }
                system("pause");
            }
            else if(user_choice == 3){
                system("cls");
                string tip;
                SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"Offers"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=~=\n\n\n"
                <<"================================================\n";
                SetConsoleTextAttribute(hc, 7); cout<<"Current offers:\n";
                citire_oferte();
                SetConsoleTextAttribute(hc, 1); cout<<"Please insert the offer you want to delete: "; cin>>tip; cin.ignore();
                string answer;
                SetConsoleTextAttribute(hc, 3); cout<<"Are you sure you want to delete "<<tip<<"? "; cin>>answer;
                if(answer == "yes"){
                    stergere_oferta(tip);
                    cooldown(1);
                    SetConsoleTextAttribute(hc, 7); cout<<"Erase complete! Press again to return to menu\n";
                    SetConsoleTextAttribute(hc, 2); cout<<"================================================\n";
                }
                else{
                    SetConsoleTextAttribute(hc, 7);cout<<"Erase aborted! Press again to return to menu\n";
                    SetConsoleTextAttribute(hc, 2); cout<<"================================================\n";
                }
                system("pause");
            }
            else if(user_choice == 4){
                cout<<"Returning to main menu...";
                cooldown(2);
            }
        }
        else if(choice == 2){
            int user_choice;
            system("cls");

            //screen
            SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"Appointments"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=\n\n\n"
            <<"==================================================\n";
            SetConsoleTextAttribute(hc, 7); cout<<"Choose what you want to do:\n";
            SetConsoleTextAttribute(hc, 1); cout<<"1. Accept/Decline appointments\n";
            SetConsoleTextAttribute(hc, 3); cout<<"2. View appointments for a certain day\n";
            SetConsoleTextAttribute(hc, 5); cout<<"3. GO BACK TO MENU\n";
            SetConsoleTextAttribute(hc, 2); cout<<"==================================================\n";
            SetConsoleTextAttribute(hc, 7); cout<<"Enter your choice:";
            cin>>user_choice;
            if(user_choice == 1){
                system("cls");
                string tip, zi, status;
                SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"Appointments"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=\n\n\n"
                <<"==================================================\n";
                SetConsoleTextAttribute(hc, 7); cout<<"Current appointments:\n";
                citire_comenzi();
                SetConsoleTextAttribute(hc, 1); cout<<"Please insert the appointment you want to accept/decline: "; cin>>tip; cin.ignore();
                SetConsoleTextAttribute(hc, 3); cout<<"Please insert the day of the appointment: "; cin>>zi; cin.ignore();
                SetConsoleTextAttribute(hc, 5); cout<<"Please insert what you want to do with the appointment(accept/decline): "; cin>>status; cin.ignore();
                if(status == "accept"){
                    acceptare_comanda(tip, zi);
                    cooldown(1);
                    SetConsoleTextAttribute(hc, 7); cout<<"Modification complete! Press again to return to menu\n";
                    SetConsoleTextAttribute(hc, 2); cout<<"==================================================\n";
                }
                else if(status == "decline"){
                    refuzare_comanda(tip, zi);
                    cooldown(1);
                    SetConsoleTextAttribute(hc, 7); cout<<"Modification complete! Press again to return to menu\n";
                    SetConsoleTextAttribute(hc, 2); cout<<"==================================================\n";
                }
                system("pause");
            }
            else if(user_choice == 2){
                system("cls");
                string zi;
                SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~="; SetConsoleTextAttribute(hc, 4); cout<<"Appointments"; SetConsoleTextAttribute(hc, 2); cout<<"=~=~=~=~=~=~=~=~=~=\n\n\n"
                <<"==================================================\n";
                SetConsoleTextAttribute(hc, 1); cout<<"Please insert the day you want to review: "; cin>>zi; cin.ignore();
                SetConsoleTextAttribute(hc, 7); cout<<"Appointments for "<<zi<<":\n";
                citire_zi(zi);
                cout<<"Press again to return to menu\n";
                SetConsoleTextAttribute(hc, 2); cout<<"==================================================\n";
                system("pause");
            }
            else if(user_choice == 3){
                cout<<"Returning to main menu...";
                cooldown(2);
            }
        }
        else if(choice == 3){
            cout<<"Closing the app...";
            cooldown(3);
            return 0;
        }
        else if(choice < 1 or choice > 3){
            cout<<"Please enter a valid input\n";
            system("pause");
        }
    }
}
