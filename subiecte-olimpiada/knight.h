#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <fstream>
using namespace std;

int nrNoduri1Fiu(int v[], int N) {
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

bool aSpreB(int v[], int N, int a, int b) {
    int qT[N + 1];
    int qC[N + 1];
    int stanga = 0, dreapta = 0;
    qT[dreapta] = v[v[a]];

}

void rezolvare() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/subiecte-olimpiada/knight.in");
    // ofstream fout("knight.out");
    int C, N;
    fin >> C >> N;
    int v[N + 1];
    v[1] = 0;
    for (int i = 2; i <= N; i++) {
        fin >> v[i];
    }

    if(C == 1) {
        cout << nrNoduri1Fiu(v, N);
    }

    if(C == 2) {
        int Q;
        fin >> Q;
        for(int i = 1; i <= Q; i++) {
            int a,b;
            fin >> a >> b;

        }
    }
}
#endif //KNIGHT_H
