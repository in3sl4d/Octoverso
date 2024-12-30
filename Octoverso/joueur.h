//
// Created by Yoko on 22/12/2024.
//


#pragma once
#include "jeu.h"
#include "chevalet.h"
#include "jeu.h"
#include "jeu.h"


typedef struct {
    char nom[]; // Nom du joueur
    Chevalet lettres[]; // Chevalets détenus par le joueur
    int ordre; // Ordre de jeu
}Joueur;

/**
 *
 * @param p La partie en cours
 * @return Le joueur créé
 */
Joueur initJoueur(Partie* p);

/**
 * @brief Laisse au joueur le choix entre plusieurs actions
 * @param p La partie en cours
 * @param joueur Le joueur devant effectuer l'action
 * @return 1 pour former un mot et 2 pour échanger un chevalet
 */
int actionJoueur(Partie* p, Joueur* joueur);

/**
 * @brief Affiche le statut actuel du joueur
 * @param joueur Le joueur
 */
void afficherJoueur(Joueur* joueur);

