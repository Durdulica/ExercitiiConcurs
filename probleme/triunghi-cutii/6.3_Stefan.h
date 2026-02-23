#ifndef INC_6_3_STEFAN_H
#define INC_6_3_STEFAN_H
#include <iostream>
using namespace std;

//se dau n, s si m. Det. cate baze de n elem. strict pozitive genereaza un triunghi valid cu suma totala exact s. Raspunsul
//se da modulo m.

bool dfsBase(int idx, int n, int remaining, int *weights, int *suffixMin, int *base, int &cnt) {
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
        if(dfsBase(idx + 1, n, remaining - v * w, weights, suffixMin, base,cnt)) {
            cnt++;
        }
    }
    if(cnt > 0) {
        return true;
    }
    return false;
}

int rezolvare(int n, int s, int m) {
    // if(!(cin >> n >> s >> m)) {
        // cout << "Error on reading\n";
        // return;
    // }

    if(n <= 0) {
        cout << 0 << endl;
        return -1;
    }

    int **comb = new int *[n + 1];
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
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    int *weights = new int[n + 1];
    for(int i = 0; i < n + 1; i++) {
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
    for(int i = 0; i < n + 2; i++) {
        suffixMin[i] = 0;
    }

    for(int i = n; i >= 1; i--) {
        suffixMin[i] = suffixMin[i + 1] + weights[i];
    }

    if(s < suffixMin[1]) {
        cout << 0 << "\n";
        for(int i = 0; i <= n; i++) {
            delete[] comb[i];
        }
        delete[] comb;
        delete[] weights;
        delete[] suffixMin;
        return -1;
    }

    int *base = new int[n + 1];
    for(int i = 0; i < n + 1; i++) {
        base[i] = 0;
    }
    int cnt = 0;
    dfsBase(1, n,s, weights, suffixMin,base, cnt);
    for(int i = 0; i <= n; i++) {
        delete[] comb[i];
    }
    delete[] comb;
    delete[] weights;
    delete[] suffixMin;
    delete[] base;
    return cnt/2 % m;
}


void assert_eq(int expected, int actual) {
    if(expected != actual) {
        cout << "Failed: expected " << expected << " but got " << actual<< endl;
    }else {
        cout << "Passed" << endl;
    }
}

void testare() {
    int n = 2;
    int s = 8;
    int m = 10000007;
    int rez = rezolvare(n, s, m);
    int expected = 3 % m;
    assert_eq(expected, rez);
}
#endif //INC_6_3_STEFAN_H