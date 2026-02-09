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
    int n, m, rez = INT_MIN;
    int *v = nullptr;
    citire(v, n, m);

    for(int l = 0; l < n; l++) {
        int elems[n] = {};
        int sumTot = 0, cnt = 0;

        for(int r = l; r < n; r++) {
            sumTot += v[r];
            elems[cnt++] = v[r];

            int tmp[n];

            for(int i = 0; i < cnt; i++) {
                tmp[i] = elems[i];
            }

            for(int i = 0; i < cnt; i++) {
                for(int j = i + 1; j < cnt; j++) {
                    if(tmp[i] > tmp[j]) {
                        int aux = tmp[i];
                        tmp[i] = tmp[j];
                        tmp[j] = aux;
                    }
                }
            }

            int removed = 0, ind = 0;
            for(int i = 0; i < cnt && ind < m; i++) {
                if(tmp[i] < 0) {
                    ind++;
                    removed += tmp[i];
                }
            }

            int candidate = sumTot - removed;
            if(candidate > rez) {
                rez = candidate;
            }
        }
    }
    cout << rez << endl;
}

#endif //INC_2_4_STEFAN_H