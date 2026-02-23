#ifndef INC_6_4_STEFAN_H
#define INC_6_4_STEFAN_H
#include <iostream>
using namespace std;

//se dau n, s, L si R. Baza triunghiului tb. sa contina numai valori in intervalul [L,R], iar restul regulilor raman la fel
//Det. daca exista configuratie si, daca da, afisati un valida

bool dfsBase(int idx, int n ,int remaining, int *weights, int *suffixMin, int *base, int L, int R) {
    if(idx > n) {
        return remaining == 0;
    }
    if(remaining < suffixMin[idx]) {
        return false;
    }

    int w = weights[idx];

    for(int v = L; v <= R; v++) {
        base[idx] = v;
        if(dfsBase(idx + 1, n, remaining - v * w, weights, suffixMin, base, L, R)) {
            return true;
        }
    }
    return false;
}

int *rezolvare(int n, int s, int L, int R) {
    // if(!(cin >> n >> s >> L >> R)) {
        // cout << "Error on reading\n";
        // return nullptr;
    // }
    if(n <= 0) {
        // cout << "impossible\n";
        return nullptr;
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
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
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
    for(int i = 0; i <= n; i++) {
        suffixMin[i] = 0;
    }
    for(int i = n; i >= 1; i--) {
        suffixMin[i] = suffixMin[i + 1] + weights[i];
    }

    if(s < suffixMin[1]) {
        // cout << "impossible\n";
        for(int i = 0; i <= n; i++) {
            delete[] comb[i];
        }
        delete[] comb;
        delete[] weights;
        delete[] suffixMin;
        return nullptr;
    }

    int *base = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        base[i] = 0;
    }

    if(!dfsBase(1,n,s,weights,suffixMin,base,L,R)) {
        // cout << "impossible\n";
        for(int i = 0; i <= n; i++) {
            delete[] comb[i];
        }
        delete[] comb;
        delete[] weights;
        delete[] suffixMin;
        delete[] base;
        return nullptr;
    }

    for(int i = 0; i <= n; i++) {
        delete[] comb[i];
    }
    delete[] comb;
    delete[] weights;
    delete[] suffixMin;
    return base;
}

void assert_eq(int *expected, int *actual, int n) {
    if(expected == nullptr || actual == nullptr) {
        if(expected == nullptr && actual == nullptr) {
            cout << "Passed\n";
        }else {
            if(expected == nullptr) {
                cout << "Failed: expected nullptr but got ";
                for(int j = 1; j <= n; j++) {
                    cout << actual[j] << " ";
                }
            }
            if(actual == nullptr) {
                cout << "Failed: expected ";
                for(int j = 1; j <= n; j++) {
                    cout << expected[j] << " ";
                }
                cout << " but got nullptr";
            }
        }
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(expected[i] != actual[i]) {
            cout << "Failed: expected ";
            for(int j = 1; j <= n; j++) {
                cout << expected[j] << " ";
            }
            cout << " but got ";
            for(int j = 1; j <= n; j++) {
                cout << actual[j] << " ";
            }
            return;
        }
    }

    cout << "Passed\n";
}

void testare() {
    int n = 2;
    int s = 8;
    int L = 1, R = 4;
    int *rez = rezolvare(n, s, L, R);
    int *expected = nullptr;
    assert_eq(expected, rez, n);
}
#endif //INC_6_4_STEFAN_H
