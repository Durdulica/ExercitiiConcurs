#ifndef INC_5_4_STEFAN_H
#define INC_5_4_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//data o scventa de cheltuieli zilnice si timpi de asteptare, gasiti cea mai lunga fereastra cu raport cost/timp sub o limita P
//Afisati lungimea maxima si intervalul
//todo: gasirea secventei de lungime MAXIMA
bool can(double x, const int cost[], const int timp[], int n, double P, int L, double pref[], int dq[], int &left, int &right, int &ct, double &maxim) {
    pref[0] = 0.0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cost[i - 1] - x * timp[i - 1];
    }

    int front = 0, back = 0;

    for(int i = L; i <= n; i++) {
        int newStart = i - L;

        while(front < back && pref[dq[back - 1]] >= pref[newStart]) back--;
        dq[back++] = newStart;

        while(front < back && dq[front] < 0) front++;

        if(front < back && pref[i] - pref[dq[front]] >= 0.0) {
            if(x < P && x > maxim) {
                maxim = x;
                ct = i - dq[front];
                left = dq[front];
                right = i - 1;
            }else if(x < P && x == maxim && i - dq[front] >= ct) {
                ct = i - dq[front];
                left = dq[front];
                right = i - 1;
            }
            return true;
        }
    }
    return false;
}

void rezolvare() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/utilitare/file.in.txt");
    int n;
    double P;
    fin >> n >> P;

    int cost[n + 1];
    int timp[n + 1];
    for (int i = 0; i < n; i++) fin >> cost[i];
    for (int i = 0; i < n; i++) fin >> timp[i];

    double pref[n + 1] = {};
    int dq[n + 1];

    double low = 0, high = 1000;
    int left, right, ct = INT_MIN;
    double maxim = INT_MIN;
    for(int i = 0; i < 60; i++) {
        double mid = (low + high) / 2;
        if(can(mid, cost, timp, n, P,1, pref, dq, left, right, ct, maxim)) low = mid;
        else high = mid;
    }
    cout << maxim << " " << ct << " " << left << " " << right << endl;
}
#endif //INC_5_4_STEFAN_H