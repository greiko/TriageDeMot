/*
* Created by Nicolas Papanicolaou on 7/12/15.
* Code Permanent: PAPN20098909
* がっきプロジェクト2(Projet de Session 2)
* Triage de mot, en enlevant les doublons et qui peut generer des statistiques.
*
*/

#ifndef TP2_GESTIONSTATISTIQUE_H
#define TP2_GESTIONSTATISTIQUE_H
#include <stdio.h>
#include <stdlib.h>


typedef struct statistique *Stats_t;

/*
 * Initialisation d'une structure statistique.
 * Valeur de retour: Pointeur sur un structure statistique avec de la memoire alloue.
 */
Stats_t initialisationStats(Stats_t stats);

/*
 * Initiation d'un tableau de integer a 0.
 * Valeur de retour: Le tableau iniatilise.
 */
int *initialisationTableauLettre();

/*
 * Compte le nombre de lettre dans le mot pour l'ajouter dans les statistiques.
 * stats: Les statistiques.
 * mot: Le mot utilise.
 */
void compteurLettre(Stats_t stats, char *mot);

/*
 * Compte le mot sans doublons et prend des donnees sur le mot.
 * stats: Les statistiques.
 * mot: Le mot utilise.
 */
void compteurMotSansDoublons(Stats_t stats, char *mot);

/*
 * Compte tout les mots, dans le fichier statistique, on le nomme:
 * le nombre de mots avec les doublons.
 * stats: Les statistiques.
 */
void compteurMotTotal(Stats_t stats);

/*
 * Compte le nombre de ligne dans le fichier entrant.
 * stats: Les statistiques.
 * combien: Combien de ligne a ajouter.
 */
void compteurLignes(Stats_t stats);

/*
 * Calcul les frequences de les lettres dans le fichier.
 * stats: Les statistiques.
 * lettre: Lettre se trouvant dans le mot.
 */
void frequenceLettre(Stats_t stats, char lettre);

/*
 * Retourne la lettre la plus frequente.
 * stats: Les statistiques.
 * Valeur de retour: La lettre la plus frequente.
 */
char laLettreFrequente(Stats_t stats);

/*
 * Inscris dans le fichier les statistiques rassembler pendant le programme.
 * stats: Les statistiques.
 * nomDuFichier: Le nom du fichier de statistiques.
 */
void afficherStats(Stats_t stats, char *nomDuFichier);

/*
 * Validation lors de l'ouverture du fichier de statistiques.
 * fichier: Le pointeur vers le fichier.
 * nomDuFichier: Le path du fichier de statistiques.
 * Valeur de retour:
 */
FILE *validationFichierSortie(FILE *fichier, char *nomDuFichier);

#endif //TP2_GESTIONSTATISTIQUE_H
