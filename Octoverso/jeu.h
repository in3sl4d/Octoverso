//
// Created by Yoko on 22/12/2024.
//

#pragma once
#include "joueur.h"
#include "dictionnaire.h"
#include "chevalet.h"

typedef struct {
 Joueur* joueur1;
 Joueur* joueur2;
 Chevalet pioche[];
 char dejajoue[];
}Partie;

/**
 * @brief Permet d'initialiser une partie.
 */
void initPartie(Partie* p);

/**
 * @brief Distribue 12 chevalets à chacun des joueurs
 * @param joueur1 Le premier joueur
 * @param joueur2 Le deuxième joueur
 */
void distribution(Joueur* joueur1, Joueur* joueur2);

/**
 * @brief Vérifie que le mot choisi existe
 * @param mot Le mot choisi
 * @param dico Le dictionnaire
 * @return 1 si le mot existe, sinon 0
 */
int verification(char mot, Dictionnaire* dico);

/**
 * @brief Assure l'affichage de la partie.
 * @param j1 Le premier joueur
 * @param j2 Le second joueur
 */
void affichage(Joueur* j1, Joueur* j2);

