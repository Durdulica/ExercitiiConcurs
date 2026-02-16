#ifndef EX5_H
#define EX5_H
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Problema (pe scurt):
 * - Avem n (<= 30000) elemente consecutive; pentru fiecare știm două numere: cost și timp (ambele în [1,1000]).
 * - Vrem să alegem o subsecvență continuă cu lungimea între L și U inclusiv,
 *   astfel încât media costurilor raportată la timpi (suma_cost / suma_timp) să fie cât mai mare.
 *
 * Ideea principală (potrivită și pentru începători):
 * - Transformăm căutarea unei „medii maxime” într-o verificare cu sume.
 * - Presupunem că răspunsul ar fi o valoare x. Dacă există o subsecvență validă pentru care
 *   suma(cost - x * timp) >= 0, atunci media reală poate fi cel puțin x.
 * - Folosim căutare binară pe x: încercăm valori din ce în ce mai precise și verificăm de fiecare dată.
 *
 * Cum verificăm rapid pentru un x dat:
 * - Calculăm prefixele: pref[i] = sum_{0..i-1}(cost - x * timp).
 * - Pentru fiecare capăt i al ferestrei, avem voie să începem între i-U și i-L.
 * - Ne trebuie minimul pref din acel interval; dacă pref[i] - min_pref >= 0, există o fereastră bună.
 * - Minimul pe fereastra glisantă îl ținem cu un deque (coadă dublă) în O(1) amortizat.
 *
 * Algoritm folosit:
 * - Căutare binară pe răspuns + verificare cu prefixe și deque de minime (tehnica „binary search pe medie”).
 *   Este o tehnică standard pentru probleme de tip „maximizați media / raportul”.
 */

 bool can(double x, const int *cost, const int *timp, int n, int L, int U, double *pref, int *dq) {
    pref[0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (double)cost[i - 1] - x * (double)timp[i - 1];
    }

    int front = 0, back = 0; // deque indices in dq[]

    for (int i = L; i <= n; ++i) {
        int newestStart = i - L;          // început exact L în urmă
        int oldestStart = i - U;          // cel mai vechi admis
        if (oldestStart < 0) oldestStart = 0;

        // adaugă newestStart menținând minimul prefixelor
        while (back > front && pref[dq[back - 1]] >= pref[newestStart]) back--;
        dq[back++] = newestStart;

        // scoate începuturile ieșite din fereastra [oldestStart, i-L]
        while (back > front && dq[front] < oldestStart) front++;

        if (back > front && pref[i] - pref[dq[front]] >= 0.0) {
            return true;
        }
    }
    return false;
}

void rezolvare() {
    int n, L, U;
    if (!(cin >> n >> L >> U)) return;
    if (n <= 0 || n > 30000) return;

    static int cost[30005];
    static int timp[30005];
    for (int i = 0; i < n; ++i) cin >> cost[i];
    for (int i = 0; i < n; ++i) cin >> timp[i];

    static double pref[30005];
    static int dq[30005];

    double lo = 0.0, hi = 1000.0; // cost și timp <= 1000 => media maximă <= 1000
    for (int it = 0; it < 60; ++it) {
        double mid = (lo + hi) * 0.5;
        if (can(mid, cost, timp, n, L, U, pref, dq)) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(6) << lo << "\n";
}

#endif //EX5_H
