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

coordonnees pose_barriere (char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coor_donnee) {
    char coordonnee_barriere[4];
    int v=0, h=0;
    char lettre;
    int nombre;
    if (mouvement_barriere==2) {
        do {
            printf("Choisissez les coordonnées de l'emplacement de la barriere :");
            fflush(stdin);
            scanf("%c%d", &coor_donnee.colonne, &coor_donnee.ligne);
            printf("coord : %d %d\n", coor_donnee.colonne-'A', coor_donnee.ligne);
            if((coor_donnee.ligne-1)%2==1) {
                if((coor_donnee.colonne-'A')%2==0) {
                    plateau[coor_donnee.ligne-1][(coor_donnee.colonne-'A')*3]='-';
                    plateau[coor_donnee.ligne-1][(coor_donnee.colonne-'A')*3+1]='-';
                    plateau[coor_donnee.ligne-1][(coor_donnee.colonne-'A')*3+2]='-';
                }
                else if((coor_donnee.colonne-'A')%2==1) {
                    printf("Impossible\n");
                }
            }
            else if((coor_donnee.ligne-1)%2==0) {
                if((coor_donnee.colonne-'A')%2==0) {
                    printf("Impossible\n");
                }
                else if((coor_donnee.colonne-'A')%2==1) {
                    plateau[coor_donnee.ligne-1][(coor_donnee.colonne-'A')*3+1]='|';
                }
            }
        } while ( (coor_donnee.ligne-1)%2==1 && (coor_donnee.colonne-'A')%2==1
            || (coor_donnee.ligne-1)%2==0 && (coor_donnee.colonne-'A')%2==0
            || coor_donnee.ligne<1 || coor_donnee.ligne>17 || coor_donnee.colonne<'A' || coor_donnee.colonne>'Q');
    }
    return coor_donnee;
}