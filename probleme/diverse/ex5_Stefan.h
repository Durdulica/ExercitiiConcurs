#ifndef EX5_STEFAN_H
#define EX5_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//sa se aleaga o secventa din n <= 30000 elem. pt. care se cunosc costul si timpul. Secventa aleasa trebuie sa fie de lungime
//minim L si maxim U, iar suma costurilor elem. secventei impartita la suma timpurilor elem. secventei, sa fie maxima. Pe prima
//linie a fisierului sa afla nr. n, l si u. Pe cea de-a doua linie se vor gasi n nr. nat repr. costurile elem. secventei, iar pe
//cea dea treia linie se vor gasi n nr. naturale repr. timpurile . Costul si timpul unui elem. este un nr. din intervalul [1,1000]

struct Elem {
    int timp;
    int cost;
    int nr;
};

int n, l, u;

void citire(Elem *&vec) {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    fin >> n >> l >> u;
    vec = new Elem[n];
    for (int i = 0; i < n; i++) {
        fin >> vec[i].cost;
        vec[i].nr = i;
    }
    for (int i = 0; i < n; i++) {
        fin >> vec[i].timp;
    }
}

void rezolvare() {
    Elem *vec = nullptr;

    citire(vec);

    int prefixCost[n], prefixTimp[n];
    prefixCost[0] = vec[0].cost;
    prefixTimp[0] = vec[0].timp;
    for (int i = 1; i < n; i++) {
        prefixCost[i] = prefixCost[i - 1] + vec[i].cost;
        prefixTimp[i] = prefixTimp[i - 1] + vec[i].timp;
    }

    double bestRes = INT_MIN;

    for (int i = 0; i < n; i++) {
        for(int j = i + l; j < n && j < i + l + u; j++) {
            float calc = (float)(prefixCost[j] - prefixCost[i]) / (float)(prefixTimp[j] - prefixTimp[i]);
            if(calc > bestRes) {
                bestRes = calc;
            }
        }
    }

    cout << bestRes << endl;
}
#endif //EX5_STEFAN_H