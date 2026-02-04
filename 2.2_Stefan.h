#ifndef INC_2_2_STEFAN_H
#define INC_2_2_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi. Det. subsecventa consec. de lungime c. p. k cu suma maxima si afisati pozitiile (1-based) si suma
ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(int v[], int &n, int &k) {
    fin >> n >> k;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

struct result {
    int sum = INT_MIN;
    int left = -1;
    int right = -1;
};

result rezolvare(int *v, int n, int k) {
    int prefix[n + 1] = {};
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    int bestSum = INT_MIN;
    int minPrefix = prefix[0];
    int posMinPrefix = 0;
    int bestL = 0, bestR = 0;

    for(int R = k; R <= n; R++) {
        if(prefix[R - k] < minPrefix) {
            minPrefix = prefix[R - k];
            posMinPrefix = R - k;
        }
        int sumCandidate = prefix[R] - minPrefix;
        if(sumCandidate > bestSum) {
            bestSum = sumCandidate;
            bestL = posMinPrefix;
            bestR = R - 1;
        }
    }

    result *rez = new result();
    rez->sum = bestSum;
    rez->left = bestL + 1;
    rez->right = bestR + 1;
    return *rez;
}

void testare() {

}
#endif //INC_2_2_STEFAN_H
