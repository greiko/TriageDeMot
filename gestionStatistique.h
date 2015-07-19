//
// Created by greiko on 7/8/15.
//


#ifndef TP2_GESTIONSTATISTIQUE_H
#define TP2_GESTIONSTATISTIQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct statistique *Stats_t;

Stats_t initiationStats(Stats_t stats);

int *initiationTableauLettre();

void compteurLettre(Stats_t stats, char *mot);

void compteurMotSansDoublons(Stats_t stats, char *mot);

void compteurMotTotal(Stats_t stats);

void compteurLignes(Stats_t stats, int combien);

void frequenceLettre(Stats_t stats, char lettre);

char lettreFrequente(Stats_t stats);

void afficherStats(Stats_t stats, char *nomDuFichier);

FILE *validationFichierSortie(FILE *fichier, char *nomDuFichier);

#endif //TP2_GESTIONSTATISTIQUE_H
