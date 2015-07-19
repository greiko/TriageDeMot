//
// Created by greiko on 7/8/15.
//


#ifndef TP2_GESTIONSTATISTIQUE_H
#define TP2_GESTIONSTATISTIQUE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct statistique *Stats;
Stats initiationStats(Stats stats);
int* initiationTableauLettre();
void compteurLettre(Stats stats,char* mot);
void compteurMotSansDoublons(Stats stats,char* mot);
void compteurMotTotal(Stats stats);
void compteurLignes(Stats stats,int combien);
void frequenceLettre(Stats stats,char lettre);
char lettreFrequente(Stats stats);
void afficherStats(Stats stats,char* nomDuFichier);
FILE* validationFichierSortie(FILE* fichier,char* nomDuFichier);

#endif //TP2_GESTIONSTATISTIQUE_H
