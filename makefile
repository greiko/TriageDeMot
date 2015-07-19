CC = gcc
OPTIONS = -Wall
EXE = main
OBJS = gestionStatistique.o listeChaine.o main.o
MTEST = gestionStatistique.o listeChaine.o testListeChaine.o

.SUFFIXES: .c .o

all: link

test: mtestcompile

mtestcompile:
	$(CC) $(OPTIONS) gestionStatistique.c listeChaine.c testListeChaine.c -g

compile: $(OBJS)

.c.o:
	$(CC) $(OPTIONS) gestionStatistique.c listeChaine.c main.c -c

link: compile
	$(CC) $(OBJS) -o $(EXE)

debug:
	$(CC) gestionStatistique.c listeChaine.c main.c -g

clean:
	rm $(EXE)
	rm $(OBJS)
cleantest:
	rm $(EXE)
	rm $(MTEST)


