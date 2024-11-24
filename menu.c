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

void menudepart (char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur, char avatar[4]) {
    int c;
    printf("BIENVENUE DANS LE JEU DU QUORIDOR\n\n");
    do{
    printf("Commencer la partie : 1\nConsulter la page d'aides : 2\n");
    scanf("%d", &c);
    }while(c!=1&&c!=2);
    if(c==2){
        printf("\nLe premier joueur a commencer est tire au hasard.\n");
        printf("Objectif : Vous devez atteindre la ligne opposee avec votre pion avant vos adversaires.\n");
        printf("Vous pouvez deplacer votre pion, poser des barrieres pour bloquer les autres joueurs ou passer votre tour.\n");
        printf("Si vous jouez a 2, chaque joueur a 10 barrieres a placer.\nSi vous jouez a 4, chaque joueur en a 5.\nLe jeu se termine lorsque l'un des joueurs atteint la ligne en face de sa position de depart.\n");
    }

    do {
        //Demande a l'utilisateur de choisir le nombre de joueur
        printf("\nVoulez vous jouez avec deux ou quatres joueurs ? :");
        //recuperation du nombre de joueur dans la variable
        scanf("%d", nombrejoueur);

        if (*nombrejoueur!=2 && *nombrejoueur!=4) { //test pour un message d'erreur
            printf("\nERREUR : Vous devez choisir 2 ou 4 joueurs\n"); //message d'erreur
        }
    } while (*nombrejoueur!=2 && *nombrejoueur!=4); //blindage pour avoir un nombre de joueur possible

    if (*nombrejoueur >= 2) { // test pour demander au 2 joueurs leurs prenoms
        printf("Entrez le prenom du joueur 1 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur1);//recuperation du prenom du joueur dans le tableau
        getchar();
        printf("Joueur 1, choisissez votre pion en entrant un unique caractere :\n");
        scanf("%c", &avatar[0]);
        getchar();

        printf("Entrez le prenom du joueur 2 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur2); //recuperation du prenom du joueur dans le tableau
        getchar();
        printf("Joueur 2, choisissez votre pion en entrant un unique caractere :\n");
        scanf("%c", &avatar[1]);
        getchar();

    }
    if (*nombrejoueur >= 4) { // test pour savoir si il ya plus de deux joueurs
        printf("Entrez le prenom du joueur 3 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur3); //recuperation du prenom du joueur dans le tableau
        getchar();
        printf("Joueur 3, choisissez votre pion en entrant un unique caractere :\n");
        scanf(" %c", &avatar[2]);
        getchar();

        printf("Entrez le prenom du joueur 4 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur4); //recuperation du prenom du joueur dans le tableau
        getchar();
        printf("Joueur 4, choisissez votre pion en entrant un unique caractere :\n");
        scanf(" %c", &avatar[3]);
        getchar();

    }
}

//creation du sous programme creant le plateau
void creationplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int nombrejoueur, coordonnees *pion1, coordonnees *pion2,
  coordonnees *pion3, coordonnees *pion4, char avatar[4]) {
  /*creation du plateau de 9x9*/
  int tourjoueurr=0;
  char caracterejoueur;

  int h;    //a=case_horizontale, k=case_verticale,
  for(int v=0; v<17; v++){
    h=0;
    for (int i=0; i<8 ;i++) {
      plateau[v][h]=' ';
      h++;
      plateau[v][h]='.';
      h++;
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
    }
    plateau[v][h]=' ';
    h++;
    plateau[v][h]='.';
    h++;
    plateau[v][h]=' ';
  }

  for(int v=1; v<16; v+=2) {
    h=0;
    for (int j=0; j<8 ;j++) {
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
      plateau[v][h]=' ';
      h++;
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
  if (nombrejoueur >= 2) {//test pour savoir le nombre de joueur dans la partie

        plateau[0][24]=' ';
        plateau[0][25]=avatar[0];
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
// sous programme affichant le tablea
void affichageplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], char prenomjoueur1[], char prenomjoueur2[],
    char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur) {

  printf ("\n     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n");//les coordonnées des cases du plateau
  printf("    ___________________________________________________\n");//les delimitations du plateau

  for (int e=0; e<TAILLEPLATEAUVERTICALE; e++) {
    if(e<9) {
      printf(" %d |", e+1);
    }
    else {
      printf("%d |", e+1);
    }
    for (int f=0; f<TAILLEPLATEAUHORIZONTALE; f++) {
      printf("%c", plateau[e][f]);

    }
    printf("| %d  ", e+1);
    if (e==1) {
      printf("  Joueur 1 : %s", prenomjoueur1);
    }
    if (e==4) {
      printf("  Joueur 2 : %s", prenomjoueur2);
    }
    if (e==7 && *nombrejoueur==4) {
      printf("  Joueur 3 : %s", prenomjoueur3);
    }
    if (e==10 && *nombrejoueur==4) {
      printf(" Joueur 4 : %s", prenomjoueur4);
    }
    printf("\n");
  }

  printf("   |___________________________________________________|\n");
  printf("     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n\n");
}
