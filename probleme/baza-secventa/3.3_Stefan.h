#ifndef INC_3_3_STEFAN_H
#define INC_3_3_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi si q interogari, fiecare interogare avand o val. k. Pt. fiecare k, det. o secventa consec.
//de lungime c. p. k cu baza maxima si afis. baza maxima

int rezolvare(int *v, int n, int k) {
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
        while(top >= 0 && v[idxStack[top]] >= v[i]) {
            top--;
        }
        if(top >= 0) {
            rightLess[i] = idxStack[top];
        }else {
            rightLess[i] = n;
        }
        idxStack[++top] = i;
    }

    int bestBase = INT_MIN, bestL = 0, bestR = k - 1;
    for(int i = 0; i < n; i++) {
        int leftBound = leftLess[i] + 1;
        int rightBound = rightLess[i] - 1;
        int length = rightBound - leftBound + 1;

        if(length < k) continue;

        int windowStart = i - k + 1;
        if(windowStart < leftBound) windowStart = leftBound;
        int windowEnd = windowStart + k - 1;
        int bestCandidate = v[i];
        bool better = false;

        if(bestCandidate > bestBase) {
            better = true;
        }else if(bestCandidate == bestBase) {
            if(windowStart < bestL) {
                better = true;
            }else if(windowStart == bestL && windowEnd < bestR) {
                better = true;
            }
        }

        if(better) {
            bestBase = bestCandidate;
            bestL = windowStart;
            bestR = windowEnd;
        }
    }

    return bestBase;
}

ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(int *&v, int &n, int*&vk, int &q) {
    fin >> n >> q;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    vk = new int[q];
    for (int i = 0; i < q; i++) {
        fin >> vk[i];
    }
}

void assert_eq(int expected, int actual) {
    if(expected != actual) {
        cout << "Failed: expected " << expected << " but got: " << actual << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void testare() {
    int n, q;
    int *v = nullptr, *vk = nullptr;
    citire(v, n, vk, q);
    int expected[q] = {5,3,1};

    for(int i = 0; i < q; i++) {
        assert_eq(expected[i],rezolvare(v,n,vk[i]));
    }

    delete []v;
    delete []vk;
}
#endif //INC_3_3_STEFAN_H