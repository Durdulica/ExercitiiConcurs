#ifndef INC_1_2_STEFAN_H
#define INC_1_2_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se dau 3 siruri formate din litere mici. Det. lungimea celui mai lung subsir comun tuturor celor 3.

ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

//{(x,y,z)={(1,0,0),(2,3,1),(1,2,0}
//,


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
            word = nullptr;
            length = 0;
            return;
        }
        word[length++] = (char)ch;
    }
    word[length] = '\0';
}

void rezolvare() {
    char *first;
    char *second;
    char *third;
    int n, m, p;
    citire(first,n);
    citire(second,m);
    citire(third,p);

    if(!first || !second || !third) {
        cout << "Error on reading";
        delete []first;
        delete []second;
        delete []third;
        return;
    }

    int r = n + 1;
    int c = m + 1;
    int h = p + 1;
    int total = r * c * h;
    long int len[total] =  {}, cnt[total] = {};

    for(int i = 0; i < total; i++) {
        cnt[i] = 1;
    }

    for(int i  = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            for(int k = p - 1; k >= 0; k--) {
                int poz = i * j * m + p;
                int jos = (i + 1) * j * m + p;
                int dr = i * j * m + p + 1;
                int diag = (i + 1) * j * m + p + 1;

                if(first[i] == second[j] == third[k]) {
                    len[poz] = len[diag] + 1;
                    cnt[poz] = cnt[diag];
                    cout << "yes";
                }else {
                    int best = max(len[jos], len[dr]);
                    len[poz] = best;

                    long long ways  = 0;
                    if(len[jos] == best) ways += cnt[jos];
                    if(len[dr] == best) ways += cnt[dr];
                    if(len[dr] == best && len[jos] == best && len[diag] == best) ways -= cnt[diag];

                    ways %= 666013;
                    if(ways < 0) ways += 666013;
                    cnt[poz] = (int)ways;
                }
            }
        }
    }

    delete []first;
    delete []second;
    delete []third;
    cout << endl << len[0] << endl;
}
#endif //INC_1_2_STEFAN_H