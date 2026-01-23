#ifndef EX1_H
#define EX1_H
#include <iostream>
#include <cassert>
#include <cstring>

using  namespace std;

// Zaharel incearca s-o invete pe Eugenia informatica. Astazi a invatat-o
// programare dinamica si a inceput cu problema celui mai lung subsir comun:
// dandu-se doua siruri, formate doar din litere mici, sa se determine cel mai
// lung subsir comun al celor doua siruri. Un subsir al unui sir este format
// din caractere ale sirului respectiv, in ordinea in care acestea apar in sir.
// Eugenia a inteles rezolvarea problemei dar i-a pus urmatoarea intrebare lui
// Zaharel: cate subsiruri comune de lungime maxima distincte exista pentru
// cele 2 siruri? Doua subsiruri sunt distincte daca exista cel putin un
// caracter in unul din ele care difera de caracterul din celalalt subsir de
// pe aceeasi pozitie. Ajutati-l pe Zaharel si determinati restul impartirii
// numarului de subsiruri comune de lungime maxima distincte pentru doua siruri
// date, la numarul 666013.

const int MOD = 666013;

 void assert_eq(int actual, int expected, const char* label) {
    if (actual != expected) {
        cerr << "FAIL " << label << ": expected " << expected
                  << ", got " << actual << '\n';
        abort();
    }
}



int rezolvare(const char* a, const char* b) {
    int n = strlen(a);
    int m = strlen(b);

    int c = m + 1;
    int r = n + 1;
    int tot = r * c;

    int* len = new int[tot];
    int* cnt = new int[tot];

    for (int i = 0; i < tot; ++i) {
        len[i] = 0;
        cnt[i] = 0;
    }

    for (int i = 0; i <= n; ++i)
        cnt[i * c + m] = 1;

    for (int j = 0; j <= m; ++j)
        cnt[n * c + j] = 1;
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {

            int poz  = i * c + j;
            int jos  = (i + 1) * c + j;
            int dr   = i * c + (j + 1);
            int diag = (i + 1) * c + (j + 1);

            if (a[i] == b[j]) {
                len[poz] = len[diag] + 1;
                cnt[poz] = cnt[diag];
            } 
            else {
                int l1 = len[jos];
                int l2 = len[dr];
                int best = max(l1, l2);
                len[poz] = best;

                long long ways = 0;
                if (l1 == best) ways += cnt[jos];
                if (l2 == best) ways += cnt[dr];

                if (l1 == best && l2 == best && len[diag] == best)
                    ways -= cnt[diag];

                ways %= MOD;
                if (ways < 0) ways += MOD;

                cnt[poz] = (int)ways;
            }
        }
    }

    int rez = cnt[0] % MOD;

    delete[] len;
    delete[] cnt;
    return rez;
}



void testare() {
     assert_eq(rezolvare("abcd","acbd"), 2, "abcd/acbd"); // "abd", "acd"
     assert_eq(rezolvare("abc","abc"), 1, "abc/abc");
     assert_eq(rezolvare("abc","def"), 1, "abc/def"); // doar sirul vid
     assert_eq(rezolvare("aaaa","aa"), 1, "aaaa/aa"); // "aa"
     assert_eq(rezolvare("ab","ba"), 2, "ab/ba"); // "a", "b"
     cout << "PASS\n";
 }


#endif //EX1_H
