#include "listeChaine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


struct listeChaine
{
  Liste precedent;
  char mot[TAILLE_MOT_MAX];
  Liste prochain;
};

Liste creeMot(char *premierMot, Stats stats)
{
  Liste nouvelleListe;
  compteurMotTotal(stats);
  nouvelleListe = (Liste) malloc(sizeof(struct listeChaine));
  strcpy(nouvelleListe->mot, premierMot);
  return nouvelleListe;
}

Liste ajouterMot(Liste liste, char mot[TAILLE_MOT_MAX], Stats stats)
{
  if (mot == NULL)
  {
    printf("erreur\n");
    exit(0);
  }
  Liste nouveauMot = creeMot(mot, stats);
  Boolean echanger = FALSE;
  Liste debutListe = liste;
  Liste courant = liste;
  while (echanger != TRUE && courant->prochain != NULL)
  {
    echanger = comparaisonMot(courant->mot, nouveauMot->mot);
    if (echanger == FALSE)
    {
      courant = courant->prochain;
    }
    else if (echanger == SAME)
    {
      break;
    }
  }
  echanger = comparaisonMot(courant->mot, nouveauMot->mot);
  debutListe = quelquechose(echanger,stats,courant,nouveauMot,debutListe);
  return debutListe;
}

Liste quelquechose(Boolean echanger,Stats stats,Liste courant,Liste nouveauMot,Liste debutListe)
{
  if (echanger != SAME)
  {
    compteurMotSansDoublons(stats);
    compteurLettre(stats, nouveauMot->mot);
    if (courant->prochain == NULL && echanger == FALSE)
    {
      nouveauMot->precedent = courant;
      courant->prochain = nouveauMot;
      return debutListe;
    }
    courant = placerLeMot(courant,nouveauMot);
    if (courant->precedent == NULL)
    {
      debutListe = courant;
    }
  }
  return debutListe;
}

Liste placerLeMot(Liste courant, Liste nouveauMot)
{
  if (courant->precedent != NULL)
  {
    courant->precedent->prochain = nouveauMot;
  }
  nouveauMot->prochain = courant;
  nouveauMot->precedent = courant->precedent;
  courant->precedent = nouveauMot;
  courant = nouveauMot;
  return courant;
}

int longueur(char *courant, char *nouveauMot)
{
  int longueurCourte = 0;
  int longueurCourant = (int) strlen(courant);
  int longueurProchain = (int) strlen(nouveauMot);
  longueurCourte = longueurCourant <= longueurProchain ? longueurCourant : longueurProchain;
  return longueurCourte;
}

Boolean comparaisonMot(char *motCourant, char *nouveauMot)
{
  Boolean echanger = FALSE;
  int longueurCourte = longueur(motCourant,nouveauMot);
  int i;
  if (strcmp(motCourant, nouveauMot) == 0)
  {
    return SAME;
  }
  for (i = 0; i <= longueurCourte; i++)
  {
    if (motCourant[i] == '\0' || nouveauMot[i] == '\0')
    {
      echanger = strlen(nouveauMot) == longueurCourte ? TRUE : FALSE;
    }
    if (motCourant[i] != nouveauMot[i])
    {
      if (motCourant[i] > nouveauMot[i])
      {
        echanger = TRUE;
      }
      break;
    }
  }
  return echanger;
}

void afficherListe(Liste liste,Stats stats,Option avecStats,char* nomDuFichier)
{
  Liste courant = liste;
  while (courant->prochain != NULL)
  {
    printf("%s\n", courant->mot);
    courant = courant->prochain;
  }
  printf("%s\n", courant->mot);
  if (avecStats == AVEC)
  {
    afficherStats(stats,nomDuFichier);
  }
}
