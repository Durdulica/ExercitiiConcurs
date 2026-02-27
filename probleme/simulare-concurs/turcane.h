#ifndef TURCANE_H
#define TURCANE_H

#include <cassert>
#include <iostream>

namespace turcane {

const int MODULO = 1000000007;
const int INFINIT = 1000000000;
const int MAX_LINII = 1005;
const int MAX_DIAG = 2010;

struct DateProblema {
    int linii;
    int coloane;
    int saltDreaptaMax;
    int saltJosMax;
    int saltDiagonalaMax;
};

int dpMinimSaritura[MAX_LINII][MAX_LINII];
int dpNumarModuri[MAX_LINII][MAX_LINII];
int dpBrut[MAX_LINII][MAX_LINII];
int prefixLinie[MAX_LINII][MAX_LINII];
int prefixColoana[MAX_LINII][MAX_LINII];
int prefixDiagonala[MAX_LINII][MAX_LINII];

int coadaColPozitie[MAX_LINII][MAX_LINII];
int coadaColValoare[MAX_LINII][MAX_LINII];
int inceputCoadaCol[MAX_LINII];
int sfarsitCoadaCol[MAX_LINII];

int coadaDiagPozitie[MAX_DIAG][MAX_LINII];
int coadaDiagValoare[MAX_DIAG][MAX_LINII];
int inceputCoadaDiag[MAX_DIAG];
int sfarsitCoadaDiag[MAX_DIAG];

inline int minim2(int a, int b) {
    return (a < b) ? a : b;
}

inline int minim3(int a, int b, int c) {
    return minim2(a, minim2(b, c));
}

inline int maxim2(int a, int b) {
    return (a > b) ? a : b;
}

int calculeazaMinimSaritura(const DateProblema& date) {
    int i, j;

    for (i = 1; i <= date.linii; ++i) {
        for (j = 1; j <= date.coloane; ++j) {
            dpMinimSaritura[i][j] = INFINIT;
        }
    }

    for (j = 1; j <= date.coloane; ++j) {
        inceputCoadaCol[j] = 0;
        sfarsitCoadaCol[j] = 0;
    }

    for (i = 0; i <= date.linii + date.coloane; ++i) {
        inceputCoadaDiag[i] = 0;
        sfarsitCoadaDiag[i] = 0;
    }

    for (i = 1; i <= date.linii; ++i) {
        int coadaLiniePozitie[MAX_LINII];
        int coadaLinieValoare[MAX_LINII];
        int inceputCoadaLinie = 0;
        int sfarsitCoadaLinie = 0;

        for (j = 1; j <= date.coloane; ++j) {
            if (i == 1 && j == 1) {
                dpMinimSaritura[i][j] = 0;
            } else {
                int ceaMaiBuna = INFINIT;

                if (date.saltDreaptaMax > 0) {
                    while (inceputCoadaLinie < sfarsitCoadaLinie &&
                           coadaLiniePozitie[inceputCoadaLinie] < j - date.saltDreaptaMax) {
                        ++inceputCoadaLinie;
                    }
                    if (inceputCoadaLinie < sfarsitCoadaLinie) {
                        ceaMaiBuna = minim2(ceaMaiBuna, coadaLinieValoare[inceputCoadaLinie]);
                    }
                }

                if (date.saltJosMax > 0) {
                    while (inceputCoadaCol[j] < sfarsitCoadaCol[j] &&
                           coadaColPozitie[j][inceputCoadaCol[j]] < i - date.saltJosMax) {
                        ++inceputCoadaCol[j];
                    }
                    if (inceputCoadaCol[j] < sfarsitCoadaCol[j]) {
                        ceaMaiBuna = minim2(ceaMaiBuna, coadaColValoare[j][inceputCoadaCol[j]]);
                    }
                }

                if (date.saltDiagonalaMax > 0) {
                    int indexDiagonala = i - j + date.coloane;
                    while (inceputCoadaDiag[indexDiagonala] < sfarsitCoadaDiag[indexDiagonala] &&
                           coadaDiagPozitie[indexDiagonala][inceputCoadaDiag[indexDiagonala]] <
                               i - date.saltDiagonalaMax) {
                        ++inceputCoadaDiag[indexDiagonala];
                    }
                    if (inceputCoadaDiag[indexDiagonala] < sfarsitCoadaDiag[indexDiagonala]) {
                        ceaMaiBuna = minim2(ceaMaiBuna, coadaDiagValoare[indexDiagonala][inceputCoadaDiag[indexDiagonala]]);
                    }
                }

                if (ceaMaiBuna < INFINIT) {
                    dpMinimSaritura[i][j] = ceaMaiBuna + 1;
                }
            }

            if (dpMinimSaritura[i][j] < INFINIT) {
                int valoareCurenta = dpMinimSaritura[i][j];

                if (date.saltDreaptaMax > 0) {
                    while (inceputCoadaLinie < sfarsitCoadaLinie &&
                           coadaLinieValoare[sfarsitCoadaLinie - 1] >= valoareCurenta) {
                        --sfarsitCoadaLinie;
                    }
                    coadaLiniePozitie[sfarsitCoadaLinie] = j;
                    coadaLinieValoare[sfarsitCoadaLinie] = valoareCurenta;
                    ++sfarsitCoadaLinie;
                }

                if (date.saltJosMax > 0) {
                    while (inceputCoadaCol[j] < sfarsitCoadaCol[j] &&
                           coadaColValoare[j][sfarsitCoadaCol[j] - 1] >= valoareCurenta) {
                        --sfarsitCoadaCol[j];
                    }
                    coadaColPozitie[j][sfarsitCoadaCol[j]] = i;
                    coadaColValoare[j][sfarsitCoadaCol[j]] = valoareCurenta;
                    ++sfarsitCoadaCol[j];
                }

                if (date.saltDiagonalaMax > 0) {
                    int indexDiagonala = i - j + date.coloane;
                    while (inceputCoadaDiag[indexDiagonala] < sfarsitCoadaDiag[indexDiagonala] &&
                           coadaDiagValoare[indexDiagonala][sfarsitCoadaDiag[indexDiagonala] - 1] >=
                               valoareCurenta) {
                        --sfarsitCoadaDiag[indexDiagonala];
                    }
                    coadaDiagPozitie[indexDiagonala][sfarsitCoadaDiag[indexDiagonala]] = i;
                    coadaDiagValoare[indexDiagonala][sfarsitCoadaDiag[indexDiagonala]] = valoareCurenta;
                    ++sfarsitCoadaDiag[indexDiagonala];
                }
            }
        }
    }

    return dpMinimSaritura[date.linii][date.coloane];
}

int calculeazaNumarModuri(const DateProblema& date) {
    int i, j;

    for (i = 0; i <= date.linii; ++i) {
        for (j = 0; j <= date.coloane; ++j) {
            dpNumarModuri[i][j] = 0;
            prefixLinie[i][j] = 0;
            prefixColoana[i][j] = 0;
            prefixDiagonala[i][j] = 0;
        }
    }

    for (i = 1; i <= date.linii; ++i) {
        for (j = 1; j <= date.coloane; ++j) {
            long long moduri = 0;

            if (i == 1 && j == 1) {
                moduri = 1;
            } else {
                if (date.saltDreaptaMax > 0) {
                    int coloanaStanga = maxim2(1, j - date.saltDreaptaMax);
                    moduri += prefixLinie[i][j - 1] - prefixLinie[i][coloanaStanga - 1];
                }

                if (date.saltJosMax > 0) {
                    int linieSus = maxim2(1, i - date.saltJosMax);
                    moduri += prefixColoana[i - 1][j] - prefixColoana[linieSus - 1][j];
                }

                if (date.saltDiagonalaMax > 0) {
                    int k = minim3(date.saltDiagonalaMax, i - 1, j - 1);
                    if (k > 0) {
                        moduri += prefixDiagonala[i - 1][j - 1] - prefixDiagonala[i - k - 1][j - k - 1];
                    }
                }
            }

            moduri %= MODULO;
            if (moduri < 0) {
                moduri += MODULO;
            }

            dpNumarModuri[i][j] = (int)moduri;

            prefixLinie[i][j] = prefixLinie[i][j - 1] + dpNumarModuri[i][j];
            if (prefixLinie[i][j] >= MODULO) {
                prefixLinie[i][j] -= MODULO;
            }

            prefixColoana[i][j] = prefixColoana[i - 1][j] + dpNumarModuri[i][j];
            if (prefixColoana[i][j] >= MODULO) {
                prefixColoana[i][j] -= MODULO;
            }

            prefixDiagonala[i][j] = prefixDiagonala[i - 1][j - 1] + dpNumarModuri[i][j];
            if (prefixDiagonala[i][j] >= MODULO) {
                prefixDiagonala[i][j] -= MODULO;
            }
        }
    }

    return dpNumarModuri[date.linii][date.coloane];
}

int brutMinimSaritura(const DateProblema& date) {
    int i, j, k;

    for (i = 1; i <= date.linii; ++i) {
        for (j = 1; j <= date.coloane; ++j) {
            dpBrut[i][j] = INFINIT;
        }
    }

    dpBrut[1][1] = 0;

    for (i = 1; i <= date.linii; ++i) {
        for (j = 1; j <= date.coloane; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }

            int ceaMaiBuna = INFINIT;
            for (k = 1; k <= date.saltDreaptaMax && j - k >= 1; ++k) {
                ceaMaiBuna = minim2(ceaMaiBuna, dpBrut[i][j - k]);
            }
            for (k = 1; k <= date.saltJosMax && i - k >= 1; ++k) {
                ceaMaiBuna = minim2(ceaMaiBuna, dpBrut[i - k][j]);
            }
            for (k = 1; k <= date.saltDiagonalaMax && i - k >= 1 && j - k >= 1; ++k) {
                ceaMaiBuna = minim2(ceaMaiBuna, dpBrut[i - k][j - k]);
            }

            if (ceaMaiBuna < INFINIT) {
                dpBrut[i][j] = ceaMaiBuna + 1;
            }
        }
    }

    return dpBrut[date.linii][date.coloane];
}

int brutNumarModuri(const DateProblema& date) {
    int i, j, k;

    for (i = 1; i <= date.linii; ++i) {
        for (j = 1; j <= date.coloane; ++j) {
            dpBrut[i][j] = 0;
        }
    }

    dpBrut[1][1] = 1;

    for (i = 1; i <= date.linii; ++i) {
        for (j = 1; j <= date.coloane; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }

            long long moduri = 0;
            for (k = 1; k <= date.saltDreaptaMax && j - k >= 1; ++k) {
                moduri += dpBrut[i][j - k];
            }
            for (k = 1; k <= date.saltJosMax && i - k >= 1; ++k) {
                moduri += dpBrut[i - k][j];
            }
            for (k = 1; k <= date.saltDiagonalaMax && i - k >= 1 && j - k >= 1; ++k) {
                moduri += dpBrut[i - k][j - k];
            }

            dpBrut[i][j] = (int)(moduri % MODULO);
        }
    }

    return dpBrut[date.linii][date.coloane];
}

void rezolvaDinStream(std::istream& intrare, std::ostream& iesire) {
    int cerinta;
    DateProblema date;

    intrare >> cerinta;
    intrare >> date.linii >> date.coloane;
    intrare >> date.saltDreaptaMax >> date.saltJosMax >> date.saltDiagonalaMax;

    if (cerinta == 1) {
        iesire << calculeazaMinimSaritura(date) << '\n';
    } else {
        iesire << calculeazaNumarModuri(date) << '\n';
    }
}

void testare() {
    {
        DateProblema date = {3, 4, 1, 1, 0};
        assert(calculeazaMinimSaritura(date) == 5);
        assert(calculeazaNumarModuri(date) == 10);
    }

    {
        DateProblema date = {5, 5, 2, 2, 2};
        assert(calculeazaMinimSaritura(date) == brutMinimSaritura(date));
        assert(calculeazaNumarModuri(date) == brutNumarModuri(date));
    }

    for (int linii = 1; linii <= 8; ++linii) {
        for (int coloane = 1; coloane <= 8; ++coloane) {
            for (int saltDreapta = 0; saltDreapta <= maxim2(0, coloane - 1); ++saltDreapta) {
                for (int saltJos = 0; saltJos <= maxim2(0, linii - 1); ++saltJos) {
                    int saltDiagMax = minim2(linii - 1, coloane - 1);
                    for (int saltDiag = 0; saltDiag <= saltDiagMax; ++saltDiag) {
                        if (linii == 1 && coloane == 1) {
                            continue;
                        }
                        if (saltDreapta == 0 && saltJos == 0 && saltDiag == 0) {
                            continue;
                        }

                        DateProblema date = {linii, coloane, saltDreapta, saltJos, saltDiag};
                        int rezultatRapidMinim = calculeazaMinimSaritura(date);
                        int rezultatBrutMinim = brutMinimSaritura(date);
                        int rezultatRapidModuri = calculeazaNumarModuri(date);
                        int rezultatBrutModuri = brutNumarModuri(date);

                        assert(rezultatRapidMinim == rezultatBrutMinim);
                        assert(rezultatRapidModuri == rezultatBrutModuri);
                    }
                }
            }
        }
    }

    std::cout << "Turcane tests: PASS\n";
}

} // namespace turcane

#endif // TURCANE_H
