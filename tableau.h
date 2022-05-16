#pragma once

#include <iostream>
#include "divers.h"
using namespace std;

// fonctions de base
void lireTaille(int& taille);
void lireIminImax(int& imin, int& imax, int taille);
void remplirTableau(int T[], int n);
void afficherTableau(int T[], int n);

// la somme des elements d'un tableau
int sommeTableau(int T[], int imin, int imax);

// fonctions de recherche
// ces fonctions retourne l'indice de l'element, -1 sinon
int rechercherTableau(int x, int T[], int imin, int imax);

// cette fonction attend un tableau trie
int dichotomieTableau(int x, int T[], int imin, int imax);


// suppression d'un element x, et decalage vers la gauche
// retourne true cas de la supression, false si l'element n'existe pas
bool supprimerTableau(int x, int T[], int n);


// cette fonction retourne l'occurence d'un element dans un tableau
// entre deux indices
int frequenceTableau(int x, int T[], int imin, int imax);


// tri d'un tableau
void tri_selection(int T[], int premier, int dernier);
void tri_insertion(int T[], int premier, int dernier);
void tri_shell(int T[], int premier, int dernier);

// tri fusion
void fusion(int T[], int premier, int milieu, int dernier);
void tri_fusion_tableau(int T[], int premier, int dernier);

// tri rapide
int partitionner(int T[], int premier, int dernier);
void tri_rapide(int T[], int premier, int dernier);

int nbrCombinaisons(int T[], int taille, int somme);

int sommeMaximale(int T[], int n, int& debut, int& fin);

void permutations(int T[], int n, int debut, int& nbr);

// n est supposé impair
int medianeTableauNonTrie(int T[], int n);
