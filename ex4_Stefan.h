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
inline int n, m, pct1 = 0, pct2 = 0, bestL = -1, bestC = - 1, turn = 0;

void citire() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> mat[i][j];
        }
    }
}

void rezolvare() {

}

#endif //EX4_STEFAN_H