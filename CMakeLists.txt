cmake_minimum_required(VERSION 3.29)
project(ProblemeDeConcurs)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProblemeDeConcurs main.cpp
        probleme/lcs/1.1_Stefan.h
        probleme/lcs/1.2_Stefan.h
        probleme/lcs/1.3_Stefan.h
        probleme/lcs/1.4_Stefan.h
        probleme/lcs/1.5_Stefan.h
        probleme/lcs/ex1.h
        probleme/lcs/zaharel_lcs.h
        probleme/subsecvente-suma/2.1_Stefan.h
        probleme/subsecvente-suma/2.2_Stefan.h
        probleme/subsecvente-suma/2.3_Stefan.h
        probleme/subsecvente-suma/2.4_Stefan.h
        probleme/subsecvente-suma/ex2.h
        probleme/subsecvente-suma/ex2_Stefan.h
        probleme/baza-secventa/3.1_Stefan.h
        probleme/baza-secventa/3.2_Stefan.h
        probleme/baza-secventa/3.3_Stefan.h
        probleme/baza-secventa/3.4_Stefan.h
        probleme/baza-secventa/3.5_Stefan.h
        probleme/baza-secventa/ex3.h
        probleme/baza-secventa/ex3_Stefan.h
        probleme/diverse/15.1_Stefan.h
        probleme/diverse/ex4.h
        probleme/diverse/ex4_Stefan.h
        probleme/diverse/ex5.h
        probleme/diverse/ex5_Stefan.h
        probleme/diverse/ex6.h
        probleme/diverse/ex6_Stefan.h
        probleme/diverse/ex7.h
        probleme/diverse/ex7_Stefan.h
        probleme/diverse/ex8.h
        probleme/diverse/ex8_Stefan.h
        teorie/teorie1.h
        teorie/teorie3.h
        utilitare/ex1_1.h
        utilitare/file.in.txt)
