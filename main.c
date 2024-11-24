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
    char av1, av2, av3, av4;
    int mouvement_barriere, tourjoueur ;
    char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE];
    coordonnees coordonnees_b, coordonnees_b1, coordonnees_b2, pion, pion1, pion2, pion3, pion4;
    int reste1, reste2, reste3, reste4;

    //execution de la fonction qui affiche le menu
    menudepart(prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur, &av1, &av2, &av3, &av4);
    
    if(nombrejoueur==2){
        reste1=10;
        reste2=10;
    }
    else if(nombrejoueur==4){
        reste1=5;
        reste2=5;
        reste3=5;
        reste4=5;
    }
    
    if(nombrejoueur==2){
        tourjoueur=1+rand()%2;
    }
    else if(nombrejoueur==4){
        tourjoueur=1+rand()%4;
    }

    creationplateau(plateau, nombrejoueur, &pion1, &pion2, &pion3, &pion4, av1, av2, av3, av4);
    //pr verifier si c les bonnes coordonnees
    if(nombrejoueur>=2){
        printf("\nCoordoonnees :\n");
        printf("1: %c", pion1.colonne);
        printf(" %d\n", pion1.ligne);
        printf("2: %c", pion2.colonne);
        printf(" %d\n", pion2.ligne);
        if(nombrejoueur==4){
            printf("3: %c", pion3.colonne);
            printf(" %d\n", pion3.ligne);
            printf("4: %c", pion4.colonne);
            printf(" %d\n", pion4.ligne);
        }
    }
    
    if(nombrejoueur>=2){
        printf("\nPions :\n");
        printf("1 : %c\n", av1);
        printf("2 : %c\n", av2);
        if(nombrejoueur==4){
            printf("3 : %c\n", av3);
            printf("4 : %c\n", av4);
        }
    }
    
    affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

    do{//infini pr l'instant
        if(tourjoueur==1){
            printf("\nAu tour de %s\n", prenomjoueur1);
            printf("Il vous reste %d barrieres\n", reste1); 
        }
        else if(tourjoueur==2){
            printf("\nAu tour de %s\n", prenomjoueur2);
            printf("Il vous reste %d barrieres\n", reste2); 
        }
        else if(tourjoueur==3){
            printf("\nAu tour de %s\n", prenomjoueur3);
            printf("Il vous reste %d barrieres\n", reste3); 
        }
        else if(tourjoueur==4){
            printf("\nAu tour de %s\n", prenomjoueur4);
            printf("Il vous reste %d barrieres\n", reste4);
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
            if(tourjoueur==1){
                reste1--;
            }
            else if(tourjoueur==2){
                reste2--;
            }
            else if(tourjoueur==3){
                reste3--;
            }
            else if(tourjoueur==4){
                reste4--;
            }
            affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);
        }
        tourjoueur++;
        if (tourjoueur>nombrejoueur) {
            tourjoueur=1;
        }
    }while(5);
    return 0;
}
