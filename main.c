#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "header.h"
#include "menu.h"
#include "mouvementbarriere.h"
#include "mouvementpoins.h"

int main() {

    srand(time(NULL));
    //creation des variables pour le prenom des joueurs
    char prenomjoueur1[20], prenomjoueur2[20], prenomjoueur3[20], prenomjoueur4[20];
    int nombrejoueur;
    int mouvement_barriere, tourjoueur ;
    char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE];
    coordonnees coordonnees_b, coordonnees_b1, coordonnees_b2, pion;

    //execution de la fonction qui affiche le menu
    menudepart(prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

    if(nombrejoueur==2){
        tourjoueur=1+rand()%2;
    }
    else if(nombrejoueur==4){
        tourjoueur=1+rand()%4;
    }

    creationplateau(plateau, nombrejoueur);
    affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

    do{//infini pr l'instant
        if(tourjoueur==1){
            printf("\nAu tour de %s\n", prenomjoueur1);
        }
        else if(tourjoueur==2){
            printf("\nAu tour de %s\n", prenomjoueur2);
        }
        else if(tourjoueur==3){
            printf("\nAu tour de %s\n", prenomjoueur3);
        }
        else if(tourjoueur==4){
            printf("\nAu tour de %s\n", prenomjoueur4);
        }
        do {
            printf("\n1. Deplacer le pion\n2. Poser une barriere\n3. Passer votre tour\nChoisissez une valeur valide :");
            scanf("%d", &mouvement_barriere);
            if (mouvement_barriere<'1'&&mouvement_barriere>'3') {
                tourjoueur--;
            }
        } while (mouvement_barriere!=1 && mouvement_barriere!=2 && mouvement_barriere!=3);
        if (mouvement_barriere==1) {
            pion.ligne = 0;
            pion.colonne = 0;
            deplacementpion(plateau, pion);
            affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);
        }
        else if (mouvement_barriere==2) {
            coordonnees_b.ligne = 0;
            coordonnees_b.colonne = 0;
            pose2(plateau, mouvement_barriere, coordonnees_b);
            affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);
        }
        tourjoueur++;
        if (tourjoueur>nombrejoueur) {
            tourjoueur=1;
        }
    }while(5);
    return 0;
}
