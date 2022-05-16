#include<string>
#include "Analyse.h"
#include "iostream"
#include <sstream>
using namespace std;

Analyse::Analyse(string equation_dif){
    this ->equation_dif=equation_dif;
}

vector<string> Analyse::verif_valeur() {
    int temp,resul,mutiplicateur,compteur(0);
    for (int i;i<10;i++){
        std::ostringstream tempi;
        tempi<<i;
        string iresult(tempi.str());
        if (equation_dif[tab_positiony[tab_position[0]]-1]==iresult[0]){
            string multiplicateurtemp;
            while( equation_dif[tab_positiony[tab_position[0]]-1]-compteur; == ' ')
        if (tab_position[2]>tab_position[0]){
            for (int e;e <tab_valeur.size();e++){
                if (tab_valeur[e].size()-1=='y'){
                    for(int value;value<tab_valeur[e].size()-2;value++){
                        std::istringstream iss(tab_valeur[value]);
                        iss>>temp;
                        resul+=temp*multiplies
                    }
                    std::ostringstream oss;

                }}}
    }}

}


vector<int> Analyse::get_tab_position(){
    cout <<tab_position.size()<<endl;
    for (int i(0);i<tab_position.size();i++){
        cout <<tab_position[i]<<" ";}
    cout<<"\n";
    return tab_position;}


vector<string> Analyse::get_tab_valeur(){
    cout <<tab_valeur.size()<<endl;
    for (int i(0);i<tab_valeur.size();i++){
        cout <<tab_valeur[i]<<" ";}
    cout<<"\n";
    return tab_valeur;}


int Analyse::get_tab_positiony() {
    string z;
    tab_position[0]=-1;
    for (int i(0); i < equation_dif.size() - 1; i++) {
        z = equation_dif[i];
        cout<<z<<" test "<<i<<endl;
        if (z=="="){tab_positiony[2]=i; cout<<tab_positiony[2]<<endl;}
        if (z == "y" and tab_positiony[0] == -1) {
            cout << "true"<<endl;
            if (equation_dif[i + 1] == char(39))
            { tab_positiony[0] = 1, tab_positiony[1] = i; cout<<z<<" y' "<<i<<endl; }
            else { tab_positiony[1] = i; tab_positiony[0] = 3; cout<<z<<" teste "<<i<<tab_positiony[0]<<endl; }
        }
        else if (z == "y") {
            cout << "False"<<endl;
            tab_positiony[3] = i;
            cout<<z<<" y' "<<i<<endl;
        }
    }
    std::cout<<" "<<tab_positiony[0]<<" "<<tab_positiony[1]<<" "<<tab_positiony[2]<<" "<<tab_positiony[3]<<endl;
    return tab_positiony[0],tab_positiony[1],tab_positiony[2],tab_positiony[3];
}


int Analyse::value_in_tab_betewen_2_point(int pos_act,int pos_fut,int i){
    string valeur("");
    while(pos_act<=pos_fut) {
        cout<<pos_act<<"pos_act"<<endl;
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
            break;
        }
        else{
            valeur = valeur + equation_dif[pos_act];
            cout<<"valeur "<<valeur<<endl;
        }
        pos_act++;

    }
    return pos_act;
}
void Analyse::analyse_position() {
    tab_positiony[0] = -1;
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
    for (int e = 0; e <= tab_valeur.size() - 1; e++) {
        if (e != 0) { cout << tab_valeur[e] << "  ab " << tab_position[e - 1] << endl; }
        else { cout << tab_valeur[e] << "  ab " << 0 << endl; }
    }
    for (int e = 0; e <= tab_valeur.size() - 1; e++) {
        cout << tab_valeur[e] << " ";
    }
    cout << "\n" << pos_act++ << endl;
}

