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

void pose_barriere (char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coordonnee) {
    char coordonnee_barriere[4];
    int v=0, h=0;
    char lettre;
    int nombre;
    if (mouvement_barriere==2) {
        do {
            printf("Choisissez les coordonnées de l'emplacement de la barriere :");
            scanf("%c %d", &coordonnee.colonne, &coordonnee.ligne);
        } while (coordonnee.colonne<= 'A' || coordonnee.colonne>= 'Q');
        plateau[coordonnee.ligne-1][coordonnee.colonne-17]='c';


/*
        if ((coordonnee_barriere[2]>='A' && coordonnee_barriere[2]<='Q')
            && (coordonnee_barriere[0]>='0' && coordonnee_barriere[0]<='9')
            && coordonnee_barriere[1]>='0' && coordonnee_barriere[1]<='6') {
            int melange1, melange2, melange3;
            melange1 = coordonnee_barriere[0];
            melange2 = coordonnee_barriere[1];
            melange3 = coordonnee_barriere[2];
            coordonnee_barriere[0] = melange3;
            coordonnee_barriere[1] = melange1;
            coordonnee_barriere[2] = melange2;
            }

        if (coordonnee_barriere[1]>='A' && coordonnee_barriere[1]<='Q'
            && coordonnee_barriere[0]>='0' && coordonnee_barriere[0]<='9') {
            int melange1, melange2;
            melange1 = coordonnee_barriere[0];
            melange2 = coordonnee_barriere[1];
            coordonnee_barriere[0] = melange2;
            coordonnee_barriere[1] = melange1;
            }

        if (coordonnee_barriere[0]=='A') {
            h=1;
        }
        if (coordonnee_barriere[0]=='B') {
            h=4;
        }
        if (coordonnee_barriere[0]=='C') {
            h=7;
        }
        if (coordonnee_barriere[0]=='D') {
            h=10;
        }
        if (coordonnee_barriere[0]=='E') {
            h=13;
        }
        if (coordonnee_barriere[0]=='F') {
            h=16;
        }
        if (coordonnee_barriere[0]=='G') {
            h=19;
        }
        if (coordonnee_barriere[0]=='H') {
            h=22;
        }
        if (coordonnee_barriere[0]=='I') {
            h=25;
        }
        if (coordonnee_barriere[0]=='J') {
            h=28;
        }
        if (coordonnee_barriere[0]=='K') {
            h=31;
        }
        if (coordonnee_barriere[0]=='L') {
            h=34;
        }
        if (coordonnee_barriere[0]=='M') {
            h=37;
        }
        if (coordonnee_barriere[0]=='N') {
            h=40;
        }
        if (coordonnee_barriere[0]=='O') {
            h=43;
        }
        if (coordonnee_barriere[0]=='P') {
            h=46;
        }
        if (coordonnee_barriere[0]=='Q') {
            h=49;
        }

        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='\0') {
            v=0;
        }
        if (coordonnee_barriere[1]=='2' && coordonnee_barriere[2]=='\0') {
            v=1;
        }
        if (coordonnee_barriere[1]=='3' && coordonnee_barriere[2]=='\0') {
            v=2;
        }
        if (coordonnee_barriere[1]=='4' && coordonnee_barriere[2]=='\0') {
            v=3;
        }
        if (coordonnee_barriere[1]=='5' && coordonnee_barriere[2]=='\0') {
            v=4;
        }
        if (coordonnee_barriere[1]=='6' && coordonnee_barriere[2]=='\0') {
            v=5;
        }
        if (coordonnee_barriere[1]=='7' && coordonnee_barriere[2]=='\0') {
            v=6;
        }
        if (coordonnee_barriere[1]=='8' && coordonnee_barriere[2]=='\0') {
            v=7;
        }
        if (coordonnee_barriere[1]=='9' && coordonnee_barriere[2]=='\0') {
            v=8;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='0') {
            v=9;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='1') {
            v=10;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='2') {
            v=11;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='3') {
            v=12;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='4') {
            v=13;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='5') {
            v=14;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='6') {
            v=15;
        }
        if (coordonnee_barriere[1]=='1' && coordonnee_barriere[2]=='7') {
            v=16;
        }
        if (h%2==0 && v%2==0) {
            plateau[v][h]='|';
        }
        if (h%2==1 && v%2==1) {
            plateau[v][h-1]='-';
            plateau[v][h]='-';
            plateau[v][h+1]='-';
        }*/
    }
}