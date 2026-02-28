#ifndef EX8_H
#define EX8_H
#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

//zaharel sa dus in vizita la bunici impreuna cu eugenia. Ferma bunicilor este de forma circulara, iar acolo cresc N<=10000 gaini.
//Ferma a fost impartita in N sectoare, numerotate de la 1 la N, a. i. oricare doua sectoare avand numere consecutive sunt adiacente.
//In plus, primul si ultimul sector sunt adiacente. In fiecare sector se afla cate o gaina, iar aceasta depune oua in fiecare zi.
//Bunicii stiu pt. fiecare gaina care este productivitatea ei, adica un nr. care repr. diferenta dintre consumul gainii si cat
//produce. Zaharel si cu Eugenia strang de K<=1000 ori pe zi oua de la gaini astfel: la fiecare strangere cei doi aleg o secventa
//(un sir de sectoare adiacente) formata din cel putin un sector, care contine numai gaini de la care nu s-au luat oua in acea zi.
//Cunoscand productivitatea fiecarei gaini si nr. de strangeri dintr-o zi, ajutati-i pe Zaharel si Eugenia sa stranga oua a. i. suma
//productivitatilor gainilor de la care au strans oua sa fie maxima.

const long long NEGATIV_INF_EX8 = LLONG_MIN / 4;
int numarSectoareEx8, numarStrangeriEx8;

inline long long maximEx8(long long valoareA, long long valoareB) {
    return (valoareA > valoareB ? valoareA : valoareB);
}

static bool citireEx8(long long *&productivitate) {
    if (!(cin >> numarSectoareEx8 >> numarStrangeriEx8)) {
        return false;
    }

    if (numarSectoareEx8 < 1 || numarSectoareEx8 > 10000 ||
        numarStrangeriEx8 < 1 || numarStrangeriEx8 > 1000) {
        return false;
    }

    // Pentru exact K strangeri, fiecare strangere are minim un sector.
    if (numarStrangeriEx8 > numarSectoareEx8) {
        return false;
    }

    productivitate = new long long[numarSectoareEx8 + 1];
    for (int indexSector = 1; indexSector <= numarSectoareEx8; ++indexSector) {
        if (!(cin >> productivitate[indexSector])) {
            delete[] productivitate;
            productivitate = nullptr;
            return false;
        }
    }
    return true;
}

void rezolvare() {
    long long *productivitate = nullptr;
    if (!citireEx8(productivitate)) {
        cout << "impossible\n";
        return;
    }
    assert(productivitate != nullptr);
    assert(numarSectoareEx8 >= 1 && numarSectoareEx8 <= 10000);
    assert(numarStrangeriEx8 >= 1 && numarStrangeriEx8 <= 1000);
    assert(numarStrangeriEx8 <= numarSectoareEx8);

    long long *dpAnteriorUltim0 = new long long[numarStrangeriEx8 + 1];
    long long *dpAnteriorUltim1 = new long long[numarStrangeriEx8 + 1];
    long long *dpCurentUltim0 = new long long[numarStrangeriEx8 + 1];
    long long *dpCurentUltim1 = new long long[numarStrangeriEx8 + 1];
    assert(dpAnteriorUltim0 != nullptr);
    assert(dpAnteriorUltim1 != nullptr);
    assert(dpCurentUltim0 != nullptr);
    assert(dpCurentUltim1 != nullptr);

    long long sumaMaxima = NEGATIV_INF_EX8;

    // Incercam separat cele doua variante pentru sectorul 1: neales / ales.
    for (int sector1Ales = 0; sector1Ales <= 1; ++sector1Ales) {
        for (int numarIntervale = 0; numarIntervale <= numarStrangeriEx8; ++numarIntervale) {
            dpAnteriorUltim0[numarIntervale] = NEGATIV_INF_EX8;
            dpAnteriorUltim1[numarIntervale] = NEGATIV_INF_EX8;
        }

        if (sector1Ales == 0) {
            dpAnteriorUltim0[0] = 0;
        } else {
            dpAnteriorUltim1[0] = productivitate[1];
        }

        for (int indexSector = 2; indexSector <= numarSectoareEx8; ++indexSector) {
            for (int numarIntervale = 0; numarIntervale <= numarStrangeriEx8; ++numarIntervale) {
                dpCurentUltim0[numarIntervale] = NEGATIV_INF_EX8;
                dpCurentUltim1[numarIntervale] = NEGATIV_INF_EX8;
            }

            for (int intervaleFolosite = 0; intervaleFolosite <= numarStrangeriEx8; ++intervaleFolosite) {
                long long valoareCuUltim0 = dpAnteriorUltim0[intervaleFolosite];
                long long valoareCuUltim1 = dpAnteriorUltim1[intervaleFolosite];

                if (valoareCuUltim0 != NEGATIV_INF_EX8) {
                    // Nu alegem sectorul curent.
                    dpCurentUltim0[intervaleFolosite] =
                            maximEx8(dpCurentUltim0[intervaleFolosite], valoareCuUltim0);

                    // Alegem sectorul curent: trebuie sa inceapa un interval nou (0 -> 1).
                    if (intervaleFolosite + 1 <= numarStrangeriEx8) {
                        dpCurentUltim1[intervaleFolosite + 1] =
                                maximEx8(dpCurentUltim1[intervaleFolosite + 1],
                                         valoareCuUltim0 + productivitate[indexSector]);
                    }
                }

                if (valoareCuUltim1 != NEGATIV_INF_EX8) {
                    // Nu alegem sectorul curent.
                    dpCurentUltim0[intervaleFolosite] =
                            maximEx8(dpCurentUltim0[intervaleFolosite], valoareCuUltim1);

                    // Alegem sectorul curent si continuam acelasi interval.
                    dpCurentUltim1[intervaleFolosite] =
                            maximEx8(dpCurentUltim1[intervaleFolosite],
                                     valoareCuUltim1 + productivitate[indexSector]);

                    // Alegem sectorul curent, dar "taiem" intre sectoare adiacente:
                    // astfel putem incepe inca un interval chiar daca sectorul anterior e ales.
                    if (intervaleFolosite + 1 <= numarStrangeriEx8) {
                        dpCurentUltim1[intervaleFolosite + 1] =
                                maximEx8(dpCurentUltim1[intervaleFolosite + 1],
                                         valoareCuUltim1 + productivitate[indexSector]);
                    }
                }
            }

            for (int numarIntervale = 0; numarIntervale <= numarStrangeriEx8; ++numarIntervale) {
                dpAnteriorUltim0[numarIntervale] = dpCurentUltim0[numarIntervale];
                dpAnteriorUltim1[numarIntervale] = dpCurentUltim1[numarIntervale];
            }
        }

        // Inchidem cercul pe muchia dintre sectorul N si sectorul 1.
        for (int intervaleFolosite = 0; intervaleFolosite <= numarStrangeriEx8; ++intervaleFolosite) {
            long long valoareCuUltim0 = dpAnteriorUltim0[intervaleFolosite];
            long long valoareCuUltim1 = dpAnteriorUltim1[intervaleFolosite];

            if (valoareCuUltim0 != NEGATIV_INF_EX8) {
                int intervaleTotale = intervaleFolosite;
                if (sector1Ales == 1) {
                    intervaleTotale += 1; // 0 -> 1 la trecerea de la N la 1
                }
                if (intervaleTotale == numarStrangeriEx8) {
                    sumaMaxima = maximEx8(sumaMaxima, valoareCuUltim0);
                }
            }

            if (valoareCuUltim1 != NEGATIV_INF_EX8) {
                if (sector1Ales == 0) {
                    // x1 = 0 => pe muchia (N,1) nu poate incepe interval nou.
                    if (intervaleFolosite == numarStrangeriEx8) {
                        sumaMaxima = maximEx8(sumaMaxima, valoareCuUltim1);
                    }
                } else {
                    // x1 = 1 si xN = 1 => putem:
                    // 1) continua peste muchie (fara interval nou)
                    if (intervaleFolosite == numarStrangeriEx8) {
                        sumaMaxima = maximEx8(sumaMaxima, valoareCuUltim1);
                    }
                    // 2) taia peste muchie (interval nou)
                    if (intervaleFolosite + 1 == numarStrangeriEx8) {
                        sumaMaxima = maximEx8(sumaMaxima, valoareCuUltim1);
                    }
                }
            }
        }
    }

    if (sumaMaxima == NEGATIV_INF_EX8) {
        cout << "impossible\n";
    } else {
        cout << sumaMaxima << "\n";
    }

    delete[] dpAnteriorUltim0;
    delete[] dpAnteriorUltim1;
    delete[] dpCurentUltim0;
    delete[] dpCurentUltim1;
    delete[] productivitate;
}

#endif //EX8_H
