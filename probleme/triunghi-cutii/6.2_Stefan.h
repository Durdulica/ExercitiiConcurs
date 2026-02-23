#ifndef INC_6_2_STEFAN_H
#define INC_6_2_STEFAN_H
#include <iostream>
using namespace std;

//se dau n si s. Daca exista configuratii valide, afisati baza cu val. strict pozitive care produce suma totala s si este
//minima lexicografic. Daca nu exista, afisati impossible

bool dfsBase(int idx, int n, int remaining, int *weights, int *suffixMin, int *base){
    if(idx > n) {
        return remaining == 0;
    }
    if(remaining < suffixMin[idx]) {
        return false;
    }

    int minAfter = suffixMin[idx + 1];
    int w = weights[idx];
    int maxVal = (remaining - minAfter) / w;
    if(maxVal < 1) {
        return false;
    }

    for(int v = 1; v <= maxVal; v++) {
        base[idx] = v;
        if(dfsBase(idx + 1, n, remaining - v * w, weights, suffixMin, base)) {
            return true;
        }
    }
    return false;
}

void rezolvare(){
    int n, s;
    if(!(cin >> n >> s)) {
        cout << "Error on reading\n";
        return;
    }
    if(n <= 0) {
        cout << "impossible\n";
        return;
    }

    int **comb = new int*[n + 1];
    for(int i = 0; i < n + 1; i++) {
        comb[i] = new int[n + 1];
        for(int j = 0; j < n + 1; j++) {
            comb[i][j] = 0;
        }
    }
    for(int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }

    int *weights = new int[n + 1];
    for(int i = 0; i < n + 1; i++) {
        weights[i] = 0;
    }
    for(int k = 1; k <= n; k++) {
        int w = 0;
        for(int r = 1; r <= n; r++){
            int depth = n - r;
            int tStart = k - r;
            int tEnd = k - 1;
            for(int t = tStart; t <= tEnd; t++) {
                if(t >= 0 && t <= depth) {
                    w += comb[depth][t];
                }
            }
        }
        weights[k] = w;
    }

    int *suffixMin = new int[n + 2];
    for(int i = 0; i <= n + 1; i++) {
        suffixMin[i] = 0;
    }
    for(int i = n; i >= 1; i--) {
        suffixMin[i] = suffixMin[i + 1] + weights[i];
    }

    if(s < suffixMin[1]) {
        cout << "impossible\n";
        for(int i = 0; i < n + 1; i++) {
            delete[] comb[i];
        }
        delete[] comb;
        delete[] weights;
        delete[] suffixMin;
        return;
    }

    int *base = new int[n + 1];
    for(int i = 0; i < n + 1; i++) {
        base[i] = 0;
    }
    if(!dfsBase(1,n,s,weights,suffixMin,base)) {
        cout << "impossible\n";
        for(int i = 0; i < n + 1; i++) {
            delete[] comb[i];
        }
        delete[] comb;
        delete[] weights;
        delete[] suffixMin;
        delete[] base;
        return;
    }

    for(int i = 1; i <= n; i++) {
        cout << base[i] << " ";
    }
    for(int i = 0; i < n + 1; i++) {
        delete[] comb[i];
    }
    delete[] comb;
    delete[] weights;
    delete[] suffixMin;
    delete[] base;
}
#endif //INC_6_2_STEFAN_H
