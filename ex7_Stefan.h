#ifndef EX7_STEFAN_H
#define EX7_STEFAN_H
#include <iostream>
#include <fstream>
using namespace std;

//gigel, primar in orasul sau, s-a gandit sa renoveze strada principala, strada de dimensiuni m*n(m<=15 si n<=150) compusa din
//bucati de dim 1*1. Majoritatea bucatilor sunt stricate, dar mai exista k bucati care sunt considerate bune.
//Dorind sa plateasca cat mai putini bani, Gigel a luat bucati de 2*2 la pretul unui bloc de 1*1. Pt. a pava strada tb. sa amplaseze
//cat mai multe din aceste blocuri pe bucati stricate, fara sa paveze vreo bucata buna deoarece ar aparea denivelari, si fara sa se
//suprapuna blocurile de 2*2. Det. nr. maxim de blocuri 2*2 pe care le poate pune primarul pt. a repara strada. Se citesc 3 nr.
//n, m si k, iar pe urmatoarele k linii se vor afla perechi de nr. intregi repr. linia si coloana pe care se afla o bucata buna.
//sa se afis. nr. max. de blocuri. 2*2 care pot fi amplasate pe strada

int n, m, k;
int mat[16][151] = {};
void citire() {
    ifstream fin("D:/info/c++/clion/ProblemeDeConcurs/file.in.txt");
    fin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x,y;
        fin >> x >> y;
        mat[x][y] = 1;
    }
}

void rezolvare() {
    citire();
    int rez = 0;
    for(int i = 1; i < n; i++) {        //100% ineficient, totusi cred ca merge in toate cazurile
        for(int j = 1; j < m; j++) {
            if(mat[i][j] == 0 && mat[i+1][j] == 0 && mat[i][j+1] == 0 && mat[i+1][j+1] == 0) {
                rez++;
                mat[i][j] = mat[i+1][j] = mat[i][j+1] = mat[i+1][j+1] = 2;
            }
        }
    }

    cout << rez << endl;
}
#endif //EX7_STEFAN_H
