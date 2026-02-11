#ifndef INC_4_3_STEFAN_H
#define INC_4_3_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da o mat n x m cu val. intregi si o poz. initiala (x,y). Jucatorul 1 face o singura mutare intr-o celula din
//dreptunghiul (1,1)-(x,y), apoi jocul se opreste. Det. dif. maxima P1 - P2(P2 nu mai muta)

void citire(int mat[101][101], int &n, int &m, int &x, int &y) {
    ifstream fin("file.in.txt");
    fin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            fin >> mat[i][j];
        }
    }
    fin >> x >> y;
}

void rezolvare() {
    int mat[101][101];
    int n, m, x, y;
    citire(mat, n, m, x, y);

    int bestRez = mat[1][1], bestRow = 1, bestCol = 1;

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            if(bestRez < mat[i][j] || (bestRez == mat[i][j] && bestRow < i || (bestRow == i && bestCol < j) )) {
                bestRez = mat[i][j];
                bestRow = i;
                bestCol = j;
            }
        }
    }

    cout << bestRez << endl;
}
#endif //INC_4_3_STEFAN_H
