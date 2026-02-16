#ifndef INC_4_4_STEFAN_H
#define INC_4_4_STEFAN_H
#include <iostream>
using namespace std;

//se da o matrice n x m si o poz initiala (x,y). P1 muta o data in prefixul (1,1)-(x,y), apoi P2 muta o data in prefixul
//noii pozitii. Jocul se opreste. Det. dif. maxima P1 - P2 (ambii joaca optim)

int maxMat(int mat[101][101], int n, int m) {
    int max = INT_MIN;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == n && j == m) break;
            if(mat[i][j] > max) {
                max = mat[i][j];
            }
        }
    }
    return max;
}
//todo: de corectat
int rezolvare(int mat[101][101], int n, int m, int x, int y) {
    int diffVal[101][101] = {};

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            diffVal[i][j] = mat[i][j] - maxMat(mat, i,j);
        }
    }

    return maxMat(diffVal, m, n);
}

void assert_eq(int actual, int expected) {
    if(actual != expected) {
        cout << "Failed: expected " << expected << " but got " << actual << endl;
    }else{
        cout << "Passed" << endl;
    }
}

void test1() {
    int mat[101][101] = {};
    mat[1][1] = 1; mat[1][2] = 2;
    mat[2][1] = 3; mat[2][2] = 4;
    int n = 2, m = 2, x = 2, y = 2;

    assert_eq(rezolvare(mat, n, m, x, y), 2);
}
#endif //INC_4_4_STEFAN_H