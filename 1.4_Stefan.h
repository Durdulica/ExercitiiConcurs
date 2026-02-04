#ifndef INC_1_4_STEFAB_H
#define INC_1_4_STEFAB_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(char *&word, int &lenght) {
    lenght = 0;
    int ch;
    int capacity = 500;
    word = new char[capacity];
    bool started = false;

    while((ch = fin.get()) != EOF) {
        if(ch >= 'a' && ch <= 'z') {
            started = true;
            word[lenght++] = (char)ch;
            break;
        }
    }

    if(!started) {
        delete []word;
        word = NULL;
        lenght = 0;
        return;
    }

    while((ch = fin.get()) != EOF) {
        if(ch < 'a' || ch > 'z') {
            break;
        }
        if(lenght + 1 > capacity) {
            cout << "word too big" << endl;
            delete []word;
            lenght = 0;
            word = NULL;
            return;
        }
        word[lenght++] = (char)ch;
    }
    word[lenght] = '\0';
}

void rezolvare() {
    char *first = nullptr;
    char *second = nullptr;
    char *letters = nullptr;
    int n, m, p;

    citire(first,n);
    citire(second,m);
    citire(letters,p);

    if(!first || !second || !letters) {
        cout << "Error on reading" << endl;
        delete []first;
        delete []second;
        delete []letters;
        return;
    }

    int r = n + 1;
    int c = m + 1;
    int total = r * c;
    int len[total] = {};
    int cnt[total] = {};

    for(int i = 0; i <= m; i++) {
        cnt[c * n + i] = 1;
    }

    for(int i = 0; i <= n; i++) {
        cnt[i * c + m] = 1;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            int poz = i * c + j;
            int dr = i * c + j + 1;
            int jos = (i + 1) * c + j;
            int diag = (i + 1) * c + j + 1;

            if(first[i] == second[j] && strchr(letters, first[i])) {
                len[poz] = len[diag] + 1;
                cnt[poz] = cnt[diag];
            }else {
                int best = max(len[dr], len[jos]);
                len[poz] = best;

                long long ways = 0;
                if(best == len[jos]) ways += cnt[jos];
                if(best == len[dr]) ways += cnt[dr];
                if(best == len[jos] && best == len[dr] && best == len[diag]) ways -= cnt[diag];

                ways %= 666013;
                if(ways < 0) ways += 666013;
                cnt[poz] = (int)ways;
            }
        }
    }

    delete []first;
    delete []second;
    delete []letters;
    cout << cnt[0] << endl;
}


#endif //INC_1_4_STEFAB_H