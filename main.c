#include <stdio.h>
#include "header.h"

int main() {
    char prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4;
    int nombrejoueur;
    menudepart(prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, nombrejoueur);

    char plateau[TAILLEPLATEAU][TAILLEPLATEAU];
    creationplateau(plateau);
    affichageplateau(plateau);
    printf("hello from jaime");
}
