//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
typedef struct {
    int ligne;
    char colonne;
}coordonnees;

coordonnees pose_barriere (char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coordonnees_b) {
    if (mouvement_barriere==2) {
        do {
            printf("Choisissez les coordonnées de l'emplacement de la barriere :");
            fflush(stdin);
            scanf("%c%d", &coordonnees_b.colonne, &coordonnees_b.ligne);
            printf("coord : %d %d\n", coordonnees_b.colonne-'A', coordonnees_b.ligne);
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
    }
    return coordonnees_b;
}