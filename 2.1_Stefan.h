#ifndef INC_2_1_STEFAN_H
#define INC_2_1_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//sa da un sir de n nr.  intregi. Det suma maxima a unei subsecvente consec. de lungime exacta k, precum si pozitiile
//de inceput si sfarsit(1-based)
ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

struct result {
    long long int sum = INT_MIN;
    int left = -1;
    int right = -1;
};

void assert_eq(result actual, result expected, const char *label){
    if(actual.sum != expected.sum || actual.left != expected.left || actual.right != expected.right) {
        cout << "ERROR: " << label << " expected "
        << expected.sum << " " << expected.left <<  " " << expected.right << " but got "
        << actual.sum << " " << actual.left << " " << actual.right << endl;
    }else{
        cout << "Passed" << endl;
    }
}

void citire(int *&vec, int &n, int &k) {
    fin >> n >> k;
    vec = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> vec[i];
    }
}

result *rezolvare(int v[], int n, int k){
    // int n, k;
    // int *v = nullptr;
    result *rez = new result();
    // citire(v, n, k);

    if(!v || !n || !k) {
        cout << "Error on reading" << endl;
        // delete []v;
        return rez;
    }

    int prefix[n] = {};
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    long long bestSum = INT_MIN;
    long long minPrefix = prefix[0];
    int posMinPrefix = 0;
    int bestL = 0, bestR = 0;

    for(int R = k; R <= n; R++) {
        if(prefix[R - k] < minPrefix) {
            minPrefix = prefix[R - k];
            posMinPrefix = R - k;
        }

        int sumCandidate = prefix[R] - minPrefix;
        if(sumCandidate > bestSum && R - posMinPrefix == k) {
            bestSum = sumCandidate;
            bestL = posMinPrefix;
            bestR = R - 1;
        }
    }

    rez->sum = bestSum;
    rez->left = bestL + 1;
    rez->right = bestR + 1;
    return rez;
}

void testare() {
    result *r = new result();
    r->sum = 6;
    r->left = 3;
    r->right = 5;
    // assert_eq(*rezolvare(,8,3), *r, "vec: 1 -2 3 4 -1 2 -5 2");
    r->sum = 12;
    r->left = 6;
    r->right = 8;
    // assert_eq(*rezolvare(,8,3), *r, "vec: 1 -2 3 4 -1 2 -5 15");
    delete r;
}
#endif //INC_2_1_STEFAN_H