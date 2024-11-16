//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>
#include "header.h"
#include "mouvementpoins.h"

//fonction pour deplacer le pion du joueur qui est en train de jouer
void deplacementpion(char plateau[TAILLEPLATEAU][TAILLEPLATEAU], int joueurenmouvement) {
    int x=-1, y=-1;// variable suivant les coordonnées des pions
    int numerojoueur=joueurenmouvement;//initalisation du numero du joueur avec le joueur qui joue
    int choix;//variable stockant le choix du joueur pour la direction des pions

    //recher de la position du pion sur le plateau
    for (int i=0; i<TAILLEPLATEAU; i++) {//boucle qui parcours le plateau a la recherche de la position du pion
        for (int j=0; j<TAILLEPLATEAU; j++) {//boucle qui parcours le plateau a la recherche de la position du pion
            if (plateau[i][j] == '1'+numerojoueur-1) {/*verification si le pion est sur la case
                parcourue avec par le test*/
                x=i;//enregistre la ligne sur laquelle est le pion
                y=j;//enregistre la ligne sur laquelle est le pion
                plateau[i][j] = '.';//reforme la case pour deplacé le pion
            }
        }
    }

    //demande a l'utilisateur de chosir une direction pour les pions
    printf("Joueurs %d, choisissez une direction valide\n", numerojoueur);
    printf("1->haut, 2->bas, 3->gauche, 4->droite :\n");//les differents choix possibles pour les directions

    //blindage pour que la valeur saisie par l'utilisateur lors du choix soit correcte
    do {
        scanf("%d", &choix);//demande a l'utilisateur de faire un choix

        //test pour afficher un message d'erreur
        if ((choix==1 && x==0) || (choix==2 && x==TAILLEPLATEAU-1) || (choix==3 && y==0)
        || (choix==4 && y==TAILLEPLATEAU-1)) {
            //affichage du message d'erreur ainsi que les choix possible pour les directions
            printf("ERREUR : Le deplacement est invalde\n");
            printf("1->haut, 2->bas, 3->gauche, 4->droite :\n");
        }
    } while ((choix==1 && x==0) || (choix==2 && x==TAILLEPLATEAU-1) || (choix==3 && y==0)
        || (choix==4 && y==TAILLEPLATEAU-1));//boucle si le choix de l'utilisateur est impossible

    if (choix==1) {
        x=x-1; //deplace le pions vers le haut
    } else if (choix==2) {
        x=x+1;//deplace le pions vers le bas
    } else if (choix==3) {
        y=y-1; //deplace le pions vers la gauche
    } else if (choix==4) {
        y=y+1; //deplace le pions vers la droite
    }

    plateau[x][y] = '1' + numerojoueur - 1; //positionnement deu pion dans sa nouvelle case
}
