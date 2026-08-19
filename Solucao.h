#ifndef SOLUCAO_H
#define SOLUCAO_H

#include <limits>
#include "algoritmo-hungaro/src/hungarian.h"
#include "Arvore.h"
#include "Branching.h"

using namespace std;

void novaSolucao(no &node, size_t &n, double **c);
double framework(string &modo, size_t n, double **matrizCusto);

#endif