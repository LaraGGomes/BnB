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

    // organizar por tamanho de subtour para o primeiro ser o menor
    sort(s.begin(), s.end(), [&](const auto &x, const auto &y) {
        return x.size() < y.size();
    });

    return s;
}