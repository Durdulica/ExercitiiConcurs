#ifndef EX3_H
#define EX3_H
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

// Gigel are un sir de n <= 50000 nr. intregi din intervalul [-30000, 30000]. O secventa este un subsir de nr. care apar
// pe pozitii consec. in sirul initial. Gigel a definit baza unei secvente ca fiind minimul valorilor elem. din secventa respectiva.
// Fiind dat un nr. nat. k det. o secventa de lungime cel putin k cu baza maxima. Sa se afis. poz. de inceput si de sfarsit a secventei
// de lungime cel putin k cu baza max. si valoarea maxima a bazei

const int MAX_N = 50000;

int n, k;
int values[MAX_N];
int leftLess[MAX_N];
int rightLess[MAX_N];
int idxStack[MAX_N];

static bool citire() {
    ifstream fin("file.in.txt");
    if (!fin.is_open()) {
        cerr << "Nu pot deschide fisierul de intrare.\n";
        return false;
    }

    fin >> n >> k;
    if (!fin || n <= 0 || n > MAX_N || k <= 0 || k > n) {
        cerr << "Date de intrare invalide.\n";
        return false;
    }

    for (int i = 0; i < n; ++i) {
        fin >> values[i];
        if (!fin) {
            cerr << "Nu pot citi valorile vectorului.\n";
            return false;
        }
    }

    return true;
}

void rezolvare() {
    if (!citire()) {
        return;
    }

    // Stive monotone pentru a afla cea mai intinsa secventa in care fiecare element ramane minim.
    int top = -1;
    for (int i = 0; i < n; ++i) {
        while (top >= 0 && values[idxStack[top]] >= values[i]) {
            --top;
        }
        leftLess[i] = (top >= 0) ? idxStack[top] : -1;
        idxStack[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; --i) {
        while (top >= 0 && values[idxStack[top]] > values[i]) {
            --top;
        }
        rightLess[i] = (top >= 0) ? idxStack[top] : n;
        idxStack[++top] = i;
    }

    int bestBase = INT_MIN;
    int bestStart = 0;
    int bestEnd = k - 1;

    for (int i = 0; i < n; ++i) {
        int leftBound = leftLess[i] + 1;
        int rightBound = rightLess[i] - 1;
        int length = rightBound - leftBound + 1;

        if (length < k) {
            continue;
        }

        int windowStart = i - k + 1;
        if (windowStart < leftBound) {
            windowStart = leftBound;
        }
        int windowEnd = windowStart + k - 1;

        int candidateBase = values[i];
        bool better = false;
        if (candidateBase > bestBase) {
            better = true;
        } else if (candidateBase == bestBase) {
            if (windowStart < bestStart) {
                better = true;
            } else if (windowStart == bestStart && windowEnd < bestEnd) {
                better = true;
            }
        }

        if (better) {
            bestBase = candidateBase;
            bestStart = windowStart;
            bestEnd = windowEnd;
        }
    }

    cout << bestStart + 1 << " " << bestEnd + 1 << " " << bestBase << "\n";
}

#endif //EX3_H
