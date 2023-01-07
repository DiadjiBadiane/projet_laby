#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"


void init_donnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, int sizeX, int sizeY){
    joueur->x = 0;
    joueur->y = 0;
    joueur->nextItem = 1;

    adversaire->x = sizeX - 1;
    adversaire->y = sizeY - 1;
    adversaire->nextItem = 24;

    labyrinthe->joueur.x = joueur->x;
    labyrinthe->joueur.y = joueur->y;
    labyrinthe->joueur.nextItem = joueur->nextItem;
    labyrinthe->adversaire.x = adversaire->x;
    labyrinthe->adversaire.y = adversaire->y;
    labyrinthe->adversaire.nextItem = adversaire->nextItem;  
    labyrinthe->sizeX = sizeX;
    labyrinthe->sizeY = sizeY;
}

void miseAJourDonnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, t_move* p_move, t_move* p_move_adversaire){
    joueur->x = p_move->x;
    joueur->y = p_move->y;
    joueur->nextItem = p_move->nextItem;

    adversaire->x = p_move_adversaire->x;
    adversaire->y = p_move_adversaire->y;
    adversaire->nextItem = p_move_adversaire->nextItem;

    labyrinthe->joueur.x = joueur->x;
    labyrinthe->joueur.y = joueur->y;
    labyrinthe->joueur.nextItem = joueur->nextItem;
    labyrinthe->adversaire.x = adversaire->x;
    labyrinthe->adversaire.y = adversaire->y;
    labyrinthe->adversaire.nextItem = adversaire->nextItem;  
}

