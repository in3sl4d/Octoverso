//
// Created by Yoko on 22/12/2024.
//

#pragma once
#include "joueur.h"
#include "dictionnaire.h"
#include "chevalet.h"
#include "constantes.h"

typedef struct {
 Joueur* joueur1;
 Joueur* joueur2;
 Chevalet pioche[MAX_LETTRES];
 Chevalet rail[MAX_RAIL];
 char dejajoue[];
}Partie;

typedef struct {
 Chevalet PaquetTotal[MAX_LETTRES];
} Paquet;


/**
 * @brief Initialise le paquet avec ses 88 chevalets
 * @return
 */
Paquet initPaquet();

/**
 * @brief Permet d'initialiser une partie.
 */
void initPartie(Partie* p);

/**
 * @brief Distribue 12 chevalets à un joueur
 * @param j Le joueur
 */
void distribution(Joueur* j);

/**
 * @brief Vérifie que le mot choisi existe
 * @param mot Le mot choisi
 * @param dico Le dictionnaire
 * @return 1 si le mot existe, sinon 0
 */
int verification(const char mot, const Dictionnaire* dico);

/**
 * @brief Assure l'affichage de la partie.
 * @param j1 Le premier joueur
 * @param j2 Le second joueur
 */
void affichage(Joueur* j1, Joueur* j2);

