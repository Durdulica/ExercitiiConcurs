#ifndef PAS3_CERC_UN_INTERVAL_H
#define PAS3_CERC_UN_INTERVAL_H

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

namespace invatare_dp_ex8_pas3 {

// Enunt:
// Avem N numere pe un cerc (N este adiacent cu 1).
// Alege exact un interval continuu, nevid, pe cerc, cu suma maxima.
//
// Input:
// N
// v1 v2 ... vN
//
// Output:
// suma maxima

inline long long maximPas3(long long a, long long b) {
    return (a > b ? a : b);
}

inline long long minimPas3(long long a, long long b) {
    return (a < b ? a : b);
}

void rezolvare() {
    int numarElemente = 0;
    cin >> numarElemente;
    assert(numarElemente >= 1 && numarElemente <= 200000);

    long long *valori = new long long[numarElemente + 1];
    assert(valori != nullptr);

    for (int index = 1; index <= numarElemente; ++index) {
        cin >> valori[index];
    }

    long long sumaTotala = valori[1];

    long long sumaCurentaMax = valori[1];
    long long sumaMaximaNormala = valori[1];

    long long sumaCurentaMin = valori[1];
    long long sumaMinimaNormala = valori[1];

    for (int index = 2; index <= numarElemente; ++index) {
        long long valoare = valori[index];
        sumaTotala += valoare;

        sumaCurentaMax = maximPas3(valoare, sumaCurentaMax + valoare);
        sumaMaximaNormala = maximPas3(sumaMaximaNormala, sumaCurentaMax);

        sumaCurentaMin = minimPas3(valoare, sumaCurentaMin + valoare);
        sumaMinimaNormala = minimPas3(sumaMinimaNormala, sumaCurentaMin);
    }

    long long raspuns;
    if (sumaMaximaNormala < 0) {
        // Toate valorile sunt negative, intervalul wrap-around ar da interval gol (interzis).
        raspuns = sumaMaximaNormala;
    } else {
        long long variantaPeCerc = sumaTotala - sumaMinimaNormala;
        raspuns = maximPas3(sumaMaximaNormala, variantaPeCerc);
    }

    cout << raspuns << "\n";
    delete[] valori;
}

} // namespace invatare_dp_ex8_pas3

#endif // PAS3_CERC_UN_INTERVAL_H
