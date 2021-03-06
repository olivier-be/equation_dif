#include<string>
#include "Analyse.h"
#include "iostream"
#include <sstream>
using namespace std;

Analyse::Analyse(string equation_dif){
    this ->equation_dif=equation_dif;
    this -> compteur=0;
    this -> compteur_cal=0;
    this -> compteur=0;
}

int Analyse:: research(int position_act) {
    // ne prend pas en compte la priorité de calculer des * et /
    int multiplicateur,denominateur,produit;
    string multiplicateurtemp(""), denominateurtemp(""), prdouittemp;
    for (int i; i < 10; i++) {
        std::ostringstream tempi("");
        std:: stringstream tempmultplicateur, tempproduit, tempdenominateur;
        tempi << i;
        string iresult(tempi.str());
        if (equation_dif[position_act - 1-compteur_cal] == iresult[0]) {

            multiplicateurtemp = equation_dif[position_act];
            while (equation_dif[position_act - 2 - compteur] != ' ' or
                   equation_dif[position_act - 2 - compteur] != '+' or
                   equation_dif[position_act - 2 - compteur] != '-') {
                if (equation_dif[position_act - 2 - compteur] != '/') {
                    while (equation_dif[position_act - 2 - compteur] != ' ' or
                           equation_dif[position_act - 2 - compteur] != '+' or
                           equation_dif[position_act - 2 - compteur] != '-') {
                        denominateurtemp += equation_dif[position_act - 2 - compteur];
                        equation_dif.erase(position_act - 2 - compteur);
                        compteur += 1;
                    }
                } else if (equation_dif[position_act - 2 - compteur] != '*') {
                    while (equation_dif[position_act - 2 - compteur] != ' ' or
                           equation_dif[position_act - 2 - compteur] != '+' or
                           equation_dif[position_act - 2 - compteur] != '-') {
                        prdouittemp += equation_dif[position_act - 2 - compteur];
                        equation_dif.erase(position_act - 2 - compteur);
                        compteur += 1;
                    }
                } else {
                    multiplicateurtemp += equation_dif[position_act - 2 - compteur];
                    equation_dif.erase(position_act - 2 - compteur);
                    compteur += 1;
                }
            }
        }
        tempmultplicateur << multiplicateurtemp;
        tempmultplicateur >> multiplicateur;
        tempdenominateur << denominateurtemp;
        tempdenominateur >> denominateur;
        tempproduit << prdouittemp;
        tempproduit >> produit;
        if (denominateur == 0) { denominateur = 1; }
        if (produit == 0) { produit = 1; }
        multiplicateur = (multiplicateur * produit) / denominateur;

    }
    return multiplicateur;
}



void Analyse::verif_valeur() {
//  reparer en utilisant la postion des valeur puis reactualiser le tableau
    int temp, multiplicateur,min,max,x,result(0);
    multiplicateur = research(tab_positiony[tab_positiony[0]]);
    search_tab_positiony();
    search_tab_positiony_tab_valeur();
    if (tab_positiony_tab_valeur[2] > tab_positiony_tab_valeur[tab_positiony_tab_valeur[0]]) {
        max=tab_positiony_tab_valeur[tab_positiony_tab_valeur[0]];
        min=0;
    }
    else
    {
        max=tab_valeur.size()-1;
        min=tab_positiony_tab_valeur[tab_positiony_tab_valeur[0]];
    }
    for (int e(min); e <max ; e++) {
        x=0;
        if (tab_valeur_int[e]!=NULL) {
            if (tab_valeur[e].size() - 1 == 'y') {
                x = 2;
            } else if (tab_valeur[e].size() - 1 == char(39)) { 
                while (tab_valeur[e].size() - 1-x== char(39)) {x+= 1;} }
            else { x = 0; }
            for (int value(e); value < tab_valeur[e + 1].size() - x; value++) {
                std::istringstream iss(tab_valeur[value]);
                iss >> temp;
                result += temp * multiplicateur;
            }
            tab_valeur_int[e] = result;
            }
        }
        
    }

vector<int> Analyse::get_tab_position() {
    analyse_position();
    cout << tab_position.size() << endl;
    for (int i; i < tab_position.size(); i++) {
        cout << tab_position[i] << " ";
    }
    cout << "\n";
    return tab_position;
}


vector<string> Analyse::get_tab_valeur() {
    search_tab_positiony ();
    cout << tab_valeur.size() << endl;
    for (int i; i < tab_valeur.size(); i++) {
        cout << tab_valeur[i] << " ";
    }
    cout << "\n";
    return tab_valeur;
}

void Analyse::search_tab_positiony (){
    analyse_position();
    string z;
    tab_positiony[0] = -1;
    for (int i(0); i < equation_dif.size() - 1; i++) {
        z = equation_dif[i];
        cout << z << " test " << i << endl;
        if (z == "=") {
            tab_positiony[2] = i;
            cout << tab_positiony[2] << endl;
        }
        if (z == "y" and tab_positiony[0] == -1) {
            cout << "true" << endl;
            if (equation_dif[i + 1] == char(39)) {
                tab_positiony[0] = 1, tab_positiony[1] = i;
                cout << z << " y' " << i << endl;
            }
            else {
                tab_positiony[1] = i;
                tab_positiony[0] = 3;
                cout << z << " teste " << i << tab_positiony[0] << endl;
            }
        } else if (z == "y") {
            cout << "False" << endl;
            tab_positiony[3] = i;
            cout << z << " y' " << i << endl;
        }
    }
}

void Analyse::search_tab_positiony_tab_valeur() {
    analyse_position();
    string z, str;
    tab_positiony_tab_valeur[0] = -1;
    for (int e; e < (tab_valeur.size())-2; e++) {
        for (int temp(tab_position[e]);temp<tab_position[e+1];temp++)
            str+=equation_dif[temp];
        for (int i(0); i<str.size();i++){
            z = str[i];
            cout << z << " test " << i << endl;
            if (z == "=") {
                tab_positiony_tab_valeur[2] = i;
                cout << tab_positiony_tab_valeur[2] << endl;
            }
            if (z == "y" and tab_positiony[0] == -1) {
                cout << "true" << endl;
                if (str[i + 1] == char(39)) {
                    tab_positiony_tab_valeur[0] = 1, tab_positiony_tab_valeur[1] = i;
                    cout << z << " y' " << i << endl;
                } else {
                    tab_positiony_tab_valeur[1] = i;
                    tab_positiony_tab_valeur[0] = 3;
                    cout << z << " teste " << i << tab_positiony_tab_valeur[0] << endl;
                }
            } else if (z == "y") {
                cout << "False" << endl;
                tab_positiony_tab_valeur[3] = i;
                cout << z << " y' " << i << endl;
            }
        }
    }
}

int Analyse::get_tab_positiony() {
    std::cout << " " << tab_positiony[0] << " " << tab_positiony[1] << " " << tab_positiony[2] << " "
              << tab_positiony[3] << endl;
    return tab_positiony[0], tab_positiony[1], tab_positiony[2], tab_positiony[3];
}

int Analyse::value_in_tab_betewen_2_point(int pos_act, int pos_fut, int i) {
    string valeur("");
    while (pos_act <= pos_fut) {
        cout << pos_act << "pos_act" << endl;
        if (pos_act >= tab_position[i] and pos_act != tab_position[tab_position.size() - 1]) {
            if (valeur != "") {
                tab_valeur.push_back(valeur);
                cout << "push_back " << valeur << endl;
            }
            cout << equation_dif[pos_act] << " seconde " << endl;
            valeur = equation_dif[pos_act];
            tab_valeur.push_back(valeur);
            cout << "push_back " << valeur << endl;
            pos_act++;
            break;
        } else if (pos_act == tab_position[tab_position.size() - 1] and
                   (equation_dif[i] == '+' or equation_dif[i] == '=' or equation_dif[i] == ' ' or
                    equation_dif[i] == '/' or equation_dif[i] == '*')) {
            valeur = equation_dif[pos_act];
            tab_valeur.push_back(valeur);
            cout << "push_back " << valeur << endl;
            pos_act++;
            break;
        } else if (pos_act == tab_position[tab_position.size() - 1]) {
            valeur = valeur + equation_dif[pos_act];
            cout << "valeur " << valeur << endl;
            tab_valeur.push_back(valeur);
            cout << "push_back " << valeur << endl;
            pos_act++;
            break;
        } else {
            valeur = valeur + equation_dif[pos_act];
            cout << "valeur " << valeur << endl;
        }
        pos_act++;

    }
    return pos_act;
}
void Analyse::analyse_position() {
    tab_positiony[0] = -1;
    tab_valeur.clear();
    int taille, pos_act, pos_fut;
    char z;
    string valeur, reponce;
    string const alphabet("abcdefghijklmnopqrdtuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    //cout << char(255)<<"choisie ta forme d'equations differencielles avec pour info prime = ' \n";
    //cin >> equation_dif;
    taille = equation_dif.size() - 1;
    for (int i = 0; i <= taille; i++) {
        z = equation_dif[i];
        if (z == '+' or z == '=' or z == ' ' or z == '/' or z == '*') {
            tab_position.push_back(i);
            cout << i << "c " << tab_position[tab_position.size() - 1] << endl;
        } else {
            cout << i << "b" << endl;
        }


    }
    tab_position.push_back(taille);
    cout << "asdfqsdf" << taille << endl;
    pos_act = 0;
    pos_fut = tab_position[0];
    cout << pos_act << " a " << pos_fut << endl;
    for (int e = 0; e <= tab_position.size() - 1; e++) {
        cout << e << "  ab " << tab_position[e] << endl;
    }
    for (int i = 0; i <= tab_position.size() - 1; i++) {
        valeur = "";
        cout << "valeur est" << valeur << " et i " << i << " zzzzzzzzzzzzzzzzz\n";
        cout << "pos_act= " << pos_act << " et pos_fut= " << pos_fut << endl;
        pos_act = value_in_tab_betewen_2_point(pos_act, pos_fut, i);

        if (taille >= pos_fut) {
            pos_fut = tab_position[i + 1];
            cout << pos_act << "test last" << pos_fut << endl;
        } else { break; }
        cout << pos_act << " a " << pos_fut << endl;
    }
    cout << tab_position.size() << endl;
    int actuel_pos(0),cal,temp;
    for (int e = 0; e <= tab_valeur.size() - 1; e++) {
        if (e != 0) { cout << tab_valeur[e] << "  ab " << tab_position[e - 1] << endl; }
        else { cout << tab_valeur[e] << "  ab " << 0 << endl;}
        if (tab_valeur[e][tab_valeur[e].size()-1]!='y' or tab_valeur[e][tab_valeur[e].size()-1]!=char(39)or tab_valeur[e]!="+" or tab_valeur[e]!="-" or tab_valeur[e]!="/" or tab_valeur[e]!="*") {
            if (tab_position[e]<tab_position[actuel_pos]){
                std::istringstream iss(tab_valeur[e]);
                iss >> temp;
                cal += temp;
                }
            else{
                tab_valeur_int.push_back(cal);
                cal=0;
                actuel_pos+=1;
                std::istringstream iss(tab_valeur[e]);
                iss >> temp;
                cal += temp;
            }

        }
        else if( tab_valeur[e]=="+" or tab_valeur[e]=="-" or tab_valeur[e]=="/" or tab_valeur[e]=="*"){
            tab_valeur_int.push_back(NULL);
        }
    }
    for (int e = 0; e <= tab_valeur.size() - 1; e++) {
        cout << tab_valeur[e] << " ";
    }
    cout << "\n" << pos_act++ << endl;
}
