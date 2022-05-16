#include<string>
#include "Analyse.h"
#include "iostream"
using namespace std;

Analyse::Analyse(string equation_dif){
    this ->equation_dif=equation_dif;
    this ->equation_dif="";
}

void Analyse::analyse_position()
{
    int taille, pos_act, pos_fut;
    tab_positiony[1] = -1;
    char valeur_chercher;
    string valeur;
    string const alphabet("abcdefghijklmnopqrdtuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    cout << char(255) << "choisie ta forme d'equations differencielles avec pour info prime = ' \n";
    taille = this->equation_dif.size() - 1;
    for (int i = 0; i <= taille; i++) {
        valeur_chercher = this->equation_dif[i];
        if (valeur_chercher == '+' or valeur_chercher == '=' or valeur_chercher == ' ' or valeur_chercher == '/' or valeur_chercher == '*') {
            this->tab_position.push_back(i);
            cout << i << "c " << this->tab_position[this->tab_position.size() - 1] << endl;
            if (valeur_chercher == '=') { tab_positiony[2] = i; }
        } else { cout << i << "b" << endl; }

    }
    this->tab_position.push_back(taille);
    cout << "asdfqsdf" << taille << endl;
    pos_act = 0;
    pos_fut = this->tab_position[0];
    cout << pos_act << " a " << pos_fut << endl;
    for (int e = 0; e <= this->tab_position.size() - 1; e++) {
        cout << e << "  ab " << this->tab_position[e] << endl;
    }
    for (int i = 0; i <= this->tab_position.size() - 1; i++) {
        valeur = "";
        cout << "valeur est" << valeur << " et i " << i << "\n";
        cout << "pos_act= " << pos_act << " et pos_fut= " << pos_fut << endl;
        while (pos_act <= pos_fut) {
            if (this->equation_dif[i] == 'y' and this->tab_positiony[1] == -1) {
                this->tab_positiony[1] = i;
                //if (equation_dif[i+1]==
            } else if (this->equation_dif[i] == 'y') {
                this->tab_positiony[3] = i;
                //if (equation_dif[i+1]==}
                if (pos_act >= this->tab_position[i] and pos_act != this->tab_position[this->tab_position.size() - 1]) {
                    if (valeur != "") {
                        this->separation.push_back(valeur);
                        cout << "push_back " << valeur << endl;
                    }
                    cout << this->equation_dif[pos_act] << " seconde " << endl;
                    valeur = this->equation_dif[pos_act];
                    this->separation.push_back(valeur);
                    cout << "push_back " << valeur << endl;
                    pos_act++;
                    break;
                } else if (pos_act == this->tab_position[this->tab_position.size() - 1] and
                           (this->equation_dif[i] == '+' or this->equation_dif[i] == '=' or this->equation_dif[i] == ' ' or
                                   this->equation_dif[i] == '/' or this->equation_dif[i] == '*')) {
                    valeur = this->equation_dif[pos_act];
                    this->separation.push_back(valeur);
                    cout << "push_back " << valeur << endl;
                    pos_act++;
                    break;
                } else if (pos_act == this->tab_position[this->tab_position.size() - 1]) {
                    valeur = valeur + this->equation_dif[pos_act];
                    cout << "valeur " << valeur << endl;
                    this->separation.push_back(valeur);
                    cout << "push_back " << valeur << endl;
                    pos_act++;
                } else {
                    valeur = valeur + this->equation_dif[pos_act];
                    cout << "valeur " << valeur << endl;
                }
                pos_act++;

            }
        }

    }
}
