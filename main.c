#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"
#include "jeu.h"


int main(){
    int sizeX;
    int sizeY;
    int tileN, tileE, tileS, tileW, tileItem;
    connectToServer("172.105.76.204",1234, "diadji");

    char labyrintheName[100];
    waitForLabyrinth("TRAINING DONTMOVE timeout=1000 start=0", labyrintheName, &sizeX, &sizeY);
    
    int* lab = malloc(sizeof(int) * sizeX * sizeY * 5);
    getLabyrinth (lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
    printLabyrinth();

    t_joueur* joueur = malloc(sizeof(t_joueur));
    t_adversaire* adversaire = malloc(sizeof (t_adversaire));
    t_labyrinthe* labyrinthe = malloc(sizeof(t_labyrinthe));
    init_donnees(joueur, adversaire, labyrinthe, lab, sizeX, sizeY);
    t_tile* tab_tile = malloc(sizeof(t_tile));

    int* tab_deplacement = malloc(sizeof(int) * sizeX * sizeY);
    t_move* p_move = malloc(sizeof(t_move));
    t_move* p_move_adversaire = malloc(sizeof(t_move));


    do{
        coup_joue(joueur, tab_deplacement, sizeX, sizeY, tab_tile, p_move, lab);
        if (sendMove(p_move) == WINNING_MOVE){
            printf("vous avez gagné");
            break;
        }
        miseAJourDonnees(joueur, adversaire, labyrinthe, p_move, p_move_adversaire, lab);
        printLabyrinth();
        if (getMove(p_move_adversaire) == LOOSING_MOVE){
            printf("vous avez perdu");
            break;
        }
        miseAJourDonnees(joueur, adversaire, labyrinthe, p_move, p_move_adversaire, lab);
        printLabyrinth();
    }
    while (1);
    free(joueur);
    free(adversaire);
    free(labyrinthe);
    free(tab_tile);
    free(p_move);
    free(p_move_adversaire); 
    closeConnection(); 
}