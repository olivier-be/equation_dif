#include<string>
#include <vector>
#ifndef UNTITLED1_ANALYSE_H
#define UNTITLED1_ANALYSE_H

class Analyse {

    private:
        int tab_positiony[4];
        int search_tab_positiony_tab_valeur[4];
        int compteur,compteur_cal;
        std::string equation_dif;
        std::vector<int> tab_position;
        std::vector<std::string> tab_valeur;
        int research(int position_act);
        int value_in_tab_betewen_2_point(int pos_act,int pos_fut,int i);
        void search_tab_positiony();
        void search_tab_positiony_tab_valeur();

public:
        void analyse_position();
        Analyse(std::string equation_dif);
        std::vector<int> get_tab_position();
        std::vector<std::string> get_tab_valeur();
        int get_tab_positiony();
        std::vector<std::string> verif_valeur();


};


#endif //UNTITLED1_ANALYSE_H
