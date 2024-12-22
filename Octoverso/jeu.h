//
// Created by Yoko on 22/12/2024.
//

#pragma once
#include "joueur.h"

/**
 * @brief Permet d'initialiser une partie.
 */
void initPartie();

/**
 * @brief Distribue 12 chevalets à chacun des joueurs
 * @param joueur1 Le premier joueur
 * @param joueur2 Le deuxième joueur
 */
void distribution(Joueur* joueur1, Joueur* joueur2);

/**
 * @brief Vérifie que le mot entré existe dans le dictionnaire
 */
void verification();