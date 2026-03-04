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
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/subiecte-olimpiada/knight.in");
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
#endif //KNIGHT_H
