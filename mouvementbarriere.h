
//
// Created by aurel on 02/11/2024.
//

#ifndef MOUVEMENTPOINS_H
#define MOUVEMENTPOINS_H

#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
void deplacementpion(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], coordonnees pion);
void pose2(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int mouvement_barriere, coordonnees coordonnees_b);

#endif //MOUVEMENTPOINS_H
