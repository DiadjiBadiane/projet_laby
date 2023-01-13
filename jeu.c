#include <stdio.h>
#include <stdlib.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"
#include "donnees.h"
#include "jeu.h"


int init_tab_tuile(int* lab, t_tile* tab_tile, int sizeX, int sizeY){
    int k = 0
    for(int i = 0; i <= sizeX ;i++){
        for(int j = ; j <= sizeY; j++)
        tab_tile[i][j]->tileN = lab[5*k];
        tab_tile[i][j]->tileE = lab[5*k + 1];
        tab_tile[i][j]->tileS = lab[5*k + 2];
        tab_tile[i][j]->tileW = lab[5*k + 3];
        tab_tile[i][j]->tileItem = lab[5*k + 4];
        k++;
        }
    }


int deplacement(x_depart, y_depart, x_arrivee, y_arrivee, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile){
    for (int i = 0; i <= sizeX; i ++){
        for (int j = 0; j <= sizeY; j++){
            tab_deplacement[i][j] = 0;
        } 
    }
    int r = 1;
    tab_deplacement[x_depart][y_depart] = r;

    int a = 0;
    while (tab_deplacement[x_arrivee][y_arrivee] == 0){
        for(int ligne = 0; ligne <= sizeX; ligne ++){
            for(int colonne = 0; colonne <= sizeY; colonne ++){
                if (tab_deplacemtn[ligne][colonne] == 0){
                    if (tab_tile[ligne][colonne]->tileN != 1 && tab_tile[ligne + 1][colonne]->tileS != 1){
                        if (ligne + 1 < sizeX && tab_deplacement[ligne + 1][colonne] == r){
                           tab_tile[ligne][colonne] = r + 1; 
                           a ++;
                        }
                    }
                    else if (tab_tile[ligne][colonne]->tileS != 1 && tab_tile[ligne - 1][colonne]->tileN != 1){
                        if (ligne - 1 > 0 && tab_deplacement[ligne - 1][colonne] == r){
                            tab_deplacement[ligne][colonne] = r + 1;
                            a ++;
                        }
                    }
                    else if (tab_tile[ligne][colonne]->tileE != 1 && tab_tile[ligne][colonne + 1]->tileW != 1){ 
                        if (colonne + 1 < sizeX && tab_deplacement[ligne][colonne + 1] == r) {
                            tab_deplacement[ligne][colonne] = r + 1;
                            a ++;
                        }
                    }
                    else if (tab_tile[ligne][colonne]->tileW != 1 && tab_tile[ligne][colonne - 1]->tileE != 1){
                        if (colonne - 1 > 0 && tab_deplacement[ligne][colonne - 1] == r) {  
                            tab_deplacement[ligne][colonne] = r + 1;
                            a ++;
                        }
                    }
                }
            }
        }
        if (a == 0){
            return -1;
        }
        else{
            r++;
            a = 0;
        }
    }
    return 0;
}



int coup_joue(t_joueur joueur, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move){
    int x_arrivee, y_arrivee;
    for (int i = 0; i <= sizeX; i ++){
        for(int j = 0; j <= sizeY; j ++){
            if tab_tile[i][j]->4 == joueur->nexItem{
                x_arrivee = i;
                y_arrivee = j;
                break;
            }

        }
    }


    int inserer;
    t_insertion insert;	
    insert = (t_insertion)inserer;
    int number, rotation;
    for(number = 1; number <= sizeX){
        for (rotation = 0; rotation <= 3; rotation ++){
            for (insert = 0; insert <= 1; insert ++){
                if (deplacement(joueur->x, joueur->y, x_arrivee, y_arrivee, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile) == 0){
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    p_move->x = y_arrivee;
                    p_move->y = x_arrivee;
                    return 0;
                }  
            }
            for (insert = 2, insert <= 3; insert ++){
                if (deplacement(joueur->x, joueur->y, x_arrivee, y_arrivee, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile) == 0){
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    p_move->x = y_arrivee;
                    p_move->y = x_arrivee;
                    return 0;
                }
                else{
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    p_move->x = joueur->x;
                    p_move->y = joueur->y;
                }
            }
        }
    }
}


