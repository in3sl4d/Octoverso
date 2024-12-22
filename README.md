# Octoverso
Projet de SAE de C période B

## Présentation du projet

Dans le contexte de la SAE, nous devons programmer un jeu nommé "Octoverso" avant le 10 janvier 2025.
Octoverso est un jeu pour deux joueurs qui consiste à former autant de mots que possibles avec les lettres qu'on détient et les lettres présentent sur le rail.
Chaque joueurs se voit attribuer 12 lettres. Le joeur formant le mot le plus petit (commençant par la lettre A par exemple) commence.
Les joueurs mettent ensuite un mot sur le rail.
Chaque joueurs doit ensuite trouver de nouveaux mots à partir des mots déjà présent sur le rail et des lettres qu'ils détiennent.

### Règles du jeu

Cependant, il y a quelques règles à suivre :
- On ne peux pas former deux fois le même mot
- Le mot doit exister dans un dictionnaire fourni

Si un joueur forme un "octo" (un mot de 8 lettres), il défausse une de ses lettres.
Les lettres éjectées du rail sont attribués à l'autre joueur.
On a la possibilité de retourner le rail et former des mots.

## Répartition du code

Nous avons réparti le code dans plusieurs fichiers :
- les fichiers d'en-tête
- les fichiers source
- le fichier main

Les fichiers d'en-tête nous ont permis de définir toutes les structures, variables et prototypes de fonctions nécéssaire au projet.
Les fichiers sources contiennent le code des fonctions prédéfinies plus tôt.
Le fichier main permet d'éxécuter et débugger le code.

### dictionnaire.h

- Contient le dictionnaire avec tous les mots utilisable.

### joueur.h

- Définit la structure joueur
- Définit ce que peux faire le joueur (tourner le rail, proposer un mot)

### partie.h

- Définit la structure partie
- Définit le déroulement de la partie (initialisation de la pioche, distribution des lettres, vérification du mot,...)


