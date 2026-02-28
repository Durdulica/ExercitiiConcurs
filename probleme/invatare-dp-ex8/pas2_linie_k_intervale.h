#ifndef PAS2_LINIE_K_INTERVALE_H
#define PAS2_LINIE_K_INTERVALE_H

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

namespace invatare_dp_ex8_pas2 {

// Enunt:
// Avem N numere intregi pe o linie.
// Alege exact K intervale continue, nevide, fara suprapunere, astfel incat suma totala sa fie maxima.
//
// Input:
// N K
// v1 v2 ... vN
//
// Output:
// suma maxima pentru exact K intervale
// sau "impossible" daca K > N

const long long NEGATIV_INF = LLONG_MIN / 4;

inline long long maximPas2(long long a, long long b) {
    return (a > b ? a : b);
}

void rezolvare() {
    int numarElemente = 0;
    int numarIntervaleDorite = 0;
    cin >> numarElemente >> numarIntervaleDorite;

    assert(numarElemente >= 1 && numarElemente <= 100000);
    assert(numarIntervaleDorite >= 0 && numarIntervaleDorite <= 2000);

    long long *valori = new long long[numarElemente + 1];
    assert(valori != nullptr);

    for (int index = 1; index <= numarElemente; ++index) {
        cin >> valori[index];
    }

    if (numarIntervaleDorite > numarElemente) {
        cout << "impossible\n";
        delete[] valori;
        return;
    }

    long long *dpAnteriorUltim0 = new long long[numarIntervaleDorite + 1];
    long long *dpAnteriorUltim1 = new long long[numarIntervaleDorite + 1];
    long long *dpCurentUltim0 = new long long[numarIntervaleDorite + 1];
    long long *dpCurentUltim1 = new long long[numarIntervaleDorite + 1];
    assert(dpAnteriorUltim0 != nullptr);
    assert(dpAnteriorUltim1 != nullptr);
    assert(dpCurentUltim0 != nullptr);
    assert(dpCurentUltim1 != nullptr);

    for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
        dpAnteriorUltim0[intervale] = NEGATIV_INF;
        dpAnteriorUltim1[intervale] = NEGATIV_INF;
    }
    dpAnteriorUltim0[0] = 0;

    for (int index = 1; index <= numarElemente; ++index) {
        for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
            dpCurentUltim0[intervale] = NEGATIV_INF;
            dpCurentUltim1[intervale] = NEGATIV_INF;
        }

        for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
            long long stareUltim0 = dpAnteriorUltim0[intervale];
            long long stareUltim1 = dpAnteriorUltim1[intervale];

            if (stareUltim0 != NEGATIV_INF || stareUltim1 != NEGATIV_INF) {
                dpCurentUltim0[intervale] = maximPas2(stareUltim0, stareUltim1);
            }

            if (intervale >= 1) {
                long long bazaPornire = maximPas2(dpAnteriorUltim0[intervale - 1], dpAnteriorUltim1[intervale - 1]);
                if (bazaPornire != NEGATIV_INF) {
                    dpCurentUltim1[intervale] = maximPas2(dpCurentUltim1[intervale], bazaPornire + valori[index]);
                }
            }

            if (stareUltim1 != NEGATIV_INF) {
                dpCurentUltim1[intervale] = maximPas2(dpCurentUltim1[intervale], stareUltim1 + valori[index]);
            }
        }

        for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
            dpAnteriorUltim0[intervale] = dpCurentUltim0[intervale];
            dpAnteriorUltim1[intervale] = dpCurentUltim1[intervale];
        }
    }

    long long raspuns = maximPas2(dpAnteriorUltim0[numarIntervaleDorite], dpAnteriorUltim1[numarIntervaleDorite]);
    if (raspuns == NEGATIV_INF) {
        cout << "impossible\n";
    } else {
        cout << raspuns << "\n";
    }

    delete[] dpAnteriorUltim0;
    delete[] dpAnteriorUltim1;
    delete[] dpCurentUltim0;
    delete[] dpCurentUltim1;
    delete[] valori;
}

} // namespace invatare_dp_ex8_pas2

#endif // PAS2_LINIE_K_INTERVALE_H
