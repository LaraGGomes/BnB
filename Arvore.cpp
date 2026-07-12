#include "Arvore.h"

vector<vector<int>> subtours(vector<vector<bool>> &matriz) {
    vector<vector<int>> s;
    bool vis[matriz.size()+1];

    for (int i = 0; i < matriz.size(); i++) {
        if (!vis[i+1]) {
            vector<int> sub;
            vis[i+1] = true;
            int j;

            sub.push_back(i+1);
            
            for (j = 0; !matriz[i][j]; j++);

            while (j != i) {
                vis[j+1] = true;
                int k;

                sub.push_back(j+1);

                for (k = 0; !matriz[j][k]; k++);
                
                if (k == i) 
                    sub.push_back(k+1);

                j = k;
            }

            s.push_back(sub);
        }
    }

    return s;
}

vector<pair<int,int>> arcos_proibidos(vector<vector<int>> &sub, int escolhido) {
    vector<pair<int,int>> arcos;

    for (int i = 0; i < sub[escolhido].size()-1; i++) {
        arcos.push_back(make_pair(sub[escolhido][i], sub[escolhido][i+1]));
    }

    return arcos;
}

int subtourEscolhido(vector<vector<int>> &s){
    int menor = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i].size() < s[menor].size())
            menor = i;
    }

    return menor;
}

bool ehViavel(vector<vector<int>> &subtours) {
    return (subtours.size() == 1);
}