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


void initTuile(t_tile tileOut, t_move* move){
    tileOut.tileN = move->tileN;
    tileOut.tileS = move->tileS;
    tileOut.tileE = move->tileE;
    tileOut.tileW = move->tileW;
}

void rotationTuile(t_tile tileOut, int save, int rotation){
    if (rotation == 0){
    }  
    else if (rotation == 1){
        save = tileOut.tileN;
        tileOut.tileN = tileOut. tileW;
        tileOut.tileW = tileOut.tileS;
        tileOut.tileS = tileOut.tileE;
        tileOut.tileE = save;
    }
    else if (rotation == 2){
        save = tileOut.tileN;
        tileOut.tileN = tileOut. tileS;
        tileOut.tileS = save;
        save = tileOut.tileE;
        tileOut.tileE = tileOut.tileW;
        tileOut.tileW = save;
    }
    else if (rotation == 3){
        save = tileOut.tileN;
        tileOut.tileN = tileOut. tileE;
        tileOut.tileE = tileOut.tileS;
        tileOut.tileS = tileOut.tileW;
        tileOut.tileW = save;
    }
}


void insertTuile(t_tile* tab_tile, t_tile tileOut, t_insertion insert, int number, int sizeX, int sizeY){
    if (insert == 0){
        for(int i = sizeX - 2; i >= 0; i --){
            tab_tile[i + number * sizeX].tileN = tab_tile[i + 1 + number * sizeX].tileN;
            tab_tile[i + number * sizeX].tileS = tab_tile[i + 1 + number * sizeX].tileS;
            tab_tile[i + number * sizeX].tileE = tab_tile[i + 1 + number * sizeX].tileE;
            tab_tile[i + number * sizeX].tileW = tab_tile[i + 1 + number * sizeX].tileW;
        }
        tab_tile[0 + number * sizeX].tileN = tileOut.tileN;
        tab_tile[0 + number * sizeX].tileS = tileOut.tileS;
        tab_tile[0 + number * sizeX].tileE = tileOut.tileE;
        tab_tile[0 + number * sizeX].tileW = tileOut.tileW;
    }

    if (insert == 1){
        for(int i = 1; i <= sizeX - 1; i ++){
            tab_tile[i + number * sizeX].tileN = tab_tile[i - 1 + number * sizeX].tileN;
            tab_tile[i + number * sizeX].tileS = tab_tile[i - 1 + number * sizeX].tileS;
            tab_tile[i + number * sizeX].tileE = tab_tile[i - 1 + number * sizeX].tileE;
            tab_tile[i + number * sizeX].tileW = tab_tile[i - 1 + number * sizeX].tileW;
        }
        tab_tile[sizeX - 1 + number * sizeX].tileN = tileOut.tileN;
        tab_tile[sizeX - 1 + number * sizeX].tileS = tileOut.tileS;
        tab_tile[sizeX - 1 + number * sizeX].tileE = tileOut.tileE;
        tab_tile[sizeX - 1 + number * sizeX].tileW = tileOut.tileW;
    }

    if (insert == 2){
        for(int j = sizeY - 2; j >= 0; j --){
            tab_tile[number + j * sizeX].tileN = tab_tile[number + (j + 1) * sizeX].tileN;
            tab_tile[number + j * sizeX].tileS = tab_tile[number + (j + 1) * sizeX].tileS;
            tab_tile[number + j * sizeX].tileE = tab_tile[number + (j + 1) * sizeX].tileE;
            tab_tile[number + j * sizeX].tileW = tab_tile[number + (j + 1) * sizeX].tileW;
        }
        tab_tile[number + 0 * sizeX].tileN = tileOut.tileN;
        tab_tile[number + 0 * sizeX].tileS = tileOut.tileS;
        tab_tile[number + 0 * sizeX].tileE = tileOut.tileE;
        tab_tile[number + 0 * sizeX].tileW = tileOut.tileW;
    }

    if (insert == 3){
        for(int j = 1; j <= sizeY - 1; j ++){
            tab_tile[number + j * sizeX].tileN = tab_tile[number + (j - 1) * sizeX].tileN;
            tab_tile[number + j * sizeX].tileS = tab_tile[number + (j - 1) * sizeX].tileS;
            tab_tile[number + j * sizeX].tileE = tab_tile[number + (j - 1) * sizeX].tileE;
            tab_tile[number + j * sizeX].tileW = tab_tile[number + (j - 1) * sizeX].tileW;
        }
        tab_tile[number + (sizeY - 1) * sizeX].tileN = tileOut.tileN;
        tab_tile[number + (sizeY - 1) * sizeX].tileS = tileOut.tileS;
        tab_tile[number + (sizeY - 1) * sizeX].tileE = tileOut.tileE;
        tab_tile[number + (sizeY - 1) * sizeX].tileW = tileOut.tileW;
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
                    else if (tab_tile[ligne * sizeX + colonne].tileS != 1 && tab_tile[(ligne + 1) * sizeX + colonne].tileN != 1){
                        if (ligne + 1 < sizeY && tab_deplacement[(ligne + 1) * sizeX + colonne] == r){
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



int coup_joue(t_joueur* joueur, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move, int* lab){
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

    int save = 0; 
    t_tile tileOut;
    t_insertion insert;	
    int number, rotation;
    for(number = 1; number < sizeY; number ++){
        if (number % 2 == 0){
        }
        else{
            for (rotation = 0; rotation <= 3; rotation ++){
                for (insert = 0; insert <= 1; insert ++){
                    init_tab_tuile(lab, tab_tile, sizeX, sizeY);
                    initTuile(tileOut, p_move);
                    rotationTuile(tileOut, save, rotation);
                    insertTuile(tab_tile, tileOut, insert, number, sizeX, sizeY);
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
    }

    for(number = 1; number < sizeX; number ++){
        if (number % 2 == 0){
        }
        else{
            for (rotation = 0; rotation <= 3; rotation ++){
                for (insert = 2; insert <= 3; insert ++){
                    init_tab_tuile(lab, tab_tile, sizeX, sizeY);
                    initTuile(tileOut, p_move);
                    rotationTuile(tileOut, save, rotation);
                    insertTuile(tab_tile, tileOut, insert, number, sizeX, sizeY);
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
    }
    

    init_tab_tuile(lab, tab_tile, sizeX, sizeY);
    if (tab_tile[joueur->x + sizeX * joueur->y].tileN != 1 && tab_tile[joueur->x + sizeX * (joueur->y - 1)].tileS != 1){
        if (joueur->y > 0){
            p_move->insert = 0;
            p_move->number = 5;
            p_move->rotation = 0;
            p_move->x = joueur->x;
            p_move->y = joueur->y - 1;
            return 0;
        }
    }


    if (tab_tile[joueur->x + sizeX * joueur->y].tileE != 1 && tab_tile[joueur->x + 1 + sizeX * joueur->y].tileW != 1){
        if (joueur->x < sizeX ){
            p_move->insert = 0;
            p_move->number = 5;
            p_move->rotation = 0;
            p_move->x = joueur->x + 1;
            p_move->y = joueur->y;
            return 0;
        }
    }


    if (tab_tile[joueur->x + sizeX * joueur->y].tileS != 1 && tab_tile[joueur->x + sizeX * (joueur->y + 1)].tileN != 1){
        if (joueur->y < sizeY){
            p_move->insert = 0;
            p_move->number = 5;
            p_move->rotation = 0;
            p_move->x = joueur->x;  
            p_move->y = joueur->y + 1;
            return 0;
        }
    }

    if (tab_tile[joueur->x + sizeX * joueur->y].tileW != 1 && tab_tile[joueur->x - 1 + sizeX * joueur->y].tileE != 1){
        if (joueur->x > 0){
            p_move->insert = 0;
            p_move->number = 5;
            p_move->rotation = 0;
            p_move->x = joueur->x - 1;
            p_move->y = joueur->y;
            return 0;
        }
    }

    p_move->insert = 0;
    p_move->number = 1;
    p_move->rotation = 0;
    p_move->x = joueur->x;
    p_move->y = joueur->y;
    return 0;    
}


