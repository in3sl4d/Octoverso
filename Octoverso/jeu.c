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
#pragma warning(disable:4996)

void initPartie(Partie *partie) {

}

void distribution(Joueur* joueur1, Joueur* joueur2) {

}

int verification(const char mot, const Dictionnaire* dico) {
    for (int i = 0; i < dico->longueur-1; i++) {
        if (strcmp(mot, dico->mots[i]) == 0) {
            return 1;
            return 0;
        }
}