//
// Created by aurel on 02/11/2024.
//

#ifndef MENU_H
#define MENU_H
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "mouvementbarriere.h"
#include "mouvementpoins.h"
#include "header.h"

void menudepart (char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur,
    char avatar[4]);

void creationplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int nombrejoueur, coordonnees *pion1, coordonnees *pion2,
    coordonnees *pion3, coordonnees *pion4, char avatar[4]);

void affichageplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], char prenomjoueur1[], char prenomjoueur2[],
    char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur, int tourjoueur, char avatar[4], int reste1, int reste2, int reste3, int reste4);

#endif //MENU_H
