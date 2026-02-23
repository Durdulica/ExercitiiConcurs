#ifndef INC_5_2_STEFAN_H
#define INC_5_2_STEFAN_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//pentru n lectii video (cost = mb, timp = minute), gasiti intervalul continuu cu lungime in [L,U] care minimizeaza raportul
//media cost/durata. Afisati raportul minim si pozitiile

bool can(double mid, int cost[], int timp[], int n, int L, int U, double *pref, int *dq, int&left, int&right) {
    pref[0] = 0.0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cost[i - 1] - mid * timp[i - 1];
    }

    int back = 0, front = 0;

    for(int i = L; i <= n; i++) {
        int newStart = i - L;
        int oldStart = i - U;
        if(oldStart < 0) oldStart = 0;

        while(front < back && pref[dq[back - 1]] < pref[newStart]) back--;
        dq[back++] = newStart;

        while(front < back && dq[front] > oldStart) front++;

        if(front < back && pref[i] - pref[dq[front]] >= 0.0 && i - dq[front] <= U - L) {
            left = dq[front];
            right = i - 1;
            return true;
        }
    }
    return false;
}

void rezolvare() {
    int n, L, U;
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/utilitare/file.in.txt");
    fin >> n >> L >> U;

    int cost[n + 1];
    int timp[n + 1];
    for (int i = 0; i < n; i++) fin >> cost[i];
    for (int i = 0; i < n; i++) fin >> timp[i];

    double pref[n + 1] = {};
    int dq[n + 1] = {};

    double low = 0, high = 1000;
    int left = 0, right = 0;
    for (int i = 0; i < 60; i++) {
        double mid = (low + high) / 2;
        if(can(mid, cost, timp, n, L, U, pref, dq, left, right)) low = mid;
        else high = mid;
    }
    cout << low << " " << left << " " << right << endl;
}
#endif //INC_5_2_STEFAN_H
