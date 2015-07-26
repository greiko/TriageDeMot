/*
* Created by Nicolas Papanicolaou on 7/12/15.
* Code Permanent: PAPN20098909
* がっきプロジェクト2(Projet de Session 2)
* Triage de mot, en enlevant les doublons et qui peut generer des statistiques.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "gestionStatistique.h"
#include "listeChaine.h"

#define  TAILLE_MOT_MAX 82

/*
 * Valide si le fichier contenant les mots soit bien traitee.
 * pathFichier: Le path du fichier a ouvrir.
 * Valeur de retour: Pointeur sur le fichier ouvert.
 */
FILE *ouvrirFichier(char *pathFichier);

/*
 * Validation de la ligne de commande.
 * nbArgument: Le nombre de argument sur la ligne de commande.
 * arguments: Les arguments de la ligne de commande.
 * Valeur de retour: Avec ou sans statistiques.
 */
Option_t validationOptionFichier(int nbArgument, char **arguments);

/*
 * Cree la liste chaine avec les mots qui sont contenus dans le fichier.
 * fichier: Fichier contenant les mots a trier.
 * option: Avec ou sans statistiques.
 * nomDuFichierStats: Le nom du fichier statistiques si utiliser.
 */
void creerListeChaine(FILE *fichier, Option_t option, char *nomDuFichierStats);

/*
 * Les instructions quoi faire quand le mot est complet.
 * c: le char courant du fichier
 * mot: le mot complet
 * stats: Les statistiques
 * liste: La liste chaine
 * n: utiliser pour mettre un \0 a la fin du mot
 * premierMot: permet de savoir si cest le debut du programme
 * Valeur de retour: La liste chaine modifie
 */
Liste_t motComplet(char c, char *mot, Stats_t stats, Liste_t liste, int n, Boolean_t premierMot);

void estUneLigne(char c,Stats_t stats);

Liste_t estPasFinDeFichier(char c,char mot[TAILLE_MOT_MAX],int n,Liste_t liste,Boolean_t premierMot,Stats_t stats,FILE* fichier);
int main(int argc, char **argv)
{
  FILE *fichierALire = NULL;
  Option_t option = SANS;
  option = validationOptionFichier(argc, argv);
  fichierALire = ouvrirFichier(argv[1]);
  creerListeChaine(fichierALire, option, argv[3]);
  fclose(fichierALire);
  return 0;
}

FILE *ouvrirFichier(char *pathFichier)
{
  FILE *fichier;
  fichier = fopen(pathFichier, "r");
  if (fichier == NULL)
  {
    printf("Erreur lors d'ouverture du fichier: %d\n", errno);
    exit(1);
  }
  return fichier;
}

void estUneLigne(char c,Stats_t stats)
{
  if (c == '\n')
  {
    compteurLignes(stats);
  }
}


Liste_t estPasFinDeFichier(char c,char mot[TAILLE_MOT_MAX],int n,Liste_t liste,Boolean_t premierMot,Stats_t stats,FILE* fichier)
{
  Boolean_t premiereLettre = TRUE;
  while (c != EOF)
  {
    if (c != '\n' && c != ' ')
    {
      premiereLettre = FALSE;
      mot[n] = c;
      n++;
      c = fgetc(fichier);
    }
    else
    {
      while (c == '\n' || c == ' ')
      {
        estUneLigne(c,stats);
        c = fgetc(fichier);
      }
      if (premiereLettre == FALSE)
      {
        liste = motComplet(c, mot, stats, liste, n, premierMot);
        n = 0;
        premierMot = FALSE;
        premiereLettre = TRUE;
      }
    }
  }
  return liste;
}

void creerListeChaine(FILE *fichier, Option_t option, char *nomDuFichierStats)
{
  Liste_t liste = NULL;
  Stats_t stats = NULL;
  Boolean_t premierMot = TRUE;
  char c = fgetc(fichier);
  char mot[TAILLE_MOT_MAX];
  int n = 0;
  if (c != EOF)
  {
    stats = initialisationStats(stats);
    liste = estPasFinDeFichier(c,mot,n,liste,premierMot,stats,fichier);
    afficherListe(liste, stats, option, nomDuFichierStats);
  }
}

Liste_t motComplet(char c, char *mot, Stats_t stats, Liste_t liste, int n, Boolean_t premierMot)
{
  if (c == '\n')
  {
    compteurLignes(stats);
  }
  mot[n] = '\0';
  if (premierMot == TRUE && mot != NULL)
  {
    if (strcmp(mot,"") != 0){
      compteurMotSansDoublons(stats, mot);
    }
    liste = creationMot(mot, stats);
    compteurLettre(stats, mot);
  }
  else if (mot != NULL)
  {
    liste = ajouterMot(liste, mot, stats);
  }
  return liste;
}

Option_t validationOptionFichier(int nbArgument, char **arguments)
{
  if (nbArgument < 2 || nbArgument > 4)
  {
    printf("Erreur nombre d'arguments! \nVeuillez lire le README pour les instructions: %d\n", errno);
    exit(1);
  }
  if (nbArgument == 4 && strcmp("-S", arguments[2]) == 0)
  {
    return AVEC;
  }
  else if (nbArgument == 2)
  {
    return SANS;
  }
  else
  {
    printf("Erreur utilisation du programme!\nVeuillez lire le README pour les instructions: %d\n", errno);
    exit(1);
  }
}
