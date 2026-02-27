// Implementare de quick sort fara STL, cu tablouri simple si indici intregi.
// Explicatii si nume de variabile prietenoase pentru incepatori.
#ifndef PROBLEME_QUICKSORT_QUICKSORT_H
#define PROBLEME_QUICKSORT_QUICKSORT_H

#include <iostream>
#include <cassert>

namespace quicksort {

// Schimba valorile a doua variabile intregi.
inline void interschimba(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Quick sort in-place pe subintervalul v[stanga..dreapta].
// Foloseste schema clasica Hoare cu pivotul ales la mijloc.
void quick_sort(int v[], int stanga, int dreapta) {
    int i = stanga;
    int j = dreapta;
    int pivot = v[(stanga + dreapta) / 2];

    // Mutam elementele mai mici la stanga pivotului si pe cele mai mari la dreapta.
    while (i <= j) {
        while (v[i] < pivot) ++i;
        while (v[j] > pivot) --j;
        if (i <= j) {
            interschimba(v[i], v[j]);
            ++i;
            --j;
        }
    }

    // Sortam recursiv cele doua parti rezultate.
    if (stanga < j) quick_sort(v, stanga, j);
    if (i < dreapta) quick_sort(v, i, dreapta);
}

// Verifica daca vectorul este sortat crescator.
bool este_sortat(const int v[], int n) {
    for (int idx = 1; idx < n; ++idx) {
        if (v[idx - 1] > v[idx]) return false;
    }
    return true;
}

// Exemplu simplu: sorteaza un vector, verifica rezultatul si il afiseaza.
void testare() {
    int v[] = {9, 3, 7, 1, 6, 2, 8, 5, 4};
    const int n = (int)(sizeof(v) / sizeof(v[0]));

    quick_sort(v, 0, n - 1);
    assert(este_sortat(v, n)); // arunca in debug daca algoritmul a esuat

    std::cout << "Quick sort (fara STL): ";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << (i + 1 == n ? '\n' : ' ');
    }
}

} // namespace quicksort

#endif // PROBLEME_QUICKSORT_QUICKSORT_H
