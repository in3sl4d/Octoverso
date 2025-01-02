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

Joueur* initJoueur(int ordre) {
    Joueur j;
    Joueur* jp = &j;
    scanf("%s", jp->nom);
    if (ordre == 1 || ordre == 2) {
        jp->ordre = ordre;
    }
    return jp;
}

