//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17

void pose_barriere (char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere) {
    char coordonnee_barriere[4];
    if (mouvement_barriere==2) {
        printf("Choisissez les coordonnées de l'emplacement de la barriere :");
        scanf("%s", &coordonnee_barriere);
        printf("%s", coordonnee_barriere);
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
        printf(", %s", coordonnee_barriere);
    }
}