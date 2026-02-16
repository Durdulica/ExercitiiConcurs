#ifndef RECAPITULARE_EX1_H
#define RECAPITULARE_EX1_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

void rezolvare(char *first, char *second){
    int n = strlen(first);
    int m = strlen(second);

    int len[n + 1][m + 1];
    int cnt[n + 1][m + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            len[i][j] = 0;
            cnt[i][j] = 0;
        }
    }

    for(int i = 0; i <= n; i++) {
        cnt[i][m] = 1;
    }
    for(int j = 0; j <= m; j++) {
        cnt[n][j] = 1;
    }



    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(first[i] == second[j]) {
                len[i][j] = len[i + 1][j + 1] + 1;
                cnt[i][j] = cnt[i + 1][j + 1];
            }else {
                int best = max(len[i + 1][j], len[i][j + 1]);
                len[i][j] = best;
                long long ways = 0;
                if(best == len[i + 1][j]) ways += cnt[i + 1][j];
                if(best == len[i][j + 1]) ways += cnt[i][j + 1];
                if(best == len[i + 1][j] && best == len[i][j + 1] && best == len[i + 1][j + 1]) {
                    ways -= cnt[i + 1][j + 1];
                }
                ways %= 666013;
                if(ways < 0) ways += 666013;
                cnt[i][j] = (int)ways;
            }
        }
    }

    cout << cnt[0][0] << endl;
}
#endif //RECAPITULARE_EX1_H