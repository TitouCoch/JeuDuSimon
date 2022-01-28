/*
 Programme : Jeu du simmon
 But : jeux du simmon
 Date de dernière modification : 22 septembre 2021
 Auteur : T. Cocheril
 Remarques : Code conforme aux spécifications internes vues en TD2
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game-tools.h"
using namespace std;

int randomMinMax(int min, int max);

int main(void)
{
    //VARIABLEs
    char couleurJoueur;                            //Couleur du joueur
    char couleurSimon;                             //Couleur du Simon choisi aléatoirement avec nombreAleatoire
    unsigned short int couleurErreur = 0;          //Position de la couleur d'erreur du joueur
    unsigned short int scoreJoueur = 0;            // Score du joueur à la fin du jeux
    unsigned short int i = 0;                      //indice d'emplacement du tableau en partant du début
    unsigned short int nombreAleatoire;            //Nombre aléatoire choisi par la machine entre 1 et 5 non compris
    unsigned short int const NOMBRE_DE_CASES = 100;//Nombre de cases du tableau
    char listeSimon[NOMBRE_DE_CASES];              //Tableau des couleurs du Simon avec un nombre de case égale à NOMBRE_DE_CASES
    unsigned short int compteurListeSimon = 0;     //Compteur qui compte le nombre de couleur du Simon
    unsigned short int compteurListeJoueur = 0;    //Compteur qui compte le nombre de couleur du Joueur
    bool finPartie = false;                        //Booléen finPartie qui prend pour valeur de base faux

    //Début du jeux

    //Boucle correspondant aux manches du jeu
    while (finPartie != true)
    {
        //Affichage jeux version Simon
        cout << "**Jeu du Simon**" << endl;
        cout << "" << endl;
        cout << "Simon : ";

        nombreAleatoire = random(1, 5); //nombre aléatoirement choisi par la machine
        //Affectation d'un caractère dans couleur du Simon en fonction du nombre aléatoirement choisi précédement par la machine
        switch (nombreAleatoire)
        {
        case 1:
            couleurSimon = 'j';
            break;
        case 2:
            couleurSimon = 'r';
            break;
        case 3:
            couleurSimon = 'b';
            break;
        case 4:
            couleurSimon = 'v';
            break;
        }
        listeSimon[compteurListeSimon] = couleurSimon;  //Affectation de la couleur du Simon dans le tableau à une case précise
        //Boucle bornée allant de 0 à jusqu'aux nombres de couleurs dans le tableau du Simon
        for (int i = 0; i <= compteurListeSimon; i++)
        {
            //Affichage de la couleur du caractère en fonction de la position du tableau
            switch (listeSimon[i])
            {
            case 'j':
                afficherTexteEnCouleur("j ", jaune, false);
                break;
            case 'v':
                afficherTexteEnCouleur("v ", vert, false);
                break;
            case 'r':
                afficherTexteEnCouleur("r ", rouge, false);
                break;
            case 'b':
                afficherTexteEnCouleur("b ", bleu, false);
                break;
            }
        }

        cout << endl;
        //Affichage Timer
        pause(1);
        cout << "3...";
        pause(1);
        cout << "2...";
        pause(1);
        cout << "1...";
        pause(1);
        //Terminal effacer
        effacer();
        //Affichage jeux version Joueur
        cout << "**Jeu du Simon**" << endl;
        cout << "[v-->vert, b-->bleu, r-->rouge, j-->jaune]" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "Joueur : ";
        //Boucle bornée de saisi des couleurs du joueur et de différentes vérification
        for (i = 0; i <= scoreJoueur; i++)
        {
            //Boucle non bornée de saisie et vérification de la saisie
            while (true)
            {
                cin >> couleurJoueur; //saisi couleur du joueur au clavier
                //Condition qui vérifie si la couleur saisie par le joueur au clavier est bien comprise dans les caractères autorisés
                if ((couleurJoueur == 'v') || (couleurJoueur == 'b') || (couleurJoueur == 'r') || (couleurJoueur == 'j'))
                {
                    break;
                }
                else
                {
                    cout << "Mauvaise valeur, recommencer : "; //Message d'erreur en cas de mauvaise sasie
                }
            }
            //Condition qui vérifie si le caractère saisi par le joueur est différent du caractère inscrit dans le tableau du Simon à une case précise
            if (couleurJoueur != listeSimon[compteurListeJoueur])
            {
                scoreJoueur = scoreJoueur - 1;
                couleurErreur = i;
                finPartie = true; //Sortie de la  boucle de partie
                break;            //Sortie de la boucle de saisi des couleurs du joueur
            }
            else
            {

                effacer(); //Effacer le terminal
                //Affichage jeux version joueur
                cout << "**Jeu du Simon**" << endl;
                cout << "[v-->vert, b-->bleu, r-->rouge, j-->jaune]" << endl;
                cout << "" << endl;
                cout << "" << endl;
                cout << "Joueur : ";
                //Boucle bornée permettant l'affichage des couleurs du joueur
                for (int i = 0; i <= compteurListeJoueur; i++)
                {
                    //Affichage de la couleurs du caractère du joueur en fonction de la saisi
                    switch (listeSimon[i])
                    {
                    case 'j':
                        afficherTexteEnCouleur("j ", jaune, false);
                        break;
                    case 'v':
                        afficherTexteEnCouleur("v ", vert, false);
                        break;
                    case 'r':
                        afficherTexteEnCouleur("r ", rouge, false);
                        break;
                    case 'b':
                        afficherTexteEnCouleur("b ", bleu, false);
                        break;
                    }
                }

                compteurListeJoueur = compteurListeJoueur + 1; //Compteur du nombre de couleurr du joueur actualiser
                pause(1);                                      // timer de 1 seconde
            }
        }
        compteurListeJoueur = 0;                     //Initialisation du compteur du nombre de couleur du joueur
        scoreJoueur++;                               // score du joueur actualiser
        effacer();                                   //terminal effacé
        compteurListeSimon = compteurListeSimon + 1; //Mise à jour du nombre de couleur du Simon
    }

    //Fin du jeu
    effacer(); //terminal effacé
    //Affichage jeux version fin de la partie
    cout << "** Jeu du Simon **" << endl;
    cout << "" << endl;
    cout << "La couleur d erreur est a la position : " << couleurErreur + 1 << endl; //Affichage de la position d'erreur du joueur
    cout << endl;
    cout << "Simon :  ";
    //Boucle bornée allant de 0 à jusqu'aux nombres de couleurs dans le tableau du Simon
    for (int i = 0; i <= compteurListeSimon; i++)
    {
        //Affichage de la couleur du caractère en fonction de la position du tableau
        switch (listeSimon[i])
        {
        case 'j':
            afficherTexteEnCouleur("j ", jaune, false);
            break;
        case 'v':
            afficherTexteEnCouleur("v ", vert, false);
            break;
        case 'r':
            afficherTexteEnCouleur("r ", rouge, false);
            break;
        case 'b':
            afficherTexteEnCouleur("b ", bleu, false);
            break;
        }
    }
    cout << endl;
    cout << "Joueur : ";
    //Boucle bornée allant de 0 jusqu'à juste avant l'erreur du joueur
    for (int i = 0; i <= couleurErreur - 1; i++)
    {
        //Affichage de la couleur du caractère en fonction de la position du tableau
        switch (listeSimon[i])
        {
        case 'j':
            afficherTexteEnCouleur("j ", jaune, false);
            break;
        case 'v':
            afficherTexteEnCouleur("v ", vert, false);
            break;
        case 'r':
            afficherTexteEnCouleur("r ", rouge, false);
            break;
        case 'b':
            afficherTexteEnCouleur("b ", bleu, false);
            break;
        }
    }
    //Affichage de la couleur d'erreur du joueur
    switch (couleurJoueur)
    {
    case 'j':
        afficherTexteEnCouleur("j ", jaune, false);
        break;
    case 'v':
        afficherTexteEnCouleur("v ", vert, false);
        break;
    case 'r':
        afficherTexteEnCouleur("r ", rouge, false);
        break;
    case 'b':
        afficherTexteEnCouleur("b ", bleu, false);
        break;
    }
    cout << endl;
    cout << endl;
    cout << "Votre score est : " << scoreJoueur; //Affichage score du joueur

    pause(10); //Pause de 10 secondes
    effacer(); //Terminal effacé
    return 0;
}
