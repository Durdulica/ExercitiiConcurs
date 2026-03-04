#ifndef ROTATII_H
#define ROTATII_H
#include <iostream>
#include <fstream>
using namespace std;

void assert_eq(int actualX, int actualY, int expectedX, int expectedY){
    if(actualX != expectedX) {
        if(actualY != expectedY) {
            cout << "Failed: expected " << expectedX << " " << expectedY
            << " but got " << actualX << " " << actualY << endl;
            return;
        }
        cout << "Failed: expected " << expectedX << " but got " << actualX << endl;
    }
    if(actualY != expectedY) {
        cout << "Failed: expected " << expectedY << " but got " << actualY << endl;
    }
}

void calc_pozitie(int cerinta, int numar_pasi, const char traseu[], const int rotatii[], int &rezultat_x, int &rezultat_y) {
    rezultat_x = 0;
    rezultat_y = 0;

    if (cerinta == 1) {
        for (int i = 0; i < numar_pasi; i++) {
            if (traseu[i] == 'N') {
                rezultat_y = rezultat_y + 1;
            } else if (traseu[i] == 'S') {
                rezultat_y = rezultat_y - 1;
            } else if (traseu[i] == 'E') {
                rezultat_x = rezultat_x + 1;
            } else if (traseu[i] == 'V') {
                rezultat_x = rezultat_x - 1;
            }

            if (rotatii[i] == 90) {
                int aux = rezultat_x;
                rezultat_x = rezultat_y;
                rezultat_y = -aux;
            } else if (rotatii[i] == 180) {
                rezultat_x = -rezultat_x;
                rezultat_y = -rezultat_y;
            } else if (rotatii[i] == 270) {
                int aux = rezultat_x;
                rezultat_x = -rezultat_y;
                rezultat_y = aux;
            }
        }
    }
    // cerinta == 2 este lasata nerezolvata, conform enuntului initial.
}

void rezolvare(int cerinta, int numar_pasi, char traseu[], int rotatii[], int asteptat_x = 0, int asteptat_y = 0) {
    int x_final = 0, y_final = 0;
    calc_pozitie(cerinta, numar_pasi, traseu, rotatii, x_final, y_final);

    if (asteptat_x != 0 || asteptat_y != 0) {
        assert_eq(x_final, y_final, asteptat_x, asteptat_y);
    } else {
        cout << x_final << " " << y_final << endl;
    }
}

void rezolvare() {
    // Citire din fisier folosind calea relativa in depozit.
    ifstream fin("subiecte-olimpiada/rotatii/rotatii.in");
    if (!fin.is_open()) {
        cerr << "Nu pot deschide fisierul subiecte-olimpiada/rotatii/rotatii.in" << endl;
        return;
    }

    int cerinta, numar_pasi;
    fin >> cerinta >> numar_pasi;

    char *traseu = new char[numar_pasi + 1];
    for (int i = 0; i < numar_pasi; i++) {
        char pas;
        fin >> pas;   // citeste urmatorul caracter (ignora spatiile)
        traseu[i] = pas;
    }
    traseu[numar_pasi] = '\0';

    int *rotatii = new int[numar_pasi];
    for (int i = 0; i < numar_pasi; i++) {
        fin >> rotatii[i];
    }

    int x_final = 0, y_final = 0;
    calc_pozitie(cerinta, numar_pasi, traseu, rotatii, x_final, y_final);
    cout << x_final << " " << y_final << endl;

    delete[] traseu;
    delete[] rotatii;
}


void testare1() {
    int cerinta = 1;
    const int numar_pasi = 4;
    char traseu[5] = "NNSV";
    int rotatii[numar_pasi] = {0,270,90,90};
    int asteptat_x = 2, asteptat_y = 2;
    rezolvare(cerinta, numar_pasi, traseu, rotatii, asteptat_x, asteptat_y);
}
#endif //ROTATII_H
