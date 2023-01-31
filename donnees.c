#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

/*fonction init_donnees: initialise le jeu avec les donnees de départ
*paramètres:
*donnees du joueur(position + prochain tresor)
*donees de l' adversaire (position + prochain tresor)
*donnees du labyrinthe,
*le labyrinthe(lab)
*la taille du labyrinthe(sizex et sizeY)*/

void init_donnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, int* lab, int sizeX, int sizeY){
    joueur->x = 0;
    joueur->y = 0;
    joueur->nextItem = 1;

    adversaire->x = sizeX - 1;
    adversaire->y = sizeY - 1;
    adversaire->nextItem = 24;

    labyrinthe->copy_lab = lab;
}




/*fonction miseAjourDonees:met à jour les données du jeu
paramètres : 
*joueur (t_joueur: position et prochain tresor)
*adversaire(t_adversaire: position et prochain tresor)
*copie du labyrinthe
*p_move: definit mon coup
*p_move_adversaire: definit le coup de l' adversaire
*le labyrinthe (lab)*/

void miseAJourDonnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, t_move* p_move, t_move* p_move_adversaire, int* lab){
    //nouvelle position et prochain tresor//
    joueur->x = p_move->x;
    joueur->y = p_move->y;
    joueur->nextItem = p_move->nextItem;

    //nouvelle position et prochain tresor de l' adversaire//
    adversaire->x = p_move_adversaire->x;
    adversaire->y = p_move_adversaire->y;
    adversaire->nextItem = p_move_adversaire->nextItem;

    labyrinthe->copy_lab = lab;
}



/*fonction sortie_tableau_adv: modifie la position du joueur si l' adversaire le deplace lors de son coup
*paramètres: joueur(position + prochain tresor)
*coup de l' adversaire
*dimensions du labyrinthe */
void sortie_tableau_adv(t_joueur* joueur,t_move* p_move_adversaire, int sizeX,int sizeY){
    //insertion par le dessous//
    if (p_move_adversaire->insert == 3 && p_move_adversaire->number == joueur->x){
        //cas où le pion sort du labyrinthe//
        if (joueur->y == 0){
            joueur->y = sizeY - 1;
        }    
        else{
            joueur->y = joueur->y - 1;
        }
    }    

    //insertion par le dessus//
    else if (p_move_adversaire->insert == 2 && p_move_adversaire->number == joueur->x){
        //cas où le pion sort du labyrinthe//
        if (joueur->y == sizeY - 1){
            joueur->y = 0;
        }
        else{
            joueur->y = joueur->y + 1;
        }
    }

    //insertion par la droite//
    else if (p_move_adversaire->insert == 1 && p_move_adversaire->number == joueur->y){
        //cas où le pion sort du labyrinthe//
        if (joueur->x == 0){
            joueur->x = sizeX - 1;
        }
        else{
            joueur->x = joueur->x - 1;
        }
    }

    //insertion par la gauche//
    else if (p_move_adversaire->insert == 0 && p_move_adversaire->number == joueur->y){
        //cas où le pion sort du labyrinthe//
        if (joueur->x == sizeX - 1){
            joueur->x = 0;
        }
        else{
            joueur->x = joueur->x + 1;
        }
    }
    else{
    }
}



/*fonction sortie_tableau: analogue à sortie_tableau_adv mais pour mon coup
**paramètres: joueur(position + prochain tresor)
*mon coup
*dimensions du labyrinthe */

void sortie_tableau(t_joueur* joueur,t_move* p_move , int sizeX,int sizeY){
    //insertion par le dessous//
    if (p_move->insert == 3 && p_move->number == joueur->x){
        //cas où le pion sort du labyrinthe//
        if (joueur->y == 0){
            joueur->y = sizeY - 1;
        }    
        else{
            joueur->y = joueur->y - 1;
        }
    }    

    //insertion par le dessus//
    else if (p_move->insert == 2 && p_move->number == joueur->x){
        //cas où le pion sort du labyrinthe//
        if (joueur->y == sizeY - 1){
            joueur->y = 0;
        }
        else{
            joueur->y = joueur->y + 1;
        }
    }

    //insertion par la droite//
    else if (p_move->insert == 1 && p_move->number == joueur->y){
        //cas où le pion sort du labyrinthe//
        if (joueur->x == 0){
            joueur->x = sizeX - 1;
        }
        else{
            joueur->x = joueur->x - 1;
        }
    }

    //insertion par la gauche//
    else if (p_move->insert == 0 && p_move->number == joueur->y){
        //cas où le pion sort du labyrinthe//
        if (joueur->x == sizeX - 1){
            joueur->x = 0;
        }
        else{
            joueur->x = joueur->x + 1;
        }
    }
    else{
    }
}