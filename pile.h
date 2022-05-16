#pragma once

#include <iostream>
#include "divers.h"
#include "liste.h"
using namespace std;

typedef Element* Pile;

Pile initialiserPile();

void empiler(Pile& tete, int x);
int depiler(Pile& tete);
void libererPile(Pile& tete);

int sommetPile(Pile tete);
bool pileVide(Pile tete);

void afficherPile(Pile tete);
int taillePile(Pile tete);
