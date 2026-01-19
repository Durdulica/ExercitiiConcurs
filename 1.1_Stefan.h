#ifndef RECAPITULARE_EX1_H
#define RECAPITULARE_EX1_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//se dau 2 siruri formate din litere mici. Det. nr. de subsiruri comune distincte de lungime maxima.
ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
void citire(char *&word, int &length) {
    length = 0;
    int capacity = 500;
    word = new char[capacity];
    int ch;
    bool started = false;

    while((ch = fin.get()) != EOF) {
        if((ch >= 'a' && ch <= 'z')) {
            started = true;
            word[length++] = (char)ch;
            break;
        }
    }

    if(!started) {
        delete[] word;
        word = nullptr;
        length = 0;
        return;
    }

    while((ch = fin.get()) != EOF) {
        if(ch < 'a' || ch > 'z') {
            break;
        }
        if(length + 1 >= capacity) {
            cout << "word exceeded capacity" << endl;
            delete[] word;
            return;
        }
        word[length++] = (char)ch;
    }
    word[length] = '\0';
}

void rezolvare() {
    char *first = nullptr;
    char *second = nullptr;
    int n, m;

    citire1(first, n);
    citire1(second, m);

    if (!first || !second) {
        delete[] first;     //ne asiguram ca avem 2 cuvinte
        delete[] second;
        return;
    }

    int cols = m + 1;
    int rows = n + 1;
    int total = rows * cols;
    int *len = new int[total];      //dimensiunea secventei din pozitia i din primul cuvant si j din al doilea
    int *cnt = new int[total];      //cate elem sunt egale pe pozitia i din primul cuvant si j din al doilea

    for(int i = 0; i < total; i++) {
        len[i] = 0;         //initializam vectorii
        cnt[i] = 0;
    }

    for(int i = 0; i <= n; i++) {
        cnt[i * cols + m] = 1;      //marcam pozitiile la care se afla literele din primul cuvant
    }
    for(int i = 0; i <= m; i++) {
        cnt[n * cols + i] = 1;      //marcam pozitiile la care se afla literele din al doilea cuvant
    }

    for(int i = n - 1; i >= 0; i--) {       //parcurgere inversa pentru a avea calculate down, right si diag
        for(int j = m - 1; j >= 0; j--) {
            int idx = i * cols + j;
            int idxDown = (i + 1) * cols + j;       //calcularea indexilor
            int idxRight = i * cols + (j + 1);
            int idxDiag =  (i + 1) * cols + (j + 1);

            if(first[i] == second[j]) {
                len[idx] = len[idxDiag] + 1;        //daca dam de litere egale incrementam dim. cu 1
                cnt[idx] = cnt[idxDiag];            //si tinem minte diagonala
            }else {
                int l1 = len[idxDown];
                int l2 = len[idxRight];
                int best =  (l1 > l2) ? l1 : l2;    //cauteam cea mai mare solutie
                len[idx] = best;

                int ways = 0;           //calculam cate secvente apar pentru fiecare pozitie
                if(l1 == best) {
                    ways += cnt[idxDown];
                }
                if(l2 == best) {
                    ways += cnt[idxRight];
                }
                if(l1 == best && l2 == best && len[idxDiag] == best) {
                    ways -= cnt[idxDiag];
                }
                ways %= 666013;
                if(ways < 0) ways += 666013;
                cnt[idx] = ways;
            }
        }
    }


    cout << cnt[0] % 666013 << endl;

    delete[] len;
    delete[] cnt;
    delete[] first;
    delete[] second;
}
#endif //RECAPITULARE_EX1_H