cmake_minimum_required(VERSION 3.29)
project(Octoverso C)

set(CMAKE_C_STANDARD 11)

add_executable(Octoverso main.c
        dictionnaire.c
        joueur.h
        jeu.h
        dictionnaire.h
        jeu.c
        chevalet.h
        constantes.h
        joueur.c
        tuple.h
        tuple.c)
