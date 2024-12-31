//
// Created by Yoko on 23/12/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chevalet.h"
#include "jeu.h"
#include "joueur.h"
#include "dictionnaire.h"
#include "constantes.h"
#pragma warning(disable:4996)

void initPartie(Partie *p) {
    p->joueur1 = &(initJoueur(1));
    p->joueur2 = &(initJoueur(2));
}

void distribution(Joueur* j) {
    for (int i = 0; i < NB_LETTRES_JOUEUR; ++i) {
        // j->lettres[i] = 'a'; (Pb : impossible d'assigner char au type chevalet, à régler)
    }
}

int verification(const char mot, const Dictionnaire* dico) {
    for (int i = 0; i < dico->longueur-1; i++) {
        if (strcmp(mot, dico->mots[i]) == 0) {
            return 1;

        }
    return 0;
    }
}