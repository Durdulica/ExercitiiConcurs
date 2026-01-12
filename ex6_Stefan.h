#ifndef EX6_STEFAN_H
#define EX6_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//Gigel a primit un joc cu cutii pe care erau scrise nr. intregi strict pozitive. El s-a gandit intr-o zi sa construiasca un
//triunghi de cutii astfel: o cutie este asezata peste doua cutii, care sunt asezate peste 3 cutii... care sunt asezate pe
//n <= 18 cutii(deci fiecare cutie se sprijina pe alte doua). Dar Gigel nu se opreste aici, ci vrea ca nr. din fiecare cutie
//din triunghiul sau(mai putin ultima linie) sa fie egal cu suma nr. din cele 2 cutii de dedesupt. Scrieti un program care
//determina daca Gigel poate construi un triunghi de latura n, in care suma nr. de pe toate sutiile sa fie s < 1000000,
// stiind ca poate folosi oricate cutii cu orice nr. in ele. Se va citii n si s. Se vor afisa nr. de pe cutiile din triunghi,




void rezolvare(){
    int n, s;
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

    fin >> n >> s;
    
    int mat[n][100] = {}; ///???

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {

            mat[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
#endif //EX6_STEFAN_H
