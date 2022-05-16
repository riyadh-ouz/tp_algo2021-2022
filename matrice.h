#pragma once

#include <iostream>
#include "divers.h"

using namespace std;

void lireTailleMatrice(int& n, int& m);
void afficherMatrice(int** M, int n, int m);
void remplirMatrice(int** M, int n, int m);

int** reserverMatrice(int n, int m);
void libererMatrice(int** M, int n);

bool rechercherMatrice(int x, int** M, int m, int n, int& i, int& j);
int frequenceMatrice(int x, int** M, int n, int m);

int** multiplicationMatrice(int** M1, int** M2, int n, int l, int m);
int sommeMatrice(int** M, int n, int m);
bool egales(int** A, int** B, int n, int m);

int** insererLigne(int** M, int n, int m, int position);
int** insererColonne(int** M, int n, int m, int position);
int** supprimerLigne(int** M, int n, int m, int position);
int** supprimerColonne(int** M, int n, int m, int position);

void remplirCarreMagique(int** M, int n); // n est impair
