#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <fstream>
using namespace std;

int *v;

int nrNoduri1Fiu(int N) {
    int cntFii[N + 1] = {};
    int rez = 0;

    for (int i = 1; i <= N; i++) {
        cntFii[v[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (cntFii[i] == 1) {
            rez++;
        }
    }

    return rez;
}

bool aSpreB(int N, int a, int b) {
    int qT[N + 1];
    int qC[N + 1];
    int stanga = 0, dreapta = 0;
    qT[dreapta] = v[v[a]];
    qC[dreapta++] = a;

    while (stanga < dreapta) {
        for(int i = 1; i <= N; i++) {
            if (v[i] == qT[stanga] && i != v[qC[stanga]]) {
                if(i == b) {
                    return true;
                }
                qT[dreapta] = v[v[i]];
                qC[dreapta++] = i;
            }
        }
        stanga++;
    }
    return false;
}

int moduriAspreB(int N, int a, int b) {
    int qT[N + 1];
    int qC[N + 1];
    int stanga = 0, dreapta = 0, rez = 0;
    qT[dreapta] = v[v[a]];
    qC[dreapta++] = a;

    while (stanga < dreapta) {
        for(int i = 1; i <= N; i++) {
            if (v[i] == qT[stanga] && i != v[qC[stanga]]) {
                if(i == b) {
                    rez++;
                }
                qT[dreapta] = v[v[i]];
                qC[dreapta++] = i;
            }
        }
        stanga++;
    }
    return rez;
}
void rezolvare() {
    // Use the repository-relative path so the input file is found after moving into its own folder.
    ifstream fin("subiecte-olimpiada/knight/knight.in");
    // ofstream fout("knight.out");
    int C, N;
    fin >> C >> N;
    v = new int[N + 1];
    v[1] = 0;
    for (int i = 2; i <= N; i++) {
        fin >> v[i];
    }

    if(C == 1) {
        cout << nrNoduri1Fiu(N); //fout
    }

    if(C == 2) {
        int Q = 0;
        fin >> Q;
        for(int i = 1; i <= Q; i++) {
            int a,b;
            fin >> a >> b;
            cout << aSpreB(N, a, b) << endl;    //fout
        }
    }

    if(C == 3) {
        int Q = 0;
        fin >> Q;
        for(int i = 1; i <= Q; i++) {
            int a,b;
            fin >> a >> b;
            cout << moduriAspreB(N, a, b) << endl;  //fout
        }
    }
}

void assert_eq(int actual, int expected) {
    if(actual != expected) {
        cout << "Failed: expected " << expected << " but got " << actual << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void assert_eqC2(bool actual, bool expected) {
    if(actual != expected) {
        cout << "Failed: expected " << expected << " but got " << actual << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void testare1() {
    int C = 1;
    int N = 7;
    int v[N + 1] = {0,0,1,1,3,3,3,4};
    int expected = 1;
    assert_eq(nrNoduri1Fiu(N), expected);
}

void testare2() {
    int C = 2;
    int N = 7;
    int v[N + 1] = {0,0,1,1,3,3,3,4};

    int Q = 3;
    int vA[Q] = {7,7,6};
    int vB[Q] = {2,4,2};
    int vExpected[Q] = {1,0,1};

    for(int i = 0; i < Q; i++) {
        assert_eq(aSpreB(N, vA[i], vB[i]), vExpected[i]);
    }
}

void testare3() {
    int C = 3;
    int N = 7;
    int v[N + 1] = {0,0,1,1,3,3,3,4};

    int Q = 3;
    int vA[Q] = {7,7,6};
    int vB[Q] = {2,4,2};
    int vExpected[Q] = {2,0,1};
    for(int i = 0; i < Q; i++) {
        assert_eq(moduriAspreB(N, vA[i], vB[i]), vExpected[i]);
    }
}
#endif //KNIGHT_H
