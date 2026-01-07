#ifndef EX3_STEFAN_H
#define EX3_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//Gigel are un sir de n <= 50000 nr. intregi din intervalul [-30000, 30000]. O secventa este un subsir de nr. care apar
//pe pozitii conesc. in sirul initial. Gigel a definit baza unei secvente ca fiind minimul valorilor elem. din secventa respectiva
//Fiind da un nr. nat. k det. o secventa de lungime cel putin k cu baza maxima. Sa se afis. poz. de inceput si de sfarsit a secventei
//de lungime cel putin k cu baza max. si valoarea maxima a bazei

int n, k;
int v[50000];

void citire(){
     ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
     fin >> n >> k;
     for(int i = 0; i < n; i++) {
          fin >> v[i];
     }
}

void rezolvare() {
     citire();

     int bestL = 0, bestR = 0, maxBase = INT_MIN;

     for(int i = 0; i <= n - k; i++) {
          int minim = INT_MAX;
          for(int j = i; j < i + k; j++) {
               minim = min(minim, v[j]);
          }
          if(minim > maxBase) {
               maxBase = minim;
               bestL = i;
               bestR = i + k - 1;
          }
     }

     cout << bestL + 1 << " " << bestR + 1 << " " << maxBase << endl;
}

#endif //EX3_STEFAN_H