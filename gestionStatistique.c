//
// Created by greiko on 7/8/15.
//

#include "gestionStatistique.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char ALPHABET[] = {'A','B','C','D','E','F','G','H','I','J',
                   'K','L','M','N','O','P','Q','R','S','T',
                   'U','V','W','X','Y','Z'};

struct statistique
{
  int nb_mots_sans_double;
  int nb_mots_avec_double;
  int nb_lignes;
  int nb_lettres;
  char *lettre_plus_frequente;
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

char *initiationTableauLettre()
{
  char* tableau;
  tableau = (char*) malloc(sizeof(char) * 26);
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

void compteurMotSansDoublons(Stats stats)
{
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

}

char lettreFrequente(Stats stats)
{
  return 'k';
}

void afficherStats(Stats stats)
{
  int nb_mots_sans_doublons = stats->nb_mots_sans_double - stats->nb_mots_avec_double;
  printf("Nombre de mots avec doublons: %d\n",stats->nb_mots_avec_double);
  printf("Nombre de mots sans doublons: %d\n",stats->nb_mots_sans_double);
  printf("Nombre de lignes: %d\n",stats->nb_lignes);
  printf("Nombre de lettres: %d\n",stats->nb_lettres);

}