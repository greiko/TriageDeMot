//
// Created by greiko on 7/8/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "gestionStatistique.h"
//#include "listeChaine.h"
#define  TAILLE_MOT_MAX 20
typedef enum {AUCUN, AVEC, SANS} Option;

FILE* ouvrirFichier(char *pathfichier);

int validationOptionFichier(int nbArgument, char **arguments);

void creerListeChaine(FILE *fichier);

int main(int argc, char **argv)
{
  FILE *fichierALire;
  FILE *fichierStats;
  Option option = AUCUN;
  option = validationOptionFichier(argc, argv);
  fichierALire = ouvrirFichier(argv[1]);
  creerListeChaine(fichierALire);

  return 0;

}

FILE *ouvrirFichier(char *pathFichier)
{
  FILE *fichier;
  fichier = fopen(pathFichier, "r");
  if (fichier == NULL)
  {
    printf("Erreur!\n");
    exit(0);
  }
  return fichier;
}

void creerListeChaine(FILE *fichier)
{
  //struct listeChaine *liste = (struct listeChaine*) malloc((sizeof(char) * 20) + sizeof(struct listeChaine*));
  char c = fgetc(fichier);
  char mot[TAILLE_MOT_MAX];
  while (c != EOF)
  {
    if (c != '\n' && c != ' ')
    {
      mot[TAILLE_MOT_MAX];
      mot[0] = c;
      c = fgetc(fichier);
    }
    else
    {
      //ajouterMot(liste,mot);
    }
  }
  //while (prochainMot(liste) != NULL)
  // {
  // struct listeChaine motCourant;
  // motCourant = liste;
  // printf("%s",getMot(liste));
  // motCourant = prochainMot(liste);
  //}
}

int validationOptionFichier(int nbArgument, char **arguments)
{
  if (nbArgument < 2 || nbArgument > 4)
  {
    printf("Erreur!\n");
    exit(0);
  }
  if (nbArgument == 4 && strcmp("-S", arguments[2]))
  {
    return AVEC;
  }
  else if (nbArgument == 2)
  {
    return SANS;
  }
  else
  {
    printf("Erreur!\n");
    exit(0);
  }
}



