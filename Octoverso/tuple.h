//
// Created by Yoko on 03/01/2025.
//

#pragma once
#include "chevalet.h"

typedef struct {
    Chevalet lettre; // La lettre
    int nbChevalet; // Le nombre de fois que la lettre est présente
}Tuple;

/**
 * @brief Crée un tuple d'une lettre avec son nomre
 * @param lettre La lettre qu'on va créer en chevalet
 * @param nbChevalet Le nombre de lettre qu'on veut dans la partie
 * @return Un pointeur sur le tuple
 */
Tuple* creeTuple(Chevalet lettre, int nbChevalet);
