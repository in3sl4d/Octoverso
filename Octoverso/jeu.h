//
// Created by Yoko on 22/12/2024.
//

#pragma once
#include "joueur.h"
#include "dictionnaire.h"
#include "chevalet.h"
#include "constantes.h"
#include "tuple.h"

typedef struct {
 Joueur* joueur1; // Premier joueur enregistre
 Joueur* joueur2; // Deuxieme joueur enregistre
 Chevalet pioche[MAX_LETTRES]; // Chevalet restant après distribution
 Chevalet rail[MAX_RAIL]; // De taille maximum 8
 char dejajoue[]; // Stocke les mots déjà joué
}Partie;

typedef struct {
 Tuple PaquetTotal[MAX_LETTRES]; // Paquet contenant tous les chevalets sous forme de tuple
} Paquet;

/**
 * @brief Initialise le paquet avec ses 88 chevalets
 * @param p Le paquet
 */
void initPaquet(Paquet* p);

/**
 * @brief Permet d'initialiser une partie.
 */
void initPartie(Partie* p);

/**
 * @brief Distribue 12 chevalets à un joueur
 * @param j Le joueur
 */
void distribution(Joueur* j, Paquet* p);

/**
 * @return Le mot saisie
 */
char* saisieMot();

/**
 * @brief Vérifie que le mot choisi existe
 * @param mot Le mot choisi
 * @param dico Le dictionnaire
 * @return 1 si le mot existe, sinon 0
 */
int verifDico(const char* mot, const Dico* d);

/**
 * @brief Vérifie que le mot passé est utilisé avec la liste de chevalets
 * @param mot Le mot passé par le joueur j
 * @param j Le joueur
 * @return 1 si le mot utilise bien les chevalets, sinon 0
 */
int verifChevalet(const char* mot[5], Joueur* j);

/**
 * @brief Assure l'affichage de la partie.
 * @param p La partie en cours
 */
void affichage(Partie* p);

