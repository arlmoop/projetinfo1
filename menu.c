#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "header.h"
#include "mouvementbarriere.h"
#include "mouvementpoins.h"
#include "menu.h"

//Fonction permettant de presenter le jeu et obtenir les informations necessaires au lancement de la partie
void menudepart (char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur, char avatar[4]) {
    int c; //Choisir de consulter l'aide ou pas
    printf("BIENVENUE DANS LE JEU DU QUORIDOR\n\n");
    do{
    printf("Commencer la partie : 1\nConsulter la page d'aides : 2\n");
    scanf("%d", &c);
    }while(c!=1&&c!=2);
    //Aide et regles principales
    if(c==2){
        printf("\nLe premier joueur a commencer est tire au hasard.\n");
        printf("Objectif : Vous devez atteindre la ligne opposee avec votre pion avant vos adversaires.\n");
        printf("Vous pouvez deplacer votre pion, poser des barrieres pour bloquer les autres joueurs ou passer votre tour.\n");
        printf("Si vous jouez a 2, chaque joueur a 10 barrieres a placer.\nSi vous jouez a 4, chaque joueur en a 5.\nLe jeu se termine lorsque l'un des joueurs atteint la ligne en face de sa position de depart.\n");
    }

    do {
        printf("\nVoulez vous jouez avec deux ou quatres joueurs ? :");
        scanf("%d", nombrejoueur);
        if (*nombrejoueur!=2 && *nombrejoueur!=4) {
            printf("\nERREUR : Vous devez choisir 2 ou 4 joueurs\n");
        }
    } while (*nombrejoueur!=2 && *nombrejoueur!=4);

    if (*nombrejoueur >= 2) {
        printf("Entrez le prenom du joueur 1 :\n");
        scanf("%s", prenomjoueur1);
        getchar();
        printf("Joueur 1, choisissez votre pion en entrant un unique caractere :\n");
        scanf("%c", &avatar[0]);
        getchar();

        printf("Entrez le prenom du joueur 2 :\n");
        scanf("%s", prenomjoueur2);
        getchar();
        printf("Joueur 2, choisissez votre pion en entrant un unique caractere :\n");
        scanf("%c", &avatar[1]);
        getchar();

    }
    if (*nombrejoueur >= 4) {
        printf("Entrez le prenom du joueur 3 :\n");
        scanf("%s", prenomjoueur3);
        getchar();
        printf("Joueur 3, choisissez votre pion en entrant un unique caractere :\n");
        scanf(" %c", &avatar[2]);
        getchar();

        printf("Entrez le prenom du joueur 4 :\n");
        scanf("%s", prenomjoueur4);
        getchar();
        printf("Joueur 4, choisissez votre pion en entrant un unique caractere :\n");
        scanf(" %c", &avatar[3]);
        getchar();

    }
}

//Creation du plateau et remplissage des cases
void creationplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int nombrejoueur, coordonnees *pion1, coordonnees *pion2,
  coordonnees *pion3, coordonnees *pion4, char avatar[4]) {
    
  int h;
    //v compte les cases verticales et h horizontales
  for(int v=0; v<17; v++){
    h=0;
      //Chaque case etant composées de 3 caracteres, on initialise 51 cases par ligne et 17 cases par colonne
    for (int i=0; i<8 ;i++) {
        //Case 1, là ou les joueurs se deplacent
      plateau[v][h]=' ';
      h++;
      plateau[v][h]='.';
      h++;
      plateau[v][h]=' ';
      h++;
        //case 2, pour les barrieres verticales
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
    }
      //case 1 pour finir la ligne
    plateau[v][h]=' ';
    h++;
    plateau[v][h]='.';
    h++;
    plateau[v][h]=' ';
  }

  for(int v=1; v<16; v+=2) {
    h=0;
      //Meme chose qu'au dessus ma ceci represente les lignes où le joueur ne se deplace pas
    for (int j=0; j<8 ;j++) {
        //Case 1 pour les barrieres horizontales
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
        //Case 2 pour les coins de cases
      plateau[v][h]=' ';
      h++;
      plateau[v][h]='+';
      h++;
      plateau[v][h]=' ';
      h++;
    }
    plateau[v][h]=' ';
    h++;
    plateau[v][h]=' ';
    h++;
    plateau[v][h]=' ';
  }
  if (nombrejoueur >= 2) {
        plateau[0][24]=' ';
        plateau[0][25]=avatar[0];//on place le joueur 1 en bas du tableau
        plateau[0][26]=' ';
        pion1->ligne=1;
        pion1->colonne='I';

        plateau[16][24]=' ';
        plateau[16][25]=avatar[1];
        plateau[16][26]=' ';
        pion2->ligne=17;
        pion2->colonne='I';
    }
    if (nombrejoueur >= 4) {
        plateau[8][0]=' ';
        plateau[8][1]=avatar[2];
        plateau[8][2]=' ';
        pion3->ligne=9;
        pion3->colonne='A';
        
        plateau[8][48]=' ';
        plateau[8][49]=avatar[3];
        plateau[8][50]=' ';
        pion4->ligne=9;
        pion4->colonne='Q';
    }
}
// sous programme affichant le tableau
void affichageplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], char prenomjoueur1[], char prenomjoueur2[],
    char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur, int tourjoueur, char avatar[4], int reste1, int reste2, int reste3, int reste4) {
    int nombre_tour;
    nombre_tour=tourjoueur;
    printf ("\n     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n"); // les coordonnées des coonnes du plateau
    printf("    ___________________________________________________\n"); // les délimitations du plateau

    for (int e=0; e<TAILLEPLATEAUVERTICALE; e++) {
        if (e<9) {
            printf(" %d |", e+1);
        } else {
            printf("%d |", e+1);//coordonnees des lignes
        }
        for (int f=0; f<TAILLEPLATEAUHORIZONTALE; f++) {
            printf("%c", plateau[e][f]);
        }
        printf("| %d  ", e+1);
        printf("\n");
    }

    printf("   |___________________________________________________|\n");
    printf("     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n\n");

    if (nombre_tour == 1) {
        printf("\n  Joueur 1 : %s", prenomjoueur1);
    } else if (nombre_tour == 2) {
        printf("\n  Joueur 2 : %s", prenomjoueur2);
    } else if (nombre_tour == 3) {
        printf("\n  Joueur 3 : %s", prenomjoueur3);
    } else if (nombre_tour == 4) {
        printf("\n  Joueur 4 : %s", prenomjoueur4);
    }
}

