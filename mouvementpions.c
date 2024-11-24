#include <stdio.h>
#include <stdlib.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "header.h"
#include "mouvementbarriere.h"
#include "mouvementpoins.h"
#include "menu.h"
//Mouvement du pion
void deplacementpion(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], coordonnees pion, char avatar[4], int tourjoueur, int *nombrejoueur, int victoire) {
    //Compte les erreurs
    int errmouv;
    //Stocke la direction du mouvement
    int mouvement;
    //Y a-t-il un pion sur la trajectoire du joueur
    int pionchemin;
    //Y a-t-il une barriere derriere le pion a sauter
    int barchemin;
    //S'il y a un pion et une barriere, choisir dans quel sens bifurquer
    int bifurquer;
    //recuperation de la variable nombrejoueur pour gerer la fin de la partie

    do {
        pionchemin = 0;
        barchemin = 0;
        errmouv = 0;

        printf("Saisissez une direction valide :\n1 gauche 2 droite 3 haut 4 bas\n");
        scanf("%d", &mouvement);
        //On cherche les coordonnes du pion en fonction du tour du joueur
        for (int i = 0; i < TAILLEPLATEAUVERTICALE; i++) {
            for (int j = 0; j < TAILLEPLATEAUHORIZONTALE; j++) {
                for (int t = 0; t < 4; t++) {
                    if (tourjoueur == t + 1) {
                        if (plateau[i][j] == avatar[t]) {
                            //Conversions pour passer d'une case de caractere à une coordonnée du plateau(case jouable)
                            pion.ligne = i + 1;
                            pion.colonne = (j - 1) / 3 + 'A';
                        }
                    }
                }
            }
        }

        //Blindage pion sur le chemin
        //Si la case jouable a gauche n'est pas un poin (donc est un pion)
        if (mouvement == 1 && plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 - 6] != '.') {
            //Si la case non-jouable à droite du pion à sauter est une barriere
            if (plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 - 9] == '|') {
                //Demander où le joueur veut bifurquer
                do {
                    printf("3 : Aller au dessus du pion\n4 : Aller en dessous du pion");
                    scanf("%d", &bifurquer);
                } while (bifurquer != 3 && bifurquer != 4);
                barchemin++;
            }
            pionchemin++;
        }
        //Si la case jouable a droite n'est pas un poin (donc est un pion)
        if (mouvement == 2 && plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 + 6] != '.') {
            //Si la case non-jouable à droite du pion à sauter est une barriere
            if (plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 + 9] == '|') {
                //Demander où le joueur veut bifurquer
                do {
                    printf("3 : Aller au dessus du pion\n4 : Aller en dessous du pion");
                    scanf("%d", &bifurquer);
                } while (bifurquer != 3 && bifurquer != 4);
                barchemin++;
            }
            pionchemin++;
        }
        //Meme chose pour un mouvement haut
        if (mouvement == 3 && plateau[pion.ligne - 1 - 2][(pion.colonne - 'A') * 3 + 1] != '.') {
            //Meme chose pour un mouvement haut
            if (plateau[pion.ligne - 1 - 3][(pion.colonne - 'A') * 3 + 1] == '-') {
                //Bifurquer a droite ou a gauche
                do {
                    printf("1 : Aller  gauche du pion\n2 : Aller a droite du pion");
                    scanf("%d", &bifurquer);
                } while (bifurquer != 1 && bifurquer != 2);
                barchemin++;
            }
            pionchemin++;
        }
        //Meme chose pour un mouvement bas
        if (mouvement == 4 && plateau[pion.ligne - 1 + 2][(pion.colonne - 'A') * 3 + 1] != '.') {
            if (plateau[pion.ligne - 1 + 3][(pion.colonne - 'A') * 3 + 1] == '-') {
                do {
                    printf("1 : Aller  gauche du pion\n2 : Aller a droite du pion");
                    scanf("%d", &bifurquer);
                } while (bifurquer != 1 && bifurquer != 2);
                barchemin++;
            }
            pionchemin++;
        }

        //Sortie du plateau
        if (pion.colonne == 'A' && mouvement == 1 || pion.colonne == 'Q' && mouvement == 2 || pion.ligne == 1 &&
            mouvement == 3 || pion.ligne == 17 && mouvement == 4) {
            errmouv++;
            }

        //Barrière qui bloque
        if (mouvement == 1 && plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 - 3] == '|') {
            errmouv++;
        }
        if (mouvement == 2 && plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 + 3] == '|') {
            errmouv++;
        }
        if (mouvement == 3 && plateau[pion.ligne - 1 - 1][(pion.colonne - 'A') * 3 + 1] == '-') {
            errmouv++;
        }
        if (mouvement == 4 && plateau[pion.ligne - 1 + 1][(pion.colonne - 'A') * 3 + 1] == '-') {
            errmouv++;
        }
        //Blindage saisie et erreur de mouvement
    } while (mouvement < 1 || mouvement > 4 || errmouv > 0);
    //Si la case est libre
    if (pionchemin == 0) {
        //Gauche
        if (mouvement == 1) {
            //Déplacement du pion de 6 caractères vers la gauche(->2 colonnes quelconques(->1 colonne jouable))
            plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 - 6] = avatar[tourjoueur - 1];
            //Reformer la case de depart
            plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
        }
        //Droite
        if (mouvement == 2) {
            //Pareil a droite
            plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 + 6] = avatar[tourjoueur - 1];
            plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
        }
        //Haut
        if (mouvement == 3) {
            //2 caractères au-dessus(->2 lignes quelconques(->1 ligne jouable))
            plateau[pion.ligne - 1 - 2][(pion.colonne - 'A') * 3 + 1] = avatar[tourjoueur - 1];
            plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
        }
        //Pareil en bas
        if (mouvement == 4) {
            plateau[pion.ligne - 1 + 2][(pion.colonne - 'A') * 3 + 1] = avatar[tourjoueur - 1];
            plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
        }
        //Si un pion est sur le chemin
    } else {
        //Si il n'y a pas de barriere apres ce pion
        if (barchemin == 0) {
            //Deplacement du joueur de 2 cases (gauche et droite->12 caracteres, haut et bas-> 4 caractères)
            if (mouvement == 1) {
                plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 - 12] = avatar[tourjoueur - 1];
                plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
            }
            if (mouvement == 2) {
                plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 + 12] = avatar[tourjoueur - 1];
                plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
            }
            if (mouvement == 3) {
                plateau[pion.ligne - 1 - 4][(pion.colonne - 'A') * 3 + 1] = avatar[tourjoueur - 1];
                plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
            }
            if (mouvement == 4) {
                plateau[pion.ligne - 1 + 4][(pion.colonne - 'A') * 3 + 1] = avatar[tourjoueur - 1];
                plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
            }
            //S'il y a une barriere apres ce pion
        } else {
            //En fonction de la direction de la bifurcation, le pion est deplacé d'une ligne et d'une colonne
            if (mouvement == 1) {
                if (bifurquer == 3) {
                    plateau[pion.ligne - 1 - 2][(pion.colonne - 'A') * 3 + 1 - 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
                if (bifurquer == 4) {
                    plateau[pion.ligne - 1 + 2][(pion.colonne - 'A') * 3 + 1 - 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
            }
            if (mouvement == 2) {
                if (bifurquer == 3) {
                    plateau[pion.ligne - 1 - 2][(pion.colonne - 'A') * 3 + 1 + 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
                if (bifurquer == 4) {
                    plateau[pion.ligne - 1 + 2][(pion.colonne - 'A') * 3 + 1 + 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
            }
            if (mouvement == 3) {
                if (bifurquer == 1) {
                    plateau[pion.ligne - 1 - 2][(pion.colonne - 'A') * 3 + 1 - 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
                if (bifurquer == 2) {
                    plateau[pion.ligne - 1 - 2][(pion.colonne - 'A') * 3 + 1 + 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
            }
            if (mouvement == 4) {
                if (bifurquer == 1) {
                    plateau[pion.ligne - 1 + 2][(pion.colonne - 'A') * 3 + 1 - 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
                if (bifurquer == 2) {
                    plateau[pion.ligne - 1 + 2][(pion.colonne - 'A') * 3 + 1 + 6] = avatar[tourjoueur - 1];
                    plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1] = '.';
                }
            }
        }
    }

    /*for (int i=0; i<TAILLEPLATEAUVERTICALE; i++) {
        if (plateau[16][pion.colonne+i]==avatar[0]) {
            victoire++;
        }
        if (plateau[0][pion.colonne+i]==avatar[1]) {
            victoire++;
        }
    }
    for(int i=0; i<TAILLEPLATEAUHORIZONTALE; i++) {
        if ( plateau[pion.ligne+i][1]==avatar[2]) {
            victoire++;
        }
        if ( plateau[pion.ligne+i][50]==avatar[3]) {
            victoire++;
        }
    }*/

}
