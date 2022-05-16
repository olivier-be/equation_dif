#include<string>
#include <vector>
#ifndef UNTITLED1_ANALYSE_H
#define UNTITLED1_ANALYSE_H
using namespace std;

class Analyse {

    private:
        string equation_dif;
        int tab_positiony[4];
        vector<int> tab_position;
        vector<string> separation;
    public:
        int get_tab_positiony;
        string get_separation;
        void analyse_position();
        Analyse(string equation_dif);


};


#endif //UNTITLED1_ANALYSE_H
