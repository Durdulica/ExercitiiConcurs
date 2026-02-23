#ifndef INC_7_1_STEFAN_H
#define INC_7_1_STEFAN_H
#include <iostream>
using namespace std;

//se da o grila n x m. Unele celule sunt marcate ca "bune" si nu pot fi acoperite. Restul celulelor(stricate) pot fi acoperite
//cu placi 2x2. O placa trebuie sa acopere exact 4 celule stricate si nu se poate suprapune cu alte placi. Det. nr. maxim de placi
//2x2 care pot fi amplasate

int rezolvare(int mat[16][151], int n, int m) {
    int rez = 0;
    for(int i = 1, j = 1; i < n; j++) {
        if(mat[i][j] == 0 && mat[i + 1][j] == 0 && mat[i][j + 1] == 0 && mat[i + 1][j + 1] == 0) {
            mat[i][j] = mat[i + 1][j] = mat[i][j + 1] = mat[i + 1][j + 1] = 2;
            rez++;
            j++;
        }
        if(j == m - 1) {
            j = 0;
            i++;
        }
    }

    return rez;
}

void assert_eq(int expected, int actual) {
    if(expected != actual) {
        cout << "Failed: expected " << expected << " but got " << actual << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void testare() {
    int mat[16][151] = {};
    int n = 4, m = 6, k = 3;
    cout << "Coordonatele celor k placi bune: ";
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }

    int rez = rezolvare(mat, n, m);
    int expected = 4;   //sa se modifice in functie de rezultatul asteptat
    assert_eq(expected, rez);
}
#endif //INC_7_1_STEFAN_H
