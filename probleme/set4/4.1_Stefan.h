#ifndef INC_4_1_STEFAN_H
#define INC_4_1_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se da o matr. n x m cu val. intregi. Jetonul porneste in (n,m) si la fiecare mutare se poate merge in sus sau in stanga cu
//exact 1 pas. Jucatorii muta alternativ, adunand val. celulei pe care ajung. Det. dif. max. (p1-p2) daca ambii joaca optim

void citire(int mat[101][101], int &n, int &m) {
    ifstream fin("file.in.txt");
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> mat[i][j];
        }
    }
}

struct result {
    int diff = INT_MIN;
    int row = -1;
    int col = -1;
};

result *rezolvare(int mat[101][101], int n, int m) {
    int diffVal[101][101] = {};
    int prefixBest[101][101];
    // citire(mat,n,m);

    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            prefixBest[i][j] = INT_MIN;
        }
    }

    int bestDiff = mat[1][1];
    int bestRow = 0, bestCol = 0;

    for (int i = 1; i <= n; i++) {
        int rowBest = INT_MIN;
        for (int j = 1; j <= m; j++) {
            int bestCand = prefixBest[i - 1][j];
            if(rowBest > bestCand) {
                bestCand = rowBest;
            }

            if(bestCand == INT_MIN) {
                diffVal[i][j] = 0;
            }else {
                diffVal[i][j] = bestCand;
            }

            int gVal = mat[i][j] - diffVal[i][j];
            if(gVal > rowBest) {
                rowBest = gVal;
            }

            int curPref = prefixBest[i - 1][j];
            if(prefixBest[i][j - 1] > curPref) {
                curPref = prefixBest[i][j - 1];
            }
            if(gVal > curPref) {
                curPref = gVal;
            }
            prefixBest[i][j] = curPref;
            if(-1 <= j - i <= 1 && diffVal[i][j] > bestDiff || (diffVal[i][j] == bestDiff &&
                (i < bestRow || i == bestRow && j < bestCol))) {
                bestDiff = diffVal[i][j];
                bestRow = i;
                bestCol = j;
            }
        }
    }
    result *rez = new result();
    rez->diff = bestDiff;
    rez->row = bestRow;
    rez->col = bestCol;
    return rez;
}

void assert_eq(result actual, result expected) {
    if(actual.diff != expected.diff || actual.row != expected.row || actual.col != expected.col) {
        cout << "Failed: expected " << expected.diff << " " << expected.row << " " << expected.col << " but got "
        << actual.diff << " " << actual.row << " " << actual.col << endl;
    }else {
        cout << "Passed" << endl;
    }
}

void test1() {
    int mat[101][101] = {};
    mat[1][1] =1; mat[1][2] = 2; mat[2][1] = 3; mat[2][2] = 4;
    int n = 2, m = 2;
    result *rez = rezolvare(mat, n, m);
    result expected;
    expected.diff = 2;
    expected.row = 2;
    expected.col = 2;

    assert_eq(*rez, expected);
}
#endif //INC_4_1_STEFAN_H