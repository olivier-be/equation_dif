#include<string>
#include "Analyse.h"
#include "iostream"
using namespace std;

Analyse::Analyse(string equation_dif){
    this ->equation_dif=equation_dif;
}

void Analyse::analyse_position()
{
    bool b;
    int taille,pos_act,pos_fut;
    char z;
    string valeur,reponce;
    string const alphabet("abcdefghijklmnopqrdtuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    cout << char(255)<<"choisie ta forme d'equations differencielles avec pour info prime = ' \n";
    //cin >> equation_dif;
    taille= equation_dif.size()-1;
    for (int i=0;i<=taille;i++)
    {
        z=equation_dif[i];
        if (z=='+' or z=='=' or z==' ' or z=='/' or z=='*')
        {
            tab_position.push_back(i);
            cout << i<<"c "<<tab_position[tab_position.size() - 1]<<endl;
        }
        else {cout << i<<"b"<<endl;}

    }
    tab_position.push_back(taille);
    cout<<"asdfqsdf"<<taille<<endl;
    pos_act=0;
    pos_fut=tab_position[0];
    cout<<pos_act<<" a "<< pos_fut<<endl;
    for (int e = 0; e <= tab_position.size()-1; e++) {
        cout << e<<"  ab "<<tab_position[e]<<endl;
    }
    for (int i=0;i<=tab_position.size()-1;i++) {
        valeur = "";
        cout <<"valeur est"<< valeur <<" et i "<< i << " zzzzzzzzzzzzzzzzz\n";
        cout <<"pos_act= "<<pos_act<<" et pos_fut= "<<pos_fut<<endl;
        while(pos_act<=pos_fut) {
            if (pos_act >= tab_position[i] and pos_act != tab_position[tab_position.size() - 1]){
                if (valeur!=""){tab_valeur.push_back(valeur);
                    cout<<"push_back "<<valeur<<endl;}
                cout << equation_dif[pos_act] << " seconde " << endl;
                valeur=equation_dif[pos_act];
                tab_valeur.push_back(valeur);
                cout<<"push_back "<<valeur<<endl;
                pos_act++;
                break;
            }
            else if (pos_act == tab_position[tab_position.size() - 1] and (equation_dif[i]=='+' or equation_dif[i]=='=' or equation_dif[i]==' ' or equation_dif[i]=='/' or equation_dif[i]=='*')){
                valeur=equation_dif[pos_act];
                tab_valeur.push_back(valeur);
                cout<<"push_back "<<valeur<<endl;
                pos_act++;
                break;
            }
            else if (pos_act == tab_position[tab_position.size() - 1]){
                valeur = valeur + equation_dif[pos_act];
                cout<<"valeur "<<valeur<<endl;
                tab_valeur.push_back(valeur);
                cout<<"push_back "<<valeur<<endl;
                pos_act++;
            }
            else{
                valeur = valeur + equation_dif[pos_act];
                cout<<"valeur "<<valeur<<endl;
            }
            pos_act++;

        }
        if (taille>=pos_fut){
            pos_fut=tab_position[i+1];
            cout<<pos_act<<"test last"<< pos_fut<<endl;}
        else{break;}
        cout<<pos_act<<" a "<< pos_fut<<endl;
    }
    cout << tab_position.size() << endl;
    for (int e = 0; e <= tab_valeur.size()-1; e++) {
        if (e!=0){cout << tab_valeur[e]<<"  ab "<<tab_position[e-1]<<endl;}
        else{cout << tab_valeur[e]<<"  ab "<<0<<endl;}
    }
    for (int e = 0; e <= tab_valeur.size()-1; e++) {
        cout << tab_valeur[e]<<" ";
    }
                cout << "\n"<<pos_act++<<endl;
}
