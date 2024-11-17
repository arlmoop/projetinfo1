#include <stdio.h>
#include <stdlib.h>
#define TAILLECASEMAX 4
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#include "menu.h"
#include "mouvementpoins.h"
#include "header.h"
#include "mouvementbarriere.h"

int main() {

    //creation des variables pour le prenom des joueurs
    char prenomjoueur1[20], prenomjoueur2[20], prenomjoueur3[20], prenomjoueur4[20];
    int nombrejoueur; //creation des variable contenant le nombre de joueur dans la partie
    int mouvement_barriere;
    //execution de la fonction qui affiche le menu
    menudepart(prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur);

    //initialisation du plateau de jeu
    char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE];
    //initialisation du plateau de jeu en fonction du nombre de joueur dans la partie
    char lignepairecolonnepaire[TAILLECASEMAX];
    char lignepairecolonneimpaire[TAILLECASEMAX];
    char ligneimpairecolonnepaire[TAILLECASEMAX];
    char ligneimpairecolonneimpaire[TAILLECASEMAX];
    creationplateau(plateau, nombrejoueur);
    //affiche le plateau de jeu en debut de partie et le nom des joueurs
    affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur,
    lignepairecolonnepaire, lignepairecolonneimpaire, ligneimpairecolonnepaire, ligneimpairecolonneimpaire);

    int joueurenmouvement =1; //variable comptant le joueur qui est en train de jouer

    while (1) { /*Boucle gérant le tour des joueurs (pour l'instant infine car pas de code pour
        la fin de la partie*/

        printf("\n1. Deplacer le pion\n2. Poser une barriere\nChoisissez une valeur valide :");
        scanf("%d", &mouvement_barriere);
        if (mouvement_barriere==1) {
            deplacementpion(plateau, joueurenmouvement); //deplacement du joueur en train de jouer
            //affichage du plateau apres chaque tour de joueur
            affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur,
        lignepairecolonnepaire, lignepairecolonneimpaire, ligneimpairecolonnepaire, ligneimpairecolonneimpaire);
        }
        if (mouvement_barriere==2) {
            pose_barriere(plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], mouvement_barriere);
            affichageplateau(plateau, prenomjoueur1, prenomjoueur2, prenomjoueur3, prenomjoueur4, &nombrejoueur,
        lignepairecolonnepaire, lignepairecolonneimpaire, ligneimpairecolonnepaire, ligneimpairecolonneimpaire);
        }


        joueurenmouvement=joueurenmouvement+1; //passage au joueur suivant
        if (joueurenmouvement>nombrejoueur) {
            joueurenmouvement=1; //si la variable depasse le nombre de joueur alors on recommence un tourd
        }
        system("pause");
    }

}
