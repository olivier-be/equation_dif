#include<string>
#include <vector>
#ifndef UNTITLED1_ANALYSE_H
#define UNTITLED1_ANALYSE_H

class Analyse {

    private:
        std::string equation_dif;
    std::vector<int> tab_position;
        std::vector<std::string> tab_valeur;
        int value_in_tab_betewen_2_point(int pos_act,int pos_fut,int i);
public:
        void analyse_position();
        Analyse(std::string equation_dif);
        std::vector<int> get_tab_position();
        std::vector<std::string> get_tab_valeur();
        int get_tab_positiony();
        std::vector<std::string> verif_valeur();

    int tab_positiony[4];
};


#endif //UNTITLED1_ANALYSE_H

