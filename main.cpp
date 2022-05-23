#include <iostream>
#include <string>
#include <vector>
#include "Analyse.h"
using namespace std;

vector<string>analyse(string equation_dif);

int main() {
    string separation;
    int tab_positiony;
    Analyse tab(("1y=2y'+5/2*6+22"));
    tab.analyse_position();
    tab.get_tab_positiony();
    tab.get_tab_valeur();
    tab.get_tab_position();
    return 0;
    }
