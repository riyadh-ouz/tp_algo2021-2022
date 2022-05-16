#pragma once
#include <iostream>
#include <queue>

using namespace std;

struct NoeudAVL {
	NoeudAVL(int x = 0);
	int info;
	int hauteur;
	NoeudAVL* fg;
	NoeudAVL* fd;
};
typedef NoeudAVL* AVL;

int get_hauteur(const AVL& A);
void set_hauteur(AVL& A);

int desequilibre(const AVL& A);
bool est_equilibre(const AVL& A);

AVL rotation_droite(AVL& A);
AVL rotation_gauche(AVL& A);
AVL rotation_GD(AVL& A);
AVL rotation_DG(AVL& A);

AVL reequilibrer(AVL& A);
void inserer_AVL(AVL& A, int x);

//void prefixe_AVL(const AVL& A);
//void infixe_AVL(const AVL& A);
//void postfixe_AVL(const AVL& A);
void parcours_niveau_AVL(const AVL& A);
