#include <iostream>
# include <string>
# include <vector>
using namespace std;
int main() {
    bool b;
    int taille,pos_act,pos_fut;
    vector <int> tab_position;
    vector <string> tab_valeur;
    char z;
    string equation_dif("y5=10/2y'+25+30"),valeur,reponce;
    cout << "choisie ta forme d'equations differencielles avec pour info prime = ' \n";
    //cin >> equation_dif;
    taille= equation_dif.size()-1;
    for (int i=0;i<=taille;i++)
    {
        z=equation_dif[i];
        if (z=='+' or z=='=' or z==' ' or z=='/')
    {
        tab_position.push_back(i);
        cout << i<<"c"<<endl;
    }
        cout << i<<"b"<<endl;
    }
    tab_position.push_back(taille);
    cout << tab_position.size()<<endl;
    pos_act=0;
    pos_fut=tab_position[0];
    for (int i=0;i<=tab_position.size();i++) {
        valeur = "";
        cout << i << "zzzzzzzzzzzzzzzzz\n";
        cout << valeur << endl;

            for (int e = pos_act; e <= pos_fut+1 ; e++) {
                if (e==tab_position[i] and e!= tab_position[tab_position.size()-1]){
                    tab_valeur.push_back(valeur);
                    cout << valeur << " seconde " << endl;
                    valeur=equation_dif[e];
                    tab_valeur.push_back(valeur);
                }
                else{
                    valeur = valeur + equation_dif[e];
                }
                if (e== tab_position[tab_position.size()-1]){tab_valeur.push_back(valeur);}
                pos_act=e;
                pos_fut=tab_position[i];
                cout<<pos_act<<" a "<< pos_fut<<endl;
            }
    }

    for (int e = 0; e <= tab_valeur.size()-1; e++) {
        cout << tab_valeur[e]<<" ";
    }

    return 0;
}
