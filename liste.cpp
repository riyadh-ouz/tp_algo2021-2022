#include "liste.h"

Liste tableau_vers_Liste(int* T, int n) {

	if (n <= 0) return nullptr;

	Liste tete = new Element;
	if (tete == nullptr) return nullptr;

	tete->info = T[0];

	Liste p = tete;

	for (int i = 1; i < n; i++) {
		
		p->suivant = new Element;
		if (p->suivant == nullptr) return nullptr;
		p = p->suivant;
		
		p->info = T[i];
	}

	p->suivant = nullptr;

	return tete;

}

Liste tableau_vers_Liste_recursive(int* T, int n) {
	if (n == 1) {
		Liste L = new Element;
		L->info = T[0];
		L->suivant = nullptr;
		return L;
	}

	Liste L = new Element;
	L->info = T[n-1];
	L->suivant = tableau_vers_Liste_recursive(T,n-1);
	return L;
}

Liste remplirListe(int n) {

	if (n <= 0) return nullptr;

	Liste tete = new Element;
	if (tete == nullptr) return nullptr;

	cout << "\nEntrez les valeurs de la liste un par un:\n";

	cin >> (tete->info);

	Liste p = tete;

	for (int i = 1; i < n; i++) {

		p->suivant = new Element;
		if (p->suivant == nullptr) return nullptr;
		p = p->suivant;

		cin >> (p->info);
	}

	p->suivant = nullptr;

	return tete;

}

void afficherListe(Liste tete) {

	if (tete == nullptr) {
		cout << "\nListe Vide\n";
		return;
	}

	cout << "\nAffichage de la Liste:\n";

	cout << tete->info;
	tete = tete->suivant;
	while (tete != nullptr) {
		cout << " --> " << tete->info;
		tete = tete->suivant;
	}

}

int longueurListe(Liste tete) {
	
	if (tete == nullptr) return 0;

	int n = 0;
	Liste p = tete;
	do {
		n++;
		p = p->suivant;
	} while (p != nullptr);

	return n;
}

int rechercherListe(int x, Liste tete) {
	
	if (tete == nullptr) return -1;

	Liste p = tete;
	int i = 1;

	while (p != nullptr && p->info != x) {
		p = p->suivant;
		i++;
	}

	if (p == nullptr) return -1;
	return i;
}

int frequenceListe(int x, Liste tete) {

	Liste p = tete;
	int n = 0;

	while (p != nullptr) {
		if (p->info == x) n++;
		p = p->suivant;
	}

	return n;
}

bool estPrefixe(Liste l1, Liste l2) {

	if (l2 == nullptr) return true;

	if (l1 == nullptr && l2 != nullptr) return false;
	
	return (l1->info == l2->info) && estPrefixe(l1->suivant, l2->suivant);

}

void libererListe(Liste& tete) {
	Liste p;

	while (tete != nullptr) {
		p = tete;
		tete = tete->suivant;
		delete p;
	}
}

void fusionnerListe(Liste& l1, Liste l2) {

	if (l1 == nullptr) {
		l1 = l2;
		return;
	}
	
	Liste p = l1;

	while (p->suivant != nullptr) p = p->suivant;

	p->suivant = l2;
}

void inverserListe(Liste& tete) {

	if (tete == nullptr) return;
	
	Liste prec = nullptr;
	Liste cour = tete;
	Liste suiv = tete->suivant;

	while (suiv != nullptr) {
		cour->suivant = prec;

		prec = cour;
		cour = suiv;
		suiv = suiv->suivant;

	}
	cour->suivant = prec;
	tete = cour;
}

void supprimerElementListe(Liste& tete, int position) {
	if (position < 0) cout << "Erreur de position";
	else if (position == 0) {
		Liste p;
		p = tete;
		tete = tete->suivant;
		delete p;
	}
	else {
		// On compte de 0
		int i = 1;
		Liste prcd = tete,
			p = tete->suivant;

		while (p != nullptr && i < position) {
			prcd = p;
			p = p->suivant;
			i++;
		}
		if (p != nullptr) {
			prcd->suivant = p->suivant;
			delete p;
		}
		else cout << "Erreur de position";
	}
}

void ajouterElementListe(Liste& tete, int x, int position) {
	if (position < 0) cout << "Erreur de position";
	else if (position == 0) {
		Liste p = new Element;
		p->info = x;
		p->suivant = tete;
		tete = p;
	}
	else {
		// On compte de 0
		int i = 1;
		Liste prcd = tete;
		while (prcd != nullptr && i < position - 1) {
			prcd = prcd->suivant;
			i++;
		}
		if (prcd == nullptr) cout << "Erreur de position";
		else
		{
			Liste p = new Element;
			p->info = x;
			p->suivant = prcd->suivant;
			prcd->suivant = p;
		}
	}
}

bool hasLoop(Liste tete) {

	if (tete == nullptr) return false;
	if (tete->suivant == nullptr) return false;

	Liste p1 = tete, p2 = tete->suivant;

	while (p1 != nullptr && p2->suivant != nullptr) {
		if (p1 == p2) return true;
		p1 = p1->suivant;
		p2 = p2->suivant->suivant;
		if (p2 == nullptr) return false;
	}
	return false;
}

// Les tris

void triSelectionListe(Liste& tete) {
	int x;
	Liste p, t, pmin;

	for (p = tete; p->suivant != nullptr; p = p->suivant) {
		pmin = p;

		for (t = p->suivant; t != nullptr; t = t->suivant)
			if (t->info < pmin->info) pmin = t;
		permuter<int>(pmin->info, p->info);
		
	}
}


// Matrice Creuse

MatriceCreuse matrice_vers_liste(int** M, int n) {
	
	if (n <= 0) return nullptr;

	MatriceCreuse tete = new ElementMatriceCreuse;
	MatriceCreuse p = tete;

	bool tete_passee = false;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (M[i][j] != 0) {

				if (!tete_passee) {
					
					p->valeur = M[i][j];
					p->i = i;
					p->j = j;
					tete_passee = true;
					continue;
				}

				p->suivant = new ElementMatriceCreuse;
				if (p->suivant == nullptr) return nullptr;
				p = p->suivant;

				p->valeur = M[i][j];
				p->i = i;
				p->j = j;
				
			}

	p->suivant = nullptr;

	return tete;
}

void afficherMatriceCreuse(MatriceCreuse tete) {
	
	if (tete == nullptr) {
		cout << "\nMatrice Creuse Vide\n";
		return;
	}

	cout << "\nAffichage de la Matrice Creuse:\n";

	do {
		cout << "M[" << tete->i << "][" << tete->j << "] = " << tete->valeur << "\n";
		tete = tete->suivant;

	} while (tete != nullptr);

}

void libererMatriceCreuse(MatriceCreuse& tete) {
	MatriceCreuse p;

	while (tete != nullptr) {
		p = tete;
		tete = tete->suivant;
		delete p;
	}
}

void ajouterCaseMatriceCreuse(MatriceCreuse& tete, int i, int j, int valeur) {
	
	if (tete == nullptr) {
		tete = new ElementMatriceCreuse;
		tete->i = i;
		tete->j = j;
		tete->valeur = valeur;
		tete->suivant = nullptr;
		return;
	}

	MatriceCreuse p, prec;
	
	p = tete;
	prec = p;

	while (p->i < i) {
		prec = p;
		p = p->suivant;
		if (p == nullptr) break;
	}
	if (p != nullptr)
		while (p->i == i && p->j < j) {
			prec = p;
			p = p->suivant;
			if (p == nullptr) break;
		}

	if (p != nullptr)
		if (p->i == i && p->j == j) p->valeur = valeur;
		else {
			MatriceCreuse nouveau = new ElementMatriceCreuse;
			nouveau->i = i;
			nouveau->j = j;
			nouveau->valeur = valeur;
			nouveau->suivant = p;
			prec->suivant = nouveau;
		}
	else {
		MatriceCreuse nouveau = new ElementMatriceCreuse;
		nouveau->i = i;
		nouveau->j = j;
		nouveau->valeur = valeur;
		nouveau->suivant = nullptr;
		prec->suivant = nouveau;
	}
}

MatriceCreuse sommeDeuxMatriceCreuses(MatriceCreuse l1, MatriceCreuse l2) {
	
	MatriceCreuse res = nullptr;

	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->i < l2->i) {
			ajouterCaseMatriceCreuse(res, l1->i, l1->j, l1->valeur);
			l1 = l1->suivant;
		}

		else if (l1->i > l2->i) {
			ajouterCaseMatriceCreuse(res, l2->i, l2->j, l2->valeur);
			l2 = l2->suivant;
		}

		else {
			
			if (l1->j == l2->j) {
				if (l1->valeur + l2->valeur != 0)
					ajouterCaseMatriceCreuse(res, l1->i, l1->j, l1->valeur + l2->valeur);

				l2 = l2->suivant;
				l1 = l1->suivant;
			}
			
			else if (l1->j < l2->j) {
				ajouterCaseMatriceCreuse(res, l1->i, l1->j, l1->valeur);
				l1 = l1->suivant;
			}

			else {
				ajouterCaseMatriceCreuse(res, l2->i, l2->j, l2->valeur);
				l2 = l2->suivant;
			}

		}
	}

	while (l1 != nullptr) {
		ajouterCaseMatriceCreuse(res, l1->i, l1->j, l1->valeur);
		l1 = l1->suivant;
	}

	while (l2 != nullptr) {
		ajouterCaseMatriceCreuse(res, l2->i, l2->j, l2->valeur);
		l2 = l2->suivant;
	}

	return res;
};


// Snake

void deplacerSnake(Snake& tete, char direction) {
	int x1 = tete->x, x2 = tete->suivant->x,
		y1 = tete->y, y2 = tete->suivant->y;

	int i = 0,
		j = 0;

	if (x1 == x2) {
		if (y1 < y2) {
			switch (direction)
			{
			case 's':
				cout << "Impossible\n";
				break;
			case 'e':
				i = x1 + 1;
				j = y1;
				break;
			case 'n':
				i = x1;
				j = y1 - 1;
				break;
			case 'o':
				i = x1 - 1;
				j = y1;
				break;
			default:
				break;
			}
		}
		else {
			switch (direction)
			{
			case 'n':
				cout << "Impossible\n";
				break;
			case 's':
				i = x1;
				j = y1 + 1;
				break;
			case 'e':
				i = x1 + 1;
				j = y1;
				break;
			case 'o':
				i = x1 - 1;
				j = y1;
				break;
			default:
				break;
			}
		}
	}

	else {
		if (x1 < x2) {
			switch (direction)
			{
			case 'e':
				cout << "Impossible\n";
				break;
			case 'o':
				i = x1 - 1;
				j = y1;
				break;
			case 'n':
				i = x1;
				j = y1 - 1;
				break;
			case 's':
				i = x1;
				j = y1 + 1;
				break;
			default:
				break;
			}
		}
		else {
			switch (direction)
			{
			case 'o':
				cout << "Impossible\n";
				break;
			case 's':
				i = x1;
				j = y1 + 1;
				break;
			case 'n':
				i = x1;
				j = y1 - 1;
				break;
			case 'e':
				i = x1 + 1;
				j = y1;
				break;
			default:
				break;
			}
		}
	}
	
	if (i < 0) i = 9;
	if (i > 9) i = 0;
	if (j < 0) j = 9;
	if (j > 9) j = 0;

	supprimerQueue(tete);
	ajouterTete(tete, i, j);

}

void supprimerQueue(Snake tete) {
	Snake p = tete, q = tete;

	while (p->suivant != nullptr) {
		q = p;
		p = p->suivant;
	}
	q->suivant = nullptr;
	delete p;
	

}

void ajouterTete(Snake& tete, int i, int j) {
	Snake n = new pos;

	n->x = i;
	n->y = j;
	n->suivant = tete;
	tete = n;
}

Snake remplirSnake(int n) {

	if (n < 2 || n > 9) return nullptr;

	Snake tete = new pos;

	cout << "\nEnter the Snake: x then y element by element\n";

	cin >> (tete->x);
	cin >> (tete->y);

	Snake p = tete;

	for (int i = 1; i < n; i++) {

		p->suivant = new pos;
		p = p->suivant;

		cin >> (p->x);
		cin >> (p->y);
	}

	p->suivant = nullptr;

	return tete;

}

void afficherSnake(Snake tete) {
	cout << "\n";
	while (tete != nullptr) {
		cout << "-->(" << tete->x << " | " << tete->y << ")";
		tete = tete->suivant;
	}

}
