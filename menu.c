//
// Created by aurel on 02/11/2024.
//
#include <stdio.h>
#define TAILLEPLATEAU 51
#define TAILLECASEMAX 4
//creation des variables contenant lenom des joueurs et le nombre de joueur dans la partie
int menudepart (char prenomjoueur1[], char prenomjoueur2[], char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur) {

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

    return 0;
}

//creation du sous programme creant le plateau
void creationplateau(char plateau[17][TAILLEPLATEAU], int nombrejoueur) {
    /*creation du plateau
de 9x9*/
    /*char lignepairecolonnepaire[TAILLECASEMAX]=" . ";
    char lignepairecolonneimpaire[TAILLECASEMAX]="   ";
    char ligneimpairecolonnepaire[TAILLECASEMAX]="   ";
    char ligneimpairecolonneimpaire[TAILLECASEMAX]=" + ";
    printf("%s", lignepairecolonnepaire);
    if (nombrejoueur >= 2) {//test pour savoir le nombre de joueur dans la partie
        plateau[0][4] = '1';//placement du joueurs n°1
        plateau[8][4] = '2';//placement du joueurs n°2
    }
    if (nombrejoueur >= 4) {//test pour savoir le nombre de joueur dans la partie
        plateau[4][0] = '3';//placement du joueurs n°3
        plateau[4][8] = '4';//placement du joueurs n°4
    }*/
    int a;
    for(int k=0; k<17; k++){
        a=0;
        for (int i=0; i<8 ;i++) {
            plateau[k][a]=' ';
            a++;
            plateau[k][a]='.';
            a++;
            plateau[k][a]=' ';
            a++;
            plateau[k][a]=' ';
            a++;
            plateau[k][a]=' ';
            a++;
            plateau[k][a]=' ';
            a++;
        }
        plateau[k][a]=' ';
        a++;
        plateau[k][a]='.';
        a++;
        plateau[k][a]=' ';
    }

    int b;
    for(int l=1; l<16; l+=2) {
        b=0;
        for (int j=0; j<8 ;j++) {
            plateau[l][b]=' ';
            b++;
            plateau[l][b]=' ';
            b++;
            plateau[l][b]=' ';
            b++;
            plateau[l][b]=' ';
            b++;
            plateau[l][b]='+';
            b++;
            plateau[l][b]=' ';
            b++;
        }
        plateau[l][b]=' ';
        b++;
        plateau[l][b]=' ';
        b++;
        plateau[l][b]=' ';
    }
}

// sous programme affichant le tableau
void affichageplateau(char plateau[TAILLEPLATEAU][TAILLEPLATEAU], char prenomjoueur1[], char prenomjoueur2[],
    char prenomjoueur3[], char prenomjoueur4[], int *nombrejoueur, char lignepairecolonnepaire[TAILLECASEMAX],
    char lignepairecolonneimpaire[TAILLECASEMAX], char ligneimpairecolonnepaire[TAILLECASEMAX],
    char ligneimpairecolonneimpaire[TAILLECASEMAX]) {
    if (*nombrejoueur == 2) {//test pour savoir si le nombre de joueur est bien deux
        printf("\n\n%s\n", prenomjoueur1);// affiche le prenom du joueur 1 en haut du plateau
    }
    printf (" A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n");//les coordonnées des cases du plateau
    printf("____________________________________________________\n");//les delimitations du plateau

    for (int e=0; e<17; e++) {
        for (int f=0; f<51; f++) {
            printf("%c", plateau[e][f]);
        }
        printf("\n");
    }



    printf("____________________________________________________\n");  // Délimitation du plateau
    printf(" A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q\n");  // Coordonnées des cases du plateau
    if (*nombrejoueur == 2) {
        printf("%s\n\n", prenomjoueur2);  // Affiche le prénom du joueur 2
    }
}

