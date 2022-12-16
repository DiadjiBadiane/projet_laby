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

    int* lab;
    lab = malloc(sizeof(int) * sizeX * sizeY * 5);
    waitForLabyrinth("TRAINING DONTMOVE", "PARTIE", &sizeX, &sizeY);
  
    getLabyrinth (lab, &tileN, &tileE, &tileS, &tileW, &tileItem);
    printLabyrinth();
    closeConnection(); 
}