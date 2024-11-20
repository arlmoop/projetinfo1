//
// Created by aurel on 02/11/2024.
//

#ifndef MOUVEMENTBARRIERE_H
#define MOUVEMENTBARRIERE_H

typedef struct {
    int ligne;
    char colonne;
}coordonnees;
coordonnees pose_barriere (char tableau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coor_donnee);
void pose2(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coordonnees_b, coordonnees coordonnees_b1, coordonnees coordonnees_b2);
#endif //MOUVEMENTBARRIERE_H
