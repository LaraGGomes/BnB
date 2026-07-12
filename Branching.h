#ifndef BRANCHING_H
#define BRANCHING_H

#include "Arvore.h"
#include <string>
#include <queue>

list<no>::iterator branchingStrategy(list<no> &arvore, string &modo);
list<no>::iterator DFS(list<no> &arvore);
list<no>::iterator BFS(list<no> &arvore);
list<no>::iterator menorLB(list<no> &arvore);

#endif