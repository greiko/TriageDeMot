//
// Created by greiko on 7/8/15.
//

#include "gestionStatistique.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


struct statistique
{
  int nb_mots_sans_double;
  int nb_mots_avec_double;
  int nb_lignes;
  int nb_lettres;
  int *lettre_plus_frequente;
};

Stats initiationStats(Stats stats)
{
  stats = (Stats) malloc(sizeof(struct statistique));
  stats->nb_lettres = 0;
  stats->nb_lignes = 0;
  stats->nb_mots_avec_double = 0;
  stats->nb_mots_sans_double = 0;
  stats->lettre_plus_frequente = initiationTableauLettre();
  return stats;
}

int *initiationTableauLettre()
{
  int* tableau;
  tableau = (int*) malloc(sizeof(int) * 26);
  int i;
  for (i = 0; i < 26; i++)
  {
    tableau[i] = 0;
  }
  return tableau;
}


void compteurLettre(Stats stats, char *mot)
{
  stats->nb_lettres += strlen(mot);
}

void compteurMotSansDoublons(Stats stats,char* mot)
{
  int i;
  for (i = 0;i < strlen(mot);i++)
  {
    frequenceLettre(stats,mot[i]);
  }
  stats->nb_mots_sans_double += 1;
}
void compteurMotTotal(Stats stats)
{
  stats->nb_mots_avec_double += 1;
}

void compteurLignes(Stats stats,int combien)
{
  stats->nb_lignes += combien;
}

void frequenceLettre(Stats stats, char lettre)
{
  char alphabet[] = {'A','B','C','D','E','F','G','H','I','J',
                     'K','L','M','N','O','P','Q','R','S','T',
                     'U','V','W','X','Y','Z'};
  int i;
  int position = 0;
  for (i = 0;lettre != alphabet[i];i++)
  {
    position++;
  }
  stats->lettre_plus_frequente[position] += 1;
}

char lettreFrequente(Stats stats)
{
  char alphabet[] = {'A','B','C','D','E','F','G','H','I','J',
                     'K','L','M','N','O','P','Q','R','S','T',
                     'U','V','W','X','Y','Z'};
  int frequence = stats->lettre_plus_frequente[0];
  int position = 0;
  int i;
  for (i = 1;i < 26;i++)
  {
    if (stats->lettre_plus_frequente[i] > frequence)
    {
      frequence = stats->lettre_plus_frequente[i];
      position = i;
    }
  }
  return alphabet[position];
}

void afficherStats(Stats stats,char* nomDuFichier)
{
  FILE* fichier = NULL;
  fichier = validationFichierSortie(fichier,nomDuFichier);
  fprintf(fichier,"Nombre de mots avec doublons: %d\n",stats->nb_mots_avec_double);
  fprintf(fichier,"Nombre de mots sans doublons: %d\n",stats->nb_mots_sans_double);
  fprintf(fichier,"Nombre de lignes: %d\n",stats->nb_lignes);
  fprintf(fichier,"Nombre de lettres: %d\n",stats->nb_lettres);
  fprintf(fichier,"Lettre la plus frequente: %c\n",lettreFrequente(stats));
  fclose(fichier);
}

FILE* validationFichierSortie(FILE* fichier,char* nomDuFichier)
{
  fichier = fopen(nomDuFichier,"w");
  if(fichier == NULL)
  {
    printf("Error!");
    exit(1);
  }
  return fichier;
}