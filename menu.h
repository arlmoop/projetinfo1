//
// Created by aurel on 02/11/2024.
//

#ifndef MENU_H
#define MENU_H
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17

int menudepart(char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[],
    char prenomjoueur4[], int *nombrejoueur);
void creationplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int nombrejoueur);
void affichageplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], char prenomjoueur1[], char prenomjoueur2[],
    char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur);

#endif //MENU_H
