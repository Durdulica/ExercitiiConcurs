#ifndef INC_7_2_STEFAN_H
#define INC_7_2_STEFAN_H
#include <iostream>
using namespace std;

//in aceleasi conditii ca in problema 1, afisati o configuratie cu nr. maxim de placi 2x2. Pt. fiecare placa afisati coordonata
//coltului stanga-sus. Daca exista mai multe solutii optime, afisati-o pe cea lexicografic minima.

void rezolvare() {
    int mat[16][151] = {};
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; k++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }

    for(int i = 1, j = 1; i < n; j++) {

        if(j == m - 1) {
            j = 0;
        }
    }
}

#endif //INC_7_2_STEFAN_H
