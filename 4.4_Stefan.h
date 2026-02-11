#ifndef INC_4_4_STEFAN_H
#define INC_4_4_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da o matrice n x m si o poz initiala (x,y). P1 muta o data in prefixul (1,1)-(x,y), apoi P2 muta o data in prefixul
//noii pozitii. Jocul se opreste. Det. dif. maxima P1 - P2 (ambii joaca optim)
//todo
void citire(int mat[101][101], int &n, int &m, int &x, int&y){
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

    int prefixBest[101][101] = {};
    int diffVal[101][101] = {};

    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            prefixBest[i][j] = INT_MIN;
        }
    }

    for(int i = 1; i <= n; i++) {
        int rowBest = INT_MIN;
        for(int j = 1; j <= m; j++) {
            int bestCand = prefixBest[i - 1][j];
            if(bestCand < rowBest) {
                bestCand = rowBest;
            }

            if(bestCand == INT_MIN) {
                diffVal[i][j] = 0;
            }else {
                diffVal[i][j] = bestCand;
            }


        }
    }
}
#endif //INC_4_4_STEFAN_H