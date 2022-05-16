#include "tableau.h"

void lireTaille(int& taille) {
	do {
		cout << "Entrez la taille: "; cin >> taille;
		if (taille < 0) cout << "!!! La taille doit etre > 0 !!!\n";
	} while (taille < 0);
}

void lireIminImax(int& imin, int& imax, int taille) {
	do {
		cout << "Entrez imin: "; cin >> imin;
		cout << "Entrez imax: "; cin >> imax;

		if (imin < 0 || imax < imin || imax >= taille)
			cout << "!!! imin et imax sont invalides !!!\n";
	} while (imin < 0 || imax < imin || imax >= taille);
}

void remplirTableau(int T[], int n) {

	if (T == NULL) {
		cout << "\nT = NULL, Memoire non initialisee pour le tableau\n";
		return;
	}

	cout << "\nEntrez les valeurs du tableau un par un:\n";

	for (int i = 0; i < n; i++) {
		cout << "T[" << i << "] = ";
		cin >> T[i];
	}
}

void afficherTableau(int T[], int n) {

	if (T == NULL) {
		cout << "\nT = NULL, Memoire non initialisee pour le tableau\n";
		return;
	}

	cout << "\nAffichage du tableau:\n";
	for (int i = 0; i < n; i++) cout << T[i] << " ";
}

int sommeTableau(int T[], int imin, int imax) {

	if (T == NULL) return -1;

	int s = 0;
	for (int i = imin; i <= imax; i++) s += T[i];
	return s;
}

int rechercherTableau(int x, int T[], int imin, int imax) {
	for (int i = imin; i <= imax; i++) if (T[i] == x) return i + 1;
	return -1;
}

int dichotomieTableau(int x, int T[], int imin, int imax) {

	int milieu;

	while (imin <= imax) {

		milieu = (imin + imax) / 2;

		if (x == T[milieu]) return milieu + 1;

		else if (x < T[milieu]) imax = milieu - 1;
		else imin = milieu + 1;

	}

	return -1;
}

bool supprimerTableau(int x, int T[], int n) {

	int res = rechercherTableau(x, T, 0, n - 1);

	if (res == -1) return false;

	for (int i = res - 1; i < n - 1; i++) T[i] = T[i + 1];
	T[n - 1] = 0;
	return true;
}

int frequenceTableau(int x, int T[], int imin, int imax) {
	int occ = 0;
	for (int i = imin; i <= imax; i++) if (T[i] == x) occ++;
	return occ;
}

// Les tris -------------------------

void tri_selection(int T[], int premier, int dernier) {
	int imin, x;
	for (int i = premier; i < dernier; i++) {
		imin = i;
		for (int j = i + 1; j <= dernier; j++)
			if (T[j] < T[imin]) imin = j;
		if (imin != i) {
			x = T[imin];
			T[imin] = T[i];
			T[i] = x;
		}
	}
}

void tri_insertion(int T[], int premier, int dernier) {
	int x, j = premier;
	for (int i = premier + 1; i <= dernier; i++) {
		j = i - 1;
		x = T[i];
		while (j >= 0 && T[j] > x) {
			T[j + 1] = T[j];
			j--;
		}
		if (j != i - 1) T[j + 1] = x;
	}
}

void tri_shell(int T[], int premier, int dernier) {

	int h = (dernier - premier + 1) / 2,
		j, tmp;

	while (h > 0) {

		for (int i = h; i <= dernier; i++) {
			j = i;
			tmp = T[i];
			while (j >= h && T[j - h] > tmp) {
				T[j] = T[j - h];
				j -= h;
			}
			T[j] = tmp;
		}

		h /= 2;
	}
}

// tri fusion

void fusion(int T[], int premier, int milieu, int dernier) {

	int* gauche = new int[milieu - premier + 1]; // Le milieu est inclu dans la partie gauche
	// Copie du demi-tableau gauche
	for (int i = premier; i <= milieu; i++) gauche[i - premier] = T[i];

	int i = premier,
		j = 0,
		k = milieu + 1;

	for (; j <= (milieu - premier) && k <= dernier; i++)
		if (gauche[j] <= T[k]) T[i] = gauche[j++];
		else T[i] = T[k++];

	while (j <= milieu - premier) T[i++] = gauche[j++];

	delete[] gauche;
}
void tri_fusion_tableau(int T[], int premier, int dernier) {
	if (premier >= dernier) return;
	int milieu = (premier + dernier) / 2;
	tri_fusion_tableau(T, premier, milieu);
	tri_fusion_tableau(T, milieu + 1, dernier);
	fusion(T, premier, milieu, dernier);
}

// tri rapide
int partitionner(int T[], int premier, int dernier) {
	int j = premier, i, x;
	for (i = premier; i < dernier; i++)
		if (T[i] <= T[dernier]) {
			x = T[i];
			T[i] = T[j];
			T[j] = x;
			j++;
		}
	x = T[dernier];
	T[dernier] = T[j];
	T[j] = x;
	return j;
}
void tri_rapide(int T[], int premier, int dernier) {
	int pivot;
	if (premier < dernier) {
		pivot = partitionner(T, premier, dernier);
		tri_rapide(T, premier, pivot - 1);
		tri_rapide(T, pivot + 1, dernier);
	}
}


int nbrCombinaisons(int T[], int taille, int somme) {

	if (somme == 0) return 1;
	if (taille == 0) return 0;

	if (T[taille - 1] > somme) return nbrCombinaisons(T, taille - 1, somme);

	int nbr = 0, rest;
	for (int i = 0; i <= (somme / T[taille - 1]); i++) {
		rest = somme - i * T[taille - 1];
		nbr += nbrCombinaisons(T, taille - 1, rest);
	}
	return nbr;
}

int sommeMaximale(int T[], int n, int& debut, int& fin) {

	int smax = T[0], // ou bien INT_MIN de  l'entete <climits>
		s = 0;

	int j = 0;

	for (int i = 0; i < n; i++) {

		if (s < 0) {
			s = T[i];
			j = i;
		}
		else s += T[i];

		if (smax < s) {
			smax = s;
			debut = j;
			fin = i;
		}
	}
	return smax;
}

void permutations(int T[], int n, int debut, int& nbr) {
	
	if (debut == n - 1) {
		nbr++;
		for (int i = 0; i < n; i++) cout << T[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = debut; i < n; i++) {
		permuter<int>(T[i], T[debut]);
		permutations(T, n, debut + 1, nbr);
		permuter<int>(T[i], T[debut]);
	}

}

int medianeTableauNonTrie(int T[], int n) {
	
	// n est supposé impair
	if (n % 2 != 1) return -999;

	int i = 0,
		j, ne, np, ng;

	while (true) {
		ne = 0; np = 0; ng = 0;

		j = 0;
		while (j < n && ne <= (n / 2)) {
			if (T[j] == T[i]) {
				ne++; ng++; np++;
			}
			else if (T[j] > T[i]) ng++;
			else np++;

			j++;
		}

		if (np == ng || ne > (n / 2)) break;
		i++;
	}
	return T[i];
}
