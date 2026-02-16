#ifndef INC_2_5_STEFAN_H
#define INC_2_5_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi si o penalizare p. Pt. o subsecventa consec, val. ei este suma elem. minus p * lungime.
//Det. subsecventa cu val. maxima si afisati pozitiile si val. ei
ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(int *&v, int &n, int &p) {
    fin >> n >> p;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

void rezolvare() {
    int n, p;
    int *v = nullptr;
    citire(v, n, p);

    int prefix[n + 1] = {};
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    int bestSum = INT_MIN;
    int minPrefix = 0, posMinPrefix = 0;
    int bestL = 0, bestR = 0;

    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            if(prefix[r - l] < minPrefix) {
                minPrefix = prefix[r - l];
                posMinPrefix = r - l;
            }

            int sumCandidate = prefix[r] - minPrefix - (p * (r - posMinPrefix));
            if(sumCandidate > bestSum) {
                bestSum = sumCandidate;
                bestL = posMinPrefix;
                bestR = r - 1;
            }
        }
    }

    cout << bestL + 1 << " " << bestR + 1 << " " << bestSum << endl;
    delete[] v;
}
#endif //INC_2_5_STEFAN_H