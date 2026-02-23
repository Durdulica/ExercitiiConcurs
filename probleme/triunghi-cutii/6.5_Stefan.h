#ifndef INC_6_5_STEFAN_H
#define INC_6_5_STEFAN_H
#include <iostream>
using namespace std;

//sa da n si apoi q interogari. Fiecare interogare ofera un interval [A,B]. Pt. fiecare interogare, tb. sa det. daca exista
//o baza strict pozitiva care genereaza un triunghi valid cu suma totala s in [A,B]. Afisati pentru fiecare interogare nr.
//de sume realizabile din interval

bool dfsBase(int idx, int n, int remaining, int *weights, int *suffixMin, int*base){
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

void rezolvare() {
    int n, q;
    if(!(cin >> n >> q)) {
        cout << "Error on reading\n";
        return;
    }

    if(n <= 0) {
        return;
    }

    int **comb = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        comb[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            comb[i][j] = 0;
        }
    }

    for(int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    int *weights = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        weights[i] = 0;
    }
    for(int k = 1; k <= n; k++) {
        int w = 0;
        for(int r = 1; r <= n; r++) {
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

    int *base = new int[n + 1];
    for (int i = 0; i <= n; ++i) {
        base[i] = 0;
    }
    for(int i = 0; i < q; i++) {
        int l, r, cnt = 0;
        cin >> l >> r;
        for(int s = l; s <= r; s++) {
            if(s >=  suffixMin[1] && dfsBase(1, n, s, weights, suffixMin, base)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    for(int i = 0; i <= n; i++) {
        delete[] comb[i];
    }
    delete[] comb;
    delete[] weights;
    delete[] suffixMin;
    delete[] base;
}
#endif //INC_6_5_STEFAN_H