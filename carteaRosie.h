#ifndef CARTEAROSIE_H
#define CARTEAROSIE_H
#include <iostream>
#include <math.h>
using namespace std;

//Pentru un nr. n <= 100 dat, sa se det. cel mai mic nr. nat. care are exact n div. Fisierul de intrare contine pe prima linie, nr n al div.
//pe care trebuiesa ii aiba nr. cautat

const int p[16] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int n, d[101], nd, rez[101];
double a[16][101];
char t[16][101];

void inmul(int a[], int b) {
    int i, t = 0;
    for(i = 1;i <= a[0] || t; i++, t/= 10) {
        a[i] = (t += a[i] * b) % 10;
    }
    a[0] = i - 1;
}

void refa(int i, int j) {
    int k = t[i][j], it;
    if(i == 0) return;

    for(it = 1; it < d[j]/d[k]; it++) {
        inmul(rez, p[i]);
    }
    refa(i - 1, k);
}

void solve() {
    int i, j, k;
    double T;
    cin >> n;
    for(i = 1; i <= n; i++) {
        if(n % i == 0) d[nd++] = i;
    }
    a[0][0] = 0.0;
    for(i = 1; i < nd; i++) {
        a[0][i] = 1e13;
    }
    for(i = 1; i <= 15; i++) {
        a[i][0] = 0.0;
        t[i][0] = 0;
        for(j = 1; j < nd; j++) {
            a[i][j] = a[i-1][j];
            t[i][j] = j;
            for(k = 0; k < j; k++) {
                if(d[j] % d[k]) continue;
                T = a[i - 1][k] + (double)(d[j]/d[k]-1) * log(p[i]);
                if(a[i][j] > T) {
                    a[i][j] = T;
                    t[i][j] = k;
                }
            }
        }
    }
    rez[0] = rez[1] = 1;
    refa(15, nd - 1);

    for(i = rez[0]; i > 0; i--) {
        cout << rez[i];
    }

}
#endif //CARTEAROSIE_H
