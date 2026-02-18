#ifndef INC_5_1_STEFAN_H
#define INC_5_1_STEFAN_H
#include <iostream>
using namespace std;

//avem n proiecte, fiecare cu cost si durata. Alegeti o subsecventa continua cu lungime intre L si U care maximizeaza media
//cost/durata. Afis val max.

bool can(double mid, int*cost, int*durata, int n, int L, int U, double*pref, int*dq) {
    pref[0] = 0.0;
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cost[i - 1] - mid * durata[i - 1];
    }

    int front = 0;
    int back = 0;

    for(int i = L; i <= n; i++) {
        int newestStart = i - L, oldestStart = i - U;
        if(oldestStart < 0) oldestStart = 0;

        while(front < back && pref[dq[back - 1]] >= pref[newestStart]) back--;
        dq[back++] = newestStart;

        while(front < back && dq[front] < oldestStart) front++;

        if(front < back && pref[i] - pref[dq[front]] >= 0.0) {
            return true;
        }
    }
    return false;
}

void rezolvare() {
    int n, L, U;
    cin >> n >> L >> U;

    int cost[n];
    int durata[n];
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) cin >> durata[i];

    double pref[n + 1];
    int dq[n + 1];

    double low = 0, high = 1000;
    for(int it = 0; it <= 60; it++) {
        double mid = (low + high) * 0.5;
        if(can(mid, cost, durata, n, L, U,  pref, dq)) low = mid;
        else high = mid;
    }

    cout << low << endl;
}
#endif //INC_5_1_STEFAN_H
