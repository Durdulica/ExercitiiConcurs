#ifndef EX1_H
#define EX1_H
#include <iostream>
#include <cstring>
using namespace std;

//zaharel incearca s-o invete pe Eugenia informatica. Astazi a invatat-o programare dinamica si a nume a inceput cu problema celui mai lung
//subsir comun:dandu-se doua siruri, formate doare din litere mici, sa se det. cel mai lung subsir comun al celor doua siruri. Un subsir al
//unui sir este format din caractere ale sirului respectiv, in ordinea in care acestea apar in sir. Eugenia a inteles  rezolvarea problemei
//dar i-a pus urmatoarea inttrebare lui zaharel: cate subsiruri comune de lungime max. distincte exista pt. cele 2 siruri? Doua subsiruri
//sunt distincte daca exista c. p. un caracter in unul din ele care difera de caracterul din celalalt subsir de pe aceeasi pozitie. Ajutatil
//pe zaharel si det. restul impartirii nr. de subsiruri comune de lungime maxima distincte pt. doua siruri data, la nr. 666013

char a[501], b[501];
int n, m, smax = -1, rez = 0;

void citire() {
    cin.getline(a, 500);
    cin.getline(b, 500);
    n = (int)strlen(a);
    m = (int)strlen(b);
}

void subsir(int max, int indi, int indj) {
    for (int i = 0; i < n; i++) {
        max = 0;
        for(int j = 0; j <= m; j++) {
            if(a[i] == b[j]) {
                max++;
                i++;
            }
        }
        if(max > smax) {
            smax = max;
            max = 0;
            rez = 1;
        }else if(max == smax) {
            rez++;
        }
    }
}

void solve() {
    citire();
    subsir(0,0,0);
    cout << rez % 666013 << endl;
}
#endif //EX1_H
