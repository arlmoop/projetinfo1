//
// Created by aurel on 02/11/2024.
//

#ifndef HEADER_H
#define HEADER_H
#define TAILLEPLATEAU 9

int menudepart(char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur);
int creationplateau(char plateau[TAILLEPLATEAU][TAILLEPLATEAU], int nombrejoueur);
int affichageplateau(char plateau[TAILLEPLATEAU][TAILLEPLATEAU]);

#endif //HEADER_H