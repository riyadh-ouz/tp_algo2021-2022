#include "pile.h"

Pile initialiserPile() { return nullptr; }
void empiler(Pile& tete, int x) {
	Pile p = new Element;
	p->info = x;
	p->suivant = tete;
	tete = p;
}

int sommetPile(Pile tete) {
	if (pileVide(tete)) {
		cout << "\nPile Vide\n";
		return -999;
	}

	return tete->info;
}

int depiler(Pile& tete) {

	if (pileVide(tete)) {
		cout << "\nPile Vide\n";
		return -999;
	}

	int x = tete->info;
	Pile p = tete;
	tete = tete->suivant;
	delete p;
	return x;
}

bool pileVide(Pile tete) {return (tete == nullptr);}
int taillePile(Pile tete) {return longueurListe(tete);}

void afficherPile(Pile tete) {

	if (pileVide(tete)) {
		cout << "\nPile Vide\n";
		return;
	}

	cout << "\nAffichage de la Pile:\n";

	cout << tete->info;
	tete = tete->suivant;
	while (tete != nullptr) {
		cout << " --> " << tete->info;
		tete = tete->suivant;
	}

}

void libererPile(Pile& tete) {libererListe(tete);}
