//
// Created by greiko on 7/8/15.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "gestionStatistique.h"
#include "listeChaine.h"

int main(int argc,char** argv)
{
  char* caca = "CACA";
  char* pipi = "PIPI";
  char* bebe = "BEBE";
  char* delta = "DELTA";
  char* alpha = "ALPHA";
  char* gamma = "GAMMA";
  char* cca = "cca";
  char* la = "LA";
  char* lance = "LANCE";
  char* un = "UN";
  char* une = "UNE";
  char* votre = "VOTRE";
  char* logiciel = "LOGICIEL";
  char* sera = "SERA";
  char* a = "A";
  char* console = "CONSOLE";
  char* en = "EN";
  //VOTRE LOGICIEL SERA LANCE A LA CONSOLE EN
  Boolean echanger = FALSE;
  echanger = comparaisonMot(pipi,caca);
  Stats stats;
  stats = initiationStats(stats);
  //should be true TRUE=0 FALSE=1
  printf("echanger = %d\n",echanger);
  //
  Liste liste = creeMot(votre,stats);
  liste = ajouterMot(liste,logiciel,stats);
  liste = ajouterMot(liste,sera,stats);
  liste = ajouterMot(liste,lance,stats);
  liste = ajouterMot(liste,a,stats);
  liste = ajouterMot(liste,la,stats);
  liste = ajouterMot(liste,console,stats);
  liste = ajouterMot(liste,en,stats);

  //liste = ajouterMot(liste,un,stats);
  //liste = ajouterMot(liste,une,stats);

//  Liste m1 = creeMot(pipi);
//  Liste m2 = creeMot(bebe);
//  placerLeMot(liste,liste,m2)
  afficherListe(liste);
  afficherStats(stats);

  return 0;
}
