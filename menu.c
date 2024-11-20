//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>
#define TAILLEPLATEAUHORIZONTALE 51
#define TAILLEPLATEAUVERTICALE 17
#define TAILLECASEMAX 4
//creation des variables contenant lenom des joueurs et le nombre de joueur dans la partie
void menudepart (char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur) {

        printf("BIENVENUE DANS LE JEU DU QUORIDOR\n\n"); //message de presentation
    do {
        //Demande a l'utilisateur de choisir le nombre de joueur
        printf("\nVoulez vous jouez avec deux ou quatres joueurs ? :");
        //recuperation du nombre de joueur dans la variable
        scanf("%d", nombrejoueur);

        if (*nombrejoueur!=2 && *nombrejoueur!=4) { //test pour un message d'erreur
            printf("\nERREUR : Vous devez choisir 2 ou 4 joueurs"); //message d'erreur
        }
    } while (*nombrejoueur!=2 && *nombrejoueur!=4); //blindage pour avoir un nombre de joueur possible

    if (*nombrejoueur >= 2) { // test pour demander au 2 joueurs leurs prenoms
        printf("Entrez le prenom du joueur 1 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur1);//recuperation du prenom du joueur dans le tableau
        printf("Entrez le prenom du joueur 2 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur2); //recuperation du prenom du joueur dans le tableau
    }
    if (*nombrejoueur >= 4) { // test pour savoir si il ya plus de deux joueurs
        printf("Entrez le prenom du joueur 3 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur3); //recuperation du prenom du joueur dans le tableau
        printf("Entrez le prenom du joueur 4 :\n"); //demandes a l'utilisateur de rentrer le prenom du joueur
        scanf("%s", prenomjoueur4); //recuperation du prenom du joueur dans le tableau
    }
}

//creation du sous programme creant le plateau
void creationplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], int nombrejoueur) {
    /*creation du plateau de 9x9*/

    int h;        //a=case_horizontale, k=case_verticale,
    for(int v=0; v<17; v++){
        h=0;
        for (int i=0; i<8 ;i++) {
            plateau[v][h]=' ';
            h++;
            plateau[v][h]='.';
            h++;
            plateau[v][h]=' ';
            h++;
            plateau[v][h]=' ';
            h++;
            plateau[v][h]=' ';
            h++;
            plateau[v][h]=' ';
            h++;
        }
        plateau[v][h]=' ';
        h++;
        plateau[v][h]='.';
        h++;
        plateau[v][h]=' ';
    }

    for(int v=1; v<16; v+=2) {
        h=0;
        for (int j=0; j<8 ;j++) {
            plateau[v][h]=' ';
            h++;
            plateau[v][h]=' ';
            h++;
            plateau[v][h]=' ';
            h++;
            plateau[v][h]=' ';
            h++;
            plateau[v][h]='+';
            h++;
            plateau[v][h]=' ';
            h++;
        }
        plateau[v][h]=' ';
        h++;
        plateau[v][h]=' ';
        h++;
        plateau[v][h]=' ';
    }
    if (nombrejoueur >= 2) {//test pour savoir le nombre de joueur dans la partie
        plateau[0][24]=' ';//placement du joueurs n°1
        plateau[0][25]='1';
        plateau[0][26]=' ';

        plateau[16][24]=' ';//placement du joueurs n°2
        plateau[16][25]='2';
        plateau[16][26]=' ';
    }
    if (nombrejoueur >= 4) {//test pour savoir le nombre de joueur dans la partie
        plateau[8][0]=' ';//placement du joueurs n°3
        plateau[8][1]='3';
        plateau[8][2]=' ';

        plateau[8][48]=' ';//placement du joueurs n°4
        plateau[8][49]='4';
        plateau[8][50]=' ';
    }
}

// sous programme affichant le tableau
void affichageplateau(char plateau[TAILLEPLATEAUVERTICALE][TAILLEPLATEAUHORIZONTALE], char prenomjoueur1[], char prenomjoueur2[],
    char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur) {
    if (*nombrejoueur == 2) {//test pour savoir si le nombre de joueur est bien deux
        printf("\n\n%s\n", prenomjoueur1);// affiche le prenom du joueur 1 en haut du plateau
    }

    printf ("     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n");//les coordonnées des cases du plateau
    printf("    ___________________________________________________\n");//les delimitations du plateau

    for (int e=0; e<17; e++) {
        if(e<9) {
            printf(" %d |", e+1);
        }
        else {
            printf("%d |", e+1);
        }
        for (int f=0; f<51; f++) {
            printf("%c", plateau[e][f]);
        }
        printf("| %d\n", e+1);
    }

    printf("   |___________________________________________________|\n");  // Délimitation du plateau
    printf("     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n");  // Coordonnées des cases du plateau
    if (*nombrejoueur == 2) {//test pour savoir si le nombre de joueur est bien deux
        printf("\nPrenom joueur 1 : %s\n", prenomjoueur1);// affiche le prenom du joueur 1 en haut du plateau
        printf("Prenom joueur 2 : %s\n", prenomjoueur2);
    }
    if (*nombrejoueur == 4) {
        printf("Prenom joueur 3 : %s\n", prenomjoueur3);
        printf("Prenom joueur 4 : %s\n", prenomjoueur4);
    }
}

