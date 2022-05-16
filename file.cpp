#include "file.h"

File initialiserFile() {
	File f;
	f.tete = nullptr;
	f.queue = nullptr;
	return f;
}

int sommetFile(File f) {
	if (fileVide(f)) {
		cout << "\nFile Vide\n";
		return -999;
	}
	return f.tete->info;
}

bool fileVide(File f) {return (f.tete == nullptr);}
int tailleFile(File f) { return longueurListe(f.tete); }

void enfiler(File& f, int x) {
	
	Element* p = new Element;
	p->info = x;
	p->suivant = nullptr;

	if (fileVide(f)) f.tete = p;
	else f.queue->suivant = p;

	f.queue = p;
}

int defiler(File& f) {
	if (fileVide(f)) {
		cout << "\nFile Vide\n";
		return -999;
	}
	int x = f.tete->info;
	Element* p = f.tete;
	f.tete = f.tete->suivant;
	delete p;
	return x;
}

void afficherFile(File f) {

	if (fileVide(f)) {
		cout << "\nFile Vide\n";
		return;
	}

	cout << "\nAffichage de la File:\n";
	Element* p = f.tete;

	cout << p->info;
	p = p->suivant;
	while (p != nullptr) {
		cout << " --> " << p->info;
		p = p->suivant;
	}

}

void libererFile(File& f) { libererListe(f.tete); f.queue = nullptr;}

// File de priorite

FilePriorite initialiserFilePriorite() {
	FilePriorite f;
	f.tete = nullptr;
	f.queue = nullptr;
	return f;
}

int sommetFilePriorite(FilePriorite f) {
	if (filePrioriteVide(f)) {
		cout << "\nFile Vide\n";
		return -999;
	}
	return f.tete->info;
}

bool filePrioriteVide(FilePriorite f) { return (f.tete == nullptr); }

void afficherFilePriorite(FilePriorite f) {
	if (filePrioriteVide(f)) {
		cout << "\nFile de Priorite Vide\n";
		return;
	}

	cout << "\nAffichage de la File de Priorite:\n";
	ElementFilePriorite* p = f.tete;

	cout << " (" << p->info << "| " << p->priorite << ")";
	p = p->suivant;
	while (p != nullptr) {
		cout << " --> (" << p->info << "| " << p->priorite << ")";
		p = p->suivant;
	}
}

void enfiler(FilePriorite& f, int x, int priorite) {
	
	ElementFilePriorite* q = new ElementFilePriorite;
	q->info = x;
	q->priorite = priorite;
	q->suivant = nullptr;

	if (filePrioriteVide(f)) { f.tete = q; f.queue = q; }

	else {
		ElementFilePriorite* p = f.tete;
		ElementFilePriorite* prec = nullptr;

		while (p != nullptr && priorite <= p->priorite) {
			prec = p;
			p = p->suivant;
		}

		if (p == f.tete) {
			q->suivant = f.tete;
			f.tete = q;
		}
		else if (p == nullptr) {
			f.queue->suivant = q;
			f.queue = q;
		}
		else {
			q->suivant = p;
			prec->suivant = q;
		}
	}
}

int defiler(FilePriorite& f) {
	if (filePrioriteVide(f)) {
		cout << "\nFile de Priorite Vide\n";
		return -999;
	}
	int x = f.tete->info;
	ElementFilePriorite* p = f.tete;
	f.tete = f.tete->suivant;
	delete p;
	return x;
}

void libererFilePriorite(FilePriorite& f) {
	ElementFilePriorite* p;

	while (f.tete != nullptr) {
		p = f.tete;
		f.tete = f.tete->suivant;
		delete p;
	}

	f.queue = nullptr;
}
