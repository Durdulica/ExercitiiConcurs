#ifndef EX2_H
#define EX2_H
#include<iostream>
using namespace std;

int n, k, v[50000];

void rezolvare() {
    if (!citire()) {
        return;
    }

    int prefix[n];
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + v[i - 1]; // prefix clasic pentru sume rapide
    }

    long long bestSum = LLONG_MIN; // cea mai buna suma gasita
    long long minPrefix = prefix[0]; // minimul prefixurilor eligibile
    int posMinPrefix = 0;
    int bestL = 0, bestR = 0;

    for (int R = k; R <= n; ++R) { // R este capatul din dreapta + 1
        if (prefix[R - k] < minPrefix) { // prefixul minim admis pentru lungime >= k
            minPrefix = prefix[R - k];
            posMinPrefix = R - k;
        }

        long long sumCandidate = prefix[R] - minPrefix; // suma secventei curente
        if (sumCandidate > bestSum) {
            bestSum = sumCandidate;
            bestL = posMinPrefix;
            bestR = R - 1;
        }
    }

    cout << bestL + 1 << " " << bestR + 1 << " " << bestSum << "\n"; // iesire 1-based
}
#endif //EX2_H