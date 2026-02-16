#ifndef INC_15_1_STEFAN_H
#define INC_15_1_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//sunteti antrenorul ciclistului Adirem Onamihs. In curand va avea loc o cursa care contine n intersectii si m drumuri
//bidirectionale intre aceste intersectii. Pt. fiecare drum se cunoaste nr. de min. necesare pt. parcurgerea lui. La fiecare
//intersectie ciclistul este obligat sa serveasca o bautura energizanta si racoritoare. Bautura diera de la intersectie la
//intersectie si se cunoaste deja nr. de calorii ale fiecarei bauturi.
//Urmeaza sa intocmiti un plan special pentru a-l antrena pe Adirem. Doriti ca durata traseului pe care il alege Adirem sa
//aiba exact T minute, insa nu doriti sa ii planuiti traseul. Ii veti preciza lui Adirem intersectia unde isi incepe traseul
//si intersectia unde se termina. Pt. a-l face sa mearga exact T minute ii veti interzice trecerea prin anumite intersectii,
//sub pretextul ca val. calorica a bauturii servite in intersectia respectiva nu este benefica pentru antrenamentul lui.
//Astfel, ii veti preciza o limita inferioara si una superioara pt. nr. de calorii ale bauturilor pe care el are voie sa le
//bea. Adirem nu va trece decat prin intersectiile unde se serveste o bautura cu valoare calorica intre limitele date.

//scrieti un program care sa calc. cele 4 var. din antrenamentul lui Adirem: intersectia de start, de finish, val. calorica
//minima si maxima pe care poate sa o consume a. i. drumul cel mai scurt dintre cele 2 intersectii(care sa respecte restrictiile)
//sa dureze exact T minute.

/// Date de intrare
// 3 nr. N, M si T. Urmatoarele N linii contin cate un nr.(val. calorice ale bauturilor din intersectii)
//Urmatoarele M linii contin cate un triplet de nr: doua intersectii(nr intre 1 si N) si durata drumului dintre ele

ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
int N, M, T;
int valCal[101] = {};       //valoarea calorica a unei intersectii
int num[101], renum[101]; //numerotare, renumerotare
int mat[101][101] = {};

void citire() {
    fin >> N >> M >> T;
    if(N < 1 || M < 1 || T < 1 || N > 100 || M > 4950 || T > 1000000) {
        cout << "Invalid input" << endl;
        return;
    }
    for(int i = 1; i <= N; i++) {
        fin >> valCal[i];
        renum[i] = num[i] = i;
    }

    for(int i = 1; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(valCal[i] > valCal[j]) {
                int aux = valCal[i];
                valCal[i] = valCal[j];
                valCal[j] = aux;
                aux = renum[i];
                renum[i] = renum[j];
                renum[j] = aux;
            }
        }
    }
    for(int i = 1; i <= M; i++) {
        int s, f, t;
        fin >> s >> f >> t;
        if(s < 1 || f < 1 || t < 1 || s > 100 || f > 100) {
            cout << "Invalid input" << endl;
            return;
        }

        mat[renum[s]][renum[f]] = mat[renum[f]][renum[s]] = t;
    }
}

void rezolvare() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(mat[i][j]){}
        }
    }
}
#endif //INC_15_1_STEFAN_H