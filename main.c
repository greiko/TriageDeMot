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


FILE *ouvrirFichier(char *pathfichier);

Option_t validationOptionFichier(int nbArgument, char **arguments);

void creerListeChaine(FILE *fichier, Option_t option, char *nomDuFichierStats);

void triageMot(Liste_t listeATrier, int longueurListe_t);

Liste_t motComplet(char c, char *mot, Stats_t stats, Liste_t liste, int n, Boolean_t premierMot);


int main(int argc, char **argv)
{
  FILE *fichierALire = NULL;
  Option_t option = AUCUN;
  option = validationOptionFichier(argc, argv);
  fichierALire = ouvrirFichier(argv[1]);
  creerListeChaine(fichierALire, option, argv[3]);
  fclose(fichierALire);
  return 0;
}

FILE *ouvrirFichier(char *pathFichier)
{
  FILE *fichier;
  fichier = fopen(pathFichier, "r");
  if (fichier == NULL)
  {
    printf("Erreur lors d'ouverture du fichier: %d\n",errno);
    exit(1);
  }
  return fichier;
}

void creerListeChaine(FILE *fichier, Option_t option, char *nomDuFichierStats)
{
  Liste_t liste;
  Stats_t stats = NULL;
  Boolean_t premierMot = TRUE;
  char c = fgetc(fichier);
  char mot[TAILLE_MOT_MAX];
  int n = 0;
  stats = initiationStats(stats);
  while (c != EOF)
  {
    if (c != '\n' && c != ' ')
    {
      mot[n] = c;
      n++;
      c = fgetc(fichier);
    }
    else
    {
      liste = motComplet(c, mot, stats, liste, n, premierMot);
      n = 0;
      premierMot = FALSE;
      c = fgetc(fichier);
    }
  }
  afficherListe(liste, stats, option, nomDuFichierStats);
}

Liste_t motComplet(char c, char *mot, Stats_t stats, Liste_t liste, int n, Boolean_t premierMot)
{
  if (c == '\n')
  {
    compteurLignes(stats, 1);
  }
  mot[n] = '\0';
  if (premierMot == TRUE)
  {
    compteurMotSansDoublons(stats, mot);
    liste = creeMot(mot, stats);
    compteurLettre(stats, mot);
  }
  else
  {
    liste = ajouterMot(liste, mot, stats);
  }
  return liste;
}

Option_t validationOptionFichier(int nbArgument, char **arguments)
{
  if (nbArgument < 2 || nbArgument > 4)
  {
    printf("Erreur nombre d'arguments! \nVeuillez lire le README pour les instructions: %d\n",errno);
    exit(1);
  }
  if (nbArgument == 4 && strcmp("-S", arguments[2]) == 0)
  {
    return AVEC;
  }
  else if (nbArgument == 2)
  {
    return SANS;
  }
  else
  {
    printf("Erreur utilisation du programme!\nVeuillez lire le README pour les instructions: %d\n",errno);
    exit(1);
  }
}
