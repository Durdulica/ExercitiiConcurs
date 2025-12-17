#ifndef TEORIE3_H
#define TEORIE3_H
#include <iostream>
#include <string.h>
using namespace std;

//se considera doua siruri de n, respectiv m caractere. Asupra primului cuvant se pot face urmatoarele schimbari in asa fel incat acesta
//sa ajunga identic cu al doilea

int n,m,c[101][101];
char a[101], b[101];

void citire() {
    cin.getline(a, 100);
    cin.getline(b, 100);
    n = (int)strlen(a);
    m = (int)strlen(b);
}


int min(int a, int b) {
    return a < b ? a : b;
}

void solve() {
    citire();
    for(int i = 1; i <= n; i++) c[i][0] = i;
    for(int j = 1; j <= m; j++) c[0][j] = j;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                c[i][j] = c[i-1][j-1];
            }else {
                c[i][j] = min(min(c[i-1][j],c[i][j-1]),c[i-1][j-1]) + 1;
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
#endif //TEORIE3_H
