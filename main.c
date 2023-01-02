#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labyrinthAPI.h"
#include "clientAPI.h"

int main(){
    int sizeX;
    int sizeY;
    int tileN, tileE, tileS, tileW, tileItem;
    connectToServer("172.105.76.204",1234, "Diadji");
    
    char labyrintheName[100];
    waitForLabyrinth("TRAINING DONTMOVE timeout=1000 start=0", labyrintheName, &sizeX, &sizeY);
    
    int* lab = malloc(sizeof(int) * sizeX * sizeY * 5);
    getLabyrinth (lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
    
    printLabyrinth();
    t_move* p_move = malloc(sizeof(t_move));
    t_move* p_move_adversaire = malloc(sizeof(t_move));
    int inserer;
    t_insertion insert;	
    insert = (t_insertion)inserer;
	int number;				
	int rotation;
    int x, y;				
    do{
        printf("choississez un coup\n\n");
        printf("où inserer\n");
        printf("numero de ligne ou colonne\n");
        printf("rotation\n");
        printf("coordonnées de déplacement\n");

        scanf("%d %d %d %d %d",&inserer,&number,&rotation,&x,&y);
        p_move->insert = insert;
        p_move->number = number;
        p_move->rotation = rotation;
        p_move->x = x;
        p_move->y = y;
        
        
        sendMove(p_move);
        getMove(p_move_adversaire);
        printLabyrinth();
    }
    while (sendMove(p_move) == NORMAL_MOVE && getMove(p_move_adversaire) == NORMAL_MOVE);

    closeConnection(); 
}