#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"


/*fonction init_tab_tuile: cree un tableau de tuile correspndant à celui du labyrinthe
*paramètres:
*le lebrinthe (lab)
*un tableau de type t_tuile (voire structure dans jeu.h)
*dimensions du tableau(sizeX, sizeY)*/

void init_tab_tuile(int* lab, t_tile* tab_tile, int sizeX, int sizeY){
    int k = 0;
    for(int i = 0; i < sizeX ;i++){
        for(int j = 0; j < sizeY; j++){
            /*4 * k premières cases de lab = cotés de la tuile k (nord-est-sud-ouest)
            *dernière case = numero du tresor de la tuile*/
            tab_tile[k].tileN = lab[5*k];
            tab_tile[k].tileE = lab[5*k + 1];
            tab_tile[k].tileS = lab[5*k + 2];
            tab_tile[k].tileW = lab[5*k + 3];
            tab_tile[k].tileItem = lab[5*k + 4];
            k++;
        }
    }
}



/*fonction initTuile: recupère la tuile en dehors du labyrinthe
*paramètres:
*une tuile 
*t_move correspondant à mon coup (contenant la tuile sortie lors du coup)*/

void initTuile(t_tile* tileOut, t_move* move){
    tileOut->tileN = move->tileN;
    tileOut->tileS = move->tileS;
    tileOut->tileE = move->tileE;
    tileOut->tileW = move->tileW;
    tileOut->tileItem = move->tileItem;
}



/*fonction rotation tuile: permet de définir la rotation de la tuile en dehors
*paramètres:
*tuile en dehors tileOut
*un entier "save" permettant de garder un coté de la tuile(lors de la rotation)
*un entier correspondant à la rotation(0, 1, 2 ou 3) */

void rotationTuile(t_tile* tileOut, int save, int rotation){
    //pas de rotation//
    if (rotation == 0){
    }  

    //rotation de 90°//
    else if (rotation == 1){
        save = tileOut->tileN;
        tileOut->tileN = tileOut->tileW;
        tileOut->tileW = tileOut->tileS;
        tileOut->tileS = tileOut->tileE;
        tileOut->tileE = save;
    }

    //rotation de 180°//
    else if (rotation == 2){
        save = tileOut->tileN;
        tileOut->tileN = tileOut->tileS;
        tileOut->tileS = save;
        save = tileOut->tileE;
        tileOut->tileE = tileOut->tileW;
        tileOut->tileW = save;
    }

    //rotation de 270°//
    else if (rotation == 3){
        save = tileOut->tileN;
        tileOut->tileN = tileOut->tileE;
        tileOut->tileE = tileOut->tileS;
        tileOut->tileS = tileOut->tileW;
        tileOut->tileW = save;
    }
}




/*fonction insertTuille: permet d' inserer une tuile dans le labyrinthe tile_tab(pour tester les modifications du labyrinthe)
*paramètres:
*tableau de tuile tab_tile
*tile en dehors du labyrinthe tileOut
*type d'insertion(gauche-droite-haut-bas)
*numero de la ligne ou colonne où l' on insère la tuile
*dimensions du labyrinthe (sizeX-sizeY)*/

void insertTuile(t_tile* tab_tile, t_tile* tileOut, t_insertion insert, int number, int sizeX, int sizeY){
    //insertion à gauche//
    if (insert == 0){
        //decalage de la ligne "number" vers la droite//
        for(int i = sizeX - 2; i >= 0; i --){
            tab_tile[i + number * sizeX].tileN = tab_tile[i + 1 + number * sizeX].tileN;
            tab_tile[i + number * sizeX].tileS = tab_tile[i + 1 + number * sizeX].tileS;
            tab_tile[i + number * sizeX].tileE = tab_tile[i + 1 + number * sizeX].tileE;
            tab_tile[i + number * sizeX].tileW = tab_tile[i + 1 + number * sizeX].tileW;
        }
        //ajout de la tuile en dehors à gauche de la ligne// 
        tab_tile[0 + number * sizeX].tileN = tileOut->tileN;
        tab_tile[0 + number * sizeX].tileS = tileOut->tileS;
        tab_tile[0 + number * sizeX].tileE = tileOut->tileE;
        tab_tile[0 + number * sizeX].tileW = tileOut->tileW;
    }

    //insertion à droite//
    if (insert == 1){
        //decalage de la ligne "number vers la droite"
        for(int i = 1; i <= sizeX - 1; i ++){
            tab_tile[i + number * sizeX].tileN = tab_tile[i - 1 + number * sizeX].tileN;
            tab_tile[i + number * sizeX].tileS = tab_tile[i - 1 + number * sizeX].tileS;
            tab_tile[i + number * sizeX].tileE = tab_tile[i - 1 + number * sizeX].tileE;
            tab_tile[i + number * sizeX].tileW = tab_tile[i - 1 + number * sizeX].tileW;
        }
        //ajout de la tuile en dehors à droite de la ligne//
        tab_tile[sizeX - 1 + number * sizeX].tileN = tileOut->tileN;
        tab_tile[sizeX - 1 + number * sizeX].tileS = tileOut->tileS;
        tab_tile[sizeX - 1 + number * sizeX].tileE = tileOut->tileE;
        tab_tile[sizeX - 1 + number * sizeX].tileW = tileOut->tileW;
    }

    //insertion par le dessus//
    if (insert == 2){
        //decalage de la colonne "number" vers le bas//
        for(int j = sizeY - 2; j >= 0; j --){
            tab_tile[number + j * sizeX].tileN = tab_tile[number + (j + 1) * sizeX].tileN;
            tab_tile[number + j * sizeX].tileS = tab_tile[number + (j + 1) * sizeX].tileS;
            tab_tile[number + j * sizeX].tileE = tab_tile[number + (j + 1) * sizeX].tileE;
            tab_tile[number + j * sizeX].tileW = tab_tile[number + (j + 1) * sizeX].tileW;
        }
        //ajout de la tuile en dehors à la première case de la colonne//
        tab_tile[number + 0 * sizeX].tileN = tileOut->tileN;
        tab_tile[number + 0 * sizeX].tileS = tileOut->tileS;
        tab_tile[number + 0 * sizeX].tileE = tileOut->tileE;
        tab_tile[number + 0 * sizeX].tileW = tileOut->tileW;
    }

    //insertion par le dessous//
    if (insert == 3){
        //decalage de la colonne "number" vers le haut//
        for(int j = 1; j <= sizeY - 1; j ++){
            tab_tile[number + j * sizeX].tileN = tab_tile[number + (j - 1) * sizeX].tileN;
            tab_tile[number + j * sizeX].tileS = tab_tile[number + (j - 1) * sizeX].tileS;
            tab_tile[number + j * sizeX].tileE = tab_tile[number + (j - 1) * sizeX].tileE;
            tab_tile[number + j * sizeX].tileW = tab_tile[number + (j - 1) * sizeX].tileW;
        }
        //ajout de la tuile en dehors à la dernière case de la colonne//
        tab_tile[number + (sizeY - 1) * sizeX].tileN = tileOut->tileN;
        tab_tile[number + (sizeY - 1) * sizeX].tileS = tileOut->tileS;
        tab_tile[number + (sizeY - 1) * sizeX].tileE = tileOut->tileE;
        tab_tile[number + (sizeY - 1) * sizeX].tileW = tileOut->tileW;
    }
}




/*fonction déplacement: recherche des chemins allan d' une case d' une départ à une case d' arrivée (phase d' expansion)
*paramètres:
*position de départ(x_depart et y_depart)
*position d' arrivée(x_arrivée et y_arrivée)
*tableau de int tab_deplacement(représentation du labyrinthe de tuile par un tableau)
*tableau de tuile tile_tab
*dimensions d' arrivée(sizeX-sizeY) */

int deplacement(int x_depart, int y_depart, int x_arrivee, int y_arrivee, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile){
    //initialise les valeurs de tab_deplacement à 0//
    int k = 0;
    for (int j = 0; j < sizeY; j ++){
        for (int i = 0; i < sizeX; i++){
            tab_deplacement[k] = 0;
            k++;
        } 
    }

    //case de départ marquée 1//
    int r = 1;
    tab_deplacement[x_depart + sizeX * y_depart] = r;


    /*tant que la case d' arrivée n' est pas marquée on parcours le tableau et on marque par r + 1 les cases:
    *non déjà traversées
    *libre d' obstacle (pas de mur sur la tuile et sur la tuule voisine)
    *qui ne sont pas en dehors du tableau et voisine du case marquée r
    *On incrémente ensuite r (à chaque tour de la boucle while)
    *Si l' arrivée n'est pas atteignable, fin de la fonction*/ 
    int a = 0;
    while (tab_deplacement[x_arrivee + y_arrivee * sizeX] == 0){
        for(int ligne = 0; ligne < sizeY; ligne ++){
            for(int colonne = 0; colonne < sizeX; colonne ++){
                if (tab_deplacement[ligne * sizeX + colonne] == 0){
                    if (tab_tile[ligne * sizeX + colonne].tileN != 1 && tab_tile[(ligne - 1)* sizeX + colonne].tileS != 1){ //pas d'obstacle//
                        if (ligne - 1 > 0 && tab_deplacement[(ligne - 1) * sizeX + colonne] == r){//voisine du case marquée et dans le tableau//
                           tab_deplacement[ligne * sizeX + colonne] = r + 1; 
                           a ++;
                        }
                    }
                    else if (tab_tile[ligne * sizeX + colonne].tileS != 1 && tab_tile[(ligne + 1) * sizeX + colonne].tileN != 1){//pas d'obstacle//
                        if (ligne + 1 < sizeY && tab_deplacement[(ligne + 1) * sizeX + colonne] == r){//voisine du case marquée et dans le tableau//
                            tab_deplacement[ligne * sizeX + colonne] = r + 1;
                            a ++;
                        }
                    }
                    else if (tab_tile[ligne * sizeX + colonne].tileE != 1 && tab_tile[ligne * sizeX + colonne + 1].tileW != 1){ //pas d'obstacle//
                        if (colonne + 1 < sizeX && tab_deplacement[ligne * sizeX + colonne + 1] == r) {//voisine du case marquée et dans le tableau//
                            tab_deplacement[ligne * sizeX + colonne] = r + 1;
                            a ++;
                        }
                    }
                    else if (tab_tile[ligne * sizeX + colonne].tileW != 1 && tab_tile[ligne * sizeX + colonne - 1].tileE != 1){ //pas d'obstacle//
                        if (colonne - 1 > 0 && tab_deplacement[ligne * sizeX + colonne - 1] == r) { //voisine du case marquée et dans le tableau// 
                            tab_deplacement[ligne * sizeX + colonne] = r + 1;
                            a ++;
                        }
                    }   
                }
            }
        }
        //cas où l'arrivée n'est pas atteignable (à cause d' obstacle)//
        if (a == 0){
            return -1;
        }
        //incrementation de r sinon//
        else{
            r++;
            a = 0;
        }
    }
    return 0;
}




/*fonction coup_gagnant: permet de récupérer un trésor
*paramètres:
*joueur(position et prochain tresor)
*tableau de int tab_deplacement(représentation du labyrinthe de tuile par un tableau)
*tableau de tuile tab_tile
*p_move correspondant à mon coup
*lab: le labyrinthe
*dimensions du labyrinthe(sizeX-sizeY)*/

int coup_gagnant(t_joueur* joueur, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move, t_move* p_move_adversaire, int* lab, t_tile* tileOut){
    //sauvegarde de la position//
    int copie_x = joueur->x;
    int copie_y = joueur->y;
    
    /*cas où la tuile contenant le tresor en dehors,
    *pas de coup gagnant possible*/ 
    initTuile(tileOut, p_move_adversaire);
    if (tileOut->tileItem == joueur->nextItem){
        return -1;
    }


    //recherche de la position du trésor// 
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

    //test pour chaque insertion possible si le trésor est atteignable//
    int save = 0; 
    t_insertion insert;	
    int number, rotation;

    //insertion par une ligne (droite ou gauche//
    for(number = 1; number < sizeY; number ++){
        if (number % 2 == 0){//ligne paire impossible//
        }
        else{
            for (rotation = 0; rotation <= 3; rotation ++){
                for (insert = 0; insert <= 1; insert ++){
                    init_tab_tuile(lab, tab_tile, sizeX, sizeY);
                    initTuile(tileOut, p_move_adversaire);
                    rotationTuile(tileOut, save, rotation);
                    insertTuile(tab_tile, tileOut, insert, number, sizeX, sizeY);
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    sortie_tableau(joueur, p_move, sizeX, sizeY);//si l' insertion a fait bouger le pion//

                    //coup permettant d' accéder au trésor//
                    if (deplacement(joueur->x, joueur->y, x_arrivee, y_arrivee, tab_deplacement, sizeX, sizeY, tab_tile) == 0){
                        //ne pas inserer du cote opposé à l' adversaire!//
                        if (p_move_adversaire->insert == p_move->insert || p_move_adversaire->number != p_move->number){
                            p_move->x = x_arrivee;
                            p_move->y = y_arrivee;
                            return 0;
                        }
                    }
                    joueur->x = copie_x;
                    joueur->y = copie_y;
                }  
            }
        }
    }

    //methode analogue mais pour les colonnes cette fois ci (insertion en haut ou en bas)//
    for(number = 1; number < sizeX; number ++){
        if (number % 2 == 0){
        }
        else{
            for (rotation = 0; rotation <= 3; rotation ++){
                for (insert = 2; insert <= 3; insert ++){
                    init_tab_tuile(lab, tab_tile, sizeX, sizeY);
                    initTuile(tileOut, p_move_adversaire);
                    rotationTuile(tileOut, save, rotation);
                    insertTuile(tab_tile, tileOut, insert, number, sizeX, sizeY);
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    sortie_tableau(joueur, p_move, sizeX, sizeY);
                    if (deplacement(joueur->x, joueur->y, x_arrivee, y_arrivee, tab_deplacement, sizeX, sizeY, tab_tile) == 0){
                        if (p_move_adversaire->insert == p_move->insert || p_move_adversaire->number != p_move->number){
                            p_move->x = x_arrivee;
                            p_move->y = y_arrivee;
                            return 0;
                        }
                    }
                    joueur->x = copie_x;
                    joueur->y = copie_y;
                }
            }
        }
    }
    return -1;//cas où aucun chemin ne mène au trésor//
}
    


/*fonction coup_joue: joue un coup normale si le trésor ne peut pas être récupéré
*paramètres:
*joueur(position et prochain tresor)
*tableau de tuile tab_tile
*p_move correspondant à mon coup
*lab: le labyrinthe
*dimensions du labyrinthe(sizeX-sizeY)*/

int coup_joue(t_joueur* joueur, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move, t_move* p_move_adversaire, int* lab, t_tile* tileOut ){
    //sauvegarde de la position//
    int copie_x = joueur->x;
    int copie_y = joueur->y;

    int save = 0; 
    t_insertion insert;	
    int number, rotation;


    //recherche d' un deplacement aléatoire possible en insérant usr une colonne//
    for(number = 1; number < sizeX; number ++){
        if (number % 2 == 0){
        }
        else{
            for (rotation = 0; rotation <= 3; rotation ++){
                for (insert = 2; insert <= 3; insert ++){
                    init_tab_tuile(lab, tab_tile, sizeX, sizeY);
                    initTuile(tileOut, p_move_adversaire);
                    rotationTuile(tileOut, save, rotation);
                    insertTuile(tab_tile, tileOut, insert, number, sizeX, sizeY);
                    p_move->insert = insert;
                    p_move->number = number;
                    p_move->rotation = rotation;
                    sortie_tableau(joueur, p_move, sizeX, sizeY);//cas où l' insertion fait bouger le pion//

                    //deplacement vers le haut//
                    if (tab_tile[joueur->x + sizeX * joueur->y].tileN != 1 && tab_tile[joueur->x + sizeX * (joueur->y - 1)].tileS != 1){
                        if (joueur->y > 0){
                            if (p_move_adversaire->insert == p_move->insert || p_move_adversaire->number != p_move->number){
                                p_move->x = joueur->x;
                                p_move->y = joueur->y - 1;
                                return 0;
                            }
                        }
                    }

                    //deplacement vers la droite//
                    if (tab_tile[joueur->x + sizeX * joueur->y].tileE != 1 && tab_tile[joueur->x + 1 + sizeX * joueur->y].tileW != 1){
                        if (joueur->x < sizeX - 1 ){
                            if (p_move_adversaire->insert == p_move->insert || p_move_adversaire->number != p_move->number){
                                p_move->x = joueur->x + 1;
                                p_move->y = joueur->y;
                                return 0;
                            }
                        }
                    }

                    //deplacement vers le bas//
                    if (tab_tile[joueur->x + sizeX * joueur->y].tileS != 1 && tab_tile[joueur->x + sizeX * (joueur->y + 1)].tileN != 1){
                        if (joueur->y < sizeY - 1){
                            if (p_move_adversaire->insert == p_move->insert || p_move_adversaire->number != p_move->number){
                                p_move->x = joueur->x;  
                                p_move->y = joueur->y + 1;
                                return 0;
                            }
                        }
                    }


                    //deplacement vers la gauche//
                    if (tab_tile[joueur->x + sizeX * joueur->y].tileW != 1 && tab_tile[joueur->x - 1 + sizeX * joueur->y].tileE != 1){
                        if (joueur->x > 0){
                            if (p_move_adversaire->insert == p_move->insert || p_move_adversaire->number != p_move->number){
                                p_move->x = joueur->x - 1;
                                p_move->y = joueur->y;
                                return 0;
                            }
                        }
                    }
                    joueur->x = copie_x;
                    joueur->y = copie_y;
                }
            }
        }
    }

    //si aucun deplacement possible(très peu probable)//
    p_move->insert = 0;
    p_move->number = 1;
    p_move->rotation = 0;
    p_move->x = joueur->x;
    p_move->y = joueur->y;
    return 0;
}    
                



