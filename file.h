#pragma once

#include <iostream>
#include "divers.h"
#include "liste.h"
using namespace std;

struct File {
	Element* tete;
	Element* queue;
};

File initialiserFile();

int sommetFile(File f);
bool fileVide(File f);
void afficherFile(File f);
int tailleFile(File f);

void enfiler(File& f, int x);
int defiler(File& f);
void libererFile(File& f);

// File de priorité

struct ElementFilePriorite {
	int info;
	int priorite;
	ElementFilePriorite* suivant;
};

struct FilePriorite {
	ElementFilePriorite* tete;
	ElementFilePriorite* queue;
};

FilePriorite initialiserFilePriorite();
int sommetFilePriorite(FilePriorite f);
bool filePrioriteVide(FilePriorite f);
void afficherFilePriorite(FilePriorite f);
void enfiler(FilePriorite& f, int x, int priorite);
int defiler(FilePriorite& f);

void libererFilePriorite(FilePriorite& f);
