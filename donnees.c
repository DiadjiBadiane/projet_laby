


typedef struct{
    int x,
    int y,
    int nextItem,
    t_move moveAdversaire,
}t_Joueur;

typedef struct{
    int x_adversaire,
    int y_adversaire,
    int nextItemAdverse,
    t_move moveJoueur,
}t_Adversaire;

typedef struct{
    t_Joueur joueur,
    t_Adversaire adversaire,
    int sizeX,
    int sizeY,
}t_labyrinthe;


int init_donnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, int sizeX, int sizeY){
    joueur->x = 0;
    joueur->y = 0;
    joueur->nextItem = 1;

    t_adversaire adversaire;
    adversaire->x = sizeX - 1;
    adversaire->y = sizeY - 1;
    adversaire->nextItemAdversse = 24;

    t_labyrinthe labyrinthe;
    labyrinthe->joueur = &joueur;
    labyrinthe->adversaire = &adversaire;
    labyrinthe->sizeX = sizeX;
    labyrinthe->sizeY = sizeY;
}

int miseAJourDonnees(t_joueur* joueur,t_adversaire* adversaire, t_labyrinthe* labyrinthe, t_move* p_move, t_move* p_move_adversaire){
    joueur->x = p_move->x;
    joueur->y = p_move->y;
    joueur->nextItem = p_move->nextItem;

    adversaire->x = p_move_adversaire->x;
    adversaire->y = p_move_adversaire->y;
    adversaire->nextItemAdversse = p_move_adversaire->nextItem;

    labyrinthe->joueur = &joueur;
    labyrinthe->adversaire = &adversaire;   
}

