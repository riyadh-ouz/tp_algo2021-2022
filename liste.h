#pragma once

#include <iostream>
#include "divers.h"
using namespace std;

struct Element {
	int info;
	Element* suivant;
};

typedef Element* Liste;

Liste tableau_vers_Liste(int* T, int n);
Liste tableau_vers_Liste_recursive(int* T, int n);
Liste remplirListe(int n);
void libererListe(Liste& tete);
void afficherListe(Liste tete);
int longueurListe(Liste tete);
int rechercherListe(int x, Liste tete);
int frequenceListe(int x, Liste tete);
bool estPrefixe(Liste l1, Liste l2);
void fusionnerListe(Liste& l1, Liste l2);

void supprimerElementListe(Liste& tete, int position = 0);
void ajouterElementListe(Liste& tete, int x, int position = 0);

void inverserListe(Liste& tete);

void triSelectionListe(Liste& tete);

bool hasLoop(Liste tete);

// Entre Listes et Tableaux
/*
	Accès arbitraire: tableau O(1), liste O(N)
	Ajout:            tableau O(N), liste O(1)
	Taille:           tableau O(1), liste O(N)***
	Concaténation:    tableau O(N+M), liste O(N) ***
		M est la taille du deuxième tableau
	Filtrage:         tableau O(N*N), liste O(N) ***

	*** Pour la taille d'une liste on peut réduire la compléxité à O(1)
		en modifiant la structure (ajout d'un champs taille) mais cela
		a ses incovénients;
	*** Pour la concaténation des listes on copie chaque élément de A vers B,
		on peut pointer le dernier element de A vers la tète de B, mais cela
		engendre un effet de bord sur la liste A qui serait la CONCAT(A, B);
	*** Pour le filtrage cas du tableau on peut réduire la compléxité en O(N) faisant deux
		parcours pour récupérer la taille de tableau de filtrage, sinon on fait
		un ajout à chaque rencontre (les éléments qui renvoient True), en effet:
		si on trouve k element alors on fait k ajouts donc:
		1 + 2 + 3 + ... + (k-1) = k*k/2 => O(N*N);

*/

// Matrice Creuse

struct ElementMatriceCreuse {
	int i, j, valeur;
	ElementMatriceCreuse* suivant;
};

typedef ElementMatriceCreuse* MatriceCreuse;

MatriceCreuse matrice_vers_liste(int** M, int n); // M : Matrice carree de taille n

void afficherMatriceCreuse(MatriceCreuse tete);
void libererMatriceCreuse(MatriceCreuse& tete);

void ajouterCaseMatriceCreuse(MatriceCreuse& tete, int i, int j, int valeur);
MatriceCreuse sommeDeuxMatriceCreuses(MatriceCreuse l1, MatriceCreuse l2);



// Snake

struct pos {
	int x;
	int y;
	pos* suivant;
};

typedef pos* Snake;

Snake remplirSnake(int n);
void deplacerSnake(Snake& tete, char direction);
void afficherSnake(Snake tete);
void supprimerQueue(Snake tete);
void ajouterTete(Snake& tete, int i, int j);
