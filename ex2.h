#ifndef EX2_H
#define EX2_H
#include <iostream>
#include <fstream>
using namespace std;

//gigel s-a decis sa devina olimpic la info. La ora de info, profesoara lui i-a dat sa rezolve problema secventei de suma maxima. El
//primeste un sir de n <= 50000 nr. intregi din intervalul [-25000,25000], iar tu tb. sa gasesti o secventa (adica un subsir de nr.
//care apar pe pozitii consecutive in sirul initial)  de lungime cel putin k cu suma elem. maxima. Sa se afis. poz. de inceput si de
//sfarsit a secventei de suma max. de lungime cel putin k si suma secventei.

int n, k;
int v[50001];
void citire() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
}

void rezolvare() {
    citire();
    int sume[50001] = {};
    int lungime[50001] = {};
    for(int i = 0; i <= n - k; i++) {
        int j = i;
        while(j < i + k) {
            sume[i] += v[j];
            lungime[i] = lungime[i] + 1;
            j++;
        }
        int aux = sume[i];
        for(;j < n; j++) {
            aux += v[j];
            if(aux > sume[i]) {
                sume[i] = aux;
                lungime[i] = j - i;
            }
        }
    }

    int smax = INT_MIN, index = -1;
    for(int i = 0; i < n - k; i++) {
        if(sume[i] > smax) {
            smax = sume[i];
            index = i;
        }
    }

    cout << index + 1<< " " << index + lungime[index] + 1 << " " << sume[index] << endl;
}



#endif //EX2_H