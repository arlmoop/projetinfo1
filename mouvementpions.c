//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>
#include "header.h"
#include "mouvementpoins.h"

void deplacementpion(char plateau[TAILLEPLATEAU][TAILLEPLATEAU], int joueurenmouvement) {
    int x=-1, y=-1, numerojoueur=joueurenmouvement;
    int choix;

    for (int i=0; i<TAILLEPLATEAU; i++) {
        for (int j=0; j<TAILLEPLATEAU; j++) {
            if (plateau[i][j] == '1'+numerojoueur-1) {
                x=i;
                y=j;
                plateau[i][j] = '.';
            }
        }
    }

    printf("Joueurs %d, choisissez une direction valide\n", numerojoueur);
    printf("1->haut, 2->bas, 3->gauche, 4->droite\n");

    do {
        scanf("%d", &choix);

        if ((choix==1 && x==0) || (choix==2 && x==TAILLEPLATEAU-1) || (choix==3 && y==0)
        || (choix==4 && y==TAILLEPLATEAU-1)) {
            printf("ERREUR : Le deplacement est invalde\n");
            printf("1->haut, 2->bas, 3->gauche, 4->droite\n");
        }
    } while ((choix==1 && x==0) || (choix==2 && x==TAILLEPLATEAU-1) || (choix==3 && y==0)
        || (choix==4 && y==TAILLEPLATEAU-1));

    if (choix==1) {
        x=x-1;
    } else if (choix==2) {
        x=x+1;
    } else if (choix==3) {
        y=y-1;
    } else if (choix==4) {
        y=y+1;
    }

    plateau[x][y] = '1' + numerojoueur - 1;
}