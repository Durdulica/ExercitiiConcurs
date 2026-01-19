#ifndef RECAPITULARE_EX1_H
#define RECAPITULARE_EX1_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//se dau 2 siruri formate din litere mici. Det. nr. de subsiruri comune distincte de lungime maxima.
ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
void citire1(char *&word, int &length) {
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

void rezolvare1() {
    char *first = nullptr;
    char *second = nullptr;
    int n, m;

    citire1(first, n);
    citire1(second, m);

    if (!first || !second) {
        delete[] first;

        delete[] second;
        return;
    }

    int cols = m + 1;
    int rows = n + 1;
    int total = rows * cols;
    int *len = new int[total];
    int *cnt = new int[total];

    for(int i = 0; i < total; i++) {
        len[i] = 0;
        cnt[i] = 0;
    }

    for(int i = 0; i <= n; i++) {
        cnt[i * cols + m] = 1;
    }
    for(int i = 0; i <= m; i++) {
        cnt[n * cols + i] = 1;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            int idx = i * cols + j;
            int idxDown = (i + 1) * cols + j;
            int idxRight = i * cols + (j + 1);
            int idxDiag =  (i + 1) * cols + (j + 1);

            if(first[i] == second[j]) {
                len[idx] = len[idxDiag] + 1;
                cnt[idx] = cnt[idxDiag];
            }else {
                int l1 = len[idxDown];
                int l2 = len[idxRight];
                int best =  (l1 > l2) ? l1 : l2;
                len[idx] = best;

                int ways = 0;
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

    for(int i = 0; i < total; i++) {
         cout << len[i] << " ";
    }

    // cout << cnt[0] % 666013 << endl;

    // int res = 0, maxim = INT_MIN;
    // for(int i = 0; i < total; i++) {
    //     if(cnt[i] >= 2) {
    //         int index = 1;
    //         while(cnt[i+1] >= 2) {
    //             i++;
    //             index++;
    //         }
    //         if(index > maxim) {
    //             maxim = index;
    //             res = 1;
    //         }else if(index == maxim) {
    //             res++;
    //         }
    //     }
    // }
    // cout << res << endl;

    delete[] len;
    delete[] cnt;
    delete[] first;
    delete[] second;
}
#endif //RECAPITULARE_EX1_H