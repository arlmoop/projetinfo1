#include <stdio.h>
#include <stdlib.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "header.h"


void deplacementpion(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], coordonnees pion) {
  //faut definir les coordonnees de depart
  int errmouv=0;
  int mouvement;
  int pionchemin=0;
  do {
  printf("Saisissez une dirction valide :\n1 gauche 2 droite 3 haut 4 bas\n");
  scanf("%d", &mouvement);
  //pion puis barriere

  if (mouvement<1 || mouvement>4
   || (pion.colonne=='A' && mouvement==1 || pion.colonne=='Q' && mouvement==2 || pion.ligne==1 && mouvement==3 || pion.ligne==17 && mouvement==4)
   || (mouvement==1 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1-3]=='|')
   || (mouvement==2 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1+3]=='|')
   || (mouvement==3 && plateau[pion.ligne-1-1][(pion.colonne-'A')*3+1]=='-')
   || (mouvement==4 && plateau[pion.ligne-1+1][(pion.colonne-'A')*3+1]=='-')
   || ((mouvement==1 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1-6]!='.') && (plateau[pion.ligne-1][(pion.colonne-'A')*3+1-9]=='|'))
   || ((mouvement==2 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1+6]!='.') && (plateau[pion.ligne-1][(pion.colonne-'A')*3+1+9]=='|'))
   || ((mouvement==3 && plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1]!='.') && (plateau[pion.ligne-1-4][(pion.colonne-'A')*3+1]=='-'))
   || ((mouvement==4 && plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1]!='.') && (plateau[pion.ligne-1+4][(pion.colonne-'A')*3+1]=='-'))) {
    if(pionchemin==0) {
      if(mouvement==1) {
        plateau[pion.ligne-1][(pion.colonne-'A')*3+1-6]='.';
        plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='1';
      }
      if(mouvement==2) {
        plateau[pion.ligne-1][(pion.colonne-'A')*3+1+6]='.';
        plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='1';
      }
      if(mouvement==3) {
        plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1]='.';
        plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='1';
      }
      if(mouvement==4) {
        plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1]='.';
        plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='1';
      }
    }
   }

  ///////////////////////////////////////////////////

  for (int i=0; i < TAILLEPLATEAUVERTICALE; i++) {
    for (int j=0; j < TAILLEPLATEAUHORIZONTALE; j++) {
      if (plateau[i][j] == '1') {
        pion.ligne=i+1;
        pion.colonne=(j-1)/3+'A';
      }
    }
  }


  //pion qui sort du plateau
  if(pion.colonne=='A' && mouvement==1 || pion.colonne=='Q' && mouvement==2 || pion.ligne==1 && mouvement==3 || pion.ligne==17 && mouvement==4) {
    errmouv++;
    //plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='1'; //remettre le pion sur sa case precedente
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


    ////////////////////////////////////////////
  } while (mouvement <1 || mouvement>4 || errmouv>0);
    ///////////////////////////////////////////

  if(pionchemin==0) {
    if(mouvement==1) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1-6]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==2) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1+6]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==3) {
      plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==4) {
      plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
  }
  else {
    if(mouvement==1) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1-12]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==2) {
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1+12]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==3) {
      plateau[pion.ligne-1-4][(pion.colonne-'A')*3+1]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
    if(mouvement==4) {
      plateau[pion.ligne-1+4][(pion.colonne-'A')*3+1]='1';
      plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
    }
  }
}