#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"
#include "donnees.h"
#include "jeu.h"


int main(){
    int sizeX;
    int sizeY;
    int tileN, tileE, tileS, tileW, tileItem;
    connectToServer("172.105.76.204",1234, "Diadji");
    
    char labyrintheName[100];
    waitForLabyrinth("TRAINING DONTMOVE timeout=1000 start=0 display=debug", labyrintheName, &sizeX, &sizeY);
    
    int* lab = malloc(sizeof(int) * sizeX * sizeY * 5);
    getLabyrinth (lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
     
    printLabyrinth();
    t_move* p_move = malloc(sizeof(t_move));
    t_move* p_move_adversaire = malloc(sizeof(t_move));
  	

    t_joueur* joueur = malloc(sizeof(t_joueur));
    t_adversaire* adversaire = malloc(sizeof (t_adversaire));
    t_labyrinthe* labyrinthe = malloc(sizeof(t_labyrinthe));
    init_donnees(joueur, adversaire, labyrinthe, sizeX, sizeY);
    int* tab_deplacement;
    t_tile* tab_tile;
    int x_depart, x_arrivee;

    do{
        int init_tab_tuile(lab, tab_tile, sizeX, sizeY);
        int deplacement(x_depart, y_depart, x_arrivee, y_arrivee, tab_deplacement, sizeX, sizeY, tab_tile);
        int coup_joue(joueur, tab_deplacement, sizeX, sizeY, tab_tile, p_move);
        if (sendMove(p_move) == WINNING_MOVE){
        printf("vous avez gagné");
        break;
        }
        miseAJourDonnees(joueur, adversaire, labyrinthe, p_move, p_move_adversaire);
        printLabyrinth();
        if (getMove(p_move_adversaire) == LOOSING_MOVE){
            printf("vous avez perdu");
            break;
        }
        miseAJourDonnees(joueur, adversaire, labyrinthe, p_move, p_move_adversaire);
        printLabyrinth();
    }
    while (1);

    closeConnection(); 
}