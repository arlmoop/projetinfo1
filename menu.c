//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>

int menudepart (char prenomjoueur1, char prenomjoueur2, char prenomjoueur3, char prenomjoueur4, int nombrejoueur) {
    printf("BIENVENUE DANS LE JEU DU QUORIDOR\n\n");
    printf("Voulez vous jouez avec deux ou quatres joueurs ? :");
    scanf("%d", &nombrejoueur);
    if (nombrejoueur >= 2) {
        printf("Entrez le prenom du joueur 1 :");
        scanf("%s", &prenomjoueur1);
        printf("\nEntrez le prenom du joueur 2 :");
        scanf("%s", &prenomjoueur2);
    }
    if (nombrejoueur >= 4) {
        printf("\nEntrez le prenom du joueur 3 :");
        scanf("%s", &prenomjoueur3);
        printf("\nEntrez le prenom du joueur 4 :");
        scanf("%s", &prenomjoueur4);
    }
    return prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, nombrejoueur;
}