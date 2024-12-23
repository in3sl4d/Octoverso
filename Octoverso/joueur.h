//
// Created by Yoko on 22/12/2024.
//

#pragma once

typedef struct {
    char nom[]; // Nom du joueur
    Chevalet lettres[]; // Chevalets détenus par le joueur
    int ordre; // Ordre de jeu
}Joueur;