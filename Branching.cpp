#include "Branching.h"

no branchingStrategy(string s) {
    // função pra melhor legibilidade
    if (s == "DFS") return DFS();
    if (s == "BFS") return BFS();
    if (s == "LB") return menorLB();
}

no DFS();
no BFS();
no menorLB();