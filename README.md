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
