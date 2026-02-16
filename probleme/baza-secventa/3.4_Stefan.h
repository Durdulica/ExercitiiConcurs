#ifndef INC_3_4_STEFAN_H
#define INC_3_4_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi si doua val. k si s. Det. o secventa consec. de lungime c. p. k cu baxa maxima, avand suma
//elem. c. p. s. Daca nu exista, afisati "NU"

int sumaSecVec(int *v, int start, int end) {
    int sum = 0;
    for(int i = start; i <= end; i++) {
        sum += v[i];
    }
    return sum;
}

void citire(int *&v, int &n, int &k, int &s) {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    fin >> n >> k >> s;
    v = new int[n];
    for(int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

void rezolvare() {
    int *v = nullptr, n, k, s;
    citire(v, n, k, s);
    int leftLess[n] = {};
    int rightLess[n] = {};
    int idxStack[n] = {};
    int top = -1;

    for(int i = 0; i < n; i++) {
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

        if(sumaSecVec(v, windowStart, windowEnd) >= s) {
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
    }
    if(bestBase == INT_MIN) {
        cout << "NU";
    }else {
        cout << bestBase << " " << bestL << " " << bestR << endl;
    }
}

#endif //INC_3_4_STEFAN_H