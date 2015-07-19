//
// Created by greiko on 7/8/15.
//


#ifndef TP2_GESTIONSTATISTIQUE_H
#define TP2_GESTIONSTATISTIQUE_H
typedef struct statistique *Stats;
Stats initiationStats(Stats stats);
char* initiationTableauLettre();
void compteurLettre(Stats stats,char* mot);
void compteurMotSansDoublons(Stats stats);
void compteurMotTotal(Stats stats);
void compteurLignes(Stats stats,int combien);
void frequenceLettre(Stats stats,char lettre);
char lettreFrequente(Stats stats);
void afficherStats(Stats stats);

#endif //TP2_GESTIONSTATISTIQUE_H
