//
// Created by greiko on 7/8/15.
//

#include "listeChaine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


struct listeChaine
{
  Liste_t precedent;
  char mot[TAILLE_MOT_MAX];
  Liste_t prochain;
};

Liste_t creeMot(char *premierMot, Stats_t stats)
{
  Liste_t nouvelleListe;
  compteurMotTotal(stats);
  nouvelleListe = (Liste_t) malloc(sizeof(struct listeChaine));
  strcpy(nouvelleListe->mot, premierMot);
  return nouvelleListe;
}

Liste_t ajouterMot(Liste_t liste, char mot[TAILLE_MOT_MAX], Stats_t stats)
{
  if (mot == NULL)
  {
    printf("Erreur, le mot est NULL!: %d\n",errno);
    exit(0);
  }
  Liste_t nouveauMot = creeMot(mot, stats);
  Boolean_t echanger = FALSE;
  Liste_t debutListe = liste;
  Liste_t courant = liste;
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
  debutListe = placementMot(echanger, stats, courant, nouveauMot, debutListe);
  return debutListe;
}

Liste_t placementMot(Boolean_t echanger, Stats_t stats, Liste_t courant, Liste_t nouveauMot, Liste_t debutListe)
{
  if (echanger != SAME)
  {
    compteurMotSansDoublons(stats, nouveauMot->mot);
    compteurLettre(stats, nouveauMot->mot);
    if (courant->prochain == NULL && echanger == FALSE)
    {
      nouveauMot->precedent = courant;
      courant->prochain = nouveauMot;
      return debutListe;
    }
    courant = placerLeMot(courant, nouveauMot);
    if (courant->precedent == NULL)
    {
      debutListe = courant;
    }
  }
  return debutListe;
}

Liste_t placerLeMot(Liste_t courant, Liste_t nouveauMot)
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

Boolean_t comparaisonMot(char *motCourant, char *nouveauMot)
{
  Boolean_t echanger = FALSE;
  int longueurCourte = longueur(motCourant, nouveauMot);
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

void afficherListe(Liste_t liste, Stats_t stats, Option_t avecStats, char *nomDuFichier)
{
  Liste_t courant = liste;
  while (courant->prochain != NULL)
  {
    printf("%s\n", courant->mot);
    courant = courant->prochain;
  }
  printf("%s\n", courant->mot);
  if (avecStats == AVEC)
  {
    afficherStats(stats, nomDuFichier);
  }
}
