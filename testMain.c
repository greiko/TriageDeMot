//
// Created by greiko on 7/8/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "gestionStatistique.h"
#include "listeChaine.h"
#define  TAILLE_MOT_MAX 20
typedef enum {AUCUN, AVEC, SANS} Option;
typedef enum {TRUE,FALSE} Boolean;

FILE* ouvrirFichier(char *pathfichier);

int validationOptionFichier(int nbArgument, char **arguments);

void creerListeChaine(FILE *fichier);

void triageMot(Liste listeATrier,int longueurListe);

Boolean comparaisonMot(Liste courant,Liste prochaine);

int main(int argc, char **argv)
{
  FILE *fichierALire;
  FILE *fichierStats;
  //Option option = AUCUN;
  //option = validationOptionFichier(argc, argv);
  //fichierALire = ouvrirFichier(argv[1]);
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

  int longueurListe = 4;
  Liste debutListe = creeMot();
  ajouterMot(debutListe,"ZETA");
  ajouterMot(debutListe,"PIPI");
  ajouterMot(debutListe,"CACA");
  ajouterMot(debutListe,"ALPHA");
//  char c = fgetc(fichier);
//  char mot[TAILLE_MOT_MAX];
//  int n = 0;
//  while (c != EOF)
//  {
//    if (c != '\n' && c != ' ')
//    {
//      mot[n] = c;
//      //printf("c = %c and mot = %s\n",c,mot); TEST
//      n++;
//      c = fgetc(fichier);
//    }
//    else
//    {
//      mot[n] = '\0';
//      n = 0;
//      ajouterMot(debutListe,mot);
//      longueurListe++;
//      c = fgetc(fichier);
//    }
//  }
  triageMot(debutListe,longueurListe);
  Liste tempListe = debutListe;
  while (nouveauMot(tempListe) != NULL)
  {
    printf("%s \n",getMot(tempListe));
    tempListe = nouveauMot(tempListe);
  }
  printf("%s \n",getMot(tempListe));
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

void triageMot(Liste listeATrier,int longueurListe)
{
  Liste debut = listeATrier;
  Liste courant = listeATrier;
  int i;
  int j;
  for (i = longueurListe;i > 1;i--)
  {
    for (j = 0;j < i;j++)
    {
      if (comparaisonMot(courant, nouveauMot(courant)) == TRUE)
      {
        char motTemp[TAILLE_MOT_MAX];
        strcpy(motTemp,getMot(courant));
        changerMot(courant,getMot(nouveauMot(courant)));
        changerMot(nouveauMot(courant),motTemp);
      }
      courant = nouveauMot(courant);
    }
    courant = debut;
  }
}

Boolean comparaisonMot(Liste courant,Liste prochain)
{
  Boolean echanger = FALSE;
  char motCourant[20];
  char prochainMot[20];
  strcpy(motCourant,getMot(courant));
  strcpy(prochainMot,getMot(prochain));
  int longueurCourant = (int) strlen(motCourant);
  int longueurProchain = (int) strlen(prochainMot);
  int i;
  int longueurCourte = 0;
  longueurCourant <= longueurProchain ? longueurCourte = longueurCourant : (longueurCourte = longueurProchain);
  for (i = 0;i < longueurCourte;i++)
  {
    if (motCourant[i] != prochainMot[i])
    {
      if (motCourant[i] > prochainMot[i])
      {
        echanger = TRUE;
      }
      break;
    }
  }
  return echanger;
}


