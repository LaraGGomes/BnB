#include "Branching.h"

list<no>::iterator branchingStrategy(list<no> &arvore, string &modo) {
    // função pra melhor legibilidade
    if (modo == "DFS") return DFS(arvore);
    if (modo == "BFS") return BFS(arvore);
    if (modo == "LB") return menorLB(arvore);
    return DFS(arvore);
}

list<no>::iterator DFS(list<no> &arvore) {
    return prev(arvore.end());
}
list<no>::iterator BFS(list<no> &arvore) {
    return arvore.begin();
}
list<no>::iterator menorLB(list<no> &arvore) {
    auto it = min_element(arvore.begin(), arvore.end(), [](const no& a, const no& b) {
        return a.lower_bound < b.lower_bound;
    });

    return it;
}