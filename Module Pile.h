/************************************************************************************************/
//Projet   : Projet TP_2_Labyrinthe
//Fichier  : Module_Pile.c
//Contenu  : Contient les fonction relatif à la création, modification et destruction de pile
//Objectif : Création d'un algorithme de réalisation de labyrinthe
//Création : 20 Octobre 2014
//                                                  Creer par Samuel - Link - Geoffroy-Heroux
//                                                            Francis Masse
//                                                            Christopher Dom
//                                                            Vincent Lynch
//
/************************************************************************************************/

/*                                          DEFINE                                              */
/************************************************************************************************/
#ifndef MOD_PILE
#define MOD_PILE
/************************************************************************************************/

/*                                         INCLUDES                                             */
/************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include <string.h>
//#include <memory.h>
/************************************************************************************************/

/*                                        DECLARATION                                           */
/************************************************************************************************/

void pile_initialiser(int* pile[], int* nb_elements);
/*
Cette fonction sert a initialiser une pile et sont nb_elements à NULL.
Parametre : int* pile[]         --> Pointeur sur tableau (qui est notre pile)
int* nb_elements    --> Pointeur sur le nombre d'éléments de la pile
Return : Void
*/
/************************************************************************************************/


void pile_detruire(int pile[], int* nb_elements);
/*
Cette fonction sert a detruire une pile et de remettre son adresse à NULL et le nombre d'éléments à 0.
Parametre : int pile[]         --> Tableau (qui est notre pile)
int* nb_elements    --> Pointeur sur le nombre d'éléments de la pile
Return : Void
*/
/************************************************************************************************/

void pile_initialiser_version_utile(int* pile[], int* nb_elements, int grandeur_pile);
/*
Cette fonction sert a initialiser une pile à un grandeur prédéterminée.
Parametre : int* pile[]         --> Pointeur sur tableau (qui est notre pile)
int* nb_elements    --> Pointeur sur le nombre d'éléments de la pile
int grandeur_pile    --> grandeur désirée de la pile (i.e. valeur qu'aura le NB d'élément)
Return : Void
*/
/************************************************************************************************/

void pile_copier(int* pile_destination[], int *nb_elements_destination, int pile_source[], int nb_elements_source);
/*
Cette fonction sert a copier une pile dans un autre.

Parametre : int* pile_destination[]      --> Pointeur vers notre pile de destination
int *nb_elements_destination     --> pointeur vers le nombre d'éléments de la pile de destination
int pile_source                --> tableau (pile) à copier dans la nouvelle pile
int nb_element_source           --> Nombre d'éléments de la pile de source
Return : Void
*/
/************************************************************************************************/

void pile_ajouter(int* pile[], int* nb_elements, int entier);
/*
Cette fonction sert a ajouter un element à une pile.
Parametre : int* pile[]         --> Pointeur sur tableau (qui est notre pile)
int* nb_elements    --> Pointeur sur le nombre d'éléments de la pile
int entier          --> L'entier à ajouter sur le dessus de la pile
Return : Void
*/
/************************************************************************************************/

int pile_enlever(int* pile[], int *nb_elements);
/*
Cette fonction sert a enlever le dernier élément d'une pile.
Parametre : int* pile[]         --> Pointeur sur tableau (qui est notre pile)
int* nb_elements    --> Pointeur sur le nombre d'éléments de la pile
Return : l'entier qui à été enlever
*/

/************************************************************************************************/

void pile_afficher(int pile[], int nb_elements);
/*
Cette fonction sert a afficher tous les éléments d'une pile.
Parametre : int* pile[]         --> Pointeur sur tableau (qui est notre pile)
            int nb_elements     --> Nombre d'éléments de la pile
Return : Void
*/

/************************************************************************************************/

void pile_tronquer(int * pile[], int* nb_elements, int indice);
/*
Cette fonction permet a l'utlisateur d'effacer le contenue d'une pille ce trouvant apres une certaine 
position dans la pille. De plus, la grosseur de la pille sera ajuste automatique au nombre exact de
donnee restaint.
Parametre : *pile[] --> addresse du pointeur pointant sur la première case du tableau.
			*nb_elements --> Nombre d'élément contenus dans la pile pointée par "*pile[]".
			indice --> Representation numérique de la position a la qu'elle la pille doit être coupée.
Return : void
*/

/************************************************************************************************/

int pile_est_present(int pile[], int nb_elements, int entier);
/*
Cette fonction permet de trouver la position d'un entier dans une pile, si cette entier n'est pas
présent dans la pile, "-1" sera retourné par la fonction.
Parametre : pile[]  -->  Addresse du premier élément du tableau.
			nb_elements  -->  Nombre d'élément contenue dans le tableau.
			entier  -->  Nombre pour lequelle le programme cherchera ça position dans la pile.
Return : int  -->  Retourne "-1" si l'entier demendé en paramêtre n'est pas présent dans la pile.
				   Si l'entier est présent, ça position sera retournée par la fonction.
*/


/************************************************************************************************/

void pile_concatener(int* pile_destination[], int* nb_elements_destination, int pile_source[], int nb_elements_source);
/*
Cette fonction permet de prendre deux piles "A" et "B" et de les mettre bout-à-bout pour créé une nouvelle
pille "AB". La grosseur de la nouvelle pille sera ajusté dynamiquement.
Parametre : *pile_destination[]  --> Pointeur pointant vers la pille ou les deux pille ce retrouveront.
			*nb_elements_destination  --> Nombre d'élément dans la pille "A".
			pile_source[]  --> Addresse de la pille qui sera fusionnée à la pille "A".
			nb_elements_source  --> Nombre d'élément de la pille "B".
Return : void
*/

/************************************************************************************************/
#endif
