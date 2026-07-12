#include "Solucao.h"
#include <iostream>

void criarMatriz(hungarian_problem_t* p, vector<vector<bool>> &matriz) {
    int** C = p->assignment;
    int rows = p->num_rows, cols = p->num_cols;

    matriz.resize(rows, vector<bool>(cols));

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            matriz[i][j] = C[i][j];
        }
    }
}

void novaSolucao(no &node, hungarian_problem_t *p, size_t &n, double **c) {
    int v1, v2;
    vector<double> custosOriginais(node.arcos_proibidos.size());
    
    // proibir todos os arcos
    for (int i = 0; i < node.arcos_proibidos.size(); i++) {
        v1 = node.arcos_proibidos[i].first -1, v2 = node.arcos_proibidos[i].second -1;

        custosOriginais[i] = c[v1][v2];
        c[v1][v2] = 99999999;
    }

    // construindo nova solução
    hungarian_free(p);

    hungarian_init(p, c, n, n, HUNGARIAN_MODE_MINIMIZE_COST);

    node.lower_bound = hungarian_solve(p);
    vector<vector<bool>> matrizAP;
    criarMatriz(p, matrizAP);
    
    node.subtour = subtours(matrizAP);
    node.escolhido = subtourEscolhido(node.subtour);
    node.viavel = ehViavel(node.subtour);

    // reincerir todos os custos originais dos arcos proibidos
    for (int i = 0; i < node.arcos_proibidos.size(); i++) {
        v1 = node.arcos_proibidos[i].first -1, v2 = node.arcos_proibidos[i].second -1;

        c[v1][v2] = custosOriginais[i];
    }
}

double framework(hungarian_problem_t* p, string &modo, size_t tam, double **matrizCusto) {
    no raiz;
    raiz.arcos_proibidos = {};
    novaSolucao(raiz, p, tam, matrizCusto);

    list<no> arvore;
    arvore.push_back(raiz);
    
    double upper_bound = numeric_limits<double>::infinity();

    while (!arvore.empty()) {

        auto node = branchingStrategy(arvore, modo);

        if (node->lower_bound > upper_bound) {
            arvore.erase(node);
            continue;
        }

        if (node->viavel) {
            upper_bound = min(upper_bound, node->lower_bound);
        }

        else {
            for (int i = 0; i < node->subtour[node->escolhido].size() - 1; i++) {
                no n;
                n.arcos_proibidos = node->arcos_proibidos;

                pair<int,int> arco_proibido = {
                    node->subtour[node->escolhido][i], 
                    node->subtour[node->escolhido][i+1]
                };

                n.arcos_proibidos.push_back(arco_proibido);

                novaSolucao(n, p, tam, matrizCusto);

                arvore.push_back(n);
            }
        }

        arvore.erase(node);
    }

    return upper_bound;
}