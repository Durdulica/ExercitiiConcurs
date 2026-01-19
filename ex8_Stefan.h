#ifndef EX8_STEFAN_H
#define EX8_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//zaharel sa dus in vizita la bunici impreuna cu eugenia. Ferma bunicilor este de forma circulara, iar acolo cresc N<=10000 gaini.
//Ferma a fost impartita in N sectoare, numerotate de la 1 la N, a. i. oricare doua sectoare avand numere consecutive sunt adiacente.
//In plus, primul si ultimul sector sunt adiacente. In fiecare sector se afla cate o gaina, iar aceasta depune oua in fiecare zi.
//Bunicii stiu pt. fiecare gaina care este productivitatea ei, adica un nr. care repr. diferenta dintre consumul gainii si cat
//produce. Zaharel si cu Eugenia strang de K<=1000 ori pe zi oua de la gaini astfel: la fiecare strangere cei doi aleg o secventa
//(un sir de sectoare adiacente) formata din cel putin un sector, care contine numai gaini de la care nu s-au luat oua in acea zi.
//Cunoscand productivitatea fiecarei gaini si nr. de strangeri dintr-o zi, ajutati-i pe Zaharel si Eugenia sa stranga oua a. i. suma
//productivitatilor gainilor de la care au strans oua sa fie maxima.

int n, k;

void citire(int *&prod){
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    if(!(fin >> n >> k)) return;
    if(n < 1 || n > 10000 || k < 1 || k > 1000) {
        cout << "impossible" << endl;
        return;
    }

    prod = new int[n];
    for(int i = 0; i < n; i++) {
        fin >> prod[i];
    }
}

void rezolvare(){
    int *prod = nullptr;
    citire(prod);
    int *prefix = new int[n];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + prod[i-1];
    }

    int bestSum = INT_MIN;
    int maxPrefix = INT_MIN;

    for(int i = 1; i <= n; i++) {
        if(prefix[n - i] > maxPrefix) {

        }
    }
    delete []prod;
}

#endif //EX8_STEFAN_H