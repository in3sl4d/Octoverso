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
    Chevalet l;
    for (int i = 0; i < NB_LETTRES_JOUEUR-1; ++i) {
        l = p->paquetTotal[rand() % MAX_LETTRES].lettre;
        j->lettres[i] = l;
    }
}

void affichageChevalet(Partie* p) {
    printf("%d : \n", p->joueur1->ordre);
    for (int i = 0; i < NB_LETTRES_JOUEUR-1; ++i) {
        printf("%c:", p->joueur1->lettres[i].lettre);
    }
    printf("%d : test \n", p->joueur2->ordre);
    for (int i = 0; i < NB_LETTRES_JOUEUR-1; ++i) {
        printf("%c:", p->joueur2->lettres[i].lettre);
    }
}

void initPaquet(Paquet *p) {
    p = (Paquet*)malloc(sizeof(Paquet));
    p->paquetTotal;
}

char* saisieMot() {
    char mot[TAILLE_PREMIER_MOT];
    scanf("%s", mot);
    char* m;
    m = (char*)malloc(sizeof(mot));
    *m = mot;
    return m;
}

void ajouterChevalet(Paquet* p) {
    Chevalet lettre;
    int nombre;
    int indice = 0;
    for (int i = NB_LETTRES; i > 0; --i) {
        scanf("%s %d", &lettre, &nombre);
        p->paquetTotal[indice].lettre = lettre;
        p->paquetTotal[indice].nbChevalet = nombre;
    }
}

void triChevalet(Joueur* j) {
    char tmp;
    for (int i = 0; i < NB_LETTRES_JOUEUR-1; ++i){
        if (j->lettres[i].lettre > j->lettres[i+1].lettre) {
            tmp = j->lettres[i].lettre;
            j->lettres[i] = j->lettres[i+1];
            j->lettres[i+1].lettre = tmp;
        }
    }
}

char* verso(Partie* r) {
    char* mot;
    mot = (char*)malloc(sizeof(r->rail));
    int taille = sizeof(r->rail) / sizeof(r->rail[0]);
    char reverse[taille];
    *mot = reverse;
    for (int i = 0; i < taille; ++i) {
        mot[i] += r->rail[taille-i].lettre;
    }
    return mot;
}