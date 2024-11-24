#include <stdio.h>
#include <stdlib.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "header.h"
#include "mouvementbarriere.h"
#include "mouvementpoins.h"
#include "menu.h"

void deplacementpion(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], coordonnees pion, char avatar[4], int tourjoueur) {
  //faut definir les coordonnees de depart
  int errmouv;
  int mouvement;
  int pionchemin=0;
  char caracterejoueur;
  do {

    printf("Saisissez une dirction valide :\n1 gauche 2 droite 3 haut 4 bas\n");
    scanf("%d", &mouvement);
    //pion puis barriere
    errmouv=0;

    ///////////////////////////////////////////////////

  for (int i=0; i < TAILLEPLATEAUVERTICALE; i++) {
    for (int j=0; j < TAILLEPLATEAUHORIZONTALE; j++) {
      for (int t=0; t<4; t++) {
        if (tourjoueur==t+1) {
          if (plateau[i][j] == avatar[t]) {
            pion.ligne=i+1;
            pion.colonne=(j-1)/3+'A';
          }
        }
      }
    }
  }

  //saut de pion adversaire
  if(mouvement==1 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1-6]!='.') {
    if(plateau[pion.ligne-1][(pion.colonne-'A')*3+1-9]=='|') {
      errmouv++;
    }
    else {
      pionchemin++;
    }
  }
  if(mouvement==2 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1+6]!='.') {
    if(plateau[pion.ligne-1][(pion.colonne-'A')*3+1+9]=='|') {
      errmouv++;
    }
    else {
      pionchemin++;
    }
  }
  if(mouvement==3 && plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1]!='.') {
    if(plateau[pion.ligne-1-4][(pion.colonne-'A')*3+1]=='-') {
      errmouv++;
    }
    else {
      pionchemin++;
    }
  }
  if(mouvement==4 && plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1]!='.') {
    if(plateau[pion.ligne-1+4][(pion.colonne-'A')*3+1]=='-') {
      errmouv++;
    }
    else {
      pionchemin++;
    }
  }

  //pion qui sort du plateau
  if(pion.colonne=='A' && mouvement==1 || pion.colonne=='Q' && mouvement==2 || pion.ligne==1 && mouvement==3 || pion.ligne==17 && mouvement==4) {
    errmouv++;
  }

  //barriere bloque
  if(mouvement==1 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1-3]=='|') {
    errmouv++;
  }
  if(mouvement==2 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1+3]=='|') {
    errmouv++;
  }
  if(mouvement==3 && plateau[pion.ligne-1-1][(pion.colonne-'A')*3+1]=='-') {
    errmouv++;
  }
  if(mouvement==4 && plateau[pion.ligne-1+1][(pion.colonne-'A')*3+1]=='-') {
    errmouv++;
  }


    ////////////////////////////////////////////
  } while (mouvement <1 || mouvement>4 || errmouv>0);
    ///////////////////////////////////////////
    ///



  if(pionchemin==0) {
    if(mouvement==1) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1-6]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==2) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1+6]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==3) {
      plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==4) {
      plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
  }
  else {
    if(mouvement==1) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1-12]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==2) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1+12]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==3) {
      plateau[pion.ligne-1-4][(pion.colonne-'A')*3+1]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==4) {
      plateau[pion.ligne-1+4][(pion.colonne-'A')*3+1]=avatar[tourjoueur-1];
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
  }

}
