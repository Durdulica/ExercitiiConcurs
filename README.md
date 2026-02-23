# Probleme LCS (mediu -> avansat)

Acest set contine 5 probleme asemanatoare cu LCS (subsir comun) pentru antrenament.
Fiecare problema are enunt, format de input/output, constrangeri si un exemplu.

## Problema 1: Numarul de LCS distincte

Enunt: Se dau doua siruri formate din litere mici. Determinati numarul de
subsiruri comune distincte de lungime maxima.

Input: doua linii, fiecare cu un sir.
Output: numarul de LCS distincte modulo 666013.
Constrangeri: 1 <= |A|, |B| <= 500.

Exemplu:
Input:
```
ababc
babca
```
Output:
```
2
```
Explicatie: LCS-urile distincte maxime sunt "babc" si "abca".

## Problema 2: LCS pe 3 siruri

Enunt: Se dau trei siruri formate din litere mici. Determinati lungimea celui
mai lung subsir comun tuturor celor trei.

Input: trei linii, fiecare cu un sir.
Output: lungimea LCS.
Constrangeri: 1 <= |A|, |B|, |C| <= 200.

Exemplu:
Input:
```
abac
cab
bac
```
Output:
```
2
```
Explicatie: LCS comun tuturor are lungimea 2 (ex. "ac").

## Problema 3: LCS distincte si lungime

Enunt: Se dau doua siruri formate din litere mici. Determinati lungimea LCS si
numarul de subsiruri comune distincte de aceasta lungime.

Input: doua linii, fiecare cu un sir.
Output: doua numere: lungimea LCS si numarul de LCS distincte modulo 1_000_000_007.
Constrangeri: 1 <= |A|, |B| <= 500.

Exemplu:
Input:
```
abcabc
acbacb
```
Output:
```
4 3
```
Explicatie: Lungimea LCS este 4, iar sunt 3 LCS distincte.

## Problema 4: LCS cu restrictie de alfabet

Enunt: Se dau doua siruri formate din litere mici si o multime de litere permise.
Determinati numarul de LCS distincte formate doar din litere permise.

Input: doua linii cu sirurile, a treia linie cu literele permise (fara spatii).
Output: numarul de LCS distincte modulo 666013.
Constrangeri: 1 <= |A|, |B| <= 500, 1 <= |S| <= 26.

Exemplu:
Input:
```
abacb
bacab
abc
```
Output:
```
1
```
Explicatie: LCS maxim este unic si contine doar litere permise.

## Problema 5: LCS cu greutati

Enunt: Se dau doua siruri si pentru fiecare litera un scor pozitiv. Un subsir
comun are scorul suma scorurilor literelor. Determinati scorul maxim al unui
subsir comun si numarul de subsiruri distincte care ating scorul maxim.

Input: doua linii cu sirurile; a treia linie cu 26 de intregi (scor pentru a-z).
Output: scorul maxim si numarul de subsiruri distincte cu acest scor, modulo
1_000_000_007.
Constrangeri: 1 <= |A|, |B| <= 400, scoruri <= 10^6.

Exemplu:
Input:
```
abac
baca
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
```
Output:
```
7 2
```
Explicatie: Scorul maxim este 7, iar 2 subsiruri distincte ating acest scor.

# Probleme cu subsecvente de suma maxima (similare cu ex2)

Acest set contine 5 probleme asemanatoare cu subsecventa de suma maxima cu
lungime minima. Fiecare problema are enunt, format input/output, constrangeri
si un exemplu.

## Problema 1: Suma maxima cu lungime exacta K

Enunt: Se da un sir de n numere intregi. Determinati suma maxima a unei
subsecvente consecutive de lungime exacta k, precum si pozitiile de inceput
si sfarsit (1-based).

Input: prima linie n si k, a doua linie n numere.
Output: trei numere: pozitia de inceput, pozitia de sfarsit, suma maxima.
Constrangeri: 1 <= k <= n <= 200000, |v[i]| <= 10^4.

Exemplu:
Input:
```
8 3
1 -2 3 4 -1 2 -5 2
```
Output:
```
3 5 6
```
Explicatie: subsecventa [3,4,-1] are suma 6 si este maxima pentru k=3.

## Problema 2: Suma maxima cu lungime cel putin K

Enunt: Se da un sir de n numere intregi. Determinati subsecventa consecutiva
de lungime cel putin k cu suma maxima si afisati pozitiile (1-based) si suma.

Input: prima linie n si k, a doua linie n numere.
Output: trei numere: pozitia de inceput, pozitia de sfarsit, suma maxima.
Constrangeri: 1 <= k <= n <= 200000, |v[i]| <= 25000.

Exemplu:
Input:
```
7 2
-1 5 -2 3 -4 6 -1
```
Output:
```
2 6 8
```
Explicatie: [5,-2,3,-4,6] are suma 8 si lungime 5 >= 2.

## Problema 3: Suma maxima cu lungime intre K si L

Enunt: Se da un sir de n numere intregi si doua valori k si l (k <= l).
Determinati subsecventa consecutiva cu suma maxima si lungime intre k si l.

Input: prima linie n k l, a doua linie n numere.
Output: pozitia de inceput, pozitia de sfarsit, suma maxima.
Constrangeri: 1 <= k <= l <= n <= 200000, |v[i]| <= 10^4.

Exemplu:
Input:
```
6 2 4
2 -1 2 -3 4 -1
```
Output:
```
1 3 3
```
Explicatie: [2,-1,2] are suma 3 si lungime 3 intre 2 si 4.

## Problema 4: Suma maxima dupa eliminarea a cel mult M elemente

Enunt: Se da un sir de n numere intregi si o valoare m. Puteti elimina cel
mult m elemente (nu neaparat consecutive), iar restul elementelor trebuie sa
formeze o subsecventa consecutiva. Determinati suma maxima obtinuta.

Input: prima linie n m, a doua linie n numere.
Output: suma maxima posibila.
Constrangeri: 0 <= m <= 50, 1 <= n <= 5000, |v[i]| <= 10^4.

Exemplu:
Input:
```
7 1
1 -3 4 -2 2 -1 3
```
Output:
```
8
```
Explicatie: eliminand -2, subsecventa [4,2,-1,3] are suma 8.

## Problema 5: Suma maxima cu penalizare pe lungime

Enunt: Se da un sir de n numere intregi si o penalizare p. Pentru o subsecventa
consecutiva, valoarea ei este suma elementelor minus p * lungime. Determinati
subsecventa cu valoare maxima si afisati pozitiile si valoarea.

Input: prima linie n p, a doua linie n numere.
Output: pozitia de inceput, pozitia de sfarsit, valoarea maxima.
Constrangeri: 1 <= n <= 200000, |v[i]| <= 10^4, 0 <= p <= 10^4.

Exemplu:
Input:
```
5 1
3 -1 2 -2 4
```
Output:
```
5 5 3
```
Explicatie: subsecventa [4] are suma 4, lungime 1, valoare 4 - 1*1 = 3.

# Probleme cu baza maxima (similare cu ex3)

Acest set contine 5 probleme asemanatoare cu "baza maxima" pentru secvente
consecutive (minimul din secventa). Fiecare problema are enunt, format
input/output, constrangeri si un exemplu.

## Problema 1: Baza maxima cu lungime exacta K

Enunt: Se da un sir de n numere intregi. Determinati o secventa consecutiva
de lungime exact k cu baza maxima (baza = minimul din secventa). Afisati
pozitiile (1-based) si valoarea bazei.

Input: prima linie n k, a doua linie n numere.
Output: pozitia de inceput, pozitia de sfarsit, baza maxima.
Constrangeri: 1 <= k <= n <= 200000, |v[i]| <= 30000.

Exemplu:
Input:
```
6 3
2 -1 4 0 3 -2
```
Output:
```
2 4 -1
```
Explicatie: secventa [-1,4,0] are baza -1 si este maxima pentru k=3.

## Problema 2: Baza maxima cu lungime cel putin K si cea mai scurta

Enunt: Se da un sir de n numere intregi si k. Determinati o secventa
consecutiva de lungime cel putin k cu baza maxima. Daca exista mai multe,
alegeti secventa cu lungime minima, iar la egalitate cea mai din stanga.

Input: prima linie n k, a doua linie n numere.
Output: pozitia de inceput, pozitia de sfarsit, baza maxima.
Constrangeri: 1 <= k <= n <= 200000, |v[i]| <= 30000.

Exemplu:
Input:
```
7 2
5 1 4 3 2 6 1
```
Output:
```
2 3 1
```
Explicatie: baza maxima este 1; secventa [1,4] are lungime minima.

## Problema 3: Baza maxima pentru intervale multiple

Enunt: Se da un sir de n numere intregi si q interogari. Fiecare interogare
da o valoare k. Pentru fiecare k, determinati o secventa consecutiva de
lungime cel putin k cu baza maxima si afisati baza maxima.

Input: prima linie n q, a doua linie n numere, apoi q linii cu k.
Output: pentru fiecare interogare, baza maxima.
Constrangeri: 1 <= n <= 200000, 1 <= q <= 200000, 1 <= k <= n,
|v[i]| <= 30000.

Exemplu:
Input:
```
5 3
2 5 1 4 3
1
2
4
```
Output:
```
5
3
1
```
Explicatie: pentru k=1 baza maxima e 5; pentru k=2 e 3; pentru k=4 e 1.

## Problema 4: Baza maxima cu restrictie de suma minima

Enunt: Se da un sir de n numere intregi si doua valori k si s. Determinati o
secventa consecutiva de lungime cel putin k cu baza maxima, avand suma
elementelor cel putin s. Daca nu exista, afisati "NU".

Input: prima linie n k s, a doua linie n numere.
Output: pozitia de inceput, pozitia de sfarsit, baza maxima sau "NU".
Constrangeri: 1 <= k <= n <= 200000, |v[i]| <= 30000, |s| <= 10^9.

Exemplu:
Input:
```
6 2 5
1 2 -1 4 0 3
```
Output:
```
4 6 0
```
Explicatie: [4,0,3] are suma 7 >= 5, baza 0, maxima.

## Problema 5: Baza maxima cu penalizare pe lungime

Enunt: Se da un sir de n numere intregi si o penalizare p. Pentru o secventa
consecutiva, valoarea ei este baza (minimul) minus p * lungime. Determinati
secventa cu valoare maxima si afisati pozitiile si valoarea.

Input: prima linie n p, a doua linie n numere.
Output: pozitia de inceput, pozitia de sfarsit, valoarea maxima.
Constrangeri: 1 <= n <= 200000, |v[i]| <= 30000, 0 <= p <= 10^4.

Exemplu:
Input:
```
5 1
3 -1 2 -2 4
```
Output:
```
1 1 2
```
Explicatie: secventa [3] are baza 3, valoare 3 - 1*1 = 2.

# Probleme cu joc pe matrice (nivel usor, asemanatoare cu ex4)

Acest set contine 5 probleme usoare inspirate din jocul de pe matrice.
Fiecare problema are enunt, format input/output, constrangeri si un exemplu.

## Problema 1: Un pas spre colt

Enunt: Se da o matrice n x m cu valori intregi. Jetonul porneste in (n,m) si
la fiecare mutare poate merge in sus sau la stanga cu exact 1 pas. Jucatorii
muta alternativ, adunand valoarea celulei pe care ajung. Determinati diferenta
maxima (P1 - P2) daca ambii joaca optim.

Input: n m, apoi matricea.
Output: diferenta maxima P1 - P2.
Constrangeri: 1 <= n,m <= 50, valori in [-1000,1000].

Exemplu:
Input:
```
2 2
1 2
3 4
```
Output:
```
3
```
Explicatie: P1 merge pe 3, P2 pe 1, P1 pe 2 => diferenta 5-2=3.

## Problema 2: Celula initiala maxima (fara joc)

Enunt: Se da o matrice n x m cu valori intregi. Determinati celula cu valoare
maxima. Afisati valoarea si pozitia (1-based). Daca sunt mai multe, alegeti
cea mai din stanga sus.

Input: n m, apoi matricea.
Output: valoarea maxima si pozitia (linie, coloana).
Constrangeri: 1 <= n,m <= 1000, valori in [-1000,1000].

Exemplu:
Input:
```
3 3
1 5 2
0 5 4
3 2 1
```
Output:
```
5 1 2
```

## Problema 3: Joc cu un singur pas

Enunt: Se da o matrice n x m cu valori intregi si o pozitie initiala (x,y).
Jucatorul 1 face o singura mutare intr-o celula din dreptunghiul (1,1)-(x,y),
apoi jocul se opreste. Determinati diferenta maxima P1 - P2 (P2 nu mai muta).

Input: n m, matricea, apoi x y.
Output: diferenta maxima.
Constrangeri: 1 <= n,m <= 1000, 1 <= x <= n, 1 <= y <= m.

Exemplu:
Input:
```
2 3
1 2 3
4 5 6
2 3
```
Output:
```
6
```
Explicatie: P1 alege celula cu valoare maxima din prefixul (1,1)-(2,3).

## Problema 4: Joc cu doua mutari (P1 si P2)

Enunt: Se da o matrice n x m si o pozitie initiala (x,y). P1 muta o data in
prefixul (1,1)-(x,y), apoi P2 muta o data in prefixul noii pozitii. Jocul se
opreste. Determinati diferenta maxima P1 - P2 (ambii joaca optim).

Input: n m, matricea, apoi x y.
Output: diferenta maxima.
Constrangeri: 1 <= n,m <= 200, 1 <= x <= n, 1 <= y <= m.

Exemplu:
Input:
```
2 2
1 2
3 4
2 2
```
Output:
```
2
```
Explicatie: P1 ia 3, P2 ia 1 => diferenta 2.

## Problema 5: Joc pe diagonala

Enunt: Se da o matrice n x m. Jetonul porneste in (n,m). La fiecare mutare se
poate merge doar pe diagonala sus-stanga (i-1, j-1). Jucatorii muta alternativ
si aduna valorile celulelor unde ajung. Determinati diferenta maxima P1 - P2.

Input: n m, matricea.
Output: diferenta maxima P1 - P2.
Constrangeri: 1 <= n,m <= 500, valori in [-1000,1000].

Exemplu:
Input:
```
3 3
1 2 3
4 5 6
7 8 9
```
Output:
```
4
```
Explicatie: traseul este 9,5,1. P1 ia 9 si 1, P2 ia 5 => 10-5=5.

# Probleme similare cu ex5 (raport cost/timp)

- Problema 1: Avem n proiecte, fiecare cu cost și durată. Alegeți o subsecvență continuă cu lungime între L și U care maximizează media cost/durată. Afișați valoarea maximă.
- Problema 2: Pentru n lecții video (cost = megabytes, timp = minute), găsiți intervalul continuu cu lungime în [L, U] care minimizează raportul MB/minut. Afișați raportul minim și pozițiile.
- Problema 3: Într-un șir de senzori (cost = energie consumată, timp = timp activ), determinați dacă există o fereastră de lungime fixă K cu raport energie/timp cel puțin T. Afișați YES/NO.
- Problema 4: Dată o secvență de cheltuieli zilnice (cost) și timpi de așteptare (timp), găsiți cea mai lungă fereastră cu raport cost/timp sub o limită P. Afișați lungimea maximă și intervalul.
- Problema 5: Înregistrări audio (cost = mărime fișier, timp = durată secunde); găsiți două ferestre disjuncte cu lungime în [L, U] care au aceeași medie maximă cost/timp. Afișați media și pozițiile celor două ferestre.

# Probleme cu triunghi de cutii (similare cu ex6)

Acest set contine 5 probleme asemanatoare cu triunghiul de tip Pascal, cu
cerinte gradate de la usor la mai complex. Fiecare problema are enunt, format
input/output, constrangeri si un exemplu.

## Problema 1: Exista o configuratie?

Enunt: Se dau n si s. Construiti un triunghi cu n linii din numere intregi
strict pozitive, astfel incat fiecare element de pe linia i sa fie suma celor
doua elemente de sub el (linia i+1), iar suma tuturor elementelor din triunghi
sa fie exact s. Cerinta este sa afisati doar daca exista cel putin o
configuratie valida.

Input: o linie cu n si s.
Output: `DA` daca exista, altfel `NU`.
Constrangeri: 1 <= n <= 18, 1 <= s < 10^6.

Exemplu:
Input:
```
2 8
```
Output:
```
DA
```
Explicatie: baza [1,3] produce triunghiul [4] / [1,3], suma totala fiind 8.

## Problema 2: Reconstruieste baza minima lexicografic

Enunt: Se dau n si s. Daca exista configuratii valide, afisati baza
(ultima linie) cu valori strict pozitive care produce suma totala s si este
minima lexicografic. Daca nu exista, afisati `impossible`.

Input: o linie cu n si s.
Output: n numere (baza) sau `impossible`.
Constrangeri: 1 <= n <= 18, 1 <= s < 10^6.

Exemplu:
Input:
```
3 14
```
Output:
```
1 1 3
```
Explicatie: baza [1,1,3] genereaza suma 14 si este cea mai mica lexicografic.

## Problema 3: Numar de configuratii modulo M

Enunt: Se dau n, s si m. Determinati cate baze de n elemente strict pozitive
genereaza un triunghi valid cu suma totala exact s. Raspunsul se da modulo m.

Input: o linie cu n s m.
Output: numarul configuratiilor modulo m.
Constrangeri: 1 <= n <= 18, 1 <= s < 10^6, 2 <= m <= 10^9+7.

Exemplu:
Input:
```
2 8 1000000007
```
Output:
```
3
```
Explicatie: bazele valide sunt [1,3], [2,2], [3,1].

## Problema 4: Triunghi cu elemente de baza in interval [L, R]

Enunt: Se dau n, s, L si R. Baza triunghiului trebuie sa contina numai valori
in intervalul [L, R], iar restul regulilor raman la fel (fiecare element este
suma celor doua de dedesubt). Determinati daca exista configuratie si, daca da,
afisati una valida.

Input: o linie cu n s L R.
Output: `impossible` sau o baza valida de n numere.
Constrangeri: 1 <= n <= 18, 1 <= s < 10^6, 1 <= L <= R <= 10^5.

Exemplu:
Input:
```
3 18 2 4
```
Output:
```
2 2 4
```
Explicatie: toate elementele bazei sunt in [2,4], iar suma totala este 18.

## Problema 5: Suma in interval pe multiple interogari

Enunt: Se da n si apoi q interogari. Fiecare interogare ofera un interval
[A, B]. Pentru fiecare interogare, trebuie sa determinati daca exista o baza
strict pozitiva care genereaza un triunghi valid cu suma totala S in [A, B].
Afisati pentru fiecare interogare numarul de sume realizabile din interval.

Input: prima linie n q; urmatoarele q linii contin A B.
Output: pentru fiecare interogare, un numar intreg.
Constrangeri: 1 <= n <= 18, 1 <= q <= 200000, 1 <= A <= B < 10^6.

Exemplu:
Input:
```
2 3
4 6
7 8
9 12
```
Output:
```
3
2
4
```
Explicatie: pentru n=2, toate sumele >=4 sunt realizabile; numaram valorile
din fiecare interval.
