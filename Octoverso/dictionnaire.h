#pragma once

typedef struct {
    char** mots; // liste contenant tous les mots
    int nbMots; // longueur du dictionnaire (combien de mots sont stockés)
    int capacite; // capacite du dictionnaire (combien de mots on peut stocker)
    int trie; // Vaut 1 si trie sinon 0 (revient a 0 avec ajout nouveau mot)
}Dico;
