#ifndef INC_2_3_STEFAN_H
#define INC_2_3_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//sa da un sir de n nr. intregi si 2 val k si l(k <= l). Det. subsecventa consecutiva cu suma maxima si lungime intre k si l

ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(int *&v, int &n, int &k, int &l) {
    fin >> n >> k >> l;
    v = new int[n];
    for(int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

void rezolvare() {
    int n, k, l;
    int *v = nullptr;
    citire(v, n, k, l);

    int prefix[n + 1] = {};
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    int q[n + 1], st = 0, dr = -1;
    int bestSum = INT_MIN;
    int bestL = 0, bestR = 0;

    for(int R = k; R <= n; R++) {
        while(st <= dr && prefix[q[dr]] >= prefix[R - k]) {
            dr--;
        }
        q[++dr] = R - k;

        while(st <= dr && q[st] < R - l) {
            st++;
        }
        if(st <= dr) {
            int sumCanditate = prefix[R] - prefix[q[st]];
            if(sumCanditate > bestSum) {
                bestSum = sumCanditate;
                bestL = q[st];
                bestR = R - 1;
            }
        }
    }

    cout << bestL + 1 << " " << bestR + 1 << " " << bestSum << endl;
}
#endif //INC_2_3_STEFAN_H