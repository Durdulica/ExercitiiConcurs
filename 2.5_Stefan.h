#ifndef INC_2_5_STEFAN_H
#define INC_2_5_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da un sir de n nr. intregi si o penalizare p. Pt. o subsecventa consec, val. ei este suma elem. minus p * lungime.
//Det. subsecventa cu val. maxima si afisati pozitiile si val. ei
ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(int *&v, int &n, int &p) {
    fin >> n >> p;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

void rezolvare() {
    int n, p;
    int *v = nullptr;
    citire(v, n, p);

    int sum[n * n] = {};
    for (int i = 0; i < n * n; i++) {

    }
}
#endif //INC_2_5_STEFAN_H