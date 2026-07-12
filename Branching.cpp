#include "Branching.h"
#include<iostream>

list<no>::iterator branchingStrategy(list<no> &arvore, string &modo) {
    // função pra melhor legibilidade
    if (modo == "DFS") return DFS(arvore);
    if (modo == "BFS") return BFS(arvore);
    if (modo == "LB") return menorLB(arvore);
    return BFS(arvore);
}

list<no>::iterator DFS(list<no> &arvore) {
    //cout << "DFS\n";
    return prev(arvore.end());
}
list<no>::iterator BFS(list<no> &arvore) {
    //cout << "BFS\n";
    return arvore.begin();
}
list<no>::iterator menorLB(list<no> &arvore) {
    auto it = min_element(arvore.begin(), arvore.end(), [](const no& a, const no& b) {
        return a.lower_bound < b.lower_bound;
    });

    return it;
}