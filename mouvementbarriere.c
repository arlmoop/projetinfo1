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

coordonnees pose_barriere(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere,
                          coordonnees coordonnees_b) {
    do {
        do {
            printf("\nChoisissez les coordonnees de l'emplacement de la barriere (lettre puis chiffre):");
            getchar();
            scanf("%c%d", &coordonnees_b.colonne, &coordonnees_b.ligne);
            coordonnees_b.colonne = toupper(coordonnees_b.colonne);
            if (coordonnees_b.colonne < 'A' || coordonnees_b.colonne > 'Z' || coordonnees_b.ligne < 1 || coordonnees_b.
                ligne > 17) {
                printf("\nERREUR : Veuillez saisir une coordonnee possible");
            }
        } while (coordonnees_b.colonne < 'A' || coordonnees_b.colonne > 'Z' || coordonnees_b.ligne < 1 || coordonnees_b.
                 ligne > 17);
        if ((coordonnees_b.ligne - 1) % 2 == 1) {
            if ((coordonnees_b.colonne - 'A') % 2 == 0) {
                plateau[coordonnees_b.ligne - 1][(coordonnees_b.colonne - 'A') * 3] = '-';
                plateau[coordonnees_b.ligne - 1][(coordonnees_b.colonne - 'A') * 3 + 1] = '-';
                plateau[coordonnees_b.ligne - 1][(coordonnees_b.colonne - 'A') * 3 + 2] = '-';
            } else if ((coordonnees_b.colonne - 'A') % 2 == 1) {
                printf("Impossible\n");
            }
        } else if ((coordonnees_b.ligne - 1) % 2 == 0) {
            if ((coordonnees_b.colonne - 'A') % 2 == 0) {
                printf("Impossible\n");
            } else if ((coordonnees_b.colonne - 'A') % 2 == 1) {
                plateau[coordonnees_b.ligne - 1][(coordonnees_b.colonne - 'A') * 3 + 1] = '|';
            }
        }
    } while ((coordonnees_b.ligne - 1) % 2 == 1 && (coordonnees_b.colonne - 'A') % 2 == 1
             || (coordonnees_b.ligne - 1) % 2 == 0 && (coordonnees_b.colonne - 'A') % 2 == 0
             || coordonnees_b.ligne < 1 || coordonnees_b.ligne > 17 || coordonnees_b.colonne < 'A' || coordonnees_b.
             colonne > 'Q');
    printf("Coordonnees choisies : %d %d\n", coordonnees_b.colonne - 'A', coordonnees_b.ligne);
    return coordonnees_b;
}

void pose2(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere,
           coordonnees coordonnees_b) {
    coordonnees coordonnees_b1, coordonnees_b2;
    int erreur;
    do {
        erreur = 0;
        printf("\nBarriere 1 :");
        coordonnees_b1 = pose_barriere(plateau, mouvement_barriere, coordonnees_b);
        printf("\nBarriere 2 :");
        coordonnees_b2 = pose_barriere(plateau, mouvement_barriere, coordonnees_b);

        if ((coordonnees_b1.ligne == coordonnees_b2.ligne && abs(coordonnees_b1.colonne - coordonnees_b2.colonne) != 2)
            || (coordonnees_b1.colonne == coordonnees_b2.colonne && abs(coordonnees_b1.ligne - coordonnees_b2.ligne) !=
                2)) {
            erreur++;
            printf("Erreur : Les barrières doivent être adjacentes.\n");
            plateau[coordonnees_b1.ligne - 1][(coordonnees_b1.colonne - 'A') * 3] = ' ';
            plateau[coordonnees_b1.ligne - 1][(coordonnees_b1.colonne - 'A') * 3 + 1] = ' ';
            plateau[coordonnees_b1.ligne - 1][(coordonnees_b1.colonne - 'A') * 3 + 2] = ' ';

            plateau[coordonnees_b2.ligne - 1][(coordonnees_b2.colonne - 'A') * 3] = ' ';
            plateau[coordonnees_b2.ligne - 1][(coordonnees_b2.colonne - 'A') * 3 + 1] = ' ';
            plateau[coordonnees_b2.ligne - 1][(coordonnees_b2.colonne - 'A') * 3 + 2] = ' ';
        }

        if ((coordonnees_b1.colonne-'A')*3+1==(coordonnees_b2.colonne-'A')*3+1) {
            if (coordonnees_b2.ligne-1>coordonnees_b1.ligne-1) {
                if (plateau[coordonnees_b1.ligne-1+1][(coordonnees_b1.colonne-'A')*3+1+2]=='-'
                    || plateau[coordonnees_b1.ligne-1+1][(coordonnees_b1.colonne-'A')*3+1+2]=='|') {
                    printf("1");
                    erreur++;
                    printf("croisement de barriere\n");
                }
            }
            if (coordonnees_b1.ligne-1>coordonnees_b2.ligne-1) {
                if (plateau[coordonnees_b1.ligne+1][coordonnees_b1.colonne-2]=='-' ||
                    plateau[coordonnees_b1.ligne+1][coordonnees_b1.colonne-2]=='|') {
                    printf("2");
                    erreur++;
                    printf("croisement de barriere\n");
                }
            }
        }
        if (coordonnees_b1.ligne==coordonnees_b2.ligne) {
            if ((coordonnees_b2.colonne-'A')*3+1>(coordonnees_b1.colonne-'A')*3+1) {
                if (plateau[coordonnees_b1.ligne-1+1][(coordonnees_b1.colonne-'A')*3+1+1]=='|'
                    || plateau[coordonnees_b1.ligne-1+1][(coordonnees_b1.colonne-'A')*3+1+1]=='-') {
                    printf("3");
                    erreur++;
                    printf("croisement de barriere\n");
                }
            }
            if ((coordonnees_b1.colonne-'A')*3+1>(coordonnees_b2.colonne-'A')*3+1) {
                if (plateau[coordonnees_b1.ligne-1+1][(coordonnees_b1.colonne-'A')*3+1-1]=='|'
                    || plateau[coordonnees_b1.ligne-1+1][(coordonnees_b1.colonne-'A')*3+1-1]=='-') {
                    erreur++;
                    printf("4");
                    printf("croisement de barriere\n");
                }
            }
        }

    } while (erreur > 0);
}
