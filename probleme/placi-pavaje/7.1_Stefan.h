#ifndef INC_7_1_STEFAN_H
#define INC_7_1_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da o grila n x m. Unele celule sunt marcate ca "bune" si nu pot fi acoperite. Restul celulelor(stricate) pot fi acoperite
//cu placi 2x2. O placa trebuie sa acopere exact 4 celule stricate si nu se poate suprapune cu alte placi. Det. nr. maxim de placi
//2x2 care pot fi amplasate

void rezolvare() {
    int mat[16][151] = {};
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }

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

    cout << rez << endl;

}
#endif //INC_7_1_STEFAN_H
