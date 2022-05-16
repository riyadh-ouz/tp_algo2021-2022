#pragma once
#include "matrice.h"
#include "liste.h"
#include <cmath>

using namespace std;

int quotient(int a, int b);

int reste(int a, int b);

int interm(int a, int b, int c);

// Problème des reines
int reines(int sol[], int colonne, int n);
void afficherSolution(int sol[], int n);


// Rangements confortables de k objets en n position
int f(int n, int k);

// inversion d'une liste recursivement
Liste inverserListeRecursive(Liste& tete);

// La séquence de Hofstadter
int F(int n);
int M(int n);

// Probleme de Josephus
// Cette fonction attend une liste circulaire
int survivant(Liste& L);

// Problème de l'ile representée par une Matrice de taille M

float f2(int x, int y, int M, int n);
float f2bis(int x, int y, int M, int n);


// test tp recursivité

// exo1
void n_parentheses(char* t, int n, int i = 0, int o = 0, int f = 0);

// exo2
Liste milieu_Rec(Liste tete, Liste m);

bool est_premier_rec(int n, int i = 2);

// exo3
void triInsertionTableau_Rec(int T[], int imin, int imax);
void triPermutationTableau_Rec(int T[], int n, bool trie = false);
