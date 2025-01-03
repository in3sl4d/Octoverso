#pragma warning (disable : 4996)
#include <assert.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnaire.h"

void enleverChar(char* mot, int i) {
	assert(i > 0 && i < strlen(mot));
	memmove(&mot[i], &mot[i + 1], strlen(mot) - i);
}

int initDico(Dico* d, int capacite) {
	assert(capacite > 0);
	d->capacite = capacite;
	d->nbMots = 0;
	d->trie = 1;
	d->mots = (char**)malloc(sizeof(char*) * capacite);
	return d->mots != NULL;
}

int tailleDico(const Dico* d) {
	return d->nbMots;
}

int comp(const void* a, const void* b) {
	return strcmp(*(const char**)a, *(const char**)b);
}

void triDico(Dico* d) {
	if (!d->trie) {
		qsort(d->mots, tailleDico(d), sizeof(const char*), comp);
		d->trie = 1;
	}
}

int ajouterDico(Dico* d, char* mot) {
	const int FACTEUR = 2;
	if (d->nbMots == d->capacite) {
		char** tab = (char**)realloc(d->mots, sizeof(char*) * d->capacite * FACTEUR);
		if (tab == NULL)
			return 0;
		d->capacite *= FACTEUR;
		d->mots = tab;
	}
	int taille = strlen(mot) + 1;
	d->mots[d->nbMots] = (char*)malloc(taille);
	if (d->mots[d->nbMots] == 0)
		return 0;
	memmove(d->mots[d->nbMots++], mot, taille);
	d->trie = 0;
	//printf("%s\n", d->mots[d->nbMots-1]);
	return 1;
}

int remplirDico(Dico* d, const char* const nomDico) {
	FILE* file = fopen(nomDico, "r");

	// Buffer to store each line of the file.
	char line[256];

	// Check if the file was opened successfully.
	if (file != NULL) {
		// Read each line from the file and store it in the
		// 'line' buffer.
		while (fgets(line, sizeof(line), file)) {
			enleverChar(line, strlen(line) - 1);
			if (strlen(line) <= 8 && !strchr(line, 'K') && !strchr(line, 'X') && !strchr(line, 'Y') && !strchr(line, 'Z') && !strchr(line, 'W')) {
				ajouterDico(d, line);
			}
		}

		// Close the file stream once all lines have been
		// read.
		fclose(file);
	}
	else {
		// Print an error message to the standard error
		// stream if the file cannot be opened.
		fprintf(stderr, "Unable to open file!\n");
	}

	return 1;
}

char* obtenirDico(const Dico* d, int i) {
	assert(i >= 0 && i < tailleDico(d));
	return d->mots[i];
}

void detruireDico(Dico* d) {
	free(d->mots);
}

int chercherDico(Dico* d, char* mot) {
	triDico(d);
	int i = tailleDico(d) / 2;
	for (int saut = i/2; i >= 0 && i < tailleDico(d); saut /= 2) {
		int pos = strcmp(obtenirDico(d, i), mot);
		if (!pos)
			return i;
		else if (pos < 0)
			i += saut;
		else if (pos > 0)
			i -= saut;
		if (saut == 1)
			saut *= 2;
	}
	return -1;
}

/** int main() {
	Dico dico;
	initDico(&dico, 5);
	remplirDico(&dico, "ods4.txt");
	printf("%d %s\n", chercherDico(&dico, "AAS"), chercherDico(&dico, "AAS") >= 0 && chercherDico(&dico, "AAS") < tailleDico(&dico) ? obtenirDico(&dico, chercherDico(&dico, "AAS")) : "NULL");
	printf("%d %s\n", chercherDico(&dico, "A"), chercherDico(&dico, "A") >= 0 && chercherDico(&dico, "A") < tailleDico(&dico) ? obtenirDico(&dico, chercherDico(&dico, "A")) : "NULL");
	detruireDico(&dico);
} */
