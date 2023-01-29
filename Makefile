# Modèle de fichier Makefile, à adapter pour le TP

# options de compilation
CC = gcc	
CCFLAGS = -Wall

# fichiers du projet
SRC = labyrinthAPI.c main.c clientAPI.c donnees.c jeu.c
OBJ = $(SRC:.c=.o)
EXEC = run.out


# règle initiale
all: $(EXEC)

# dépendance des .h
main.o: main.c 
clientAPI.o: clientAPI.c clientAPI.h
labyrintheAPI.o: labyrinthAPI.c labyrinthAPI.h	
donnees.o: donnees.c donnees.h
jeu.o: jeu.c jeu.h

# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ 

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o