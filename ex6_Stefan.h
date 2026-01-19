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


int minSum(int n) { //calculam suma minima pe care o poate avea triunghiul
    int sum = 0;    //(adica toate elem. de pe ultima linie sunt 1)
    for(int i = 1, ct = n; i <= n; i++, ct--) {
        sum += ct * i;
    }
    return sum;
}

int n, s;
bool found = false;

int combinari(int i) {      //algorimul de calculare al combinarilor de n luate cate i
    if(i < 0 || i > n) return 0;    //folosit pentru a calcula valoarea minima a unui elem. de pe fiecare linie

    if(i == 0 || i == n) return 1;
    if(i > n/2) {
        i = n - i;
    }
    int result = 1;
    for(int j = 1; j <= i; j++) {
        result = result * (n - j + 1)/j;    //simplificam n! si (n-k)! din formula pt. a ajunge la ecuatie
    }
    return result;
}

void back(int *c, int *base, int row, int currentSum) {     //incercam sa calculam direct suma, fara construirea matricei
    if(found) return;   //ne oprim daca avem o solutie

    if(row == n + 1) {  //daca am ajuns cu parcurgerea la ultimul rand, ne oprim
        if(currentSum == s) {   //verificam daca am gasit o solutie
            found = true;
        }
        return;
    }

    int minSumRest = 0;     //valoarea care ne mai trebuie pentru a ajunge la s

    for(int i = row + 1; i <= n; i++) {
        minSumRest += c[i];
    }

    for(int i = 1;;i++) {       //construim recursiv ultima linie prin backtracking
        int newSum = currentSum + c[row]*i;     //calculam o noua suma, la care adaugam elem. min. de pe linia pe care ne aflam *i
        if(newSum + minSumRest > s) {    //daca suma noua + min pana la s este prea mare, ne oprim
            break;                                 //todo: aici cred ca imi lipseste ceva
        }

        base[row] = i;          //am gasit un elem. pentru ultima linie
        back(c, base, row + 1, newSum);     //continuam cautarea pentru urmatorul elem. recursiv
        if(found) return;   //daca am gasit o solutie ne oprim, altfel cautam alt elem. pentru aceasta pozitie
    }
}

void rezolvare(){
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

    fin >> n >> s; //citirea

    if(minSum(n) > s) {     //verificam daca este matematic posibil sa construim triunghiul
        cout << "sum to little or number of rows to big" << endl;
        return;
    }
    int c[n + 1] = {};      //vector de combinari
    int base[n + 1] = {};   //vector pe care il populam cu ultima linie a triunghiului
    for(int i = 1; i <= n; i++) {
        c[i] = combinari(i);    //se populeaza cu elem. min. de pe fiecare rand
    }

    back(c, base, 1, 0);

    if(!found) {
        cout << "impossible" << endl;       //nu am gasit o solutie
    }else {
        int triunghi[n + 1][n + 1] = {};
        for(int i = 1; i <= n; i++) {
            triunghi[n][i] = base[i];       //adaugam linia gasita din triunghi
        }

        for(int i = n - 1; i > 0; i--) {
            for(int j = 1; j <= i; j++) {
                triunghi[i][j] = triunghi[i + 1][j] + triunghi[i + 1][j + 1];   //construim triunghiul in functie de elem. precedente
            }
        }

        for(int i = 1; i <= n; i++) {       //afisarea
            for(int j = 1; j <= i; j++) {
                cout << triunghi[i][j] << " ";
            }
            cout << endl;
        }
    }
}
#endif //EX6_STEFAN_H