/*
* Created by Nicolas Papanicolaou on 7/12/15.
* Code Permanent: PAPN20098909
* がっきプロジェクト2(Projet de Session 2)
* Triage de mot, en enlevant les doublons et qui peut generer des statistiques.
*
*/
#include "gestionStatistique.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef enum
{
  TRUE, FALSE
} Boolean_t;

struct statistique
{
  int nbMotsSansDouble;
  int nbMotsAvecDouble;
  int nbLignes;
  int nbLettres;
  int *lettrePlusFrequente;
};

Stats_t initialisationStats(Stats_t stats)
{
  stats = (Stats_t) malloc(sizeof(struct statistique));
  stats->nbLettres = 0;
  stats->nbLignes = 0;
  stats->nbMotsAvecDouble = 0;
  stats->nbMotsSansDouble = 0;
  stats->lettrePlusFrequente = initialisationTableauLettre();
  return stats;
}

int *initialisationTableauLettre()
{
  int *tableau;
  tableau = (int *) malloc(sizeof(int) * 26);
  int i;
  for (i = 0; i < 26; i++)
  {
    tableau[i] = 1;
  }
  return tableau;
}


void compteurLettre(Stats_t stats, char *mot)
{
  stats->nbLettres += strlen(mot);
}

void compteurMotSansDoublons(Stats_t stats, char *mot)
{
  int i;
  for (i = 0; i < strlen(mot); i++)
  {
    frequenceLettre(stats, mot[i]);
  }
  stats->nbMotsSansDouble += 1;
}

void compteurMotTotal(Stats_t stats)
{
  stats->nbMotsAvecDouble += 1;
}

void compteurLignes(Stats_t stats)
{
  stats->nbLignes += 1;
}

void frequenceLettre(Stats_t stats, char lettre)
{
  char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z'};
  int i;
  int position = 0;
  for (i = 0; lettre != alphabet[i]; i++)
  {
    position++;
  }
  stats->lettrePlusFrequente[position] += 1;
}

char laLettreFrequente(Stats_t stats)
{
  char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z' , ' '};
  int frequence = 1;
  int position = 0;
  Boolean_t aucuneLettre = TRUE;
  int i;
  for (i = 0;i < 26; i++)
  {
    if (stats->lettrePlusFrequente[i] > frequence)
    {
      frequence = stats->lettrePlusFrequente[i];
      position = i;
      aucuneLettre = FALSE;
    }
  }
  if (aucuneLettre == TRUE)
  {
    position = 26;
  }
  return alphabet[position];
}

void afficherStats(Stats_t stats, char *nomDuFichier)
{
  FILE *fichier = NULL;
  fichier = validationFichierSortie(fichier, nomDuFichier);
  fprintf(fichier, "Nombre de mots avec doublons: %d\n", stats->nbMotsAvecDouble);
  fprintf(fichier, "Nombre de mots sans doublons: %d\n", stats->nbMotsSansDouble);
  fprintf(fichier, "Nombre de lignes: %d\n", stats->nbLignes);
  fprintf(fichier, "Nombre de lettres: %d\n", stats->nbLettres);
  fprintf(fichier, "Lettre la plus frequente: %c\n", laLettreFrequente(stats));
  fclose(fichier);
}

FILE *validationFichierSortie(FILE *fichier, char *nomDuFichier)
{
  fichier = fopen(nomDuFichier, "w");
  if (fichier == NULL)
  {
    printf("Erreur ouverture du fichier de statistiques: %d",errno);
    exit(1);
  }
  return fichier;
}