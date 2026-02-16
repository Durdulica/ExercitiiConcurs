#ifndef INC_1_3_STEFAN_H
#define INC_1_3_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se dau 2 siruri formate din litere mici. Det. lungimea LCS si nr. de subsiruri comune distincte de aceasta lungime

ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");

void citire(char *&word, int &lenght) {
    lenght = 0;
    int capacity = 200;
    word = new char[capacity];
    int ch;
    bool started = false;

    while ((ch = fin.get()) != EOF) {
        if(ch >= 'a' && ch <= 'z') {
            started = true;
            word[lenght++] = (char)ch;
            break;
        }
    }

    if(!started) {
        delete []word;
        word = nullptr;
        lenght = 0;
        return;
    }

    while ((ch = fin.get()) != EOF) {
        if(ch < 'a' || ch > 'z') {
            break;
        }

        if(lenght + 1 > capacity) {
            cout << "word exceeded capacity" << endl;
            delete []word;
            word = nullptr;
            lenght = 0;
            return;
        }
        word[lenght++] = (char)ch;
    }
    word[lenght] = '\0';
}

void rezolvare() {
    char *first = nullptr;
    char *second = nullptr;
    int n, m;

    citire(first, n);
    citire(second, m);

    if(!first || !second) {
        cout << "Error on reading" << endl;
        delete []first;
        delete []second;
        return;
    }

    int r = n + 1;
    int c = m + 1;
    int total = r * c;

    int len[total] = {};
    int cnt[total] = {};

    for(int i = 0; i <= n; i++) {
        cnt[i * c + m] = 1;
    }

    for(int i = 0; i <= m; i++) {
        cnt[c * n + i] = 1;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            int poz = i * c + j;
            int jos = (i + 1) * c + j;
            int dr =  i * c + j + 1;
            int diag = (i + 1) * c + j + 1;

            if(first[i] == second[j]) {
                len[poz] = len[diag] + 1;
                cnt[poz] = cnt[diag];
            }else {
                int best = max(len[jos], len[dr]);
                len[poz] = best;

                long long ways = 0;
                if(len[jos] == best) ways += cnt[jos];
                if(len[dr] == best) ways += cnt[dr];
                if(len[jos] == best && len[dr] == best && len[diag] == best) ways -= cnt[diag];

                ways %= 666013;
                if(ways < 0) ways += 666013;
                cnt[poz] = ways;
            }
        }
    }

    cout << len[0] << " " << cnt[0] << endl;
}
#endif //INC_1_3_STEFAN_H
