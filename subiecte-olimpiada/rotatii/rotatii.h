#ifndef ROTATII_H
#define ROTATII_H
#include <iostream>
#include <fstream>
using namespace std;

void assert_eq(int actualX, int actualY, int expectedX, int expectedY){
    if(actualX != expectedX) {
        if(actualY != expectedY) {
            cout << "Failed: expected " << expectedX << " " << expectedY
            << " but got " << actualX << " " << actualY << endl;
            return;
        }
        cout << "Failed: expected " << expectedX << " but got " << actualX << endl;
    }
    if(actualY != expectedY) {
        cout << "Failed: expected " << expectedY << " but got " << actualY << endl;
    }
}

void rezolvare(int C, int N, char tr[], int rot[], int expectedX = 0, int expectedY = 0) {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/subiecte-olimpiada/rotatii/rotatii.in");
    //ofstream fout("rotatii.out");
    /*int C, N;
    fin >> C >> N;
    char tr[N + 1];
    fin >> tr;*/

    if(C == 1) {
        // int rot[N + 1];
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
        assert_eq(x,y,expectedX,expectedY);
        //cout << x << " " << y << endl;  fout
    }

    if(C == 2) {
        //todo
    }
}


void testare1() {
    int C = 1;
    int N = 4;
    char tr[6] = "NNSV\0";
    int rot[N] = {0,270,90,90};
    int expectedX = 2, expectedY = 2;
    rezolvare(C, N, tr, rot, expectedX, expectedY);
}
#endif //ROTATII_H
