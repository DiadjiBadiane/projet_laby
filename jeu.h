typedef struct{
    int tileN;
    int tileE;
    int tileS;
    int tileW;
    int tileItem;
}t_tile;


int init_tab_tuile(int* lab, t_tile* tab_tile, int sizeX, int sizeY);
int deplacement(x_depart, y_depart, x_arrivee, y_arrivee, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile);
int coup_joue(t_joueur joueur, int* tab_deplacement, int sizeX, int sizeY, t_tile* tab_tile, t_move* p_move);