#include "exos.h"

void Exo1() {
	cout << "Donnez le nombre de parentheses: ";
	int n; cin >> n;
	char* t = new char[n];
	n_parentheses(t, n);
	delete[]t;
}

void Exo2() {

	int n; lireTaille(n);
	Liste tete = remplirListe(n);
	Liste m = tete;
	m = milieu_Rec(tete, m);
	if (m != nullptr) cout << "Milieu : " << m->info;

	cout << "\nDonnez le nombre a tester: ";
	int x; cin >> x;
	cout << boolalpha << est_premier_rec(x);
}

void Exo3() {

	cout << "Tri Insertion recursive\n";
	cout << "Donnez la taille du 1er tableau: ";
	int n; cin >> n;
	int* T = new int[n];
	remplirTableau(T, n);
	triInsertionTableau_Rec(T, 0, n - 1);
	afficherTableau(T, n);

	cout << "\nTri Permutation recursive\n";
	cout << "Donnez la taille du 2eme tableau: ";
	int m; cin >> m;
	int* t = new int[m];
	remplirTableau(t, m);
	triPermutationTableau_Rec(t, m);
	afficherTableau(t, m);

	delete[]t;
	delete[]T;
}

void Exo4() {

	int n;
	cout << "Enter the snake's size: ";  cin >> n;

	Snake tete = remplirSnake(n);

	char d;
	cout << "\nEnter the direction:";
	cin >> d;

	deplacerSnake(tete, d);

	cout << "\nAfter\n";
	afficherSnake(tete);

}

void Exo5() {

	cout << "\n1ere liste:\n";
	int n; lireTaille(n);
	Liste l1 = remplirListe(n);

	cout << "\n2eme liste:\n";
	lireTaille(n);
	Liste l2 = remplirListe(n);

	cout << boolalpha << estPrefixe(l1, l2);

	libererListe(l1);
	libererListe(l2);
}

void Exo6() {

	int n; lireTaille(n);

	int** M1 = reserverMatrice(n, n);
	remplirMatrice(M1, n, n);

	int** M2 = reserverMatrice(n, n);
	remplirMatrice(M2, n, n);

	MatriceCreuse l1 = matrice_vers_liste(M1, n);
	MatriceCreuse l2 = matrice_vers_liste(M2, n);

	MatriceCreuse res = sommeDeuxMatriceCreuses(l1, l2);
	afficherMatriceCreuse(res);

	libererMatrice(M1, n);
	libererMatrice(M2, n);

	libererMatriceCreuse(l1);
	libererMatriceCreuse(l2);
	libererMatriceCreuse(res);

}


void TP() {
	int choix;

	do {
		cout << "\n\nTP Algo\nEntrez le numero de l'exo: (-1 pour quitter)\n\n";
		cin >> choix;
		if (choix == -1) break;
		switch (choix)
		{
		case 1:
			Exo1();
			break;
		case 2:
			Exo2();
			break;
		case 3:
			Exo3();
			break;
		case 4:
			Exo4();
			break;
		case 5:
			Exo5();
			break;
		case 6:
			Exo6();
			break;
		default:
			cout << "Choix invalid!!\n";
			break;
		}

	} while (true);
}
