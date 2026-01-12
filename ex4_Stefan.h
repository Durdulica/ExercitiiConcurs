#ifndef EX4_STEFAN_H
#define EX4_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;


//-fie o matrice cu nr. intregi cuprinse in intervalul [-1000,1000], cu n linii si m coloane
//-liniile sunt numerotate de la 1 la n si coloanele de la 1 la m
//-fiecare jucator muta alternativ un jeton plasat pe un elem. din matr.
//-o mutare consta in plasarea jetonului pe alta pozitie si adaugarea valorii din matr. de pe poz. resp. la scorul jucatorului
//care a facut mutarea; odata plasat jetonul pe pozitie, jucatorul urmator poate sa mute jetonul doar pe o alta pozitie din dreptunghiul
//format de coltul stanga-sus si pozitia curenta a matricei
//-jocul se termina cand un jucator ajunge cu jetonul in coltul de stanga-sus al matr.
//-la inceputul jocului, ambii jucatori au scor 0, iar jucatorul care incepe alege pozitia initiala a jetonului
//Presupunand ca fiecare din cei doi jucatori joaca optim si ca jucatorul 1 incepe jocul, det. pozitia initiala a jetonului, a. i.
//diferenta de scor dintre primul jucator si al doilea sa fie maxima. Sa se afis. diferenta maxima de scor dintre jucatori si linia si
//coloana unde se va plasa jetonul la inceputul jocului

int mat[1001][1001];
inline int n, m, bestL = -1, bestC = -1, bestScore = INT_MIN, turn;

void citire() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> mat[i][j];
        }
    }
}

//0 0 0 0
//0 0 17 0
//0 5 3 18
//0 0 0 0

int maxMat(int lin, int col, int &indi, int &indj) {
    int maxim = INT_MIN;
    for (int i = 1; i <= lin; i++) {
        for (int j = 1; j <= col; j++) {
            if(mat[i][j] > maxim) {
                maxim = mat[i][j];
            }
        }
    }
    return maxim;
}

void rezolvare() {
    for(int i = n; i > 0; i--) {
        for(int j = m; j > 0; j--) {
            int pct1 = mat[i][j], pct2 = 0, a = i, b = j, indi = -1, indj = -1;
            while(a > 0 && b > 0) {
                int maxim = maxMat(a, b, indi, indj);
                if(turn) {
                    pct2 += maxim;
                    turn = 0;
                }else {
                    pct1 += maxim;
                    turn = 1;
                }
                a = indi, b = indj;
            }
        }
    }
}

#endif //EX4_STEFAN_H