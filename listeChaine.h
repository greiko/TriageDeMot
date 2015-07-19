//
// Created by greiko on 7/8/15.
//


#ifndef TP2_LISTECHAINE_H
#define TP2_LISTECHAINE_H

#define TAILLE_MOT_MAX 20

#include "gestionStatistique.h"

typedef struct listeChaine *Liste_t;
typedef enum
{
  TRUE, FALSE, SAME
} Boolean_t;
typedef enum
{
  AUCUN, AVEC, SANS
} Option_t;

Liste_t creeMot(char *premierMot, Stats_t stats);

Boolean_t comparaisonMot(char *motCourant, char *nouveauMot);

Liste_t placerLeMot(Liste_t courant, Liste_t nouveauMot);

Liste_t ajouterMot(Liste_t liste, char mot[TAILLE_MOT_MAX], Stats_t stats);

int longueur(char *courant, char *nouveauMot);

Liste_t placementMot(Boolean_t echanger, Stats_t stats, Liste_t courant, Liste_t nouveauMot, Liste_t debutListe);

void afficherListe(Liste_t liste, Stats_t stats, Option_t avecStats, char *nomDuFichier);


#endif //TP2_LISTECHAINE_H