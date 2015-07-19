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
  Liste liste = creeMot(caca,stats);
  liste = ajouterMot(liste,pipi,stats);
  liste = ajouterMot(liste,delta,stats);
  liste = ajouterMot(liste,alpha,stats);
  liste = ajouterMot(liste,gamma,stats);
  afficherStats(stats,"testStats.txt");

  return 0;
}
