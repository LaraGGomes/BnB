#ifndef ARVORE_H
#define ARVORE_H

#include <vector>
#include <algorithm>

using namespace std;

typedef struct noArvore {
    vector<pair<int,int>> arcos_proibidos;
    vector<vector<int>> subtour;
    double lower_bound;
    int escolhido;
    bool viavel;
}no;

vector<vector<int>> subtours(vector<vector<int>> matriz);

#endif