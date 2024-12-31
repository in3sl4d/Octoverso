//
// Created by Yoko on 23/12/2024.
//
#pragma once
#include "jeu.h"

typedef struct {
    int longueur; // longueur du dictionnaire
    char mots[]; // liste contenant tous les mots
} Dictionnaire;

//FILE * dico = fopen("dico.txt", "r"); (Essayer d'ouvrir et copier le contenu de dico.txt dans dictionnaire.h)


