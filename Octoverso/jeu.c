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
    p->joueur1 = initJoueur(1);
    p->joueur2 = initJoueur(2);
}

void distribution(Joueur* j, Paquet* p) {
    Chevalet lettre;
    for (int i = 0; i < NB_LETTRES_JOUEUR; ++i) {
        // lettre = p->paquetTotal[rand() % MAX_LETTRES];
        j->lettres[i] = lettre;
    }
}

int verifDico(const char* mot, const Dico* d) {
    for (int i = 0; i < d->nbMots-1; i++) {
        if (strcmp(mot, d->mots[i]) == 0) {
            return 1;
        }
        return 0;
    }
}

void affichage(Partie* p) {
    printf("%d : test \n", p->joueur1->ordre);
    printf("%d : test \n", p->joueur2->ordre);
}

void initPaquet(Paquet *p) {
    p = (Paquet*)malloc(sizeof(Paquet));
}

char* saisieMot() {
    char mot[TAILLE_PREMIER_MOT];
    scanf("%s", mot);
    char* m;
    m = (char*)malloc(sizeof(mot));
    *m = mot;
    return m;
}

