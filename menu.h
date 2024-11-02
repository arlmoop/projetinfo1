//
// Created by aurel on 02/11/2024.
//

#ifndef MENU_H
#define MENU_H
#define TAILLEPLATEAU 9

int menudepart(char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[],
    char prenomjoueur4[], int *nombrejoueur);
void creationplateau(char plateau[TAILLEPLATEAU][TAILLEPLATEAU], int nombrejoueur);
void affichageplateau(char plateau[TAILLEPLATEAU][TAILLEPLATEAU], char prenomjoueur1[],
    char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur);


#endif //MENU_H
