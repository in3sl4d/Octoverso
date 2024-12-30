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

Joueur initJoueur(Partie* p) {
    Joueur j;
    scanf("%s", j.nom);
    if (p->joueur1->ordre == 0)
        j.ordre = 1;
    else
        j.ordre = 2;
    return j;
}