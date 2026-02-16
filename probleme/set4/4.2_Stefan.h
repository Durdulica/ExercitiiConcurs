#ifndef INC_4_2_STEFAN_H
#define INC_4_2_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da o mat. n x m cu val. intregi. Det. celula cu val. maxima. Afisati valoare si pozitia. Daca sunt mai multe, alegeti
//cea mai din stanga sus

void citire(int mat[101][101], int &n, int &m) {
    ifstream fin("file.in.txt");
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> mat[i][j];
        }
    }
}

struct result {
    int diff = INT_MIN;
    int row = -1;
    int col = -1;
};

result rezolvare(int mat[101][101], int n, int m) {
    int bestCel = mat[1][1], bestRow = 1, bestCol = 1;
    // citire(mat, n, m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(mat[i][j] > bestCel || (mat[i][j] == bestCel && i < bestRow || (i == bestRow && j < bestCol))) {
                bestCel = mat[i][j];
                bestRow = i, bestCol = j;
            }
        }
    }

    result rez;
    rez.diff = bestCel;
    rez.row = bestRow;
    rez.col = bestCol;
    return rez;
}

void assert_eq(result actual, result expected) {
    if(actual.diff != expected.diff || actual.row != expected.row || actual.col != expected.col) {
        cout << "Failed: expected " << expected.diff << " " << expected.row << " " << expected.col << " but got "
        << actual.diff << " " << actual.row << " " << actual.col << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void test1() {
    int mat[101][101] = {};
    mat[1][1] = 1; mat[1][2] = 5, mat[1][3] = 2;
    mat[2][1] = 0; mat[2][2] = 5, mat[2][3] = 4;
    mat[3][1] = 3; mat[3][2] = 2, mat[3][3] = 1;
    int n = 3, m = 4;

    result rez = rezolvare(mat, n, m);
    result expected;
    expected.diff = 5;
    expected.row = 1;
    expected.col = 2;

    assert_eq(rez, expected);
}

#endif //INC_4_2_STEFAN_H
