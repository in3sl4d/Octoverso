//
// Created by Yoko on 22/12/2024.
//

#pragma once
#include "chevalet.h"
#include "constantes.h"

typedef struct {
    char nom[MAX_NOM]; // Nom du joueur
    Chevalet lettres[NB_LETTRES_JOUEUR]; // Chevalets détenus par le joueur
    int ordre; // Ordre de jeu
}Joueur;

/**
 *
 * @param ordre Le numéro du joueur créé
 * @return Le joueur créé
 */
Joueur initJoueur(int ordre);

/**
 * @brief Laisse au joueur le choix entre plusieurs actions
 * @param joueur Le joueur devant effectuer l'action
 * @return 1 pour former un mot et 2 pour échanger un chevalet
 */
int actionJoueur(Joueur* joueur);

/**
 * @brief Affiche le statut actuel du joueur
 * @param joueur Le joueur
 */
void afficherJoueur(Joueur* joueur);

