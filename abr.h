#pragma once
#include <iostream>
#include <stack>
#include <queue>

using namespace std;


struct Noeud {
	Noeud(int x = 0);
	int info;
	Noeud* fg;
	Noeud* fd;
};
typedef Noeud* ABR;

bool est_vide(const ABR& A);
bool est_feuille(const ABR& A);
bool est_noeud_interne(const ABR& A);


ABR rechercher_ABR(ABR A, int x);
bool inserer_ABR(ABR& A, int x);

ABR rechercher_ABR_rec(ABR A, int x);
bool inserer_ABR_rec(ABR& A, int x);

ABR supprimer_ABR(ABR& A, int x);
ABR retirer_min_ABR(ABR& A);

void prefixe_ABR(const ABR& A);
void infixe_ABR(const ABR& A);
void postfixe_ABR(const ABR& A);
void parcours_niveau_ABR(const ABR& A);

void prefixe_ABR_iter(const ABR& A);


void liberer_ABR(ABR& A);
int taille_ABR(const ABR& A);

// Verifier si un Arbre est un ABR
bool est_ABR(const ABR& A, int& n);
bool __est_ABR(const ABR& A, int& prcd, int& n);

int max_ABR(const ABR& A, int& n);
int min_ABR(const ABR& A, int& n);
bool est_ABR_bis(const ABR& A, int& n);


// tri d'un tableau par un ABR
void tri_par_ABR(int T[], int premier, int dernier);
void ABR_vers_tableau(ABR A, int T[], int& premier, int dernier);
