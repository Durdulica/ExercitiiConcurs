#ifndef INC_4_5_STEFAN_H
#define INC_4_5_STEFAN_H
#include <iostream>
using namespace std;

//se da o matr. n x m. Jetonul porneste in (n,m). La fiecare mutare se poate merge doare pe diagonala de sus-stanga(i-1,j-1)
//Jucatorii muta alternativ si aduna val. celulelor unde ajung. Det. dif. maxima P1 - P2

int rezolvare(int mat[101][101], int n, int m) {
    int dim = 0;
    int v[101] = {};
    int prefixBest[101][2] = {};
    int diffVal[101] = {};

    for(int i = n, j = m; i > 0 && j > 0; i--, j--) {
        v[dim++] = mat[i][j];
    }

    int *aux = new int[dim], ind = dim;
    for(int i = 0; i < dim; i++) {
        aux[i] = v[i];
    }
    for(int i = 0; i < dim; i++) {
        v[i] = aux[--ind];
    }
    delete[] aux;

    int bestDiff = INT_MIN;
    int rowBest = INT_MIN;
    for(int i = 0; i < dim; i++) {
        int bestCand = prefixBest[i - 1][1];
        if(rowBest > bestCand) {
            bestCand = rowBest;
        }

        if(bestCand == INT_MIN) {
            diffVal[i] = 0;
        }else {
            diffVal[i] = bestCand;
        }

        int gVal = v[i] - diffVal[i];
        if(gVal > rowBest) {
            rowBest = gVal;
        }

        int curPref = prefixBest[i - 1][1];
        if(prefixBest[i][0] > curPref) {
            curPref = prefixBest[i][0];
        }
        if(gVal > curPref) {
            curPref = gVal;
        }
        prefixBest[i][1] = curPref;

        if(diffVal[i] > bestDiff) {
            bestDiff = diffVal[i];
        }
    }

    return bestDiff;
}

void assert_eq(int actual, int expected) {
    if (actual != expected) {
        cout << "Failed: expected " << expected << " but got " << actual << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void test1() {
    int mat[101][101] = {};
    mat[1][1] = 1; mat[1][2] = 2; mat[1][3] = 3;
    mat[2][1] = 4; mat[2][2] = 5; mat[2][3] = 6;
    mat[3][1] = 7; mat[3][2] = 8; mat[3][3] = 9;
    int n = 3, m = 3;
    int rez = rezolvare(mat, n, m);
    assert_eq(rez, 4);
}
#endif //INC_4_5_STEFAN_H
