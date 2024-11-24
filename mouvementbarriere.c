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

coordonnees pose_barriere (char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], coordonnees coordonnees_b) {
	do {
		printf("\nChoisissez les coordonnees de l'emplacement de la barriere :");//affichage dans la console 
		getchar();
		scanf("%c%d", &coordonnees_b.colonne, &coordonnees_b.ligne);//recuperation des coordonnees
		coordonnees_b.colonne=toupper(coordonnees_b.colonne);// sert a convertir les valeurs saisie en majuscule
		if (coordonnees_b.colonne<'A' || coordonnees_b.colonne>'Q' || coordonnees_b.ligne<1 || coordonnees_b.ligne>17) {
			printf("\nERREUR : Veuillez saisir une coordonnee possible");// blindage qui permet de saisir une coordonnee possible (c'est a dire comprise entre A et Q et entre 1 et 17)
		}
		else if ((coordonnees_b.ligne-1)%2 == 1) {//verifie si la ligne est impaire 
			if ((coordonnees_b.colonne-'A')%2 == 1) {//verifie si la colonne est impaire 
				printf("Impossible\n");//impossible car ce n'est pas une case jouable du plateau
			}
		}
		else if ((coordonnees_b.ligne - 1) % 2 == 0) {//verifie si la ligne est paire 
			if ((coordonnees_b.colonne - 'A') % 2 == 0) {//verifie si la colonne est paire
				printf("Impossible\n");//impossible car ce n'est pas une case jouable du plateau
			}
		}
	} while ((coordonnees_b.ligne - 1) % 2 == 1 && (coordonnees_b.colonne - 'A') % 2 == 1
	         || (coordonnees_b.ligne - 1) % 2 == 0 && (coordonnees_b.colonne - 'A') % 2 == 0
	         || coordonnees_b.ligne < 1 || coordonnees_b.ligne > 17 || coordonnees_b.colonne < 'A' || coordonnees_b.colonne > 'Q');//blindage qui permet de verifier que les valeurs saisies soit possible
	printf("Coordonnees choisies : %c %d\n", coordonnees_b.colonne, coordonnees_b.ligne);// affichage des coordonnees pour une meilleur visibilite
	return coordonnees_b;
}

void pose2(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], coordonnees coordonnees_b) {
	coordonnees coordonnees_b1, coordonnees_b2;// creation de structure qui permettent de stocker les valeurs des coordonnees de la barrieres 1 et de la 2
	int erreur;// creation d'une variable erreur qui permet une fois negative de recommencer le programme de saisie
	do {
		erreur=0;//initialisation de la variable erreur 
		printf("\nBarriere 1 :");
		coordonnees_b1=pose_barriere(plateau, coordonnees_b);//recuperation des valeurs des coordonnées 
		printf("\nBarriere 2 :");
		coordonnees_b2=pose_barriere(plateau, coordonnees_b);//recuperation des valeurs des coordonnées 


        if((coordonnees_b1.ligne!=coordonnees_b2.ligne) && (coordonnees_b1.colonne!=coordonnees_b2.colonne)){
            erreur++;
        }
        else { 
    		if ((coordonnees_b1.ligne == coordonnees_b2.ligne && abs(coordonnees_b1.colonne - coordonnees_b2.colonne) != 2)
    		        || (coordonnees_b1.colonne == coordonnees_b2.colonne && abs(coordonnees_b1.ligne - coordonnees_b2.ligne) != 2)) {
    			erreur++;
    			printf("\n\nErreur : Les barrieres doivent etre adjacentes et non confonues");
    		}
    		else {
    			if((plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3+1]=='-'
    			        ||plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3+1]=='|')
    			        ||(plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3+1]=='-'
    			           ||plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3+1]=='|')) {
    				erreur++;
    				printf("\n\nSuperpose");
    			}
    			else {
    			    ////////////////1111
    				if ((coordonnees_b1.ligne - 1) % 2 == 1) {
    					if ((coordonnees_b1.colonne - 'A') % 2 == 1) {
    						printf("Impossible\n");
    						erreur++;
    					}
    					else if((coordonnees_b1.colonne-'A')%2==0) {
    						plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3]='-';
    						plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3+1]='-';
    						plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3+2]='-';
    					}
    				}
    				else if ((coordonnees_b1.ligne - 1) % 2 == 0) {
    					if ((coordonnees_b1.colonne - 'A') % 2 == 0) {
    						printf("Impossible\n");
    						erreur++;
    					}
    					else if((coordonnees_b1.colonne-'A')%2==1) {
    						plateau[coordonnees_b1.ligne-1][(coordonnees_b1.colonne-'A')*3+1]='|';
    					}
    				}
    				////////////////////2222
    				if ((coordonnees_b2.ligne - 1) % 2 == 1) {
    					if ((coordonnees_b2.colonne - 'A') % 2 == 1) {
    						printf("Impossible\n");
    						erreur++;
    					}
    					else if((coordonnees_b2.colonne-'A')%2==0) {
    						plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3]='-';
    						plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3+1]='-';
    						plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3+2]='-';
    					}
    				}
    				else if ((coordonnees_b2.ligne - 1) % 2 == 0) {
    					if ((coordonnees_b2.colonne - 'A') % 2 == 0) {
    						printf("Impossible\n");
    						erreur++;
    					}
    					else if((coordonnees_b2.colonne-'A')%2==1) {
    						plateau[coordonnees_b2.ligne-1][(coordonnees_b2.colonne-'A')*3+1]='|';
    					}
    				}
    			}
    		}
		}

	} while (erreur>0);
}
