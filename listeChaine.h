//
// Created by greiko on 7/8/15.
//


#ifndef TP2_LISTECHAINE_H
#define TP2_LISTECHAINE_H

#define TAILLE_MOT_MAX 20

#include "gestionStatistique.h"
typedef struct listeChaine *Liste;
typedef enum {TRUE,FALSE,SAME} Boolean;
typedef enum {AUCUN, AVEC, SANS} Option;

Liste creeMot(char *premierMot, Stats stats);
Boolean comparaisonMot(char* motCourant,char* nouveauMot);
Liste placerLeMot(Liste courant,Liste nouveauMot);
Liste ajouterMot(Liste liste, char mot[TAILLE_MOT_MAX], Stats stats);
int longueur(char *courant, char *nouveauMot);
Liste quelquechose(Boolean echanger,Stats stats,Liste courant,Liste nouveauMot,Liste debutListe);
void afficherListe(Liste liste,Stats stats,Option avecStats);



#endif //TP2_LISTECHAINE_H