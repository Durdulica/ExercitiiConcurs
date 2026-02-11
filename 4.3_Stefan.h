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

int rezolvare(int mat[101][101], int n, int m, int x, int y) {
    // citire(mat, n, m, x, y);

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

    return bestRez;
}

void assert_eq(int actual, int expected) {
    if(expected != actual) {
        cout << "Failed: expected " << expected << " but got" << actual << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void test1() {
    int mat[101][101] = {};
    mat[1][1] = 1; mat[1][2] = 2; mat[1][3] = 3;
    mat[2][1] = 4; mat[2][2] = 5; mat[2][3] = 6;
    int n = 2, m = 3, x = 2, y = 3;
    int rez = rezolvare(mat,n,m,x,y);

    assert_eq(rez,6);
}
#endif //INC_4_3_STEFAN_H
