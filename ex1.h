#ifndef EX1_H
#define EX1_H
#include <iostream>
#include <cstring>
using namespace std;

//zaharel incearca s-o invete pe Eugenia informatica. Astazi a invatat-o programare dinamica si a nume a inceput cu problema celui mai lung
//subsir comun:dandu-se doua siruri, formate doare din litere mici, sa se det. cel mai lung subsir comun al celor doua siruri. Un subsir al
//unui sir este format din caractere ale sirului respectiv, in ordinea in care acestea apar in sir. Eugenia a inteles  rezolvarea problemei
//dar i-a pus urmatoarea inttrebare lui zaharel: cate subsiruri comune de lungime max. distincte exista pt. cele 2 siruri? Doua subsiruri
//sunt distincte daca exista c. p. un caracter in unul din ele care difera de caracterul din celalalt subsir de pe aceeasi pozitie. Ajutatil
//pe zaharel si det. restul impartirii nr. de subsiruri comune de lungime maxima distincte pt. doua siruri data, la nr. 666013

char a[501], b[501];
int n, m, smax = -1, rez = 0;

void citire() {
    cin.getline(a, 500);
    cin.getline(b, 500);
    n = (int)strlen(a);
    m = (int)strlen(b);
}

void subsir(int max, int indi, int indj) {
    for (int i = 0; i < n; i++) {
        max = 0;
        for(int j = 0; j <= m; j++) {
            if(a[i] == b[j]) {
                max++;
                i++;
            }
        }
        if(max > smax) {
            smax = max;
            max = 0;
            rez = 1;
        }else if(max == smax) {
            rez++;
        }
    }
}

void solve() {
    citire();
    subsir(0,0,0);
    cout << rez % 666013 << endl;
}


///ex 1 optim

const int MOD = 666013;

inline void readWord(char *&buffer, int &length) {
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

    while ((ch = cin.get()) != EOF) {
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

void rezolvare() {
    char *first = nullptr;
    char *second = nullptr;
    int n = 0, m = 0;
    readWord(first, n);
    readWord(second, m);

    if (!first || !second) {
        std::cout << 0;
        delete[] first;
        delete[] second;
        return;
    }

    // len[i][j] = lungimea LCS pentru sufixele a[i..], b[j..]
    const int cols = m + 1;
    const int rows = n + 1;
    const int total = rows * cols;
    int *len = new int[total];
    int *cnt = new int[total];  // cnt[i][j] = numarul de LCS distincte pentru aceleasi sufixe

    for (int i = 0; i < total; ++i) {
        len[i] = 0;
        cnt[i] = 0;
    }

    // Baza: daca unul dintre sufixe e gol, exista doar sirul vid => un singur LCS
    for (int i = 0; i <= n; ++i) {
        cnt[i * cols + m] = 1;
    }
    for (int j = 0; j <= m; ++j) {
        cnt[n * cols + j] = 1;
    }

    // Parcurgem invers, astfel incat dependentele (dreapta, jos, diagonala) sunt deja evaluate
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int idx = i * cols + j;
            int idxDown = (i + 1) * cols + j;
            int idxRight = i * cols + (j + 1);
            int idxDiag = (i + 1) * cols + (j + 1);

            if (first[i] == second[j]) {
                // Caractere egale: crestem cu 1 lungimea diagonalei si mostenim numarul de solutii
                len[idx] = len[idxDiag] + 1;
                cnt[idx] = cnt[idxDiag];
            } else {
                int l1 = len[idxDown];
                int l2 = len[idxRight];
                int best = (l1 > l2) ? l1 : l2;
                len[idx] = best;

                long long ways = 0;
                if (l1 == best) {
                    // Folosim varianta "jos" daca pastreaza lungimea maxima
                    ways += cnt[idxDown];
                }
                if (l2 == best) {
                    // Folosim varianta "dreapta" daca pastreaza lungimea maxima
                    ways += cnt[idxRight];
                }
                if (l1 == best && l2 == best && len[idxDiag] == best) {
                    // Diagonala ar fi numarata de doua ori, o scadem (inclusion-exclusion)
                    ways -= cnt[idxDiag];
                }
                ways %= MOD;
                if (ways < 0) ways += MOD;
                cnt[idx] = static_cast<int>(ways);
            }
        }
    }

    std::cout << (cnt[0] % MOD);

    delete[] len;
    delete[] cnt;
    delete[] first;
    delete[] second;
}
#endif //EX1_H
