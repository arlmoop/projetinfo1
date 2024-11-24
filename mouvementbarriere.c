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
		printf("\nChoisissez les coordonnees de l'emplacement de la barriere :");
		getchar();
		scanf("%c%d", &coordonnees_b.colonne, &coordonnees_b.ligne);
		coordonnees_b.colonne=toupper(coordonnees_b.colonne);
		if (coordonnees_b.colonne<'A' || coordonnees_b.colonne>'Q' || coordonnees_b.ligne<1 || coordonnees_b.ligne>17) {
			printf("\nERREUR : Veuillez saisir une coordonnee possible");
		}
		else if ((coordonnees_b.ligne - 1) % 2 == 1) {
			if ((coordonnees_b.colonne - 'A') % 2 == 1) {
				printf("Impossible\n");
			}
		}
		else if ((coordonnees_b.ligne - 1) % 2 == 0) {
			if ((coordonnees_b.colonne - 'A') % 2 == 0) {
				printf("Impossible\n");
			}
		}
	} while ((coordonnees_b.ligne - 1) % 2 == 1 && (coordonnees_b.colonne - 'A') % 2 == 1
	         || (coordonnees_b.ligne - 1) % 2 == 0 && (coordonnees_b.colonne - 'A') % 2 == 0
	         || coordonnees_b.ligne < 1 || coordonnees_b.ligne > 17 || coordonnees_b.colonne < 'A' || coordonnees_b.colonne > 'Q');
	printf("Coordonnees choisies : %c %d\n", coordonnees_b.colonne, coordonnees_b.ligne);
	return coordonnees_b;
}

void pose2(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coordonnees_b) {
	coordonnees coordonnees_b1, coordonnees_b2;
	int erreur;
	do {
		erreur=0;
		printf("\nBarriere 1 :");
		coordonnees_b1=pose_barriere(plateau, mouvement_barriere, coordonnees_b);
		printf("\nBarriere 2 :");
		coordonnees_b2=pose_barriere(plateau, mouvement_barriere, coordonnees_b);


        if((coordonnees_b1.ligne!=coordonnees_b2.ligne) && (coordonnees_b1.colonne!=coordonnees_b2.colonne)){
            printf("11111");
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

		/*
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
		*/
	} while (erreur>0);
}
