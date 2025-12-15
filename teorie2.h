#ifndef TEORIE2_H
#define TEORIE2_H
#include <iostream>
using namespace std;
//astazi Bronzarel a rezolvat seria de problemw "Secventa X". Zaharel vrea sa-l testeze pe Bronzarel cu o noua problema care nu este
//pe info-arena si ii spune: "Iti dau un sir de n <= 5000 nr. intregi si vreau sa-mi spui care este cel mai scurt subsir crescator maximal. La
//probleme cu secvente te-ai descurcat, vei reusi si la subsiruri?".
//spune ca un subsir B = (ai1, ai2,...,aik) este cresc. maximal daca ai1<=ai2<=...<=aik si nu exista nici un x a. i.: sa existe j<K, ij<x<ij+1
//si aij <= ax <= aij+1 sau 1<=x<i1 si ax<=ai1 sau ik<x<n si aik<=ak.

inline int n, a[5001], bst[5001], t[5001], rez = 0, poz;
char ok[5001];

void citire(int&min) {
    cin >> n;
    min = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(min <= a[i]) continue;
        ok[i] = 1;
        min = a[i];
    }
}

void solve() {
    int min;
    citire(min);
    for(int i = n - 1; i >= 0; i--) {
        bst[i] = min = INT_MAX;
        t[i] = -1;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[i]) continue;
            if(min > a[j] && (bst[i] > bst[j] + 1 || (bst[i] == bst[j] + 1 && a[j] < a[t[i]]))) {
                bst[i] = bst[j] + 1;
                t[i] = j;
            }
            if(min > a[j]) min = a[j];
        }

        if(bst[i] == INT_MAX) {
            bst[i] = 1;
            t[i] = i;
        }
        if(ok[i] && (rez > bst[i] || (rez == bst[i] && a[i] < a[poz]))) {
            rez = bst[i];
            poz = i;
        }
    }
    cout << rez << endl;
    int i;
    for(i = poz; i != t[i]; i = t[i]) {
        cout << i + 1 << " ";
    }
    cout << i + 1 << endl;
}
#endif //TEORIE2_H