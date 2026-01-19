#ifndef INC_1_2_STEFAN_H
#define INC_1_2_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//se dau 3 siruri formate din litere mici. Det. lungimea celui mai lung subsir comun tuturor celor 3.

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

voi
#endif //INC_1_2_STEFAN_H
