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


int minSum(int n) {
    int sum = 0;
    for(int i = 1, ct = n; i <= n; i++, ct--) {
        sum += ct * i;
    }
    return sum;
}

int n, s;
bool found = false;

int combinari(int i) {
    if(i < 0 || i > n) return 0;

    if(i == 0 || i == n) return 1;
    if(i > n/2) {
        i = n - i;
    }
    int result = 1;
    for(int j = 1; j <=i; j++) {
        result = result * (n - j + 1)/j;
    }
    return result;
}

void back(int *c, int *base, int row, int currentSum) {
    if(found) return;

    if(row == n + 1) {
        if(currentSum == s) {
            found = true;
        }
        return;
    }

    int minSumRest = 0;

    for(int i = row + 1; i <= n; i++) {
        minSumRest += c[i];
    }

    for(int i = 1;;i++) {
        int newSum = currentSum + c[row]*i;
        if(newSum + minSumRest > s || i > s/n) {
            break;
        }

        base[row] = i;
        back(c, base, row + 1, newSum);
        if(found) return;
    }
}

void rezolvare(){
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

    fin >> n >> s;

    if(minSum(n) > s) {
        cout << "sum to little or number of rows to big" << endl;
        return;
    }
    int c[n + 1] = {}, base[n + 1] = {};
    for(int i = 1; i <= n; i++) {
        c[i] = combinari(i);
    }

    back(c, base, 1, 0);

    if(!found) {
        cout << "impossible" << endl;
    }else {
        int triunghi[n + 1][n + 1] = {};
        for(int i = 1; i <= n; i++) {
            triunghi[n][i] = base[i];
        }

        for(int i = n - 1; i > 0; i--) {
            for(int j = 1; j <= i; j++) {
                triunghi[i][j] = triunghi[i + 1][j] + triunghi[i + 1][j + 1];
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(triunghi[i][j]) {
                    cout << triunghi[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
}
#endif //EX6_STEFAN_H