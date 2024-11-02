#include "menu.h"
#include "mouvementpoins.h"

int main() {

    char prenomjoueur1[20], prenomjoueur2[20], prenomjoueur3[20], prenomjoueur4[20];
    int nombrejoueur;
    menudepart(prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

    char plateau[TAILLEPLATEAU][TAILLEPLATEAU];
    creationplateau(plateau, nombrejoueur);
    affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

    int joueurenmouvement =1;
    int a =0;
    do {
        deplacementpion(plateau, joueurenmouvement);
        affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

        joueurenmouvement=joueurenmouvement+1;
        if (joueurenmouvement>nombrejoueur) {
            joueurenmouvement=1;
        }
        a=a+1;
    } while (a<10);
}
