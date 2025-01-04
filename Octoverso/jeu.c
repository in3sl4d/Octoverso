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

int initPaquet(Paquet *p) {
    char lettre;
    int nombre;
    int taille = sizeof(p->paquetTotal) / sizeof(p->paquetTotal[0]);
    for (int i = 0 ; i < (NB_LETTRES-1) ; ++i) {
        printf("Entrez la lettre désirée et son nombre");
        scanf("%s %d", &lettre, &nombre);
        for (int j = 0; j < taille; ++j) {
            if (lettre == p->paquetTotal[j].lettre.lettre ) {
                return 0;
            }
            p->paquetTotal[i].lettre.lettre = lettre;
            p->paquetTotal[i].nbChevalet = nombre;
        }
        return 1;
    }
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

char* verso(const Partie* r) {
    char* mot;
    mot = (char*)malloc(sizeof(r->rail));
    const int taille = sizeof(r->rail) / sizeof(r->rail[0]);
    char reverse[taille];
    *mot = reverse;
    for (int i = 0; i < taille; ++i) {
        mot[i] = r->rail[(taille-1)-i].lettre;
    }
    return mot;
}

int verifChevalet(const char* mot, const Joueur* j) {
    const int taille_mot = sizeof(*mot) / sizeof(mot[0]);
    const int nb_chevalets = sizeof(j->lettres) / sizeof(j->lettres[0]);
    int id = 0;
    for (int i = 0; i < nb_chevalets; ++i) {
        for (int f = 0; f < taille_mot; ++f)
            if (mot[i] == j->lettres[f].lettre) {
                id += 1;
            }
    }
    return id == taille_mot;
}