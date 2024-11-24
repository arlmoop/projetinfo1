#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "header.h"
#include "mouvementbarriere.h"
#include "mouvementpoins.h"
#include "menu.h"


// Fonction pour vérifier si la case est valide et si elle est vide

coordonnees pose_barriere (char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coordonnees_b) {
    do {
      do {
        printf("\nChoisissez les coordonnees de l'emplacement de la barriere (lettre puis chiffre):");
        getchar();
        scanf("%c%d", &coordonnees_b.colonne, &coordonnees_b.ligne);
        coordonnees_b.colonne=toupper(coordonnees_b.colonne);
        if (coordonnees_b.colonne<'A' || coordonnees_b.colonne>'Z' || coordonnees_b.ligne<1 || coordonnees_b.ligne>17) {
          printf("\nERREUR : Veuillez saisir une coordonnee possible");
        }
      } while (coordonnees_b.colonne<'A' || coordonnees_b.colonne>'Z' || coordonnees_b.ligne<1 || coordonnees_b.ligne>17);
      if((coordonnees_b.ligne-1)%2==1) {
        if((coordonnees_b.colonne-'A')%2==0) {
          plateau[coordonnees_b.ligne-1][(coordonnees_b.colonne-'A')*3]='-';
          plateau[coordonnees_b.ligne-1][(coordonnees_b.colonne-'A')*3+1]='-';
          plateau[coordonnees_b.ligne-1][(coordonnees_b.colonne-'A')*3+2]='-';
        }
        else if((coordonnees_b.colonne-'A')%2==1) {
          printf("Impossible\n");
        }
      }
      else if((coordonnees_b.ligne-1)%2==0) {
        if((coordonnees_b.colonne-'A')%2==0) {
          printf("Impossible\n");
        }
        else if((coordonnees_b.colonne-'A')%2==1) {
          plateau[coordonnees_b.ligne-1][(coordonnees_b.colonne-'A')*3+1]='|';
        }
      }
    } while ( (coordonnees_b.ligne-1)%2==1 && (coordonnees_b.colonne-'A')%2==1
      || (coordonnees_b.ligne-1)%2==0 && (coordonnees_b.colonne-'A')%2==0
      || coordonnees_b.ligne<1 || coordonnees_b.ligne>17 || coordonnees_b.colonne<'A' || coordonnees_b.colonne>'Q');
    printf("Coordonnees choisies : %d %d\n", coordonnees_b.colonne-'A', coordonnees_b.ligne);
    return coordonnees_b;
}

void pose2(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coordonnees_b) {
  coordonnees coordonnees_b1, coordonnees_b2;
  int ligne_diff, colonne_diff, erreur;
  do {
    erreur=0;
    printf("\nBarriere 1 :");
    coordonnees_b1 = pose_barriere(plateau, mouvement_barriere, coordonnees_b);
    printf("\nBarriere 2 :");
    coordonnees_b2 = pose_barriere(plateau, mouvement_barriere, coordonnees_b);

    ligne_diff = coordonnees_b1.ligne - coordonnees_b2.ligne;
    colonne_diff = coordonnees_b1.colonne - coordonnees_b2.colonne;

    if ((colonne_diff != 0 && colonne_diff != -2 && colonne_diff != 2) || (ligne_diff != 0 && ligne_diff != 2 && ligne_diff != -2)){
      erreur++;
      plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3+1] = ' ';
      plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3+1] = ' ';
      printf("2");
    }
    if ((ligne_diff != 0 && ligne_diff != 2 && ligne_diff != -2) || (colonne_diff != 0 && colonne_diff != 2 && colonne_diff != -2)){
      erreur++;
      plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3+1] = ' ';
      plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3+1] = ' ';
      printf("1");
    }

    if (coordonnees_b1.colonne==coordonnees_b2.colonne) {
      if (coordonnees_b2.ligne>coordonnees_b1.ligne) {
        if (plateau[coordonnees_b1.ligne+1][coordonnees_b1.colonne+2]=='-') {
          erreur++;
          printf("croisement de barriere\n");
        }
      }
      if (coordonnees_b1.ligne>coordonnees_b2.ligne) {
        if (plateau[coordonnees_b1.ligne+1][coordonnees_b1.colonne-2]=='-') {
          erreur++;
          printf("croisement de barriere\n");
        }
      }
    }
    if (coordonnees_b1.ligne==coordonnees_b2.ligne) {
      if (coordonnees_b2.colonne>coordonnees_b1.colonne) {
        if (plateau[coordonnees_b1.colonne+3][coordonnees_b1.colonne+1]=='|') {
          erreur++;
          printf("croisement de barriere\n");
        }
      }
      if (coordonnees_b1.colonne>coordonnees_b2.colonne) {
        if (plateau[coordonnees_b1.colonne+3][coordonnees_b1.colonne-1]=='|') {
          erreur++;
          printf("croisement de barriere\n");
        }
      }
    }

  } while (erreur>0);
}
