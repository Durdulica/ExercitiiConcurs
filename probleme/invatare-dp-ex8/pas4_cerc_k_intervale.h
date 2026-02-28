#ifndef PAS4_CERC_K_INTERVALE_H
#define PAS4_CERC_K_INTERVALE_H

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

namespace invatare_dp_ex8_pas4 {

// Enunt:
// Avem N numere pe cerc (N este adiacent cu 1).
// Alege exact K intervale continue, nevide, pe cerc, astfel incat suma totala sa fie maxima.
//
// Input:
// N K
// v1 v2 ... vN
//
// Output:
// suma maxima sau "impossible" daca nu exista configuratie valida

const long long NEGATIV_INF = LLONG_MIN / 4;

inline long long maximPas4(long long a, long long b) {
    return (a > b ? a : b);
}

void rezolvare() {
    int numarElemente = 0;
    int numarIntervaleDorite = 0;
    cin >> numarElemente >> numarIntervaleDorite;

    assert(numarElemente >= 1 && numarElemente <= 10000);
    assert(numarIntervaleDorite >= 1 && numarIntervaleDorite <= 1000);

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

    long long sumaMaxima = NEGATIV_INF;

    // Cazul A: elementul 1 nu este ales
    // Cazul B: elementul 1 este ales
    for (int primulElementEsteAles = 0; primulElementEsteAles <= 1; ++primulElementEsteAles) {
        for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
            dpAnteriorUltim0[intervale] = NEGATIV_INF;
            dpAnteriorUltim1[intervale] = NEGATIV_INF;
        }

        if (primulElementEsteAles == 0) {
            dpAnteriorUltim0[0] = 0;
        } else {
            dpAnteriorUltim1[0] = valori[1];
        }

        for (int index = 2; index <= numarElemente; ++index) {
            for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
                dpCurentUltim0[intervale] = NEGATIV_INF;
                dpCurentUltim1[intervale] = NEGATIV_INF;
            }

            for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
                long long stareUltim0 = dpAnteriorUltim0[intervale];
                long long stareUltim1 = dpAnteriorUltim1[intervale];

                if (stareUltim0 != NEGATIV_INF) {
                    // Nu aleg elementul curent.
                    dpCurentUltim0[intervale] = maximPas4(dpCurentUltim0[intervale], stareUltim0);

                    // Aleg elementul curent si incep interval nou (0 -> 1).
                    if (intervale + 1 <= numarIntervaleDorite) {
                        dpCurentUltim1[intervale + 1] =
                            maximPas4(dpCurentUltim1[intervale + 1], stareUltim0 + valori[index]);
                    }
                }

                if (stareUltim1 != NEGATIV_INF) {
                    // Nu aleg elementul curent.
                    dpCurentUltim0[intervale] = maximPas4(dpCurentUltim0[intervale], stareUltim1);

                    // Aleg elementul curent si continui intervalul curent.
                    dpCurentUltim1[intervale] = maximPas4(dpCurentUltim1[intervale], stareUltim1 + valori[index]);

                    // Aleg elementul curent dar "tai" intre (index-1, index), deci pornesc interval nou.
                    if (intervale + 1 <= numarIntervaleDorite) {
                        dpCurentUltim1[intervale + 1] =
                            maximPas4(dpCurentUltim1[intervale + 1], stareUltim1 + valori[index]);
                    }
                }
            }

            for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
                dpAnteriorUltim0[intervale] = dpCurentUltim0[intervale];
                dpAnteriorUltim1[intervale] = dpCurentUltim1[intervale];
            }
        }

        // Inchid cercul pe muchia (N, 1):
        for (int intervale = 0; intervale <= numarIntervaleDorite; ++intervale) {
            long long stareUltim0 = dpAnteriorUltim0[intervale];
            long long stareUltim1 = dpAnteriorUltim1[intervale];

            if (stareUltim0 != NEGATIV_INF) {
                int intervaleTotale = intervale;
                if (primulElementEsteAles == 1) {
                    intervaleTotale += 1; // 0 -> 1 pe muchia (N,1)
                }
                if (intervaleTotale == numarIntervaleDorite) {
                    sumaMaxima = maximPas4(sumaMaxima, stareUltim0);
                }
            }

            if (stareUltim1 != NEGATIV_INF) {
                if (primulElementEsteAles == 0) {
                    if (intervale == numarIntervaleDorite) {
                        sumaMaxima = maximPas4(sumaMaxima, stareUltim1);
                    }
                } else {
                    // xN=1, x1=1: pot fie sa continui, fie sa tai pe muchia (N,1).
                    if (intervale == numarIntervaleDorite) {
                        sumaMaxima = maximPas4(sumaMaxima, stareUltim1);
                    }
                    if (intervale + 1 == numarIntervaleDorite) {
                        sumaMaxima = maximPas4(sumaMaxima, stareUltim1);
                    }
                }
            }
        }
    }

    if (sumaMaxima == NEGATIV_INF) {
        cout << "impossible\n";
    } else {
        cout << sumaMaxima << "\n";
    }

    delete[] dpAnteriorUltim0;
    delete[] dpAnteriorUltim1;
    delete[] dpCurentUltim0;
    delete[] dpCurentUltim1;
    delete[] valori;
}

} // namespace invatare_dp_ex8_pas4

#endif // PAS4_CERC_K_INTERVALE_H
