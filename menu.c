//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>
#define TAILLEPLATEAU 9

int menudepart (char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur) {

        printf("BIENVENUE DANS LE JEU DU QUORIDOR\n\n");
    do {
        printf("\nVoulez vous jouez avec deux ou quatres joueurs ? :");
        scanf("%d", nombrejoueur);

        if (*nombrejoueur >= 2) {
            printf("Entrez le prenom du joueur 1 :");
            scanf("%s", prenomjoueur1);
            printf("\nEntrez le prenom du joueur 2 :");
            scanf("%s", prenomjoueur2);
        }
        if (*nombrejoueur >= 4) {
            printf("\nEntrez le prenom du joueur 3 :");
            scanf("%s", prenomjoueur3);
            printf("\nEntrez le prenom du joueur 4 :");
            scanf("%s", prenomjoueur4);
        }
        if (*nombrejoueur!=2 && *nombrejoueur!=4) {
            printf("\nERREUR : Vous devez choisir 2 ou 4 joueurs");
        }
    } while (*nombrejoueur!=2 && *nombrejoueur!=4);

    return prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, *nombrejoueur;
}

void creationplateau(char plateau[TAILLEPLATEAU][TAILLEPLATEAU], int nombrejoueur) {
    for (int i = 0; i < TAILLEPLATEAU; i++) {
        for (int j = 0; j < TAILLEPLATEAU; j++) {
            plateau[i][j] = '.';
        }
    }
    if (nombrejoueur >= 2) {
        plateau[0][4] = '1';
        plateau[8][4] = '2';
    }
    if (nombrejoueur >= 4) {
        plateau[4][0] = '3';
        plateau[4][8] = '4';
    }
}

void affichageplateau(char plateau[TAILLEPLATEAU][TAILLEPLATEAU]) {
    printf("\n\n   A  B  C  D  E  F  G  H  I\n");
    printf("  ___________________________\n");
    for (int i = 0; i < TAILLEPLATEAU; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < TAILLEPLATEAU; j++) {
            printf("%c |", plateau[i][j]);
        }
        printf(" %d\n", i + 1);
    }
    printf("  ___________________________\n");
    printf("   A  B  C  D  E  F  G  H  I\n");
}