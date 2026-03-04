#ifndef ROTATII_H
#define ROTATII_H
#include <iostream>
#include <fstream>
using namespace std;


void rezolvare() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/subiecte-olimpiada/rotatii/rotatii.in");
    //ofstream fout("rotatii.out");
    int C, N;
    fin >> C >> N;
    char tr[N + 1];
    fin >> tr;

    if(C == 1) {
        int rot[N + 1];
        int x = 0, y = 0;
        for(int i = 0; i < N; i++) {
            fin >> rot[i];
            if(tr[i] == 'N') {
                y = y + 1;
            }
            else if(tr[i] == 'S') {
                y = y - 1;
            }
            else if(tr[i] == 'E') {
                x = x + 1;
            }
            else if(tr[i] == 'V') {
                x = x - 1;
            }
            if(rot[i] == 90) {
                int aux = x;
                x = y;
                y = -aux;
            }
            else if(rot[i] == 180) {
                x = -x;
                y = -y;
            }
            else if(rot[i] == 270) {
                int aux = x;
                x = -y;
                y = aux;
            }
        }

        cout << x << " " << y << endl;  //fout
    }

    if(C == 2) {
        //todo
    }
}
#endif //ROTATII_H
