#ifndef COZI_MONOTONE_SLIDING_MIN_H
#define COZI_MONOTONE_SLIDING_MIN_H
#include <cassert>
#include <iostream>

namespace cozi_monotone {

// Problema: Dat sirul v[1..n] si o fereastra de lungime k, sa se afiseze
// minimul fiecarei ferestre consecutive. Constrangeri moderate, O(n) dorit.
// Rezolvare: coada monotona (sliding window minimum).

const int MAXN = 200000;
int v[MAXN + 5];
int poz[MAXN + 5];
int val[MAXN + 5];
int head_q, tail_q;

void adauga(int index, int valoare, int k) {
    while (head_q < tail_q && val[tail_q - 1] >= valoare) {
        --tail_q;
    }
    poz[tail_q] = index;
    val[tail_q] = valoare;
    ++tail_q;

    while (head_q < tail_q && poz[head_q] <= index - k) {
        ++head_q;
    }
}

// Returneaza minimul curent (front-ul cozii). Presupune coada nevida.
inline int minim_curent() {
    return val[head_q];
}

void rezolva_citire(std::istream& in, std::ostream& out) {
    int n, k;
    in >> n >> k;
    for (int i = 1; i <= n; ++i) {
        in >> v[i];
    }

    head_q = tail_q = 0;
    for (int i = 1; i <= n; ++i) {
        adauga(i, v[i], k);
        if (i >= k) {
            out << minim_curent();
            if (i < n) out << ' ';
        }
    }
    out << '\n';
}

void testare() {
    {
        int arr[] = {0, 2, 1, 3, -1, 4}; // 1-based helper
        int n = 5, k = 3;
        head_q = tail_q = 0;
        for (int i = 1; i <= n; ++i) adauga(i, arr[i], k);
        assert(minim_curent() == -1);
    }
    {
        // n=5, k=2, sir: 4 3 5 1 2 => minime: 3 3 1 1
        int n = 5, k = 2;
        int sir[] = {0,4,3,5,1,2};
        head_q = tail_q = 0;
        for (int i = 1; i <= n; ++i) {
       adauga(i, sir[i], k);
            if (i >= k) {
                int expected;
                if (i == 2) expected = 3;
                else if (i == 3) expected = 3;
                else if (i == 4) expected = 1;
                else expected = 1;
                assert(minim_curent() == expected);
            }
        }
    }
    std::cout << "Sliding window min: PASS\n";
}

} // namespace cozi_monotone

#endif // COZI_MONOTONE_SLIDING_MIN_H
