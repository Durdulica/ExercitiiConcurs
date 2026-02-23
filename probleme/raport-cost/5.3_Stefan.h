#ifndef INC_5_3_STEFAN_H
#define INC_5_3_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//intr-un sir de sonzori (cost = ener. consumata, timp = timp activ), det. daca exista o fereastra de lungime fix K cu
//raport energie/timp cel putin T. Afisati YES/NO

bool can(double x, int cost[], int timp[], int n, int K, double pref[], int dq[]) {
    pref[0] = 0.0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cost[i - 1] - x * timp[i - 1];
    }

    int front = 0, back = 0;
    for(int i = K; i <= n; i++) {
        int newStart = i - K;

        while(front < back && pref[dq[back - 1]] >= pref[newStart]) back--;
        dq[back++] = newStart;

        while(front < back && dq[front] < newStart) front++;

        if(front < back && pref[i] - pref[dq[front]] >= 0.0) return true;
    }
    return false;
}

void rezolvare() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/utilitare/file.in.txt");
    int n, K;
    double T;
    fin >> n >> K >> T;

    int cost[n + 1];
    int timp[n + 1];
    for(int i = 0; i < n; i++) fin >> cost[i];
    for(int i = 0; i < n; i++) fin >> timp[i];

    double pref[n + 1] = {};
    int dq[n + 1];

    double low = 0, high = 1000;
    for(int i = 1; i < 60; i++) {
        double mid = (low + high) / 2;
        if(can(mid, cost, timp, n, K, pref, dq)) low = mid;
        else high = mid;
        if(low >= T) {
            cout << " Yes\n";
            return;
        }
    }
    cout << " No\n";
}
#endif //INC_5_3_STEFAN_H
