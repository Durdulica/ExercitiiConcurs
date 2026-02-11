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

void rezolvare() {
    int mat[101][101];
    int n, m;
    int bestCel = mat[1][1], bestRow = 1, bestCol = 1;
    citire(mat, n, m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(mat[i][j] > bestCel || (mat[i][j] == bestCel && i < bestRow || (i == bestRow && j < bestCol))) {
                bestCel = mat[i][j];
                bestRow = i, bestCol = j;
            }
        }
    }

    cout << bestCel << " " << bestRow << " " << bestCol << endl;
}
#endif //INC_4_2_STEFAN_H
