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

/*
 * Cree ma structure listeChaine muni d'un mot.
 * premierMot : Le mot a mettre dans Liste_t
 * stats : Pour generer des statistiques
 * Valeur de Retour: Un pointeur vers ce mot.
 */
Liste_t creeMot(char *premierMot, Stats_t stats);

/*
 * Compare deux mots pour savoir leur ordre alphabetique.
 * motCourant : Le mot courant qui est comparer avec le nouveau mot dans la liste.
 * nouveauMot : Le nouveau mot dans la liste.
 * Valeur de retour : TRUE si changement doit etre fait,
 *                    FALSE si aucun changement,
 *                    SAME si c'est le meme mot.
 */
Boolean_t comparaisonMot(char *motCourant, char *nouveauMot);

/*
 * Place le nouveau mot a la place du mot courant.
 * courant : Le mot courant.
 * nouveauMot : Le nouveau mot.
 * Valeur de Retour: Retourne le pointeur vers le nouveau mot.
 */
Liste_t placerLeMot(Liste_t courant, Liste_t nouveauMot);

/*
 * Ajoute un mot dans la liste chaine.
 * liste : Une liste chaine.
 * mot : Un mot a ajouter dans la liste chaine.
 * stats : Statistique a generer.
 * Valeur de retour : Pointeur vers le debut de la liste chaine.
 */
Liste_t ajouterMot(Liste_t liste, char mot[TAILLE_MOT_MAX], Stats_t stats);

/*
 * Calcule la longueur la plus courte entre le mot courant et le nouveau mot.
 * courant : Le mot courant.
 * nouveauMot : Le nouveau mot.
 * Valeur de retour: La longueur le plus court.
 */
int longueur(char *courant, char *nouveauMot);

/*
 * Determine la facon de placer le nouveau mot dans la liste.
 * echanger : TRUE, FALSE ou SAME.
 * stats : Pour generer des statistiques.
 * courant : Le mot courant.
 * nouveauMot : Le nouveau mot.
 * debutListe : Pointeur vers le debut de la liste chaine.
 * Valeur de retour: Pointeur vers le debut de la liste chaine.
 */
Liste_t placementMot(Boolean_t echanger, Stats_t stats, Liste_t courant, Liste_t nouveauMot, Liste_t debutListe);

/*
 * Affiche le resultat du programme, les mot trie alphabetiquement sans doublons.
 * liste : La liste chaine.
 * stats : Les statistiques de la liste.
 * avecStats : Si l'utilisateur le veut avec statistiques.
 * nomDuFichier : Le nom du fichier qui contiendra les statistiques.
 */
void afficherListe(Liste_t liste, Stats_t stats, Option_t avecStats, char *nomDuFichier);


#endif //TP2_LISTECHAINE_H