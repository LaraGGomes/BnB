#ifndef SOLUCAO_H
#define SOLUCAO_H

#include <limits>
#include "algoritmo-hungaro/src/hungarian.h"
#include "Arvore.h"
#include "Branching.h"

using namespace std;

void criarMatriz(hungarian_problem_t* p, vector<vector<bool>> &matriz);
void novaSolucao(no &node, hungarian_problem_t *p, size_t &n, double **c);
double framework(hungarian_problem_t* p, string &modo, size_t n, double **matrizCusto);

#endif