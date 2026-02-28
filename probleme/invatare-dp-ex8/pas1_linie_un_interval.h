#ifndef PAS1_LINIE_UN_INTERVAL_H
#define PAS1_LINIE_UN_INTERVAL_H

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

namespace invatare_dp_ex8_pas1 {

// Enunt:
// Avem N numere intregi pe o linie.
// Alege exact un interval continuu, nevid, cu suma maxima.
//
// Input:
// N
// v1 v2 ... vN
//
// Output:
// suma maxima a unui interval continuu nevid

void rezolvare() {
    int numarElemente = 0;
    cin >> numarElemente;
    assert(numarElemente >= 1 && numarElemente <= 200000);

    long long valoareCurenta = 0;
    cin >> valoareCurenta;

    long long sumaCurenta = valoareCurenta;
    long long sumaMaxima = valoareCurenta;

    for (int index = 2; index <= numarElemente; ++index) {
        cin >> valoareCurenta;
        long long pornesteNou = valoareCurenta;
        long long continuaInterval = sumaCurenta + valoareCurenta;

        if (pornesteNou > continuaInterval) {
            sumaCurenta = pornesteNou;
        } else {
            sumaCurenta = continuaInterval;
        }

        if (sumaCurenta > sumaMaxima) {
            sumaMaxima = sumaCurenta;
        }
    }

    cout << sumaMaxima << "\n";
}

} // namespace invatare_dp_ex8_pas1

#endif // PAS1_LINIE_UN_INTERVAL_H
