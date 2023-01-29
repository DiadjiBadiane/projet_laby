#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"





void init_tab_tuile(int* lab, t_tile* tab_tile, int sizeX, int sizeY){
    int k = 0;
    for(int i = 0; i < sizeX ;i++){
        for(int j = 0; j < sizeY; j++){
            tab_tile[k].tileN = lab[5*k];
            tab_tile[k].tileE = lab[5*k + 1];
            tab_tile[k].tileS = lab[5*k + 2];
            tab_tile[k].tileW = lab[5*k + 3];
            tab_tile[k].tileItem = lab[5*k + 4];
            k++;
        }
    }
}


int deplacement(int x_depart, int y_depart, int x_arrivee, int y_arrivee, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile){
    int k = 0;
    for (int j = 0; j < sizeY; j ++){
        for (int i = 0; i < sizeX; i++){
            tab_deplacement[k] = 0;
            k++;
        } 
    }
    int r = 1;
    tab_deplacement[x_depart + sizeX * y_depart] = r;

    int a = 0;
    while (tab_deplacement[x_arrivee + y_arrivee * sizeX] == 0){
        for(int ligne = 0; ligne < sizeY; ligne ++){
            for(int colonne = 0; colonne < sizeX; colonne ++){
                if (tab_deplacement[ligne * sizeX + colonne] == 0){
                    if (tab_tile[ligne * sizeX + colonne].tileN != 1 && tab_tile[(ligne - 1)* sizeX + colonne].tileS != 1){
                        if (ligne - 1 > 0 && tab_deplacement[(ligne - 1) * sizeX + colonne] == r){
                           tab_deplacement[ligne * sizeX + colonne] = r + 1; 
                           a ++;
                        }
                    }
                    else if (tab_tile[ligne * sizeY + colonne].tileS != 1 && tab_tile[(ligne + 1) * sizeX + colonne].tileN != 1){
                        if (ligne - 1 < sizeX && tab_deplacement[(ligne + 1) * sizeX + colonne] == r){
                            tab_deplacement[ligne * sizeX + colonne] = r + 1;
                            a ++;
                        }
                    }
                    else if (tab_tile[ligne * sizeX + colonne].tileE != 1 && tab_tile[ligne * sizeX + colonne + 1].tileW != 1){ 
                        if (colonne + 1 < sizeX && tab_deplacement[ligne * sizeX + colonne + 1] == r) {
                            tab_deplacement[ligne * sizeX + colonne] = r + 1;
                            a ++;
                        }
                    }
                    else if (tab_tile[ligne * sizeX + colonne].tileW != 1 && tab_tile[ligne * sizeX + colonne - 1].tileE != 1){
                        if (colonne - 1 > 0 && tab_deplacement[ligne * sizeX + colonne - 1] == r) {  
                            tab_deplacement[ligne * sizeX + colonne] = r + 1;
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



int coup_joue(t_joueur* joueur, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move){
    int k = 0;
    int x_arrivee, y_arrivee; 
    for (int j = 0; j < sizeY; j ++){
        for(int i = 0; i < sizeX; i ++){
            if (tab_tile[k].tileItem == joueur->nextItem){
                x_arrivee = i;
                y_arrivee = j;
            }
            k ++;
        }
    }

    t_insertion insert;	
    int number, rotation;
    for(number = 1; number < sizeY; number ++){
        for (rotation = 0; rotation <= 3; rotation ++){
            for (insert = 0; insert <= 1; insert ++){
                }
                if (deplacement(joueur->x, joueur->y, x_arrivee, y_arrivee, tab_deplacement, sizeX, sizeY, tab_tile) == 0){
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    p_move->x = x_arrivee;
                    p_move->y = y_arrivee;
                    return 0;
                }  
            }
            for (insert = 2; insert <= 3; insert ++){
                if (deplacement(joueur->x, joueur->y, x_arrivee, y_arrivee, tab_deplacement, sizeX, sizeY, tab_tile) == 0){
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    p_move->x = x_arrivee;
                    p_move->y = y_arrivee;
                    return 0;
                }
            }
        }
    }
    p_move->insert = insert;
    p_move->number = number;
    p_move->rotation = rotation;
    p_move->x = joueur->x;
    p_move->y = joueur->y;
    return 0;
}

