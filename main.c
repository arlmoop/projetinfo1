#include <stdio.h>
#include "header.h"

int main() {
    char prenomjoueur1[20], prenomjoueur2[20], prenomjoueur3[20], prenomjoueur4[20];
    int nombrejoueur;
    menudepart(prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

    char plateau[TAILLEPLATEAU][TAILLEPLATEAU];
    creationplateau(plateau, nombrejoueur);
    affichageplateau(plateau);
    return 0;
}
