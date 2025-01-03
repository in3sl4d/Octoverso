#pragma once

typedef struct {
    char** mots; // liste contenant tous les mots
    int nbMots; // longueur du dictionnaire (combien de mots sont stockés)
    int capacite; // capacite du dictionnaire (combien de mots on peut stocker)
    int trie; // Vaut 1 si trie sinon 0 (revient a 0 avec ajout nouveau mot)
}Dico;

/**
 * @brief Retire un caractère d'un mot ?
 * @param mot Le mot à retirer
 * @param i L'indice du caractère à retirer
 */
void enleverChar(char* mot, int i);

/**
 * @brief Initialise le dictionnaire
 * @param d Le dictionnaire
 * @param capacite Le nombre de mots qu'on peut stocker
 * @return 1 si l'initialisation est un succès, sinon 0
 */
int initDico(Dico* d, int capacite);

/**
 * @brief Renvoie la taille du dictionnaire
 * @param d Le dictionnaire
 * @return Sa taille
 */
int tailleDico(const Dico* d);

/**
 * @brief Compare deux mots entre eux
 * @param a Le premier mot
 * @param b Le deuxième mot
 * @return 1 si différent, sinon 0
 */
int comp(const void* a, const void* b);

/**
 * @brief Trie le dictionnaire par ordre alphabétique
 * @param d Le dictionnaire à trier
 */
void triDico(Dico* d);

/**
 * @brief Rajoute un mot dans un dictionnaire
 * @param d Le dictionnaire
 * @param mot Le mot
 * @return 1 si succès, sinon 0
 */
int ajouterDico(Dico* d, char* mot);

/**
 * @brief Remplie le dictionnaire avec les mots d'un fichier .txt
 * @param d Le dictionnaire à remplir
 * @param nomDico Le nom du fichier .txt avec les mots
 * @return 1 si succès, sinon 0
 */
int remplirDico(Dico* d, const char* const nomDico);

/**
 * @brief Obtenir le mot à l'indice donné
 * @param d Le dictionnaire
 * @param i L'indice
 * @return Le mot à l'indice i du dictionnaire
 */
char* obtenirDico(const Dico* d, int i);

/**
 * @brief Détruit le dictionnaire en libérant l'espace mémoire occupé par ce dernier
 * @param d Le dictionnaire à détruire
 */
void detruireDico(Dico* d);

/**
 * @brief Cherche si un mot est dans le dictionnaire
 * @param d Le dictionnaire où on cherche
 * @param mot Le mot qu'on recherche
 * @return L'indice où se trouve le mot, sinon -1
 */
int chercherDico(Dico* d, char* mot);