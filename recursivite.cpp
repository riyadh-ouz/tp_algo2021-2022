#include "recursivite.h"

int quotient(int a, int b) {
	if (b == 0) return -1;
	if (a >= b) return 1 + quotient(a - b, b);
	return 0;
}

int reste(int a, int b) {
	if (a >= b) return reste(a - b, b);
	return a;
}

// b est encadré par a et c ssi a <= b et b <= c ou l'inverse
int interm(int a, int b, int c) {
	if ((a <= b && b <= c) || (a >= b && b >= c)) return b;
	return interm(c, a, b);
}

// Problème des reines
int reines(int sol[], int colonne, int n) {
	if (colonne == n) {
		afficherSolution(sol, n);
		return 1;
	}

	int nbr = 0;
	for (int i = 0; i < n; i++) { // pour chaque ligne
		bool possible = true;
		int j = 0;
		while (possible && j < colonne) {
			// dans la position (sol[j], j) il y a une reine
			if (i == sol[j] || abs(i - sol[j]) == colonne - j) // test horizontal + diagonal
				possible = false;
			j++;
		}
		if (possible) {
			sol[colonne] = i;
			nbr += reines(sol, colonne + 1, n);
		}
	}
	return nbr;
}

void afficherSolution(int sol[], int n) {
	int** M = reserverMatrice(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
	for (int i = 0; i < n; i++) M[sol[i]][i] = 1;
	afficherMatrice(M, n, n);
	libererMatrice(M, n);
}

// Rangements confortables
int f(int n, int k) {
	if (k == 0) return 1;
	if (n < k) return 0;
	return f(n - 1, k) + f(n - 2, k - 1);
}

// inversion d'une Liste recursivement
Liste inverserListeRecursive(Liste& tete) {
	if (tete == nullptr) return nullptr;
	if (tete->suivant == nullptr) return tete;
	
	Liste L = inverserListeRecursive(tete->suivant);
	tete->suivant = nullptr;
	Liste p = L;
	while (p->suivant != nullptr) p = p->suivant;
	p->suivant = tete;
	return L;
}

// La séquence de Hofstadter
int F(int n) {
	if (n == 0) return 1;
	return n - M(F(n - 1));
}
int M(int n) {
	if (n == 0) return 0;
	return n - F(M(n - 1));
}

// Probleme de Josephus
// Cette fonction attend une liste circulaire
int survivant(Liste& L) {

	if (L == L->suivant) return L->info;

	L->suivant = L->suivant->suivant;

	return survivant(L->suivant);
}


// Probleme de l'ile

float f2(int x, int y, int M, int n) {
	if (x < 1 || x > M || y < 1 || y > M) return 0;
	if (n == 0) return 1;
	return (f2(x + 1, y, M, n - 1) +
		f2(x - 1, y, M, n - 1) +
		f2(x, y + 1, M, n - 1) + f2(x, y - 1, M, n - 1)) / 4;
}

float f2bis(int x, int y, int M, int n) {
	if (x < 1 || x > M || y < 1 || y > M) return 0;
	if (n == 0) return 1;
	return 3*f2(x + 1, y, M, n - 1)/8 +
		f2(x - 1, y, M, n - 1)/8 +
		f2(x, y + 1, M, n - 1)/8 + 3*f2(x, y - 1, M, n - 1)/8;
}


// test tp recursivité

//exo1
void n_parentheses(char* t, int n, int i, int o, int f) {

	if (n % 2 == 1) return;
	
	if (o < f || o > n / 2) return; 
	
	if (i >= n) {
		for (int j = 0; j < n; j++) cout << t[j];
		cout << "\n";
		return;
	}
	
	t[i] = '('; n_parentheses(t, n, i + 1, o + 1, f);
	t[i] = ')'; n_parentheses(t, n, i + 1, o, f + 1);
}

//exo2
Liste milieu_Rec(Liste tete, Liste m) {
	if (tete == nullptr || tete->suivant == nullptr) return m;
	return milieu_Rec(tete->suivant->suivant, m->suivant);
}


bool est_premier_rec(int n, int i) {
	if (n == i) return true;
	if (n % i == 0) return false;
	return est_premier_rec(n, i + 1);
}

//exo3

void triInsertionTableau_Rec(int T[], int imin, int imax) {

	if (imin > imax) return;
	
	int tmp, i = imin - 1;

	tmp = T[imin];

	while (i >= 0 && T[i] > tmp) {
		T[i + 1] = T[i];
		i--;
	}
	T[i + 1] = tmp;

	triInsertionTableau_Rec(T, imin + 1, imax);
}


void triPermutationTableau_Rec(int T[], int n, bool trie) {
	if (trie) return;
	
	bool trie1 = true;
	for (int j = 0; j < n - 1; j++)
		if (T[j] > T[j + 1]) { 
			permuter<int>(T[j], T[j + 1]);
			trie1 = false;
		}

	triPermutationTableau_Rec(T, n - 1, trie1);
}
