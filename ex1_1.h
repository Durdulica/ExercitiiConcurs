#ifndef EX1_1_H
#define EX1_1_H

#include <iostream>

// Problema 1 : Numarul de LCS distincte pentru doua siruri.
// Metoda: programare dinamica pe sufixe (bottom-up).
// - len[i][j] = lungimea LCS dintre sufixele A[i..] si B[j..]
// - cnt[i][j] = numarul de LCS distincte pentru aceleasi sufixe
// Daca A[i] == B[j], mostenim diagonala si crestem lungimea cu 1.
// Altfel, combinam directiile care pastreaza lungimea maxima si eliminam
// dubla numarare prin inclusion-exclusion.
// Raspunsul este cnt[0][0] modulo 666013.

const int MOD_EX1_1 = 666013;

inline void readWordEx1_1(char *&buffer, int &length) {
    length = 0;
    int capacity = 16;
    buffer = new char[capacity];
    int ch;
    bool started = false;

    while ((ch = std::cin.get()) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            started = true;
            buffer[length++] = static_cast<char>(ch);
            break;
        }
    }

    if (!started) {
        delete[] buffer;
        buffer = nullptr;
        length = 0;
        return;
    }

    while ((ch = std::cin.get()) != EOF) {
        if (ch < 'a' || ch > 'z') {
            break;
        }
        if (length + 1 >= capacity) {
            capacity <<= 1;
            char *temp = new char[capacity];
            for (int i = 0; i < length; ++i) {
                temp[i] = buffer[i];
            }
            delete[] buffer;
            buffer = temp;
        }
        buffer[length++] = static_cast<char>(ch);
    }
    buffer[length] = '\0';
}

inline void rezolvare_ex1_1() {
    char *first = nullptr;
    char *second = nullptr;
    int n = 0, m = 0;
    readWordEx1_1(first, n);
    readWordEx1_1(second, m);

    if (!first || !second) {
        std::cout << 0;
        delete[] first;
        delete[] second;
        return;
    }

    const int cols = m + 1;
    const int rows = n + 1;
    const int total = rows * cols;
    int *len = new int[total];
    int *cnt = new int[total];

    for (int i = 0; i < total; ++i) {
        len[i] = 0;
        cnt[i] = 0;
    }

    // Baza: daca unul dintre sufixe e gol, LCS-ul este sirul vid.
    for (int i = 0; i <= n; ++i) {
        cnt[i * cols + m] = 1;
    }
    for (int j = 0; j <= m; ++j) {
        cnt[n * cols + j] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int idx = i * cols + j;
            int idxDown = (i + 1) * cols + j;
            int idxRight = i * cols + (j + 1);
            int idxDiag = (i + 1) * cols + (j + 1);

            if (first[i] == second[j]) {
                len[idx] = len[idxDiag] + 1;
                cnt[idx] = cnt[idxDiag];
            } else {
                int l1 = len[idxDown];
                int l2 = len[idxRight];
                int best = (l1 > l2) ? l1 : l2;
                len[idx] = best;

                long long ways = 0;
                if (l1 == best) {
                    ways += cnt[idxDown];
                }
                if (l2 == best) {
                    ways += cnt[idxRight];
                }
                if (l1 == best && l2 == best && len[idxDiag] == best) {
                    ways -= cnt[idxDiag];
                }
                ways %= MOD_EX1_1;
                if (ways < 0) {
                    ways += MOD_EX1_1;
                }
                cnt[idx] = static_cast<int>(ways);
            }
        }
    }

    std::cout << (cnt[0] % MOD_EX1_1);

    delete[] len;
    delete[] cnt;
    delete[] first;
    delete[] second;
}

#endif // EX1_1_H
=======
>>>>>>> 2c7959f34e656f246c4a863024b930a4bd955a8b
