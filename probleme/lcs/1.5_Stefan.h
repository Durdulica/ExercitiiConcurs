#ifndef INC_1_5_STEFAN_H
#define INC_1_5_STEFAN_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//sa dau 2 siruri si pt. fiecare litera un scor pozitiv. Un subsir comun are sorul suma scorurilor literelor. Det. scorul
//maxim al unui subsir comun si nr. de subsiruri distincte care ating scorul maxim.

void rezolvare() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    char first[100], second[100];
    int score[26] = {}, m , n;
    fin.getline(first, 100);
    fin.getline(second, 100);
    n = strlen(first);
    m = strlen(second);
    for(int i = 0; i < 26; i++) {
        fin >> score[i];
    }

    int r = n + 1;
    int c = m + 1;
    int total = c * r;
    int len[total] = {}, cnt[total] = {}, sum[total] = {};

    for(int i = 0; i <= m; i++) {
        cnt[n * c + i] = 1;
    }
    for(int i = 0; i <= n; i++) {
        cnt[i * c + m] = 1;
    }

    for(int i = n - 1;  i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            int poz = i * c + j;
            int dr = i * c + j + 1;
            int jos = (i + 1) * c + j;
            int diag = (i + 1) * c + j + 1;

            if(first[i] == second[j]) {
                len[poz] = len[diag] + 1;
                // cnt[poz] = cnt[diag];
                sum[poz] = sum[diag] + score[(int)first[i] - (int)'a'];
            }else {
                int best = max(len[dr], len[jos]);
                len[poz] = best;

                long long ways = 0;
                if(len[dr] == best) {
                    // ways += cnt[dr];
                    sum[poz] += sum[dr];
                }
                if(len[jos] == best) {
                    // ways += cnt[jos];
                    sum[poz] += sum[jos];
                }
                if(len[dr] == best && len[jos] == best && len[diag] == best) {
                    // ways -= cnt[diag];
                    sum[poz] -= sum[diag];
                }

                // ways %= 666013;
                // if(ways < 0) ways += 666013;
                // cnt[poz] = (int)ways;
            }
        }
    }

    int ct = 0, max = 0;
    for(int i = 0; i < total; i++) {
        if(sum[i] > max) {
            max = sum[i];
            ct = 1;
        }else if(max == sum[i]) {
            ct++;
        }
    }
    cout << sum[0] << " " << ct << endl;
}
#endif //INC_1_5_STEFAN_H
