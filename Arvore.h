#ifndef ARVORE_H
#define ARVORE_H

#include <vector>
#include <algorithm>
#include <list>

using namespace std;

typedef struct noArvore {
    vector<pair<int,int>> arcos_proibidos;
    vector<vector<int>> subtour;
    double lower_bound; // custo total da solução
    int escolhido;
    bool viavel;
}no;

vector<pair<int,int>> arcos_proibidos(vector<vector<int>> &subtours, int escolhido);
vector<vector<int>> subtours(vector<vector<bool>> &matriz);
int subtourEscolhido(vector<vector<int>> &subtours);
bool ehViavel(vector<vector<int>> &subtours);

#endif