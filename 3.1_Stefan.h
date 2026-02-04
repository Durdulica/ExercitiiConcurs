#ifndef INC_3_1_STEFAN_H
#define INC_3_1_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi. Det. o secventa consecutiva de lungime exact k cu baza maxima(min din secventa)
ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

struct result {
    int left = -1, right = -1, best = INT_MIN;
};

void assert_eq(result *actual, result expected) {
    if(actual->left != expected.left || actual->right != expected.right || actual->best != expected.best) {
        cout << "Fail: expected " << expected.left << " " << expected.right << " " << expected.best << " but got: "
        << actual->left << " " << actual->right << " " << actual->best << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void citire(int *&v, int &n, int &k) {
    fin >> n >> k;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

result *rezolvare(int *v, int n, int k) {
    // int n, k;
    // int *v = nullptr;
    // citire(v, n, k);

    int top = -1;
    int leftLess[n];
    int rightLess[n];
    int idxStack[n];

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
    for (int i = n - 1; i >= 0; i--) {
        while(top >= 0 && v[idxStack[top]] > v[i]) {
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

    for (int i = 0; i < n; i++) {

        int leftBound = leftLess[i] + 1;
        int rightBound = rightLess[i] - 1;
        int length = rightBound - leftBound + 1;
        // cout << leftBound << " " << rightBound << endl;
        if(length != k) {
            continue;
        }

        int windowStart = i - k + 1;
        if(windowStart < leftBound) {
            windowStart = leftBound;
        }
        int windowEnd = windowStart + k - 1;

        int baseCandidate = v[i];
        bool better = false;
        if(baseCandidate > bestBase) {
            better = true;
        }else if(baseCandidate == bestBase) {
            if(windowStart < bestL) {
                better = true;
            }else if(windowStart == bestL && windowEnd == bestR) {
                better = true;
            }
        }

        if(better) {
            bestBase = baseCandidate;
            bestL = windowStart;
            bestR = windowEnd;
        }
    }

    result *rez= new result();
    rez->left = bestL + 1;
    rez->right = bestR + 1;
    rez->best = bestBase;
    return rez;
}

void test1() {
    int v[100] = {2,-1,4,0,3,-2};
    result *rez = rezolvare(v,6,1);
    result expected;
    expected.left = 3;
    expected.right = 3;
    expected.best = 4;

    assert_eq(rez, expected);
    delete rez;
}

void test2() {
    int v[100] = {2,-1,4,0,3,-2};
    result *rez = rezolvare(v,6,2);
    result expected;
    expected.left = 3;
    expected.right = 4;
    expected.best = 0;

    assert_eq(rez, expected);
    delete rez;
}

void test3() {
    int v[100] = {2,-1,4,0,3,-2};
    result *rez = rezolvare(v,6,3);
    result expected;
    expected.left = 3;
    expected.right = 5;
    expected.best = 0;

    assert_eq(rez, expected);
    delete rez;
}

void test4() {
    int v[100] = {2,-1,4,0,3,-2};
    result *rez = rezolvare(v,6,4);
    result expected;
    expected.left = 1;
    expected.right = 4;
    expected.best = -1;

    assert_eq(rez, expected);
    delete rez;
}

void test5() {
    int v[100] = {2,-1,4,0,3,-2};
    result *rez = rezolvare(v,6,5);
    result expected;
    expected.left = 1;
    expected.right = 5;
    expected.best = -1;

    assert_eq(rez, expected);
    delete rez;
}

void testare() {
    test1();
    test2();
    test3();
    test4();
    test5();
}
#endif //INC_3_1_STEFAN_H
