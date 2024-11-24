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
    int pion_chemin;
    //Y a-t-il une barriere derriere le pion a sauter
    int barriere_chemin;
    //S'il y a un pion et une barriere, choisir dans quel sens bifurquer
    int bifurquer;
    //recuperation de la variable nombrejoueur pour gerer la fin de la partie

    do {
        //initialisation des variables
        pion_chemin = 0;
        barriere_chemin = 0;
        errmouv = 0;

        printf("Saisissez une direction valide :\n1 gauche 2 droite 3 haut 4 bas\n");//affichage du menu dans la console
        scanf("%d", &mouvement);//recuperation du choix du joueur dans la variable mouvement
        //On cherche les coordonnes du pion en fonction du tour du joueur
        for (int i=0; i<TAILLEPLATEAUVERTICALE; i++) {
            for (int j=0; j<TAILLEPLATEAUHORIZONTALE; j++) {
                for (int t = 0; t < 4; t++) {
                    if (tourjoueur == t + 1) {//utilisation d'une variable t pour changer le caractere du joueur
                        if (plateau[i][j] == avatar[t]) {
                            //Conversions pour passer d'une case de caractere à une coordonnée du plateau(case jouable)
                            pion.ligne=i+1;
                            pion.colonne=(j-1)/3+'A';
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
                    printf("3 : Aller au dessus du pion\n4 : Aller en dessous du pion");//menu lors d'une bifurquation devant une barriere
                    scanf("%d", &bifurquer);// recuperation du choix du joueur
                } while (bifurquer != 3 && bifurquer != 4);//blindage pour recuperer une valeur valide
                barriere_chemin++;//on signale qu'il y a une barriere apres le saut d'un pion d'un joueur
            }
            pion_chemin++;//on signale qu'il y a pion sur le chemin emprunte par le joueur
        }
        //Si la case jouable a droite n'est pas un poin (donc est un pion)
        if (mouvement == 2 && plateau[pion.ligne - 1][(pion.colonne - 'A') * 3 + 1 + 6] != '.') {
            //Si la case non-jouable à droite du pion à sauter est une barriere
            if (plateau[pion.ligne-1][(pion.colonne-'A')*3+1+9]=='|') {
                //Demander où le joueur veut bifurquer
                do {
                    printf("3 : Aller au dessus du pion\n4 : Aller en dessous du pion");//menu lors d'une bifurquation devant une barriere
                    scanf("%d", &bifurquer);// recuperation du choix du joueur
                } while (bifurquer!=3&& bifurquer!=4);//blindage pour recuperer une valeur valide
                barriere_chemin++;//on signale qu'il y a une barriere apres le saut d'un pion d'un joueur
            }
            pion_chemin++;//on signale qu'il y a pion sur le chemin emprunte par le joueur
        }
        //Meme chose pour un mouvement haut
        if (mouvement==3 && plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1]!='.') {
            //Meme chose pour un mouvement haut
            if (plateau[pion.ligne-1-3][(pion.colonne-'A')*3+1]=='-') {
                //Bifurquer a droite ou a gauche
                do {
                    printf("1 : Aller  gauche du pion\n2 : Aller a droite du pion");//menu lors d'une bifurquation devant une barriere
                    scanf("%d", &bifurquer);// recuperation du choix du joueur
                } while (bifurquer != 1 && bifurquer != 2);//blindage pour recuperer une valeur valide
                barriere_chemin++;//on signale qu'il y a une barriere apres le saut d'un pion d'un joueur
            }
            pion_chemin++;//on signale qu'il y a pion sur le chemin emprunte par le joueur
        }
        //Meme chose pour un mouvement bas
        if (mouvement==4&&plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1]!='.') {
            if (plateau[pion.ligne-1+3][(pion.colonne-'A')*3+1]=='-') {
                do {
                    printf("1 : Aller  gauche du pion\n2 : Aller a droite du pion");//menu lors d'une bifurquation devant une barriere
                    scanf("%d", &bifurquer);// recuperation du choix du joueur
                } while (bifurquer != 1 && bifurquer != 2);//blindage pour recuperer une valeur valide
                barriere_chemin++;//on signale qu'il y a une barriere apres le saut d'un pion d'un joueur
            }
            pion_chemin++;//on signale qu'il y a pion sur le chemin emprunte par le joueur
        }

        //Sortie du plateau
        if (pion.colonne=='A' && mouvement==1 || pion.colonne=='Q' && mouvement==2 || pion.ligne==1 &&
            mouvement==3 || pion.ligne==17 && mouvement==4) {
            errmouv++;//creation d'une erreur
            }

        //Barrière qui bloque
        if (mouvement == 1 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1-3]=='|') {
            errmouv++;//creation d'une erreur
        }
        if (mouvement == 2 && plateau[pion.ligne-1][(pion.colonne-'A')*3+1+3]=='|') {
            errmouv++;//creation d'une erreur
        }
        if (mouvement == 3 && plateau[pion.ligne-1-1][(pion.colonne-'A')*3+1]=='-') {
            errmouv++;//creation d'une erreur
        }
        if (mouvement == 4 && plateau[pion.ligne-1+1][(pion.colonne-'A')*3+1]=='-') {
            errmouv++;//creation d'une erreur
        }
        //Blindage saisie et erreur de mouvement
    } while (mouvement<1 || mouvement>4 || errmouv>0);
    //Si la case est libre
    if (pion_chemin == 0) {
        //Gauche
        if (mouvement==1) {
            //Déplacement du pion de 6 caractères vers la gauche(->2 colonnes quelconques(->1 colonne jouable))
            plateau[pion.ligne-1][(pion.colonne-'A')*3+1-6]=avatar[tourjoueur-1];
            //Reformer la case de depart
            plateau[pion.ligne-1][(pion.colonne-'A')*3+1]='.';
        }
        //Droite
        if (mouvement == 2) {
            //Pareil a droite
            plateau[pion.ligne-1][(pion.colonne-'A')*3+1+6] = avatar[tourjoueur-1];
            plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
        }
        //Haut
        if (mouvement == 3) {
            //2 caractères au-dessus(->2 lignes quelconques(->1 ligne jouable))
            plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1] = avatar[tourjoueur-1];
            plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
        }
        //Pareil en bas
        if (mouvement == 4) {
            plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1] = avatar[tourjoueur-1];
            plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
        }
        //Si un pion est sur le chemin
    } else {
        //Si il n'y a pas de barriere apres ce pion
        if (barriere_chemin==0) {
            //Deplacement du joueur de 2 cases (gauche et droite->12 caracteres, haut et bas-> 4 caractères)
            if (mouvement==1) {
                plateau[pion.ligne-1][(pion.colonne-'A')*3+1-12] = avatar[tourjoueur-1];
                plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
            }
            if (mouvement == 2) {
                plateau[pion.ligne-1][(pion.colonne-'A')*3+1+12] = avatar[tourjoueur-1];
                plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
            }
            if (mouvement == 3) {
                plateau[pion.ligne-1-4][(pion.colonne-'A')*3+1] = avatar[tourjoueur-1];
                plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
            }
            if (mouvement == 4) {
                plateau[pion.ligne-1+4][(pion.colonne-'A')*3+1] = avatar[tourjoueur-1];
                plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
            }
            //S'il y a une barriere apres ce pion
        } else {
            //En fonction de la direction de la bifurcation, le pion est deplacé d'une ligne et d'une colonne
            if (mouvement == 1) {
                if (bifurquer == 3) {
                    plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1-6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
                if (bifurquer == 4) {
                    plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1-6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
            }
            if (mouvement == 2) {
                if (bifurquer == 3) {
                    plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1+6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
                if (bifurquer == 4) {
                    plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1+6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
            }
            if (mouvement == 3) {
                if (bifurquer == 1) {
                    plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1-6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
                if (bifurquer == 2) {
                    plateau[pion.ligne-1-2][(pion.colonne-'A')*3+1+6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
            }
            if (mouvement == 4) {
                if (bifurquer == 1) {
                    plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1-6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
                if (bifurquer == 2) {
                    plateau[pion.ligne-1+2][(pion.colonne-'A')*3+1+6] = avatar[tourjoueur-1];
                    plateau[pion.ligne-1][(pion.colonne-'A')*3+1] = '.';
                }
            }
        }
    }
}
