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
 Tuple paquetTotal[MAX_LETTRES]; // Paquet contenant tous les chevalets sous forme de tuple
} Paquet;

/**
 * @brief Initialise le paquet avec ses 88 chevalets
 * @param p Le paquet
 * @return 1 si initialisé, sinon 0
 */
int initPaquet(Paquet* p);

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
 * @brief Ajoute des chevalets dans le paquet principal
 * @param p Le paquet
 */
void ajouterChevalet(Paquet* p);

/**
 * @brief Vérifie que le mot passé est utilisé avec la liste de chevalets
 * @param mot Le mot passé par le joueur j
 * @param j Le joueur
 * @return 1 si le mot utilise bien les chevalets, sinon 0
 */
int verifChevalet(const char* mot, Joueur* j);

/**
 * @brief Assure l'affichage de la partie.
 * @param p La partie en cours
 */
void affichageChevalet(Partie* p);

// Algorithmes utilisés lors du jeu

/**
 * @brief Trie les chevalets des joueurs par ordre alphabétique
 * @param j Les chevalets du joueur
 */
void triChevalet(Joueur* j);

/**
 * @brief Renvoie l'inverse du rail
 * @param r Le rail
 * @return Le mot du rail à l'envers
 */
char* verso(Partie* r);

