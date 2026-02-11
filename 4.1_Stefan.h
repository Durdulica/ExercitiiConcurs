#ifndef INC_4_1_STEFAN_H
#define INC_4_1_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da o matr. n x m cu val. intregi. Jetonul porneste in (n,m) si la fiecare mutare se poate merge in sus sau in stanga cu
//exact 1 pas. Jucatorii muta alternativ, adunand val. celulei pe care ajung. Det. dif. max. (p1-p2) daca ambii joaca optim

void citire(int mat[101][101], int &n, int &m) {
    ifstream fin("file.in.txt");
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> mat[i][j];
        }
    }
}

void rezolvare() {
    int mat[101][101];
    int diffVal[101][101] = {};
    int prefixBest[101][101];
    int n,m;
    citire(mat,n,m);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            prefixBest[i][j] = INT_MIN;
        }
    }

    int bestDiff = mat[1][1];
    int bestRow = 0, bestCol = 0;

    for (int i = 1; i <= n; i++) {
        int rowBest = INT_MIN;
        for (int j = 1; j <= m; j++) {
            int bestCand = prefixBest[i - 1][j];
            if(rowBest > bestCand) {
                bestCand = rowBest;
            }

            if(bestCand == INT_MIN) {
                diffVal[i][j] = 0;
            }else {
                diffVal[i][j] = bestCand;
            }

            int gVal = mat[i][j] - diffVal[i][j];
            if(gVal > rowBest) {
                rowBest = gVal;
            }

            int curPref = prefixBest[i - 1][j];
            if(prefixBest[i][j - 1] > curPref) {
                curPref = prefixBest[i][j - 1];
            }
            if(gVal > curPref) {
                curPref = gVal;
            }
            prefixBest[i][j] = curPref;
            if(-1 <= j - i < 1 && diffVal[i][j] > bestDiff || (diffVal[i][j] == bestDiff &&
                (i < bestRow || i == bestRow && j < bestCol))) {
                bestDiff = diffVal[i][j];
                bestRow = i;
                bestCol = j;
            }
        }
    }

    cout << bestDiff << " " << bestRow << " " << bestCol << endl;
}
#endif //INC_4_1_STEFAN_H