#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include "menu.h"
#include "mouvementbarriere.h"
#include "mouvementpoins.h"
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
/////::dcfzv
int main() {
    srand(time(NULL));
    //creation des variables pour le prenom des joueurs et du plateau
    char prenomjoueur1[20], prenomjoueur2[20], prenomjoueur3[20], prenomjoueur4[20], plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE];
    //mouvement_barriere gere l'action faite par le joueur
    int nombrejoueur,mouvement_barriere, tourjoueur=0;
    // 4 cases pour 4 joueurs
    char avatar[4];
    //Structures gerants les barrieres et les pions
    coordonnees coordonnees_b, coordonnees_b1, coordonnees_b2, pion, pion1, pion2, pion3, pion4;
    //Barrieres restantes
    int reste1=0, reste2=0, reste3=0, reste4=0;
    //Variable qui lorsqu'elle devient positive un joueur a gagne la partie
    int victoire=0;
    //execution de la fonction qui affiche le menu
    menudepart(prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur, avatar);

    //Combien de barrieres chacun
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
    //Qui commence ?
    if(nombrejoueur==2){
        tourjoueur=1+rand()%2;
    }
    else if(nombrejoueur==4){
        tourjoueur=1+rand()%4;
    }
    
    creationplateau(plateau, nombrejoueur, &pion1, &pion2, &pion3, &pion4, avatar);
    //Verification des coordonnes
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
    //Verification des pions
    if(nombrejoueur>=2){
        printf("\nPions :\n");
        printf("1 : %c\n", avatar[0]);
        printf("2 : %c\n", avatar[1]);
        if(nombrejoueur==4){
            printf("3 : %c\n", avatar[2]);
            printf("4 : %c\n", avatar[3]);
        }
    }
    //On connait toutes les infos donc on peut afficher le plateau
    affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur, avatar,
        tourjoueur, reste1, reste2, reste3, reste4);
    //Condition de victoire
    do{
        //Saisie valide

        do {
            printf("\n1. Deplacer le pion\n2. Poser une barriere\n3. Passer votre tour\nChoisissez une valeur valide :");
            scanf("%d", &mouvement_barriere);
        } while (mouvement_barriere!=1 && mouvement_barriere!=2 && mouvement_barriere!=3);
        //Le joueur a choisi de se deplacer
        if (mouvement_barriere==1) {
            pion.ligne = 0;
            pion.colonne = 0;
            deplacementpion(plateau, pion, avatar, tourjoueur, &nombrejoueur, victoire);
        }
        //Le joueur a choisi de poser une barriere
        else if (mouvement_barriere==2) {
            coordonnees_b.ligne = 0;
            coordonnees_b.colonne = 0;
            //Pose de barriere
            pose2(plateau, mouvement_barriere, coordonnees_b);
            //Enlever une barriere au joueur
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
        }
        //Afficher la plateau apres chaque tour
        affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur, reste1, reste2, reste3, reste4, tourjoueur, avatar);
        //Passer au joueur suivant
        tourjoueur++;
        //Revenir au joueur 1 quand on atteint le dernier joueur
        if (tourjoueur>nombrejoueur) {
            tourjoueur=1;
        }

    }while(victoire<=0);//Condtion de victoire
    printf("LE JOUEUR %d A GAGNE LA PARTIE", tourjoueur-1);
    return 0;
}