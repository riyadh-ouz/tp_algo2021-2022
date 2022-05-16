#include "matrice.h"


void lireTailleMatrice(int& n, int& m) {
	do {
		cout << "Entrez n: "; cin >> n;
		if (n <= 0) cout << "!!! n doit etre > 0 !!!\n";
	} while (n <= 0);

	do {
		cout << "Entrez m: "; cin >> m;
		if (m <= 0) cout << "!!! m doit etre > 0 !!!\n";
	} while (m <= 0);
}

void afficherMatrice(int** M, int n, int m) {
	if (M == NULL) {
		cout << "\nM = NULL, Memoire non initialisee pour la matrice\n";
		return;
	}

	cout << "\nAffichage\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << M[i][j] << " ";
		cout << "\n";
	}
}

void remplirMatrice(int** M, int n, int m) {
	if (M == NULL) {
		cout << "\nM = NULL, Memoire non initialisee pour la matrice\n";
		return;
	}
	cout << "\nEntrez les valeurs de la matrice un par un:\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << "M[" << i << "][" << j << "] = "; cin >> M[i][j];
		}
}

int** reserverMatrice(int n, int m) {
	int** M = new int* [n];
	for (int i = 0; i < n; i++) M[i] = new int[m];
	return M;
}

void libererMatrice(int** M, int n) {
	for (int i = 0; i < n; i++) delete[] M[i];
	delete[] M;
}


bool rechercherMatrice(int x, int** M, int m, int n, int& i, int& j) {

	for (int k = 0; k < n; k++)
		for (int l = 0; l < m; l++)
			if (M[k][l] == x) {
				i = k;
				j = l;
				return true;
			}
	return false;

}

int frequenceMatrice(int x, int** M, int n, int m) {
	int freq = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (M[i][j] == x) freq++;
	return freq;
}


int** multiplicationMatrice(int** M1, int** M2, int n, int l, int m) {
	int** M = reserverMatrice(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			M[i][j] = 0;
			for (int k = 0; k < l; k++) M[i][j] += M1[i][k] * M2[k][j];
		}

	return M;
}


int** insererLigne(int** M, int n, int m, int position) {

	if (position > n - 1 || position < -1) return nullptr;

	int** res = reserverMatrice(n + 1, m);

	for (int i = 0; i <= position; i++)
		for (int j = 0; j < m; j++) res[i][j] = M[i][j];

	for (int j = 0; j < m; j++) res[position + 1][j] = rand() % 100;

	for (int i = position + 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res[i + 1][j] = M[i][j];
		}
	}
	return res;
}
int** insererColonne(int** M, int n, int m, int position) {

	if (position > m - 1 || position < -1) return nullptr;

	int** res = reserverMatrice(n, m + 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= position; j++) res[i][j] = M[i][j];

	for (int i = 0; i < n; i++) res[i][position + 1] = rand() % 100;

	for (int i = 0; i < n; i++) {
		for (int j = position + 1; j < m; j++) {
			res[i][j + 1] = M[i][j];
		}
	}

	return res;

}

int** supprimerLigne(int** M, int n, int m, int position) {

	if (position > n - 1 || position < 0) return nullptr;

	int** res = reserverMatrice(n - 1, m);

	for (int i = 0; i <= position; i++)
		for (int j = 0; j < m; j++) res[i][j] = M[i][j];

	for (int i = position + 2; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res[i - 1][j] = M[i][j];
		}
	}

	return res;
}
int** supprimerColonne(int** M, int n, int m, int position) {

	if (position > m - 1 || position < 0) return nullptr;

	int** res = reserverMatrice(n, m - 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= position; j++) res[i][j] = M[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = position + 2; j < m; j++) {
			res[i][j - 1] = M[i][j];
		}
	}

	return res;

}


int sommeMatrice(int** M, int n, int m) {
	int s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s += M[i][j];

	return s;
}

bool egales(int** A, int** B, int n, int m) {
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i][j] != B[i][j]) return false;
	return true;

}


void remplirCarreMagique(int** M, int n) {

	int m = 2 * n - 1;
	int** tmp = reserverMatrice(m, m);

	int c = 1, k, l;

	for (int i = 0; i < n; i++) {
		k = i;
		l = n - 1 - i;
		while (k < i + n) tmp[k++][l++] = c++;
	}
	
	for (int i = 0; i < (n - 1) / 2; i++)
		for (int j = n - 1 - i; j < n + i; j += 2) {
			tmp[i + n][j] = tmp[i][j];
			tmp[n - 2 - i][j] = tmp[2 * n - 2 - i][j];

			tmp[j][i + n] = tmp[j][i];
			tmp[j][n - 2 - i] = tmp[j][2 * n - 2 - i];
		}

	for (int i = (n - 1) / 2; i < (n - 1) / 2 + n; i++)
		for (int j = (n - 1) / 2; j < (n - 1) / 2 + n; j++)
			M[i - ((n - 1) / 2)][j - ((n - 1) / 2)] = tmp[i][j];

	libererMatrice(tmp, 2 * n - 1);
}
