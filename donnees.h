#include <stdio.h>
#include <stdlib.h>
#include "clientAPI.h"
#include "labyrinthAPI.h"


typedef struct{
    int x;
    int y;
    int nextItem;
    t_move moveAdversaire;
}t_joueur;


typedef struct{
    int x;
    int y;
    int nextItem;
    t_move moveJoueur;
}t_adversaire;


typedef struct{
    int* copy_lab;
}t_labyrinthe;



void init_donnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, int* lab, int sizeX, int sizeY);
void miseAJourDonnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, t_move* p_move, t_move* p_move_adversaire, int* lab);
