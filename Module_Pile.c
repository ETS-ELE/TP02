#include "Module_pile.h"

/*                                        DEFINITION                                            */
/************************************************************************************************/

void pile_initialiser(int* pile[], int* nb_elements)
{
    *nb_elements = 0;

    *pile = (int *)calloc(*nb_elements+1, sizeof(int*));
    assert (*pile!=NULL);
}

void pile_detruire(int pile[], int* nb_elements)
{

	*nb_elements = 0;
	free(pile);
	pile = NULL;
}

void pile_initialiser_version_utile(int* pile[], int* nb_elements, int grandeur_pile)
{

	*nb_elements = grandeur_pile;

	*pile = (int *)calloc(*nb_elements, sizeof(int*));

	/*créé le NB de mémoire pour accueillir grandeur_pile NB de bytes
	assigne l'adresse du début de ce bloc de mémoire à l'adresse de pile[0]*/
	assert(*pile != NULL);
}

void pile_copier(int* pile_destination[], int *nb_elements_destination, int pile_source[], int nb_elements_source)
{

	int d = *nb_elements_destination - 1;
	int i = nb_elements_source - 1;

	//Utilisation de memcpy à la place
	for (; (i >= 0) && (d >= 0); i--)
	{
		*(*pile_destination + d) = *(pile_source + i);
		d--;
	}
}

void pile_ajouter(int* pile[], int* nb_elements, int entier)
{

	//Initialisation des variables temporaire
	int nb_ele_temp;
	int* pile_temp = NULL;

	//Allocation de la memoire temporaire
	pile_initialiser_version_utile(&pile_temp, &nb_ele_temp, *nb_elements + 1); //On veut un tableau une case plus grande

	//Verification si le pointeur est en erreur
	//assert((pile_temp) != NULL);

	pile_copier(&pile_temp, &nb_ele_temp, *pile, *nb_elements);
	*pile_temp = entier; //assigne l'entier à la position 0 de la nouvelle pile

	free(*pile);               //Libération de la première pile
	*pile = pile_temp;         //assignation de la nouvelle pile
	(*nb_elements)++;
}

int pile_enlever(int* pile[], int* nb_elements)
{
	//sauvegarde l'entier qui sera enlevé
	int entier_enleve = **pile;

	//Initialisation des variables temporaire
	int nb_ele_temp;
	int* pile_temp = NULL;

	//Allocation de la memoire temporaire
	pile_initialiser_version_utile(&pile_temp, &nb_ele_temp, *nb_elements - 1); //On veut un tableau une case plus petite

	//Verification si le pointeur est en erreur
	//assert((pile_temp) != NULL);

	pile_copier(&pile_temp, &nb_ele_temp, *pile, *nb_elements);

	free(*pile);               //Libération de la première pile
	*pile = pile_temp;           //assignation de la nouvelle pile
	(*nb_elements)--;

	return entier_enleve;
}

void pile_afficher(int pile[], int nb_elements)
{
	//Affiche tous les éléments de la pile
	int i;

	for (i = 0; i < nb_elements; i++)
	{
		printf("Deplacement #%d : %d\n", i, pile[i]);
	}
}

void pile_tronquer(int * pile[], int* nb_elements, int indice)
{
	//Initialisation des variables temporaire
	int nb_ele_temp;
	int* pile_temp = NULL;

	//Allocation de la memoire temporaire
	pile_initialiser_version_utile(&pile_temp, &nb_ele_temp, indice+1); //On veut un tableau de grosseur indice+1

	//Verification si le pointeur est en erreur
	//assert((pile_temp) != NULL);

	pile_copier(&pile_temp, &nb_ele_temp, *pile, *nb_elements);

	free(*pile);               //Libération de la première pile
	*pile = pile_temp;           //assignation de la nouvelle pile
	(*nb_elements) = indice+1;

	//il est important de noter que cette fonction enleve la fin (le dessus) de notre pile, 
	//mais comme le dessus de notre pile est a l'indice 0, elle tronque a partir de l'element 0
	//afin qu'il RESTE (indice+1) element dans la pile
}

int pile_est_present(int pile[], int nb_elements, int entier)
{
	int x = 0;

	for (x = 0; x < nb_elements; x++)
	{
		if (pile[x] == entier)  
		{ 
			return x; 
		}
	}
	return -1;
}

void pile_concatener(int* pile_destination[], int* nb_elements_destination, int pile_source[], int nb_elements_source)
{

	//Initialisation des variables temporaire
	int nb_ele_temp;
	int* pile_temp = NULL;

	//Allocation de la memoire temporaire
	//On veut un tableau qui aura la grandeur des 2 tableaux réunis
	pile_initialiser_version_utile(&pile_temp, &nb_ele_temp, *nb_elements_destination + nb_elements_source); 

	//Verification si le pointeur est en erreur
	//assert((pile_temp) != NULL);
	
	//le dernier element (0) de pile_source sera sur le dessus de la nouvelle pile (0)
	pile_copier(&pile_temp, &nb_ele_temp, *pile_destination, *nb_elements_destination);

	pile_temp -= *nb_elements_destination; //some fucked up arithmetic, was on acid.
	pile_copier(&pile_temp, &nb_ele_temp, pile_source, nb_elements_source);
	pile_temp += *nb_elements_destination;
	
	free(pile_source);					  //Libération de la pile source
	free(*pile_destination);			  //Libération de la pile source

	*pile_destination = pile_temp;         //assignation de la nouvelle pile
	*nb_elements_destination = *nb_elements_destination + nb_elements_source;
}
