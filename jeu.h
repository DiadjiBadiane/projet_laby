#include <stdio.h>
#include <stdlib.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"
#include "donnees.h"
 

typedef struct{
    int tileN;
    int tileE;
    int tileS;
    int tileW;
    int tileItem;
}t_tile;



void init_tab_tuile(int* lab, t_tile* tab_tile, int sizeX, int sizeY);
void initTuile(t_tile* tileOut, t_move* move);
void rotationTuile(t_tile* tileOut, int save, int rotation);
void insertTuile(t_tile* tab_tile, t_tile* tileOut, t_insertion insert, int number, int sizeX, int sizeY);
int deplacement(int x_depart, int y_depart, int x_arrivee, int y_arrivee, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile);
int coup_gagnant(t_joueur* joueur, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move, t_move* p_move_adversaire, int* lab, t_tile* tileOut;);
int coup_joue(t_joueur* joueur, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move, t_move* p_move_adversaire, int* lab, t_tile* tileOut, int* tab_deplacement);




