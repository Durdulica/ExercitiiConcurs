#ifndef INC_3_2_STEFAN_H
#define INC_3_2_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi si k. Det. o secventa consec. de lungime c. p. k cu baza maxima. Daca exista mai multe,
//alegeti secventa cu lungime minima, iar la egalitate cea mai din stanga

void rezolvare(int *v, int n, int k) {
    int leftLess[n] = {};
    int rightLess[n] = {};
    int idxStack[n] = {};
    int top = -1;
    for (int i = 0; i < n; i++) {
        while(top >= 0 && v[idxStack[top]] >= v[i]) {
            top--;
        }
        if(top >= 0) {
            leftLess[i] = idxStack[top];
        }else {
            leftLess[i] = -1;
        }
        idxStack[++top] = i;
    }
    top = -1;
    for(int i = n - 1; i >= 0; i--) {
        while(top >= 0 && v[idxStack[top]] > v[i]) {
            top--;
        }
        if(top >= 0) {
            rightLess[i] = idxStack[top];
        }else {
            rightLess[i] = -1;
        }
        idxStack[++top] = i;
    }

    int bestBase = INT_MIN, bestL = 0, bestR = k - 1;

    for(int i = 0; i < n; i++) {
        int leftBound = leftLess[i] + 1;
        int rightBound = rightLess[i] - 1;
        int length = rightBound - leftBound + 1;

        if(length < k) {
            continue;
        }

        int windowStart = i - k + 1;
        if(windowStart < leftBound) windowStart = leftBound;
        int windowEnd = windowStart + k - 1;
        int candidateBase = v[i];
        bool better = false;

        if(candidateBase > bestBase) {
            better = true;
        }else if(candidateBase == bestBase) {
            if(windowStart < bestL) {
                better = true;
            }else if(windowStart == bestL && windowEnd <= bestR) {
                better = true;
            }
        }

        if(better) {
            bestBase = candidateBase;
            bestL = windowStart;
            bestR = windowEnd;
        }
    }

    cout << bestL + 1 << " " << bestR + 1 << " " << bestBase << endl;
}
#endif //INC_3_2_STEFAN_H
