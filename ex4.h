#ifndef EX4_H
#define EX4_H
#include <iostream>
#include <fstream>
#include <climits>
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

const int MAX_DIM = 1000;
const int NEG_INF = -2000000000;

int mat[MAX_DIM + 1][MAX_DIM + 1];
int diffVal[MAX_DIM + 1][MAX_DIM + 1];    // f(i,j): diferenta maxima pentru jucatorul care urmeaza la mutare
int prefixBest[MAX_DIM + 1][MAX_DIM + 1]; // maximul lui g(x,y) in prefixul (1,1)-(i,j)

inline int n, m;

static bool citire() {
    ifstream fin("file.in.txt");
    if (!fin.is_open()) {
        cerr << "Nu pot deschide fisierul de intrare.\n";
        return false;
    }

    fin >> n >> m;
    if (!fin || n <= 0 || n > MAX_DIM || m <= 0 || m > MAX_DIM) {
        cerr << "Dimensiuni invalide.\n";
        return false;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fin >> mat[i][j];
            if (!fin) {
                cerr << "Nu pot citi matricea.\n";
                return false;
            }
        }
    }

    return true;
}

void rezolvare() {
    if (!citire()) {
        return;
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            prefixBest[i][j] = NEG_INF;
            diffVal[i][j] = 0;
        }
    }

    int bestDiff = NEG_INF;
    int bestRow = 1;
    int bestCol = 1;

    // Algoritm pas cu pas:
    // 1) f(i,j) = diferenta maxima (P1 - P2) daca jetonul e in (i,j) si urmeaza sa mut.
    // 2) g(i,j) = mat[i][j] - f(i,j); atunci f(i,j) e maximul lui g pe dreptunghiul (1,1)-(i,j) fara (i,j).
    // 3) prefixBest tine maximul lui g pe prefix, pentru a calcula f(i,j) in O(1).
    for (int i = 1; i <= n; ++i) {
        int rowBest = NEG_INF; // maxim g pe prefixul de pe linia curenta
        for (int j = 1; j <= m; ++j) {
            // Pas 1: luam maximul lui g din celulele deja procesate (deasupra si stanga).
            int bestCandidate = prefixBest[i - 1][j];
            if (rowBest > bestCandidate) {
                bestCandidate = rowBest;
            }

            // Pas 2: f(i,j) = bestCandidate (sau 0 daca nu exista mutari).
            if (bestCandidate == NEG_INF) {
                diffVal[i][j] = 0;
            } else {
                diffVal[i][j] = bestCandidate;
            }

            // Pas 3: calculam g(i,j) pentru mutari viitoare.
            int gValue = mat[i][j] - diffVal[i][j];
            if (gValue > rowBest) {
                rowBest = gValue;
            }

            // Pas 4: actualizam maximul de prefix pentru (1,1)-(i,j).
            int curPref = prefixBest[i - 1][j];
            if (prefixBest[i][j - 1] > curPref) {
                curPref = prefixBest[i][j - 1];
            }
            if (gValue > curPref) {
                curPref = gValue;
            }
            prefixBest[i][j] = curPref;

            // Pas 5: retinem cea mai buna plasare initiala (dif. maxima, iar la egalitate cea mai din stanga sus).
            if (diffVal[i][j] > bestDiff ||
                (diffVal[i][j] == bestDiff && (i < bestRow || (i == bestRow && j < bestCol)))) {
                bestDiff = diffVal[i][j];
                bestRow = i;
                bestCol = j;
            }
        }
    }

    cout << bestDiff << " " << bestRow << " " << bestCol << "\n";
}

#endif //EX4_H
