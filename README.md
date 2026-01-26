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
