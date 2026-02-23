#ifndef EX6_H
#define EX6_H
#include <iostream>
using namespace std;

static bool dfsBase(int idx,
                    int n,
                    long long remaining,
                    const long long *weights,
                    const long long *suffixMin,
                    long long *base) {
    if (idx > n) {
        return remaining == 0;
    }
    if (remaining < suffixMin[idx]) {
        return false;
    }

    long long minAfter = suffixMin[idx + 1];
    long long w = weights[idx];
    long long maxVal = (remaining - minAfter) / w;
    if (maxVal < 1) {
        return false;
    }

    for (long long v = 1; v <= maxVal; ++v) {
        base[idx] = v;
        if (dfsBase(idx + 1, n, remaining - v * w, weights, suffixMin, base)) {
            return true;
        }
    }
    return false;
}

void rezolvare() {
    int n = 0;
    long long s = 0;
    if (!(cin >> n >> s)) {
        return;
    }

    if (n <= 0) {
        cout << "impossible";
        return;
    }

    // Diferenta fata de ex6_Stefan: folosim combinari corecte (Pascal) pentru a calcula contributia reala a bazei.
    long long **comb = new long long *[n + 1];
    for (int i = 0; i <= n; ++i) {
        comb[i] = new long long[n + 1];
        for (int j = 0; j <= n; ++j) {
            comb[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; ++i) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    // Diferenta fata de ex6_Stefan: weights[k] este contributia reala a bazei (nu C(n, k) gresit).
    long long *weights = new long long[n + 1];
    for (int i = 0; i <= n; ++i) {
        weights[i] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        long long w = 0;
        for (int r = 1; r <= n; ++r) {
            int depth = n - r;
            int tStart = k - r;
            int tEnd = k - 1;
            for (int t = tStart; t <= tEnd; ++t) {
                if (t >= 0 && t <= depth) {
                    w += comb[depth][t];
                }
            }
        }
        weights[k] = w;
    }

    // Diferenta fata de ex6_Stefan: suma minima ramasa se bazeaza pe weights corecte.
    long long *suffixMin = new long long[n + 2];
    for (int i = 0; i <= n + 1; ++i) {
        suffixMin[i] = 0;
    }
    for (int i = n; i >= 1; --i) {
        suffixMin[i] = suffixMin[i + 1] + weights[i];
    }

    // Diferenta fata de ex6_Stefan: conditie corecta pentru imposibilitate (minimul real al sumei).
    if (s < suffixMin[1]) {
        cout << "impossible";
        for (int i = 0; i <= n; ++i) {
            delete[] comb[i];
        }
        delete[] comb;
        delete[] weights;
        delete[] suffixMin;
        return;
    }

    long long *base = new long long[n + 1];
    for (int i = 0; i <= n; ++i) {
        base[i] = 0;
    }
    // Diferenta fata de ex6_Stefan: backtracking cu pruning pe baza contributiilor corecte.
    if (!dfsBase(1, n, s, weights, suffixMin, base)) {
        cout << "impossible";
        for (int i = 0; i <= n; ++i) {
            delete[] comb[i];
        }
        delete[] comb;
        delete[] weights;
        delete[] suffixMin;
        delete[] base;
        return;
    }

    // Diferenta fata de ex6_Stefan: reconstruim triunghiul doar dupa ce baza este validata cu suma corecta.
    long long **tri = new long long *[n + 1];
    for (int i = 0; i <= n; ++i) {
        tri[i] = new long long[n + 1];
        for (int j = 0; j <= n; ++j) {
            tri[i][j] = 0;
        }
    }
    // Diferenta fata de ex6_Stefan: afisam strict elementele valide pe fiecare rand (1..i).
    for (int i = 1; i <= n; ++i) {
        tri[n][i] = base[i];
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            tri[i][j] = tri[i + 1][j] + tri[i + 1][j + 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << tri[i][j] << (j == i ? '\n' : ' ');
        }
    }

    for (int i = 0; i <= n; ++i) {
        delete[] comb[i];
        delete[] tri[i];
    }
    delete[] comb;
    delete[] tri;
    delete[] weights;
    delete[] suffixMin;
    delete[] base;
}
#endif //EX6_H