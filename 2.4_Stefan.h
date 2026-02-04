#ifndef INC_2_4_STEFAN_H
#define INC_2_4_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi si o val m. Se pot elim. cel mult m elem, iar restul elem. tb sa formeze
//o subsecventa consecutiva. Det suma maxima obtinuta

ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(int *&v, int &n, int &m) {
    fin >> n >> m;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

void rezolvare() {
    int n, m;
    int *v = nullptr;
    citire(v, n, m);

    int prefix[n + 1] = {};

    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    
}

#endif //INC_2_4_STEFAN_H