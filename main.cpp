#include <iostream>
#include "algoritmo-hungaro/src/Data.h"
#include "algoritmo-hungaro/src/hungarian.h"
#include "Solucao.h"

using namespace std;

int main(int argc, char** argv) {

    auto data = Data(argc, argv[1]);
    data.read();
    string branching = argv[2];

    size_t n = data.getDimension();

	double **cost = new double*[n];
	for (int i = 0; i < n; i++){
		cost[i] = new double[n];
		for (int j = 0; j < n; j++){
			cost[i][j] = data.getDistance(i+1,j+1);
		}
	}

    double custo = framework(branching, n, cost);
    cout << "\nCusto da melhor solucao encontrada: " << custo << '\n';

    return 0;
}
